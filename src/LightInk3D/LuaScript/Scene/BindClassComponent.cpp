

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
#include "../../Scene/Component.h"
#include "../../Scene/ReplicationState.h"
#include "../../Scene/Scene.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<Component> ComponentGetComponent(const Component* self, StringHash type)
	{
		return SharedPtr<Component>(self->GetComponent(type));
	}

	static PODVector<Component*> ComponentGetComponents(const Component* self)
	{
		PODVector<Component*> dest;
		self->GetComponents(dest);
		return dest;
	}
	void bind_class_Component(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Component, void ()>(lm.state(), "Component", BaseClassStrategy<Animatable>())
				.disable_new()
				.def(CreateObject<Component>, "new")
				.def(&Component::SetEnabled, "SetEnabled")
				.def(&Component::Remove, "Remove")
				.def(&Component::GetID, "GetID")
				.def(&Component::GetNode, "GetNode")
				.def(&Component::GetScene, "GetScene")
				.def(&Component::IsEnabled, "IsEnabled")
				.def(ComponentGetComponent, "GetComponent")
				.def(ComponentGetComponents, "GetComponents")
				.def(&Component::AddReplicationState, "AddReplicationState")
				.def(&Component::PrepareNetworkUpdate, "PrepareNetworkUpdate")

		];
	}
}
