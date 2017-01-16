

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
#include "IO/FileSystem.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static Vector<String> FileSystemScanDir(const FileSystem* self, const String& pathName, const String& filter, unsigned flags, bool recursive)
	{
		Vector<String> result;
		self->ScanDir(result, pathName, filter, flags, recursive);
		return result;
	}
	void bind_class_FileSystem(LuaModule & lm)
	{
		lm
		[
			LuaRegister<FileSystem, void ()>(lm.state(), "FileSystem", BaseClassStrategy<Object>())
				.def(&FileSystem::SetCurrentDir, "SetCurrentDir")
				.def(&FileSystem::CreateDir, "CreateDir")
				.def(&FileSystem::SetExecuteConsoleCommands, "SetExecuteConsoleCommands")
				.def(&FileSystem::SystemCommand, "SystemCommand")
				.def(&FileSystem::SystemRun, "SystemRun")
				.def(&FileSystem::SystemCommandAsync, "SystemCommandAsync")
				.def(&FileSystem::SystemRunAsync, "SystemRunAsync")
				.def(&FileSystem::SystemOpen, "SystemOpen")
				.def(&FileSystem::Copy, "Copy")
				.def(&FileSystem::Rename, "Rename")
				.def(&FileSystem::Delete, "Delete")
				.def(&FileSystem::SetLastModifiedTime, "SetLastModifiedTime")
				.def(&FileSystem::GetCurrentDir, "GetCurrentDir")
				.def(&FileSystem::GetExecuteConsoleCommands, "GetExecuteConsoleCommands")
				.def(&FileSystem::HasRegisteredPaths, "HasRegisteredPaths")
				.def(&FileSystem::CheckAccess, "CheckAccess")
				.def(&FileSystem::GetLastModifiedTime, "GetLastModifiedTime")
				.def(&FileSystem::FileExists, "FileExists")
				.def(&FileSystem::DirExists, "DirExists")
				.def(FileSystemScanDir, "ScanDir")
				.def(&FileSystem::GetProgramDir, "GetProgramDir")
				.def(&FileSystem::GetUserDocumentsDir, "GetUserDocumentsDir")
				.def(&FileSystem::GetAppPreferencesDir, "GetAppPreferencesDir")
				.def(GetPath, "GetPath")
				.def(GetFileName, "GetFileName")
				.def(GetExtension, "GetExtension")
				.def(GetFileNameAndExtension, "GetFileNameAndExtension")
				.def(ReplaceExtension, "ReplaceExtension")
				.def(AddTrailingSlash "AddTrailingSlash")
				.def(RemoveTrailingSlash, "RemoveTrailingSlash")
				.def(GetParentPath, "GetParentPath")
				.def(GetInternalPath, "GetInternalPath")
				.def(GetNativePath, "GetNativePath")
				.def(IsAbsolutePath, "IsAbsolutePath")
				.def(GetFileSizeString, "GetFileSizeString")
		];
	}
}

