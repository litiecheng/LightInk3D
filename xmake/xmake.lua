

g_output = {
	bin = "$(projectdir)/__bin",
	obj = "$(projectdir)/__output/obj",
	include = "$(projectdir)/__output/include",
}
set_project("LightInk3D")
set_version("0.0.1")

add_subdirs("ThirdParty")
add_subdirs("LightInk3D")

