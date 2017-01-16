

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
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;

	extern void bind_class_Serializable(LuaModule & lm);
	extern void bind_class_Animatable(LuaModule & lm);
	extern void bind_class_Component(LuaModule & lm);
	extern void bind_class_LogicComponent(LuaModule & lm);
	extern void bind_class_Node(LuaModule & lm);
	extern void bind_class_ObjectAnimation(LuaModule & lm);
	extern void bind_class_Scene(LuaModule & lm);
	extern void bind_class_SmoothedTransform(LuaModule & lm);
	extern void bind_class_SplinePath(LuaModule & lm);
	extern void bind_class_ValueAnimation(LuaModule & lm);
	

	void bind_scene_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModule lm(lua, "LightInk3D__", lrf);
		
		bind_class_Serializable(lm);

		bind_class_Animatable(lm);
		bind_class_Component(lm);
		bind_class_LogicComponent(lm);
		bind_class_Node(lm);
		bind_class_ObjectAnimation(lm);
		bind_class_Scene(lm);
		bind_class_SmoothedTransform(lm);
		bind_class_SplinePath(lm);
		bind_class_ValueAnimation(lm);
		

		// [Enum] WrapMode
		lrf["WM_LOOP"] = WM_LOOP;
		lrf["WM_ONCE"] = WM_ONCE;
		lrf["WM_CLAMP"] = WM_CLAMP;
		
		// [Constant] unsigned char USE_UPDATE
		lrf["USE_UPDATE"] = USE_UPDATE;
		// [Constant] unsigned char USE_POSTUPDATE
		lrf["USE_POSTUPDATE"] = USE_POSTUPDATE;
		// [Constant] unsigned char USE_FIXEDUPDATE
		lrf["USE_FIXEDUPDATE"] = USE_FIXEDUPDATE;
		// [Constant] unsigned char USE_FIXEDPOSTUPDATE
		lrf["USE_FIXEDPOSTUPDATE"] = USE_FIXEDPOSTUPDATE;
		
		// [Enum] CreateMode
		// [Constant] Node* CreateChild(String& name
		lrf["REPLICATED"] = REPLICATED;
		// [Variable] LOCAL
		lrf["LOCAL"] = LOCAL;

		// [Enum] TransformSpace
		// [Constant] void Translate(Vector3& delta, TransformSpace space
		lrf["TS_LOCAL"] = TS_LOCAL;
		// [Variable] TS_PARENT,
		lrf["TS_PARENT"] = TS_PARENT;
		// [Constant] bool LookAt(Vector3& target, Vector3& up
		lrf["TS_WORLD"] = TS_WORLD;
		
		// [Constant] unsigned FIRST_REPLICATED_ID
		lrf["FIRST_REPLICATED_ID"] = FIRST_REPLICATED_ID;
		// [Constant] unsigned LAST_REPLICATED_ID
		lrf["LAST_REPLICATED_ID"] = LAST_REPLICATED_ID;
		// [Constant] unsigned FIRST_LOCAL_ID
		lrf["FIRST_LOCAL_ID"] = FIRST_LOCAL_ID;
		// [Constant] unsigned LAST_LOCAL_ID
		lrf["LAST_LOCAL_ID"] = LAST_LOCAL_ID;

		// [Enum] LoadMode
		lrf["LOAD_RESOURCES_ONLY"] = LOAD_RESOURCES_ONLY;
		lrf["LOAD_SCENE"] = LOAD_SCENE;
		lrf["LOAD_SCENE_AND_RESOURCES"] = LOAD_SCENE_AND_RESOURCES;
		
		// [Constant] unsigned SMOOTH_NONE
		lrf["SMOOTH_NONE"] = SMOOTH_NONE;
		// [Constant] unsigned SMOOTH_POSITION
		lrf["SMOOTH_POSITION"] = SMOOTH_POSITION;
		// [Constant] unsigned SMOOTH_ROTATION
		lrf["SMOOTH_ROTATION"] = SMOOTH_ROTATION;
		
		// [Enum] InterpMethod
		lrf["IM_NONE"] = IM_NONE;
		lrf["IM_LINEAR"] = IM_LINEAR;
		lrf["IM_SPLINE"] = IM_SPLINE;


}

