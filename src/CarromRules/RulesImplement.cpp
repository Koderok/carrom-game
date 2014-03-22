#include "../../include/CarromRules/RulesImplement.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
#include <iostream>
using namespace std;

void rulesImplement(common *data)
{
	int n = (data->side==1)?-1:1; //x=-1 if side is 1 , 1 if 2
	int c1 = (data->side==1)?2:4; //c1=2 if side is 1 , 4 if 2
	int c2 = (data->side==1)?3:5; //c2=3 if side is 1 , 5 if 2
	int d1 = (data->side==1)?4:2; //d1=4 if side is 1 , 2 if 2
	int d2 = (data->side==1)?5:3; //d2=5 if side is 1 , 3 if 2
	data->continueTurn=1;//By default, the turn should pass on to next player
	
	//If neither of the sides have yet acquired the queen
	if((data->a[1].getY()!=7 && data->a[1].getY()!=-7)) 
	{
		
		//cout<<"Queen not acquired yet"<<endl ;
		
		//if queen is sunk by either side in this turn or in previous turn
		if(data->a[1].getX()==-1 || \
		(data->a[1].getY() == 0 && data->a[1].getX()==7))
		{		
				cout<<"Queen sunk"<<endl;
				
				//if own coin is sunk, the side acquires queen
				if(data->a[c1].getX()==-1 || data->a[c2].getX()==-1)
				{
					cout<<"Queen acquired!!!!!!!"<<endl;
					
					data->queenCovered=data->side;
					data->a[1].setPos(7,7*n);//Queen acquired
					data->continueTurn=0;
				}
				else//This means our coin was not sunk after sinking queen
				{
					/*if queen was sunk in this chance OR queen was sunk in
					previous turn and other coin sunk in this turn,then 
					continue turn*/
					
					//cout<<"Coin not sunk with queen"<<endl;
					
					if(data->a[1].getX()==-1 || data->a[d1].getX()==-1 || data->a[d2].getX()==-1)
							data->continueTurn=0;
					else
					{
						//cout<<"Queen was sunk in previous turn; not acquired in this turn"<<endl; 
						
						data->continueTurn=1;
					}
					
					/*Set queen position to centre of board if it was sunk in
					 * previous chance else set it to (7,0) */
					if(data->a[1].getX()==-1)
					{	
						//cout<<"Queen sunk in this turn without being acquired"<<endl;
						
						data->a[1].setPos(7,0);
					}
					else
					{
						cout<<"Queen has to be returned"<<endl;
						
						placeAtCentre(1,data);
					}		
				}
		}
	}
	
	//Now queen is on the board with other pieces
	
	if(data->a[c1].getX()==-1)//Own coin sunk
	{
		cout<<"CONGRATS !! You sunk a coin.."<<endl;
		
		int owing=0;
		data->a[c1].setPos(7,5*n);
		data->continueTurn=0;
		//Place this coin at centre if already a coin was owed
		if(data->side==1)
		{
			if(data->foulA<0)
			{
				placeAtCentre(c1,data);
				data->foulA++;
				owing=1;
			}
		}
		else
		{
			if(data->foulB<0)
			{
				placeAtCentre(c1,data);
				data->foulB++;
				owing=1;
			}
		}
		if(!owing && data->queenCovered)
		{
			if(data->a[c2].getY()==5*n)//other coin also covered
			{
				cout<<"CONGRATS!!You won the board..";
				data->finish=1;				
				if(data->side==1)
				{
					if(data->queenCovered==1)
						data->scoreA+=3;
					if(data->a[d1].getY()==5*n*(-1)	|| data->a[d2].getY()==5*n*(-1) )
					{
						data->scoreA+=1;
					}
					else
						data->scoreA+=2;
				}
				else
				{
					if(data->queenCovered==2)
						data->scoreB+=3;
					if(data->a[d1].getY()==5*n*(-1)	|| data->a[d2].getY()==5*n*(-1) )
					{
						data->scoreB+=1;
					}
					else
						data->scoreB+=2;
				}
			}
		}
		if(!data->queenCovered && data->a[c2].getY()==5*n)
		{
			cout<<"You lose the board"<<endl;
			data->finish=1;
			if(data->side==1)
				data->scoreA-=3;
			else
				data->scoreB-=3;
		}
	}

	if(data->a[c2].getX()==-1)//Own coin sunk
	{
		cout<<"CONGRATS !! You sunk a coin..."<<endl;
		
		int owing=0;
		data->a[c2].setPos(7,5*n);
		data->continueTurn=0;
		//Place this coin at centre if already a coin was owed
		if(data->side==1)
		{
			if(data->foulA<0)
			{
				placeAtCentre(c2,data);
				data->foulA++;
				owing=1;
			}
		}
		else
		{
			if(data->foulB<0)
			{
				placeAtCentre(c2,data);
				data->foulB++;
				owing=1;
			}
		}
		if(!owing && data->queenCovered)
		{
			if(data->a[c1].getY()==5*n)//other coin also covered
			{
				cout<<"CONGRATS!!"<<"Side "<<data->side<<" won the board..";
				data->finish=1;				
				if(data->side==1)
				{
					if(data->queenCovered==1)
						data->scoreA+=3;
					if(data->a[d1].getY()==5*n*(-1)	|| data->a[d2].getY()==5*n*(-1) )
					{
						data->scoreA+=1;
					}
					else
						data->scoreA+=2;
				}
				else
				{
					if(data->queenCovered==2)
						data->scoreB+=3;
					if(data->a[d1].getY()==5*n*(-1)	|| data->a[d2].getY()==5*n*(-1) )
					{
						data->scoreB+=1;
					}
					else
						data->scoreB+=2;
				}
			}
		}
		if(!data->queenCovered && data->a[c1].getY()==5*n)
		{
			cout<<"You lose the board"<<endl;
			if(data->side==1)
				data->scoreA-=3;
			else
				data->scoreB-=3;
		}
	}

	if(data->a[d2].getX()==-1)//Other coin sunk
	{
		cout<<"you sunk your opponent's coin"<<endl;
		data->a[d2].setPos(7,5*n*(-1));
		data->continueTurn=1;
		if( data->queenCovered)
		{
			if(data->a[d1].getY()==5*n)//other coin also covered
			{
				cout<<"CONGRATS!!"<<"Side "<<data->side<<" lost the board..";
				if(data->side==1)
				{
					if(data->queenCovered==1)
						data->scoreA+=3;
					if(data->a[c1].getY()==5*n*(-1)	|| data->a[c2].getY()==5*n*(-1) )
					{
						data->scoreA+=1;
					}
					else
						data->scoreA+=2;
				}
				else
				{
					if(data->queenCovered==2)
						data->scoreB+=3;
					if(data->a[c1].getY()==5*n*(-1)	|| data->a[c2].getY()==5*n*(-1) )
					{
						data->scoreB+=1;
					}
					else
						data->scoreB+=2;
				}
			}
		}
		if(!data->queenCovered && data->a[d1].getY()==5*n)
		{
			cout<<"You lose the board"<<endl;
			if(data->side==1)
				data->scoreA-=3;
			else
				data->scoreB-=3;
		}
	}
	
	if(data->a[d1].getX()==-1)//Other coin sunk
	{
		cout<<"you sunk your opponent's coin"<<endl;
		data->a[d1].setPos(7,5*n*(-1));
		data->continueTurn=1;
		if( data->queenCovered)
		{
			if(data->a[d2].getY()==5*n)//other coin also covered
			{
				cout<<"CONGRATS!!"<<"Side "<<data->side<<" lost the board..";
				if(data->side==1)
				{
					if(data->queenCovered==1)
						data->scoreA+=3;
					if(data->a[c1].getY()==5*n*(-1)	|| data->a[c2].getY()==5*n*(-1) )
					{
						data->scoreA+=1;
					}
					else
						data->scoreA+=2;
				}
				else
				{
					if(data->queenCovered==2)
						data->scoreB+=3;
					if(data->a[c1].getY()==5*n*(-1)	|| data->a[c2].getY()==5*n*(-1) )
					{
						data->scoreB+=1;
					}
					else
						data->scoreB+=2;
				}
			}
		}
		if(!data->queenCovered && data->a[d1].getY()==5*n)
		{
			cout<<"You lose the board"<<endl;
			if(data->side==1)
				data->scoreA-=3;
			else
				data->scoreB-=3;
		}
	}	

	if(data->a[0].getX()==-1)//Striker sunk
	{
		int i,coinSunk=0;
		if(data->side==1)
			data->foulA--;
		else
			data->foulB--;
		
		/*if any other coin is also sunk with striker, then place that coin
		in centre and the player continues his/her turn.*/	
		for (int i = 2; i < 6; i++)
		{
			if(data->a[i].getX()==5 || data->a[i].getX()==-5)
			{
				placeAtCentre(i,data);
				coinSunk=1;
			}
		}
		//if any other coin is also sunk alongwith striker continueTurn
		if(coinSunk)
		{
				data->continueTurn=0;
				cout<<"Striker sunk...continue your turn !"<<endl;
		}
		else
		{
			cout<<"Striker sunk...FOUL !!"<<endl;
			data->continueTurn=1;		
			
			/*If no other coin is sunk alongwith striker, then return a 
			 * coin which was earned earlier.If no coin has been earned
			 * yet, then you owe a coin(foulA or foulB < 0) */
			 if(data->a[c1].getY()==5*n)
			 {
				 cout<<"c1 "<<c1<< "is being placed";
				 placeAtCentre(c1, data);
				 if(data->side==1)
					data->foulA++;
				 else
					data->foulB++;
			 }
			 else if(data->a[c2].getY()==5*n)
			 {
				 cout<<"c1 "<<c1<< "is being placed";
				 placeAtCentre(c2, data);
				 if(data->side==1)
					data->foulA++;
				 else
					data->foulB++;
			 }
			 else //No coin has been sunk yet
			 {
				 cout<<"You owe a coin...";
			 }
			 
			 
		}
		
		
	}


}
