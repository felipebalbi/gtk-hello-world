# SPDX-License-Identifier: GPL-3.0-or-later

cmake_minimum_required(VERSION 3.20)

project(gtk-hello-world VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -ggdb -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O2 -flto")
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING
    "Choose build type: None Debug Release RelWithDebInfo MinSizeRel"
    FORCE)
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)

include_directories(include ${GTK_INCLUDE_DIRS})

# Create executable
add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTK_LIBRARIES})

# Visit subdirectory
add_subdirectory(src)
