

function set_mode_config(name)
	if is_mode("debug") then
		if is_plat("windows") then
			-- enable some checkers
			add_cxflags("-Gs", "-RTC1") 

			-- link libcmtd.lib
			add_cxflags("-MDd") 
			local output = g_output
			if output then
				output = output.bin .. "/"
			else
				output = "$(buildir)/"
			end
			add_cxflags("-Zi")--, "-Fd" .. output .. name .. ".pdb")
			add_ldflags("-pdb:" .. output .. name .. ".pdb")
			--add_arflags("-pdb:" .. output .. name .. ".pdb")
			add_defines("_DEBUG=1")
		else
			-- enable the debug symbols
			set_symbols("debug")
		end
		add_defines("Debug")
		-- disable optimization
		set_optimize("none")
	elseif is_mode("release") then
		  -- set the symbols visibility: hidden
		set_symbols("hidden")

		-- enable fastest optimization
		set_optimize("fastest")

		-- strip all symbols
		set_strip("all")
		if is_plat("windows") then
			-- link libcmt.lib
			add_cxflags("-MD") 
		else
		
		end
	
	end
	
	if is_arch("*64") then
		add_defines("URHO3D_64BIT")
	end
	if is_plat("windows") then
		add_defines("_WINDOWS", "WINDOWS", "_WIN32", "WIN32")
	end
	
	--set_languages("c99", "cxx98")
	--add_defines("__cplusplus")
	
end


option("LightInk3DLua")
	
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("URHO3D_LUA")
	
option("LightInk3DEMSCRIPTEN")
	
	set_default(false)
	
	set_showmenu(true)
	
	add_defines_if_ok("__EMSCRIPTEN__")
	
option("LightInk3DSQLite")
	
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("URHO3D_DATABASE")
	add_defines_if_ok("URHO3D_DATABASE_SQLITE")
	
option("LightInk3DOPENGL")
	
	set_default(false)
	
	set_showmenu(true)
	
	add_defines_if_ok("URHO3D_OPENGL")

option("LightInk3DDX9")
	
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("LightInk3DDX9")

option("LightInk3DDX11")
	
	set_default(false)
	
	set_showmenu(true)
	
	add_defines_if_ok("URHO3D_D3D11")
	
option("LightInk3D2D")
	
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("URHO3D_URHO2D")
	
option("LightInk3DPHYSICS")
	
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("URHO3D_PHYSICS")

option("LightInk3DNAVIGATION")
	
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("URHO3D_NAVIGATION")
	

option("LightInk3DNETWORK")
	
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("URHO3D_NETWORK")	
	
	
option("LightInk3DDUMMYAUDIO")
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("SDL_AUDIO_DRIVER_DUMMY")
	
option("LightInk3DDISKAUDIO")
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("SDL_AUDIO_DRIVER_DISK")
	
option("LightInk3DVIDEO_DUMMY")
	set_default(true)
	
	set_showmenu(true)
	
	add_defines_if_ok("SDL_VIDEO_DRIVER_DUMMY")
	
	

	