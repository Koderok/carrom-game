#ifndef _Common_h_included_
#define _Common_h_included_

#include "../CarromRules/Coin.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
typedef struct common
{
	bool lbuttonDown,play;
	double X,Y,finish,escape;
	int st,s1,s2,ss,aii;
	float w1,w2,acc;
	int turn,just,num;
	float tim,startcol,createdby;
	int mouseflag,powInc;
	double conversionx,conversiony;
	int continueTurn;
	int flag1,final, finalStopped,side,queenCovered;
	int control,scoreA,scoreB,foulA,foulB;
	float arrowAng,arrowRad;
	float powH,level;
	int sockfd,sockfd1, newsockfd, portno;
     socklen_t clilen;
	int server,players;	
	Coin a[6];
}common;

extern common *data ;

void initData() ;

#endif
