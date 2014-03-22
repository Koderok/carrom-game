#include <stdlib.h>
#include <math.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#include <GL/glut.h>
#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/Physics/Physics.h"
#include "../../include/CarromRules/RulesImplement.h"
// glutKeyboardFunc is called below to set this function to handle
//		all "normal" ascii key presses.
// Only space bar and escape key have an effect.
void myKeyboardFunc( unsigned char key, int x, int y )
{
	
switch ( key ) 
	{

	case 27:
if(data->createdby==5)
data->createdby=0;
else if(data->createdby==1)
data->createdby=0;
else if(data->createdby==2)
data->createdby=0;
else if(data->createdby==4)
{
data->createdby=0;
data->just=0;
}
else							// "27" is theEscape key
exit(0);
		break;
	case 13:									//13 is enter/return
		{
			
			if(data->control != 0)
			{
			data->control=0;
			data->a[0].setVel(3*((data->powH+unit)*cos(data->arrowAng)),3*((data->powH+unit)*sin(data->arrowAng)));
			if(data->finish==1)
			exit(0);			
			}
			glutPostRedisplay();	
		}	
		break;
	case ' ':
		{
			int i;
			for (int i = 0; i < 6; i++)
			{
			if(DEBUG)				
			cout<<i<<" : "<<data->a[i].getY()<<"  "<<data->side<<endl; 
			}
			
			data->side=(data->side+1)%2;
			if(data->side==0)
			data->side=2;	
			rulesImplement(data);
			//data->a[0].init((l+r)/2,d+pDist1+pWidth/2,0,11*unit);
			//data->a[1].init(data->a[1].getX(),data->a[1].getY(),0,0);
			data->control=1;
			
			if(data->continueTurn&&data->players==4)		//change turn if continueTurn is 1
				data->turn=(data->turn+1)%4;
			else if(data->continueTurn&&data->players==2)		//
			{
			data->turn=(data->turn+2)%4;	
					
			}	
			data->arrowRad=2*unit;data->arrowAng=PI/2;
			glutPostRedisplay();
			data->st=0;
			if(data->server==89)
			{
			if(data->turn==1)
			data->a[0].init((l+pDist1+pWidth/2),(u+d)/2,0,0);
			if(data->turn==3)
			data->a[0].init((r-pDist1-pWidth/2),(u+d)/2,0,0);
			if(data->turn==2)
			data->a[0].init((l+r)/2,u-pDist1-pWidth/2,0,0);	
			if(data->turn==0)
			data->a[0].init((l+r)/2,d+pDist1+pWidth/2,0,0);			
			}			
			glutPostRedisplay();
if(data->server!=89)
{
			data->control=1;
if(data->server==1)
data->a[0].init((l+r)/2,d+pDist1+pWidth/2,0,0);
else if(data->server==0)
data->a[0].init((r-pDist1-pWidth/2),(u+d)/2,0,0);
data->turn=(data->turn)%2;		
}		}
		break;
	case 'a':
		{
			if(DEBUG)			
			printf("pppppppp");
			if(1)
				data->arrowAng+=angInc; 	
				
		}break;
	case 'd' :
		{	if(1)
				data->arrowAng-=angInc;
			
		}break;
	case 'w':
		{	
			if(data->arrowRad<=maxArrRad-unit/3)
				data->arrowRad+=unit/3;
			else
				data->arrowRad=maxArrRad;	
		}break;
	case 's' :
		{
			if(data->arrowRad>=unit/3)
				data->arrowRad-=unit/3;
			else
				data->arrowRad=0;
		}break;
	default:
	if(data->a[0].getVx()<=10*unit&&data->a[0].getVy()<=10*unit&&data->control==0)
		{
data->control=1;
data->a[0].init((l+r)/2,d+pDist1+pWidth/2,0,0);

data->turn=(data->turn+1)%2;
}
	}
}


