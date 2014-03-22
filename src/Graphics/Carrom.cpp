#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <sys/types.h>
#include <netdb.h> 
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

#include <GL/glut.h>	// OpenGL Graphics Utility Library
#include <math.h>
#include "../../include/Graphics/Graphics.h"
#include "../../include/Common/Common.h"
#include "../../include/CarromRules/Board.h"
#include "../../include/Physics/Physics.h"
#include "../../include/Networking/Networking.h"
#include <iostream>
using namespace std;

// Main routine
// Set up OpenGL, define the callbacks and start the main loop
void error(const char *msg)
{
    perror(msg);
    exit(1);
}
int main( int argc, char** argv )
{
	data->acc=-13*unit;	
	data->play=false;	
	data->lbuttonDown=false;
	data->mouseflag=0;
	data->powInc=1;
	data->flag1=0;
	data->aii=0;
	data->control=1;
	data->arrowAng=PI/2;
	data->arrowRad=2*unit;
	data->powH=0;
	data->just=1;
	data->tim=0;
	data->createdby=0;
	data->startcol=0;
	data->continueTurn=1;
	data->side=1;
	data->scoreA=0;
	data->scoreB=0;
	data->foulA=0;
	data->foulB=0;
	data->queenCovered=0;
	data->players=2;
	data->ss=0;
int option,pl;
printf("To play locally enter any negative number \n1.) enter 1 for server\n2.) enter 2 for a client\n");
scanf("%d",&option);

if(option<0)
{
printf("Against whom you want to play\n 1.)Player 2.)Computer\n");
scanf("%d",&pl);
if(pl==2)
{
int le;
data->aii=1;
printf("What level AI do you want to play against \n 1.)Easy 2.) Medium 3.) Hard\n");
scanf("%d",&le);
data->level=le;
}
else
data->aii=0;
}
if(option==1)
{
data->turn=1;
//glutInit(&argc,argv);

data->server=1;}
else if(option==2)
data->server=0;
else
data->server=89;
if(data->server==1)
{
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     
     data->sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (data->sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
	char ho[256];     
	printf("Please enter the port");
	scanf("%s",&ho);
	data->portno = atoi(ho);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(data->portno);
     if (bind(data->sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(data->sockfd,5);
     data->clilen= sizeof(cli_addr);
     data->newsockfd = accept(data->sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &data->clilen);
 
data->turn=1;
 

}
else if(data->server==0)
{
 struct sockaddr_in serv_addr;
    struct hostent *server;
char port[256],host[256];
int portno;
printf("Please enter the port name");
   scanf("%s",port);
printf("Please enter the ip/localhost");
scanf("%s",host);
    portno = atoi(port);
    server=0;
data->sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (data->sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
  
  bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(data->sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
data->turn=0;
}


// The
home(data);
	if(DEBUG)
		cout<<"home was called"<<data->a[0].getX()<<" "<<data->a[0].getY()<<endl ;
	glutInit(&argc,argv);
	// The image is not animated so single buffering is OK. 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

	// Window position (from top corner), and size (width and hieght)
	glutInitWindowPosition( 20, 60 );
	glutInitWindowSize(700,700 );
if(data->server==1)	
glutCreateWindow( "Carrom server" );
else if(data->server==0)
glutCreateWindow( "Carrom client" );
else
glutCreateWindow( "Single Computer" );
	//AI() ;


	// Set up callback functions for key presses
	glutKeyboardFunc( myKeyboardFunc );			// Handles "normal" ascii symbols
	glutSpecialFunc( mySpecialKeyFunc );		// Handles "special" keyboard keys

	// Set up the callback function for resizing windows
	glutReshapeFunc( resizeWindow );

	// Call this for background processing
	// glutIdleFunc( myIdleFunction );


	// call this whenever window needs redrawing
	glutDisplayFunc( drawScene );

	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutPassiveMotionFunc(motionPassive);
	glutEntryFunc(entry);

	if(DEBUG)
		cout<<"before main loop"<<endl ;

	if(DEBUG)
		cout<<"after returning in main  loop"<<endl ;
	

	// Start the main loop.  glutMainLoop never returns.
	glutMainLoop( );
	
	if(DEBUG)
		cout<<"before returning from main"<<endl ;
	

	return(0);	// This line is never reached.
}

