#!/bin/bash
# Author: Ernest Ivanov

# /usr/include/

FILE_CMAKE =            CMakeLists.txt
FILE_CONAN =            conanfile.txt
FILE_PROFILE_CONAN =    /home/$(whoami)/.conan2/profiles
GLFW_PACKAGE =          glfw-x11


if (MSVC)
  #target_compile_options(<target> PUBLIC "/ZI")
  #target_link_options(<target> PUBLIC "/INCREMENTAL")
    echo "Windows not supported yet."
    exit 1
fi

if ! [[ -f "$FILE_CMAKE" && -f "$FILE_CONAN" ]]; then
    echo "$FILE_CMAKE or $FILE_CONAN does not exists."
    echo "Please reinstall package."
    exit 1
fi

if ! [ -x "$(command -v conan)" ]; then
    echo "Conan is not installed." >&2
    exit 1
fi

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    if [ -f /etc/os-release ]; then
        . /etc/os-release
        ID=$ID

        if [[ $ID == "arch" ]]
            "$(command sudo pacman -S "$GLFW_PACKAGE")"
            "$(command sudo pacman -S glm)"
        fi
    else
        echo '"/etc/os-release" path was not found.'
    fi
else
    echo "OSTYPE check not supported yet for your OS. Please install manually glfw3 or try to install through conan"
fi

if ! [ -f "$FILE_PROFILE_CONAN" ]; then
    echo "Conan profile does not exists."
    echo "Creating conan profile..."
    exec conan profile detect --force
fi

exec conan install . --output-folder=build --build=missing
mkdir build && cd build && exec cmake .. && exec sudo make install && exec export LD_LIBRARY_PATH=/usr/local/lib && exec sudo ldconfig

echo "Done!"
