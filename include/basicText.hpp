//
// BasicGUI C++ Library
//
// basicText.hpp
//
// Author: Ernest Ivanov
//

#ifndef basicText_hpp
#define basicText_hpp

	#include <iostream>
    #include <stdio.h>
    #include <algorithm>

	#include <string>
	#include <map>

    #ifdef GLAD 
        #include <glad/glad.h>
    #else
        #include "glad.h"
    #endif

    #include <GLFW/glfw3.h>

    #include <glm/glm.hpp>
    #include <glm/gtc/matrix_transform.hpp>
    #include <glm/gtc/type_ptr.hpp>

    #include "basicWindow.hpp"

    namespace basic{
        class basicText{
            public:
                /* Render-Text */
                /* change string type to const char* */
                static int basicRText(std::string TEXT, short TEXT_SIZE, float x, float y, float SCALE, std::string COLOR, std::string FONT, int WIDTH, int HEIGHT);

            private:
                
        };
    }


#endif // basicText_hpp