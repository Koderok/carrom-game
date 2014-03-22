#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "../../include/Graphics/Graphics.h"
#include "../../include/Common/Common.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/Physics/Physics.h"
#include <iostream>
using namespace std ;

void mouse(int button, int state, int x, int y)
{
	if(data->flag1!=1)
{
	data->X=x*data->conversiony;
	data->Y=2-y*data->conversiony;	
}	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
			if(DEBUG)
			cout << "Right button pressed"
			<< endl;
		else
			if(DEBUG)
			cout << "Right button lifted "
			<< "at (" << data->X << "," <<data->Y
			<< ")" << endl;
	//cout<<distance(X,0,Y,0);
	}
	else if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
if(data->X>=l+border+30*unit&&data->X<=l+border+32*unit&&data->Y<=u+border+5.6*unit&&data->Y>=u+border+2.6*unit)//drawPoly(l+border+30*unit,u+border+5*unit,0,l+border+32*unit,u+border+5*unit,0,l+border+32*unit,u+border-4*border,0,l+border+30*unit,u+border-4*border,0);
data->acc+=2*unit;
else if(data->X>=l+border+30*unit&&data->X<=l+border+32*unit&&data->Y<=u+border+2.6*unit&&data->Y>=u+border+-0.6*unit)//drawPoly(l+border+30*unit,u+border+5*unit,0,l+border+32*unit,u+border+5*unit,0,l+border+32*unit,u+border-4*border,0,l+border+30*unit,u+border-4*border,0);
data->acc+=4*unit;
else if(data->X>=l+border+30*unit&&data->X<=l+border+32*unit&&data->Y<=u+border-0.6*unit&&data->Y>=u+border-3.6*unit)//drawPoly(l+border+30*unit,u+border+5*unit,0,l+border+32*unit,u+border+5*unit,0,l+border+32*unit,u+border-4*border,0,l+border+30*unit,u+border-4*border,0);
data->acc+=6*unit;

if(data->just==0&&data->X<=1.19&&data->X>=1&&data->Y>=(d+1.85)/2&&data->Y<=(d+2.045)/2)
			{
	if(!data->play)			
			data->createdby=4;
		else
	data->createdby=5;
return;	
			}
			if(data->createdby!=5&&data->just==0&&data->X>=(l+r-.01)/2&&data->X<=(l+r+1)/2&&data->Y>=(d+1.25)/2&&data->Y<=(d+1.445)/2)
			{
			exit(1);
				}
			if(data->createdby!=5&&data->just==0&&data->X>=(l+r-.01)/2&&data->X<=(l+r+1)/2&&data->Y>=(d+1.45)/2&&data->Y<=(d+1.645)/2)
			{
			data->createdby=1;
return;	
			}
			if(data->createdby!=5&&data->just==0&&data->X>=1&&data->X<=1.19&&data->Y>=(d+1.65)/2&&data->Y<=(d+2)/2)
			{
			data->createdby=2;
				}
			if(data->createdby!=5&&data->just==5&&data->X<=2&&data->X>=1&&data->Y>=(d+1.85)/2&&data->Y<=(d+2.045)/2)
{
	
data->startcol=4;
data->just=0;	
data->ss=1;
data->createdby=5;
return;	
}
			if(data->createdby!=5&&data->just==5&&data->X<=2&&data->X>=1&&data->Y>=(d+1.65)/2&&data->Y<=(d+1.845)/2)
{
	
data->startcol=4;
data->just=0;
data->ss=1;	
data->createdby=5;
return;	
}
			if(data->createdby!=5&&data->just==5&&data->X<=2&&data->X>=1&&data->Y>=(d+1.45)/2&&data->Y<=(d+1.645)/2)
{
	
data->startcol=4;
data->just=0;
data->ss=1;	
data->createdby=5;
return;	
}
			if(data->createdby!=5&&data->just==5&&data->X<=2&&data->X>=1&&data->Y>=(d+1.25)/2&&data->Y<=(d+1.445)/2)
{
	
data->startcol=4;
data->just=0;
data->ss=1;	
data->createdby=5;
return;	
}
else
data->startcol=0;	
if(data->createdby!=5&&data->just==0&&data->X>=(l+r-.01)/2&&data->X<=(l+r+.38)/2&&data->Y>=(d+1.05)/2&&data->Y<=(d+1.245)/2)		
	{
			data->play=0;
home(data);
				}
		glColor3f(0,0,-1);	


			glColor3f(0,0,-1);	
			data->lbuttonDown = true;
			

			if(DEBUG)
			cout<<"AAAAAAAAAAAAAAAAAAAAAAA";	
			//drawFilledCircle(x/20,y/20,0.5,.4);	
			if(DEBUG)
			cout<<"AAAAAAAAAAAAAAAAAAAAAAA";
		}	
		else
			data->lbuttonDown = false;
	}
}

//####################################################################//


