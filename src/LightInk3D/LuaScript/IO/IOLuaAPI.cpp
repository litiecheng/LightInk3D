

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

	extern void bind_class_Compression(LuaModule & lm);
	extern void bind_class_Deserializer(LuaModule & lm);
	extern void bind_class_Serializer(LuaModule & lm);
	extern void bind_class_File(LuaModule & lm);
	extern void bind_class_FileSystem(LuaModule & lm);
	extern void bind_class_Log(LuaModule & lm);
	extern void bind_class_NamedPipe(LuaModule & lm);
	extern void bind_class_PackageFile(LuaModule & lm);
	extern void bind_class_VectorBuffer(LuaModule & lm);
	

	void bind_io_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModule lm(lua, "LightInk3D__", lrf);
		
		bind_class_Compression(lm);
		bind_class_Deserializer(lm);
		bind_class_Serializer(lm);
		bind_class_File(lm);
		bind_class_FileSystem(lm);
		bind_class_Log(lm);
		bind_class_NamedPipe(lm);
		bind_class_PackageFile(lm);
		bind_class_VectorBuffer(lm);

		
		
		 // [Enum] FileMode
		lrf["FILE_READ"] = FILE_READ;
		lrf["FILE_WRITE"] = FILE_WRITE;
		lrf["FILE_READWRITE"] = FILE_READWRITE;
		
		
		// [Constant] unsigned SCAN_FILES
		lrf["SCAN_FILES"] = SCAN_FILES;
		// [Constant] unsigned SCAN_DIRS
		lrf["SCAN_DIRS"] = SCAN_DIRS;
		// [Constant] unsigned SCAN_HIDDEN
		lrf["SCAN_HIDDEN"] = SCAN_HIDDEN;
		
		// [Constant] int LOG_RAW
		lrf["LOG_RAW"] = LOG_RAW;
		// [Constant] int LOG_DEBUG
		lrf["LOG_DEBUG"] = LOG_DEBUG;
		// [Constant] int LOG_INFO
		lrf["LOG_INFO"] = LOG_INFO;
		// [Constant] int LOG_WARNING
		lrf["LOG_WARNING"] = LOG_WARNING;
		// [Constant] int LOG_ERROR
		lrf["LOG_ERROR"] = LOG_ERROR;
		// [Constant] int LOG_NONE
		lrf["LOG_NONE"] = LOG_NONE;
			

		lrf["fileSystem"] = GetSubsystem<FileSystem>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<FileSystem>, "GetFileSystem");
		
		lrf["log"] = GetSubsystem<Log>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<Log>, "GetLog");


}

