#include<math.h>
#include<vector>
#include<iostream>
#include "../include/shapeLib.h"
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

Sphere::Sphere(float r, int rings, int sectors){
	radius = r;
	vector< vector< Point> > ringsOfSphere;
	for(int i = 0; i < rings; i++){
		vector<Point> pointsOfRing;

		float ringHeight, ringRadius;
		ringHeight = (2.0*radius/(rings-1))*i - radius;
		ringRadius = sqrt(radius*radius - ringHeight*ringHeight);

		for(int j = 0; j< sectors; j++){
			Point vertex;
			float angle = (2*PI/sectors)*j;
			vertex.x = cos(angle) * ringRadius;
			vertex.y = sin(angle) * ringRadius;
			vertex.z = ringHeight;
			pointsOfRing.push_back(vertex);
		}
		ringsOfSphere.push_back(pointsOfRing);
	}
	vertices = ringsOfSphere;
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
void Sphere::translate(float xDist, float yDist, float zDist){
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

void Sphere::shear(float angle, Plane fixedPlane, Direction forceDir){
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

void Sphere::rotate(float angle, Point axisVector) {
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

void Sphere::scale(float xFactor, float yFactor, float zFactor){
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
 * Finally draws the object
 */
void Sphere::draw()
{
	
   //Printing Horizontal Loops
    for(int i=0;i<(int)vertices.size(); i++)
    { 	
    	glBegin(GL_LINE_LOOP); 
			for(int j=0; j<(int)vertices[i].size(); j++)
			{
				glVertex3f(vertices[i][j].x, vertices[i][j].y, vertices[i][j].z); 
			}
        glEnd();
    } 
   //Printing Vertical Loops

  for(int j=0;j<(int)(vertices[0]).size(); j++)
    { 	
    	glBegin(GL_LINES); 
			for(int i=0; i<(int)vertices.size()-1; i++)
			{
				glVertex3f(vertices[i][j].x, vertices[i][j].y, vertices[i][j].z); 
				glVertex3f(vertices[i+1][j].x, vertices[i+1][j].y, vertices[i+1][j].z); 
			}
        glEnd();
    }
}

void Sphere::calculateTransform()
{
	//Final Points;
	float w;
	for(int i=0; i< (int)vertices.size(); i++)
	{
		for(int j=0; j<(int)vertices[i].size(); j++)
		{
			w 				 =   transformMatrix[3][0]*vertices[i][j].x + transformMatrix[3][1]*vertices[i][j].y + transformMatrix[3][2]*vertices[i][j].z +transformMatrix[3][3]*1; 
			vertices[i][j].x =  (transformMatrix[0][0]*vertices[i][j].x + transformMatrix[0][1]*vertices[i][j].y + transformMatrix[0][2]*vertices[i][j].z +transformMatrix[0][3]*1)/w; 
			vertices[i][j].y =  (transformMatrix[1][0]*vertices[i][j].x + transformMatrix[1][1]*vertices[i][j].y + transformMatrix[1][2]*vertices[i][j].z +transformMatrix[1][3]*1)/w; 
			vertices[i][j].z =  (transformMatrix[2][0]*vertices[i][j].x + transformMatrix[2][1]*vertices[i][j].y + transformMatrix[2][2]*vertices[i][j].z +transformMatrix[2][3]*1)/w; 
		}
	}
}

void Sphere::fillDraw()
{
	int h = (int)vertices.size();
	int v = (int)vertices[0].size();
    for(int i=0;i<h; i++)
    { 	
		for(int j=0; j<v; j++)
		{
			glBegin(GL_QUADS);
				glVertex3f(vertices[i][j].x, vertices[i][j].y, vertices[i][j].z); 
				glVertex3f(vertices[i][(j+1)%v].x, vertices[i][(j+1)%v].y, vertices[i][(j+1)%v].z); 
				glVertex3f(vertices[(i+1)%h][(j+1)%v].x, vertices[(i+1)%h][(j+1)%v].y, vertices[(i+1)%h][(j+1)%v].z); 
				glVertex3f(vertices[(i+1)%h][j].x, vertices[(i+1)%h][j].y, vertices[(i+1)%h][j].z); 
			glEnd();
		}
	}     
}

/*
 * Multiplies transformMatrix = B * transformMatrix
 */
void Sphere::transform(float b[4][4])
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
