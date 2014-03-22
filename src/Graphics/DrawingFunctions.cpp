#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/Physics/Physics.h"

void drawLine(float x1,float y1,float z1,float x2,float y2,float z2)
{
	glBegin(GL_LINES);
	glVertex3f(x1,y1,z1);
	glVertex3f(x2,y2,z2);
	glEnd();
}

void output(float x, float y, char *string)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
  }
}
void output1(int x, int y, int string)
{
  int len, i;

  glRasterPos2f(x, y);
   for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string);
  }
}
void drawPoly(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4)
{
	glBegin(GL_POLYGON);
	glVertex3f(x1,y1,z1);
	glVertex3f(x2,y2,z2);
	glVertex3f(x3,y3,z3);
	glVertex3f(x4,y4,z4);
	glEnd();
}

void drawTri(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3)
{
	glBegin(GL_POLYGON);
	glVertex3f(x1,y1,z1);
	glVertex3f(x2,y2,z2);
	glVertex3f(x3,y3,z3);
	glEnd();
}

void drawFilledCircle(float cx,float cy,float cz,float radius)
{
	float delta_theta = 0.4;
	glBegin( GL_POLYGON ); 
	for( float angle = 0; angle < 2*PI; angle += delta_theta )
	glVertex3f(cx+ radius*cos(angle),cy+ radius*sin(angle), cz );
	glEnd();
}

void drawCircle(float cx,float cy,float cz,float radius)
{
	int NUM_LINES = 77;
	glBegin( GL_LINE_LOOP );
	for(int i=0;i<NUM_LINES;i++)
	glVertex3f(cx+ radius * cos(i*2*PI/NUM_LINES),cy + radius* sin(i*2*PI/NUM_LINES),cz) ;
	glEnd();
}	

void drawArc(float cx,float cy,float cz,float radius,int num)
{
	int NUM_LINES = 77;
	glBegin( GL_LINE_STRIP );
	for(int i=0;i<NUM_LINES;i++)
	glVertex3f(cx+ radius * cos(-PI/2+num*PI/2+ i*1.5*PI/NUM_LINES),cy + radius* sin(-PI/2+num*PI/2+i*1.5*PI/NUM_LINES),cz) ;
	glEnd();	
}

void drawDes(float num)
{
	int NUM_LINES = 77,i;
	glBegin( GL_POLYGON );
	//glVertex3f((r+l)/2+ temp2 * cos(2*PI/num+ i*0.25*PI/NUM_LINES),(u+d)/2 + temp2* sin(2*PI/num+i*0.25*PI/NUM_LINES),0);
	for( i=0;i<NUM_LINES;i++)
	glVertex3f((r+l)/2+ temp1 * cos(2*PI/num+ i*0.25*PI/NUM_LINES),(u+d)/2 + temp1* sin(2*PI/num+i*0.25*PI/NUM_LINES),0) ;

	glVertex3f((r+l)/2+ temp2 * cos(2*PI/num+ i*0.25*PI/NUM_LINES),(u+d)/2 + temp2* sin(2*PI/num+i*0.25*PI/NUM_LINES),0);
	glEnd();	
	i=0;
	glColor3f(1,0.9,0.9);
	glBegin( GL_POLYGON );
	glVertex3f((r+l)/2+ temp2 * cos(2*PI/num+ i*0.25*PI/NUM_LINES),(u+d)/2 + temp2* sin(2*PI/num+i*0.25*PI/NUM_LINES),0);
	for( i=0;i<NUM_LINES;i++)
	glVertex3f((r+l)/2+ temp1 * cos(2*PI/num+ i*0.25*PI/NUM_LINES),(u+d)/2 + temp1* sin(2*PI/num+i*0.25*PI/NUM_LINES),0) ;

	//glVertex3f((r+l)/2+ temp2 * cos(PI/2+ i*0.25*PI/NUM_LINES),(u+d)/2 + temp2* sin(PI/2+i*0.25*PI/NUM_LINES),0);
	glEnd();
	glColor3f(0,0,0);
}	
