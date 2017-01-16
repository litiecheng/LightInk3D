

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
#include "Resource/JSONValue.h"
#include "Resource/XMLElement.h"
#include "Scene/Serializable.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static bool SerializableLoadSCSB(Serializable* self, Context * context, const String& fileName, bool setInstanceDefault = false)
	{
		SharedPtr<File> file(new File(context, fileName));
		return self->Load(*file, setInstanceDefault);
	}

	static bool SerializableSave(const Serializable* self, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		return self->Save(*file);
	}
	
	void bind_class_Serializable(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Serializable, void ()>(lm.state(), "Serializable", BaseClassStrategy<Object>())
				.def(SerializableLoadSCSB, "LoadSCSB")
				.def(&Serializable::Load, "Load")
				.def(SerializableSave, "Save")
				.def(&Serializable::Save, "Save")
				.def(&Serializable::LoadXML, "LoadXML")
				.def(&Serializable::SaveXML, "SaveXML")
				.def(&Serializable::LoadJSON, "LoadJSON")
				.def(&Serializable::SaveJSON, "SaveJSON")
				.def(static_cast<bool(Serializable::*)(unsigned int, const Variant&)>(&Serializable::SetAttribute), "SetAttributeUV")
				.def(static_cast<bool(Serializable::*)(const String&, const Variant&)>(&Serializable::SetAttribute), "SetAttributeSV")
				.def(static_cast<Variant(Serializable::*)(unsigned int) const>(&Serializable::GetAttribute), "GetAttributeU")
				.def(static_cast<Variant(Serializable::*)(const String&) const>(&Serializable::GetAttribute), "GetAttributeS")
				.def(static_cast<Variant(Serializable::*)(unsigned) const>(&Serializable::GetAttributeDefault), "GetAttributeDefaultU")
				.def(static_cast<Variant(Serializable::*)(const String&) const>(&Serializable::GetAttributeDefault), "GetAttributeDefaultS")
				.def(&Serializable::GetNumAttributes, "GetNumAttributes")
				.def(&Serializable::GetNumNetworkAttributes, "GetNumNetworkAttributes")
			
		];
	}
}
