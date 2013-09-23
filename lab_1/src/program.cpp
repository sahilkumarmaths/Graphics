#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "../include/program.h"
#include<math.h>
#include<vector>

using namespace std;
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


/**************************************************************************
 * Question 1
 *************************************************************************/
 
void ques1()
{
   shape();
}

void shape() {
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
  
  /*
   * Object: Tetrahedron
   * Represntation: Mesh
   */
  glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
    glColor3f(0, 1, 0); glVertex3f(1, 0, 1);
    glColor3f(0, 0, 1); glVertex3f(0, 0, -1.4);
    glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
  glEnd();
  
   /*
   * Object: Sphere
   * Representation : Mesh
   */
  glColor3f(1,0,1);
  glTranslatef(-1,1,-3);
  glutWireSphere(0.5,15, 30);
  
  /* 
   * Object: Torus
   * Representation : Mesh
   */
  glColor3f(1,0,1);
  glRotatef(100,0,1,0);
  glTranslatef(0,-0.5,2);
  glutWireTorus(0.4,1,30,50 );
  
  /* 
   * Object: Sweep Surface
   * Representation : Sweep
   */
  int rad = 2.25;
  float PI = 3.14;
  
  glTranslatef(0,-2.5,-2);
  glBegin(GL_LINES); 
    for(int i=0;i<90;i= i+2)
    { 
        glColor3f(1, 0, 1); 
        glVertex3f(0.0, 0.0, 0.0); 
        glColor3f(1, 0, 1); 
        
        glVertex3f( 0,rad * cos (i * PI /180),rad * sin(i *PI /180) ); 
     } 
  glEnd();
  
  
  /* 
   * Object: Voxel
   * Representation : Voxel
   */
    float pixelSize = 0.25;
    float centreX = 1, centreY = 1,centreZ = 1;
    float radius = 5;
    glTranslatef(-10,0,6);
    for(float i = centreX - radius;i<centreX + radius;i+=pixelSize) 
    { 
        for(float j = centreX - radius;j<centreX + radius;j+=pixelSize) 
        { 
            for(float k = centreX - radius;k<centreX + radius;k+=pixelSize) 
            { 
                if((i-centreX)*(i-centreX) + (j-centreY)*(j-centreY) + (k-centreZ) *(k-centreZ) < radius)
                {
                    glTranslatef(-i,-j,-k); 
                    glColor3f(i,j,k); 
                    glutSolidCube(pixelSize); 
                    glTranslatef(i,j,k); 
                } 
                else continue; 
             } 
         } 
    }
    glFlush();
}

/**************************************************************************
 * Question 2
 *************************************************************************/
 
 void ques2()
{
   //Background Color
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
  
  
  vector<point> c;
  point a;
  int size = 1;
  a.x= 0,       a.y = 0,    a.z = 0,        c.push_back(a);
  a.x= size,    a.y = 0,    a.z = 0,        c.push_back(a);
  a.x= size,    a.y = 0,    a.z = size,     c.push_back(a);
  a.x= 0,       a.y = 0,    a.z = size,     c.push_back(a);  
  
  a.x= 0,       a.y = 3*size,    a.z = 0,        c.push_back(a);
  a.x= size,    a.y = 3*size,    a.z = 0,        c.push_back(a);
  a.x= size,    a.y = 3*size,    a.z = size,     c.push_back(a);
  a.x= 0,       a.y = 3*size,    a.z = size,     c.push_back(a);  
  function_ques2(c,cube);
  c.clear();

  a.x= 2*size,    a.y = 3*size,    a.z = 0,        c.push_back(a);
  a.x= 2*size,    a.y = 2*size,    a.z = 0,        c.push_back(a);
  a.x= 2*size,    a.y = 2*size,    a.z = size,     c.push_back(a);
  a.x= 2*size,    a.y = 3*size,    a.z = size,     c.push_back(a);  
  
  a.x= 0,    a.y = 3*size,    a.z = 0,        c.push_back(a);
  a.x= 0,    a.y = 2*size,    a.z = 0,        c.push_back(a);
  a.x= 0,    a.y = 2*size,    a.z = size,     c.push_back(a);
  a.x= 0,    a.y = 3*size,    a.z = size,     c.push_back(a);  
  function_ques2(c,cube);
  
  glTranslatef(0,0,2.0);
  
  
  vector<point> t;
  a.x= 0,       a.y = 0,    a.z = 0,        t.push_back(a);
  a.x= size,    a.y = 0,    a.z = 0,        t.push_back(a);
  a.x= 0,       a.y = size, a.z = 0,        t.push_back(a);
  a.x= 0,       a.y = 0,    a.z = size,     t.push_back(a);  
  
  function_ques2(t,tetrahedron);
  glFlush();
}

