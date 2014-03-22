#include <math.h>
#include<stdio.h>
#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"

void home(common *data)
{
	/*
	data->a[0].init(l+15*unit,d+pDist1+pWidth/2,0,30*unit);
	data->a[1].init((l+r)/2,(u+d)/2,0,0);
	data->a[2].init((l+r)/2-1*sRad,(u+d)/2-3*sRad,0,0);
	data->a[3].init((l+r)/2-1*sRad,(u+d)/2+4*sRad,0,0);
	data->a[4].init((l+r)/2+1*sRad,(u+d)/2-3*sRad,0,0);
	data->a[5].init((l+r)/2+1*sRad,(u+d)/2+4*sRad,0,0);
	*/
	/*
	data->a[0].init((l+r)/2+(sRad+cRad)*(r-l)/sqrt((r-l)*(r-l)+(u-d)*(u-d)),d+pDist1+pWidth/2,0,30*unit,3);
	data->a[1].init((l+r)/2,(u+d)/2,0,0,2);
	data->a[2].init((l+r)/2-3*sRad,d+pDist1+pWidth/2,0,0,0);
	data->a[3].init(-10,-10,0,0,0);
	data->a[4].init((l+r)/2+3*sRad,(u+d)/2+4*sRad,0,0,1);
	data->a[5].init(-10,-10,0,0,1);
	*/
	/*
	data->a[0].init(l+15*unit,d+pDist1+pWidth/2,0,30*unit,3);
	data->a[1].init((l+r)/2,(u+d)/2,0,0,2);
	data->a[2].init((l+r)/2-1.42*cRad,(u+d)/2-1.42*cRad,0,0,0);
	data->a[3].init((l+r)/2-1.42*cRad,(u+d)/2+1.42*cRad,0,0,0);
	data->a[4].init((l+r)/2+1.42*cRad,(u+d)/2-1.42*cRad,0,0,1);
	data->a[5].init((l+r)/2+1.42*cRad,(u+d)/2+1.42*cRad,0,0,1);
	*/
	printf("QQQQQQQQQQQS");
	data->a[0].init(l+15*unit,d+pDist1+pWidth/2,0,30*unit,3);
	data->a[1].init((l+r)/2,(u+d)/2,0,0,2);
	data->a[2].init((l+r)/2,(u+d)/2-2.1*cRad,0,0,0);
	data->a[3].init((l+r)/2-2.1*cRad,(u+d)/2,0,0,0);
	data->a[4].init((l+r)/2,(u+d)/2+2.1*cRad,0,0,1);
	data->a[5].init((l+r)/2+2.1*cRad,(u+d)/2,0,0,1);
	
	/*data->a[0].init(l+15*unit,d+pDist1+pWidth/2,0,30*unit,3);
	data->a[1].init((l+r)/2-11,(u+d)/2,0,0,2);
	data->a[2].init((l+r)/2,(u+d)/2,0,0,0);
	data->a[3].init((l+r)/2-2.001*sRad,(u+d)/2+1.001*sRad,0,0,0);
	data->a[4].init((l+r)/2+2.001*sRad,(u+d)/2-1.001*sRad,0,0,1);
	data->a[5].init((l+r)/2+11.001*sRad,(u+d)/2+1.001*sRad,0,0,1);
	*/
	data->finalStopped=0;
}
