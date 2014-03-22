#ifndef _Graphics_h_included_
#define _Graphics_h_included_
#include "../Common/Common.h"
#include<string.h>
void myKeyboardFunc( unsigned char key, int x, int y );
void mySpecialKeyFunc(int key,int x , int y);
void output(float x, float y, char *string);
void output1(int x, int y, int string);
void home(common *data) ;
void drawScene(void);
void initRendering();
void resizeWindow(int w, int h);


int inHole(float x,float y );

void mouse(int button, int state, int x, int y) ;
void motion(int x, int y);
void motionPassive(int x, int y);
void entry(int state);

void printCoins(common *data);
void placeAtCentre(int coinNum, common *data) ; 

void drawLine(float x1,float y1,float z1,float x2,float y2,float z2);
void drawPoly(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4);
void drawTri(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3);
void drawFilledCircle(float cx,float cy,float cz,float radius);
void drawCircle(float cx,float cy,float cz,float radius);
void drawArc(float cx,float cy,float cz,float radius,int num);
void drawDes(float num);

#endif




