

/* Copyright ChenDong(Wilbur), email <baisaichen@live.com>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "Precompiled.h"

#include "Audio/Audio.h"
#include "Audio/Sound.h"
#include "Audio/SoundListener.h"
#include "Audio/SoundSource.h"
#include "LuaEngine/LuaEngine.h"
#include "LuaScript/LuaUtils.h"


namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Audio(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Audio, void (Context *)>(lm.state(), "Audio", BaseClassStrategy<Object>())
				.disable_new()
				.def(&Audio::SetMode, "SetMode")
				.def(&Audio::Play, "Play")
				.def(&Audio::Stop, "Stop")
				.def(&Audio::SetMasterGain, "SetMasterGain")
				.def(&Audio::PauseSoundType, "PauseSoundType")
				.def(&Audio::ResumeSoundType, "ResumeSoundType")
				.def(&Audio::ResumeAll, "ResumeAll")
				.def(&Audio::SetListener, "SetListener")
				.def(&Audio::StopSound, "StopSound")
				.def(&Audio::GetSampleSize, "GetSampleSize")
				.def(&Audio::GetMixRate, "GetMixRate")
				.def(&Audio::GetInterpolation, "GetInterpolation")
				.def(&Audio::IsStereo, "IsStereo")
				.def(&Audio::IsPlaying, "IsPlaying")
				.def(&Audio::IsInitialized, "IsInitialized")
				.def(&Audio::GetMasterGain, "GetMasterGain")
				.def(&Audio::IsSoundTypePaused, "IsSoundTypePaused")
				.def(&Audio::GetListener, "GetListener")
				.def(&Audio::GetSoundSources, "GetSoundSources")
				.def(&Audio::HasMasterGain, "HasMasterGain")
				.def(&Audio::AddSoundSource, "AddSoundSource")
				.def(&Audio::RemoveSoundSource, "RemoveSoundSource")
		];
	}
}

