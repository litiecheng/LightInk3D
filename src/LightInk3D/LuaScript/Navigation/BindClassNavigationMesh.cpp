

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
 
#ifdef URHO3D_NAVIGATION

#include "Precompiled.h"
#include "Navigation/NavigationMesh.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static PODVector<Vector3> NavigationMeshFindPath(NavigationMesh* self, const Vector3& start, const Vector3& end, const Vector3& extents = Vector3::ONE, const dtQueryFilter* filter = 0)
	{
		PODVector<Vector3> dest;
		self->FindPath(dest, start, end, extents, filter);
		return dest;
	}
	struct NM_VV
	{
		Vector3 hitNormal_;
		Vector3 result_;
	};
	
	static NM_VV NavigationMeshRaycast(NavigationMesh * self, const Vector3& start, const Vector3& end, const Vector3& extents = Vector3::ONE)
	{
		NM_VV vv;
		vv.result_ = self->Raycast(start, end, extents, 0, &vv.hitNormal_);
		return vv;
	}
		
	void bind_class_NavigationMesh(LuaModule & lm)
	{
		lm
		[
			LuaRegister<NavigationMesh, void ()>(lm.state(), "NavigationMesh", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<NavigationMesh>, "new")
				.def(&NavigationMesh::SetTileSize, "SetTileSize")
				.def(&NavigationMesh::SetCellSize, "SetCellSize")
				.def(&NavigationMesh::SetCellHeight, "SetCellHeight")
				.def(&NavigationMesh::SetAgentHeight, "SetAgentHeight")
				.def(&NavigationMesh::SetAgentRadius, "SetAgentRadius")
				.def(&NavigationMesh::SetAgentMaxClimb, "SetAgentMaxClimb")
				.def(&NavigationMesh::SetAgentMaxSlope, "SetAgentMaxSlope")
				.def(&NavigationMesh::SetRegionMinSize, "SetRegionMinSize")
				.def(&NavigationMesh::SetRegionMergeSize, "SetRegionMergeSize")
				.def(&NavigationMesh::SetEdgeMaxLength, "SetEdgeMaxLength")
				.def(&NavigationMesh::SetEdgeMaxError, "SetEdgeMaxError")
				.def(&NavigationMesh::SetDetailSampleDistance, "SetDetailSampleDistance")
				.def(&NavigationMesh::SetDetailSampleMaxError, "SetDetailSampleMaxError")
				.def(&NavigationMesh::SetPadding, "SetPadding")
				.def(&NavigationMesh::SetAreaCost, "SetAreaCost")
				.def(static_cast<bool(NavigationMesh::*)()>(&NavigationMesh::Build), "Build")
				.def(static_cast<bool(NavigationMesh::*)(const BoundingBox&)>(&NavigationMesh::Build), "Build")
				.def(&NavigationMesh::SetPartitionType, "SetPartitionType")
				.def(&NavigationMesh::SetDrawOffMeshConnections, "SetDrawOffMeshConnections")
				.def(&NavigationMesh::SetDrawNavAreas, "SetDrawNavAreas")
				.def(&NavigationMesh::FindNearestPoint, "FindNearestPoint")
				.def(&NavigationMesh::MoveAlongSurface, "MoveAlongSurface")
				.def(NavigationMeshFindPath, "FindPath")
				.def(&NavigationMesh::GetRandomPoint, "GetRandomPoint")
				.def(&NavigationMesh::GetRandomPointInCircle, "GetRandomPointInCircle")
				.def(&NavigationMesh::GetDistanceToWall, "GetDistanceToWall")
				.def(NavigationMeshRaycast, "Raycast")
				.def(static_cast<void (NavigationMesh::*)(bool)>(&NavigationMesh::DrawDebugGeometry), "DrawDebugGeometry")
				.def(&NavigationMesh::GetTileSize, "GetTileSize")
				.def(&NavigationMesh::GetCellSize, "GetCellSize")
				.def(&NavigationMesh::GetCellHeight, "GetCellHeight")
				.def(&NavigationMesh::GetAgentHeight, "GetAgentHeight")
				.def(&NavigationMesh::GetAgentRadius, "GetAgentRadius")
				.def(&NavigationMesh::GetAgentMaxClimb, "GetAgentMaxClimb")
				.def(&NavigationMesh::GetAgentMaxSlope, "GetAgentMaxSlope")
				.def(&NavigationMesh::GetRegionMinSize, "GetRegionMinSize")
				.def(&NavigationMesh::GetRegionMergeSize, "GetRegionMergeSize")
				.def(&NavigationMesh::GetEdgeMaxLength, "GetEdgeMaxLength")
				.def(&NavigationMesh::GetEdgeMaxError, "GetEdgeMaxError")
				.def(&NavigationMesh::GetDetailSampleDistance, "GetDetailSampleDistance")
				.def(&NavigationMesh::GetDetailSampleMaxError, "GetDetailSampleMaxError")
				.def(&NavigationMesh::GetPadding, "GetPadding")
				.def(&NavigationMesh::GetAreaCost, "GetAreaCost")
				.def(&NavigationMesh::IsInitialized, "IsInitialized")
				.def(&NavigationMesh::GetBoundingBox, "GetBoundingBox")
				.def(&NavigationMesh::GetWorldBoundingBox, "GetWorldBoundingBox")
				.def(&NavigationMesh::GetNumTiles, "GetNumTiles")
				.def(&NavigationMesh::GetPartitionType, "GetPartitionType")
				.def(&NavigationMesh::GetDrawOffMeshConnections, "GetDrawOffMeshConnections")
				.def(&NavigationMesh::GetDrawNavAreas, "GetDrawNavAreas")
			<=
			LuaRegister<NM_VV, void ()>(lm.state(), "NM_VV")
				.def(&NM_VV::hitNormal_, "hitNormal")
				.def(&NM_VV::result_, "result")
			<=
			LuaRegister<NavigationGeometryInfo, void ()>(lm.state(), "NavigationGeometryInfo")
				.def(&NavigationGeometryInfo::component_, "component")
				.def(&NavigationGeometryInfo::lodLevel_, "lodLevel")
				.def(&NavigationGeometryInfo::transform_, "transform")
				.def(&NavigationGeometryInfo::boundingBox_, "boundingBox")

		];
	}
}

#endif