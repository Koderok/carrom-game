#include <stdlib.h>
#include<stdio.h>
#include <math.h>
#include<string.h>
#include <GL/glut.h>
#include "../../include/Common/Common.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/Physics/Physics.h"
#include "../../include/Networking/Networking.h"
#include "../../include/AI/ai.h"
#include <iostream>
using namespace std ;

/*
 * drawScene() handles the animation and the redrawing of the
 *		graphics window contents.
 */
void drawScene()
{
	// Clear the rendering window
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Set drawing color to white
	glColor3f( 00.0, 0.0, 0.0 );		//	CARROM SQUARE
	if(data->just==1)
	{
	glClearColor(2, .89,.01,0.1);
	glColor3f(1,0,0.4);
	data->tim+=.01;
	
	output((l+r)/2,(d+2)/2+.4, "CARROM");
	if(data->tim>=.5)
	{
		data->just=0;
			
		glClearColor(1.0, 1.0, 1.0, 1.0);
	}	
	}
else
{	
	
if(data->createdby==5)
{
	drawPoly(l,d,0,r,d,0,r,u,0,l,u,0);	// size of carrom square is 30*unit
	glPushMatrix();	
	if(data->server==0)
	{
		glTranslatef((l+r)/2,(u+d)/2, 0);
	 glRotatef(-180,0,0,1);
	glTranslatef(-(l+r)/2,-(u+d)/2, 0);
	}
	
	//printf("((((((((((((((((((((");	
	if(data->control==1)
	{
	if(d+4.2*border+data->powH>u-4.2*border || data->powH<0)
		data->powInc=1-data->powInc;
	if(data->powInc)	
		data->powH+=unit/5;
	else
		data->powH-=unit/5;
	}
		//printf("((((((((((((((((((((");
	glColor3f( 1, 0.8, 0.6 );		//CARROM BORDER SQUARE
	drawPoly(l+border,d+border,0,r-border,d+border,0,r-border,u-border,0,l+border,u-border,0);	
			
	glColor3f(0,0,0);
	
	glLineWidth(2);	drawLine(l+pDist2,d+pDist1,0.0,r-pDist2,d+pDist1,0.0);	// BOTTOM PANEL
	glLineWidth(1);	drawLine(l+pDist2,d+pDist1+pWidth,0.0,r-pDist2,d+pDist1+pWidth,0.0);
	
	glLineWidth(2);	drawLine(r-pDist1,d+pDist2,0.0,r-pDist1,u-pDist2,0.0);	// RIGHT PANEL
	glLineWidth(1);	drawLine(r-pDist1-pWidth,d+pDist2,0.0,r-pDist1-pWidth,u-pDist2,0.0);
		
	glLineWidth(2);	drawLine(l+pDist2,u-pDist1,0.0,r-pDist2,u-pDist1,0.0);	// UPPER PANEL
	glLineWidth(1);	drawLine(l+pDist2,u-pDist1-pWidth,0.0,r-pDist2,u-pDist1-pWidth,0.0);
	
	glLineWidth(2);	drawLine(l+pDist1,d+pDist2,0.0,l+pDist1,u-pDist2,0.0);	//LEFT PANEL
	glLineWidth(1);	drawLine(l+pDist1+pWidth,d+pDist2,0.0,l+pDist1+pWidth,u-pDist2,0.0);
	
	drawCircle(l+pDist2,d+pDist1+pWidth/2,0.0,pWidth/2);	// PANEL CIRCLES
	drawCircle(r-pDist2,d+pDist1+pWidth/2,0.0,pWidth/2);
	drawCircle(r-pDist1-pWidth/2,d+pDist2,0.0,pWidth/2);
	drawCircle(r-pDist1-pWidth/2,u-pDist2,0.0,pWidth/2);		
	drawCircle(r-pDist2,u-pDist1-pWidth/2,0.0,pWidth/2);
	drawCircle(l+pDist2,u-pDist1-pWidth/2,0.0,pWidth/2);
	drawCircle(l+pDist1+pWidth/2,u-pDist2,0.0,pWidth/2);
	drawCircle(l+pDist1+pWidth/2,d+pDist2,0.0,pWidth/2);		
	glColor3f(1,0,0);	
	drawFilledCircle(l+pDist2,d+pDist1+pWidth/2,0.0,pWidth/2.5);
	drawFilledCircle(r-pDist2,d+pDist1+pWidth/2,0.0,pWidth/2.5);
	drawFilledCircle(r-pDist1-pWidth/2,d+pDist2,0.0,pWidth/2.5);
	drawFilledCircle(r-pDist1-pWidth/2,u-pDist2,0.0,pWidth/2.5);		
	drawFilledCircle(r-pDist2,u-pDist1-pWidth/2,0.0,pWidth/2.5);
	drawFilledCircle(l+pDist2,u-pDist1-pWidth/2,0.0,pWidth/2.5);
	drawFilledCircle(l+pDist1+pWidth/2,u-pDist2,0.0,pWidth/2.5);
	drawFilledCircle(l+pDist1+pWidth/2,d+pDist2,0.0,pWidth/2.5);		
	
	glColor3f(0,0,0);									//	AIMING LINES
	drawLine(l+border+2*hRad+1.222*unit,d+border+2*hRad+1.222*unit,0,l+border+2*hRad+7.504*unit+arcRad/1.414,d+border+2*hRad+arcRad/1.414+7.504*unit,0);
	drawLine(r-border-2*hRad-1.222*unit,d+border+2*hRad+1.222*unit,0,r-border-2*hRad-7.504*unit-arcRad/1.414,d+border+2*hRad+arcRad/1.414+7.504*unit,0);
	drawLine(r-border-2*hRad-1.222*unit,u-border-2*hRad-1.222*unit,0,r-border-2*hRad-7.504*unit-arcRad/1.414,u-border-2*hRad-7.504*unit-arcRad/1.414,0);
	drawLine(l+border+2*hRad+1.222*unit,u-border-2*hRad-1.222*unit,0,l+border+2*hRad+7.504*unit+arcRad/1.414,u-border-2*hRad-7.504*unit-arcRad/1.414,0);
	
	drawTri(l+border+2*hRad+1.222*unit-tri, d+border+2*hRad+1.222*unit-tri, 0.0,		\
		  l+border+2*hRad+1.222*unit+tri-tri/1.5, d+border+2*hRad+1.222*unit+tri+tri/1.5, 0.0,	\
		  l+border+2*hRad+1.222*unit+tri+tri/1.5, d+border+2*hRad+1.222*unit+tri-tri/1.5, 0.0 );
	drawTri(r-border-2*hRad-1.222*unit+tri, d+border+2*hRad+1.222*unit-tri, 0.0,		\
		  r-border-2*hRad-1.222*unit-tri+tri/1.5, d+border+2*hRad+1.222*unit+tri+tri/1.5, 0.0,	\
		  r-border-2*hRad-1.222*unit-tri-tri/1.5, d+border+2*hRad+1.222*unit+tri-tri/1.5, 0.0 );
	drawTri(r-border-2*hRad-1.222*unit+tri, u-border-2*hRad-1.222*unit+tri, 0.0,		\
		  r-border-2*hRad-1.222*unit-tri+tri/1.5, u-border-2*hRad-1.222*unit-tri-tri/1.5, 0.0,	\
		  r-border-2*hRad-1.222*unit-tri-tri/1.5, u-border-2*hRad-1.222*unit-tri+tri/1.5, 0.0 );
	drawTri(l+border+2*hRad+1.222*unit-tri, u-border-2*hRad-1.222*unit+tri, 0.0,		\
		  l+border+2*hRad+1.222*unit+tri-tri/1.5, u-border-2*hRad-1.222*unit-tri-tri/1.5, 0.0,	\
		  l+border+2*hRad+1.222*unit+tri+tri/1.5, u-border-2*hRad-1.222*unit-tri+tri/1.5, 0.0 );
	
	drawArc(l+border+2*hRad+7.504*unit,d+border+2*hRad+7.504*unit,0,arcRad,0);		
	drawArc(r-border-2*hRad-7.504*unit,d+border+2*hRad+7.504*unit,0,arcRad,1);
	drawArc(r-border-2*hRad-7.504*unit,u-border-2*hRad-7.504*unit,0,arcRad,2);	
	drawArc(l+border+2*hRad+7.504*unit,u-border-2*hRad-7.504*unit,0,arcRad,3);
	
	drawTri(l+border+2*hRad+7.504*unit-arcRad+0.2*tri, d+border+2*hRad+7.504*unit-1.4*tri, 0,	\
		  l+border+2*hRad+7.504*unit-arcRad-0.7*tri, d+border+2*hRad+7.504*unit+tri, 0,	\
		  l+border+2*hRad+7.504*unit-arcRad+1.2*tri, d+border+2*hRad+7.504*unit+tri, 0);
	drawTri(l+border+2*hRad+7.504*unit-1.4*tri,d+border+2*hRad+7.504*unit-arcRad+0.2*tri,0,	\
		  l+border+2*hRad+7.504*unit+tri,d+border+2*hRad+7.504*unit-arcRad+1.2*tri,0,	\
		  l+border+2*hRad+7.504*unit+tri,d+border+2*hRad+7.504*unit-arcRad-0.7*tri,0);
	drawTri(r-border-2*hRad-7.504*unit+arcRad-0.2*tri, d+border+2*hRad+7.504*unit-1.4*tri, 0,	\
		  r-border-2*hRad-7.504*unit+arcRad+0.7*tri, d+border+2*hRad+7.504*unit+tri, 0,	\
		  r-border-2*hRad-7.504*unit+arcRad-1.2*tri, d+border+2*hRad+7.504*unit+tri, 0);	
	drawTri(r-border-2*hRad-7.504*unit+1.4*tri, d+border+2*hRad+7.504*unit-arcRad-0.2*tri, 0,	\
		  r-border-2*hRad-7.504*unit-tri, d+border+2*hRad+7.504*unit-arcRad+1.2*tri, 0,	\
		  r-border-2*hRad-7.504*unit-tri, d+border+2*hRad+7.504*unit-arcRad-0.7*tri, 0);		
	drawTri(r-border-2*hRad-7.504*unit+arcRad-0.2*tri, u-border-2*hRad-7.504*unit+1.4*tri, 0,	\
		  r-border-2*hRad-7.504*unit+arcRad+0.7*tri, u-border-2*hRad-7.504*unit-tri, 0,	\
		  r-border-2*hRad-7.504*unit+arcRad-1.2*tri, u-border-2*hRad-7.504*unit-tri, 0);	
	drawTri(r-border-2*hRad-7.504*unit+1.4*tri, u-border-2*hRad-7.504*unit+arcRad-0.2*tri, 0,	\
		  r-border-2*hRad-7.504*unit-tri, u-border-2*hRad-7.504*unit+arcRad-1.2*tri, 0,	\
		  r-border-2*hRad-7.504*unit-tri, u-border-2*hRad-7.504*unit+arcRad+0.7*tri, 0);		
	drawTri(l+border+2*hRad+7.504*unit-arcRad+0.2*tri, u-border-2*hRad-7.504*unit+1.4*tri, 0,	\
		  l+border+2*hRad+7.504*unit-arcRad-0.7*tri, u-border-2*hRad-7.504*unit-tri, 0,	\
		  l+border+2*hRad+7.504*unit-arcRad+1.2*tri, u-border-2*hRad-7.504*unit-tri, 0);		
	drawTri(l+border+2*hRad+7.504*unit-1.4*tri,u-border-2*hRad-7.504*unit+arcRad-0.2*tri,0,	\
		  l+border+2*hRad+7.504*unit+tri,u-border-2*hRad-7.504*unit+arcRad-1.2*tri,0,	\
		  l+border+2*hRad+7.504*unit+tri,u-border-2*hRad-7.504*unit+arcRad+0.7*tri,0);	
		  		
	glLineWidth(2);	drawCircle((l+r)/2,(u+d)/2,0.0,2.9376*unit);
			drawCircle((l+r)/2,(u+d)/2,0.0,0.77*unit);	glLineWidth(1);
			drawCircle((l+r)/2,(u+d)/2,0.0,2.7*unit);
			drawCircle((l+r)/2,(u+d)/2,0.0,2.6*unit);
	glColor3f(1,0,0);									// CENTRE CIRCLES
	drawFilledCircle((l+r)/2,(u+d)/2,0.0,0.5495*unit) ;
	glColor3f(0,0,0);
	
	//drawTri((r+l)/2+temp1*cos(PI/4),(u+d)/2-temp1*sin(PI/4),0,(r+l)/2+temp1*cos(PI/4),(u+d)/2+temp1*sin(PI/4),0,(r+l)/2+temp2,(u+d)/2,0);
	//drawTri((r+l)/2+temp1,(u+d)/2,0,(r+l)/2,(u+d)/2-temp1,0,(r+l)/2+temp2*cos(PI/4),(u+d)/2-temp2*sin(PI/4),0);
	//int i=0;
	//for(i=1;i<9;i++)
	drawDes(1);
	drawDes(2);
	drawDes(4);
	drawDes(8);
	drawDes(2.666667);
	drawDes(1.6);
	drawDes(1.333333);
	drawDes(8.0/7.0);
	
	glColor3f(0.2,0.2,0.2);
	drawFilledCircle(l+border+hRad,d+hRad+border,0,hRad) ;	// HOLES
	drawFilledCircle(r-hRad-border,d+hRad+border,0,hRad) ;
	drawFilledCircle(r-hRad-border,u-hRad-border,0,hRad) ;
	drawFilledCircle(l+border+hRad,u-hRad-border,0,hRad) ;
	//printf("((((((((((((((((((((");
	glColor3f(0.2,0.5,0.2);
	
	
	if(data->control == 1)		// now initialize striker and all coins for hitting
	{
		printCoins(data);
		int i;
		if(DEBUG)		
		cout<<"after print coins........."<<endl;
			for (int i = 0; i < 6; i++)
			{
				cout<<i<<" : "<<data->a[i].getVy()<<" "<<data->a[i].getX()<<" "<< data->a[i].getY()<<"  "<<data->scoreA<<data->scoreB<<endl;  
			}
	}
	else if(data->control==0)
	{
		move(data);
		if(DEBUG)		
		cout<<"after move!!!!!!!!!!"<<endl;
			for (int i = 0; i < 6; i++)
			{
				cout<<i<<" : "<<data->a[i].getVy()<<" "<<data->a[i].getX()<<" "<< data->a[i].getY()<<"  "<<data->scoreA<<data->scoreB<<endl; 
			}
	}
	else
	{
	if(DEBUG)		
	cout<<"Error value of control !!";		
	}
	
		
	if(data->control==0)
	{
		move(data);
	}
	if(data->control==1 && (data->arrowRad>=sRad))		// Aiming arrow
	{		
			glColor3f(1,0.3,0);
			//glLineWidth(1.6);
			//cosa=(anglex/(sqrt( anglex*anglex + angley*angley ) ) ) ;
			//sina=(angley/(sqrt( anglex*anglex + angley*angley ) ) ) ;
			
			drawLine(data->a[0].getX(),data->a[0].getY(),0,data->a[0].getX()+data->arrowRad*cos(data->arrowAng),data->a[0].getY()+data->arrowRad*sin(data->arrowAng),0);
			drawLine(data->arrowRad*cos(data->arrowAng)+data->a[0].getX(),data->arrowRad*sin(data->arrowAng)+data->a[0].getY(),0,data->arrowRad*cos(data->arrowAng)+data->a[0].getX()-lArr*(cos(data->arrowAng)*cosb-sin(data->arrowAng)*sinb), \
				data->arrowRad*sin(data->arrowAng)+data->a[0].getY()-lArr*(sin(data->arrowAng)*cosb+cos(data->arrowAng)*sinb),0);		
			drawLine(data->arrowRad*cos(data->arrowAng)+data->a[0].getX(),data->arrowRad*sin(data->arrowAng)+data->a[0].getY(),0,data->arrowRad*cos(data->arrowAng)+data->a[0].getX()-lArr*(cos(data->arrowAng)*cosb+sin(data->arrowAng)*sinb), \
				data->arrowRad*sin(data->arrowAng)+data->a[0].getY()-lArr*(sin(data->arrowAng)*cosb-cos(data->arrowAng)*sinb),0);
			glColor3f(0,0,0);	
			//glLineWidth(1);
}
glPopMatrix();
if(data->turn==0&&data->aii==1)
ai();
drawPoly(r+1.1*border,d+4*border,0,r+2.2*border,d+4*border,0,r+2.2*border,u-4*border,0,r+1.1*border,u-4*border,0);//POWER BAR
output(r+.6*border,d+4*border+12*unit,"P");	
output(r+.55*border,d+4*border+11*unit,"O");
output(r+.5*border,d+4*border+10*unit,"W");
output(r+.6*border,d+4*border+9*unit,"E");
output(r+.6*border,d+4*border+8*unit,"R");
glColor3f(1,1,0);
	drawPoly(r+1.3*border,d+4.2*border,0,r+2*border,d+4.2*border,0,r+2*border,d+4.2*border+data->powH,0,r+1.3*border,d+4.2*border+data->powH,0);
glColor3f(.1,1,1);
drawPoly(l+border+5*unit,u+border+5*unit,0,l+border+21*unit,u+border+5*unit,0,l+border+21*unit,u+border,0,l+border+5*unit,u+border,0);
glColor3f(1,0,0);

drawLine(l+border+13*unit,u+border+5*unit,0,l+border+13*unit,u+border,0);
glColor3f(.1,1,1);
output(l+border+26*unit,u+border+5.6*unit,"POWDER");
output(l+border+24.5*unit,u+border+4.2*unit,"LEAST->");
output(l+border+24.5*unit,u+border+2*unit,"MEDIUM");
output(l+border+24.5*unit,u+border-1*unit,"MAXIMUM");
drawPoly(l+border+30*unit,u+border+5.6*unit,0,l+border+32*unit,u+border+5.6*unit,0,l+border+32*unit,u+border-2.6*border,0,l+border+30*unit,u+border-2.6*border,0);
glColor3f(1,0,0);
drawLine(l+border+30*unit,u+border+2.6*unit,0,l+border+32*unit,u+border+2.6*unit,0);
drawLine(l+border+30*unit,u+border-0.6*unit,0,l+border+32*unit,u+border-0.6*unit,0);
glColor3f(0,0,1);
output(l+border+15*unit,u+border+3*unit,"BLACK - 0");
output(l+border+5*unit,u+border+3*unit,"WHITE - 0");

glFlush();
glFlush();
	glutSwapBuffers();

int n;

 if(data->turn==1&&data->server<=5)
{

//fgets(buffer,255,stdin);
//serverconvert(); 
if(data->server==1)
{
n = write(data->newsockfd,data->a,sizeof(data->a));
}
else
n = write(data->sockfd,data->a,sizeof(data->a));
//printf("AAAAAAAAAAAAAAAAA");   
 //if (n < 0) 
   //      error("ERROR writing to socket");
if(data->a[0].getVx()>10*unit)
data->control=0;//add the code here also



}
	
else if(data->server<=5)
{
if(DEBUG)
printf("PLEASE");
if(data->server==1)
{
//n = write(data->newsockfd1,data->a,sizeof(data->a));
 n = read(data->newsockfd,data->a,sizeof(data->a));
///n = write(data->newsockfd,data->a,sizeof(data->a));

}
else
    n = read(data->sockfd,data->a,sizeof(data->a));
if (n < 0) error("ERROR reading from socket");
   
    //add the code to be added in client here also
   
     if (n < 0) error("ERROR writing to socket");
//printf("assssssssssssssssssss%f %f  %f  %f",a[0].getX(),a[0].getY(),a[0].getVx(),a[0].getVy());

if(data->a[0].getVx()>10*unit||data->a[0].getVy()>10*unit)//put the case that whenever u recieve that that anything changed control changes
data->control=0;


}


	}	
else if(data->just==0&&data->createdby==0)
{	
	glClearColor(1.0, 0.5, .3, 10);
	if(data->startcol==1)
	{
	glColor3f(1.89,.1,1.4);
	
	}	
	else
	glColor3f(.89,.1,0.4);
	
	glPushMatrix ();
	drawPoly(.995,(d+2.045)/2,0,.995,(d+1.85)/2,0,1.39,(d+1.85)/2,0,1.39,(d+2.045)/2,0);
	glColor3f(1,1,0);
	glRasterPos2i((l+r)/2,(d+2)/2);
	
	
	glPopMatrix ();
glPushMatrix ();
/*
if(data->queenCovered)
{
glColor3f(0,1,1);
drawPoly((l+r-.01)/2,(d+u)/2,0,(l+r-.01)/2,(d+u-.45)/2,0,(l+r+.38)/2,(d+u-.45)/2,0,(l+r+.38)/2,(d+u)/2,0);
printf("BINGOOOOOOOO");
sleep(1);
}*/
if(DEBUG)
printf("%dsda\n",data->ss);


	if(data->startcol==2)
	glColor3f(1.89,.1,1.4);
	else
	glColor3f(.89,.1,0.4);
	drawPoly((l+r-.01)/2,(d+1.845)/2,0,(l+r-.01)/2,(d+1.65)/2,0,(l+r+.78)/2,(d+1.65)/2,0,(l+r+.78)/2,(d+1.845)/2,0);
	glColor3f(1,1,0);
	glRasterPos2i(0,.51);
	output((l+r)/2,(d+2)/2-.05, "PLAY");
	glPopMatrix ();
glPushMatrix ();
	if(data->startcol==3)
	glColor3f(1.89,.1,1.4);
	else
	glColor3f(.89,.1,0.4);
	drawPoly((l+r-.01)/2,(d+1.645)/2,0,(l+r-.01)/2,(d+1.45)/2,0,(l+r+.78)/2,(d+1.45)/2,0,(l+r+.78)/2,(d+1.645)/2,0);
	glColor3f(1,1,0);
	//glRasterPos2i((l+r+1.69)/2,(d+1.61)/2);

	output((l+r)/2,(d+1.67)/2, "CREDITS");
glPopMatrix ();
glPushMatrix ();
	if(data->startcol==4)
	glColor3f(1.89,.1,1.4);
	else
	glColor3f(.89,.1,0.4);
	drawPoly((l+r-.01)/2,(d+1.445)/2,0,(l+r-.01)/2,(d+1.25)/2,0,(l+r+.78)/2,(d+1.25)/2,0,(l+r+.78)/2,(d+1.445)/2,0);
glColor3f(1,1,0);
output((l+r)/2,(d+1.47)/2, "RULES");
if(DEBUG)
printf("DADA");	
glPopMatrix ();

glPushMatrix ();
	if(data->startcol==9)
	glColor3f(1.89,.1,1.4);
	else
	glColor3f(.89,.1,0.4);
	drawPoly((l+r-.01)/2,(d+1.245)/2,0,(l+r-.01)/2,(d+1.05)/2,0,(l+r+.78)/2,(d+1.05)/2,0,(l+r+.78)/2,(d+1.245)/2,0);
glColor3f(1,1,0);
output((l+r)/2,(d+1.27)/2, "EXIT");
	output((l+r)/2,(d+1.07)/2, "RESET SERVER");
glPopMatrix ();
}
else if(data->createdby==1)
{
output(0,(d+2)/2+.44, "General International Rules given in Carrom.org have been implemented");
output(0,(d+2)/2+.38, "");
}
else if(data->createdby==2)
{
output((l+r)/2,(d+2)/2+.4, "1. Prof. Kolin Paul");
output((l+r)/2,(d+1.8)/2+.4, "2. Google");
output((l+r)/2,(d+1.6)/2+.4, "3. Wikipedia");
output((l+r)/2,(d+1.4)/2+.4, "4. Mr. Tarun Mangla");
}
else if(data->createdby==4)
{
	data->just=5;
	glColor3f(.89,.1,0.4);
	if(data->startcol==10)
	{
	glColor3f(.89,0,0);
drawPoly((l+r-.01)/2,(d+2.045)/2,0,(l+r-.01)/2,(d+1.85)/2,0,(l+r+1)/2,(d+1.85)/2,0,(l+r+1)/2,(d+2.045)/2,0);
	glColor3f(.89,.1,0.4);
data->players=2;
data->play=true;	
}
	else
	{
drawPoly((l+r-.01)/2,(d+2.045)/2,0,(l+r-.01)/2,(d+1.85)/2,0,(l+r+1)/2,(d+1.85)/2,0,(l+r+1)/2,(d+2.045)/2,0);

	}

drawPoly((l+r-.01)/2,(d+1.645)/2,0,(l+r-.01)/2,(d+1.45)/2,0,(l+r+1)/2,(d+1.45)/2,0,(l+r+1)/2,(d+1.645)/2,0);
drawPoly((l+r-.01)/2,(d+1.845)/2,0,(l+r-.01)/2,(d+1.65)/2,0,(l+r+1)/2,(d+1.65)/2,0,(l+r+1)/2,(d+1.845)/2,0);
drawPoly((l+r-.01)/2,(d+1.445)/2,0,(l+r-.01)/2,(d+1.25)/2,0,(l+r+1)/2,(d+1.25)/2,0,(l+r+1)/2,(d+1.445)/2,0);

	if(data->startcol==11)
	{
	glColor3f(.89,0,0);
drawPoly((l+r-.01)/2,(d+1.845)/2,0,(l+r-.01)/2,(d+1.65)/2,0,(l+r+1)/2,(d+1.65)/2,0,(l+r+1)/2,(d+1.845)/2,0);
	glColor3f(.89,.1,0.4);
data->players=4;
data->play=true;	
}
if(data->startcol==12)
	{
	glColor3f(.89,0,0);
drawPoly((l+r-.01)/2,(d+1.645)/2,0,(l+r-.01)/2,(d+1.45)/2,0,(l+r+1)/2,(d+1.45)/2,0,(l+r+1)/2,(d+1.645)/2,0);
	glColor3f(.89,.1,0.4);
data->players=2;
data->play=true;	
}
if(data->startcol==13)
	{
	glColor3f(.89,0,0);
drawPoly((l+r-.01)/2,(d+1.645)/2,0,(l+r-.01)/2,(d+1.45)/2,0,(l+r+1)/2,(d+1.45)/2,0,(l+r+1)/2,(d+1.645)/2,0);
	glColor3f(.89,.1,0.4);
data->aii=1;
data->players=2;
data->play=true;	
}
if(data->startcol==14)
	{
	glColor3f(.89,0,0);
drawPoly((l+r-.01)/2,(d+1.645)/2,0,(l+r-.01)/2,(d+1.45)/2,0,(l+r+1)/2,(d+1.45)/2,0,(l+r+1)/2,(d+1.645)/2,0);
	glColor3f(.89,.1,0.4);

data->players=2;
data->play=true;	
}
glColor3f(1,1,0);	
output((l+r)/2,(d+1.9)/2, "2 PLAYER OFFLINE");
output((l+r)/2,(d+1.7)/2, "4 PLAYER OFFLINE");
output((l+r)/2,(d+1.5)/2, "AI vs AI ONLINE ");
output((l+r)/2,(d+1.3)/2, "2 PLAYER ONLINE ");
//output((l+r)/2,(d+2)/2+.4, "RULES");
}	
// Flush the pipeline. 

}
if(data->finish==1)
{
int j=data->scoreA;
if(data->scoreA>data->scoreB)
output((l+r)/2,(d+1.9)/2, "PLAYER 1 (WHITE) WINS");
else
output((l+r)/2,(d+1.9)/2, "PLAYER 2 (BLACK) WINS");
}
if(DEBUG)
printf("DADA");
	glutSwapBuffers();	
	
	glutPostRedisplay();
	
}

