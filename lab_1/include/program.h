
#include<vector>
using namespace std;
enum choice{
    triangle=0,cube=1,tetrahedron=2
};

typedef struct point1{
    float x,y,z;
}point;



/*
 * Question Number: 1
 */
void ques1();
void shape();
/*
 * Question Number: 2
 */
void ques2();
void function_ques2(vector<point> p, choice t );
void displaycube(vector<point> cube);
void displaytetra(vector<point> tetra);
void displaytriangle(vector<point> t);
void keyboard(unsigned char key, int x, int y);



/*
 * Question Number: 3
 */



/*
 * Question Number: 4
 */
void ques4();
void ques4_helping(vector<point> points);
