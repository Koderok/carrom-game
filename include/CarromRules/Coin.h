#ifndef _Coin_h_included_
#define _Coin_h_included_

class Coin
{
	float x,y,vx,vy;
	int f,colour;	//colour : 0->white, 1->black, 2->red, 3->Striker's colour
	public :
	Coin();						// 	EMPTY
	Coin(float X,float Y,float Vx,float Vy);	// 	CONSTRUCTOR
	void init(float X,float Y,float Vx,float Vy);
	void init(float X,float Y,float Vx,float Vy,int col);
	void setPos(float X,float Y);
	void setX(float X);
	void setY(float Y);
	void setVx(float Vx);
	void setVy(float Vy);
	void setF(int ff);
	void setColour(int col);
	void setVel(float Vx,float Vy);
	float getX();
	float getY();
	float getVx();
	float getVy();
	int getColour();
	int getF();
};
#endif
