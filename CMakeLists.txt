cmake_minimum_required(VERSION 3.20.0)
project(RacingSimulator)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include_directories(lib/means_transport)

file(GLOB prjct
    src/*
)
add_executable(race ${prjct})

add_subdirectory(lib/means_transport)
target_link_libraries(race transport)