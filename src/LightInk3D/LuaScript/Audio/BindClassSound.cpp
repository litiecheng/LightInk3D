

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

#include "Audio/Sound.h"
#include "IO/File.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;
	static bool SoundLoadRawS(Sound* sound, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return sound->LoadRaw(*file);
	}

	static bool SoundLoadRawF(Sound* sound, Deserializer * source)
	{
		return sound->LoadRaw(*source);
	}
	
	static bool SoundLoadWavS(Sound* sound, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return sound->LoadWav(*file);
	}
	
	static bool SoundLoadWavF(Sound* sound, Deserializer * source)
	{
		return sound->LoadWav(*source);
	}


	static bool SoundLoadOggVorbisS(Sound* sound, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return sound->LoadOggVorbis(*file);
	}
	
	static bool SoundLoadOggVorbisF(Sound* sound, Deserializer * source)
	{
		return sound->LoadOggVorbis(*source);
	}
	
	void bind_class_Sound(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Sound, void (Context *)>(lm.state(), "Sound", BaseClassStrategy<Resource>())
				.disable_new()
				.def(CreateObject<Sound>, "new")
				.def(SoundLoadRawF, "LoadRaw")
				.def(SoundLoadRawS, "LoadRawS")
				.def(SoundLoadWavF, "LoadWav")
				.def(SoundLoadWavS, "LoadWavS")
				.def(SoundLoadOggVorbisF, "LoadOggVorbis")
				.def(SoundLoadOggVorbisS, "LoadOggVorbisS")
				.def(&Sound::SetSize, "SetSize")
				.def(&Sound::SetData, "SetData")
				.def(&Sound::SetFormat, "SetFormat")
				.def(&Sound::SetLooped, "SetLooped")
				.def(&Sound::SetLoop, "SetLoop")
				.def(&Sound::GetLength, "GetLength")
				.def(&Sound::GetDataSize, "GetDataSize")
				.def(&Sound::GetSampleSize, "GetSampleSize")
				.def(&Sound::GetFrequency, "GetFrequency")
				.def(&Sound::GetIntFrequency, "GetIntFrequency")
				.def(&Sound::IsLooped, "IsLooped")
				.def(&Sound::IsSixteenBit, "IsSixteenBit")
				.def(&Sound::IsStereo, "IsStereo")
				.def(&Sound::IsCompressed, "IsCompressed")
				.def(&Sound::FixInterpolation, "FixInterpolation")
		];
		
	}
}

