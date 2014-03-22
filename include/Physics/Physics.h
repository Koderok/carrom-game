#ifndef _Physics_h_included_
#define _Physics_h_included_
#include "../Common/Common.h"


double distance(double x1,double x2, double y1,double y2);
double distanceFromHole(double x, double y, int hole);
int approaching(int i,int j,common *data);		// returns 1 if coin i and j are approaching or are stat wrt each other 
void move(common *data);
float mod(float f);

#endif
