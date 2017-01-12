

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
#include "../../IO/File.h"
#include "../../IO/PackageFile.h"
#include "../../Scene/Component.h"
#include "../../Scene/Scene.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static bool SceneLoadXML(Scene* scene, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return scene->LoadXML(*file);
	}

	static bool SceneLoadJSON(Scene* scene, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return scene->LoadJSON(*file);
	}

	static bool SceneSaveXML(const Scene* scene, Context * context, const String& fileName, const String& indentation = "\t")
	{
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		if (!file->IsOpen())
			return false;
		return scene->SaveXML(*file, indentation);
	}

	static bool SceneSaveJSON(const Scene* scene, Context * context, const String& fileName, const String& indentation = "\t")
	{
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		if (!file->IsOpen())
			return false;
		return scene->SaveJSON(*file, indentation);
	}

	static bool SceneLoadAsync(Scene* self, Context * context, const String& fileName, LoadMode mode = LOAD_SCENE_AND_RESOURCES)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return self->LoadAsync(file, mode);
	}

	static bool SceneLoadAsyncXML(Scene* self, Context * context, const String& fileName, LoadMode mode = LOAD_SCENE_AND_RESOURCES)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return self->LoadAsyncXML(file, mode);
	}

	static bool SceneLoadAsyncJSON(Scene* self, Context * context, const String& fileName, LoadMode mode = LOAD_SCENE_AND_RESOURCES)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return self->LoadAsyncJSON(file, mode);
	}

	static SharedPtr<Node> SceneInstantiate(Scene* self, Context * context, const String& fileName, const Vector3& position, const Quaternion& rotation, CreateMode mode = REPLICATED)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return SharedPtr<Node>();
		return SharedPtr<Node>(self->Instantiate(*file, position, rotation, mode));
	}

	static SharedPtr<Node> SceneInstantiateXML(Scene* self, Context * context, const String& fileName, const Vector3& position, const Quaternion& rotation, CreateMode mode = REPLICATED)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return SharedPtr<Node>();
		return SharedPtr<Node>(self->InstantiateXML(*file, position, rotation, mode));
	}

	static SharedPtr<Node> SceneInstantiateJSON(Scene* self, Context * context, const String& fileName, const Vector3& position, const Quaternion& rotation, CreateMode mode = REPLICATED)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return SharedPtr<Node>();
		return SharedPtr<Node>(self->InstantiateJSON(*file, position, rotation, mode));
	}
	
	void bind_class_Scene(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Scene, void ()>(lm.state(), "Scene", BaseClassStrategy<Node>())
				.disable_new()
				.def(CreateObject<Scene>, "new")
				.def(SceneLoadXML, "LoadXMLSS")
				.def(static_cast<bool (Scene::*)(Deserializer&)>(&Scene::LoadXML), "LoadXMLD")
				.def(SceneLoadJSON, "LoadJSONSD")
				.def(static_cast<bool (Scene::*)(Deserializer&)>(&Scene::LoadJSON), "LoadJSOND")
				.def(SceneSaveXML, "SaveXMLSSS")
				.def(static_cast<bool (Scene::*)(Serializer&, const String&) const>(&Scene::SaveXML), "SaveXMLSS")
				.def(SceneSaveJSON, "SaveJSONSSS")
				.def(static_cast<bool (Scene::*)(Serializer&, const String&) const>(&Scene::SaveJSON), "SaveJSONSS")
				.def(SceneLoadAsync, "LoadAsync")
				.def(SceneLoadAsyncXML, "LoadAsyncXML")
				.def(SceneLoadAsyncJSON, "LoadAsyncJSON")
				.def(&Scene::StopAsyncLoading, "StopAsyncLoading")
				.def(SceneInstantiate, "Instantiate")
				.def(SceneInstantiateXML, "InstantiateXML")
				.def(SceneInstantiateJSON, "InstantiateJSON")
				.def(&Scene::Clear, "Clear")
				.def(&Scene::SetUpdateEnabled, "SetUpdateEnabled")
				.def(&Scene::SetTimeScale, "SetTimeScale")
				.def(&Scene::SetElapsedTime, "SetElapsedTime")
				.def(&Scene::SetSmoothingConstant, "SetSmoothingConstant")
				.def(&Scene::SetSnapThreshold, "SetSnapThreshold")
				.def(&Scene::SetAsyncLoadingMs, "SetAsyncLoadingMs")
				.def(&Scene::AddRequiredPackageFile, "AddRequiredPackageFile")
				.def(&Scene::ClearRequiredPackageFiles, "ClearRequiredPackageFiles")
				.def(&Scene::RegisterVar, "RegisterVar")
				.def(&Scene::UnregisterVar, "UnregisterVar")
				.def(&Scene::UnregisterAllVars, "UnregisterAllVars")
				.def(&Scene::GetNode, "GetNode")
				.def(static_cast<Component* (Scene::*)(unsigned) const>(&Scene::GetComponent), "GetComponentByID")
				.def(&Scene::GetNodesWithTag, "GetNodesWithTag")
				.def(&Scene::IsUpdateEnabled, "IsUpdateEnabled")
				.def(&Scene::IsAsyncLoading, "IsAsyncLoading")
				.def(&Scene::GetAsyncProgress, "GetAsyncProgress")
				.def(&Scene::GetAsyncLoadMode, "GetAsyncLoadMode")
				.def(&Scene::GetFileName, "GetFileName")
				.def(&Scene::GetChecksum, "GetChecksum")
				.def(&Scene::GetTimeScale, "GetTimeScale")
				.def(&Scene::GetElapsedTime, "GetElapsedTime")
				.def(&Scene::GetSmoothingConstant, "GetSmoothingConstant")
				.def(&Scene::GetSnapThreshold, "GetSnapThreshold")
				.def(&Scene::GetAsyncLoadingMs, "GetAsyncLoadingMs")
				.def(&Scene::GetRequiredPackageFiles, "GetRequiredPackageFiles")
			
		];
	}
}
