#include "../include/program.h"

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Solutions");
  
  
  //glutDisplayFunc(ques1);
  //glutDisplayFunc(ques2);
  glutDisplayFunc(ques4);
  
  
  glutKeyboardFunc(keyboard);
  glutMainLoop();
}

