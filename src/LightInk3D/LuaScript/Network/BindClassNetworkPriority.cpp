

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
 
#ifdef URHO3D_NETWORK

#include "Precompiled.h"
#include "Network/NetworkPriority.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_NetworkPriority(LuaModele & lm)
	{
		lm
		[
			LuaRegister<NetworkPriority, void ()>(lm.state(), "NetworkPriority", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<NetworkPriority>, "new")
				.def(&NetworkPriority::SetBasePriority, "SetBasePriority")
				.def(&NetworkPriority::SetDistanceFactor, "SetDistanceFactor")
				.def(&NetworkPriority::SetMinPriority, "SetMinPriority")
				.def(&NetworkPriority::SetAlwaysUpdateOwner, "SetAlwaysUpdateOwner")
				.def(&NetworkPriority::GetBasePriority, "GetBasePriority")
				.def(&NetworkPriority::GetDistanceFactor, "GetDistanceFactor")
				.def(&NetworkPriority::GetMinPriority, "GetMinPriority")
				.def(&NetworkPriority::GetAlwaysUpdateOwner, "GetAlwaysUpdateOwner")
				.def(&NetworkPriority::CheckUpdate, "CheckUpdate")
				
		];
	}
}

#endif