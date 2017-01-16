

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
#include "Container/ArrayPtr.h"
#include "Graphics/Geometry.h"
#include "Graphics/Material.h"
#include "Graphics/Terrain.h"
#include "Graphics/TerrainPatch.h"
#include "Graphics/VertexBuffer.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_TerrainPatch(LuaModule & lm)
	{
		lm
		[
			LuaRegister<TerrainPatch, void ()>(lm.state(), "TerrainPatch", BaseClassStrategy<Drawable>())
				.disable_new()
				.def(CreateObject<TerrainPatch>, "new")
				.def(&TerrainPatch::SetOwner, "SetOwner")
				.def(&TerrainPatch::SetNeighbors, "SetNeighbors")
				.def(&TerrainPatch::SetMaterial, "SetMaterial")
				.def(&TerrainPatch::SetBoundingBox, "SetBoundingBox")
				.def(&TerrainPatch::SetCoordinates, "SetCoordinates")
				.def(&TerrainPatch::ResetLod, "ResetLod")
				.def(&TerrainPatch::GetGeometry, "GetGeometry")
				.def(&TerrainPatch::GetMaxLodGeometry, "GetMaxLodGeometry")
				.def(&TerrainPatch::GetOcclusionGeometry, "GetOcclusionGeometry")
				.def(&TerrainPatch::GetVertexBuffer, "GetVertexBuffer")
				.def(&TerrainPatch::GetOwner, "GetOwner")
				.def(&TerrainPatch::GetNorthPatch, "GetNorthPatch")
				.def(&TerrainPatch::GetSouthPatch, "GetSouthPatch")
				.def(&TerrainPatch::GetWestPatch, "GetWestPatch")
				.def(&TerrainPatch::GetEastPatch, "GetEastPatch")
				.def(&TerrainPatch::GetCoordinates, "GetCoordinates")
				.def(&TerrainPatch::GetLodLevel, "GetLodLevel")
				
		];
	}
}

