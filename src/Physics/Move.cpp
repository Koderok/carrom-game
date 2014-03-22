#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "../../include/Physics/Physics.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/CarromRules/RulesImplement.h"
void move(common *data)
{
	int i=0,j=0,colliding;
	float big=0,magV=0;
	printCoins(data);	
	
	if(data->control == 1)
		return;
	Coin change[6];
	for(i=0;i<6;i++)				// Initialize changed[] elements to "non-changed"
	{
		change[i].setF(0);
		change[i].init(data->a[i].getX(), data->a[i].getY(), data->a[i].getVx(), data->a[i].getVy());	
		if(data->a[i].getX()==7||data->a[i].getX()<0)
		data->a[i].setVel(0,0);		
			
	}	
	for(i=0;i<6;i++)				// Loop for checking collisions of coin all 6 values of i
	{
	
		/*Look at the following code. Remove the redundant cases for speeding up*/
		
		//if((data->a[i].getVx() == 0 && data->a[i].getVy() == 0) && change[i].getF()==0 && i!=0) 	// skip the stationary && unchanged(non-colliding) coins 
		//	continue;
		
		
		for(j=0;j<6;j++)
		{
			if(DEBUG)
				printf("starting to check %d's collision with %d\n",i,j);
			
			if(j==i)
				continue;
			if(DEBUG)
				printf("check coin-coin collision for coin %d with %d\n",i,j);
			if(i!=0 && j!=0)
				if( (distance(data->a[j].getX(),data->a[i].getX(),data->a[j].getY(),data->a[i].getY()) <= 2*cRad) && (approaching(j,i,data)))
					colliding=1;
				else 
					colliding=0;
			else
				if( (distance(data->a[j].getX(),data->a[i].getX(),data->a[j].getY(),data->a[i].getY()) <= hRad+cRad) && (approaching(j,i,data)))				
					colliding=1;
				else 
					colliding=0;
			if( colliding )		// COIN-COIN COLLISION
			{
				if(DEBUG)
					printf("\n\n\n\n\nt ***********************coin %d collided with coin %d\n",i,j);		
				change[i].setF(1);											//Mark both i and j as changed(colliding)
				change[j].setF(1);
				
				big= (data->a[j].getVx()-data->a[i].getVx()) * (data->a[j].getX()-data->a[i].getX()) ;  
				big+= (data->a[j].getVy()-data->a[i].getVy()) * (data->a[j].getY()-data->a[i].getY()) ;
				big/=(data->a[j].getX()-data->a[i].getX())*( data->a[j].getX()-data->a[i].getX()) + \
				(data->a[j].getY()-data->a[i].getY())*( data->a[j].getY()-data->a[i].getY()) ;
			
				
				//store state of colliding coin i in change[i] for later assignment into data->a[i]
				//change[i].init(data->a[i].getX(), data->a[i].getY(), data->a[j].getVx(), data->a[j].getVy());	//store in change[] after collision
				
				change[i].init(data->a[i].getX(), data->a[i].getY(), data->a[i].getVx()+big*(data->a[j].getX()-data->a[i].getX()), data->a[i].getVy()+big*(data->a[j].getY()-data->a[i].getY()));
				
				if(DEBUG)
					printf("collision and updating change for coin %d\n",i);
			}						// COIN-COIN COLLISION CONDITION ENDS
			if(DEBUG)
				printf("inside coin-coin loop for coin %d",i);
		}
		if(DEBUG)
			printf("All coin-coin collisions have been checked for coin %d",i);
		
		
		
	
		if( (data->a[i].getY() <= d+border+cRad-data->a[i].getVy()*dt) && data->a[i].getVy()<0 )	// LOWER WALL
		{	
			data->a[i].setVy(-data->a[i].getVy());
		}
		else if( (data->a[i].getX() >= r-border-cRad-data->a[i].getVx()*dt) && data->a[i].getVx()>0 )	//RIGHT WALL
		{
			data->a[i].setVx(-data->a[i].getVx());
		}
		else if( (data->a[i].getY() >= u-border-cRad-data->a[i].getVy()*dt) && data->a[i].getVy()>0 )	//UPPER WALL
		{	
			data->a[i].setVy(-data->a[i].getVy());
		}
		else if( (data->a[i].getX() <= l+border+cRad-data->a[i].getVx()*dt) && data->a[i].getVx()<0 )	//LEFT WALL
		{
			data->a[i].setVx(-data->a[i].getVx());
		}
		if(DEBUG)
				printf("All balls have been examined for collisions..move will now exit %f %f\n",data->a[0].getVy(),data->a[1].getVy());
	}//loop for checking collisions with coin 'i' ends
	
	for(j=0;j<6;j++)
		{	
			if(DEBUG)
				printf("\n\tupdating loop before : j=%d , change: %f,%f	%f,%f",j,change[j].getX(),change[j].getY(),change[j].getVx(),change[j].getVy()); 
			
			if(DEBUG)
				printf("\n\tupdating loop before : j=%d , a : %f,%f	%f,%f",j,data->a[j].getX(),data->a[j].getY(),data->a[j].getVx(),data->a[j].getVy()); 
			
			if(change[j].getF() == 0 )
			{
					if(mod(data->a[j].getVx()) <=unit/10 && mod(data->a[j].getVy()) <=unit/10 ) 
					{	
						//printf("%f %f\n",mod(data->a[j].getVx()),mod(data->a[j].getVy()));
						data->a[i].setVel(0,0);
						continue;
					}
					else
					{
						magV=sqrt(data->a[j].getVx()*data->a[j].getVx() +data->a[j].getVy()*data->a[j].getVy() ) ;
						data->a[j].setVel(data->a[j].getVx()+(data->acc*data->a[j].getVx()*dt)/magV , data->a[j].getVy()+(data->acc*data->a[j].getVy()*dt)/magV );
						data->a[j].setPos(data->a[j].getX()+data->a[j].getVx()*dt,data->a[j].getY()+data->a[j].getVy()*dt);
						//data->a[j].setPos(data->a[j].getX()+data->a[j].getVx()*dt+(data->acc*data->a[j].getVx()*dt*dt)/(2*magV), \
						data->a[j].getY()+data->a[j].getVy()*dt+(data->acc*data->a[j].getVy()*dt*dt)/(2*magV) );//Translate non-colliding coins
						continue;
					}
			}			
			if(DEBUG)
				printf("updating changes from change[] for coin %d\n",j);	
//			data->a[j].init(change[j].getX() + 39*change[j].getVx()*dt, change[j].getY() + 39*change[j].getVy()*dt, change[j].getVx(), change[j].getVy() );	//Change //collided coins
			
			
			if(DEBUG)
				printf("big == %f\n",big);
			
			//data->a[j].init(change[j].getX() , change[j].getY() , change[i].getVx()+big*(change[j].getX()-change[i].getX()), \
								change[i].getVy()+big*(change[j].getX()-change[i].getX()) );
			
			data->a[j].init(change[j].getX() , change[j].getY() , change[j].getVx(), change[j].getVy() );	//Update colliding coins
			
			if(DEBUG)
				printf("\n\tupdating loop after : j=%d , change: %f,%f	%f,%f",j,change[j].getX(),change[j].getY(),change[j].getVx(),change[j].getVy()); 
			
			if(DEBUG)
				printf("\n\tupdating loop after : j=%d , a : %f,%f	%f,%f",j,data->a[j].getX(),data->a[j].getY(),data->a[j].getVx(),data->a[j].getVy()); 
			
			
		}
	if(DEBUG)
			printf("change has been used for coin %d",i);	
	if(data->server!=89&&data->a[0].getVx()<=.51*unit&&data->a[0].getVy()<=.51*unit&&data->control==0&&data->a[0].getVx()>=-.51*unit&&data->a[0].getVy()>=-.51*unit)//add that if every ball stops then control=1
		{
if(data->a[1].getVx()<=.5*unit&&data->a[1].getVy()<=.5*unit&&data->a[1].getVx()>=-.51*unit&&data->a[1].getVy()>=-.51*unit){
if(data->a[2].getVx()<=.5*unit&&data->a[2].getVy()<=.5*unit&&data->a[2].getVx()>=-.51*unit&&data->a[2].getVy()>=-.51*unit){
if(data->a[3].getVx()<=.5*unit&&data->a[3].getVy()<=.5*unit&&data->a[3].getVx()>=-.51*unit&&data->a[3].getVy()>=-.51*unit){
if(data->a[4].getVx()<=.5*unit&&data->a[4].getVy()<=.5*unit&&data->a[4].getVx()>=-.51*unit&&data->a[4].getVy()>=-.51*unit){
if(data->a[5].getVx()<=.5*unit&&data->a[5].getVy()<=.5*unit&&data->a[5].getVx()>=-.51*unit&&data->a[5].getVy()>=-.51*unit){

	rulesImplement(data);
		if(data->continueTurn&&data->players==2)		//change turn if continueTurn is 1
				{data->turn=(data->turn+1)%2;
					data->side=(data->side+1)%2;			
				}
			else if(data->continueTurn&&data->players==2)		//
			{
			data->turn=(data->turn+2)%4;	
			data->side=(data->side+1)%2;
			if(data->side==0)
			data->side=2;			
			}	
			data->arrowRad=2*unit;data->arrowAng=PI/2;
		
data->control=1;
if(data->server==1)
data->a[0].init((l+r)/2,d+pDist1+pWidth/2,0,0);
else if(data->server==0)
data->a[0].init((l+r)/2,u-pDist1-pWidth/2,0,0);
//data->turn=(data->turn+1)%2;
}}}}}
else
{
if(DEBUG)
printf("ADSSSSSSS");	
}}				
	
}
