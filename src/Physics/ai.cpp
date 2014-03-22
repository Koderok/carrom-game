#include "../../include/AI/ai.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/Physics/Physics.h"
#include<stdio.h>
#include<math.h>
void ai()
{
int j;
double corr,sq;
if(data->a[1].getX()!=7||data->a[1].getX()!=7)
j=1;
else if(data->a[2].getX()!=7||data->a[2].getX()!=-1)
j=2;
else
j=3;
float x,y;
float qw;
if(data->level==1)
corr=-.0015;
else if(data->level==2)
corr=-.0001;
else
corr=0;

if(data->a[j].getX()<=(l+r)/2&&data->control==1&&data->a[j].getY()>data->a[0].getY())
{
sq=sqrt((u-border-hRad-data->a[j].getY())*(u-border-hRad-data->a[j].getY())+(l+border+hRad-data->a[j].getX())*(l+border+hRad-data->a[j].getX()));
x=data->a[j].getX()-(hRad+cRad)* (l+border+hRad-data->a[j].getX())/sq-corr;//costheta
y=data->a[j].getY()-(hRad+cRad)*(u-border-hRad-data->a[j].getY())/sq; //sintheta
qw=sqrt((x-(r-border-8*hRad))*(x-(r-border-8*hRad))+(y-data->a[0].getY())*(y-data->a[0].getY()));
data->a[0].init(r-border-8*hRad,data->a[0].getY(),2.6*(u-d-8.4*border)*(x-(r-border-8*hRad))/qw,2.6*(u-d-8.4*border)*(y-data->a[0].getY())/qw);
}
else if(data->control==1&&data->a[j].getY()>data->a[0].getY())
{
sq=sqrt((u-border-hRad-data->a[j].getY())*(u-border-hRad-data->a[j].getY())+(r-border-hRad-data->a[j].getX())*(r-border-hRad-data->a[j].getX()));
x=data->a[j].getX()-(hRad+cRad)* (r-border-hRad-data->a[j].getX())/sq-.001;//costheta
y=data->a[j].getY()-(hRad+cRad)*(u-border-hRad-data->a[j].getY())/sq; //sintheta
qw=sqrt((x-(r-border-8*hRad))*(x-(r-border-8*hRad))+(y-data->a[0].getY())*(y-data->a[0].getY()));
data->a[0].init(r-border-8*hRad,data->a[0].getY(),2.6*(u-d-8.4*border)*(x-(r-border-8*hRad))/qw,2.6*(u-d-8.4*border)*(y-data->a[0].getY())/qw);
}
else if(data->control==1)
{
data->a[0].init(r-border-8*hRad,data->a[0].getY(),2.6*(u-d-8.4*border)*(x-(r-border-8*hRad))/qw,2.6*(u-d-8.4*border)*(y-data->a[0].getY())/qw);
}
data->control=0;
move(data);
}
