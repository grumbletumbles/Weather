cmake_minimum_required(VERSION 3.23)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(BUILD_SHARED_LIBS ON)
project(
        Weather
        VERSION 1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(lib)
add_subdirectory(bin)

include(FetchContent)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr
                    GIT_TAG 340acc5cdad624b9398827eec2832fe2fd05f966)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_Declare(tabulate URL https://github.com/p-ranav/tabulate/archive/refs/tags/v1.5.tar.gz)
FetchContent_MakeAvailable(json)
FetchContent_MakeAvailable(cpr)
FetchContent_MakeAvailable(tabulate)

