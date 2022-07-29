project(
	'textgrid',
	'cpp',
	version : '0.1',
	default_options : [
		'warning_level=3',
		'cpp_std=c++17'
	])

public_headers = include_directories('include')

sources = files([
    'src/TextCell.cpp',
    'src/TextGrid.cpp',
    'src/Cell.cpp'
])

libtextgrid = library(
    'textgrid',
    sources,
    install : true,
    include_directories : public_headers
)

libtextgrid_dep = declare_dependency(
    include_directories : public_headers,
    link_with : libtextgrid
)

demo = executable(
    'demo',
    'src/demo.cpp',
    include_directories : public_headers,
    link_with : libtextgrid
)
