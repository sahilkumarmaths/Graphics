#include<math.h>
#include<vector>
#include "../include/shapeLib.h"

void tree();
void snowman();
void constructHouse(float moveX, float moveY, float moveZ);
vector<Point> vertexListCenterCube();
void tree_helper(float r,float x, float y, float z, float h, int rings,int sectors,float distance);
void constructRoad(float width,float height,float length,Direction widthDir, Direction lengthDir);

using namespace std;
// Global Variables
double rotate_y          = 0.0;
double rotate_x          = 0.0;
double rotate_z          = 0.0;
double zoom              = 1.0;

// Constants
const double rotate_step = 5.0;
const double zoom_step   = 0.01;
const double cube_size   = 1.0;
const double center_x    = 0.0;
const double center_y    = 0.0;
const double center_z    = 0.0;

void drawScene()
{

	init();
	
/***********Question 3**************/

	snowman();  
    tree();
    constructHouse(0,0,0);

	Direction widthDir = X, lengthDir = Z;
	constructRoad(1,0.1,4,widthDir, lengthDir);
/***********Question 5**************/
 
	/*Objects obj;
    obj.village();
   */
  
    glFlush();	
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
    else if (key == 'z')
        rotate_z += rotate_step;
    else if (key == 'x')
        rotate_z -= rotate_step;
    else if (key == 'q')
        zoom *= (1.0 + zoom_step);
    else if (key == 'e')
        zoom *= (1.0 - zoom_step);

    glutPostRedisplay();
}

void init(){
  //Initialization
  // Color of the background
  glClearColor(0.1, 0.39, 0.88, 1.0);
  // Projection Mode
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-2, 2, -1.5, 1.5, 1, 40);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, -3);
  //Rotating
  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);
  glScaled(zoom, zoom, zoom);
  glClear(GL_COLOR_BUFFER_BIT);
}	

void renderSphere(Sphere sphere,float r,float g,float b){
	sphere.calculateTransform();	
	glColor3f(r,g,b);
	sphere.fillDraw();
	glColor3f(r,g,b);
	sphere.draw();
}

Cube getCube(float side){
	vector<Point> cubeList;
	Point a;
	float size = 0.5 * side;
	a.x= 0,		a.y = 0,    	a.z = 0,	cubeList.push_back(a);
	a.x= size,	a.y = 0,    	a.z = 0,	cubeList.push_back(a);
	a.x= size,	a.y = 0,    	a.z = size,	cubeList.push_back(a);
	a.x= 0,		a.y = 0,    	a.z = size,	cubeList.push_back(a);

	a.x= 0,		a.y = size,	a.z = 0,	cubeList.push_back(a);
	a.x= size,	a.y = size,	a.z = 0,	cubeList.push_back(a);
	a.x= size,	a.y = size,	a.z = size,	cubeList.push_back(a);
	a.x= 0,		a.y = size,	a.z = size,	cubeList.push_back(a);

	Cube cube(cubeList);
	return cube;
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Solutions");

  glutDisplayFunc(drawScene);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
}

/*************************Question 1**********************************************/
/*
 * Function:	 Draws the required Snowman Object
 * Parameters:   None
 */
