

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
#include "../../UI/Button.h"
#include "../../UI/DropDownList.h"
#include "../../UI/FileSelector.h"
#include "../../UI/LineEdit.h"
#include "../../UI/ListView.h"
#include "../../UI/Text.h"
#include "../../UI/Window.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_FileSelector(LuaModele & lm)
	{
		lm
		[
			LuaRegister<FileSelector, void ()>(lm.state(), "FileSelector", BaseClassStrategy<Object>())
				.disable_new()
				.def(CreateObject<FileSelector>, "new")
				.def(&FileSelector::SetDefaultStyle, "SetDefaultStyle")
				.def(&FileSelector::SetTitle, "SetTitle")
				.def(&FileSelector::SetButtonTexts, "SetButtonTexts")
				.def(&FileSelector::SetPath, "SetPath")
				.def(&FileSelector::SetFileName, "SetFileName")
				.def(&FileSelector::SetFilters, "SetFilters")
				.def(&FileSelector::SetDirectoryMode, "SetDirectoryMode")
				.def(&FileSelector::UpdateElements, "UpdateElements")
				.def(&FileSelector::GetDefaultStyle, "GetDefaultStyle")
				.def(&FileSelector::GetWindow, "GetWindow")
				.def(&FileSelector::GetTitleText, "GetTitleText")
				.def(&FileSelector::GetFileList, "GetFileList")
				.def(&FileSelector::GetPathEdit, "GetPathEdit")
				.def(&FileSelector::GetFileNameEdit, "GetFileNameEdit")
				.def(&FileSelector::GetFilterList, "GetFilterList")
				.def(&FileSelector::GetOKButton, "GetOKButton")
				.def(&FileSelector::GetCancelButton, "GetCancelButton")
				.def(&FileSelector::GetCloseButton, "GetCloseButton")
				.def(&FileSelector::GetTitle, "GetTitle")
				.def(&FileSelector::GetPath, "GetPath")
				.def(&FileSelector::GetFileName, "GetFileName")
				.def(&FileSelector::GetFilter, "GetFilter")
				.def(&FileSelector::GetFilterIndex, "GetFilterIndex")
				.def(&FileSelector::GetDirectoryMode, "GetDirectoryMode")
			<=
			LuaRegister<FileSelectorEntry, void ()>(lm.state(), "FileSelectorEntry")
				.def(&FileSelectorEntry::name_, "name")
				.def(&FileSelectorEntry::directory_, "directory")
				
		];
	}
}
