

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
#include "../../Core/Context.h"
#include "../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;

	extern void bind_class_Context(LuaModele & lm);
	extern void bind_class_Object(LuaModele & lm);
	extern void bind_class_ProcessUtils(LuaModele & lm);
	extern void bind_class_Spline(LuaModele & lm);
	extern void bind_class_StringUtils(LuaModele & lm);
	extern void bind_class_Timer(LuaModele & lm);
	extern void bind_class_Variant(LuaModele & lm);
	extern void bind_class_VariantMap(LuaModele & lm);

	void bind_core_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModele lm(lua, "LightInk3D__", lrf);
		
		bind_class_Context(lm);
		bind_class_Object(lm);
		bind_class_ProcessUtils(lm);
		bind_class_Spline(lm);
		bind_class_StringUtils(lm);
		bind_class_Timer(lm);
		bind_class_Variant(lm);
		bind_class_VariantMap(lm);
		
		lrf["context"] = context;
		lrf["eventSender"] = context->GetEventSender();
		
		//InterpolationMode
		lrf["BEZIER_CURVE"] = BEZIER_CURVE;
		lrf["CATMULL_ROM_CURVE"] = CATMULL_ROM_CURVE;
		lrf["LINEAR_CURVE"] = LINEAR_CURVE;
		lrf["CATMULL_ROM_FULL_CURVE"] = CATMULL_ROM_FULL_CURVE;
		
		lrf["time"] = GetSubsystem<Time>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<Time>, "GetTime");
		
		//VariantType
		lrf["VAR_NONE"] = VAR_NONE;
		lrf["VAR_INT"] = VAR_INT;
		lrf["VAR_BOOL"] = VAR_BOOL;
		lrf["VAR_FLOAT"] = VAR_FLOAT;
		lrf["VAR_VECTOR2"] = VAR_VECTOR2;
		lrf["VAR_VECTOR3"] = VAR_VECTOR3;
		lrf["VAR_VECTOR4"] = VAR_VECTOR4;
		lrf["VAR_QUATERNION"] = VAR_QUATERNION;
		lrf["VAR_COLOR"] = VAR_COLOR;
		lrf["VAR_STRING"] = VAR_STRING;
		lrf["VAR_BUFFER"] = VAR_BUFFER;
		lrf["VAR_VOIDPTR"] = VAR_VOIDPTR;
		lrf["VAR_RESOURCEREF"] = VAR_RESOURCEREF;
		lrf["VAR_RESOURCEREFLIST"] = VAR_RESOURCEREFLIST;
		lrf["VAR_VARIANTVECTOR"] = VAR_VARIANTVECTOR;
		lrf["VAR_VARIANTMAP"] = VAR_VARIANTMAP;
		lrf["VAR_INTRECT"] = VAR_INTRECT;
		lrf["VAR_INTVECTOR2"] = VAR_INTVECTOR2;
		lrf["VAR_PTR"] = VAR_PTR;
		lrf["VAR_MATRIX3"] = VAR_MATRIX3;
		lrf["VAR_MATRIX3X4"] = VAR_MATRIX3X4;
		lrf["VAR_MATRIX4"] = VAR_MATRIX4;
		lrf["VAR_DOUBLE"] = VAR_DOUBLE;
		lrf["VAR_STRINGVECTOR"] = VAR_STRINGVECTOR;
		lrf["MAX_VAR_TYPES"] = MAX_VAR_TYPES;
	}
}
