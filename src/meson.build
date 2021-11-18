
warning_args = ['-Wshadow', '-Wnon-virtual-dtor',
        '-Wcast-align', '-Wunused', '-Woverloaded-virtual', '-Wpedantic', '-Wconversion',
                '-Wnull-dereference', '-Wdouble-promotion', '-Wformat=2']

add_global_arguments(warning_args, language : 'cpp')

boost_dep = dependency('boost', modules : ['json'])
wx_dep = dependency('wxwidgets', version : '3.1.5')

cc = meson.get_compiler('cpp')
lm = cc.find_library('m', required : false)
wx_osx_cocoau_core = cc.find_library('wx_osx_cocoau_core-3.1', required : false)
lz = cc.find_library('z', required : false)
pthread = cc.find_library('pthread', required : false)
iconv = cc.find_library('iconv', required : false)
curl = cc.find_library('curl', required : false)
lzma = cc.find_library('lzma', required : false)

src = ['cApp.cpp', 'cMain.cpp']

executable(meson.project_name(),
           src,
           dependencies : [wx_dep, lm, wx_osx_cocoau_core, lz, pthread, iconv, curl, lzma, boost_dep],
           cpp_pch : '../pch/cpp_pch.h',
           install: true
           )