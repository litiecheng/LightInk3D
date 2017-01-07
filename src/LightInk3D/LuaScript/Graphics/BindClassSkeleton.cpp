

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


#include "../../Precompiled.h"
#include "../../Graphics/Skeleton.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Skeleton(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Skeleton, void ()>(lm.state(), "Skeleton")
				.def(&Skeleton::GetNumBones, "GetNumBones")
				.def(&Skeleton::GetRootBone, "GetRootBone")
				.def(static_cast<Bone*(Skeleton::*)(unsigned int)>(&Skeleton::GetBone), "GetBoneU")
				.def(static_cast<Bone*(Skeleton::*)(const char*)>(&Skeleton::GetBone), "GetBoneC")
				.def(static_cast<Bone*(Skeleton::*)(StringHash)>(&Skeleton::GetBone), "GetBoneSH")
			<=
			LuaRegister<Bone, void ()>(lm.state(), "Bone")
				.def(&Bone::name_, "name")
				.def(&Bone::nameHash_, "nameHash")
				.def(&Bone::parentIndex_, "parentIndex")
				.def(&Bone::initialPosition_, "initialPosition")
				.def(&Bone::initialRotation_, "initialRotation")
				.def(&Bone::initialScale_, "initialScale")
				.def(&Bone::offsetMatrix_, "offsetMatrix")
				.def(&Bone::animated_, "animated")
				.def(&Bone::collisionMask_, "collisionMask")
				.def(&Bone::radius_, "radius")
				.def(&Bone::boundingBox_, "boundingBox")
				.def(&Bone::node_, "node")
		];
	}
}

