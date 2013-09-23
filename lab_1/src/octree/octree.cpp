#include <GL/glut.h>
#include "../../include/octree_fn.h"
using namespace octree;

// Defines
#define APP_NAME "OctTree"
#define WINDOW_W 600
#define WINDOW_H 600

// Global Variables
double rotate_y          = 0.0;
double rotate_x          = 0.0;
double zoom              = 1.0;

// Constants
const double rotate_step = 5.0;
const double zoom_step   = 0.01;
const double cube_size   = 1.0;
const double center_x    = 0.0;
const double center_y    = 0.0;
const double center_z    = 0.0;

// Example octree for a cube grid: "2", "1" and "0" are the symbols for dirty,
// filled and empty nodes, respectively
//tertahedron
const string tree1      =
	"2"
		"2"
			"2"
				"10001110"
			"0"
			"0"
			"0"
			"1"
			"2"
				"10001110"
			"2"
				"10001110"
			"0"
		"0"
		"0"
		"0"
		"1"
		"2"
			"2"
				"10001110"
			"0"
			"0"
			"0"
			"1"
			"2"
				"10001110"
			"2"
				"10001110"
			"0"
		"2"
			"2"
				"10001110"
			"0"
			"0"
			"0"
			"1"
			"2"
				"10001110"
			"2"
				"10001110"
			"0"
		"0"
	"0"
	"0"
	"0"
	"1"
	"2"
		"2"
			"2"
				"10001110"
			"0"
			"0"
			"0"
			"1"
			"2"
				"10001110"
			"2"
				"10001110"
			"0"
		"0"
		"0"
		"0"
		"1"
		"2"
			"2"
				"10001110"
			"0"
			"0"
			"0"
			"1"
			"2"
				"10001110"
			"2"
				"10001110"
			"0"
		"2"
			"2"
				"10001110"
			"0"
			"0"
			"0"
			"1"
			"2"
				"10001110"
			"2"
				"10001110"
			"0"
		"0"
	"2"
		"2"
			"2"
				"10001110"
			"0"
			"0"
			"0"
			"1"
			"2"
				"10001110"
			"2"
				"10001110"
			"0"
		"0"
		"0"
		"0"
		"1"
		"2"
			"2"
				"10001110"
			"0"
			"0"
			"0"
			"1"
			"2"
				"10001110"
			"2"
				"10001110"
			"0"
		"2"
			"2"
				"10001110"
			"0"
			"0"
			"0"
			"1"
			"2"
				"10001110"
			"2"
				"10001110"
			"0"
		"0"
	"0"
;

//L shape
const string tree2      =
"2"
	"1"
	"1"
	"1"
	"1"
	"0"
	"2"
		"01010101"
	"0"
	"2"	
		"01010101"
"2"
	"2"
	"1"
	"1"
	"1"
	"1"
	"2"
		"10101010"
	"0"
	"2"
"2"
	"1"
	"1"
	"1"
	"1"
	"0"
	"2"
		"01010101"
	"0"
	"2"	
		"01010101"
"2"
	"2"
	"1"
	"1"
	"1"
	"1"
	"2"
		"10101010"
	"0"
	"2"
"2"
	"0"
	"2"
		"01010101"
	"0"
	"2"
		"01010101"
	"0"
	"2"
		"01010101"
	"0"
	"2"
		"01010101"
"2"
	"2"
	"10101010"
	"0"
	"2"
		"10101010"
	"0"
	"2"
		"10101010"
	"0"
	"2"
		"10101010"
	"0"
"2"
	"0"
	"2"
		"01010101"
	"0"
	"2"
		"01010101"
	"0"
	"2"
		"01010101"
	"0"
	"2"
		"01010101"
"2"
	"2"
	"10101010"
	"0"
	"2"
		"10101010"
	"0"
	"2"
		"10101010"
	"0"
	"2"
		"10101010"
	"0";
// Prototypes
void reshape(int width, int height);
void display();
void keyboard(unsigned char key, int x, int y);

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height);
    glOrtho(0.0, width, 0.0, height, 0, 50000);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glScaled(zoom, zoom, zoom);

    drawOctree(tree1, center_x, center_y, center_z, cube_size);
    drawOctree(tree2, center_x + cube_size, center_y + cube_size, center_z + cube_size, cube_size);
    

    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'd')
        rotate_y += rotate_step;
    else if (key == 'a')
        rotate_y -= rotate_step;
    else if (key == 'w')
        rotate_x += rotate_step;
    else if (key == 's')
        rotate_x -= rotate_step;
    else if (key == 'q')
        zoom *= (1.0 + zoom_step);
    else if (key == 'e')
        zoom *= (1.0 - zoom_step);

    glutPostRedisplay();
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_W*2, WINDOW_H*2);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WINDOW_W) / 2,
                           (glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_H) / 2);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow(APP_NAME);

    glEnable(GL_DEPTH_TEST);

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}





