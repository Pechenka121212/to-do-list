cmake_minimum_required(VERSION 3.0)

project(to-do-list VERSION 0.0.1 LANGUAGES CXX)

set(
    CORE
        modules/core/core.h
        modules/core/core.cpp
)

set(
    START
        modules/start/main.cpp
)

set(
    DATABASE
        modules/database/db_notepad.h
        modules/database/db_notepad.cpp
)

add_executable(TaskList ${CORE} ${START} ${DATABASE})

target_include_directories(TaskList
    PRIVATE
    modules/core
    modules/database
)

set_target_properties(
    TaskList PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
