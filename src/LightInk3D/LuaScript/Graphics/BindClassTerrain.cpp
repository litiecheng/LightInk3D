

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
#include "Graphics/Material.h"
#include "Graphics/Terrain.h"
#include "Graphics/TerrainPatch.h"
#include "Resource/Image.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Terrain(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Terrain, void ()>(lm.state(), "Terrain", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<Terrain>, "new")
				.def(&Terrain::SetPatchSize, "SetPatchSize")
				.def(&Terrain::SetSpacing, "SetSpacing")
				.def(&Terrain::SetMaxLodLevels, "SetMaxLodLevels")
				.def(&Terrain::SetOcclusionLodLevel, "SetOcclusionLodLevel")
				.def(&Terrain::SetSmoothing, "SetSmoothing")
				.def(&Terrain::SetHeightMap, "SetHeightMap")
				.def(&Terrain::SetMaterial, "SetMaterial")
				.def(&Terrain::SetDrawDistance, "SetDrawDistance")
				.def(&Terrain::SetShadowDistance, "SetShadowDistance")
				.def(&Terrain::SetLodBias, "SetLodBias")
				.def(&Terrain::SetViewMask, "SetViewMask")
				.def(&Terrain::SetLightMask, "SetLightMask")
				.def(&Terrain::SetShadowMask, "SetShadowMask")
				.def(&Terrain::SetZoneMask, "SetZoneMask")
				.def(&Terrain::SetMaxLights, "SetMaxLights")
				.def(&Terrain::SetCastShadows, "SetCastShadows")
				.def(&Terrain::SetOccluder, "SetOccluder")
				.def(&Terrain::SetOccludee, "SetOccludee")
				.def(&Terrain::ApplyHeightMap, "ApplyHeightMap")
				.def(&Terrain::GetPatchSize, "GetPatchSize")
				.def(&Terrain::GetSpacing, "GetSpacing")
				.def(&Terrain::GetNumVertices, "GetNumVertices")
				.def(&Terrain::GetNumPatches, "GetNumPatches")
				.def(&Terrain::GetMaxLodLevels, "GetMaxLodLevels")
				.def(&Terrain::GetOcclusionLodLevel, "GetOcclusionLodLevel")
				.def(&Terrain::GetSmoothing, "GetSmoothing")
				.def(&Terrain::GetHeightMap, "GetHeightMap")
				.def(&Terrain::GetMaterial, "GetMaterial")
				.def(static_cast<TerrainPatch*(Terrain::*)(unsigned int) const>(&Terrain::GetPatch), "GetPatchU")
				.def(static_cast<TerrainPatch*(Terrain::*)(int, int) const>(&Terrain::GetPatch), "GetPatchII")
				.def(&Terrain::GetHeight, "GetHeight")
				.def(&Terrain::GetNormal, "GetNormal")
				.def(&Terrain::WorldToHeightMap, "WorldToHeightMap")
				.def(&Terrain::UpdatePatchLod, "UpdatePatchLod")
				
		];
	}
}

