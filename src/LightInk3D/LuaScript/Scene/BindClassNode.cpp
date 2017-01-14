

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
#include "LuaScript/LuaFile.h"
#include "LuaScript/LuaScriptInstance.h"
#include "Resource/ResourceCache.h"
#include "Scene/Node.h"
#include "Scene/Scene.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static bool NodeSaveXML(const Node* self, Context * context, const String& fileName, const String& indentation = "\t")
	{
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		if (!file->IsOpen())
			return false;
		return self->SaveXML(*file, indentation);
	}

	static bool NodeSaveJSON(const Node* self, Context * context, const String& fileName, const String& indentation = "\t")
	{
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		if (!file->IsOpen())
			return false;
		return self->SaveJSON(*file, indentation);
	}
	static SharedPtr<Node> NodeCreateChild(Node* self, const String& name = String::EMPTY, CreateMode mode = REPLICATED, unsigned id = 0)
	{
		return SharedPtr<Node>(self->CreateChild(name, mode, id));
	}

	static SharedPtr<Component> NodeCreateComponent(Node* self, StringHash type, CreateMode mode = REPLICATED, unsigned id = 0)
	{
		return SharedPtr<Component>(self->CreateComponent(type, mode, id));
	}

	static SharedPtr<Component> NodeGetOrCreateComponent(Node* self, StringHash type, CreateMode mode = REPLICATED, unsigned id = 0)
	{
		return SharedPtr<Component>(self->GetOrCreateComponent(type, mode, id));
	}


	static LuaRef NodeCreateScriptObjectNC(Node* node, const char* scriptObjectType)
	{
		LuaScriptInstance* instance = node->CreateComponent<LuaScriptInstance>();
		instance->CreateObject(scriptObjectType);

		lua_rawgeti(instance->GetLuaState(), LUA_REGISTRYINDEX, instance->GetScriptObjectRef());

		return LuaRef(instance->GetLuaState(), true);
	}

	static LuaRef NodeCreateScriptObjectNCC(Node* node, const char* fileName, const char* scriptObjectType)
	{
		ResourceCache* cache = node->GetSubsystem<ResourceCache>();
		LuaFile* scriptFile = cache->GetResource<LuaFile>(fileName);
		if (!scriptFile)
			return 0;

		LuaScriptInstance* instance = node->CreateComponent<LuaScriptInstance>();
		instance->CreateObject(scriptFile, scriptObjectType);

		lua_rawgeti(instance->GetLuaState(), LUA_REGISTRYINDEX, instance->GetScriptObjectRef());
		return LuaRef(instance->GetLuaState(), true);
	}

	static LuaRef NodeGetScriptObject(Node* self)
	{
		LuaScriptInstance* instance = self->GetComponent<LuaScriptInstance>();
		if (!instance)
			return 0;

		lua_rawgeti(instance->GetLuaState(), LUA_REGISTRYINDEX, instance->GetScriptObjectRef());
		return LuaRef(instance->GetLuaState(), true);
	}

	static SharedPtr<Component> NodeCloneComponentNC(Node* self, Component* component, unsigned int id = 0)
	{
		return SharedPtr<Component>(self->CloneComponent(component, id));
	}

	static SharedPtr<Component> NodeCloneComponentNCCU(Node* self, Component* component, CreateMode mode, unsigned int id = 0)
	{
		return SharedPtr<Component>(self->CloneComponent(component, mode, id));
	}


	static SharedPtr<Node> NodeClone(Node* self, CreateMode mode = REPLICATED)
	{
		return SharedPtr<Node>(self->Clone(mode));
	}


	static PODVector<Node*> NodeGetChildren(const Node* self, bool recursive = false)
	{
		PODVector<Node*> dest;
		self->GetChildren(dest, recursive);
		return dest;
	}


	static PODVector<Node*> NodeGetChildrenWithComponent(const Node* self, StringHash type, bool recursive = false)
	{
		PODVector<Node*> dest;
		self->GetChildrenWithComponent(dest, type, recursive);
		return dest;
	}


	static PODVector<Node*> NodeGetChildrenWithTag(const Node* self, const String& tag, bool recursive = false)
	{
		PODVector<Node*> dest;
		self->GetChildrenWithTag(dest, tag, recursive);
		return dest;
	}

	static PODVector<Component*> NodeGetComponents(const Node* self, StringHash type, bool recursive = false)
	{
		PODVector<Component*> dest;
		self->GetComponents(dest, type, recursive);
		return dest;
	}

	static SharedPtr<Component> NodeGetComponent(const Node* node, StringHash type, bool recursive = false)
	{
		return SharedPtr<Component>(node->GetComponent(type, recursive));
	}

	static SharedPtr<Component> NodeGetParentComponent(const Node* node, StringHash type, bool fullTraversal = false)
	{
		return SharedPtr<Component>(node->GetParentComponent(type, fullTraversal));
	}

	void bind_class_Node(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Node, void ()>(lm.state(), "Node", BaseClassStrategy<Animatable>())
				.disable_new()
				.def(CreateObject<Node>, "new")
				.def(NodeSaveXML, "SaveXML")
				.def(NodeSaveJSON, "SaveJSON")
				.def(&Node::SetID, "SetID")
				.def(&Node::SetName, "SetName")
				.def(&Node::SetTags, "SetTags")
				.def(&Node::AddTag, "AddTag")
				.def(static_cast<void(Node::*)(const String&, char)>(&Node::AddTags), "AddTagsSC")
				.def(static_cast<void(Node::*)(const StringVector&)>(&Node::AddTags), "AddTagsSV")
				.def(&Node::RemoveTag, "RemoveTag")
				.def(&Node::RemoveAllTags, "RemoveAllTags")
				.def(&Node::SetPosition, "SetPosition")
				.def(static_cast<void(Node::*)(const Vector2&)>(&Node::SetPosition2D), "SetPosition2DV")
				.def(static_cast<void(Node::*)(float, float)>(&Node::SetPosition2D), "SetPosition2DFF")
				.def(&Node::SetRotation, "SetRotation")
				.def(&Node::SetRotation2D, "SetRotation2D")
				.def(&Node::SetDirection, "SetDirection")
				.def(static_cast<void(Node::*)(float)>(&Node::SetScale), "SetScaleF")
				.def(static_cast<void(Node::*)(const Vector3&)>(&Node::SetScale), "SetScaleV")
				.def(static_cast<void(Node::*)(const Vector2&)>(&Node::SetScale2D), "SetScale2DV")
				.def(static_cast<void(Node::*)(float, float)>(&Node::SetScale2D), "SetScale2DFF")
				.def(static_cast<void(Node::*)(const Vector3&, const Quaternion&)>(&Node::SetTransform), "SetTransformVQ")
				.def(static_cast<void(Node::*)(const Vector3&, const Quaternion&, float)>(&Node::SetTransform), "SetTransformVQF")
				.def(static_cast<void(Node::*)(const Vector3&, const Quaternion&, const Vector3&)>(&Node::SetTransform), "SetTransformVQV")
				.def(static_cast<void(Node::*)(const Vector2&, float)>(&Node::SetTransform2D), "SetTransform2DVF")
				.def(static_cast<void(Node::*)(const Vector2&, float, float)>(&Node::SetTransform2D), "SetTransform2DVFF")
				.def(static_cast<void(Node::*)(const Vector2&, float, const Vector2&)>(&Node::SetTransform2D), "SetTransform2DVFV")
				.def(&Node::SetWorldPosition, "SetWorldPosition")
				.def(static_cast<void(Node::*)(const Vector2&)>(&Node::SetWorldPosition2D), "SetWorldPosition2DV")
				.def(static_cast<void(Node::*)(float, float)>(&Node::SetWorldPosition2D), "SetWorldPosition2DFF")
				.def(&Node::SetWorldRotation, "SetWorldRotation")
				.def(&Node::SetWorldRotation2D, "SetWorldRotation2D")
				.def(&Node::SetWorldDirection, "SetWorldDirection")
				.def(static_cast<void(Node::*)(float)>(&Node::SetWorldScale), "SetWorldScaleF")
				.def(static_cast<void(Node::*)(const Vector3&)>(&Node::SetWorldScale), "SetWorldScaleV")
				.def(static_cast<void(Node::*)(const Vector2&)>(&Node::SetWorldScale2D), "SetWorldScale2DV")
				.def(static_cast<void(Node::*)(float, float)>(&Node::SetWorldScale2D), "SetWorldScale2DFF")
				.def(static_cast<void(Node::*)(const Vector3&, const Quaternion&)>(&Node::SetWorldTransform), "SetWorldTransformVQ")
				.def(static_cast<void(Node::*)(const Vector3&, const Quaternion&, float)>(&Node::SetWorldTransform), "SetWorldTransformVQF")
				.def(static_cast<void(Node::*)(const Vector3&, const Quaternion&, const Vector3&)>(&Node::SetWorldTransform), "SetWorldTransformVQV")
				.def(static_cast<void(Node::*)(const Vector2&, float)>(&Node::SetWorldTransform2D), "SetWorldTransform2DVF")
				.def(static_cast<void(Node::*)(const Vector2&, float, float)>(&Node::SetWorldTransform2D), "SetWorldTransform2DVFF")
				.def(static_cast<void(Node::*)(const Vector2&, float, const Vector2&)>(&Node::SetWorldTransform2D), "SetWorldTransform2DVFV")
				.def(&Node::Translate, "Translate")
				.def(&Node::Translate2D, "Translate2D")
				.def(&Node::Rotate, "Rotate")
				.def(&Node::Rotate2D, "Rotate2D")
				.def(&Node::RotateAround, "RotateAround")
				.def(&Node::RotateAround2D, "RotateAround2D")
				.def(&Node::Pitch, "Pitch")
				.def(&Node::Yaw, "Yaw")
				.def(&Node::Roll, "Roll")
				.def(&Node::LookAt, "LookAt")
				.def(static_cast<void(Node::*)(float)>(&Node::Scale), "ScaleF")
				.def(static_cast<void(Node::*)(const Vector3&)>(&Node::Scale), "ScaleV")
				.def(&Node::Scale2D, "Scale2D")
				.def(static_cast<void(Node::*)(bool)>(&Node::SetEnabled), "SetEnabled")
				.def(&Node::SetDeepEnabled, "SetDeepEnabled")
				.def(&Node::ResetDeepEnabled, "ResetDeepEnabled")
				.def(&Node::SetEnabledRecursive, "SetEnabledRecursive")
				.def(&Node::MarkDirty, "MarkDirty")
				.def(NodeCreateChild, "CreateChild")
				.def(&Node::AddChild, "AddChild")
				.def(static_cast<void(Node::*)(Node*)>(&Node::RemoveChild), "RemoveChild")
				.def(&Node::RemoveAllChildren, "RemoveAllChildren")
				.def(&Node::RemoveChildren, "RemoveChildren")
				.def(NodeCreateComponent, "CreateComponent")
				.def(NodeGetOrCreateComponent, "GetOrCreateComponent")
				.def(NodeCreateScriptObjectNC, "CreateScriptObjectNC")
				.def(NodeCreateScriptObjectNCC, "CreateScriptObjectNCC")
				.def(NodeGetScriptObject, "GetScriptObject")
				.def(NodeCloneComponentNCU, "CloneComponentNCU")
				.def(NodeCloneComponentNCCU, "CloneComponentNCCU")
				.def(static_cast<void(Node::*)(Component*)>(&Node::RemoveComponent), "RemoveComponentC")
				.def(static_cast<void(Node::*)(StringHash)>(&Node::RemoveComponent), "RemoveComponentSH")
				.def(static_cast<void(Node::*)(bool, bool)>(&Node::RemoveComponents), "RemoveComponentsBB")
				.def(static_cast<void(Node::*)(StringHash)>(&Node::RemoveComponents), "RemoveComponentsSH")
				.def(&Node::RemoveAllComponents, "RemoveAllComponents")
				.def(&Node::ReorderComponent, "ReorderComponent")
				.def(NodeClone, "Clone")
				.def(&Node::Remove, "Remove")
				.def(&Node::SetParent, "SetParent")
				.def(&Node::SetVar, "SetVar")
				.def(&Node::AddListener, "AddListener")
				.def(&Node::RemoveListener, "RemoveListener")
				.def(&Node::GetID, "GetID")
				.def(&Node::GetName, "GetName")
				.def(&Node::GetNameHash, "GetNameHash")
				.def(&Node::GetTags, "GetTags")
				.def(&Node::HasTag, "HasTag")
				.def(&Node::GetParent, "GetParent")
				.def(&Node::GetScene, "GetScene")
				.def(&Node::IsEnabled, "IsEnabled")
				.def(&Node::IsEnabledSelf, "IsEnabledSelf")
				.def(&Node::GetPosition, "GetPosition")
				.def(&Node::GetPosition2D, "GetPosition2D")
				.def(&Node::GetRotation, "GetRotation")
				.def(&Node::GetRotation2D, "GetRotation2D")
				.def(&Node::GetDirection, "GetDirection")
				.def(&Node::GetUp, "GetUp")
				.def(&Node::GetRight, "GetRight")
				.def(&Node::GetScale, "GetScale")
				.def(&Node::GetScale2D, "GetScale2D")
				.def(&Node::GetTransform, "GetTransform")
				.def(&Node::GetWorldPosition, "GetWorldPosition")
				.def(&Node::GetWorldPosition2D, "GetWorldPosition2D")
				.def(&Node::GetWorldRotation, "GetWorldRotation")
				.def(&Node::GetWorldRotation2D, "GetWorldRotation2D")
				.def(&Node::GetWorldDirection, "GetWorldDirection")
				.def(&Node::GetWorldUp, "GetWorldUp")
				.def(&Node::GetWorldRight, "GetWorldRight")
				.def(&Node::GetWorldScale, "GetWorldScale")
				.def(&Node::GetWorldScale2D, "GetWorldScale2D")
				.def(&Node::GetWorldTransform, "GetWorldTransform")
				.def(static_cast<Vector3(Node::*)(const Vector3&) const>(&Node::LocalToWorld), "LocalToWorldV3")
				.def(static_cast<Vector3(Node::*)(const Vector4&) const>(&Node::LocalToWorld), "LocalToWorldV4")
				.def(&Node::LocalToWorld2D, "LocalToWorld2D")
				.def(static_cast<Vector3(Node::*)(const Vector3&) const>(&Node::WorldToLocal), "WorldToLocalV3")
				.def(static_cast<Vector3(Node::*)(const Vector4&) const>(&Node::WorldToLocal), "WorldToLocalV4")
				.def(&Node::WorldToLocal2D, "WorldToLocal2D")
				.def(&Node::IsDirty, "IsDirty")
				.def(&Node::GetNumChildren, "GetNumChildren")
				.def(NodeGetChildren, "GetChildren")
				.def(NodeGetChildrenWithComponent, "GetChildrenWithComponent")
				.def(NodeGetChildrenWithTag, "GetChildrenWithTag")
				.def(static_cast<Node*(Node::*)(unsigned int) const>(&Node::GetChild), "GetChildU")
				.def(static_cast<Node*(Node::*)(const String&, bool)const)>(&Node::GetChild), "GetChildSB")
				.def(&Node::GetNumComponents, "GetNumComponents")
				.def(&Node::GetNumNetworkComponents, "GetNumNetworkComponents")
				.def(static_cast<const Vector<SharedPtr<Component> >&(Node::*)() const>(&Node::GetComponents), "GetComponents")
				.def(NodeGetComponents, "GetComponentsNSHB")
				.def(NodeGetComponent, "GetComponent")
				.def(NodeGetParentComponent, "GetParentComponent")
				.def(static_cast<bool(Node::*)(StringHash)const>(&Node::HasComponent), "HasComponent")
				.def(&Node::GetVar, "GetVar")
				.def(&Node::GetVars, "GetVars")

		];
	}
}