void mySpecialKeyFunc(int key,int x , int y)
{
	int i=0;
	switch(key)
	{
		case GLUT_KEY_LEFT :
if(data->server==89)
{			
if(data->turn==1&&data->a[0].getY()<u-2*pWidth)
data->a[0].setY(data->a[0].getY()+unit/2);
if(data->turn==3&&data->a[0].getY()>d+2*pWidth)
data->a[0].setY(data->a[0].getY()-unit/2);				
			if(data->turn==2&&data->a[0].getX()<r-2*pWidth)
data->a[0].setX(data->a[0].getX()+unit/2);
}
			if(data->server==1 && data->a[0].getX()>=l+pDist2)
						data->a[0].setX(data->a[0].getX()-inc);
						else if(data->server==0&&data->a[0].getX()>=l+pDist2&&data->a[0].getX()<=r-pDist2-inc)
						{
						;//data->a[0].setX(data->a[0].getY()+inc);				
						
						}
							
			if(data->control==1 && data->a[0].getX()>=l+pDist2 && data->a[0].getX()<=r-pDist2+inc)
			{
				if(data->a[0].getX()<=l+pDist2+inc)
					{
						data->a[0].setX(l+pDist2);
					}
				else
					{
						for(i=1;i<6;i++)
						{
							if((distance(data->a[0].getX(),data->a[i].getX(),data->a[0].getY(),data->a[i].getY()) <=sRad+cRad) && (data->a[0].getX()-2*sRad-2*cRad >=l+pDist2))
							{
								if(data->turn==0)								
								data->a[0].setX(data->a[0].getX()-2*sRad-2*cRad) ;
								else
								data->a[0].setX(data->a[0].getX()+2*sRad+2*cRad) ;								
								glutPostRedisplay();
								return;
							}
						}
						if(data->server==0)						
						data->a[0].setX(data->a[0].getX()+inc);							
						else data->a[0].setX(data->a[0].getX()-inc);	
							
					}	
				glutPostRedisplay();
			}
			break;
		case GLUT_KEY_RIGHT :

if(data->server==89)
{
if(data->turn==1&&data->a[0].getY()>d+2*pWidth)
data->a[0].setY(data->a[0].getY()-unit/2);
if(data->turn==3&&data->a[0].getY()<u-2*pWidth)
data->a[0].setY(data->a[0].getY()+unit/2);			
if(data->turn==2&&data->a[0].getX()>l+2*pWidth)
data->a[0].setX(data->a[0].getX()-unit/2);				
}
				if(data->server==1&&data->a[0].getX()<=r-pDist2+inc)
						data->a[0].setX(data->a[0].getX()+inc);
						else if(data->server==0&&data->a[0].getX()<=r-pDist2+inc&&data->a[0].getX()>=l+pDist2+inc)
						{
						;//data->a[0].setX(data->a[0].getY()-inc);				
						
						}			
			if(data->control==1 && data->a[0].getX()>=l+pDist2-inc && data->a[0].getX()<=r-pDist2)
			{
				if(data->a[0].getX()>=r-pDist2-inc)
					data->a[0].setX(r-pDist2);
				else
					{
						for(i=1;i<6;i++)
						{
							if((distance(data->a[0].getX(),data->a[i].getX(),data->a[0].getY(),data->a[i].getY())<=sRad+cRad) && (data->a[0].getX()-2*sRad-2*cRad <=r-pDist2))
							{
								if(data->turn==0)								
								data->a[0].setX(data->a[0].getX()+2*sRad+2*cRad) ;
								else
								data->a[0].setX(data->a[0].getX()-2*sRad-2*cRad) ;
								glutPostRedisplay();
								return;
							}
						}
						if(data->server==0)						
						data->a[0].setX(data->a[0].getX()-inc);							
						else data->a[0].setX(data->a[0].getX()+inc);	
					}
				glutPostRedisplay();
			}
			break;
		case GLUT_KEY_HOME :
		{
			home(data);
			data->control=1;
			//anglex=0;angley=unit/2;
			data->arrowRad=2*unit;data->arrowAng=PI/2;
			glutPostRedisplay();
		}
			break;	
	}
}
