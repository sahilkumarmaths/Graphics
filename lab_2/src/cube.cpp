#include<math.h>
#include<vector>
#include<iostream>
#include "../include/shapeLib.h"
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define PI 3.14159265

using namespace std;

Cube::Cube(vector<struct Point> ivlist) {
	vlist = ivlist;
	for(int i = 0; i<4;i++){
		for(int j = 0; j<4;j++){
			if(i==j)
				transformMatrix[i][j] = 1;
			else
				transformMatrix[i][j] = 0;
		}
	}
}

//x,y,z in translate are translate distances along x,y,z axes
void Cube::translate(float xDist, float yDist, float zDist){
	float translateMatrix[4][4];
	for(int i=0; i<4;i++){
		for (int j=0;j<4;j++){
			if(i == j)
				translateMatrix[i][j] = 1;
			else
				translateMatrix[i][j] =0;
		}
	}
	translateMatrix[0][3] = xDist;
	translateMatrix[1][3] = yDist;
	translateMatrix[2][3] = zDist;
	transform(translateMatrix);
}

void Cube::rotate(float angle, Point axisVector) {
	float x = axisVector.x;
	float y = axisVector.y;
	float z = axisVector.z;

	float angle_radian = angle*0.01745; 
	float cosine = cos(angle_radian); 
	float sine = sin(angle_radian);
	float transformation_matrix[4][4] = 
	{
		{x*x*(1-cosine)+cosine,y*x*(1-cosine)+z*sine,z*x*(1-cosine)-y*sine,0},
		{x*y*(1-cosine)-z*sine,y*y*(1-cosine)+cosine,z*y*(1-cosine)+x*sine,0},
		{x*z*(1-cosine)+y*sine,y*z*(1-cosine)-x*sine,z*z*(1-cosine)+cosine,0},
	 	{0,0,0,1}
	};	
	transform(transformation_matrix);
}

void Cube::shear(float angle, Plane fixedPlane, Direction forceDir){
	float translateMatrix[4][4];
	for(int i=0; i<4;i++){
		for (int j=0;j<4;j++){
			if(i == j)
				translateMatrix[i][j] = 1;
			else
				translateMatrix[i][j] =0;
		}
	}

	translateMatrix[fixedPlane][forceDir] = tan(angle);
	transform(translateMatrix);
}

void Cube::draw(float r, float g, float b) {
	calculateTransform();
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	
	glBegin(GL_QUADS);
	glVertex3f(vlist[0].x,vlist[0].y,vlist[0].z);
	glVertex3f(vlist[1].x,vlist[1].y,vlist[1].z);
	glVertex3f(vlist[2].x,vlist[2].y,vlist[2].z);
	glVertex3f(vlist[3].x,vlist[3].y,vlist[3].z);
	glEnd();
				
	glColor3f(r,g,b); 
	glBegin(GL_QUADS);
	glVertex3f(vlist[4].x,vlist[4].y,vlist[4].z);
	glVertex3f(vlist[5].x,vlist[5].y,vlist[5].z);
	glVertex3f(vlist[6].x,vlist[6].y,vlist[6].z);
	glVertex3f(vlist[7].x,vlist[7].y,vlist[7].z);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(vlist[0].x,vlist[0].y,vlist[0].z);
	glVertex3f(vlist[1].x,vlist[1].y,vlist[1].z);
	glVertex3f(vlist[5].x,vlist[5].y,vlist[5].z);
	glVertex3f(vlist[4].x,vlist[4].y,vlist[4].z);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(vlist[3].x,vlist[3].y,vlist[3].z);
	glVertex3f(vlist[2].x,vlist[2].y,vlist[2].z);
	glVertex3f(vlist[6].x,vlist[6].y,vlist[6].z);
	glVertex3f(vlist[7].x,vlist[7].y,vlist[7].z);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(vlist[0].x,vlist[0].y,vlist[0].z);
	glVertex3f(vlist[3].x,vlist[3].y,vlist[3].z);
	glVertex3f(vlist[7].x,vlist[7].y,vlist[7].z);
	glVertex3f(vlist[4].x,vlist[4].y,vlist[4].z);
	glEnd();
				  
	glBegin(GL_QUADS);
	glVertex3f(vlist[1].x,vlist[1].y,vlist[1].z);
	glVertex3f(vlist[2].x,vlist[2].y,vlist[2].z);
	glVertex3f(vlist[6].x,vlist[6].y,vlist[6].z);
	glVertex3f(vlist[5].x,vlist[5].y,vlist[5].z);
	glEnd();

	glPopMatrix();
}

void Cube::scale(float xFactor, float yFactor, float zFactor){
	float translateMatrix[4][4];
	for(int i=0; i<4;i++){
		for (int j=0;j<4;j++){
			if(i == j)
				translateMatrix[i][j] = 1;
			else
				translateMatrix[i][j] =0;
		}
	}
	translateMatrix[0][0] = xFactor;
	translateMatrix[1][1] = yFactor;
	translateMatrix[2][2] = zFactor;
	transform(translateMatrix);
}

/*
 * Multiplies transformMatrix = B * transformMatrix
 */
void Cube::transform(float b[4][4])
{
	float temp[4][4];
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			temp[i][j] = 0;
			for(int k=0; k<4; k++)
			{
				temp[i][j] += b[i][k]*transformMatrix[k][j];
			}
		}
	}

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			transformMatrix[i][j] = temp[i][j];
		}
	}
}

void Cube::calculateTransform()
{
	//Final Points;
	float multiplier;
	for(int i=0; i< (int)vlist.size(); i++)
	{
			multiplier		 =   transformMatrix[3][0]*vlist[i].x + transformMatrix[3][1]*vlist[i].y + transformMatrix[3][2]*vlist[i].z + transformMatrix[3][3]*1; 
			vlist[i].x =  (transformMatrix[0][0]*vlist[i].x + transformMatrix[0][1]*vlist[i].y + transformMatrix[0][2]*vlist[i].z +transformMatrix[0][3]*1)/multiplier; 
			vlist[i].y =  (transformMatrix[1][0]*vlist[i].x + transformMatrix[1][1]*vlist[i].y + transformMatrix[1][2]*vlist[i].z +transformMatrix[1][3]*1)/multiplier; 
			vlist[i].z =  (transformMatrix[2][0]*vlist[i].x + transformMatrix[2][1]*vlist[i].y + transformMatrix[2][2]*vlist[i].z +transformMatrix[2][3]*1)/multiplier;
	}
}
