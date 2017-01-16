

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

#include "../Precompiled.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;

	extern void bind_class_NavigationMesh(LuaModule & lm);
	extern void bind_class_CrowdAgent(LuaModule & lm);
	extern void bind_class_CrowdManager(LuaModule & lm);
	extern void bind_class_DynamicNavigationMesh(LuaModule & lm);
	extern void bind_class_NavArea(LuaModule & lm);
	extern void bind_class_Navigable(LuaModule & lm);
	extern void bind_class_Obstacle(LuaModule & lm);
	extern void bind_class_OffMeshConnection(LuaModule & lm);
	

	void bind_navigation_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModule lm(lua, "LightInk3D__", lrf);
		
		bind_class_NavigationMesh(lm);
		bind_class_CrowdAgent(lm);
		bind_class_CrowdManager(lm);
		bind_class_DynamicNavigationMesh(lm);
		bind_class_NavArea(lm);
		bind_class_Navigable(lm);
		bind_class_Obstacle(lm);
		bind_class_OffMeshConnection(lm);
		

		// [Enum] CrowdAgentRequestedTarget
		lrf["CA_REQUESTEDTARGET_NONE"] = CA_REQUESTEDTARGET_NONE;
		lrf["CA_REQUESTEDTARGET_POSITION"] = CA_REQUESTEDTARGET_POSITION;
		lrf["CA_REQUESTEDTARGET_VELOCITY"] = CA_REQUESTEDTARGET_VELOCITY;

		// [Enum] CrowdAgentTargetState
		lrf["CA_TARGET_NONE"] = CA_TARGET_NONE;
		lrf["CA_TARGET_FAILED"] = CA_TARGET_FAILED;
		lrf["CA_TARGET_VALID"] = CA_TARGET_VALID;
		lrf["CA_TARGET_REQUESTING"] = CA_TARGET_REQUESTING;
		lrf["CA_TARGET_WAITINGFORQUEUE"] = CA_TARGET_WAITINGFORQUEUE;
		lrf["CA_TARGET_WAITINGFORPATH"] = CA_TARGET_WAITINGFORPATH;
		lrf["CA_TARGET_VELOCITY"] = CA_TARGET_VELOCITY;

		// [Enum] CrowdAgentState
		lrf["CA_STATE_INVALID"] = CA_STATE_INVALID;
		lrf["CA_STATE_WALKING"] = CA_STATE_WALKING;
		lrf["CA_STATE_OFFMESH"] = CA_STATE_OFFMESH;

		// [Enum] NavigationQuality
		lrf["NAVIGATIONQUALITY_LOW"] = NAVIGATIONQUALITY_LOW;
		lrf["NAVIGATIONQUALITY_MEDIUM"] = NAVIGATIONQUALITY_MEDIUM;
		lrf["NAVIGATIONQUALITY_HIGH"] = NAVIGATIONQUALITY_HIGH;

		// [Enum] NavigationPushiness
		lrf["NAVIGATIONPUSHINESS_LOW"] = NAVIGATIONPUSHINESS_LOW;
		lrf["NAVIGATIONPUSHINESS_MEDIUM"] = NAVIGATIONPUSHINESS_MEDIUM;
		lrf["NAVIGATIONPUSHINESS_HIGH"] = NAVIGATIONPUSHINESS_HIGH;
		
		// [Enum] NavmeshPartitionType
		lua["NAVMESH_PARTITION_WATERSHED"] = NAVMESH_PARTITION_WATERSHED;
		lua["NAVMESH_PARTITION_MONOTONE"] = NAVMESH_PARTITION_MONOTONE;
		
		

}

#endif
