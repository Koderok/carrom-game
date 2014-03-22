#include "../../include/Networking/Networking.h"
void error(const char *msg)
{
  perror(msg);
  exit(1);
}

void network()
{
  int n;
  if(turn==1)
  {
    //fgets(buffer,255,stdin);
    //serverconvert(); 
    n = write(newsockfd,a,sizeof(a));

    if (n < 0) 
     error("ERROR writing to socket");

  }	
  else if(turn==0)
  {
    printf("TURN CHANGES");
    n = read(newsockfd,a,sizeof(a));
    if (n < 0) 
      error("ERROR reading from socket");

    //add the code to be added in client here also

    if (n < 0) error("ERROR writing to socket");

    if(a[0].getVx()>10*unit||a[0].getVy()>10*unit)//put the case that whenever u recieve that that anything changed control changes
      control=0;
  }

}
