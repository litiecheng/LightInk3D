

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
#include "Resource/Resource.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static bool ResourceLoad(Resource* self, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return self->Load(*file);
	}

	static bool ResourceSave(const Resource* self, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		if (!file->IsOpen())
			return false;
		return self->Save(*file);
	}
	void bind_class_Resource(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Resource, void ()>(lm.state(), "Resource", BaseClassStrategy<Object>())
				.disable_new()
				.def(CreateObject<Resource>, "new")
				.def(ResourceLoad, "LoadCS")
				.def(&Resource::Load, "LoadD")
				.def(ResourceSave, "SaveCS")
				.def(&Resource::Save, "SaveS")
				.def(&Resource::SetName, "SetName")
				.def(&Resource::SetMemoryUse, "SetMemoryUse")
				.def(&Resource::ResetUseTimer, "ResetUseTimer")
				.def(&Resource::SetAsyncLoadState, "SetAsyncLoadState")
				.def(&Resource::GetName, "GetName")
				.def(&Resource::GetNameHash, "GetNameHash")
				.def(&Resource::GetMemoryUse, "GetMemoryUse")
				.def(&Resource::GetUseTimer, "GetUseTimer")
				.def(&Resource::GetAsyncLoadState, "GetAsyncLoadState")
			
		];
	}
}
