add_library(lib STATIC api.h api.cpp console.h console.cpp info.h info.cpp pictures.h)


target_link_libraries(lib PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(lib PUBLIC cpr::cpr)
target_link_libraries(lib PUBLIC tabulate::tabulate)
