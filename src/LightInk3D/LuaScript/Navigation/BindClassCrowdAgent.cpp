

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
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_CrowdAgent(LuaModule & lm)
	{
		lm
		[
			LuaRegister<CrowdAgent, void ()>(lm.state(), "CrowdAgent", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<CrowdAgent>, "new")
				.def(static_cast<void(CrowdAgent::*)(bool)>(&CrowdAgent::DrawDebugGeometry), "DrawDebugGeometry")
				.def(&CrowdAgent::SetTargetPosition, "SetTargetPosition")
				.def(&CrowdAgent::SetTargetVelocity, "SetTargetVelocity")
				.def(&CrowdAgent::ResetTarget, "ResetTarget")
				.def(&CrowdAgent::SetUpdateNodePosition, "SetUpdateNodePosition")
				.def(&CrowdAgent::SetMaxAccel, "SetMaxAccel")
				.def(&CrowdAgent::SetMaxSpeed, "SetMaxSpeed")
				.def(&CrowdAgent::SetRadius, "SetRadius")
				.def(&CrowdAgent::SetHeight, "SetHeight")
				.def(&CrowdAgent::SetQueryFilterType, "SetQueryFilterType")
				.def(&CrowdAgent::SetObstacleAvoidanceType, "SetObstacleAvoidanceType")
				.def(&CrowdAgent::SetNavigationQuality, "SetNavigationQuality")
				.def(&CrowdAgent::SetNavigationPushiness, "SetNavigationPushiness")
				.def(&CrowdAgent::GetPosition, "GetPosition")
				.def(&CrowdAgent::GetDesiredVelocity, "GetDesiredVelocity")
				.def(&CrowdAgent::GetActualVelocity, "GetActualVelocity")
				.def(&CrowdAgent::GetTargetPosition, "GetTargetPosition")
				.def(&CrowdAgent::GetTargetVelocity, "GetTargetVelocity")
				.def(&CrowdAgent::GetRequestedTargetType, "GetRequestedTargetType")
				.def(&CrowdAgent::GetAgentState, "GetAgentState")
				.def(&CrowdAgent::GetTargetState, "GetTargetState")
				.def(&CrowdAgent::GetUpdateNodePosition, "GetUpdateNodePosition")
				.def(&CrowdAgent::GetMaxAccel, "GetMaxAccel")
				.def(&CrowdAgent::GetMaxSpeed, "GetMaxSpeed")
				.def(&CrowdAgent::GetRadius, "GetRadius")
				.def(&CrowdAgent::GetHeight, "GetHeight")
				.def(&CrowdAgent::GetQueryFilterType, "GetQueryFilterType")
				.def(&CrowdAgent::GetObstacleAvoidanceType, "GetObstacleAvoidanceType")
				.def(&CrowdAgent::GetNavigationQuality, "GetNavigationQuality")
				.def(&CrowdAgent::GetNavigationPushiness, "GetNavigationPushiness")
				.def(&CrowdAgent::HasRequestedTarget, "HasRequestedTarget")
				.def(&CrowdAgent::HasArrived, "HasArrived")
				.def(&CrowdAgent::IsInCrowd, "IsInCrowd")
				
		];
	}
}

#endif