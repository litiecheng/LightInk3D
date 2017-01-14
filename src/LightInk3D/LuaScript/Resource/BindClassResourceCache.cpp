

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
#include "Resource/ResourceCache.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<Resource> ResourceCacheGetResource(ResourceCache* cache, StringHash type, const String& name, bool sendEventOnFailure = true)
	{
		return SharedPtr<Resource>(cache->GetResource(type, name, sendEventOnFailure));
	}

	static SharedPtr<Resource> ResourceCacheGetTempResource(ResourceCache* cache, StringHash type, const String& name, bool sendEventOnFailure = true)
	{
		return SharedPtr<Resource>(cache->GetTempResource(type, name, sendEventOnFailure));
	}

	static PODVector<Resource*> ResourceCacheGetResources(const ResourceCache* self, StringHash type)
	{
		PODVector<Resource*> dest;
		self->GetResources(dest, type);
		return dest;
	}

	static SharedPtr<Resource> ResourceCacheGetExistingResource(ResourceCache* cache, StringHash type, const String& name)
	{
		return SharedPtr<Resource>(cache->GetExistingResource(type, name));
	}
	
	void bind_class_ResourceCache(LuaModele & lm)
	{
		lm
		[
			LuaRegister<ResourceCache, void ()>(lm.state(), "ResourceCache", BaseClassStrategy<Object>())
				.disable_new()
				.def(CreateObject<ResourceCache>, "new")
				.def(&ResourceCache::AddResourceDir, "AddResourceDir")
				.def(static_cast<bool(ResourceCache::*)(PackageFile*, unsigned int)>(&ResourceCache::AddPackageFile), "AddPackageFilePU")
				.def(static_cast<bool(ResourceCache::*)(const String&, unsigned int)>(&ResourceCache::AddPackageFile), "AddPackageFileSU")
				.def(&ResourceCache::AddManualResource, "AddManualResource")
				.def(&ResourceCache::RemoveResourceDir, "RemoveResourceDir")
				.def(static_cast<void(ResourceCache::*)(PackageFile*, bool, bool)>(&ResourceCache::RemovePackageFile), "RemovePackageFilePBB")
				.def(static_cast<void(ResourceCache::*)(const String&, bool, bool)>(&ResourceCache::RemovePackageFile), "RemovePackageFileSBB")
				.def(static_cast<void(ResourceCache::*)(StringHash, const String&, bool)>(&ResourceCache::ReleaseResource, "ReleaseResource")
				.def(static_cast<void(ResourceCache::*)(StringHash, bool)>(&ResourceCache::ReleaseResources), "ReleaseResourcesSHB")
				.def(static_cast<void(ResourceCache::*)(StringHash, const String&, bool)>(&ResourceCache::ReleaseResources), "ReleaseResourcesSHSB")
				.def(static_cast<void(ResourceCache::*)(const String&, bool)>(&ResourceCache::ReleaseResources), "ReleaseResourcesSB")
				.def(&ResourceCache::ReleaseAllResources, "ReleaseAllResources")
				.def(&ResourceCache::ReloadResource, "ReloadResource")
				.def(&ResourceCache::ReloadResourceWithDependencies, "ReloadResourceWithDependencies")
				.def(&ResourceCache::SetMemoryBudget, "SetMemoryBudget")
				.def(&ResourceCache::SetAutoReloadResources, "SetAutoReloadResources")
				.def(&ResourceCache::SetReturnFailedResources, "SetReturnFailedResources")
				.def(&ResourceCache::SetSearchPackagesFirst, "SetSearchPackagesFirst")
				.def(&ResourceCache::SetFinishBackgroundResourcesMs, "SetFinishBackgroundResourcesMs")
				.def(&ResourceCache::GetFile, "GetFile")
				.def(ResourceCacheGetResource, "GetResource")
				.def(ResourceCacheGetTempResource, "GetTempResource")
				.def(ResourceCacheGetResources, "GetResources")
				.def(ResourceCacheGetExistingResource, "GetExistingResource")
				.def(&ResourceCache::GetResourceDirs, "GetResourceDirs")
				.def(&ResourceCache::GetPackageFiles, "GetPackageFiles")
				.def(&ResourceCache::Exists, "Exists")
				.def(&ResourceCache::GetMemoryBudget, "GetMemoryBudget")
				.def(&ResourceCache::GetMemoryUse, "GetMemoryUse")
				.def(&ResourceCache::GetTotalMemoryUse, "GetTotalMemoryUse")
				.def(&ResourceCache::GetResourceFileName, "GetResourceFileName")
				.def(&ResourceCache::GetAutoReloadResources, "GetAutoReloadResources")
				.def(&ResourceCache::GetReturnFailedResources, "GetReturnFailedResources")
				.def(&ResourceCache::GetSearchPackagesFirst, "GetSearchPackagesFirst")
				.def(&ResourceCache::GetPreferredResourceDir, "GetPreferredResourceDir")
				.def(&ResourceCache::SanitateResourceName, "SanitateResourceName")
				.def(&ResourceCache::SanitateResourceDirName, "SanitateResourceDirName")
				.def(&ResourceCache::StoreResourceDependency, "StoreResourceDependency")
				.def(&ResourceCache::ResetDependencies, "ResetDependencies")
				.def(&ResourceCache::PrintMemoryUsage, "PrintMemoryUsage")
			
		];
	}
}
