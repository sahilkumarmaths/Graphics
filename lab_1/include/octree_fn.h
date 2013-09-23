#ifndef  OCTREE_FN_INC
#define  OCTREE_FN_INC

// Includes
#include <cassert>
#include <string>
using std::string;
#include <GL/glut.h>

namespace octree
{

// Tree symbols specs
const char EMPTY  = '0';
const char FILLED = '1';
const char DIRTY  = '2';

// Prototypes
void drawCube(double center_x, double center_y, double center_z, double size);
void drawOctree(const string& tree, double center_x, double center_y,
                double center_z, double cube_size);
int drawOctree(const string& tree, size_t pos, double center_x, double center_y,
                double center_z, double cube_size);

}		


#endif
