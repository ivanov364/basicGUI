//
// BasicGUI C++ Library
//
// basicBackground.hpp
//
// Author: Ernest Ivanov
//

#ifndef basicBackground_hpp
#define basicBackground_hpp

    #ifdef GLAD 
        #include <glad/glad.h>
    #else
        #include "glad.h"
    #endif

    #include <GLFW/glfw3.h>

    #include <iostream>
    #include <string>
    #include <stdio.h>

    namespace basic{
        class basicBackground{
            public:
                /* Function to set background color */
                static void basicBackgroundColorFloat(float RED, float GREEN, float BLUE, float ALPHA);

                static int basicBackgroundColor(std::string COLOR);
        };
    }

#endif // basicBackground_hpp