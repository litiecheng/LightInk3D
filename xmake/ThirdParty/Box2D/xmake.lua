
local name = "Box2D"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)

	if is_option("LightInk3D2D") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		-- add headers
		add_headers(prefixInclude .. "/**.h", prefixInclude .. "/**.hpp")

			
		-- add files
		add_files(prefixSrc .. "/**.cpp")

	end

end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)

	if is_option("LightInk3D2D") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name
		

	end

end
end