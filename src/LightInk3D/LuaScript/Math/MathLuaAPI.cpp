

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

 

#include "../Precompiled.h"
#include "Math/Random.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;

	extern void bind_class_BoundingBox(LuaModule & lm);
	extern void bind_class_Color(LuaModule & lm);
	extern void bind_class_Frustum(LuaModule & lm);
	extern void bind_class_MathDefs(LuaModule & lm);
	extern void bind_class_Matrix2(LuaModule & lm);
	extern void bind_class_Matrix3(LuaModule & lm);
	extern void bind_class_Matrix3x4(LuaModule & lm);
	extern void bind_class_Matrix4(LuaModule & lm);
	extern void bind_class_Plane(LuaModule & lm);
	extern void bind_class_Polyhedron(LuaModule & lm);
	extern void bind_class_Quaternion(LuaModule & lm);
	extern void bind_class_Ray(LuaModule & lm);
	extern void bind_class_Rect(LuaModule & lm);
	extern void bind_class_Sphere(LuaModule & lm);
	extern void bind_class_StringHash(LuaModule & lm);
	extern void bind_class_Vector2(LuaModule & lm);
	extern void bind_class_Vector3(LuaModule & lm);
	extern void bind_class_Vector4(LuaModule & lm);
	

	void bind_math_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModule lm(lua, "LightInk3D__", lrf);
		
		bind_class_BoundingBox(lm);
		bind_class_Color(lm);
		bind_class_Frustum(lm);
		bind_class_MathDefs(lm);
		bind_class_Matrix2(lm);
		bind_class_Matrix3(lm);
		bind_class_Matrix3x4(lm);
		bind_class_Matrix4(lm);
		bind_class_Plane(lm);
		bind_class_Polyhedron(lm);
		bind_class_Quaternion(lm);
		bind_class_Ray(lm);
		bind_class_Rect(lm);
		bind_class_Sphere(lm);
		bind_class_StringHash(lm);
		bind_class_Vector2(lm);
		bind_class_Vector3(lm);
		bind_class_Vector4(lm);

		
		
		// [Enum] FrustumPlane
		lrf["PLANE_NEAR"] = PLANE_NEAR;
		lrf["PLANE_LEFT"] = PLANE_LEFT;
		lrf["PLANE_RIGHT"] = PLANE_RIGHT;
		lrf["PLANE_UP"] = PLANE_UP;
		lrf["PLANE_DOWN"] = PLANE_DOWN;
		lrf["PLANE_FAR"] = PLANE_FAR;

		// [Constant] unsigned NUM_FRUSTUM_PLANES
		lrf["NUM_FRUSTUM_PLANES"] = NUM_FRUSTUM_PLANES;
		// [Constant] unsigned NUM_FRUSTUM_VERTICES
		lrf["NUM_FRUSTUM_VERTICES"] = NUM_FRUSTUM_VERTICES;
		
		
		LuaDefAutoTool::def(lua, SetRandomSeed, "SetRandomSeed");
		LuaDefAutoTool::def(lua, GetRandomSeed, "GetRandomSeed");
		LuaDefAutoTool::def(lua, Rand, "Rand");
		LuaDefAutoTool::def(lua, RandStandardNormal, "RandStandardNormal");


}

