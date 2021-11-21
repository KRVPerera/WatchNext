cmake_minimum_required(VERSION 3.0.0)
project("WatchNext"
        VERSION 0.0.0.1
        LANGUAGES "CXX")

set(CMAKE_CXX_STANDARD 11)
#
set(Boost_USE_STATIC_LIBS ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS OFF)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS ON)  # only find release libs
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

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
find_package(spdlog REQUIRED)

add_executable(WatchNext
        src/cApp.cpp
        src/cApp.h
        src/cMain.cpp
        src/cMain.h)

include(${wxWidgets_USE_FILE})
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(WatchNext PRIVATE ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES} spdlog::spdlog)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)


list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_executable(tests test/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(
        tests
        TEST_PREFIX
        "unittests."
        EXTRA_ARGS
        -s
        --reporter=xml
        --out=tests.xml
)


enable_testing()