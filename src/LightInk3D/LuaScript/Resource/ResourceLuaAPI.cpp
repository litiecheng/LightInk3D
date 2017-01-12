

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

	extern void bind_class_Resource(LuaModele & lm);
	extern void bind_class_Image(LuaModele & lm);
	extern void bind_class_JSONFile(LuaModele & lm);
	extern void bind_class_JSONValue(LuaModele & lm);
	extern void bind_class_Localization(LuaModele & lm);
	extern void bind_class_PListFile(LuaModele & lm);
	extern void bind_class_ResourceCache(LuaModele & lm);
	extern void bind_class_XMLElement(LuaModele & lm);
	extern void bind_class_XMLFile(LuaModele & lm);
	

	void bind_resource_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModele lm(lua, "LightInk3D__", lrf);
		
		bind_class_Resource(lm);
		
		bind_class_Image(lm);
		bind_class_JSONFile(lm);
		bind_class_JSONValue(lm);
		bind_class_Localization(lm);
		bind_class_PListFile(lm);
		bind_class_ResourceCache(lm);
		bind_class_XMLElement(lm);
		bind_class_XMLFile(lm);
		

		// [Enum] CompressedFormat
		lrf["CF_NONE"] = CF_NONE;
		lrf["CF_RGBA"] = CF_RGBA;
		lrf["CF_DXT1"] = CF_DXT1;
		lrf["CF_DXT3"] = CF_DXT3;
		lrf["CF_DXT5"] = CF_DXT5;
		lrf["CF_ETC1"] = CF_ETC1;
		lrf["CF_PVRTC_RGB_2BPP"] = CF_PVRTC_RGB_2BPP;
		lrf["CF_PVRTC_RGBA_2BPP"] = CF_PVRTC_RGBA_2BPP;
		lrf["CF_PVRTC_RGB_4BPP"] = CF_PVRTC_RGB_4BPP;
		lrf["CF_PVRTC_RGBA_4BPP"] = CF_PVRTC_RGBA_4BPP;
		
		// [Enum] JSONValueType
		lrf["JSON_NULL"] = JSON_NULL;
		lrf["JSON_BOOL"] = JSON_BOOL;
		lrf["JSON_NUMBER"] = JSON_NUMBER;
		lrf["JSON_STRING"] = JSON_STRING;
		lrf["JSON_ARRAY"] = JSON_ARRAY;
		lrf["JSON_OBJECT"] = JSON_OBJECT;

		// [Enum] JSONNumberType
		lrf["JSONNT_NAN"] = JSONNT_NAN;
		lrf["JSONNT_INT"] = JSONNT_INT;
		lrf["JSONNT_UINT"] = JSONNT_UINT;
		lrf["JSONNT_FLOAT_DOUBLE"] = JSONNT_FLOAT_DOUBLE;
		
		// [Enum] PListValueType
	    lrf["PLVT_NONE"] = PLVT_NONE;
	    lrf["PLVT_INT"] = PLVT_INT;
	    lrf["PLVT_BOOL"] = PLVT_BOOL;
	    lrf["PLVT_FLOAT"] = PLVT_FLOAT;
	    lrf["PLVT_STRING"] = PLVT_STRING;
	    lrf["PLVT_VALUEMAP"] = PLVT_VALUEMAP;
	    lrf["PLVT_VALUEVECTOR"] = PLVT_VALUEVECTOR;
		
		// [Enum] AsyncLoadState
		lrf["ASYNC_DONE"] = ASYNC_DONE;
		lrf["ASYNC_QUEUED"] = ASYNC_QUEUED;
		lrf["ASYNC_LOADING"] = ASYNC_LOADING;
		lrf["ASYNC_SUCCESS"] = ASYNC_SUCCESS;
		lrf["ASYNC_FAIL"] = ASYNC_FAIL;
		
		// [Constant] const unsigned PRIORITY_LAST
		lrf["PRIORITY_LAST"] = PRIORITY_LAST;

		// [Enum] ResourceRequest
		lrf["RESOURCE_CHECKEXISTS"] = RESOURCE_CHECKEXISTS;
		lrf["RESOURCE_GETFILE"] = RESOURCE_GETFILE;
		
		lrf["localization"] = GetSubsystem<Localization>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<Localization>, "GetLocalization");
		
		lrf["cache"] = GetSubsystem<ResourceCache>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<ResourceCache>, "GetCache");

}

