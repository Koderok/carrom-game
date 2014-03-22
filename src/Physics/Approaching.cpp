#include "../../include/Physics/Physics.h"
#include "../../include/Common/Common.h"

int approaching(int i,int j,common *data)		// returns 1 if coin i and j are approaching or are stat wrt each other 
{
	if( (( (data->a[i].getX()-data->a[j].getX()) * (data->a[i].getVx()-data->a[j].getVx()) ) ) +  \
	    (( (data->a[i].getY()-data->a[j].getY()) * (data->a[i].getVy()-data->a[j].getVy()) ) ) <= 0 )
	{
		return 1 ;
	}
	else return 0;
	
}
