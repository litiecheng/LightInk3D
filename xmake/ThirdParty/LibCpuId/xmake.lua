

local name = "LibCpuId"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if not is_plat("linux") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_links("advapi32")
		
		add_includedirs(prefixInclude)
		
		-- add headers
		add_headers(prefixInclude .. "/*.h")

			
		-- add files
		add_files(prefixSrc .. "/*.c")

	end

end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if not is_plat("linux") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_links("advapi32")
		
		add_includedirs(prefixInclude)
		

	end

end
end