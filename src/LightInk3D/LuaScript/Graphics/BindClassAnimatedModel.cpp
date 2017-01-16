

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
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_AnimatedModel(LuaModule & lm)
	{
		lm
		[
			LuaRegister<AnimatedModel, void ()>(lm.state(), "AnimatedModel", BaseClassStrategy<StaticModel>())
				.disable_new()
				.def(CreateObject<AnimatedModel>, "new")
				.def(&AnimatedModel::SetModel, "SetModel")
				.def(&AnimatedModel::GetModel, "GetModel")
				.def(&AnimatedModel::AddAnimationState, "AddAnimationState")
				.def(static_cast<void(AnimatedModel::*)(Animation*)>(&AnimatedModel::RemoveAnimationState), "RemoveAnimationStateA")
				.def(static_cast<void(AnimatedModel::*)(const String&)>(&AnimatedModel::RemoveAnimationState), "RemoveAnimationStateS")
				.def(static_cast<void(AnimatedModel::*)(StringHash)>(&AnimatedModel::RemoveAnimationState), "RemoveAnimationStateSH")
				.def(static_cast<void(AnimatedModel::*)(AnimationState*)>(&AnimatedModel::RemoveAnimationState), "RemoveAnimationStateAS")
				.def(static_cast<void(AnimatedModel::*)(unsigned int)>(&AnimatedModel::RemoveAnimationState), "RemoveAnimationStateU")
				.def(&AnimatedModel::RemoveAllAnimationStates, "RemoveAllAnimationStates")
				.def(&AnimatedModel::SetAnimationLodBias, "SetAnimationLodBias")
				.def(&AnimatedModel::SetUpdateInvisible, "SetUpdateInvisible")
				.def(static_cast<void(AnimatedModel::*)(unsigned int, float)>(&AnimatedModel::SetMorphWeight), "SetMorphWeightUF")
				.def(static_cast<void(AnimatedModel::*)(const String&, float)>(&AnimatedModel::SetMorphWeight), "SetMorphWeightSF")
				.def(static_cast<void(AnimatedModel::*)(StringHash, float)>(&AnimatedModel::SetMorphWeight), "SetMorphWeightSHF")
				.def(&AnimatedModel::ResetMorphWeights, "ResetMorphWeights")
				.def(&AnimatedModel::GetSkeleton, "GetSkeleton")
				.def(&AnimatedModel::GetNumAnimationStates, "GetNumAnimationStates")
				.def(static_cast<AnimationState*(AnimatedModel::*)(Animation*) const>(&AnimatedModel::GetAnimationState), "GetAnimationStateA")
				.def(static_cast<AnimationState*(AnimatedModel::*)(const String&) const>(&AnimatedModel::GetAnimationState), "GetAnimationStateS")
				.def(static_cast<AnimationState*(AnimatedModel::*)(const StringHash) const>(&AnimatedModel::GetAnimationState), "GetAnimationStateSH")
				.def(static_cast<AnimationState*(AnimatedModel::*)(unsigned int) const>(&AnimatedModel::GetAnimationState), "GetAnimationStateU")
				.def(&AnimatedModel::GetAnimationLodBias, "GetAnimationLodBias")
				.def(&AnimatedModel::GetUpdateInvisible, "GetUpdateInvisible")
				.def(&AnimatedModel::GetMorphs, "GetMorphs")
				.def(&AnimatedModel::GetNumMorphs, "GetNumMorphs")
				.def(static_cast<float(AnimatedModel::*)(unsigned) const>(&AnimatedModel::GetMorphWeight), "GetMorphWeightU")
				.def(static_cast<float(AnimatedModel::*)(const String&) const>(&AnimatedModel::GetMorphWeight), "GetMorphWeightS")
				.def(static_cast<float(AnimatedModel::*)(StringHash) const>(&AnimatedModel::GetMorphWeight), "GetMorphWeightSH")
				.def(&AnimatedModel::IsMaster, "IsMaster")
				.def(&AnimatedModel::UpdateBoneBoundingBox, "UpdateBoneBoundingBox")
				.def(&AnimatedModel::GetUpdateGeometryType, "GetUpdateGeometryType")
		];
	}
}

