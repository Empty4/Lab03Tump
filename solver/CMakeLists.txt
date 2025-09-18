cmake_minimum_required(VERSION 3.10)
project(solver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем исполняемый файл
add_executable(solver
    src/equation.cpp
)

# Включаем директории с заголовками
target_include_directories(solver PRIVATE
    ${CMAKE_SOURCE_DIR}/formatter_ex_lib/include
    ${CMAKE_SOURCE_DIR}/solver_lib/include
)

# Линкуем с библиотеками
target_link_libraries(solver PRIVATE formatter_ex solver_lib)

# Устанавливаем путь для установки
install(TARGETS solver
    RUNTIME DESTINATION bin
)
