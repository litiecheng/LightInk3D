
local name = "Common"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DLua") or is_option("LightInk3DNETWORK") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		--add_defines("LIGHTINK_AS_DLL", "LIGHTINK_EXPORTS")

		-- add headers
		add_headers(prefixInclude .. "/*.h", prefixInclude .. "/*.cpp")
		add_headers(prefixInclude .. "/Atomic/*.h")
			
		-- add files
		add_files(prefixSrc .. "/*.cpp", prefixSrc .. "/*.c")

		if not is_plat("windows") then
			add_files(prefixSrc .. "/Atomic/*.c")
		end
		
	end
	
end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DLua") or is_option("LightInk3DNETWORK") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name
		
		--add_defines("LIGHTINK_AS_DLL")
		
	end
	
end
end