void function_ques2(vector<point> p,choice t )
{
    if(t==triangle)
    {
         displaytriangle(p);
    }else if(t==cube)
    {
        displaycube(p);
        
    }else if(t==tetrahedron)
    {
         displaytetra(p);
    }
}
/*
 * This function displays the cube of the given list of vertices
 */
void displaycube(vector<point> cube){

   //Surface 1
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_QUADS);
  
  	glVertex3f(cube[0].x,cube[0].y,cube[0].z);
  	glVertex3f(cube[1].x,cube[1].y,cube[1].z);
  	glVertex3f(cube[2].x,cube[2].y,cube[2].z);
  	glVertex3f(cube[3].x,cube[3].y,cube[3].z);
  glEnd();
  
  //Surface 2
  glColor3f(1.0, 0, 0.0); 
  glBegin(GL_QUADS);
  	glVertex3f(cube[4].x,cube[4].y,cube[4].z);
  	glVertex3f(cube[5].x,cube[5].y,cube[5].z);
  	glVertex3f(cube[6].x,cube[6].y,cube[6].z);
  	glVertex3f(cube[7].x,cube[7].y,cube[7].z);
  	
  glEnd();
  
  //Surface 3
  glColor3f(1.0, 0.0, 0);
  glBegin(GL_QUADS);
  
  	glVertex3f(cube[2].x,cube[2].y,cube[2].z);
  	glVertex3f(cube[3].x,cube[3].y,cube[3].z);
  	glVertex3f(cube[7].x,cube[7].y,cube[7].z);
  	glVertex3f(cube[6].x,cube[6].y,cube[6].z);
  	
  glEnd();
  
  //Surface 4
  glColor3f(1.0, 0, 0);
  glBegin(GL_QUADS);
  
  	glVertex3f(cube[5].x,cube[5].y,cube[5].z);
  	glVertex3f(cube[1].x,cube[1].y,cube[1].z);
  	glVertex3f(cube[0].x,cube[0].y,cube[0].z);
  	glVertex3f(cube[4].x,cube[4].y,cube[4].z);
  	
  glEnd();
  
   //Surface 5  
   glColor3f(1.0, 0, 0.0);
   glBegin(GL_QUADS);
  
  	glVertex3f(cube[1].x,cube[1].y,cube[1].z);
  	glVertex3f(cube[2].x,cube[2].y,cube[2].z);
  	glVertex3f(cube[6].x,cube[6].y,cube[6].z);
  	glVertex3f(cube[5].x,cube[5].y,cube[5].z);
  	
  glEnd();
  
  //Surface 6
  glColor3f(1.0, 0.0, 0);
  glBegin(GL_QUADS);
  
  	glVertex3f(cube[0].x,cube[0].y,cube[0].z);
  	glVertex3f(cube[3].x,cube[3].y,cube[3].z);
  	glVertex3f(cube[7].x,cube[7].y,cube[7].z);
  	glVertex3f(cube[4].x,cube[4].y,cube[4].z);
  glEnd();
}


/*
 * This function displays the tetrahedron of the passed 
 * vector points.
 * You need to flush after calling this function.
 */
