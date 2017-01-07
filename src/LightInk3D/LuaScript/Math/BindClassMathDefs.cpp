

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


#include "../../Precompiled.h"
#include "../../Math/MathDefs.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_MathDefs(LuaModele & lm)
	{
		lua_State * lua = lm.state();
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		// [Constant] float M_HALF_PI
		lrf["M_PI"] = M_PI;
		// [Constant] float M_HALF_PI
		lrf["M_HALF_PI"] = M_HALF_PI;
		// [Constant] int M_MIN_INT
		lrf["M_MIN_INT"] = M_MIN_INT;
		// [Constant] int M_MAX_INT
		lrf["M_MAX_INT"] = M_MAX_INT;
		// [Constant] unsigned M_MIN_UNSIGNED
		lrf["M_MIN_UNSIGNED"] = M_MIN_UNSIGNED;
		// [Constant] unsigned M_MAX_UNSIGNED
		lrf["M_MAX_UNSIGNED"] = M_MAX_UNSIGNED;

		// [Constant] float M_EPSILON
		lrf["M_EPSILON"] = M_EPSILON;
		// [Constant] float M_LARGE_EPSILON
		lrf["M_LARGE_EPSILON"] = M_LARGE_EPSILON;
		// [Constant] float M_MIN_NEARCLIP
		lrf["M_MIN_NEARCLIP"] = M_MIN_NEARCLIP;
		// [Constant] float M_MAX_FOV
		lrf["M_MAX_FOV"] = M_MAX_FOV;
		// [Constant] float M_LARGE_VALUE
		lrf["M_LARGE_VALUE"] = M_LARGE_VALUE;
		// [Constant] float M_INFINITY
		lrf["M_INFINITY"] = M_INFINITY;
		// [Constant] float M_DEGTORAD
		lrf["M_DEGTORAD"] = M_DEGTORAD;
		// [Constant] float M_DEGTORAD_2
		lrf["M_DEGTORAD_2"] = M_DEGTORAD_2;
		// [Constant] float M_RADTODEG
		lrf["M_RADTODEG"] = M_RADTODEG;

		// [Enum] Intersection
		lrf["OUTSIDE"] = OUTSIDE;
		lrf["INTERSECTS"] = INTERSECTS;
		lrf["INSIDE"] = INSIDE;
		
		
		LuaDefAutoTool::def(lua, Equals<float>, "Equals");
		LuaDefAutoTool::def(lua, Lerp<float, float>, "Lerp");
		LuaDefAutoTool::def(lua, Min<float, float>, "Min");
		LuaDefAutoTool::def(lua, Max<float, float>, "Max");
		LuaDefAutoTool::def(lua, Abs<float>, "Abs");
		LuaDefAutoTool::def(lua, Sign<float>, "Sign");
		LuaDefAutoTool::def(lua, IsNaN, "IsNaN");
		LuaDefAutoTool::def(lua, Clamp<float>, "Clamp");
		LuaDefAutoTool::def(lua, SmoothStep<float>, "SmoothStep");
		LuaDefAutoTool::def(lua, Sin<float>, "Sin");
		LuaDefAutoTool::def(lua, Cos<float>, "Cos");
		LuaDefAutoTool::def(lua, Tan<float>, "Tan");
		LuaDefAutoTool::def(lua, Asin<float>, "Asin");
		LuaDefAutoTool::def(lua, Acos<float>, "Acos");
		LuaDefAutoTool::def(lua, Atan<float>, "Atan");
		LuaDefAutoTool::def(lua, Atan2<float>, "Atan2");
		LuaDefAutoTool::def(lua, Min<int, int>, "MinInt");
		LuaDefAutoTool::def(lua, Max<int, int>, "MaxInt");
		LuaDefAutoTool::def(lua, Abs<int>, "AbsInt");
		LuaDefAutoTool::def(lua, Clamp<int>, "ClampInt");
		LuaDefAutoTool::def(lua, IsPowerOfTwo, "IsPowerOfTwo");
		LuaDefAutoTool::def(lua, NextPowerOfTwo, "NextPowerOfTwo");
		LuaDefAutoTool::def(lua, CountSetBits, "CountSetBits");
		LuaDefAutoTool::def(lua, SDBMHash, "SDBMHash");
		LuaDefAutoTool::def(lua, static_cast<float(*)(float)>(&Random), "RandomF");
		LuaDefAutoTool::def(lua, static_cast<float(*)(float, float)>(&Random), "RandomFF");
		LuaDefAutoTool::def(lua, static_cast<int(*)(int)>(&Random), "RandomI");
		LuaDefAutoTool::def(lua, static_cast<int(*)(int, int)>(&Random), "RandomII");
		LuaDefAutoTool::def(lua, RandomNormal, "RandomNormal");
		
	}
}