void motion(int x, int y)
{
	int i=0;
	if(DEBUG)
	cout<<"QWQEWQW"<<x<<"   "<<y;	
	data->X=x*data->conversiony;
	data->Y=2-y*data->conversiony;	
	if (data->lbuttonDown)
	{
	if(DEBUG)
	cout << "Mouse dragged with left button at "
		<< "(kkkkkkkkkk" << data->X << "," << data->Y << ")" <<"  " \
		<<data->a[0].getX()<<" "<<data->a[0].getY()<< "   "<<distance \
		((double)data->X,(double)data->a[0].getX(),(double)data->Y, \
		(double)data->a[0].getY());
	
	if( distance((double)data->X,(double)data->a[0].getX(),(double)data->Y,(double) data->a[0].getY())<=cRad &&data->X<=r-2*pWidth&&data->X>=l+2*pWidth)
		{if(data->a[0].getX()>data->X)
		for(i=1;i<6;i++)
						{
							if((distance(data->a[0].getX(),data->a[i].getX(),data->a[0].getY(),data->a[i].getY()) <=sRad+cRad) && (data->a[0].getX()-2*sRad-2*cRad >=l+pDist2))
							{
								data->a[0].setX(data->a[0].getX()-2*cRad-2*sRad) ;
								//data->a[0].setY(data->a[0].getY());								
								glutPostRedisplay();
								return;
							}
						}
						
		if(data->a[0].getX()< data->X && data->X-data->a[0].getX()<=cRad)
		for(i=1;i<6;i++)
						{
							if((distance(data->a[0].getX(),data->a[i].getX(),data->a[0].getY(),data->a[i].getY()) <=sRad+cRad) && (data->a[0].getX()-2*sRad-2*cRad <=r-pDist2))
							{
								data->a[0].setX(data->a[0].getX()+2*sRad+2*cRad) ;
								glutPostRedisplay();
								return;
							}
						}				
		data->a[0].setX(data->X);
		data->a[0].setY(data->Y);
		//data->mouseflag=1;	
	}
	
if( distance(data->X,data->a[0].getX(),data->Y,data->a[0].getY())>=cRad && data->a[0].getX() >=l && data->a[0].getX() <=r)
	{
		
		
		data->arrowAng=acos( (data->X-data->a[0].getX())/sqrt((data->X-data->a[0].getX())* \
		(data->X-data->a[0].getX()) + (data->Y-data->a[0].getY())*(data->Y-data->a[0].getY())) ) ;
		
		data->arrowRad=sqrt((data->X-data->a[0].getX())*(data->X-data->a[0].getX()) + \
		(data->Y-data->a[0].getY())*(data->Y-data->a[0].getY())) ;
		data->arrowRad=(data->arrowRad>=maxArrRad)?maxArrRad:data->arrowRad;
		//data->arrowRad=(data->arrowRad<=unit/3)?unit/3:data->arrowRad;
	}
if(data->X>=r)
{
data->control=1;
			//data->a[0].setY(data->a[0].getY()+inc);
			glutPostRedisplay();

}
	glutPostRedisplay();
}
	
}


void motionPassive(int x, int y)
{
	data->X=x*data->conversiony;
	data->Y=2-y*data->conversiony;

if(data->just==0&&data->X<=1.5&&data->X>=1&&data->Y>=(d+1.85)/2&&data->Y<=(d+2.045)/2)
{
	
data->startcol=1;	
return;	
}
else
data->startcol=0;

if(data->just==0&&data->X>=(l+r-.01)/2&&data->X<=(l+r+1)/2&&data->Y>=(d+1.45)/2&&data->Y<=(d+1.645)/2)
{

data->startcol=3;
return;
}
else
data->startcol=0;
if(data->just==0&&data->X>=(l+r-.01)/2&&data->X<=(l+r+1)/2&&data->Y>=(d+1.65)/2&&data->Y<=(d+1.845)/2)
{
data->startcol=2;
return;
}
else
data->startcol=0;
if(data->just==0&&data->X>=(l+r-.01)/2&&data->X<=(l+r+1)/2&&data->Y>=(d+1.25)/2&&data->Y<=(d+1.445)/2)
{
data->startcol=4;
return;
}
else
data->startcol=0;
if(data->just==5&&data->X<=(l+r+1)/2&&data->X>=(l+r-.01)/2&&data->Y>=(d+1.85)/2&&data->Y<=(d+2.045)/2)
{
	
data->startcol=10;
return;	
}
else if(data->just==5&&data->X<=(l+r+1)/2&&data->X>=(l+r-.01)/2&&data->Y>=(d+1.65)/2&&data->Y<=(d+1.845)/2)
{

	
data->startcol=11;
return;	

}
else if(data->just==5&&data->X<=(l+r+1)/2&&data->X>=(l+r-.01)/2&&data->Y>=(d+1.45)/2&&data->Y<=(d+1.645)/2)
{

	
data->startcol=12;
return;	

}
else if(data->just==5&&data->X<=(l+r+1)/2&&data->X>=(l+r-.01)/2&&data->Y>=(d+1.25)/2&&data->Y<=(d+1.445)/2)
{

	
data->startcol=13;
return;	

}
else
data->startcol=0;
if(data->just==0&&data->X>=(l+r-.01)/2&&data->X<=(l+r+1)/2&&data->Y>=(d+1.05)/2&&data->Y<=(d+1.245)/2)
{
data->startcol=9;
return;
}
else
data->startcol=0;	
/*if(data->just==5&&data->X<=(l+r+.38)/2&&data->X>=(l+r-.01)/2&&data->Y>=(d+1.85)/2&&data->Y<=(d+2.045)/2)
{
	
data->startcol=1;	
return;	
}
else
data->startcol=0;
*/	if(DEBUG)
	cout << "Mouse moved at "
		<< "(" << data->X << "," << data->Y << ")" << endl;

}

void entry(int state)
{
	if (state == GLUT_ENTERED)
		if(DEBUG)
			cout << "Mouse Entered" << endl;
	else
		if(DEBUG)
			cout << "Mouse Left" << endl;
}







