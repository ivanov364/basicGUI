//
// BasicGUI C++ Library
//
// basicWindow.hpp
//
// Author: Ernest Ivanov
//

#ifndef basicWindow_hpp
#define basicWindow_hpp

    #ifdef GLAD 
        #include <glad/glad.h>
    #else
        #include "glad.h"
    #endif

    #include <GLFW/glfw3.h>

    #include <iostream>
    #include <stdio.h> // fprintf

    namespace basic{

        static GLFWwindow* window; // private?

        class basicWindow{
            public:
                /* Functions */
                static void basicEvent(); // calls event

                static void basicFocus(); // focuses window // GLFWwindow* window

                static void basicTerminate(); // terminates window

                static void basicSetPosition(int POSITION_X, int POSITION_Y); //  sets window position //GLFWwindow* window, 

                static void basicSetIcon(const char* icon_path); // sets window icon // GLFWwindow* window, const char* images, int count
                
                static int basicVisibility(int STATUS); // windows visibility //GLFWwindow* window

                static int basicCreate(int WIDTH, int HEIGHT, const char* TITLE, int FULLSCREEN, int VSYNC); // creates window

                static int basicSetMinimumSize(int WIDTH, int HEIGHT); // GLFWwindow* window

                static int basicSetMaximumSize(int WIDTH, int HEIGHT); // GLFWwindow* window

                static int basicSet(); // sets all important window information

                static bool basicRun();

                ////////////////////////////////

                static void basicInput(); // GLFWwindow* window

            private:

                /* Functions */
                static void framebuffer_size_callback(GLFWwindow* window, int WIDTH, int HEIGHT);
        
                static void error_callback(int error, const char* description);

                static void windowVSync(int VSYNC);
        };

    }

#endif // basicWindow_hpp
