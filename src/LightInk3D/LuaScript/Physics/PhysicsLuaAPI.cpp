

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

#ifdef URHO3D_PHYSICS

#include "../Precompiled.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;

	extern void bind_class_CollisionShape(LuaModele & lm);
	extern void bind_class_Constraint(LuaModele & lm);
	extern void bind_class_PhysicsWorld(LuaModele & lm);
	extern void bind_class_RigidBody(LuaModele & lm);
	

	void bind_physics_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModele lm(lua, "LightInk3D__", lrf);
		
		bind_class_CollisionShape(lm);
		bind_class_Constraint(lm);
		bind_class_PhysicsWorld(lm);
		bind_class_RigidBody(lm);
		

		// [Enum] ShapeType
		lrf["SHAPE_BOX"] = SHAPE_BOX;
		lrf["SHAPE_SPHERE"] = SHAPE_SPHERE;
		lrf["SHAPE_STATICPLANE"] = SHAPE_STATICPLANE;
		lrf["SHAPE_CYLINDER"] = SHAPE_CYLINDER;
		lrf["SHAPE_CAPSULE"] = SHAPE_CAPSULE;
		lrf["SHAPE_CONE"] = SHAPE_CONE;
		lrf["SHAPE_TRIANGLEMESH"] = SHAPE_TRIANGLEMESH;
		lrf["SHAPE_CONVEXHULL"] = SHAPE_CONVEXHULL;
		lrf["SHAPE_TERRAIN"] = SHAPE_TERRAIN;
		
		// [Enum] ConstraintType
		// [Variable] CONSTRAINT_POINT
		lrf["CONSTRAINT_POINT"] = CONSTRAINT_POINT;
		// [Variable] CONSTRAINT_HINGE,
		lrf["CONSTRAINT_HINGE"] = CONSTRAINT_HINGE;
		// [Variable] CONSTRAINT_SLIDER,
		lrf["CONSTRAINT_SLIDER"] = CONSTRAINT_SLIDER;
		// [Variable] CONSTRAINT_CONETWIST
		lrf["CONSTRAINT_CONETWIST"] = CONSTRAINT_CONETWIST;
		
		// [Constant] float DEFAULT_MAX_NETWORK_ANGULAR_VELOCITY
		lrf["DEFAULT_MAX_NETWORK_ANGULAR_VELOCITY"] = DEFAULT_MAX_NETWORK_ANGULAR_VELOCITY;
		
		// [Enum] CollisionEventMode
		lrf["COLLISION_NEVER"] = COLLISION_NEVER;
		lrf["COLLISION_ACTIVE"] = COLLISION_ACTIVE;
		lrf["COLLISION_ALWAYS"] = COLLISION_ALWAYS;

}

#endif
