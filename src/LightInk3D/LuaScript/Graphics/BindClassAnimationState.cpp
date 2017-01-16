

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
#include "Graphics/AnimatedModel.h"
#include "Graphics/Animation.h"
#include "Graphics/AnimationState.h"
#include "Scene/Node.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_AnimationState(LuaModule & lm)
	{
		lm
		[
			LuaRegister<AnimationState, void (AnimatedModel*, Animation*)>(lm.state(), "AnimationState", BaseClassStrategy<RefCounted>())
				.def(&AnimationState::SetStartBone, "SetStartBone")
				.def(&AnimationState::SetLooped, "SetLooped")
				.def(&AnimationState::SetWeight, "SetWeight")
				.def(&AnimationState::SetBlendMode, "SetBlendMode")
				.def(&AnimationState::SetTime, "SetTime")
				.def(static_cast<void (AnimationState::*)(unsigned int, float, bool)>(&AnimationState::SetBoneWeight), "SetBoneWeightUFB")
				.def(static_cast<void (AnimationState::*)(const String&, float, bool)>(&AnimationState::SetBoneWeight), "SetBoneWeightSFB")
				.def(&AnimationState::AddWeight, "AddWeight")
				.def(&AnimationState::AddTime, "AddTime")
				.def(&AnimationState::SetLayer, "SetLayer")
				.def(&AnimationState::GetAnimation, "GetAnimation")
				.def(&AnimationState::GetModel, "GetModel")
				.def(&AnimationState::GetNode, "GetNode")
				.def(&AnimationState::GetStartBone, "GetStartBone")
				.def(static_cast<float(AnimationState::*)(unsigned) const>(&AnimationState::GetBoneWeight), "GetBoneWeight")
				.def(static_cast<float(AnimationState::*)(const String&) const>(&AnimationState::GetBoneWeight), "GetBoneWeight")
				.def(static_cast<unsigned(AnimationState::*)(const String&) const>(&AnimationState::GetTrackIndex), "GetTrackIndex")
				.def(&AnimationState::IsEnabled, "IsEnabled")
				.def(&AnimationState::IsLooped, "IsLooped")
				.def(&AnimationState::GetWeight, "GetWeight")
				.def(&AnimationState::GetBlendMode, "GetBlendMode")
				.def(&AnimationState::GetTime, "GetTime")
				.def(&AnimationState::GetLength, "GetLength")
				.def(&AnimationState::GetLayer, "GetLayer")
				.def(&AnimationState::Apply, "Apply")

		];
	}
}

