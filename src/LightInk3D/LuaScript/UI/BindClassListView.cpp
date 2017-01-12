

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
#include "../../UI/ListView.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<UIElement> ListViewGetItem(const ListView* self, unsigned index)
	{
		return SharedPtr<UIElement>(self->GetItem(index));
	}

	static SharedPtr<UIElement> ListViewGetSelectedItem(const ListView* self)
	{
		return SharedPtr<UIElement>(self->GetSelectedItem());
	}
	void bind_class_ListView(LuaModele & lm)
	{
		lm
		[
			LuaRegister<ListView, void ()>(lm.state(), "ListView", BaseClassStrategy<ScrollView>())
				.disable_new()
				.def(CreateObject<ListView>, "new")
				.def(&ListView::AddItem, "AddItem")
				.def(&ListView::InsertItem, "InsertItem")
				.def(static_cast<void(ListView::*)(UIElement*, unsigned int)>(&ListView::RemoveItem), "RemoveItemUEU")
				.def(static_cast<void (ListView::*)(unsigned int)>(&ListView::RemoveItem), "RemoveItemU")
				.def(&ListView::RemoveAllItems, "RemoveAllItems")
				.def(&ListView::SetSelection, "SetSelection")
				.def(&ListView::SetSelections, "SetSelections")
				.def(&ListView::AddSelection, "AddSelection")
				.def(&ListView::RemoveSelection, "RemoveSelection")
				.def(&ListView::ToggleSelection, "ToggleSelection")
				.def(&ListView::ChangeSelection, "ChangeSelection")
				.def(&ListView::ClearSelection, "ClearSelection")
				.def(&ListView::SetHighlightMode, "SetHighlightMode")
				.def(&ListView::SetMultiselect, "SetMultiselect")
				.def(&ListView::SetHierarchyMode, "SetHierarchyMode")
				.def(&ListView::SetBaseIndent, "SetBaseIndent")
				.def(&ListView::SetClearSelectionOnDefocus, "SetClearSelectionOnDefocus")
				.def(&ListView::SetSelectOnClickEnd, "SetSelectOnClickEnd")
				.def(&ListView::Expand, "Expand")
				.def(&ListView::GetNumItems, "GetNumItems")
				.def(ListViewGetItem, "GetItem")
				.def(&ListView::GetItems, "GetItems")
				.def(&ListView::FindItem, "FindItem")
				.def(&ListView::GetSelection, "GetSelection")
				.def(&ListView::GetSelections, "GetSelections")
				.def(&ListView::CopySelectedItemsToClipboard, "CopySelectedItemsToClipboard")
				.def(ListViewGetSelectedItem, "GetSelectedItem")
				.def(&ListView::GetSelectedItems, "GetSelectedItems")
				.def(&ListView::IsSelected, "IsSelected")
				.def(&ListView::IsExpanded, "IsExpanded")
				.def(&ListView::GetHighlightMode, "GetHighlightMode")
				.def(&ListView::GetMultiselect, "GetMultiselect")
				.def(&ListView::GetClearSelectionOnDefocus, "GetClearSelectionOnDefocus")
				.def(&ListView::GetSelectOnClickEnd, "GetSelectOnClickEnd")
				.def(&ListView::GetHierarchyMode, "GetHierarchyMode")
				.def(&ListView::GetBaseIndent, "GetBaseIndent")
				
				
		];
	}
}
