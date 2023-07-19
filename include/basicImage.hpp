//
// BasicGUI C++ Library
//
// basicImage.hpp
//
// Author: Ernest Ivanov
//

#ifndef basicImage_hpp
#define basicImage_hpp

    #ifdef GLAD 
        #include <glad/glad.h>
    #else
        #include "glad.h"
    #endif

    #include <GLFW/glfw3.h>

    #include <stdio.h>
    #include <iostream>

    #include "basicWindow.hpp"

    namespace basic{
        class basicImage : public basicWindow{
            public:
                static int basicBackgroundImage(const char* PATH, int* WIDTH, int* HEIGHT, short BEHAVIOR, short TEXTURE_FILTERING, short MIPMAPS);

                static int basicSetImage(const char* PATH, int WIDTH, int HEIGHT, short BEHAVIOR, short TEXTURE_FILTERING, short MIPMAPS);
            private:

        };
    }

#endif // basicImage_hpp