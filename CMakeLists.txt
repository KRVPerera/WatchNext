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


find_package(Boost 1.76.0 REQUIRED date_time filesystem system)
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)

add_executable(WatchNext
        src/cApp.cpp
        src/cApp.h
        src/cMain.cpp
        src/cMain.h)

if (wxWidgets_FOUND AND Boost_FOUND)
 include(${wxWidgets_USE_FILE})
 include_directories(${Boost_INCLUDE_DIRS})
 # and for each of your dependent executable/library targets:
 target_link_libraries(WatchNext ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})
endif()



