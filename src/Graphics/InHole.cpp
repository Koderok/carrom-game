#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/Physics/Physics.h"

int inHole(float x,float y )
{
	if(distance(x,l+border+hRad,y,d+border+hRad) <= hRad )
		return 1;				//coin is in bottom left hole
	if(distance(x,r-border-hRad,y,d+border+hRad) <= hRad )
		return 1;				//coin is in bottom right hole	
	if(distance(x,r-border-hRad,y,u-border-hRad) <= hRad )
		return 1;				//coin is in top right hole	
	if(distance(x,l+border+hRad,y,u-border-hRad) <= hRad )
		return 1;				//coin is in top left hole		
}
