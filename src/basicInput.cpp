//
// BasicGUI C++ Library
//
// basicInput.cpp
//
// Author: Ernest Ivanov
//

#include "../include/basicInput.hpp"

void basic::basicInput::basicProcess(GLFWwindow *window){ // GLFWwindow *window
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

void basic::basicInput::basicInputCursorMode(GLFWwindow *window){
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

basic::basicInput::basicInput(){
    basicProcess(window);
}