void snowman()
{
  float x=2,y=0,z=0;
  float r = 0.30;
  int rings = 50;
  int sectors = 50; 	
  float r1=1,g1=1.0,b1=1,r2=1.0,g2=1.0,b2=1.0;
 
  Sphere obj1(1.5*r,rings,sectors),obj2(2*r,rings,sectors),obj3(2.5*r,rings,sectors) ,obj4(0.2*r,rings,sectors),obj5(0.2*r,rings,sectors),obj6(0.2*r,rings,sectors);
  Sphere obj7(0.1*r,rings,sectors),obj8(0.1*r,rings,sectors),obj9(0.1*r,rings,sectors),obj10(0.1*r,rings,sectors);
  

  //Sphere 1 - top Head
  obj1.translate(0+x,4.5*r+y,0+z);
  obj1.calculateTransform();	
  glColor3f(r1, g1,b1);
  obj1.fillDraw();
  glColor3f(r2, g2, b2);
  obj1.draw();
  
  //Sphere 2 - Stomach
  obj2.translate(x,y,z);
  obj2.translate(0,2.2*r,0);
  obj2.calculateTransform();	
  glColor3f(r1, g1,b1);
  obj2.fillDraw();
  glColor3f(r2, g2, b2);
  obj2.draw();
  
  //Sphere 3 Lower
  obj3.translate(0+x,y-0.2*r,0+z);
  obj3.calculateTransform();	
  glColor3f(r1, g1,b1);
  obj3.fillDraw();
  glColor3f(r2, g2, b2);
  obj3.draw();
  
  //Sphere 4 Right Eye
  obj4.translate(0.5*r+x,4.5*r+0.75*r*sin(PI*45/180.0) + y,1.5*r*cos(PI*45/180.0) +z);
  obj4.calculateTransform();	
  glColor3f(0, 0,0);
  obj4.fillDraw();
  glColor3f(0,0, 0);
  obj4.draw();
  
  //Sphere 5 Left Eye
  obj5.translate(-1*0.5*r+x,y+4.5*r+0.75*r*sin(PI*45/180.0),z+1.5*r*cos(PI*45/180.0));
  obj5.calculateTransform();	
  glColor3f(0, 0,0);
  obj5.fillDraw();
  glColor3f(0,0, 0);
  obj5.draw();
  
  //Sphere 6 Nose
  obj6.translate(0+x,y+4.0*r+0.75*r*sin(PI*45/180.0),z+1.5*r*cos(PI*45/180.0));
  obj6.calculateTransform();	
  glColor3f(1, 0,0);
  obj6.fillDraw();
  glColor3f(1,0, 0);
  obj6.draw();
  
   //Sphere 7-Mouth
  obj7.translate(0.5*r+x,y+3.5*r+0.75*r*sin(PI*45/180.0),z+1.5*r*cos(PI*45/180.0));
  obj7.calculateTransform();	
  glColor3f(0,0,0);
  obj7.fillDraw();
  glColor3f(0,0, 0);
  obj7.draw();
  
   //Sphere 8-Mouth
  obj8.translate(-1*0.5*r+x,y+3.5*r+0.75*r*sin(PI*45/180.0),z+1.5*r*cos(PI*45/180.0));
  obj8.calculateTransform();	
  glColor3f(0, 0,0);
  obj8.fillDraw();
  glColor3f(0,0, 0);
  obj8.draw();
  
   //Sphere 9-Mouth
  obj9.translate(0.25*r+x,y+3.3*r+0.75*r*sin(PI*45/180.0),z+1.5*r*cos(PI*45/180.0));
  obj9.calculateTransform();	
  glColor3f(0, 0,0);
  obj9.fillDraw();
  glColor3f(0,0, 0);
  obj9.draw();
  
   //Sphere 10-Mouth
  obj10.translate(-1*0.25*r+x,y+3.3*r+0.75*r*sin(PI*45/180.0),z+1.5*r*cos(PI*45/180.0));
  obj10.calculateTransform();	
  glColor3f(0, 0,0);
  obj10.fillDraw();
  glColor3f(0,0, 0);
  obj10.draw();
}

/*
 * Function:	 Draws the required Tree Object
 * Parameters:   None
 */
void tree()
{
	float r=0.25,x=-3, y=0, z=0, h=0;
	int rings=20,sectors=20;

	//first level
	tree_helper(2*r,x, y, z, h+0.5,rings, sectors,r);

	//second level
	tree_helper(1*r,x, y, z, h+0.5+2*r, rings, sectors,0.75*r);

	//third level
	tree_helper(0.5*r,x, y, z, h+0.5+2*r+1*r, rings, sectors,0.75*0.5*r);

	//top level
	Sphere obj1(1.0*r,rings,sectors);
	obj1.translate(x,y+h+0.5+2*r+1*r+0.5*r+0.5*r,z);
	obj1.calculateTransform();	
	obj1.fillDraw();
	obj1.draw();
	
	Cube cube1 = getCube(1);
	cube1.scale(1,4,1);
	cube1.translate(-0.25+x,(-1)*2+y,-0.25+z);
	cube1.draw(0.35,0.16,0.14);
}

/*
 * Function:	 Helps in drawing the levels of the cube
 * Parameters:
 * 		r : 	 Radius of the sphere
 * 		x : 	 The final world X coordinates
 *  	y :      The final world Y coordinates
 *		z :		 The final world Z coordinates
 *		h :		 Height of the level of the tree
 */
