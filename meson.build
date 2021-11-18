project('WatchNext', 'cpp',
  version : '0.1',
  default_options : ['warning_level=1', 'cpp_std=c++20', 'macosx-version-min=10.10', 'optimization=s'])

conf_data = configuration_data()
conf_data.set('version', '0.1')
configure_file(input : 'config.h.in',
               output : 'config.h',
               configuration : conf_data)

subdir('src')