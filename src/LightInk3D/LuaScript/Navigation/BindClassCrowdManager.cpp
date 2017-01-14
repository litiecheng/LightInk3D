

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
#include "Navigation/CrowdAgent.h"
#include "Navigation/CrowdManager.h"
#include "Navigation/NavigationMesh.h"
#include "Scene/Node.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static PODVector<Vector3> CrowdManagerFindPath(CrowdManager* self, Vector3& start, const Vector3& end, int queryFilterType)
	{
		PODVector<Vector3> dest;
		self->FindPath(dest, start, end, queryFilterType);
		return dest;
	}
	struct CM_VVF
	{
		Vector3 hitPos_;
		Vector3 hitNormal_;
		float distance_;
	};
	struct CM_VV
	{
		Vector3 hitNormal_;
		Vector3 result_;
	};
	
	static CM_VVF CrowdManagerGetDistanceToWall(CrowdManager * self, const Vector3& point, float radius, int queryFilterType)
	{
		CM_VVF vvf;
		vvf.distance_ = self->GetDistanceToWall(point, radius, queryFilterType, &vvf.hitPos_, &vvf.hitNormal_);
		return vvf;
	}

	static CM_VV CrowdManagerRaycast(CrowdManager * self, const Vector3& start, const Vector3& end, int queryFilterType)
	{
		CM_VV vv;
		vv.result_ = self->Raycast(start, end, queryFilterType, &vv.hitNormal_);
		return vv;
	}
	
	void bind_class_CrowdManager(LuaModele & lm)
	{
		lm
		[
			LuaRegister<CrowdManager, void ()>(lm.state(), "CrowdManager", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<CrowdManager>, "new")
				.def(static_cast<void(CrowdManager::*)(bool)>(&CrowdManager::DrawDebugGeometry), "DrawDebugGeometry")
				.def(&CrowdManager::SetCrowdTarget, "SetCrowdTarget")
				.def(&CrowdManager::SetCrowdVelocity, "SetCrowdVelocity")
				.def(&CrowdManager::ResetCrowdTarget, "ResetCrowdTarget")
				.def(&CrowdManager::SetMaxAgents, "SetMaxAgents")
				.def(&CrowdManager::SetMaxAgentRadius, "SetMaxAgentRadius")
				.def(&CrowdManager::SetNavigationMesh, "SetNavigationMesh")
				.def(&CrowdManager::SetIncludeFlags, "SetIncludeFlags")
				.def(&CrowdManager::SetExcludeFlags, "SetExcludeFlags")
				.def(&CrowdManager::SetAreaCost, "SetAreaCost")
				.def(&CrowdManager::SetObstacleAvoidanceParams, "SetObstacleAvoidanceParams")
				.def(&CrowdManager::GetAgents, "GetAgents")
				.def(&CrowdManager::FindNearestPoint, "FindNearestPoint")
				.def(&CrowdManager::MoveAlongSurface, "MoveAlongSurface")
				.def(CrowdManagerFindPath, "FindPath")
				.def(&CrowdManager::GetRandomPoint, "GetRandomPoint")
				.def(&CrowdManager::GetRandomPointInCircle, "GetRandomPointInCircle")
				.def(CrowdManagerGetDistanceToWall, "GetDistanceToWall")
				.def(CrowdManagerRaycast, "Raycast")
				.def(&CrowdManager::GetMaxAgents, "GetMaxAgents")
				.def(&CrowdManager::GetMaxAgentRadius, "GetMaxAgentRadius")
				.def(&CrowdManager::GetNavigationMesh, "GetNavigationMesh")
				.def(&CrowdManager::GetNumQueryFilterTypes, "GetNumQueryFilterTypes")
				.def(&CrowdManager::GetNumAreas, "GetNumAreas")
				.def(&CrowdManager::GetIncludeFlags, "GetIncludeFlags")
				.def(&CrowdManager::GetExcludeFlags, "GetExcludeFlags")
				.def(&CrowdManager::GetAreaCost, "GetAreaCost")
				.def(&CrowdManager::GetNumObstacleAvoidanceTypes, "GetNumObstacleAvoidanceTypes")
				.def(&CrowdManager::GetObstacleAvoidanceParams, "GetObstacleAvoidanceParams")
			<=
			LuaRegister<CM_VVF, void ()>(lm.state(), "CM_VVF")
				.def(&CM_VVF::hitPos_, "hitPos")
				.def(&CM_VVF::hitNormal_, "hitNormal")
				.def(&CM_VVF::distance_, "distance")
			<=
			LuaRegister<CM_VV, void ()>(lm.state(), "CM_VV")
				.def(&CM_VV::hitNormal_, "hitNormal")
				.def(&CM_VV::result_, "result")
			<=
			LuaRegister<CrowdObstacleAvoidanceParams, void ()>(lm.state(), "CrowdObstacleAvoidanceParams")
				.def(&CrowdObstacleAvoidanceParams::velBias, "velBias")
				.def(&CrowdObstacleAvoidanceParams::weightDesVel, "weightDesVel")
				.def(&CrowdObstacleAvoidanceParams::weightCurVel, "weightCurVel")
				.def(&CrowdObstacleAvoidanceParams::weightSide, "weightSide")
				.def(&CrowdObstacleAvoidanceParams::weightToi, "weightToi")
				.def(&CrowdObstacleAvoidanceParams::horizTime, "horizTime")
				.def(&CrowdObstacleAvoidanceParams::gridSize, "gridSize")
				.def(&CrowdObstacleAvoidanceParams::adaptiveDivs, "adaptiveDivs")
				.def(&CrowdObstacleAvoidanceParams::adaptiveRings, "adaptiveRings")
				.def(&CrowdObstacleAvoidanceParams::adaptiveDepth, "adaptiveDepth")

		];
	}
}

#endif