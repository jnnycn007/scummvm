/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "voyeur/voyeur.h"

#include "engines/advancedDetector.h"

#include "common/savefile.h"
#include "common/system.h"
#include "common/translation.h"

#include "backends/keymapper/action.h"
#include "backends/keymapper/keymapper.h"
#include "backends/keymapper/standard-actions.h"

#include "graphics/surface.h"

#include "voyeur/detection.h"

#define MAX_SAVES 99

namespace Voyeur {

static const ADExtraGuiOptionsMap optionsList[] = {
	{
		GAMEOPTION_COPY_PROTECTION,
		{
			// I18N: lockout is code to start the game
			_s("Enable lockout system"),
			_s("Require a lockout code to start the game."),
			"copy_protection",
			false,
			0,
			0
		},
	},

	AD_EXTRA_GUI_OPTIONS_TERMINATOR
};

uint32 VoyeurEngine::getFeatures() const {
	return _gameDescription->desc.flags;
}

Common::Language VoyeurEngine::getLanguage() const {
	return _gameDescription->desc.language;
}

Common::Platform VoyeurEngine::getPlatform() const {
	return _gameDescription->desc.platform;
}

bool VoyeurEngine::getIsDemo() const {
	return _gameDescription->desc.flags & ADGF_DEMO;
}

} // End of namespace Voyeur

class VoyeurMetaEngine : public AdvancedMetaEngine<Voyeur::VoyeurGameDescription> {
public:
	const char *getName() const override {
		return "voyeur";
	}

	const ADExtraGuiOptionsMap *getAdvancedExtraGuiOptions() const override {
		return Voyeur::optionsList;
	}

	bool hasFeature(MetaEngineFeature f) const override;
	Common::Error createInstance(OSystem *syst, Engine **engine, const Voyeur::VoyeurGameDescription *desc) const override;
	SaveStateList listSaves(const char *target) const override;
	int getMaximumSaveSlot() const override;
	bool removeSaveState(const char *target, int slot) const override;
	SaveStateDescriptor querySaveMetaInfos(const char *target, int slot) const override;
	Common::KeymapArray initKeymaps(const char *target) const override;
};

bool VoyeurMetaEngine::hasFeature(MetaEngineFeature f) const {
	return
	    (f == kSupportsListSaves) ||
		(f == kSupportsLoadingDuringStartup) ||
		(f == kSupportsDeleteSave) ||
		(f == kSavesSupportMetaInfo) ||
		(f == kSavesSupportThumbnail) ||
		(f == kSimpleSavesNames);
}

bool Voyeur::VoyeurEngine::hasFeature(EngineFeature f) const {
	return
		(f == kSupportsReturnToLauncher) ||
		(f == kSupportsLoadingDuringRuntime) ||
		(f == kSupportsSavingDuringRuntime);
}

Common::Error VoyeurMetaEngine::createInstance(OSystem *syst, Engine **engine, const Voyeur::VoyeurGameDescription *desc) const {
	*engine = new Voyeur::VoyeurEngine(syst,desc);
	return Common::kNoError;
}

SaveStateList VoyeurMetaEngine::listSaves(const char *target) const {
	Common::SaveFileManager *saveFileMan = g_system->getSavefileManager();
	Common::String saveDesc;
	Common::String pattern = Common::String::format("%s.0##", target);
	Common::StringArray filenames = saveFileMan->listSavefiles(pattern);

	SaveStateList saveList;
	Voyeur::VoyeurSavegameHeader header;

	for (const auto &filename : filenames) {
		const char *ext = strrchr(filename.c_str(), '.');
		int slot = ext ? atoi(ext + 1) : -1;

		if (slot >= 0 && slot <= MAX_SAVES) {
			Common::InSaveFile *in = g_system->getSavefileManager()->openForLoading(filename);

			if (in) {
				if (header.read(in)) {
					saveList.push_back(SaveStateDescriptor(this, slot, header._saveName));
				}
				delete in;
			}
		}
	}

	// Sort saves based on slot number.
	Common::sort(saveList.begin(), saveList.end(), SaveStateDescriptorSlotComparator());
	return saveList;
}

int VoyeurMetaEngine::getMaximumSaveSlot() const {
	return MAX_SAVES;
}

bool VoyeurMetaEngine::removeSaveState(const char *target, int slot) const {
	Common::String filename = Common::String::format("%s.%03d", target, slot);
	return g_system->getSavefileManager()->removeSavefile(filename);
}

