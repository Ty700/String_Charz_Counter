cmake_minimum_required(VERSION 3.28)
project(String_Charz_Counter VERSION 1.0.0)

set(EXE_NAME String_Charz_Counter)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${EXE_NAME} src/main.cpp)
add_subdirectory(src)
add_subdirectory(lib)
include_directories(${GTKMM_INCLUDE_DIRS})

target_compile_options(${EXE_NAME} PRIVATE -Wall -Wextra ${GTK4_CFLAGS})
target_include_directories(${EXE_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(${EXE_NAME} PRIVATE ${GTKMM_LIBRARIES})

target_compile_options(${EXE_NAME} PRIVATE
  $<$<CONFIG:Debug>:-DDEBUG>
)

set_target_properties(${EXE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/../bin/debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/../bin/release"
)
