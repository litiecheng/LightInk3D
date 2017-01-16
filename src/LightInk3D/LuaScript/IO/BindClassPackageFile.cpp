

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
#include "IO/PackageFile.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<PackageFile> CreatePackageFile(Context * context)
	{
		return SharedPtr<PackageFile>(new PackageFile(context));
	}

	static SharedPtr<PackageFile> CreatePackageFileCS(Context * context, const String& fileName)
	{
		return SharedPtr<PackageFile>(new PackageFile(context, fileName));
	}

	static SharedPtr<PackageFile> CreatePackageFileCSU(Context * context, const String& fileName, unsigned int startOffset)
	{
		return SharedPtr<PackageFile>(new PackageFile(context, fileName, startOffset));
	}
	void bind_class_PackageFile(LuaModule & lm)
	{
		lm
		[
			LuaRegister<PackageFile, void ()>(lm.state(), "PackageFile", BaseClassStrategy<Object>())
				.disable_new()
				.def(CreatePackageFile, "new")
				.def(CreatePackageFileCS, "newCS")
				.def(CreatePackageFileCSU, "newCSU")
				.def(&PackageFile::Open, "Open")
				.def(&PackageFile::Exists, "Exists")
				.def(&PackageFile::GetEntry, "GetEntry")
				.def(&PackageFile::GetEntries, "GetEntries")
				.def(&PackageFile::GetName, "GetName")
				.def(&PackageFile::GetNameHash, "GetNameHash")
				.def(&PackageFile::GetNumFiles, "GetNumFiles")
				.def(&PackageFile::GetTotalSize, "GetTotalSize")
				.def(&PackageFile::GetTotalDataSize, "GetTotalDataSize")
				.def(&PackageFile::GetChecksum, "GetChecksum")
				.def(&PackageFile::IsCompressed, "IsCompressed")
			<=
			LuaRegister<PackageEntry, void ()>(lm.state(), "PackageEntry")
				.def(&PackageEntry::offset_, "offset")
				.def(&PackageEntry::size_, "size")
				.def(&PackageEntry::checksum_, "checksum")
		];
	}
}

