cmake_minimum_required(VERSION 3.11)

project(SortedAlghs-v1 CXX)

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Объявляем библиотеку
add_library(SortedAlghs-v1 INTERFACE "include/SortedAlghs.h")
target_include_directories(SortedAlghs-v1 INTERFACE "include")

add_executable(SortedAlghs-v1-main  "App/main.cc" )
target_link_libraries(SortedAlghs-v1-main SortedAlghs-v1)
add_executable(SortedAlghs-v1-test  "App/test.cc" )
target_link_libraries(SortedAlghs-v1-test SortedAlghs-v1)
