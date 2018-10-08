# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

aux_source_directory(src/main/cpp/zlib DIR_SRCS_ZLIB)
aux_source_directory(src/main/cpp/png DIR_SRCS_PNG)
aux_source_directory(src/main/cpp/hpdf DIR_SRCS_HPDF)

include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/include)

add_library( # Sets the name of the library.
             hpdf-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/hpdf-lib.cpp
             ${DIR_SRCS_PNG}
             ${DIR_SRCS_ZLIB}
             ${DIR_SRCS_HPDF})
