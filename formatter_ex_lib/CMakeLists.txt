cmake_minimum_required(VERSION 3.10)
project(formatter_ex LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем статическую библиотеку formatter_ex
add_library(formatter_ex STATIC
    src/formatter_ex.cpp
)

# Включаем директории с заголовками
target_include_directories(formatter_ex
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_SOURCE_DIR}/formatter_lib/include  # Прямой путь к formatter
)

# Линкуем с библиотекой formatter (просто указываем имя цели)
target_link_libraries(formatter_ex PRIVATE formatter)

# Устанавливаем выходную директорию для библиотеки
set_target_properties(formatter_ex PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OUTPUT_NAME formatter_ex
)

# Установочные цели
install(TARGETS formatter_ex
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
)
