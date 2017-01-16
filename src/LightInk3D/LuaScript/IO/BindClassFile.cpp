

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
#include "IO/File.h"
#include "IO/PackageFile.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<File> CreateFile(Context * context)
	{
		return SharedPtr<File>(new File(context));
	}

	static SharedPtr<File> CreateFileCS(Context * context, const String& fileName)
	{
		return SharedPtr<File>(new File(context, fileName));
	}

	static SharedPtr<File> CreateFileCSF(Context * context, const String& fileName, FileMode mode)
	{
		return SharedPtr<File>(new File(context, fileName, mode));
	}

	static SharedPtr<File> CreateFileCPS(Context * context, PackageFile* package, const String& fileName)
	{
		return SharedPtr<File>(new File(context, package, fileName));
	}
	void bind_class_File(LuaModule & lm)
	{
		lm
		[
			LuaRegister<File, void ()>(lm.state(), "File", BaseClassStrategy<Serializer>())
			.disable_new()
			.def(CreateFile, "new")
			.def(CreateFileCS, "newCS")
			.def(CreateFileCSF, "newCSF")
			.def(CreateFileCPS, "newCPS")
			.def(static_cast<bool(File::*)(PackageFile*, const String&)>(&File::Open), "OpenPS")
			.def(static_cast<bool(File::*)(const String&, FileMode)>(&File::Open), "OpenSF")
			.def(&File::Close, "Close")
			.def(&File::Flush, "Flush")
			.def(&File::SetName, "SetName")
			.def(&File::GetMode, "GetMode")
			.def(&File::IsOpen, "IsOpen")
			.def(&File::GetHandle, "GetHandle")
			.def(&File::IsPackaged, "IsPackaged")
			<=
			LuaRegister<File, void ()>(lm.state(), "File", BaseClassStrategy<Deserializer>())
			<=
			LuaRegister<File, void ()>(lm.state(), "File", BaseClassStrategy<Object>())

		];
	}
}

