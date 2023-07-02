add_executable(${PROJECT_NAME} main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(BUILD_SHARED_LIBS ON)


target_link_libraries(${PROJECT_NAME} PRIVATE lib)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PUBLIC cpr::cpr)
target_link_libraries(${PROJECT_NAME} PUBLIC tabulate::tabulate)


