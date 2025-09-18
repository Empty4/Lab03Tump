# Lab03Tump

# Отчет по лабораторной работе #3
## Вечтомова Юлия ИУ8-23

```bash
┌──(kali㉿empty4)-[~]
└─$ git clone https://github.com/tp-labs/lab03.git ~/empty4/lab03
Cloning into '/home/kali/empty4/lab03'...
remote: Enumerating objects: 24, done.
remote: Counting objects: 100% (24/24), done.
remote: Compressing objects: 100% (19/19), done.
remote: Total 24 (delta 7), reused 19 (delta 5), pack-reused 0
Receiving objects: 100% (24/24), 5.79 KiB | 5.79 MiB/s, done.
Resolving deltas: 100% (7/7), done.

┌──(kali㉿empty4)-[~]
└─$ cd ~/empty4/lab03
```

<details>
  <summary>Задание 1</summary>
  <p>
    Вам поручили перейти на систему автоматизированной сборки CMake. Исходные файлы находятся в директории formatter_lib. В этой директории находятся файлы для статической библиотеки formatter. Создайте CMakeList.txt в директории formatter_lib, с помощью которого можно будет собирать статическую библиотеку formatter.
    
```bash
┌──(kali㉿empty4)-[~/empty4/lab03]
└─$ find . -type f -name "*.hpp" -o -name "*.cpp" | sort
./formatter_ex_lib/include/formatter_ex.hpp
./formatter_ex_lib/src/formatter_ex.cpp
./formatter_lib/include/formatter.hpp
./formatter_lib/src/formatter.cpp

┌──(kali㉿empty4)-[~/empty4/lab03]
└─$ cd formatter_lib

┌──(kali㉿empty4)-[~/empty4/lab03/formatter_lib]
└─$ cat > CMakeLists.txt << 'EOF'
cmake_minimum_required(VERSION 3.10)
project(formatter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter STATIC
    src/formatter.cpp
)

target_include_directories(formatter
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(formatter PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OUTPUT_NAME formatter
)

install(TARGETS formatter
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
)
EOF

┌──(kali㉿empty4)-[~/empty4/lab03/formatter_lib]
└─$ ls -la CMakeLists.txt
-rw-r--r-- 1 kali kali 512 мар 18 13:45 CMakeLists.txt

```

  </p>
</details>

<details>
  <summary>Задание 2</summary>
  <p>

У компании "Formatter Inc." есть перспективная библиотека, которая является расширением предыдущей библиотеки. Т.к. вы уже овладели навыком созданием CMakeList.txt для статической библиотеки formatter, ваш руководитель поручает заняться созданием CMakeList.txt для библиотеки formatter_ex, которая в свою очередь использует библиотеку formatter.
    
```bash
┌──(kali㉿empty4)-[~/empty4/lab03/formatter_lib]
└─$ cd ../formatter_ex_lib

┌──(kali㉿empty4)-[~/empty4/lab03/formatter_ex_lib]
└─$ cat > CMakeLists.txt << 'EOF'
cmake_minimum_required(VERSION 3.10)
project(formatter_ex LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter_ex STATIC
    src/formatter_ex.cpp
)

target_include_directories(formatter_ex
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_SOURCE_DIR}/formatter_lib/include
)

target_link_libraries(formatter_ex PRIVATE formatter)

set_target_properties(formatter_ex PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OUTPUT_NAME formatter_ex
)

install(TARGETS formatter_ex
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
)
EOF

┌──(kali㉿empty4)-[~/empty4/lab03/formatter_ex_lib]
└─$ ls -la CMakeLists.txt
-rw-r--r-- 1 kali kali 723 мар 18 13:46 CMakeLists.txt
```

  </p>
</details>

<details>
  <summary>Задание 3</summary>
  <p>

  Конечно же ваша компания предоставляет примеры использования своих библиотек. Чтобы продемонстрировать как работать с библиотекой formatter_ex, вам необходимо создать два CMakeList.txt для двух простых приложений:

    hello_world, которое использует библиотеку formatter_ex;
    solver, приложение которое испольует статические библиотеки formatter_ex и solver_lib.

```bash
┌──(kali㉿empty4)-[~/empty4/lab03/formatter_ex_lib]
└─$ cd ..

┌──(kali㉿empty4)-[~/empty4/lab03]
└─$ mkdir -p hello_world/src solver/src solver_lib/src solver_lib/include

```

### Для hello_world:
```bash
┌──(kali㉿empty4)-[~/empty4/lab03]
└─$ cd hello_world

┌──(kali㉿empty4)-[~/empty4/lab03/hello_world]
└─$ cat > CMakeLists.txt << 'EOF'
cmake_minimum_required(VERSION 3.10)
project(hello_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world
    src/hello_world.cpp
)

target_include_directories(hello_world PRIVATE
    ${CMAKE_SOURCE_DIR}/formatter_ex_lib/include
)

target_link_libraries(hello_world PRIVATE formatter_ex)

install(TARGETS hello_world
    RUNTIME DESTINATION bin
)
EOF

```
Copyright (c) 2015-2021 The ISC Authors
```
