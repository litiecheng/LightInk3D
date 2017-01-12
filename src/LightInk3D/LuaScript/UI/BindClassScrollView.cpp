

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
#include "../../UI/BorderImage.h"
#include "../../UI/ScrollBar.h"
#include "../../UI/ScrollView.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<UIElement> ScrollViewGetContentElement(const ScrollView* self)
	{
		return SharedPtr<UIElement>(self->GetContentElement());
	}
	void bind_class_ScrollView(LuaModele & lm)
	{
		lm
		[
			LuaRegister<ScrollView, void ()>(lm.state(), "ScrollView", BaseClassStrategy<UIElement>())
				.disable_new()
				.def(CreateObject<ScrollView>, "new")
				.def(&ScrollView::SetContentElement, "SetContentElement")
				.def(static_cast<void(ScrollView::*)(const IntVector2&)>(&ScrollView::SetViewPosition), "SetViewPositionIV")
				.def(static_cast<void(ScrollView::*)(int, int)>(&ScrollView::SetViewPosition), "SetViewPositionII")
				.def(&ScrollView::SetScrollBarsVisible, "SetScrollBarsVisible")
				.def(&ScrollView::SetScrollBarsAutoVisible, "SetScrollBarsAutoVisible")
				.def(&ScrollView::SetScrollStep, "SetScrollStep")
				.def(&ScrollView::SetPageStep, "SetPageStep")
				.def(&ScrollView::SetScrollDeceleration, "SetScrollDeceleration")
				.def(&ScrollView::SetScrollSnapEpsilon, "SetScrollSnapEpsilon")
				.def(&ScrollView::SetAutoDisableChildren, "SetAutoDisableChildren")
				.def(&ScrollView::SetAutoDisableThreshold, "SetAutoDisableThreshold")
				.def(&ScrollView::GetViewPosition, "GetViewPosition")
				.def(ScrollViewGetContentElement, "GetContentElement")
				.def(&ScrollView::GetHorizontalScrollBar, "GetHorizontalScrollBar")
				.def(&ScrollView::GetVerticalScrollBar, "GetVerticalScrollBar")
				.def(&ScrollView::GetScrollPanel, "GetScrollPanel")
				.def(&ScrollView::GetScrollBarsAutoVisible, "GetScrollBarsAutoVisible")
				.def(&ScrollView::GetScrollStep, "GetScrollStep")
				.def(&ScrollView::GetPageStep, "GetPageStep")
				.def(&ScrollView::GetScrollDeceleration, "GetScrollDeceleration")
				.def(&ScrollView::GetScrollSnapEpsilon, "GetScrollSnapEpsilon")
				.def(&ScrollView::GetAutoDisableChildren, "GetAutoDisableChildren")
				.def(&ScrollView::GetAutoDisableThreshold, "GetAutoDisableThreshold")
				
		];
	}
}
