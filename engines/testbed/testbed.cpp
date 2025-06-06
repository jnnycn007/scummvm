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

#include "common/debug-channels.h"
#include "common/scummsys.h"
#include "common/archive.h"
#include "common/config-manager.h"
#include "common/error.h"
#include "common/fs.h"
#include "common/rect.h"
#include "common/str.h"

#include "engines/achievements.h"
#include "engines/util.h"

#include "gui/textviewer.h"
#include "gui/gui-manager.h"

#include "testbed/events.h"
#include "testbed/fs.h"
#include "testbed/graphics.h"
#include "testbed/image.h"
#include "testbed/midi.h"
#include "testbed/misc.h"
#include "testbed/networking.h"
#include "testbed/savegame.h"
#include "testbed/sound.h"
#include "testbed/testbed.h"
#include "testbed/video.h"
#ifdef USE_CLOUD
#include "testbed/cloud.h"
#endif
#ifdef USE_SDL_NET
#include "testbed/webserver.h"
#endif
#ifdef USE_TTS
#include "testbed/speech.h"
#endif
#ifdef USE_IMGUI
#include "testbed/imgui.h"
#endif

namespace Testbed {

void TestbedExitDialog::init() {
	resize(80, 40, 500, 330);
	_xOffset = 25;
	_yOffset = 0;
	Common::String text = "Thank you for using ScummVM testbed! Here are yor summarized results:";
	addText(450, 20, text, Graphics::kTextAlignCenter, _xOffset, 15);
	Common::Array<Common::U32String> strArray;
	Common::U32String color;

	for (Common::Array<Testsuite *>::const_iterator i = _testsuiteList.begin(); i != _testsuiteList.end(); ++i) {
		color = GUI::ListWidget::getThemeColor(GUI::ThemeEngine::kFontColorNormal);
		strArray.push_back(color + Common::U32String::format("%s :", (*i)->getDescription()));

		color = GUI::ListWidget::getThemeColor(GUI::ThemeEngine::kFontColorAlternate);
		if ((*i)->isEnabled()) {
			strArray.push_back(color + Common::U32String::format("Passed: %d  Failed: %d Skipped: %d", (*i)->getNumTestsPassed(), (*i)->getNumTestsFailed(), (*i)->getNumTestsSkipped()));
		} else {
			strArray.push_back(color + Common::U32String("Skipped"));
		}
	}

	addList(0, _yOffset, 500, 200, strArray);
	text = "More Details can be viewed in the Log file : " + ConfParams.getLogFilename();
	addText(450, 20, text, Graphics::kTextAlignLeft, 0, 0);
	if (ConfParams.getLogDirectory().empty()) {
		text = "Directory : .";
	} else {
		text = "Directory : " + ConfParams.getLogDirectory().toString(Common::Path::kNativeSeparator);
	}
	addText(500, 20, text, Graphics::kTextAlignLeft, 0, 0);
	_yOffset += 5;
	addButtonXY(_xOffset + 80, _yOffset, 120, 24, "Rerun test suite", kCmdRerunTestbed);
	addButtonXY(_xOffset + 240, _yOffset, 60, 24, "Close", GUI::kCloseCmd);
	addButtonXY(_xOffset + 340, _yOffset, 60, 24, "Open Log", kViewLogCmd);
}

void TestbedExitDialog::handleCommand(GUI::CommandSender *sender, uint32 cmd, uint32 data) {
	switch (cmd) {
	default:
		break;

	case kCmdRerunTestbed:
		ConfParams.setRerunFlag(true);
		cmd = GUI::kCloseCmd;
		break;
	case kViewLogCmd: 
		Common::Path logPath = Common::Path(ConfParams.getLogDirectory());
		GUI::TextViewerDialog viewer(logPath.appendComponent(ConfParams.getLogFilename()));
		viewer.runModal();
		g_gui.scheduleTopDialogRedraw();
		break;
	}

	GUI::Dialog::handleCommand(sender, cmd, data);
}

bool TestbedEngine::hasFeature(EngineFeature f) const {
	return (f == kSupportsReturnToLauncher) ? true : false;
}

TestbedEngine::TestbedEngine(OSystem *syst)
	: Engine(syst) {
	// Put your engine in a sane state, but do nothing big yet;
	// in particular, do not load data from files; rather, if you
	// need to do such things, do them from init().

	// Do not initialize graphics here

	// However this is the place to specify all default directories
	// Put game-data dir in search path
	Common::FSNode gameRoot(ConfMan.getPath("path"));
	if (gameRoot.exists()) {
		SearchMan.addDirectory(gameRoot.getDisplayName(), gameRoot);
	}
	DebugMan.enableDebugChannel("LOG");

	pushTestsuites(_testsuiteList);
}

void TestbedEngine::pushTestsuites(Common::Array<Testsuite *> &testsuiteList) {
	// Initialize testsuites here
	Testsuite *ts;
	// GFX
	ts = new GFXTestSuite();
	testsuiteList.push_back(ts);
	// Image
	ts = new ImageTestSuite();
	testsuiteList.push_back(ts);
	// FS
	ts = new FSTestSuite();
	testsuiteList.push_back(ts);
	// Savegames
	ts = new SaveGameTestSuite();
	testsuiteList.push_back(ts);
	// Misc.
	ts = new MiscTestSuite();
	testsuiteList.push_back(ts);
	// Events
	ts = new EventTestSuite();
	testsuiteList.push_back(ts);
	// Sound
	ts = new SoundSubsystemTestSuite();
	testsuiteList.push_back(ts);
	// Midi
	ts = new MidiTestSuite();
	testsuiteList.push_back(ts);
	// Networking
	ts = new NetworkingTestSuite();
	testsuiteList.push_back(ts);
#ifdef USE_TTS
	// TextToSpeech
	ts = new SpeechTestSuite();
	testsuiteList.push_back(ts);
#endif
#if defined(USE_CLOUD) && defined(USE_LIBCURL)
	// Cloud
	ts = new CloudTestSuite();
	testsuiteList.push_back(ts);
#endif
#ifdef USE_SDL_NET
	// Webserver
	ts = new WebserverTestSuite();
	testsuiteList.push_back(ts);
#endif
#ifdef USE_IMGUI
	// ImGui
	ts = new ImGuiTestSuite();
	testsuiteList.push_back(ts);
#endif
	// Video decoder
	ts = new VideoDecoderTestSuite();
	testsuiteList.push_back(ts);
}

TestbedEngine::~TestbedEngine() {
	ConfParams.deleteWriteStream();

	for (Common::Array<Testsuite *>::const_iterator i = _testsuiteList.begin(); i != _testsuiteList.end(); ++i) {
		delete (*i);
	}
}

void TestbedEngine::invokeTestsuites(TestbedConfigManager &cfMan) {
	Common::Array<Testsuite *>::const_iterator iter;
	uint count = 1;
	Common::Point pt = Testsuite::getDisplayRegionCoordinates();
	int numSuitesEnabled = cfMan.getNumSuitesEnabled();

	if (!numSuitesEnabled)
		return;

	for (iter = _testsuiteList.begin(); iter != _testsuiteList.end(); iter++) {
		if (shouldQuit()) {
			return;
		}
		(*iter)->reset();
		if ((*iter)->isEnabled()) {
			Testsuite::updateStats("Testsuite", (*iter)->getName(), count++, numSuitesEnabled, pt);
			(*iter)->execute();
		}
		if ((*iter)->getNumTests() == (*iter)->getNumTestsPassed()) {
			AchMan.setAchievement((*iter)->getName());
			checkForAllAchievements();
		}
	}
}

void TestbedEngine::checkForAllAchievements() {
	Common::Array<Testsuite *>::const_iterator iter;
	for (iter = _testsuiteList.begin(); iter != _testsuiteList.end(); iter++) {
		if (!AchMan.isAchieved((*iter)->getName())) {
			return;
		}
	}
	AchMan.setAchievement("EVERYTHINGWORKS");
}

Common::Error TestbedEngine::run() {
	if (ConfMan.hasKey("start_movie")) {
		return Videotests::videoTest(ConfMan.getPath("start_movie"));
	}

	// Initialize graphics using following:
	initGraphics(320, 200);

	// Initialize achievements manager
	Common::AchievementsInfo info;
	info.platform = Common::UNK_ACHIEVEMENTS;
	info.appId = "testbed";
	AchMan.setActiveDomain(info);

	// As of now we are using GUI::MessageDialog for interaction, Test if it works.
	// interactive mode could also be modified by a config parameter "non-interactive=1"
	// TODO: Implement that

	TestbedConfigManager cfMan(_testsuiteList, "testbed.config");

	// Keep running if rerun requested

	do {
		Testsuite::clearEntireScreen();
		cfMan.selectTestsuites();
		// Init logging
		ConfParams.initLogging(true);
		invokeTestsuites(cfMan);
		// Check if user wanted to exit.
		if (Engine::shouldQuit()) {
			return Common::kNoError;
		}

		TestbedExitDialog tbDialog(_testsuiteList);
		tbDialog.init();
		tbDialog.run();

	} while (ConfParams.isRerunRequired());

	return Common::kNoError;
}

} // End of namespace Testbed
