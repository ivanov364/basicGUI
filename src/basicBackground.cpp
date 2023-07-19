//
// BasicGUI C++ Library
//
// basicBackground.cpp
//
// Author: Ernest Ivanov
//

#include "../include/basicBackground.hpp"

void basic::basicBackground::basicBackgroundColorFloat(float RED, float GREEN, float BLUE, float ALPHA){
    glClearColor(RED, GREEN, BLUE, ALPHA);
    glClear(GL_COLOR_BUFFER_BIT);
}

int basic::basicBackground::basicBackgroundColor(std::string COLOR){

    if(COLOR == "white"){
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }else if(COLOR == "black"){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }else if(COLOR == "green"){
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }else if(COLOR == "red"){
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }else if(COLOR == "orange"){
        glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }else if(COLOR == "gray"){
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }else{
        std::cout << "Invalid color parameter.\nCheck documentation\n";
        glfwTerminate();
        return -1;
    }
    return 0;
}
