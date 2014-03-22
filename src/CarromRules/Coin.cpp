#include "../../include/CarromRules/Coin.h"

Coin :: Coin(){}

Coin :: Coin(float X,float Y,float Vx,float Vy)
{
	x=X;
	y=Y;
	vx=Vx;
	vy=Vy;
}

void Coin :: init(float X,float Y,float Vx,float Vy)
{
	x=X;
	y=Y;
	vx=Vx;
	vy=Vy;
}

void Coin :: init(float X,float Y,float Vx,float Vy,int col)
{
	x=X;
	y=Y;
	vx=Vx;
	vy=Vy;
	colour=col;
}

void Coin ::setPos(float X,float Y)
{
	x=X;y=Y;
}		

void Coin :: setX( float X)
{ 	
	x=X;
}	

void Coin :: setY( float Y)
{ 	
	y=Y;
}
	
void Coin :: setVx( float Vx)
{ 	
	vx=Vx;
}

void Coin :: setVy( float Vy)
{ 	
	vy=Vy;
}
	
void Coin :: setF(int ff)
{
	f=ff;
}	
	
void Coin ::  setVel(float Vx,float Vy)
{
	vx=Vx; vy=Vy;
}

void Coin :: setColour(int col)
{
	colour = col ;
}

float Coin ::  getX()
{
	return x;
}

float Coin :: getY()
{
	return y;
}	
	
float Coin :: getVx()
{
	return vx;
}

float Coin :: getVy()
{	
	return vy;
}

int Coin::getF()
{
	return f;
}

int Coin :: getColour()
{
	return colour ;
}