SaveStateDescriptor VoyeurMetaEngine::querySaveMetaInfos(const char *target, int slot) const {
	Common::String filename = Common::String::format("%s.%03d", target, slot);
	Common::InSaveFile *f = g_system->getSavefileManager()->openForLoading(filename);

	if (f) {
		Voyeur::VoyeurSavegameHeader header;
		header.read(f, false);
		delete f;

		// Create the return descriptor
		SaveStateDescriptor desc(this, slot, header._saveName);
		desc.setThumbnail(header._thumbnail);
		desc.setSaveDate(header._saveYear, header._saveMonth, header._saveDay);
		desc.setSaveTime(header._saveHour, header._saveMinutes);
		desc.setPlayTime(header._totalFrames * GAME_FRAME_TIME);

		return desc;
	}

	return SaveStateDescriptor();
}

Common::KeymapArray VoyeurMetaEngine::initKeymaps(const char *target) const {

	using namespace Common;
	using namespace Voyeur;

	Keymap *engineKeymap = new Keymap(Keymap::kKeymapTypeGame, "voyeur-default", _("Default keymappings"));
	Keymap *cutsceneKeymap = new Keymap(Keymap::kKeymapTypeGame, "cutscene", _("Cutscene keymappings"));
	Keymap *roomKeymap = new Keymap(Keymap::kKeymapTypeGame, "room", _("Room keymappings"));
	Keymap *cameraKeymap = new Keymap(Keymap::kKeymapTypeGame, "camera", _("Camera keymappings"));
	Keymap *introKeymap = new Keymap(Keymap::kKeymapTypeGame, "intro", _("Intro keymappings"));

	Common::Action *act;

	act = new Common::Action(kStandardActionLeftClick, _("Interact"));
	act->setLeftClickEvent();
	act->addDefaultInputMapping("MOUSE_LEFT");
	act->addDefaultInputMapping("JOY_A");
	engineKeymap->addAction(act);

	act = new Common::Action(kStandardActionRightClick, _("Exit"));
	act->setRightClickEvent();
	act->addDefaultInputMapping("MOUSE_RIGHT");
	act->addDefaultInputMapping("JOY_B");
	engineKeymap->addAction(act);

	act = new Common::Action(kStandardActionRightClick, _("Skip scene"));
	act->setLeftClickEvent();
	act->addDefaultInputMapping("MOUSE_LEFT");
	act->addDefaultInputMapping("MOUSE_RIGHT");
	act->addDefaultInputMapping("JOY_A");
	cutsceneKeymap->addAction(act);

	act = new Common::Action(kStandardActionLeftClick, _("View evidence"));
	act->setLeftClickEvent();
	act->addDefaultInputMapping("MOUSE_LEFT");
	act->addDefaultInputMapping("JOY_A");
	roomKeymap->addAction(act);

	act = new Common::Action(kStandardActionRightClick, _("Exit / Put away evidence"));
	act->setRightClickEvent();
	act->addDefaultInputMapping("MOUSE_RIGHT");
	act->addDefaultInputMapping("JOY_B");
	roomKeymap->addAction(act);

	act = new Common::Action(kStandardActionLeftClick, _("Enter room"));
	act->setLeftClickEvent();
	act->addDefaultInputMapping("MOUSE_LEFT");
	act->addDefaultInputMapping("JOY_A");
	cameraKeymap->addAction(act);

	act = new Common::Action(kStandardActionRightClick, _("Exit"));
	act->setRightClickEvent();
	act->addDefaultInputMapping("MOUSE_RIGHT");
	act->addDefaultInputMapping("JOY_B");
	cameraKeymap->addAction(act);

	act = new Common::Action("SKIP", _("Skip intro"));
	act->setCustomEngineActionEvent(kActionSkip);
	act->addDefaultInputMapping("MOUSE_LEFT");
	act->addDefaultInputMapping("ESCAPE");
	act->addDefaultInputMapping("SPACE");
	act->addDefaultInputMapping("JOY_A");
	introKeymap->addAction(act);

	KeymapArray keymaps(5);
	keymaps[0] = engineKeymap;
	keymaps[1] = cutsceneKeymap;
	keymaps[2] = roomKeymap;
	keymaps[3] = cameraKeymap;
	keymaps[4] = introKeymap;

	cutsceneKeymap->setEnabled(false);
	roomKeymap->setEnabled(false);
	cameraKeymap->setEnabled(false);
	introKeymap->setEnabled(false);

	return keymaps;
}

#if PLUGIN_ENABLED_DYNAMIC(VOYEUR)
	REGISTER_PLUGIN_DYNAMIC(VOYEUR, PLUGIN_TYPE_ENGINE, VoyeurMetaEngine);
#else
	REGISTER_PLUGIN_STATIC(VOYEUR, PLUGIN_TYPE_ENGINE, VoyeurMetaEngine);
#endif
