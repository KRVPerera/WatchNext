cmake_minimum_required(VERSION 3.0.0)
project("WatchNext"
        VERSION 0.0.0.1
        LANGUAGES "CXX")

set (CMAKE_CXX_STANDARD 11)
#
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

include(cmake/StandardProjectSettings.cmake)

# enable cache system
include(cmake/Cache.cmake)

# Add linker configuration
include(cmake/Linker.cmake)

include(cmake/CompilerWarnings.cmake)

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

find_package(Boost 1.76.0 REQUIRED date_time filesystem system)
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)

add_executable(WatchNext
        src/cApp.cpp
        src/cApp.h
        src/cMain.cpp
        src/cMain.h)

 include(${wxWidgets_USE_FILE})
 include_directories(${Boost_INCLUDE_DIRS})
 target_link_libraries(WatchNext ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})



