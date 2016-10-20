

local name = "MojoShader"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if is_plat("windows") and is_option("LightInk3DDX9") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)
		
		add_defines("_CRT_SECURE_NO_WARNINGS=1")

		-- add headers
		add_headers(prefixInclude .. "/*.h")

			
		-- add files
		add_files(prefixSrc .. "/*.cpp")



	end

end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if is_plat("windows") and is_option("LightInk3DDX9") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)

	end

end
end