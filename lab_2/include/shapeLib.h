#include<iostream>
#include<vector>
#include<math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define PI 3.14159265

using namespace std;

struct Point{
	float x,y,z;
};
enum Direction {
	X, Y, Z
};
enum Plane {
	YZ = 0,
	XZ = 1,
	XY = 2
};

class Cube{
	private:
		vector< struct Point > vlist;
		float transformMatrix[4][4];

	public:

		Cube(vector<struct Point> ivlist);
		void translate(float xDist, float yDist, float zDist);
		void rotate(float angle, Point axisVector);
		void shear(float angle, Plane fixedPlane, Direction forceDir);		
		void draw(float r, float g, float b);
		void scale(float xFactor, float yFactor, float zFactor);
		void transform(float b[4][4]);
		void calculateTransform();
};

class Sphere{
	vector<vector<Point> > vertices;
	float radius;
	float transformMatrix[4][4];

	public:
		Sphere(float radius, int hRings, int sectors);
		//x,y,z in translate are translate distances along x,y,z axes
		void translate(float x,float y, float z);
		/*
		*	0 means xy plane fixed,force along x,
		* 	1 means xy plane fixed,force along y
		*	2 means yz plane fixed, force along y,
		*	3 means yz plane fixed, force along z,
		*	4 means yz plane fixed, force along x,
		*	5 means yz plane fixed, force along z
		*/
		void shear(float angle, Plane fixedPlane, Direction forceDir);
		void rotate(float angle, Point axisVector);
		void calculateTransform();
		void draw();
		void fillDraw();
		void scale(float xFactor, float yFactor, float zFactor);
		void transform(float a[4][4]);
};

class Objects
{

	public:
		void tree();
		void house();
		void road();
		void character();
		void village();
		
		void trunk( int blockCount );
		void oneLevel();
		
		void drawCube( double center_x=0.0, double center_y=0.0, double center_z=0.0, double size=1 );
		void drawSphere( double center_x=0.0, double center_y=0.0, double center_z=0.0, double radius=0.5 );
		
		void translate( double tx, double ty, double tz );
		void rotate( double x=0.0, double y=0.0, double z=0.0 );
		void scale( double x=0.0, double y=0.0, double z=0.0 );
		void shear( double zx=0.0, double zy=0.0, double yx=0.0, double yz=0.0, double xy=0.0, double xz=0.0 );
};

//void ques1();
void init();
void keyboard(unsigned char key, int x, int y);
void renderSphere(Sphere sphere,float r,float g,float b);
Cube getCube(float side);
