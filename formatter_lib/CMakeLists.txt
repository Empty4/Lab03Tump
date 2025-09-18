cmake_minimum_required(VERSION 3.10)
project(formatter)

# Устанавливаем стандарт C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем статическую библиотеку formatter
add_library(formatter STATIC
    src/formatter.cpp
)

# Включаем директории с заголовками
target_include_directories(formatter
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Устанавливаем выходную директорию для библиотеки
set_target_properties(formatter PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OUTPUT_NAME formatter
)

# Устанавливаем путь для установки библиотеки
install(TARGETS formatter
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
)
