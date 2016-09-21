


local name = "LightInk3D"
local deps = { 
	ThirdParty = "../../include/ThirdParty/",
}
local output = g_output

set_project("LightInk3D")
set_version("0.0.1")

add_subfiles("../LightInk3DOption.lua")

set_mode_config(name)

--[[
for k, v in pairs(deps) do
	add_subdirs(k)
end
--]]
local prefixInclude = "../../include/LightInk3D/"
local prefixSrc = "../../src/LightInk3D/"
-- add target
target(name)

    -- set kind
    set_kind("shared")
	
	for k, v in pairs(deps) do
		-- add deps
		add_deps(k)
		-- add links
		add_links(k)
	end
	
	add_includedirs(prefixInclude)
	for k, v in pairs(deps) do
		add_includedirs(v)
	end
	if output then
		set_targetdir(output.bin)
		set_objectdir(output.obj)
		set_headerdir(output.include)
		
		-- add link directory
		add_linkdirs(output.bin)
	else
		-- add link directory
		add_linkdirs("$(buildir)")
	end

	add_options("LightInk3DLua")
	add_options("LightInk3DEMSCRIPTEN")
	add_options("LightInk3DSQLite")
	add_options("LightInk3DOPENGL")
	add_options("LightInk3DDX9")
	add_options("LightInk3DDX11")
	add_options("LightInk3D2D")
	add_options("LightInk3DPHYSICS")
	add_options("LightInk3DNAVIGATION")
	add_options("LightInk3DNETWORK")

	local normalDir = { 
		Audio = "/**", 
		Container = "/**", 
		Core = "/**", 
		Graphics = "/*",
		Engine = "/**", 
		Input = "/**", 
		IO = "/**", 
		Math = "/**", 
		Resource = "/**", 
		Scene = "/**", 
		UI = "/**",
	}
	-- add headers
	add_headers(prefixInclude .. "*.h", prefixInclude .. "*.hpp")
	for k, v in pairs(normalDir) do
		add_headers(prefixInclude .. k .. v .. ".h", prefixInclude .. k .. v .. ".hpp")
	end
	
	
    -- add files
	add_files(prefixSrc .. "*.cpp", prefixSrc .. "*.c")
    for k, v in pairs(normalDir) do
		add_files(prefixSrc .. k .. v .. ".cpp", prefixSrc .. k .. v .. ".c")
	end
	
	
	local optionDir = {
		LightInk3DLua = "LuaScript/**",
		LightInk3DSQLite = "Database/**",
		LightInk3DOPENGL = "Graphics/OpenGL/**",
		LightInk3DDX9 = "Graphics/Direct3D9/**",
		LightInk3DDX11 = "Graphics/Direct3D11/**", 
		LightInk3D2D = "2D/**",
		LightInk3DPHYSICS = "Physics/**",
		LightInk3DNAVIGATION = "Navigation/**",
		LightInk3DNETWORK = "Network/**",
	}
	
	
	for k, v in pairs(optionDir) do
		if is_option(k) then
			add_headers(prefixInclude .. v .. ".h", prefixInclude .. v .. ".hpp")
			add_files(prefixSrc .. v .. ".cpp", prefixSrc .. v .. ".c")
		end
	end
	
	
	
	
	
	

