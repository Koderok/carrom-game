#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/Physics/Physics.h"
#include <iostream>
using namespace std;

void placeAtCentre(int coinNum, common *data)
{
	data->a[coinNum].setPos((l+r)/2,(u+d)/2);
	int safe = 0,i;
	while(!safe)
	{	
		safe=1;
		for (int i = 1; i < 6; i++)
		{
			if(i==coinNum)
				continue;
			if(distance(data->a[i].getX(),data->a[coinNum].getX(),	\
				data->a[i].getY(),data->a[coinNum].getY()) < 2*cRad )
				{
					safe=0; //Not safe
					if(DEBUG)
						cout<<"Coin "<<i<<" is creating hinderance"<<endl;
				}
		}
		if(!safe)
		data->a[coinNum].setPos(data->a[coinNum].getX(),data->a[coinNum].getY()+unit/10);
	}
	
}
