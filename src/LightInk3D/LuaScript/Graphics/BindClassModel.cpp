

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
#include "../../Graphics/Geometry.h"
#include "../../Graphics/Model.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Model(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Model, void ()>(lm.state(), "Model", BaseClassStrategy<Resource>())
				.disable_new()
				.def(CreateObject<Model>, "new")
				.def(&Model::SetBoundingBox, "SetBoundingBox")
				.def(&Model::SetNumGeometries, "SetNumGeometries")
				.def(&Model::SetNumGeometryLodLevels, "SetNumGeometryLodLevels")
				.def(&Model::SetGeometry, "SetGeometry")
				.def(&Model::SetGeometryCenter, "SetGeometryCenter")
				.def(&Model::SetSkeleton, "SetSkeleton")
				.def(&Model::Clone, "Clone")
				.def(&Model::GetBoundingBox, "GetBoundingBox")
				.def(&Model::GetSkeleton, "GetSkeleton")
				.def(&Model::GetNumGeometries, "GetNumGeometries")
				.def(&Model::GetNumGeometryLodLevels, "GetNumGeometryLodLevels")
				.def(&Model::GetGeometries, "GetGeometries")
				.def(&Model::GetGeometryCenters, "GetGeometryCenters")
				.def(&Model::GetGeometry, "GetGeometry")
				.def(&Model::GetGeometryCenter, "GetGeometryCenter")
				.def(&Model::GetNumMorphs, "GetNumMorphs")
				.def(static_cast<const ModelMorph*(Model::*)(unsigned) const>(&Model::GetMorph), "GetMorphU")
				.def(static_cast<const ModelMorph*(Model::*)(const String&) const>(&Model::GetMorph), "GetMorphS")
				.def(static_cast<const ModelMorph*(Model::*)(StringHash) const>(&Model::GetMorph), "GetMorphSH")
				.def(&Model::GetMorphRangeStart, "GetMorphRangeStart")
				.def(&Model::GetMorphRangeCount, "GetMorphRangeCount")
				
		];
	}
}
