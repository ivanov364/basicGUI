# Author: Ernest Ivanov

# Specify the minimum version.
cmake_minimum_required(VERSION 3.25.3)

# Specify the project info.
project(basicGUI VERSION 0.3)

message("Using CMake version ${CMAKE_VERSION}")

set(CMAKE_CXX_STANDARD 20) ## 17
set(CMAKE_C_STANDARD 11)

# Specify the compiler options.
add_compile_options(-L/usr/lib -L/usr/local/lib -I/usr/local/include/freetype2/ -lglfw -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -pthread -lfreetype)

# Declare the library target.
add_library(${PROJECT_NAME} SHARED
    src/basic.cpp
    src/basicLog.cpp
    src/basicWindow.cpp
    src/basicText.cpp
    src/basicInput.cpp
    src/basicAudio.cpp
    #src/basicButton.cpp
    src/basicImage.cpp
    src/basicBackground.cpp
    src/glad.cpp
)

# Configure the directories to search for header files.
target_include_directories(${PROJECT_NAME} PRIVATE .) # PUBLIC

# Set the version property.
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set the shared object version property to the project's major version.
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# Set the public header property to the one with the actual API.
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "include/basic.hpp;include/basicInput.hpp;include/basicLog.hpp;include/khrplatform.h;include/glad.h;include/basicAudio.hpp;include/stb_image.h;include/basicBackground.hpp;include/basicGUI.hpp;include/basicWindow.hpp;include/shader.h;include/conio.h;include/basicText.hpp;include/basicImage.hpp;include/text.vs;include/text.fs") #include/basic.hpp

#include/basicButton.hpp

# For access to standard installation directory variables (CMAKE_INSTALL_xDIR).
include(GNUInstallDirs)

# Set library shared object and API header file to install.
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Create the pkg-config file from the template.
configure_file(src/${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

# Set pkg-config file to install.
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

# Enabling ctesting
#enable_testing()

#add_executable(test2 examples/test.cpp)
#add_test(Test test2)

# ctest
