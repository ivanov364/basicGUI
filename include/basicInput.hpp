//
// BasicGUI C++ Library
//
// basicInput.hpp
//
// Author: Ernest Ivanov
//

#ifndef basicInput_hpp
#define basicInput_hpp

    #ifdef GLAD 
        #include <glad/glad.h>
    #else
        #include "glad.h"
    #endif

    #include <GLFW/glfw3.h>

    #include <iostream>
    #include <stdio.h>

    #include "basicWindow.hpp"

    namespace basic{
        class basicInput : public basicWindow{
            public:
                /* process input function */
                static void basicInputCursorMode(GLFWwindow *window);

                basicInput();

            private:
                static void basicProcess(GLFWwindow *window); // GLFWwindow *window
                
        };
    }

#endif // basicInput_hpp