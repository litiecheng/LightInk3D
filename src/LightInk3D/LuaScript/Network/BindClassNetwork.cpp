

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
#include "IO/PackageFile.h"
#include "Network/HttpRequest.h"
#include "Network/Network.h"
#include "Scene/Scene.h"
#include <kNet/kNet.h>
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Network(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Network, void ()>(lm.state(), "Network", BaseClassStrategy<Object>())
				.def(&Network::Connect, "Connect")
				.def(&Network::Disconnect, "Disconnect")
				.def(&Network::StartServer, "StartServer")
				.def(&Network::StopServer, "StopServer")
				.def(static_cast<void(Network::*)(int, bool, bool, const VectorBuffer&, unsigned int)>(&Network::BroadcastMessage), "BroadcastMessageIBBVU")
				.def(static_cast<void(Network::*)(int, bool, bool, const unsigned char*, unsigned int, unsigned int)>(&Network::BroadcastMessage), "BroadcastMessageIBBCUU")
				.def(static_cast<void(Network::*)(StringHash, bool, const VariantMap&)>(&Network::BroadcastRemoteEvent), "BroadcastRemoteEventSHBV")
				.def(static_cast<void(Network::*)(Scene*, StringHash, bool, const VariantMap&)>(&Network::BroadcastRemoteEvent), "BroadcastRemoteEventSSHBV")
				.def(static_cast<void(Network::*)(Node*, StringHash, bool, const VariantMap&)>(&Network::BroadcastRemoteEvent), "BroadcastRemoteEventNSHBV")
				.def(&Network::SetUpdateFps, "SetUpdateFps")
				.def(&Network::SetSimulatedLatency, "SetSimulatedLatency")
				.def(&Network::SetSimulatedPacketLoss, "SetSimulatedPacketLoss")
				.def(&Network::RegisterRemoteEvent, "RegisterRemoteEvent")
				.def(&Network::UnregisterRemoteEvent, "UnregisterRemoteEvent")
				.def(&Network::UnregisterAllRemoteEvents, "UnregisterAllRemoteEvents")
				.def(&Network::SetPackageCacheDir, "SetPackageCacheDir")
				.def(&Network::SendPackageToClients, "SendPackageToClients")
				.def(&Network::MakeHttpRequest, "MakeHttpRequest")
				.def(&Network::GetUpdateFps, "GetUpdateFps")
				.def(&Network::GetSimulatedLatency, "GetSimulatedLatency")
				.def(&Network::GetSimulatedPacketLoss, "GetSimulatedPacketLoss")
				.def(&Network::GetConnection, "GetConnection")
				.def(&Network::GetServerConnection, "GetServerConnection")
				.def(&Network::IsServerRunning, "IsServerRunning")
				.def(&Network::CheckRemoteEvent, "CheckRemoteEvent")
				.def(&Network::GetPackageCacheDir, "GetPackageCacheDir")
				
		];
	}
}

#endif