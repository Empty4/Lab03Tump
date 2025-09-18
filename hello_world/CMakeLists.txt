cmake_minimum_required(VERSION 3.10)
project(hello_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем исполняемый файл
add_executable(hello_world
    src/hello_world.cpp
)

# Включаем директории с заголовками
target_include_directories(hello_world PRIVATE
    ${CMAKE_SOURCE_DIR}/formatter_ex_lib/include
)

# Линкуем с библиотекой formatter_ex
target_link_libraries(hello_world PRIVATE formatter_ex)

# Устанавливаем путь для установки
install(TARGETS hello_world
    RUNTIME DESTINATION bin
)
