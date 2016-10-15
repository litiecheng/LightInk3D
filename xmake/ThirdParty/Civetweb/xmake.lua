
if is_option("LightInk3DNETWORK") then

	local name = "Civetweb"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name


	add_includedirs(prefixInclude)
	
	
	-- add headers
	add_headers(prefixInclude .. "/*.h", prefixSrc .. "/*.inl")
			
	-- add files
	add_files(prefixSrc .. "/*.c")
	


end
	

