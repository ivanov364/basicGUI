//
// BasicGUI C++ Library
//
// basicButton.cpp
//
// Author: Ernest Ivanov
//

#include "../include/basicButton.hpp"

#include <GL/glut.h>
#include "glui.h"

int window_id = glutCreateWindow( "Main gfx window" ); //  global???

GLUI *glui = GLUI_Master.create_glui( "name", flags, x, y ); // globalVar

GLUI_Master.set_glutIdleFunc( myGlutIdle ); // global ??

void myGlutIdle(void){
	glutSetWindow(main_window);
	glutPostRedisplay();
}

static int basic::basicButton::basicButton(const char TEXT, short TEXT_SIZE, const char COLOR){

	switch(tolower(COLOR)){
		case white:

		case black:

		case gray:

		default:
			std::cout << "Invalid basicButton parameter.\n";
			glfwTerminate();
			return -1;
	}

	glui->add_button(TEXT, )


}