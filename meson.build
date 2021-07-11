
project('WatchNext', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20', 'macosx-version-min=10.10'])

#boost_dep = dependency('boost', modules : ['filesystem'])
wx_dep = dependency('wxwidgets', version : '3.1.5')

cc = meson.get_compiler('cpp')
lm = cc.find_library('m', required : false)
wx_osx_cocoau_core = cc.find_library('wx_osx_cocoau_core-3.1', required : false)
lz = cc.find_library('z', required : false)
pthread = cc.find_library('pthread', required : false)
iconv = cc.find_library('iconv', required : false)
curl = cc.find_library('curl', required : false)
lzma = cc.find_library('lzma', required : false)

extra_args = ['-dynamic', '-fPIC', '-DPIC', '-D_FILE_OFFSET_BITS=64', '-D__WXOSX_COCOA__', '-DWXUSINGDLL', '-mmacosx-version-min=10.10']

executable('WatchNext',
           'main.cpp',
           dependencies : [wx_dep, lm, wx_osx_cocoau_core, lz, pthread, iconv, curl, lzma],
           install : true)
