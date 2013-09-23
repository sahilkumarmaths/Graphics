#include "../include/shapeLib.h"

/*
 * For drawing the Tree one Level
 */
void Objects::oneLevel()
{
	glColor3d(0.0,1.0,0.0);
	drawSphere();
	translate(-0.5,0.0,0.0);
	drawSphere();
	translate(0.0,0.0,0.5);
	drawSphere();
	translate(0.5,0.0,0.0);
	drawSphere();
	translate(0.5,0.0,0.0);
	drawSphere();
	translate(0.0,0.0,-0.5);
	drawSphere();
	translate(0.0,0.0,-0.5);
	drawSphere();
	translate(-0.5,0.0,0.0);
	drawSphere();
	translate(-0.5,0.0,0.0);
	drawSphere();

	translate(-0.5,0.0,0.0);
	drawSphere();
	translate(0.0,0.0,0.5);
	drawSphere();
	translate(0.0,0.0,0.5);
	drawSphere();
	translate(0.0,0.0,0.5);
	drawSphere();
	translate(0.5,0.0,0.0);
	drawSphere();
	translate(0.5,0.0,0.0);
	drawSphere();
	translate(0.5,0.0,0.0);
	drawSphere();
	translate(0.5,0.0,0.0);
	drawSphere();
	translate(0.0,0.0,-0.5);
	drawSphere();
	translate(0.0,0.0,-0.5);
	drawSphere();
	translate(0.0,0.0,-0.5);
	drawSphere();
	translate(0.0,0.0,-0.5);
	drawSphere();
	translate(-0.5,0.0,0.0);
	drawSphere();
	translate(-0.5,0.0,0.0);
	drawSphere();
	translate(-0.5,0.0,0.0);
	drawSphere();
	translate(-0.5,0.0,0.0);
	drawSphere();

	translate(-0.5,0.0,0.0);
	translate(0.0,0.0,0.5);
	drawSphere();
	translate(0.0,0.0,0.5);
	drawSphere();
	translate(0.0,0.0,0.5);
	drawSphere();

	translate(0.0,0.0,0.5);
	translate(0.0,0.0,0.5);
	translate(0.5,0.0,0.0);
	translate(0.5,0.0,0.0);
	drawSphere();
	translate(0.5,0.0,0.0);
	drawSphere();
	translate(0.5,0.0,0.0);
	drawSphere();

	translate(0.5,0.0,0.0);
	translate(0.5,0.0,0.0);
	translate(0.0,0.0,-0.5);
	translate(0.0,0.0,-0.5);
	drawSphere();
	translate(0.0,0.0,-0.5);
	drawSphere();
	translate(0.0,0.0,-0.5);
	drawSphere();


	translate(0.0,0.0,-0.5);
	translate(0.0,0.0,-0.5);
	translate(-0.5,0.0,0.0);
	translate(-0.5,0.0,0.0);
	drawSphere();
	translate(-0.5,0.0,0.0);
	drawSphere();
	translate(-0.5,0.0,0.0);
	drawSphere();
}

void Objects::trunk( int blockCount )
{
	glColor3f(0.35,0.16,0.14);
	for( int i = 0; i<blockCount; i++ ){
		translate(0.0,0.5,0.0);
		drawCube();
	}
}

void Objects::tree()
{

	    glPushMatrix();

	 // creating trunk of tree
		scale(0.25,0.25,0.25);
		translate(0.0,-5.5,0.0);
		trunk( 8 );

	    //now the leaves
		//first level
		translate(0.0,0.5,0.0);
		glPushMatrix();
		scale(2.0,2.0,2.0);
		oneLevel();
		glPopMatrix();

		
		//second level
		translate(0.0,1.0,0.0);
		glPushMatrix();
		scale(1.5,1.5,1.5);
		oneLevel();
		glPopMatrix();

		//3rd level
		translate(0.0,0.75,0.0);
		glPushMatrix();
		scale(1.0,1.0,1.0);
		oneLevel();
		glPopMatrix();

		//4th level
		translate(0.0,0.5,0.0);
		glPushMatrix();
		scale(0.75,0.75,0.75);
		oneLevel();
		glPopMatrix();

		//5th level
		translate(0.0,0.5,0.0);
		glPushMatrix();
		scale(0.5,0.5,0.5);
		oneLevel();
		glPopMatrix();

		glPushMatrix();
		scale(1.5,1.5,1.5);
		drawSphere();
		glPopMatrix();

	glPopMatrix();

	
}

void Objects::road()
{
	glColor3f(0.7,0.3,0.3);
	glPushMatrix();

		translate(-0.05,-.2,-.4);
		
		GLdouble shearAngle = 0.5;
		GLdouble pathLen = 1.5;
		glPushMatrix();
		scale(0.2,0.02,pathLen);
		shear(shearAngle);
		drawCube();
		glPopMatrix();

		translate(0.25,0,0);
		glPushMatrix();
		scale(0.2,0.02,pathLen);
		shear(-shearAngle);
		drawCube();
		glPopMatrix();

	glPopMatrix();
}

void Objects::house()
{


	glColor3f(1,0.5,1);

	glPushMatrix();
	glScaled(0.2,0.2,0.2);


	glPushMatrix();
	glutSolidCube(1.5);
	glPopMatrix();

    glColor3f(1,0,0);
	glPushMatrix();
	glRotatef(45,0,0,1);
	glTranslated(0.75, 0.75, 0);
	glutSolidCube(1.5); //draw the cube
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(0.4f, 0.6, 1.5);
	glTranslated(0, -0.45,0);
	glutSolidCube(1.5); //draw the cube
	glPopMatrix();

	glPopMatrix();
}

