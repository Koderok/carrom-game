//#include "Coin.h"
#include "Carrom.h"
#include <stdio.h>
#include <iostream>
using namespace std ;



void AI()
{	
	if(DEBUG == 1)
		cout<<"AI starts "<<endl ;
	
	float holeDistances[6][4] ;
	int i=0,j=0;
	for(i=0;i<6;i++)
	{
			for(j=0;j<4;j++)
			{
				holeDistances[i][j]= distanceFromHole(a[i].getX(),a[i].getY(),j);
			}
	}
	
	for(i=0;i<6;i++)
	{
			for(j=0;j<4;j++)
			{
				cout<<holeDistances[i][j]<<"  ";
			}
			cout<<endl;
	}
}
