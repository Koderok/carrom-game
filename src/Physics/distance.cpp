#include <iostream>
using namespace std ;
#include <math.h>

#include "../../include/Physics/Physics.h"


double distance(double x1,double x2, double y1,double y2)
{
	double dis=(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
	return sqrt(dis);
}

