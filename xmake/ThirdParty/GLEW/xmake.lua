

local name = "GLEW"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DOPENGL") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)

		add_links("opengl32")
		
		-- add headers
		add_headers(prefixInclude .. "/**.h", prefixInclude .. "/**.hpp")

			
		-- add files
		add_files(prefixSrc .. "/**.c")



	end

end
end



if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DOPENGL") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)

		add_links("opengl32")

	end

end
end