

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

#include "Core/StringUtils.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_StringUtils(LuaModule & lm)
	{
		lua_State * lua = lm.state();
		LuaDefAutoTool::def(lua, static_cast<bool(*)(const char*)>(ToBool), "ToBool");
		LuaDefAutoTool::def(lua, static_cast<float(*)(const char*)>(ToFloat), "ToFloat");
		LuaDefAutoTool::def(lua, static_cast<double(*)(const char*)>(ToDouble), "ToDouble");
		LuaDefAutoTool::def(lua, static_cast<int(*)(const char*)>(ToInt), "ToInt");
		LuaDefAutoTool::def(lua, static_cast<unsigned int(*)(const char*)>(ToUInt), "ToUInt");
		LuaDefAutoTool::def(lua, static_cast<Color(*)(const char*)>(ToColor), "ToColor");
		LuaDefAutoTool::def(lua, static_cast<IntRect(*)(const char*)>(ToIntRect), "ToIntRect");
		LuaDefAutoTool::def(lua, static_cast<IntVector2(*)(const char*)>(ToIntVector2), "ToIntVector2");
		LuaDefAutoTool::def(lua, static_cast<Quaternion(*)(const char*)>(ToQuaternion), "ToQuaternion");
		LuaDefAutoTool::def(lua, static_cast<Rect(*)(const char*)>(ToRect), "ToRect");
		LuaDefAutoTool::def(lua, static_cast<Vector2(*)(const char*)>(ToVector2), "ToVector2");
		LuaDefAutoTool::def(lua, static_cast<Vector3(*)(const char*)>(ToVector3), "ToVector3");
		LuaDefAutoTool::def(lua, static_cast<Vector4(*)(const char*)>(ToVector4), "ToVector4");
		LuaDefAutoTool::def(lua, static_cast<Matrix3(*)(const char*)>(ToMatrix3), "ToMatrix3");
		LuaDefAutoTool::def(lua, static_cast<Matrix3x4(*)(const char*)>(ToMatrix3x4), "ToMatrix3x4");
		LuaDefAutoTool::def(lua, static_cast<Matrix4(*)(const char*)>(ToMatrix4), "ToMatrix4");
		LuaDefAutoTool::def(lua, ToStringHex, "ToStringHex");
		LuaDefAutoTool::def(lua, IsAlpha, "IsAlpha");
		LuaDefAutoTool::def(lua, IsDigit, "IsDigit");
		LuaDefAutoTool::def(lua, ToUpper, "ToUpper");
		LuaDefAutoTool::def(lua, ToLower, "ToLower");
		
	}

}

