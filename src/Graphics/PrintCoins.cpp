#include <GL/glut.h>
#include <iostream>
using namespace std;
#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/CarromRules/RulesImplement.h"

void printCoins(common *data)
{
		int i;
	for(i=0;i<6;i++)
		{	
			if(inHole(data->a[i].getX(),data->a[i].getY()) )	// do not print coin if it is in hole
			{
				//if(DEBUG)
					cout<<"coin "<<i<<" is in hole...(from Print Coins)"<<endl ;
				data->a[i].init(-1,-1,0,0);
				continue;
			}	
			else
			{
				if(DEBUG)
					cout<<"coin "<< i << " is not in hole" ;
			}
			if(data->a[i].getColour()==0)	// WHITE COIN
			{
				glColor3f(0.9,0.9,0.9);
				drawFilledCircle(data->a[i].getX(),data->a[i].getY(),-0.05,pWidth/2);
				glColor3f(0,0,0);
				glLineWidth(2);
				drawCircle(data->a[i].getX(),data->a[i].getY(),-0.05,pWidth/2);
				glLineWidth(1);
			}
			else if(data->a[i].getColour()==1)	// BLACK COIN
			{	
				glColor3f(0.1,0.1,0.1);
				drawFilledCircle(data->a[i].getX(),data->a[i].getY(),-0.05,pWidth/2);
			}
			else if(data->a[i].getColour()==2)	// RED COIN
			{	
				glColor3f(1,0,0);
				drawFilledCircle(data->a[i].getX(),data->a[i].getY(),-0.05,pWidth/2);
				glColor3f(0,0,0);
				glLineWidth(2);
				drawCircle(data->a[i].getX(),data->a[i].getY(),-0.05,pWidth/4);
				drawCircle(data->a[i].getX(),data->a[i].getY(),-0.05,pWidth/2);
				glLineWidth(1);
			}
			else  								//	STRIKER
			{			
				glColor3f(0,0,0);
				drawFilledCircle(data->a[i].getX(),data->a[i].getY(),-0.05,sRad);
				glColor3f(0.2,1,0.2);
				drawFilledCircle(data->a[i].getX(),data->a[i].getY(),-0.05,0.92*sRad);
			}
		}


}
