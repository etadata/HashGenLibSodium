# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

# add by dreamer
message(${ANDROID_ABI})

file(GLOB CPP_FILES "*.cpp")
#include_directories(${PATH_TO_SUPERPOWERED}




# end
add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp)
# added by dreamer

#add_library( # Sets the name of the library.
#        Ext
#        SHARED
#        native-lib.cpp)

#### end of modif

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

#specific paraeters by dreamer
add_library( sodium
        STATIC
        IMPORTED)

# set the path to appropriate so files with appropriate architectures
set_property(TARGET
        sodium

        PROPERTY IMPORTED_LOCATION /home/nordo/AndroidStudioProjects/Lib//app/src/main/cpp/libsodium/libs/${ANDROID_ABI}/libsodium.a)

include_directories( libsodium/include )



#### end


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib
        sodium

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})