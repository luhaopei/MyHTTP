cmake_minimum_required(VERSION 3.1)
project(MyHTTP C CXX)
ADD_SUBDIRECTORY(src bin)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

# Put the libaries and binaries that get built into directories at the
# top of the build tree rather than in hard-to-find leaf directories.

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
INSTALL(FILES COPYRIGHT README DESTINATION share/doc/MyHTTP)
INSTALL(DIRECTORY doc/ DESTINATION share/doc/MyHTTP)

include_directories(${PROJECT_SOURCE_DIR})