

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
#include "../../UI/DropDownList.h"
#include "../../UI/ListView.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<UIElement> DropDownListGetItem(const DropDownList* self, unsigned index)
	{
		return SharedPtr<UIElement>(self->GetItem(index));
	}

	static SharedPtr<UIElement> DropDownListGetSelectedItem(const DropDownList* self)
	{
		return SharedPtr<UIElement>(self->GetSelectedItem());
	}

	static SharedPtr<UIElement> DropDownListGetPlaceholder(const DropDownList* self)
	{
		return SharedPtr<UIElement>(self->GetPlaceholder());
	}
	void bind_class_DropDownList(LuaModele & lm)
	{
		lm
		[
			LuaRegister<DropDownList, void ()>(lm.state(), "DropDownList", BaseClassStrategy<Menu>())
				.disable_new()
				.def(CreateObject<DropDownList>, "new")
				.def(&DropDownList::AddItem, "AddItem")
				.def(&DropDownList::InsertItem, "InsertItem")
				.def(static_cast<void(DropDownList::*)(UIElement*)>(&DropDownList::RemoveItem), "RemoveItemUE")
				.def(static_cast<void(DropDownList::*)(unsigned int)>(&DropDownList::RemoveItem), "RemoveItemU")
				.def(&DropDownList::RemoveAllItems, "RemoveAllItems")
				.def(&DropDownList::SetSelection, "SetSelection")
				.def(&DropDownList::SetPlaceholderText, "SetPlaceholderText")
				.def(&DropDownList::SetResizePopup, "SetResizePopup")
				.def(&DropDownList::GetNumItems, "GetNumItems")
				.def(DropDownListGetItem, "GetItem")
				.def(&DropDownList::GetItems, "GetItems")
				.def(&DropDownList::GetSelection, "GetSelection")
				.def(DropDownListGetSelectedItem, "GetSelectedItem")
				.def(&DropDownList::GetListView, "GetListView")
				.def(DropDownListGetPlaceholder, "GetPlaceholder")
				.def(&DropDownList::GetPlaceholderText, "GetPlaceholderText")
				.def(&DropDownList::GetResizePopup, "GetResizePopup")

		];
	}
}
