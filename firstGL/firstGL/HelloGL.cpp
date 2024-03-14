#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutCreateWindow("OPENPL WOOOOOOOOOOOOOO");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
	glutInitWindowSize(800,800);
}

void HelloGL::Display() 
{
	
}

HelloGL::~HelloGL(void)
{

}




