

if is_option("LightInk3DLua") or is_option("LightInk3DNETWORK") then
	local name = "Common"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

	add_defines("LIGHTINK_AS_DLL", "LIGHTINK_EXPORTS")

	-- add headers
	add_headers(prefixInclude .. "/*.h", prefixInclude .. "/*.cpp")
	add_headers(prefixInclude .. "/Atomic/*.h")
		
	-- add files
	add_files(prefixSrc .. "/*.cpp", prefixSrc .. "/*.c")

	if not is_plat("windows") then
		add_files(prefixSrc .. "/Atomic/*.c")
	end
	
end
	

