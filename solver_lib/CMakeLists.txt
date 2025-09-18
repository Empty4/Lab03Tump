cmake_minimum_required(VERSION 3.10)
project(solver_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем статическую библиотеку solver_lib
add_library(solver_lib STATIC
    src/solver.cpp
)

# Включаем директории с заголовками
target_include_directories(solver_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Устанавливаем выходную директорию
set_target_properties(solver_lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OUTPUT_NAME solver_lib
)

# Устанавливаем путь для установки
install(TARGETS solver_lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
)