void displaytetra(vector<point> tetra) {

   //Surface 1
   glColor3f(1.0, 0, 0);
   glBegin(GL_TRIANGLES );
  
  	glVertex3f(tetra[1].x,tetra[1].y,tetra[1].z);
  	glVertex3f(tetra[2].x,tetra[2].y,tetra[2].z);
  	glVertex3f(tetra[3].x,tetra[3].y,tetra[3].z);
  	
  glEnd();
  
  //Surface 2
  glColor3f(0.0, 1.0, 00); 
     glBegin(GL_TRIANGLES );
  	
  	glVertex3f(tetra[0].x,tetra[0].y,tetra[0].z);
  	glVertex3f(tetra[1].x,tetra[1].y,tetra[1].z);
  	glVertex3f(tetra[2].x,tetra[2].y,tetra[2].z);
  	
  glEnd();
  
    //Surface 3
      glColor3f(0, 0, 1.0);
      glBegin(GL_TRIANGLES );
  
    glVertex3f(tetra[0].x,tetra[0].y,tetra[0].z);
  	glVertex3f(tetra[2].x,tetra[2].y,tetra[2].z);
  	glVertex3f(tetra[3].x,tetra[3].y,tetra[3].z);
  	
  glEnd();
  
      //Surface 4
      glColor3f(1.0, 0, 0.00);
      glBegin(GL_TRIANGLES );
  
  	glVertex3f(tetra[0].x,tetra[0].y,tetra[0].z);
  	glVertex3f(tetra[1].x,tetra[1].y,tetra[1].z);
  	glVertex3f(tetra[3].x,tetra[3].y,tetra[3].z);
  	
  glEnd();
}


void displaytriangle(vector<point> t) {

      glColor3f(1.0, 1.0, 1.0);
      //Line 1
      glBegin(GL_LINES);
        glVertex3f(t[0].x,t[0].y,t[0].z);
        glVertex3f(t[1].x,t[1].y,t[1].z);
      glEnd();
      
      //Line 2
      glBegin(GL_LINES);
          glVertex3f(t[1].x,t[1].y,t[1].z);
          glVertex3f(t[2].x,t[2].y,t[2].z);  
      glEnd();
      //Line 3
      glBegin(GL_LINES);
          glVertex3f(t[0].x,t[0].y,t[0].z);
          glVertex3f(t[2].x,t[2].y,t[2].z);
      glEnd();
/*      glBegin(GL_POLYGON );
           glVertex3f(t[0].x,t[0].y,t[0].z);
           glVertex3f(t[1].x,t[1].y,t[1].z);
           glVertex3f(t[2].x,t[2].y,t[2].z);  	
      glEnd();*/
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

/**************************************************************************
 * Question 4: 
 **************************************************************************/
void ques4()
{
   //Background Color
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
    
  vector<point> c;
  point a;
  int size = 1;
  a.x= 0,       a.y = 0,    a.z = 0,        c.push_back(a);
  a.x= 0,       a.y = 0,    a.z = size,     c.push_back(a);
  a.x= size,    a.y = 0,    a.z = size,     c.push_back(a);
  a.x= size,    a.y = 0,    a.z = 0,        c.push_back(a);  
  
  a.x= 0,       a.y = size, a.z = 0,        c.push_back(a);  
  a.x= 0,       a.y = size, a.z = size,     c.push_back(a);  
  a.x= size,    a.y = size, a.z = size,     c.push_back(a);  
  a.x= size,    a.y = size, a.z = 0,        c.push_back(a);   
  
  ques4_helping(c);
  glFlush();  
}

void ques4_helping(vector<point> points)
{  
    glBegin(GL_TRIANGLES);
	for(unsigned int i = 0;i<points.size();i++)
	{
		for(unsigned int j=i+1;j<points.size();j++)
		{
			for(unsigned int k=j+1;k<points.size();k++)
			{
				glColor3f(1,0.5,0.25);
				vector<point> temp;
				temp.push_back(points[i]);
				temp.push_back(points[j]);
				temp.push_back(points[k]);
				displaytriangle(temp);
			}
		}
	}    
    glEnd();    
}

