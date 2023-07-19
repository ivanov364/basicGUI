//
// BasicGUI C++ Library
//
// basicWindow.cpp
//
// Author: Ernest Ivanov
//

#include "../include/basicWindow.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

void basic::basicWindow::error_callback(int error, const char* description){
    fprintf(stderr, "Error: %s\n", description);
}

void basic::basicWindow::framebuffer_size_callback(GLFWwindow* window, int WIDTH, int HEIGHT){ // GLFWwindow* window
    glViewport(0, 0, WIDTH, HEIGHT);
}

void basic::basicWindow::basicEvent(){
    /* check and call events and swap the buffers */
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void basic::basicWindow::windowVSync(int VSYNC){
    if(VSYNC == 1){
        glfwSwapInterval(1);
    }else{
        glfwSwapInterval(0);
    }
}

/* window func name */

void basic::basicWindow::basicFocus(){
    // GLFWwindow* window
    glfwFocusWindow(window);
}

void basic::basicWindow::basicSetPosition(int POSITION_X, int POSITION_Y){
    // GLFWwindow* window, 
    glfwSetWindowPos(window, POSITION_X, POSITION_Y);
}

void basic::basicWindow::basicSetIcon(const char* icon_path){
    // GLFWwindow* window, 
    
    GLFWimage images[1];
    images[0].pixels = stbi_load(icon_path, &images[0].width, &images[0].height, 0, 4);
    glfwSetWindowIcon(window, 1, images);
    stbi_image_free(images[0].pixels);
}

void basic::basicWindow::basicTerminate(){
    glfwTerminate();
}

int basic::basicWindow::basicSet(){

    glfwSetErrorCallback(error_callback);

    if (!glfwInit()){
        std::cout << "Failed to initialize GLFW\n";
        return -1;
    }

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}

int basic::basicWindow::basicCreate(int WIDTH, int HEIGHT, const char* TITLE, int FULLSCREEN, int VSYNC){

    window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

    if (FULLSCREEN == 1) { window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, glfwGetPrimaryMonitor(), NULL); }
    else if (FULLSCREEN == 0) { }
    else{
        std::cout << "Invalid FULLSCREEN parameter\n";
        glfwTerminate();
        return -1;
    }
    
    if (!window){
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (VSYNC == 1) { windowVSync(1); }
    else if (VSYNC == 0) { windowVSync(0); }
    else{
        std::cout << "Invalid VSYNC parameter\n";
        glfwTerminate();
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }
    return 0;
}

int basic::basicWindow::basicSetMinimumSize(int WIDTH, int HEIGHT){
    // GLFWwindow* window
    if (!window){
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeLimits(window, WIDTH, HEIGHT, GLFW_DONT_CARE, GLFW_DONT_CARE);

    return 0;
}

int basic::basicWindow::basicSetMaximumSize(int WIDTH, int HEIGHT){
    // GLFWwindow* window
    if (!window){
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeLimits(window, GLFW_DONT_CARE, GLFW_DONT_CARE, WIDTH, HEIGHT);

    return 0;
}

int basic::basicWindow::basicVisibility(int STATUS){
    // GLFWwindow
    if (STATUS == 1) { glfwHideWindow(window); }
    else if (STATUS == 0) { glfwShowWindow(window); }
    else{
        std::cout << "Invalid STATUS parameter\n";
        glfwTerminate();
        return -1;
    }
    return 0;
}

void basic::basicWindow::basicInput(){ // GLFWwindow* window
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

bool basic::basicWindow::basicRun(){
    if(!glfwWindowShouldClose(window)){
        return true;
    }
    return false;
}

/* window func name end */