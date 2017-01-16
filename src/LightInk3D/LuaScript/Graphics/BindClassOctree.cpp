

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
#include "Graphics/DebugRenderer.h"
#include "Graphics/Octree.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static PODVector<RayQueryResult> OctreeRaycast(const Octree* self, 
		const Ray& ray,
		RayQueryLevel level = RAY_TRIANGLE,
		float maxDistance = M_INFINITY,
		unsigned char drawableFlags = DRAWABLE_ANY,
		unsigned viewMask = DEFAULT_VIEWMASK)
	{
		PODVector<RayQueryResult> result;
		RayOctreeQuery query(result, ray, level, maxDistance, drawableFlags, viewMask);
		self->Raycast(query);
		return result;
	}
	
	static RayQueryResult OctreeRaycastSingle(const Octree* self, 
		const Ray& ray, 
		RayQueryLevel level = RAY_TRIANGLE,
		float maxDistance = M_INFINITY, 
		unsigned char drawableFlags = DRAWABLE_ANY, 
		unsigned viewMask = DEFAULT_VIEWMASK)
	{
		PODVector<RayQueryResult> result;
		RayOctreeQuery query(result, ray, level, maxDistance, drawableFlags, viewMask);
		self->RaycastSingle(query);
		if (result.Size() == 0)
			return RayQueryResult();

		return result[0];
	}

	void bind_class_Octree(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Octree, void ()>(lm.state(), "Octree", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<Octree>, "new")
				.def(static_cast<void(Octree::*)(DebugRenderer*, bool)>(&Octree::DrawDebugGeometry), "DrawDebugGeometryDB")
				.def(static_cast<void(Octree::*)(bool)>(&Octree::DrawDebugGeometry), "DrawDebugGeometryB")
				.def(&Octree::SetSize, "SetSize")
				.def(&Octree::Update, "Update")
				.def(&Octree::AddManualDrawable, "AddManualDrawable")
				.def(&Octree::RemoveManualDrawable, "RemoveManualDrawable")
				.def(OctreeRaycast, "Raycast")
				.def(OctreeRaycastSingle, "RaycastSingle")
				.def(&Octree::GetNumLevels, "GetNumLevels")
				.def(&Octree::QueueUpdate, "QueueUpdate")
				
		];
	}
}

