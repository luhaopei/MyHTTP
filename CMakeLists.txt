cmake_minimum_required(VERSION 3.1)
project(MyHTTP C CXX)
ADD_SUBDIRECTORY(lib lib)
ADD_SUBDIRECTORY(src bin)
ADD_SUBDIRECTORY(test)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_C_STANDARD 99)

# Put the libaries and binaries that get built into directories at the
# top of the build tree rather than in hard-to-find leaf directories.
INSTALL(FILES COPYRIGHT README DESTINATION share/doc/MyHTTP)
INSTALL(DIRECTORY doc/ DESTINATION share/doc/MyHTTP)

include_directories(${PROJECT_SOURCE_DIR})

# Put the libaries and binaries that get built into directories at the
# top of the build tree rather than in hard-to-find leaf directories.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# check epoll and add config.h for the macro compilation
include(CheckSymbolExists)
check_symbol_exists(epoll_create "sys/epoll.h" EPOLL_EXISTS)
if (EPOLL_EXISTS)
    # Linux下设置为epoll
    set(EPOLL_ENABLE 1 CACHE INTERNAL "enable epoll")

    # Linux下也设置为poll
#    set(EPOLL_ENABLE "" CACHE INTERNAL "not enable epoll")
else ()
    set(EPOLL_ENABLE "" CACHE INTERNAL "not enable epoll")
endif ()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/include/config.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