void tree_helper(float r,float x, float y, float z, float h, int rings,int sectors,float d)
{
	float cx = x;
	float cy = y+h;
	float cz = z;
	glColor3f(0, 1, 0);
	
	// Sphere Object
	Sphere obj(r,rings,sectors);
	obj.translate(cx,cy,cz);
	renderSphere(obj,0,1,0);
	
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,d);
	renderSphere(obj,0,1,0);
	obj.translate(d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,-1*d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,-1*d);
	renderSphere(obj,0,1,0);
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);

	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,d);
	renderSphere(obj,0,1,0);
	obj.translate(d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,-1*d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,-1*d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,-1*d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,-1*d);
	renderSphere(obj,0,1,0);
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);

	obj.translate(-1*d,0.0,0.0);
	obj.translate(0.0,0.0,d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,d);
	renderSphere(obj,0,1,0);

	obj.translate(0.0,0.0,d);
	obj.translate(0.0,0.0,d);
	obj.translate(d,0.0,0.0);
	obj.translate(d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(d,0.0,0.0);
	renderSphere(obj,0,1,0);

	obj.translate(d,0.0,0.0);
	obj.translate(d,0.0,0.0);
	obj.translate(0.0,0.0,-1*d);
	obj.translate(0.0,0.0,-1*d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,-1*d);
	renderSphere(obj,0,1,0);
	obj.translate(0.0,0.0,-1*d);
	renderSphere(obj,0,1,0);

	obj.translate(0.0,0.0,-1*d);
	obj.translate(0.0,0.0,-1*d);
	obj.translate(-1*d,0.0,0.0);
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);
	obj.translate(-1*d,0.0,0.0);
	renderSphere(obj,0,1,0);
}


void constructHouse(float moveObjectX = 0, float moveObjectY = 0, float moveObjectZ = 0) {
	vector<Point> houseBaseList = vertexListCenterCube();
	Cube houseBase(houseBaseList);
	houseBase.scale(1.5, 1.5, 1.5);
	houseBase.translate(0 + moveObjectX, 0 + moveObjectY, 0 + moveObjectZ);
	houseBase.draw(1.0, 0.50, 1.0);

	vector<Point> roofList = vertexListCenterCube();
	
	
	Cube roof1(roofList);
	roof1.scale(1, 1.5, 1.5);
	Point axisVector;
	axisVector.x = 0;
	axisVector.y = 0;
	axisVector.z = 1;
	roof1.rotate(41,axisVector);
	roof1.translate(moveObjectX, 0.75+moveObjectY, moveObjectZ);
	roof1.draw(1, 0, 0);

	vector<Point> doorList = vertexListCenterCube();
	Cube door(doorList);
	door.scale(0.4, 0.6, 1.7);
	axisVector.x = 1;
	axisVector.y = 0;
	axisVector.z = 0;
	door.rotate(180, axisVector);
	door.translate(moveObjectX, -0.45 + moveObjectY, moveObjectZ);
	door.draw(1, 1, 1);
}

vector<Point> vertexListCenterCube() {
	vector<Point> cubeAtCenter;
	Point a;
	float size = 1;
	a.x= -(size/2), a.y = -(size/2),	a.z = -(size/2),cubeAtCenter.push_back(a);
	a.x= (size/2),	a.y = -(size/2),	a.z = -(size/2),cubeAtCenter.push_back(a);
	a.x= (size/2),	a.y = -(size/2),	a.z = (size/2),	cubeAtCenter.push_back(a);
	a.x= -(size/2),	a.y = -(size/2),	a.z = (size/2),	cubeAtCenter.push_back(a);

	a.x= -(size/2),	a.y = (size/2),	a.z = -(size/2),cubeAtCenter.push_back(a);
	a.x= (size/2),	a.y = (size/2),	a.z = -(size/2),cubeAtCenter.push_back(a);
	a.x= (size/2),	a.y = (size/2),	a.z = (size/2),	cubeAtCenter.push_back(a);
	a.x= -(size/2),	a.y = (size/2),	a.z = (size/2),	cubeAtCenter.push_back(a);
	
	return cubeAtCenter;
}

void constructRoad(float width,float height,float length,Direction widthDir, Direction lengthDir){
	float angle = atan(width/(length*2));
	Cube cube1 = getCube(1);
	if(widthDir == 0 && lengthDir == 1)
		cube1.scale(width,length,height);
	else if(widthDir == 0 && lengthDir == 2)
		cube1.scale(width,height,length);
	else if(widthDir == 1 && lengthDir == 2)
		cube1.scale(height,width,length);
	else if(widthDir == 1 && lengthDir == 0)
		cube1.scale(length,width,height);
	else if(widthDir == 2 && lengthDir == 0)
		cube1.scale(length,height,width);
	else if(widthDir == 2 && lengthDir == 1)
		cube1.scale(height,length,width);
	Cube cube2 = cube1;
	
	Plane fixedPlane;
	if(widthDir == X)
		fixedPlane = YZ;
	else if(widthDir == Y)
		fixedPlane = XZ;
	else if(widthDir == Z)
		fixedPlane = XY;

	cube1.shear(angle,fixedPlane,lengthDir);
	cube2.shear((-1)*angle,fixedPlane,lengthDir);
	cube1.translate(-0.2,-1,0);
	cube2.translate(-0.2,-1,0);
	float r = 0.7;
	float g =0.3;
	float b =0.3;
	cube1.draw(r,g,b);	
	cube2.draw(r,g,b); 
}
