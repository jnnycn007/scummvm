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

#include "backends/keymapper/action.h"
#include "backends/keymapper/keymapper.h"
#include "backends/keymapper/standard-actions.h"

#include "engines/wintermute/base/base_game_custom_actions.h"

#include "common/translation.h"

namespace Wintermute {

inline Common::KeymapArray getWintermuteKeymaps(const char *target, const Common::String &gameId, const char *gameDescr) {

	using namespace Common;

	Keymap *engineKeyMap = new Keymap(Keymap::kKeymapTypeGame, "wintermute", "Wintermute engine");
	Keymap *gameKeyMap = new Keymap(Keymap::kKeymapTypeGame, gameId, gameDescr);
	Keymap *extraKeyMap = new Keymap(Keymap::kKeymapTypeGame, "extras", "ScummVM extra actions");

	Action *act;

	act = new Action(kStandardActionLeftClick, _("Left click"));
	act->setLeftClickEvent();
	act->addDefaultInputMapping("MOUSE_LEFT"); // original mouse
	act->addDefaultInputMapping("JOY_A"); // extra joy
	engineKeyMap->addAction(act);

	act = new Action(kStandardActionRightClick, _("Right click"));
	act->setRightClickEvent();
	act->addDefaultInputMapping("MOUSE_RIGHT"); // original mouse
	act->addDefaultInputMapping("JOY_B"); // extra joy
	engineKeyMap->addAction(act);

	act = new Action("RETURN", _("Confirm"));
	act->setKeyEvent(KeyState(KEYCODE_RETURN, ASCII_RETURN));
	act->addDefaultInputMapping("RETURN"); // original keyboard
	//TODO: extra joy control, e.g. "JOY_R+JOY_X"
	engineKeyMap->addAction(act);

	act = new Action("ESCAPE", _("Escape"));
	act->setKeyEvent(KeyState(KEYCODE_ESCAPE, ASCII_ESCAPE));
	act->addDefaultInputMapping("ESCAPE"); // original keyboard
	act->addDefaultInputMapping("JOY_X"); // extra joy
	engineKeyMap->addAction(act);

	Common::KeymapArray result = Keymap::arrayOf(engineKeyMap);
	if (gameId == "8squares" ||
		gameId == "actualdest" ||
		gameId == "artofmurder1" ||
		gameId == "agustin" ||
		gameId == "barrowhilldp" ||
		gameId == "bickadoodle" ||
		gameId == "bthreshold" ||
		gameId == "carolreed6" ||
		gameId == "carolreed7" ||
		gameId == "carolreed8" ||
		gameId == "colorsoncanvas" ||
		gameId == "conspiracao" ||
		gameId == "corrosion" ||
		gameId == "deadcity" ||
		gameId == "darkfallls" ||
		gameId == "drbohus" ||
		gameId == "dreaming" ||
		gameId == "dreamscape" ||
		gameId == "driller" ||
		gameId == "everydaygray" ||
		gameId == "findinghope" ||
		gameId == "four" ||
		gameId == "framed" ||
		gameId == "hamlet" ||
		gameId == "hor" ||
		gameId == "idiotstale" ||
		gameId == "imustkill" ||
		gameId == "juliauntold" ||
		gameId == "lifein3minutes" ||
		gameId == "lonelyrobot" ||
		gameId == "machumayu" ||
		gameId == "mirage" ||
		gameId == "miskatonic1" ||
		gameId == "nighttrain" ||
		gameId == "projectdoom" ||
		gameId == "rosemary" ||
		gameId == "satanandsons" ||
		gameId == "sofiasdebt" ||
		gameId == "spaceinvaders" ||
		gameId == "spacemadness" ||
		gameId == "strangechange" ||
		gameId == "tanya1" ||
		gameId == "tanya2" ||
		gameId == "theancientmark1" ||
		gameId == "thebox" ||
		gameId == "thekite" ||
		gameId == "tradestory" ||
		gameId == "war" ||
		gameId == "wmedemo"
	) {
		/* no game-specific keymap */
	} else if (gameId == "dfafadventure" ||
		gameId == "dreamcat" ||
		gameId == "openquest"
	) {
		act = new Action("LOOK", _("Look at"));
		act->setKeyEvent(KeyState(KEYCODE_l, 'l'));
		act->addDefaultInputMapping("l"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("TALK", _("Talk to"));
		act->setKeyEvent(KeyState(KEYCODE_t, 't'));
		act->addDefaultInputMapping("t"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PICK", _("Pick up"));
		act->setKeyEvent(KeyState(KEYCODE_p, 'p'));
		act->addDefaultInputMapping("p"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("USE", _("Use"));
		act->setKeyEvent(KeyState(KEYCODE_u, 'u'));
		act->addDefaultInputMapping("u"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "basisoctavus" ||
		gameId == "lovmamuta" ||
		gameId == "wmedemo3d"
	) {
		act = new Action(kStandardActionMoveUp, _("Move forward"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveDown, _("Move backwards"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Turn left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Turn right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		// I18N: Debug feature to draw lines of scene geometry: walls, walking areas, etc
		act = new Action("DBGSCN", _("Show scene geometry"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "5ld" ||
		gameId == "projectjoe"
	) {
		act = new Action("PAGEUP", _("Previous page"));
		act->setKeyEvent(KEYCODE_PAGEUP);
		act->addDefaultInputMapping("PAGEUP"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PAGEDN", _("Next page"));
		act->setKeyEvent(KEYCODE_PAGEDOWN);
		act->addDefaultInputMapping("PAGEDOWN"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "5ma" ||
		gameId == "dirtysplit"
	) {
		act = new Action("PAGEUP", _("Previous page"));
		act->setKeyEvent(KEYCODE_PAGEUP);
		act->addDefaultInputMapping("PAGEUP"); // original keyboard
		act->addDefaultInputMapping("LEFT"); // original keyboard for 5ma & dirtysplit
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PAGEDN", _("Next page"));
		act->setKeyEvent(KEYCODE_PAGEDOWN);
		act->addDefaultInputMapping("PAGEDOWN"); // original keyboard
		act->addDefaultInputMapping("RIGHT"); // original keyboard for 5ma & dirtysplit
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "chivalry" ||
		gameId == "paintaria" ||
		gameId == "pigeons" ||
		gameId == "rhiannon" ||
		gameId == "shinestar"
	) {
		act = new Action(kStandardActionSkip, _("Skip"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "drdoylemotch" ||
		gameId == "carolreed9" ||
		gameId == "carolreed10" ||
		gameId == "carolreed11" ||
		gameId == "carolreed12" ||
		gameId == "carolreed13" ||
		gameId == "carolreed14" ||
		gameId == "carolreed15" ||
		gameId == "carolreed16" ||
		gameId == "kulivocko" ||
		gameId == "sunrise" ||
		gameId == "rebeccacarlson1"
	) {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "goldencalf" ||
		gameId == "msos" ||
		gameId == "one"
	) {
		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "bookofgron") {
		act = new Action(kStandardActionMiddleClick, _("Middle click"));
		act->setMiddleClickEvent();
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // original mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "qajarycat") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIA", _("GUI variant A"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIB", _("GUI variant B"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONEX", _("Phone cancel button"));
		act->setKeyEvent(KeyState(KEYCODE_BACKSPACE, ASCII_BACKSPACE));
		act->addDefaultInputMapping("BACKSPACE"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEU", _("Phone up button"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONED", _("Phone down button"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMiddleClick, _("Middle click"));
		act->setMiddleClickEvent();
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_HOME);
		act->addDefaultInputMapping("HOME"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "forgottensound1" ||
		gameId == "forgottensound2"
	) {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIA", _("GUI variant A"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIB", _("GUI variant B"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_HOME);
		act->addDefaultInputMapping("HOME"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "tehran1933") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		// I18N: Some items are scripted to have alternative "Use" action, when MiddleClick is used
		// It may result in actor saying different text or item being decomposed to it's parts
		act = new Action("ALTUSE", _("Alternative action"));
		act->setMiddleClickEvent();
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // original mouse
		act->addDefaultInputMapping("BACKSPACE"); // extra keyboard
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIA", _("GUI variant A"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIB", _("GUI variant B"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_HOME);
		act->addDefaultInputMapping("HOME"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "darksummer" ||
		gameId == "tehran2016"
	) {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_i, 'i'));
		act->addDefaultInputMapping("i"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIA", _("GUI variant A"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		gameKeyMap->addAction(act);

		act = new Action("GUIB", _("GUI variant B"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		gameKeyMap->addAction(act);

		act = new Action("PHONEX", _("Phone cancel button"));
		act->setKeyEvent(KeyState(KEYCODE_BACKSPACE, ASCII_BACKSPACE));
		act->addDefaultInputMapping("BACKSPACE"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEU", _("Phone up button"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONED", _("Phone down button"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONE0", _("Phone 0 button"));
		act->setKeyEvent(KeyState(KEYCODE_0, '0'));
		act->addDefaultInputMapping("0"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE1", _("Phone 1 button"));
		act->setKeyEvent(KeyState(KEYCODE_1, '1'));
		act->addDefaultInputMapping("1"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE2", _("Phone 2 button"));
		act->setKeyEvent(KeyState(KEYCODE_2, '2'));
		act->addDefaultInputMapping("2"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE3", _("Phone 3 button"));
		act->setKeyEvent(KeyState(KEYCODE_3, '3'));
		act->addDefaultInputMapping("3"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE4", _("Phone 4 button"));
		act->setKeyEvent(KeyState(KEYCODE_4, '4'));
		act->addDefaultInputMapping("4"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE5", _("Phone 5 button"));
		act->setKeyEvent(KeyState(KEYCODE_5, '5'));
		act->addDefaultInputMapping("5"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE6", _("Phone 6 button"));
		act->setKeyEvent(KeyState(KEYCODE_6, '6'));
		act->addDefaultInputMapping("6"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE7", _("Phone 7 button"));
		act->setKeyEvent(KeyState(KEYCODE_7, '7'));
		act->addDefaultInputMapping("7"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE8", _("Phone 8 button"));
		act->setKeyEvent(KeyState(KEYCODE_8, '8'));
		act->addDefaultInputMapping("8"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE9", _("Phone 9 button"));
		act->setKeyEvent(KeyState(KEYCODE_9, '9'));
		act->addDefaultInputMapping("9"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEA", _("Phone * button"));
		act->setKeyEvent(KeyState(KEYCODE_ASTERISK, '*'));
		act->addDefaultInputMapping("ASTERISK"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEH", _("Phone # button"));
		act->setKeyEvent(KeyState(KEYCODE_HASH, '#'));
		act->addDefaultInputMapping("HASH"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_HOME);
		act->addDefaultInputMapping("HOME"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "alimardan1" ||
		gameId == "devilincapital"
	) {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIA", _("GUI variant A"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIB", _("GUI variant B"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_HOME);
		act->addDefaultInputMapping("HOME"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "alimardan2") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIA", _("GUI variant A"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIB", _("GUI variant B"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONEX", _("Phone cancel button"));
		act->setKeyEvent(KeyState(KEYCODE_BACKSPACE, ASCII_BACKSPACE));
		act->addDefaultInputMapping("BACKSPACE"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEU", _("Phone up button"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONED", _("Phone down button"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONE0", _("Phone 0 button"));
		act->setKeyEvent(KeyState(KEYCODE_0, '0'));
		act->addDefaultInputMapping("0"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE1", _("Phone 1 button"));
		act->setKeyEvent(KeyState(KEYCODE_1, '1'));
		act->addDefaultInputMapping("1"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE2", _("Phone 2 button"));
		act->setKeyEvent(KeyState(KEYCODE_2, '2'));
		act->addDefaultInputMapping("2"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE3", _("Phone 3 button"));
		act->setKeyEvent(KeyState(KEYCODE_3, '3'));
		act->addDefaultInputMapping("3"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE4", _("Phone 4 button"));
		act->setKeyEvent(KeyState(KEYCODE_4, '4'));
		act->addDefaultInputMapping("4"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE5", _("Phone 5 button"));
		act->setKeyEvent(KeyState(KEYCODE_5, '5'));
		act->addDefaultInputMapping("5"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE6", _("Phone 6 button"));
		act->setKeyEvent(KeyState(KEYCODE_6, '6'));
		act->addDefaultInputMapping("6"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE7", _("Phone 7 button"));
		act->setKeyEvent(KeyState(KEYCODE_7, '7'));
		act->addDefaultInputMapping("7"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE8", _("Phone 8 button"));
		act->setKeyEvent(KeyState(KEYCODE_8, '8'));
		act->addDefaultInputMapping("8"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE9", _("Phone 9 button"));
		act->setKeyEvent(KeyState(KEYCODE_9, '9'));
		act->addDefaultInputMapping("9"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEA", _("Phone * button"));
		act->setKeyEvent(KeyState(KEYCODE_ASTERISK, '*'));
		act->addDefaultInputMapping("ASTERISK"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEH", _("Phone # button"));
		act->setKeyEvent(KeyState(KEYCODE_HASH, '#'));
		act->addDefaultInputMapping("HASH"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_HOME);
		act->addDefaultInputMapping("HOME"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "alavi") {
		act = new Action("PAGEUP", _("Previous page"));
		act->setKeyEvent(KEYCODE_PAGEUP);
		act->addDefaultInputMapping("PAGEUP"); // original keyboard
		act->addDefaultInputMapping("LEFT"); // original keyboard for 5ma & dirtysplit
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PAGEDN", _("Next page"));
		act->setKeyEvent(KEYCODE_PAGEDOWN);
		act->addDefaultInputMapping("PAGEDOWN"); // original keyboard
		act->addDefaultInputMapping("RIGHT"); // original keyboard for 5ma & dirtysplit
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRS", _("Save screenshot"));
		act->setKeyEvent(KEYCODE_F6);
		act->addDefaultInputMapping("F6"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "alphapolaris") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_i, 'i'));
		act->addDefaultInputMapping("i"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("HELP", _("Show help"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("PAGEUP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("PAGEDOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		// I18N: Debug feature to draw lines of scene geometry: walls, walking areas, etc
		act = new Action("DBGSCN", _("Show scene geometry"));
		act->setKeyEvent(KeyState(KEYCODE_F2, 0, KBD_CTRL));
		act->addDefaultInputMapping("C+F2"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("SHADOW", _("Change shadow type"));
		act->setKeyEvent(KeyState(KEYCODE_F3, 0, KBD_CTRL));
		act->addDefaultInputMapping("C+F3"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("SCRS", _("Save screenshot"));
		act->setKeyEvent(KeyState(KEYCODE_F5, 0, KBD_CTRL));
		// act->addDefaultInputMapping("C+F5"); // original keyboard (disabled due to conflict with GMM)
		gameKeyMap->addAction(act);

		act = new Action("VOLMAX", _("Volume max"));
		act->setKeyEvent(KeyState(KEYCODE_F6, 0, KBD_CTRL));
		act->addDefaultInputMapping("C+F6"); // original keyboard
		gameKeyMap->addAction(act);

		// I18N: Displays a debug interface with a CLI for various features
		act = new Action("DBGCLI", _("Show debug parser"));
		act->setKeyEvent(KeyState(KEYCODE_F7, 0, KBD_CTRL));
		act->addDefaultInputMapping("C+F7"); // original keyboard
		act->addDefaultInputMapping("C+F10"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);

		// I18N: Displays a debug text message
		act = new Action("DBGTXT", _("Debug print"));
		act->setKeyEvent(KeyState(KEYCODE_F8, 0, KBD_CTRL));
		act->addDefaultInputMapping("C+F8"); // original keyboard
		gameKeyMap->addAction(act);

		// I18N: Exits the game
		act = new Action("EXIT", _("Exit"));
		act->setKeyEvent(KeyState(KEYCODE_F9, 0, KBD_CTRL));
		act->addDefaultInputMapping("C+F9"); // original keyboard
		gameKeyMap->addAction(act);

		// I18N: Displays a debug interface that changes light settings
		act = new Action("LIGHT", _("Light helper window"));
		act->setKeyEvent(KeyState(KEYCODE_F11, 0, KBD_CTRL));
		act->addDefaultInputMapping("C+F11"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveUp, _("Move forward"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveDown, _("Move backwards"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Turn left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Turn right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("FASTU", _("Run forward"));
		act->setKeyEvent(KeyState(KEYCODE_UP, 0, KBD_SHIFT));
		act->addDefaultInputMapping("S+UP"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("FASTD", _("Run backward"));
		act->setKeyEvent(KeyState(KEYCODE_DOWN, 0, KBD_SHIFT));
		act->addDefaultInputMapping("S+DOWN"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("FASTL", _("Turn left fast"));
		act->setKeyEvent(KeyState(KEYCODE_LEFT, 0, KBD_SHIFT));
		act->addDefaultInputMapping("S+LEFT"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("FASTR", _("Turn right fast"));
		act->setKeyEvent(KeyState(KEYCODE_RIGHT, 0, KBD_SHIFT));
		act->addDefaultInputMapping("S+RIGHT"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "apeiron") {
		// I18N: Displays a blueprint with robot parts
		act = new Action("BLUE", _("Show blueprint"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KeyState(KEYCODE_n, 'n'));
		act->addDefaultInputMapping("n"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "awakening") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ACTNXT", _("Next action"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("PAGEDOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ACTPRV", _("Previous action"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("PAGEUP"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_END);
		act->addDefaultInputMapping("END"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "carolreed4") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_TAB, ASCII_TAB));
		act->addDefaultInputMapping("TAB"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("VOLMAX", _("Volume max"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("PAGEUP"); // extra keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_UP"
		gameKeyMap->addAction(act);

		act = new Action("VOLOFF", _("Volume off"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("PAGEDOWN"); // extra keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_DOWN"
		gameKeyMap->addAction(act);
	} else if (gameId == "carolreed5") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_TAB, ASCII_TAB));
		act->addDefaultInputMapping("TAB"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "erinmyers") {
		act = new Action("GUIB", _("Change font size"));
		act->setKeyEvent(KEYCODE_END);
		act->addDefaultInputMapping("END"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "escapemansion") {
		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);

		// I18N: Displays a debug text message
		act = new Action("DBGTXT", _("Debug print"));
		act->setKeyEvent(KEYCODE_F2);
		act->addDefaultInputMapping("F2"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "facenoir") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // original mouse
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("UP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("DOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "foxtail") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // original mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PAGEUP", _("Previous page"));
		act->setKeyEvent(KEYCODE_PAGEUP);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("PAGEUP"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PAGEDN", _("Next page"));
		act->setKeyEvent(KEYCODE_PAGEDOWN);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("PAGEDOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionSave, _("Save game"));
		act->setKeyEvent(KEYCODE_F2);
		act->addDefaultInputMapping("F2"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionLoad, _("Load game"));
		act->setKeyEvent(KEYCODE_F3);
		act->addDefaultInputMapping("F3"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("QSAVE", _("Quick save"));
		act->setKeyEvent(KEYCODE_F5);
		act->addDefaultInputMapping("F5"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("SPD1", _("Walking speed: Low"));
		act->setKeyEvent(KEYCODE_F6);
		act->addDefaultInputMapping("F6"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("SPD2", _("Walking speed: Medium"));
		act->setKeyEvent(KEYCODE_F7);
		act->addDefaultInputMapping("F7"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("SPD3", _("Walking speed: High"));
		act->setKeyEvent(KEYCODE_F8);
		act->addDefaultInputMapping("F8"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("QLOAD", _("Quick load"));
		act->setKeyEvent(KEYCODE_F9);
		act->addDefaultInputMapping("F9"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("NOWAIT", _("Cancel waiting"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("CAPT", _("Toggle mouse capture"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("HOME", _("First page"));
		act->setKeyEvent(KEYCODE_HOME);
		act->addDefaultInputMapping("HOME"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("END", _("Last page"));
		act->setKeyEvent(KEYCODE_END);
		act->addDefaultInputMapping("END"); // original keyboard
		gameKeyMap->addAction(act);

		Common::String extra = ConfMan.get("extra", target);
		if (extra.hasPrefix("1.2.230.") || extra.hasPrefix("1.2.304.") || extra.hasPrefix("1.2.362.")) {
			// I18N: ultra_super_mega_fast_walk is the name of the variable used at game script for this speed
			act = new Action("SPDMAX", _("Walking speed: Ultra Super Mega Fast"));
			act->setKeyEvent(KeyState(KEYCODE_s, 's', KBD_CTRL|KBD_ALT|KBD_SHIFT));
			act->addDefaultInputMapping("C+A+S+s"); // original keyboard
			//TODO: extra joy control, e.g. "JOY_R+JOY_A"
			gameKeyMap->addAction(act);
		}

		if (extra.hasPrefix("1.2.362.")) {
			act = new Action(kStandardActionEE, _("???"));
			act->setKeyEvent(KeyState(KEYCODE_z, 'z'));
			act->addDefaultInputMapping("z"); // original keyboard
			//TODO: extra joy control, e.g. "JOY_R+JOY_B"
			gameKeyMap->addAction(act);
		}

		if (extra.hasPrefix("1.2.896.")) {
			act = new Action("CREDIT", _("Show game credits"));
			act->setKeyEvent(KEYCODE_F1);
			act->addDefaultInputMapping("F1"); // original keyboard
			gameKeyMap->addAction(act);

			act = new Action("MPLAY", _("Play selected music record"));
			act->setKeyEvent(KEYCODE_F4);
			act->addDefaultInputMapping("F4"); // original keyboard
			gameKeyMap->addAction(act);

			act = new Action("MNEXT", _("Select next music record"));
			act->setKeyEvent(KeyState(KEYCODE_TAB, ASCII_TAB));
			act->addDefaultInputMapping("TAB"); // original keyboard
			gameKeyMap->addAction(act);

			act = new Action("NOTE1", _("Play note 1: A"));
			act->setKeyEvent(KeyState(KEYCODE_d, 'd'));
			act->addDefaultInputMapping("d"); // original keyboard
			gameKeyMap->addAction(act);

			act = new Action("NOTE2", _("Play note 2: F#"));
			act->setKeyEvent(KeyState(KEYCODE_f, 'f'));
			act->addDefaultInputMapping("f"); // original keyboard
			gameKeyMap->addAction(act);

			act = new Action("NOTE3", _("Play note 3: D#"));
			act->setKeyEvent(KeyState(KEYCODE_g, 'g'));
			act->addDefaultInputMapping("g"); // original keyboard
			gameKeyMap->addAction(act);

			act = new Action("NOTE4", _("Play note 4: C#"));
			act->setKeyEvent(KeyState(KEYCODE_h, 'h'));
			act->addDefaultInputMapping("h"); // original keyboard
			gameKeyMap->addAction(act);

			act = new Action("NOTE5", _("Play note 5: E"));
			act->setKeyEvent(KeyState(KEYCODE_j, 'j'));
			act->addDefaultInputMapping("j"); // original keyboard
			gameKeyMap->addAction(act);

			act = new Action("NOTE6", _("Play note 6: G#"));
			act->setKeyEvent(KeyState(KEYCODE_k, 'k'));
			act->addDefaultInputMapping("k"); // original keyboard
			gameKeyMap->addAction(act);

			act = new Action("NOTE7", _("Play note 7: B"));
			act->setKeyEvent(KeyState(KEYCODE_l, 'l'));
			act->addDefaultInputMapping("l"); // original keyboard
			gameKeyMap->addAction(act);
		}
	} else if (gameId == "ghostsheet") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_TAB, ASCII_TAB));
		act->addDefaultInputMapping("TAB"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ABLT1", _("Ability: Telekinesis"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ABLT2", _("Ability: Push"));
		act->setKeyEvent(KEYCODE_F2);
		act->addDefaultInputMapping("F2"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ABLT3", _("Ability: Lightning"));
		act->setKeyEvent(KEYCODE_F3);
		act->addDefaultInputMapping("F3"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ABLT4", _("Ability: Light"));
		act->setKeyEvent(KEYCODE_F4);
		act->addDefaultInputMapping("F4"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ABLT5", _("Ability: Wind"));
		act->setKeyEvent(KEYCODE_F5);
		act->addDefaultInputMapping("F5"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ABLT6", _("Ability: Sound"));
		act->setKeyEvent(KEYCODE_F6);
		act->addDefaultInputMapping("F6"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ABLT7", _("Ability: Esence"));
		act->setKeyEvent(KEYCODE_F7);
		act->addDefaultInputMapping("F7"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ABLT8", _("Ability: Exorcist"));
		act->setKeyEvent(KEYCODE_F8);
		act->addDefaultInputMapping("F8"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionSkip, _("Skip"));
		act->setKeyEvent(KeyState(KEYCODE_BACKSPACE, ASCII_BACKSPACE));
		act->addDefaultInputMapping("BACKSPACE"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);

		act = new Action("SCRS", _("Save screenshot"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "helga") {
		act = new Action("PAGEUP", _("Previous page"));
		act->setKeyEvent(KEYCODE_PAGEUP);
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("PAGEUP"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PAGEDN", _("Next page"));
		act->setKeyEvent(KEYCODE_PAGEDOWN);
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("PAGEDOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONEX", _("Phone cancel button"));
		act->setKeyEvent(KeyState(KEYCODE_BACKSPACE, ASCII_BACKSPACE));
		act->addDefaultInputMapping("BACKSPACE"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEU", _("Phone up button"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONED", _("Phone down button"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONE0", _("Phone 0 button"));
		act->setKeyEvent(KeyState(KEYCODE_0, '0'));
		act->addDefaultInputMapping("0"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE1", _("Phone 1 button"));
		act->setKeyEvent(KeyState(KEYCODE_1, '1'));
		act->addDefaultInputMapping("1"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE2", _("Phone 2 button"));
		act->setKeyEvent(KeyState(KEYCODE_2, '2'));
		act->addDefaultInputMapping("2"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE3", _("Phone 3 button"));
		act->setKeyEvent(KeyState(KEYCODE_3, '3'));
		act->addDefaultInputMapping("3"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE4", _("Phone 4 button"));
		act->setKeyEvent(KeyState(KEYCODE_4, '4'));
		act->addDefaultInputMapping("4"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE5", _("Phone 5 button"));
		act->setKeyEvent(KeyState(KEYCODE_5, '5'));
		act->addDefaultInputMapping("5"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE6", _("Phone 6 button"));
		act->setKeyEvent(KeyState(KEYCODE_6, '6'));
		act->addDefaultInputMapping("6"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE7", _("Phone 7 button"));
		act->setKeyEvent(KeyState(KEYCODE_7, '7'));
		act->addDefaultInputMapping("7"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE8", _("Phone 8 button"));
		act->setKeyEvent(KeyState(KEYCODE_8, '8'));
		act->addDefaultInputMapping("8"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE9", _("Phone 9 button"));
		act->setKeyEvent(KeyState(KEYCODE_9, '9'));
		act->addDefaultInputMapping("9"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEA", _("Phone * button"));
		act->setKeyEvent(KeyState(KEYCODE_ASTERISK, '*'));
		act->addDefaultInputMapping("ASTERISK"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONEH", _("Phone # button"));
		act->setKeyEvent(KeyState(KEYCODE_HASH, '#'));
		act->addDefaultInputMapping("HASH"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "knossos") {
		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KeyState(KEYCODE_a, 'a', KBD_SHIFT));
		act->addDefaultInputMapping("S+a"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "jamesperis") {
		act = new Action("HINT", _("Show hints / Dance move"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveUp, _("Dance move up"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveDown, _("Dance move down"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Dance move left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Dance move right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PAGEUP", _("Previous page"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action("PAGEDN", _("Next page"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		act->addDefaultInputMapping("PAGEDOWN"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "jamesperis2") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PAGEUP", _("Previous page"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action("PAGEDN", _("Next page"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionLoad, _("Load game"));
		act->setKeyEvent(KEYCODE_F5);
		act->addDefaultInputMapping("F5"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KeyState(KEYCODE_t, 't', KBD_CTRL));
		act->addDefaultInputMapping("C+t"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "julia") {
		act = new Action(kStandardActionSkip, _("Skip"));
		act->setKeyEvent(KEYCODE_F12);
		act->addDefaultInputMapping("F12"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "juliastars") {
		act = new Action("CANCEL", _("Cancel input"));
		act->setKeyEvent(KEYCODE_BACKSPACE);
		act->addDefaultInputMapping("BACKSPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveUp, _("Up"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveDown, _("Down"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("NOWAIT", _("Cancel waiting"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "looky") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("UP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("DOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRS", _("Save screenshot"));
		act->setKeyEvent(KEYCODE_F12);
		act->addDefaultInputMapping("F12"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "lotl") {
		act = new Action("SUBS", _("Toggle subtitles"));
		act->setKeyEvent(KeyState(KEYCODE_t, 't'));
		act->addDefaultInputMapping("t"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("PAGEUP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("PAGEDOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "lostbride") {
		act = new Action("HELP", _("Show help"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveUp, _("Up"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveDown, _("Down"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KeyState(KEYCODE_SLASH, 0, KBD_SHIFT));
		act->addDefaultInputMapping("S+SLASH"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_A+JOY_B"
		gameKeyMap->addAction(act);

		act = new Action("HINT", _("???"));
		act->setKeyEvent(KeyState(KEYCODE_s, 's'));
		act->addDefaultInputMapping("s"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_A"
		gameKeyMap->addAction(act);

		act = new Action("NOHINT", _("Hide hints"));
		act->setKeyEvent(KeyState(KEYCODE_h, 'h'));
		act->addDefaultInputMapping("h"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "mentalrepairs") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("HELP", _("Show help"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "mythguff") {
		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("UP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("DOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "oknytt") {
		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_TAB, ASCII_TAB));
		act->addDefaultInputMapping("TAB"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "onehelluvaday") {
		act = new Action(kStandardActionMoveUp, _("Up"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveDown, _("Down"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		// I18N: At one of the puzzles game asks to press Up key / Shift key / Down key
		act = new Action("SHIFT", _("Shift key"));
		act->setKeyEvent(KEYCODE_RSHIFT);
		act->addDefaultInputMapping("LSHIFT"); // original keyboard control
		act->addDefaultInputMapping("RSHIFT"); // original keyboard control
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "palladion") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRS", _("Save screenshot"));
		act->setKeyEvent(KEYCODE_F12);
		act->addDefaultInputMapping("F12"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "papasdaughters1") {
		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("UP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("DOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "papasdaughters2") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("UP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("DOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "petka02") {
		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_i, 'i'));
		act->addDefaultInputMapping("i"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("MAP", _("Show map"));
		act->setKeyEvent(KeyState(KEYCODE_m, 'm'));
		act->addDefaultInputMapping("TAB"); // original keyboard
		act->addDefaultInputMapping("F1"); // original keyboard
		act->addDefaultInputMapping("m"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("LOOK", _("Look at"));
		act->setKeyEvent(KeyState(KEYCODE_l, 'l'));
		act->addDefaultInputMapping("1"); // original keyboard
		act->addDefaultInputMapping("l"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("WALK", _("Walk to"));
		act->setKeyEvent(KeyState(KEYCODE_w, 'w'));
		act->addDefaultInputMapping("2"); // original keyboard
		act->addDefaultInputMapping("w"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PICK", _("Pick up"));
		act->setKeyEvent(KeyState(KEYCODE_g, 'g'));
		act->addDefaultInputMapping("3"); // original keyboard
		act->addDefaultInputMapping("g"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("USE", _("Use"));
		act->setKeyEvent(KeyState(KEYCODE_u, 'u'));
		act->addDefaultInputMapping("4"); // original keyboard
		act->addDefaultInputMapping("u"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("TALK", _("Talk to"));
		act->setKeyEvent(KeyState(KEYCODE_t, 't'));
		act->addDefaultInputMapping("5"); // original keyboard
		act->addDefaultInputMapping("t"); // original keyboard
		gameKeyMap->addAction(act);

		// I18N: Chapayev is the name of game character, Vasily Chapayev
		// This action makes Chapayev interact with item instead of Petka
		act = new Action("ALTUSE", _("Chapayev's action"));
		act->setKeyEvent(KeyState(KEYCODE_c, 'c'));
		act->addDefaultInputMapping("6"); // original keyboard
		act->addDefaultInputMapping("c"); // original keyboard
		gameKeyMap->addAction(act);

		Common::String extra = ConfMan.get("extra", target);
		if (extra.hasSuffix("2015")) {
			act = new Action(kStandardActionEE, _("???"));
			act->setKeyEvent(KeyState(KEYCODE_q, 'q'));
			act->addDefaultInputMapping("q"); // original keyboard
			//TODO: extra joy control, e.g. "JOY_R+JOY_A"
			gameKeyMap->addAction(act);

			// I18N: Displays a debug text message
			act = new Action("DBGTXT", _("Debug print"));
			act->setKeyEvent(KEYCODE_BACKSPACE);
			act->addDefaultInputMapping("BACKSPACE"); // original keyboard
			gameKeyMap->addAction(act);
		}
	} else if (gameId == "pizzamorgana") {
		act = new Action("ACTNXT", _("Next action"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_RIGHT"); // original mouse
		act->addDefaultInputMapping("RIGHTBRACKET"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("JOY_B"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ACTPRV", _("Previous action"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("LEFTBRACKET"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionSkip, _("Skip"));
		act->setKeyEvent(KeyState(KEYCODE_PERIOD, '.'));
		act->addDefaultInputMapping("PERIOD"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionPause, _("Pause"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("p"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionOpenSettings, _("Settings"));
		act->setKeyEvent(KeyState(KEYCODE_s, 's'));
		act->addDefaultInputMapping("s"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ANSWR1", _("Dialog answer 1"));
		act->setKeyEvent(KeyState(KEYCODE_1, '1'));
		act->addDefaultInputMapping("1"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ANSWR2", _("Dialog answer 2"));
		act->setKeyEvent(KeyState(KEYCODE_2, '2'));
		act->addDefaultInputMapping("2"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ANSWR3", _("Dialog answer 3"));
		act->setKeyEvent(KeyState(KEYCODE_3, '3'));
		act->addDefaultInputMapping("3"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("ANSWR4", _("Dialog answer 4"));
		act->setKeyEvent(KeyState(KEYCODE_4, '4'));
		act->addDefaultInputMapping("4"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("SCRS", _("Save screenshot"));
		act->setKeyEvent(KeyState(KEYCODE_p, 'p', KBD_SHIFT));
		act->addDefaultInputMapping("S+p"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "polechudes") {
		// I18N: This game is called "Pole Chudes" and it features a wheel similar to "Wheel of Fortune" TV show
		act = new Action("SLOWER", _("Spin wheel slower"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		// I18N: This game is called "Pole Chudes" and it features a wheel similar to "Wheel of Fortune" TV show
		act = new Action("FASTER", _("Spin wheel faster"));
		act->setKeyEvent(KEYCODE_F2);
		act->addDefaultInputMapping("F2"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "reptilesquest") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_x, 'x'));
		act->addDefaultInputMapping("x"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_i, 'i'));
		act->addDefaultInputMapping("i"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("MAP", _("Show map"));
		act->setKeyEvent(KeyState(KEYCODE_m, 'm'));
		act->addDefaultInputMapping("m"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "reversion1") {
		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_i, 'i'));
		act->addDefaultInputMapping("i"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "reversion2" ||
		gameId == "reversion3"
	) {
		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_i, 'i'));
		act->addDefaultInputMapping("i"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveUp, _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("UP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveDown, _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("DOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "ritter") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionSkip, _("Skip"));
		act->setKeyEvent(KeyState(KEYCODE_BACKSPACE, ASCII_BACKSPACE));
		act->addDefaultInputMapping("BACKSPACE"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "shaban") {
		act = new Action("MAP", _("Show map"));
		act->setKeyEvent(KeyState(KEYCODE_m, 'm'));
		act->addDefaultInputMapping("m"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "sof1" ||
		gameId == "sof2"
	) {
		act = new Action("ZOOMOT", _("Zoom out"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("PAGEUP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ZOOMIN", _("Zoom in"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("PAGEDOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("MAP", _("Show map"));
		act->setKeyEvent(KeyState(KEYCODE_m, 'm'));
		act->addDefaultInputMapping("m"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("JRNL", _("Show journal"));
		act->setKeyEvent(KeyState(KEYCODE_n, 'n'));
		act->addDefaultInputMapping("n"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "sotv1") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("MAP", _("Show map"));
		act->setKeyEvent(KeyState(KEYCODE_m, 'm'));
		act->addDefaultInputMapping("m"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ACTNXT", _("Next action"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("PAGEDOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ACTPRV", _("Previous action"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("PAGEUP"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setMiddleClickEvent();
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // original mouse
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "sotv2") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("MAP", _("Show map"));
		act->setKeyEvent(KeyState(KEYCODE_m, 'm'));
		act->addDefaultInputMapping("m"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ACTNXT", _("Next action"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("PAGEDOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ACTPRV", _("Previous action"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("PAGEUP"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("PHONE1", _("Phone 1 button"));
		act->setKeyEvent(KeyState(KEYCODE_1, '1'));
		act->addDefaultInputMapping("1"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE2", _("Phone 2 button"));
		act->setKeyEvent(KeyState(KEYCODE_2, '2'));
		act->addDefaultInputMapping("2"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("PHONE3", _("Phone 3 button"));
		act->setKeyEvent(KeyState(KEYCODE_3, '3'));
		act->addDefaultInputMapping("3"); // original keyboard
		gameKeyMap->addAction(act);

		// I18N: Displays a debug text message
		act = new Action("DBGTXT", _("Debug print"));
		act->setKeyEvent(KEYCODE_F6);
		act->addDefaultInputMapping("F6"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setMiddleClickEvent();
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // original mouse
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "tib") {
		act = new Action("SCRS", _("Save screenshot"));
		act->setKeyEvent(KEYCODE_F9);
		act->addDefaultInputMapping("F9"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "thelastcrownmh") {
		act = new Action("EXIT", _("Exit"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		gameKeyMap->addAction(act);

		// I18N: Debug feature to draw lines of scene geometry: walls, walking areas, etc
		act = new Action("DBGSCN", _("Show scene geometry"));
		act->setKeyEvent(KEYCODE_F2);
		act->addDefaultInputMapping("F2"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRS", _("Save screenshot"));
		act->setKeyEvent(KEYCODE_F3);
		act->addDefaultInputMapping("F3"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionOpenSettings, _("Settings"));
		act->setKeyEvent(KEYCODE_F4);
		act->addDefaultInputMapping("F4"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("NOWAIT", _("Cancel waiting"));
		act->setKeyEvent(KEYCODE_F5);
		act->addDefaultInputMapping("F5"); // original keyboard
		gameKeyMap->addAction(act);

		// I18N: Displays a debug text message
		act = new Action("DBGTXT", _("Debug print"));
		act->setKeyEvent(KEYCODE_F6);
		act->addDefaultInputMapping("F6"); // original keyboard
		gameKeyMap->addAction(act);

		// I18N: Displays a debug interface with Bezier curves
		act = new Action("DBGBEZ", _("Bezier window"));
		act->setKeyEvent(KEYCODE_F7);
		act->addDefaultInputMapping("F7"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "thelostcrowngha") {
		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);

		act = new Action("SCRS", _("Save screenshot"));
		act->setKeyEvent(KEYCODE_F3);
		act->addDefaultInputMapping("F3"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "twc") {
		// I18N: Use droid to perform an action
		act = new Action("ALTUSE", _("Droid's action"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveUp, _("Up"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveDown, _("Down"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIA", _("GUI variant A"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		gameKeyMap->addAction(act);

		act = new Action("GUIB", _("GUI variant B"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_HOME);
		act->addDefaultInputMapping("HOME"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "vsevolod") {
		act = new Action("INV", _("Show inventory"));
		act->setKeyEvent(KeyState(KEYCODE_i, 'i'));
		act->addDefaultInputMapping("i"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("JRNL", _("Show journal"));
		act->setKeyEvent(KeyState(KEYCODE_j, 'j'));
		act->addDefaultInputMapping("j"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionOpenSettings, _("Settings"));
		act->setKeyEvent(KeyState(KEYCODE_m, 'm'));
		act->addDefaultInputMapping("m"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("UP"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		act->addDefaultInputMapping("DOWN"); // extra keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "wayoflove") {
		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("GUIA", _("GUI variant A"));
		act->setKeyEvent(KEYCODE_F10);
		act->addDefaultInputMapping("F10"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		gameKeyMap->addAction(act);

		act = new Action("GUIB", _("GUI variant B"));
		act->setKeyEvent(KEYCODE_F11);
		act->addDefaultInputMapping("F11"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionEE, _("???"));
		act->setKeyEvent(KEYCODE_HOME);
		act->addDefaultInputMapping("HOME"); // original keyboard
		//TODO: extra joy control, e.g. "JOY_R+JOY_B"
		gameKeyMap->addAction(act);
	} else if (gameId == "wtetris") {
		// I18N: It's a Tetris game clone, this action rotates current tetris item
		act = new Action("ROTATE", _("Rotate"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("MOUSE_RIGHT"); // extra mouse
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("KP4"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // extra mouse
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("KP6"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // extra mouse
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		// I18N: It's a Tetris game clone, this action drops current tetris item
		act = new Action("DROP", _("Drop"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("KP2"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);
	} else if (gameId == "zilm") {
		act = new Action("P1UP", _("Player 1: Up"));
		act->setKeyEvent(KeyState(KEYCODE_w, 'w'));
		act->addDefaultInputMapping("w"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("P1LT", _("Player 1: Left"));
		act->setKeyEvent(KeyState(KEYCODE_a, 'a'));
		act->addDefaultInputMapping("a"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("P1DN", _("Player 1: Down"));
		act->setKeyEvent(KeyState(KEYCODE_s, 's'));
		act->addDefaultInputMapping("s"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("P1RT", _("Player 1: Right"));
		act->setKeyEvent(KeyState(KEYCODE_d, 'd'));
		act->addDefaultInputMapping("d"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("P2UP", _("Player 2: Up"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("P2LT", _("Player 2: Left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("P2DN", _("Player 2: Down"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("P2RT", _("Player 2: Right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		gameKeyMap->addAction(act);

		// I18N: Displays a debug FPS counter
		act = new Action("DBGFPS", _("Debug FPS"));
		act->setKeyEvent(KEYCODE_F2);
		act->addDefaultInputMapping("F2"); // original keyboard
		gameKeyMap->addAction(act);
	} else if (gameId == "zbang") {
		act = new Action("ACTNXT", _("Next action"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_RIGHT"); // original mouse
		act->addDefaultInputMapping("RIGHTBRACKET"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		act->addDefaultInputMapping("JOY_B"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action("ACTPRV", _("Previous action"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("LEFTBRACKET"); // original keyboard
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action("HINT", _("Show hints"));
		act->setKeyEvent(KeyState(KEYCODE_TAB, ASCII_TAB));
		act->addDefaultInputMapping("TAB"); // original keyboard
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // extra mouse
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionSkip, _("Skip"));
		act->setKeyEvent(KeyState(KEYCODE_PERIOD, '.'));
		act->addDefaultInputMapping("PERIOD"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveUp, _("Move forward"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Turn left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Turn right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);
	} else {
		warning("Autogenerated keymap for unknown WME game, id '%s', target '%s'", gameId.c_str(), target);

		act = new Action("SPACE", _("Space"));
		act->setKeyEvent(KeyState(KEYCODE_SPACE, ASCII_SPACE));
		act->addDefaultInputMapping("SPACE"); // original keyboard
		act->addDefaultInputMapping("JOY_Y"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Left"));
		act->setKeyEvent(KEYCODE_LEFT);
		act->addDefaultInputMapping("LEFT"); // original keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Right"));
		act->setKeyEvent(KEYCODE_RIGHT);
		act->addDefaultInputMapping("RIGHT"); // original keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveUp, _("Up"));
		act->setKeyEvent(KEYCODE_UP);
		act->addDefaultInputMapping("UP"); // original keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMoveDown, _("Down"));
		act->setKeyEvent(KEYCODE_DOWN);
		act->addDefaultInputMapping("DOWN"); // original keyboard
		act->addDefaultInputMapping("JOY_DOWN"); // extra joy
		gameKeyMap->addAction(act);

		act = new Action(kStandardActionMiddleClick, _("Middle click"));
		act->setMiddleClickEvent();
		act->addDefaultInputMapping("MOUSE_MIDDLE"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action("SCRLUP", _("Scroll up"));
		act->setMouseWheelUpEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_UP"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action("SCRLDN", _("Scroll down"));
		act->setMouseWheelDownEvent();
		act->addDefaultInputMapping("MOUSE_WHEEL_DOWN"); // original mouse
		gameKeyMap->addAction(act);

		act = new Action("KEYF1", _("F1"));
		act->setKeyEvent(KEYCODE_F1);
		act->addDefaultInputMapping("F1"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("KEYI", _("Key i"));
		act->setKeyEvent(KeyState(KEYCODE_i, 'i'));
		act->addDefaultInputMapping("i"); // original keyboard
		gameKeyMap->addAction(act);

		act = new Action("TAB", _("Tab"));
		act->setKeyEvent(KeyState(KEYCODE_TAB, ASCII_TAB));
		act->addDefaultInputMapping("TAB"); // original keyboard
		gameKeyMap->addAction(act);
	}
	result.push_back(gameKeyMap);


	if (gameId == "carolreed4" ||
		gameId == "carolreed5" ||
		gameId == "carolreed6" ||
		gameId == "carolreed7" ||
		gameId == "carolreed8" ||
		gameId == "carolreed9" ||
		gameId == "carolreed10" ||
		gameId == "carolreed11" ||
		gameId == "carolreed12" ||
		gameId == "carolreed13" ||
		gameId == "carolreed14" ||
		gameId == "carolreed15" ||
		gameId == "carolreed16" ||
		gameId == "corrosion" ||
		gameId == "rebeccacarlson1" ||
		gameId == "rhiannon"
	) {
		act = new Action(kStandardActionMoveUp, _("Move forward"));
		act->setCustomEngineActionEvent(kClickAtEntityNearestToCenter);
		act->addDefaultInputMapping("UP"); // extra keyboard
		act->addDefaultInputMapping("KP5"); // extra keyboard
		act->addDefaultInputMapping("JOY_UP"); // extra joy
		extraKeyMap->addAction(act);

		act = new Action(kStandardActionMoveLeft, _("Turn left"));
		act->setCustomEngineActionEvent(kClickAtLeft);
		act->addDefaultInputMapping("LEFT"); // extra keyboard
		act->addDefaultInputMapping("KP4"); // extra keyboard
		act->addDefaultInputMapping("JOY_LEFT"); // extra joy
		extraKeyMap->addAction(act);

		act = new Action(kStandardActionMoveRight, _("Turn right"));
		act->setCustomEngineActionEvent(kClickAtRight);
		act->addDefaultInputMapping("RIGHT"); // extra keyboard
		act->addDefaultInputMapping("KP6"); // extra keyboard
		act->addDefaultInputMapping("JOY_RIGHT"); // extra joy
		extraKeyMap->addAction(act);

		if (gameId != "rhiannon") {
			act = new Action(kStandardActionMoveDown, _("Move backwards"));
			act->setCustomEngineActionEvent(kClickAtBottom);
			act->addDefaultInputMapping("DOWN"); // extra keyboard
			act->addDefaultInputMapping("KP2"); // extra keyboard
			act->addDefaultInputMapping("JOY_DOWN"); // extra joy
			extraKeyMap->addAction(act);
		}
	}
	result.push_back(extraKeyMap);

	return result;

}

} // End of namespace Wintermute
