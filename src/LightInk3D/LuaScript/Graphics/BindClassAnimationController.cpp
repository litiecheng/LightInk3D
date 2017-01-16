

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
#include "Graphics/AnimationController.h"
#include "Graphics/Skeleton.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_AnimationController(LuaModule & lm)
	{
		lm
		[
			LuaRegister<AnimationController, void ()>(lm.state(), "AnimationController", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<AnimationController>, "new")
				.def(&AnimationController::Play, "Play")
				.def(&AnimationController::PlayExclusive, "PlayExclusive")
				.def(&AnimationController::Stop, "Stop")
				.def(&AnimationController::StopLayer, "StopLayer")
				.def(&AnimationController::StopAll, "StopAll")
				.def(&AnimationController::Fade, "Fade")
				.def(&AnimationController::FadeOthers, "FadeOthers")
				.def(&AnimationController::SetLayer, "SetLayer")
				.def(&AnimationController::SetStartBone, "SetStartBone")
				.def(&AnimationController::SetTime, "SetTime")
				.def(&AnimationController::SetWeight, "SetWeight")
				.def(&AnimationController::SetLooped, "SetLooped")
				.def(&AnimationController::SetSpeed, "SetSpeed")
				.def(&AnimationController::SetAutoFade, "SetAutoFade")
				.def(&AnimationController::SetRemoveOnCompletion, "SetRemoveOnCompletion")
				.def(&AnimationController::SetBlendMode, "SetBlendMode")
				.def(&AnimationController::IsPlaying, "IsPlaying")
				.def(&AnimationController::IsFadingIn, "IsFadingIn")
				.def(&AnimationController::IsFadingOut, "IsFadingOut")
				.def(&AnimationController::IsAtEnd, "IsAtEnd")
				.def(&AnimationController::GetLayer, "GetLayer")
				.def(&AnimationController::GetStartBone, "GetStartBone")
				.def(&AnimationController::GetStartBoneName, "GetStartBoneName")
				.def(&AnimationController::GetTime, "GetTime")
				.def(&AnimationController::GetWeight, "GetWeight")
				.def(&AnimationController::IsLooped, "IsLooped")
				.def(&AnimationController::GetBlendMode, "GetBlendMode")
				.def(&AnimationController::GetLength, "GetLength")
				.def(&AnimationController::GetSpeed, "GetSpeed")
				.def(&AnimationController::GetFadeTarget, "GetFadeTarget")
				.def(&AnimationController::GetFadeTime, "GetFadeTime")
				.def(&AnimationController::GetAutoFade, "GetAutoFade")
				.def(&AnimationController::GetRemoveOnCompletion, "GetRemoveOnCompletion")
				.def(static_cast<AnimationState*(AnimationController::*)(const String&) const>(&AnimationController::GetAnimationState), "GetAnimationState")
		];
	}
}

