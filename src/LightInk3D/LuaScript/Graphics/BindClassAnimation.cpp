

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
#include "Graphics/Animation.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Animation(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Animation, void ()>(lm.state(), "Animation", BaseClassStrategy<Resource>())
				.disable_new()
				.def(CreateObject<Animation>, "new")
				.def(&Animation::SetAnimationName, "SetAnimationName")
				.def(&Animation::SetLength, "SetLength")
				.def(&Animation::CreateTrack, "CreateTrack")
				.def(&Animation::RemoveTrack, "RemoveTrack")
				.def(&Animation::RemoveAllTracks, "RemoveAllTracks")
				.def(&Animation::SetTrigger, "SetTrigger")
				.def(static_cast<void(Animation::*)(const AnimationTriggerPoint&)>(&Animation::AddTrigger), "AddTriggerATP")
				.def(static_cast<void(Animation::*)(float, bool, const Variant&)>(&Animation::AddTrigger), "AddTriggerFBV")
				.def(&Animation::RemoveTrigger, "RemoveTrigger")
				.def(&Animation::RemoveAllTriggers, "RemoveAllTriggers")
				.def(&Animation::Clone, "Clone")
				.def(&Animation::GetAnimationName, "GetAnimationName")
				.def(&Animation::GetAnimationNameHash, "GetAnimationNameHash")
				.def(&Animation::GetLength, "GetLength")
				.def(&Animation::GetNumTracks, "GetNumTracks")
				.def(static_cast<AnimationTrack*(Animation::*)(const String&)>(&Animation::GetTrack), "GetTrack")
				.def(&Animation::GetNumTriggers, "GetNumTriggers")
				.def(&Animation::GetTrigger, "GetTrigger")
			<=
			LuaRegister<AnimationTriggerPoint, void ()>(lm.state(), "AnimationTriggerPoint")
				.def(&AnimationTriggerPoint::time_, "time")
				.def(&AnimationTriggerPoint::data_, "data")
			<=
			LuaRegister<AnimationTrack, void ()>(lm.state(), "AnimationTrack")
				.def(&AnimationTrack::SetKeyFrame, "SetKeyFrame")
				.def(&AnimationTrack::AddKeyFrame, "AddKeyFrame")
				.def(&AnimationTrack::InsertKeyFrame, "InsertKeyFrame")
				.def(&AnimationTrack::RemoveKeyFrame, "RemoveKeyFrame")
				.def(&AnimationTrack::RemoveAllKeyFrames, "RemoveAllKeyFrames")
				.def(&AnimationTrack::GetKeyFrame, "GetKeyFrame")
				.def(&AnimationTrack::GetNumKeyFrames, "GetNumKeyFrames")
				.def(&AnimationTrack::name_, "name")
				.def(&AnimationTrack::nameHash_, "nameHash")
				.def(&AnimationTrack::channelMask_, "channelMask")
				.def(&AnimationTrack::keyFrames_, "keyFrames")
			<=
			LuaRegister<AnimationKeyFrame, void ()>(lm.state(), "AnimationKeyFrame")
				.def(&AnimationKeyFrame::time_, "time")
				.def(&AnimationKeyFrame::position_, "position")
				.def(&AnimationKeyFrame::rotation_, "rotation")
				.def(&AnimationKeyFrame::scale_, "scale")
		];
	}
}

