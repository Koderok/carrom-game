#include "../../include/Physics/Physics.h"
#include "../../include/CarromRules/Board.h"
#include <iostream>
using namespace std ;

double distanceFromHole(double x, double y, int hole)
{
	if(hole == 0)
		{	return distance(x,y,l+hRad,d+hRad);
		}
	else if(hole==1)
		{	return distance(x,y,r-hRad,d+hRad);
		}
	else if(hole==2)
		{	return distance(x,y,r-hRad,u-hRad);
		}
	else if(hole==3)
		{	return distance(x,y,l+hRad,u-hRad);
		}
	else
		{ 	cout<<"invalid hole number "<< endl ;
		}
}
