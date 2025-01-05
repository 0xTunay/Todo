cmake_minimum_required(VERSION 3.10)

project(Todo)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

set(SRC
    src/Upper.c

)

set(INCLUDE
    include/todo.h
    include/Upper.h
)

add_library(core
    ${SRC}
    ${CORE_SRC}
)

add_executable(Todo
    main.c
)

target_link_libraries(Todo PRIVATE core)

