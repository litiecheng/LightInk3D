

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
#include "UI/UI.h"
#include "IO/File.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<UIElement> UILoadLayoutUCSX(UI* self, Context * context, const String& fileName, XMLFile* styleFile = 0)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return SharedPtr<UIElement>();

		return self->LoadLayout(*file, styleFile);
	}

	static SharedPtr<UIElement> UILoadLayoutUXX(UI* self, XMLFile* file, XMLFile* styleFile = 0)
	{
		return self->LoadLayout(file, styleFile);
	}

	static bool UISaveLayout(UI* self, Context * context, const String& fileName, UIElement* element)
	{
		if (!element)
			return false;
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		if (!file->IsOpen())
			return false;
		return self->SaveLayout(*file, element);
	}

	static SharedPtr<UIElement> UIGetRoot(const UI* self)
	{
		return SharedPtr<UIElement>(self->GetRoot());
	}

	static SharedPtr<UIElement> UIGetRootModalElement(const UI* self)
	{
		return SharedPtr<UIElement>(self->GetRootModalElement());
	}

	static SharedPtr<UIElement> UIGetElementAtUIVB(UI* self, const IntVector2& position, bool enabledOnly = true)
	{
		return SharedPtr<UIElement>(self->GetElementAt(position, enabledOnly));
	}

	static SharedPtr<UIElement> UIGetElementAtUIIB(UI* self, int x, int y, bool enabledOnly = true)
	{
		return SharedPtr<UIElement>(self->GetElementAt(x, y, enabledOnly));
	}

	static SharedPtr<UIElement> UIGetFocusElement(const UI* self)
	{
		return SharedPtr<UIElement>(self->GetFocusElement());
	}

	static SharedPtr<UIElement> UIGetFrontElement(const UI* self)
	{
		return SharedPtr<UIElement>(self->GetFrontElement());
	}

	static SharedPtr<UIElement> UIGetDragElement(UI* self, unsigned index)
	{
		return SharedPtr<UIElement>(self->GetDragElement(index));
	}
	void bind_class_UI(LuaModule & lm)
	{
		lm
		[
			LuaRegister<UI, void ()>(lm.state(), "UI", BaseClassStrategy<Object>())
				.disable_new()
				.def(CreateObject<UI>, "new")
				.def(&UI::SetCursor, "SetCursor")
				.def(&UI::SetFocusElement, "SetFocusElement")
				.def(&UI::SetModalElement, "SetModalElement")
				.def(&UI::Clear, "Clear")
				.def(&UI::DebugDraw, "DebugDraw")
				.def(UILoadLayoutUCSX, "LoadLayoutUCSX")
				.def(UILoadLayoutUXX, "LoadLayoutUXX")
				.def(UISaveLayout, "SaveLayout")
				.def(&UI::SetClipboardText, "SetClipboardText")
				.def(&UI::SetDoubleClickInterval, "SetDoubleClickInterval")
				.def(&UI::SetDragBeginInterval, "SetDragBeginInterval")
				.def(&UI::SetDragBeginDistance, "SetDragBeginDistance")
				.def(&UI::SetDefaultToolTipDelay, "SetDefaultToolTipDelay")
				.def(&UI::SetMaxFontTextureSize, "SetMaxFontTextureSize")
				.def(&UI::SetNonFocusedMouseWheel, "SetNonFocusedMouseWheel")
				.def(&UI::SetUseSystemClipboard, "SetUseSystemClipboard")
				.def(&UI::SetUseScreenKeyboard, "SetUseScreenKeyboard")
				.def(&UI::SetUseMutableGlyphs, "SetUseMutableGlyphs")
				.def(&UI::SetForceAutoHint, "SetForceAutoHint")
				.def(&UI::SetScale, "SetScale")
				.def(&UI::SetWidth, "SetWidth")
				.def(&UI::SetHeight, "SetHeight")
				.def(UIGetRoot, "GetRoot")
				.def(UIGetRootModalElement, "GetRootModalElement")
				.def(&UI::GetCursor, "GetCursor")
				.def(&UI::GetCursorPosition, "GetCursorPosition")
				.def(UIGetElementAtUIIB, "GetElementAtUIIB")
				.def(UIGetElementAtUIVB, "GetElementAtUIVB")
				.def(UIGetFocusElement, "GetFocusElement")
				.def(UIGetFrontElement, "GetFrontElement")
				.def(&UI::GetNumDragElements, "GetNumDragElements")
				.def(UIGetDragElement "GetDragElement")
				.def(&UI::GetClipboardText, "GetClipboardText")
				.def(&UI::GetDoubleClickInterval, "GetDoubleClickInterval")
				.def(&UI::GetDragBeginInterval, "GetDragBeginInterval")
				.def(&UI::GetDragBeginDistance, "GetDragBeginDistance")
				.def(&UI::GetDefaultToolTipDelay, "GetDefaultToolTipDelay")
				.def(&UI::GetMaxFontTextureSize, "GetMaxFontTextureSize")
				.def(&UI::IsNonFocusedMouseWheel, "IsNonFocusedMouseWheel")
				.def(&UI::GetUseSystemClipboard, "GetUseSystemClipboard")
				.def(&UI::GetUseScreenKeyboard, "GetUseScreenKeyboard")
				.def(&UI::GetUseMutableGlyphs, "GetUseMutableGlyphs")
				.def(&UI::GetForceAutoHint, "GetForceAutoHint")
				.def(&UI::HasModalElement, "HasModalElement")
				.def(&UI::IsDragging, "IsDragging")

		];
	}
}