void Objects::character()
{
	
	glPushMatrix();
		glColor3f(1, 1,1);
		glPushMatrix();
			scale(1,1,1);
			drawSphere();
		glPopMatrix();	
		
		translate(0,0.5,0);
		glPushMatrix();
			scale(0.75,0.75,0.75);
			drawSphere();
		glPopMatrix();
		
		translate(0,0.25,0);
		glPushMatrix();
			scale(0.60,0.60,0.60);
			drawSphere();
		glPopMatrix();
		
		glColor3f(0, 0,0);
		translate(.10,0.10,.2);
		glPushMatrix();
			scale(0.10,0.10,0.10);
			drawSphere();
		glPopMatrix();
		

		translate(-2*.10,0,0);
		glPushMatrix();
			scale(0.10,0.10,0.10);
			drawSphere();
		glPopMatrix();
		
		translate(.10,-.10,0);
		glPushMatrix();
			scale(0.10,0.10,0.10);
			drawSphere();
		glPopMatrix();
		

	glPopMatrix();

}

void Objects::village()
{
	glPushMatrix();
	rotate(-25,-40,0);
	translate(0.4,0.0,0.3);
	glPushMatrix();

		translate(-0.7,0.0,0.0);
		glPushMatrix();
		translate(0.0,0.15,0.0);
		scale(0.4,0.4,0.4);
		tree();
		glPopMatrix();

		translate(0.7,0.0,0.0);
		glPushMatrix();
		scale(0.8,0.8,0.8);
		house();
		glPopMatrix();
	
		glPushMatrix();
		translate(-0.05,-0.4,-0.6);
		scale(0.5,0.8,0.5);
		road();
		glPopMatrix();
	
		translate(0.15,-0.25,-0.5);
		glPushMatrix();
		scale(0.2,0.2,0.2);
		character();
		glPopMatrix();
	
	glPopMatrix();
	glPopMatrix();
}

void Objects::drawCube( double center_x, double center_y, double center_z, double size )
{
	double half_size = size / 2.0;
	double front     = center_z - half_size;
	double back      = center_z + half_size;
	double left      = center_x - half_size;
	double right     = center_x + half_size;
	double bottom    = center_y - half_size;
	double top       = center_y + half_size;

	glPushMatrix();

	// red side - front
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(right, bottom, front);
	glVertex3f(right, top,    front);
	glVertex3f(left,  top,    front);
	glVertex3f(left,  bottom, front);
	glEnd();

	// green side - back
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 1.0, 0.0);
	glVertex3f(right, bottom, back);
	glVertex3f(right, top,    back);
	glVertex3f(left,  top,    back);
	glVertex3f(left,  bottom, back);
	glEnd();

	// blue side - right
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 1.0);
	glVertex3f(right, bottom, front);
	glVertex3f(right, top,    front);
	glVertex3f(right, top,    back);
	glVertex3f(right, bottom, back);
	glEnd();

	// yellow side - left
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 0.0);
	glVertex3f(left, bottom, back);
	glVertex3f(left, top,    back);
	glVertex3f(left, top,    front);
	glVertex3f(left, bottom, front);
	glEnd();

	// magneta side - top
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 1.0);
	glVertex3f(right, top, back);
	glVertex3f(right, top, front);
	glVertex3f(left,  top, front);
	glVertex3f(left,  top, back);
	glEnd();

	// cyan side - bottom
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 1.0, 1.0);
	glVertex3f(right, bottom, front);
	glVertex3f(right, bottom, back);
	glVertex3f(left,  bottom, back);
	glVertex3f(left,  bottom, front);
	glEnd();

	glPopMatrix();
}

void Objects::drawSphere( double center_x, double center_y, double center_z, double radius )
{
	glPushMatrix();
	//glColor3d(0.0,1.0,0.0);
	glTranslated( center_x, center_y, center_z );
	glutSolidSphere(radius,50,50);
	glPopMatrix();
}

/***********************************************************************************************/
void Objects::translate( double tx, double ty, double tz )
{
	float Mtranslate[] = { 
		1, 0, 0, 0, 
		0, 1, 0, 0,
		0, 0, 1, 0,
		tx, ty, tz, 1 };
	glMultMatrixf(Mtranslate);
}

void Objects::rotate( double rx, double ry, double rz )
{
	rx = rx * PI / 180.0;
	ry = ry * PI / 180.0;
	rz = rz * PI / 180.0;

	float Mtranslate_x[] = { 
		1, 0, 0, 0, 
		0, cos(rx), sin(rx), 0,
		0, -sin(rx), cos(rx), 0,
		0, 0, 0, 1 };

	float Mtranslate_y[] = { 
		cos(ry), 0, -sin(ry), 0, 
		0, 1, 0, 0,
		sin(ry), 0, cos(ry), 0,
		0, 0, 0, 1 };

	float Mtranslate_z[] = { 
		cos(rz), sin(rz), 0, 0, 
		-sin(rz), cos(rz), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1 };
	glMultMatrixf(Mtranslate_x);
	glMultMatrixf(Mtranslate_y);
	glMultMatrixf(Mtranslate_z);
}

void Objects::scale( double sx, double sy, double sz )
{
	float Mscale[] = { 
		sx, 0, 0, 0, 
		0, sy, 0, 0,
		0, 0, sz, 0,
		0, 0, 0, 1 };
	glMultMatrixf(Mscale);
}

void Objects::shear( double zx, double zy, double yx, double yz, double xy, double xz )
{
	float Mtranslate[] = { 
		1, xy, xz, 0, 
		yx, 1, yz, 0,
		zx, zy, 1, 0,
		0, 0, 0, 1 };
	glMultMatrixf(Mtranslate);
}
