


project('WatchNext', 'cpp',
  version : '0.1',
  debug : true,
  default_options : ['warning_level=3', 'cpp_std=c++20', 'macosx-version-min=10.10', 'optimization=s'])

conf_data = configuration_data()
conf_data.set('version', '0.1')
configure_file(input : 'config.h.in',
               output : 'config.h',
               configuration : conf_data)

warning_args = ['-Wall','-Wextra','-Wshadow', '-Wnon-virtual-dtor', '-Wold-style-cast',
        '-Wcast-align', '-Wunused', '-Woverloaded-virtual', '-Wpedantic', '-Wconversion', '-Wsign-conversion',
        '-Wnull-dereference', '-Wdouble-promotion', '-Wformat=2']
optval = get_option('warning_as_error')

if optval
    warning_args += '-Werror'
endif
        

#      -Wextra # reasonable and standard
#      -Wshadow # warn the user if a variable declaration shadows one from a parent context
#      -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps
#                       # catch hard to track down memory errors
#      -Wold-style-cast # warn for c-style casts
#      -Wcast-align # warn for potential performance problem casts
#      -Wunused # warn on anything being unused
#      -Woverloaded-virtual # warn if you overload (not override) a virtual function
#      -Wpedantic # warn if non-standard C++ is used
#      -Wconversion # warn on type conversions that may lose data
#      -Wsign-conversion # warn on sign conversions
#      -Wnull-dereference # warn if a null dereference is detected
#      -Wdouble-promotion # warn if float is implicit promoted to double
#      -Wformat=2 # warn on security issues around functions that format output (ie printf)

warning_args = ['-Wshadow', '-Wnon-virtual-dtor', '-Wold-style-cast',
        '-Wcast-align', '-Wunused', '-Woverloaded-virtual', '-Wpedantic', '-Wconversion', '-Wsign-conversion',
        '-Wnull-dereference', '-Wdouble-promotion', '-Wformat=2']

add_global_arguments(warning_args, language : 'cpp')

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

src = ['main.cpp', 'showNode.cpp']

executable('WatchNext',
           src,
           dependencies : [wx_dep, lm, wx_osx_cocoau_core, lz, pthread, iconv, curl, lzma],
           cpp_pch : 'pch/cpp_pch.h')
