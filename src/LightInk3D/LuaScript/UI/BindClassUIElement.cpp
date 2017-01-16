

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
#include "UI/UIElement.h"
#include "IO/File.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static bool UIElementLoadXML(UIElement* uiElement, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return uiElement->LoadXML(*file);
	}

	static bool UIElementSaveXML(const UIElement* self, Context * context, const String& fileName, const String& indentation = "\t")
	{
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		if (!file->IsOpen())
			return  false;
		return self->SaveXML(*file, indentation);
	}

	static SharedPtr<UIElement> UIElementCreateChild(UIElement* self, StringHash type, const String& name = String::EMPTY, unsigned index = M_MAX_UNSIGNED)
	{
		return SharedPtr<UIElement>(self->CreateChild(type, name, index));
	}

	static SharedPtr<UIElement> UIElementGetChildUEU(const UIElement* self, unsigned int index)
	{
		return SharedPtr<UIElement>(self->GetChild(index));
	}

	static SharedPtr<UIElement> UIElementGetChildUESB(const UIElement* self, const String& name, bool recursive = false)
	{
		return SharedPtr<UIElement>(self->GetChild(name, recursive));
	}

	static SharedPtr<UIElement> UIElementGetChildUESHVB(const UIElement* self, StringHash key, const Variant& value, bool recursive = false)
	{
		return SharedPtr<UIElement>(self->GetChild(key, value, recursive));
	}

	static PODVector<UIElement*> UIElementGetChildren(const UIElement* self, bool recursive = false)
	{
		PODVector<UIElement*> dest;
		self->GetChildren(dest, recursive);
		return dest;
	}

	static PODVector<UIElement*> UIElementGetChildrenWithTag(const UIElement* self, const char* tag, bool recursive = false)
	{
		PODVector<UIElement*> dest;
		self->GetChildrenWithTag(dest, tag, recursive);
		return dest;
	}


	void bind_class_UIElement(LuaModule & lm)
	{
		lm
		[
			LuaRegister<UIElement, void ()>(lm.state(), "UIElement", BaseClassStrategy<Animatable>())
				.disable_new()
				.def(CreateObject<UIElement>, "new")
				.def(&UIElement::ScreenToElement, "ScreenToElement")
				.def(&UIElement::ElementToScreen, "ElementToScreen")
				.def(UIElementLoadXML, "LoadXML")
				.def(UIElementSaveXML, "SaveXML")
				.def(&UIElement::SetName, "SetName")
				.def(static_cast<void(UIElement::*)(const IntVector2&)>(&UIElement::SetPosition), "SetPositionIV")
				.def(static_cast<void(UIElement::*)(int, int)>(&UIElement::SetPosition), "SetPositionII")
				.def(static_cast<void(UIElement::*)(const IntVector2&)>(&UIElement::SetSize), "SetSizeIV")
				.def(static_cast<void(UIElement::*)(int, int)>(&UIElement::SetSize), "SetSizeII")
				.def(&UIElement::SetWidth, "SetWidth")
				.def(&UIElement::SetHeight, "SetHeight")
				.def(static_cast<void(UIElement::*)(const IntVector2&)>(&UIElement::SetMinSize), "SetMinSizeIV")
				.def(static_cast<void(UIElement::*)(int, int)>(&UIElement::SetMinSize), "SetMinSizeII")
				.def(&UIElement::SetMinWidth, "SetMinWidth")
				.def(&UIElement::SetMinHeight, "SetMinHeight")
				.def(static_cast<void(UIElement::*)(const IntVector2&)>(&UIElement::SetMaxSize), "SetMaxSizeIV")
				.def(static_cast<void(UIElement::*)(int, int)>(&UIElement::SetMaxSize), "SetMaxSizeII")
				.def(&UIElement::SetMaxWidth, "SetMaxWidth")
				.def(&UIElement::SetMaxHeight, "SetMaxHeight")
				.def(static_cast<void(UIElement::*)(const IntVector2&)>(&UIElement::SetFixedSize), "SetFixedSizeIV")
				.def(static_cast<void(UIElement::*)(int, int)>(&UIElement::SetFixedSize), "SetFixedSizeII")
				.def(&UIElement::SetFixedWidth, "SetFixedWidth")
				.def(&UIElement::SetFixedHeight, "SetFixedHeight")
				.def(&UIElement::SetAlignment, "SetAlignment")
				.def(&UIElement::SetHorizontalAlignment, "SetHorizontalAlignment")
				.def(&UIElement::SetVerticalAlignment, "SetVerticalAlignment")
				.def(&UIElement::SetClipBorder, "SetClipBorder")
				.def(static_cast<void(UIElement::*)(const Color&)>(&UIElement::SetColor), "SetColorC")
				.def(static_cast<void(UIElement::*)(Corner, const Color&)>(&UIElement::SetColor), "SetColorCC")
				.def(&UIElement::SetPriority, "SetPriority")
				.def(&UIElement::SetOpacity, "SetOpacity")
				.def(&UIElement::SetBringToFront, "SetBringToFront")
				.def(&UIElement::SetBringToBack, "SetBringToBack")
				.def(&UIElement::SetClipChildren, "SetClipChildren")
				.def(&UIElement::SetSortChildren, "SetSortChildren")
				.def(&UIElement::SetUseDerivedOpacity, "SetUseDerivedOpacity")
				.def(&UIElement::SetEnabled, "SetEnabled")
				.def(&UIElement::SetDeepEnabled, "SetDeepEnabled")
				.def(&UIElement::ResetDeepEnabled, "ResetDeepEnabled")
				.def(&UIElement::SetEnabledRecursive, "SetEnabledRecursive")
				.def(&UIElement::SetEditable, "SetEditable")
				.def(&UIElement::SetFocus, "SetFocus")
				.def(&UIElement::SetSelected, "SetSelected")
				.def(&UIElement::SetVisible, "SetVisible")
				.def(&UIElement::SetFocusMode, "SetFocusMode")
				.def(&UIElement::SetDragDropMode, "SetDragDropMode")
				.def(static_cast<bool(UIElement::*)(const String&, XMLFile*)>(&UIElement::SetStyle), "SetStyleSX")
				.def(static_cast<bool (UIElement::*)(const XMLElement&)>(&UIElement::SetStyle), "SetStyleX")
				.def(&UIElement::SetStyleAuto, "SetStyleAuto")
				.def(&UIElement::SetDefaultStyle, "SetDefaultStyle")
				.def(&UIElement::SetLayout, "SetLayout")
				.def(&UIElement::SetLayoutMode, "SetLayoutMode")
				.def(&UIElement::SetLayoutSpacing, "SetLayoutSpacing")
				.def(&UIElement::SetLayoutBorder, "SetLayoutBorder")
				.def(&UIElement::SetLayoutFlexScale, "SetLayoutFlexScale")
				.def(&UIElement::SetIndent, "SetIndent")
				.def(&UIElement::SetIndentSpacing, "SetIndentSpacing")
				.def(&UIElement::UpdateLayout, "UpdateLayout")
				.def(&UIElement::DisableLayoutUpdate, "DisableLayoutUpdate")
				.def(&UIElement::EnableLayoutUpdate, "EnableLayoutUpdate")
				.def(&UIElement::BringToFront, "BringToFront")
				.def(UIElementCreateChild, "CreateChild")
				.def(&UIElement::AddChild, "AddChild")
				.def(&UIElement::InsertChild, "InsertChild")
				.def(&UIElement::RemoveChild, "RemoveChild")
				.def(&UIElement::RemoveChildAtIndex, "RemoveChildAtIndex")
				.def(&UIElement::RemoveAllChildren, "RemoveAllChildren")
				.def(&UIElement::Remove, "Remove")
				.def(&UIElement::FindChild, "FindChild")
				.def(&UIElement::SetParent, "SetParent")
				.def(&UIElement::SetVar, "SetVar")
				.def(&UIElement::SetInternal, "SetInternal")
				.def(&UIElement::SetTraversalMode, "SetTraversalMode")
				.def(&UIElement::SetElementEventSender, "SetElementEventSender")
				.def(&UIElement::SetTags, "SetTags")
				.def(&UIElement::AddTag, "AddTag")
				.def(static_cast<void(UIElement::*)(const String&, char)>(&UIElement::AddTags), "AddTagsSC")
				.def(static_cast<void(UIElement::*)(const StringVector&)>(&UIElement::AddTags), "AddTagsSV")
				.def(&UIElement::RemoveTag, "RemoveTag")
				.def(&UIElement::RemoveAllTags, "RemoveAllTags")
				.def(&UIElement::GetName, "GetName")
				.def(&UIElement::GetPosition, "GetPosition")
				.def(&UIElement::GetSize, "GetSize")
				.def(&UIElement::GetWidth, "GetWidth")
				.def(&UIElement::GetHeight, "GetHeight")
				.def(&UIElement::GetMinSize, "GetMinSize")
				.def(&UIElement::GetMinWidth, "GetMinWidth")
				.def(&UIElement::GetMinHeight, "GetMinHeight")
				.def(&UIElement::GetMaxSize, "GetMaxSize")
				.def(&UIElement::GetMaxWidth, "GetMaxWidth")
				.def(&UIElement::GetMaxHeight, "GetMaxHeight")
				.def(&UIElement::IsFixedSize, "IsFixedSize")
				.def(&UIElement::IsFixedWidth, "IsFixedWidth")
				.def(&UIElement::IsFixedHeight, "IsFixedHeight")
				.def(&UIElement::GetChildOffset, "GetChildOffset")
				.def(&UIElement::GetHorizontalAlignment, "GetHorizontalAlignment")
				.def(&UIElement::GetVerticalAlignment, "GetVerticalAlignment")
				.def(&UIElement::GetClipBorder, "GetClipBorder")
				.def(&UIElement::GetColor, "GetColor")
				.def(&UIElement::GetPriority, "GetPriority")
				.def(&UIElement::GetOpacity, "GetOpacity")
				.def(&UIElement::GetDerivedOpacity, "GetDerivedOpacity")
				.def(&UIElement::GetBringToFront, "GetBringToFront")
				.def(&UIElement::GetBringToBack, "GetBringToBack")
				.def(&UIElement::GetClipChildren, "GetClipChildren")
				.def(&UIElement::GetSortChildren, "GetSortChildren")
				.def(&UIElement::GetUseDerivedOpacity, "GetUseDerivedOpacity")
				.def(&UIElement::HasFocus, "HasFocus")
				.def(&UIElement::IsEnabled, "IsEnabled")
				.def(&UIElement::IsEnabledSelf, "IsEnabledSelf")
				.def(&UIElement::IsEditable, "IsEditable")
				.def(&UIElement::IsSelected, "IsSelected")
				.def(&UIElement::IsVisible, "IsVisible")
				.def(&UIElement::IsVisibleEffective, "IsVisibleEffective")
				.def(&UIElement::IsHovering, "IsHovering")
				.def(&UIElement::IsInternal, "IsInternal")
				.def(&UIElement::HasColorGradient, "HasColorGradient")
				.def(&UIElement::GetFocusMode, "GetFocusMode")
				.def(&UIElement::GetDragDropMode, "GetDragDropMode")
				.def(&UIElement::GetAppliedStyle, "GetAppliedStyle")
				.def(&UIElement::GetDefaultStyle, "GetDefaultStyle")
				.def(&UIElement::GetLayoutMode, "GetLayoutMode")
				.def(&UIElement::GetLayoutSpacing, "GetLayoutSpacing")
				.def(&UIElement::GetLayoutBorder, "GetLayoutBorder")
				.def(&UIElement::GetLayoutFlexScale, "GetLayoutFlexScale")
				.def(&UIElement::GetNumChildren, "GetNumChildren")
				.def(UIElementGetChildUEU, "GetChildUEU")
				.def(UIElementGetChildUESB, "GetChildUESB")
				.def(UIElementGetChildUESHVB, "GetChildUESHVB")
				.def(UIElementGetChildren, "GetChildren")
				.def(&UIElement::GetParent, "GetParent")
				.def(&UIElement::GetRoot, "GetRoot")
				.def(&UIElement::GetDerivedColor, "GetDerivedColor")
				.def(&UIElement::GetVar, "GetVar")
				.def(&UIElement::GetVars, "GetVars")
				.def(&UIElement::HasTag, "HasTag")
				.def(&UIElement::GetTags, "GetTags")
				.def(UIElementGetChildrenWithTag, "GetChildrenWithTag")
				.def(&UIElement::GetDragButtonCombo, "GetDragButtonCombo")
				.def(&UIElement::GetDragButtonCount, "GetDragButtonCount")
				.def(&UIElement::IsInside, "IsInside")
				.def(&UIElement::IsInsideCombined, "IsInsideCombined")
				.def(&UIElement::GetCombinedScreenRect, "GetCombinedScreenRect")
				.def(&UIElement::SortChildren, "SortChildren")
				.def(&UIElement::GetLayoutElementMaxSize, "GetLayoutElementMaxSize")
				.def(&UIElement::GetIndent, "GetIndent")
				.def(&UIElement::GetIndentSpacing, "GetIndentSpacing")
				.def(&UIElement::GetIndentWidth, "GetIndentWidth")
				.def(&UIElement::GetScreenPosition, "GetScreenPosition")

		];
	}
}
