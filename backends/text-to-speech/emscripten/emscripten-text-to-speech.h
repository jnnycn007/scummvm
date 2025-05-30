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

#ifndef BACKENDS_TEXT_TO_SPEECH_EMSCRIPTEN_H
#define BACKENDS_TEXT_TO_SPEECH_EMSCRIPTEN_H

#include "common/scummsys.h"

#if defined(USE_TTS) && defined(EMSCRIPTEN)

#include "common/list.h"
#include "common/str.h"
#include "common/text-to-speech.h"
#include "common/ustr.h"

class EmscriptenTextToSpeechManager final : public Common::TextToSpeechManager {
public:
	EmscriptenTextToSpeechManager();
	~EmscriptenTextToSpeechManager() override;

	bool say(const Common::U32String &str, Action action) override;

	bool stop() override;
	bool pause() override;
	bool resume() override;

	bool isSpeaking() override;
	bool isPaused() override;
	bool isReady() override;

	void setVoice(unsigned index) override;

	void setRate(int rate) override;

	void setPitch(int pitch) override;

	void setVolume(unsigned volume) override;

	void setLanguage(Common::String language) override;

	void freeVoiceData(void *data) override;

	void updateVoicesPublic() { updateVoices(); };

private:
	void updateVoices() override;
};

#endif

#endif // BACKENDS_TEXT_TO_SPEECH_EMSCRIPTEN_H
