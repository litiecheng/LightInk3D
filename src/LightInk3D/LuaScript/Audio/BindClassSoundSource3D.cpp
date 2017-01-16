

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

#include "Audio/SoundSource3D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_SoundSource3D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<SoundSource3D, void (Context *)>(lm.state(), "SoundSource3D", BaseClassStrategy<SoundSource>())
				.disable_new()
				.def(CreateObject<SoundSource3D>, "new")
				.def(&SoundSource3D::SetDistanceAttenuation, "SetDistanceAttenuation")
				.def(&SoundSource3D::SetAngleAttenuation, "SetAngleAttenuation")
				.def(&SoundSource3D::SetNearDistance, "SetNearDistance")
				.def(&SoundSource3D::SetFarDistance, "SetFarDistance")
				.def(&SoundSource3D::SetInnerAngle, "SetInnerAngle")
				.def(&SoundSource3D::SetOuterAngle, "SetOuterAngle")
				.def(&SoundSource3D::SetRolloffFactor, "SetRolloffFactor")
				.def(&SoundSource3D::CalculateAttenuation, "CalculateAttenuation")
				.def(&SoundSource3D::GetNearDistance, "GetNearDistance")
				.def(&SoundSource3D::GetFarDistance, "GetFarDistance")
				.def(&SoundSource3D::GetInnerAngle, "GetInnerAngle")
				.def(&SoundSource3D::GetOuterAngle, "GetOuterAngle")
				.def(&SoundSource3D::RollAngleoffFactor, "RollAngleoffFactor")
		];
				
	}
}

