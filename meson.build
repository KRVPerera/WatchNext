project('WatchNext', 'cpp',
  version : '0.1',
  default_options : ['warning_level=1', 'cpp_std=c++20', 'macosx-version-min=10.10', 'optimization=s'])

conf_data = configuration_data()
conf_data.set('version', '0.1')
configure_file(input : 'config.h.in',
               output : 'config.h',
               configuration : conf_data)
boost_dep = dependency('boost', modules : ['json'])
wx_dep = dependency('wxwidgets', version : '3.1.5')
spdlog = dependency('spdlog')

cc = meson.get_compiler('cpp')
lm = cc.find_library('m', required : false)
wx_osx_cocoau_core = cc.find_library('wx_osx_cocoau_core-3.1', required : false)
pthread = cc.find_library('pthread', required : false)
#lz = cc.find_library('z', required : false)
#iconv = cc.find_library('iconv', required : false)
#curl = cc.find_library('curl', required : false)
#lzma = cc.find_library('lzma', required : false)

src = ['src/cApp.cpp', 'src/cMain.cpp']

executable(meson.project_name(),
           src,
           #dependencies : [wx_dep, spdlog, boost_dep, lm, wx_osx_cocoau_core, lz, pthread, iconv, curl, lzma],
           dependencies : [wx_dep, spdlog, boost_dep, lm, wx_osx_cocoau_core],
           cpp_pch : 'pch/cpp_pch.h',
           install: true
           )
