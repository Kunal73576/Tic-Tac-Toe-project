#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;
class tic
{
	public:
		int flag;
		char ch1,ch2;
	void play(char ar[3][3])
	{
		if((ar[0][0]=='X'&& ar[2][2]=='X' || ar[0][2]=='X' && ar[2][0]=='X'||
		ar[0][0]=='O'&& ar[2][2]=='O' || ar[0][2]=='O' && ar[2][0]=='O') && ar[1][1]=='4')
		{
			ar[1][1]=ch2;
			goto end;
		}
		else if((ar[0][0]=='X'&&ar[1][1]=='X'||ar[0][0]=='O'&&ar[1][1]=='O')&&ar[2][2]=='8')
		{
			ar[2][2]=ch2;
			goto end;
		}
		else if((ar[0][2]=='X'&&ar[1][1]=='X'||ar[0][2]=='O'&&ar[1][1]=='O') &&ar[2][0]=='6')
		{
			ar[2][0]=ch2;
			goto end;
		}
		else
		{
			for(int x=0;x<3;x++)
			{
				for(int y=0;y<3;y++)
				{
					if((ar[x][y]=='X'&& ar[x][y+2]=='X'||ar[x][y]=='O'&&ar[x][y+2]=='O') && ar[x][y+1]!='X'&& ar[x][y+1]!='O')
					{
						ar[x][y+1]=ch2;
						goto end;
					}
					else if((ar[x][y]=='X'&& ar[x][y+1]=='X'||ar[x][y]=='O' && ar[x][y+1]=='O') && ar[x][y+2]!='X' && ar[x][y+2]!='O')
					{
						ar[x][y+2]=ch2;
						goto end;
					}
					else if((ar[x][y]=='X'&&ar[x+2][y]=='X'|| ar[x][y]=='O' && ar[x+2][y]=='O') && ar[x+1][y]!='X' && ar[x+1][y]!='O')
					{
						ar[x+1][y]=ch2;
						goto end;
					}
					else if((ar[x][y]=='X'&&ar[x+1][y]=='X'|| ar[x][y]=='O'&& ar[x+1][y]=='O') && ar[x+2][y]!='X'&& ar[x+2][y]!='O')
					{
						ar[x+2][y]=ch2;
						goto end;
					}
					else
					{
						srand(time(0));
						int f=0;
						while(f==0)
						{
							int i=rand()%8+1;
							for(int x=0;x<3;x++)
							{
								for(int y=0;y<3;y++)
								{
									if(ar[x][y]==((char)(i+48)))
									{
										ar[x][y]=ch2;
										f=1;
										goto end;
									}
								}
							}
						}		
					}
				}
			}
		}
		end:
			cout<<"\n";
	}
	check_diagnol(char ar[3][3])
	{
		if(ar[0][0]==ar[1][1]&&ar[1][1]==ar[2][2] ||ar[0][2]==ar[1][1]&&ar[1][1]==ar[2][0])
		{
			flag=1;
			if(ar[1][1]==ch2)
			{
				cout<<"\nOhhh!! You lost";
				PlaySound(TEXT("lost game.wav"),NULL, SND_SYNC);
			}
			else if(ar[1][1]==ch1)
			{
				cout<<"\nCongratulations!! You Won The Game";
				PlaySound(TEXT("won the game.wav"),NULL, SND_SYNC);
			}
			
			exit(1);
		}
	}
	check_row(char ar[3][3])
	{
		for(int x=0;x<=2;x++)
		{
			if(ar[x][0]==ar[x][1]&&ar[x][1]==ar[x][2])
			{
				flag=1;
				if(ar[x][0]==ch2)
				{
					cout<<"\nOhhh!! You lost";
					PlaySound(TEXT("lost game.wav"),NULL, SND_SYNC);
				}
				else if(ar[x][0]==ch1)
				{
					cout<<"\nCongratulations!! You Won The Game";
					PlaySound(TEXT("won the game.wav"),NULL, SND_SYNC);
				}

				exit(1);
			}
		}
		
	}
	check_column(char ar[3][3])
	{
		for(int y=0;y<=2;y++)
		{
			if(ar[0][y]==ar[1][y]&&ar[1][y]==ar[2][y])
			{
				flag=1;
				if(ar[0][y]==ch2)
				{
					cout<<"\nOhhh!! You lost";
					PlaySound(TEXT("lost game.wav"),NULL, SND_SYNC);
				}
				else if(ar[0][y]==ch1)
				{
					cout<<"\nCongratulations!! You Won The Game";
					PlaySound(TEXT("won the game.wav"),NULL, SND_SYNC);
				}
				
				exit(1);
			}
		}
	}
	int compare(int pos,int m,char ar[3][3])
	{
		int f=0;
		for(int x=0;x<3;x++)
		{
			for(int y=0;y<3;y++)
			{
				if(ar[x][y]==((char)(pos+48)) && m==1)
				{
					ar[x][y]=ch2;
					f=1;
				}
				if(ar[x][y]==((char)(pos+48)) && m==0)
				{
					ar[x][y]=ch1;
					f=1;
				}
			}
		}
		return f;
	}
	void display(char ar[3][3])
	{
		cout<<"\n";
		for(int x=0;x<3;x++)
		{
			cout<<"\t\t     |     |     |     \n";
			cout<<"\t\t";
			for(int y=0;y<3;y++)
			{
				cout<<"  "<<ar[x][y]<<"  |";
			}
			if(x!=2)
    		cout<<"\n\t\t_____________________\n";
		}	
	}	
};
int main()
{
	PlaySound(TEXT("welcome.wav"),NULL, SND_SYNC);
	cout<<"\t\t\t\t\t\t\t\t\t\t    WELCOME TO TIC TAC TOE GAME\n";
	cout<<"\n\t\t\t\t\t\t\t     To play the game you just need to choose the cell number to mark your turn.\n";
	cout<<"New Game\n";
	PlaySound(TEXT("welcome.wav"),NULL, SND_SYNC);
	char ar[3][3];
	int mt,yt;
	tic ob;
	char i='0';
	for(int x=0;x<3;x++)
	{
		for(int y=0;y<3;y++)
		{
			ar[x][y]=i++;
		}
	}
	ob.display(ar);
	int iter=0;
	cout<<"\n\nChoose X or O : ";
	PlaySound(TEXT("hello chose x or 0.wav"),NULL, SND_SYNC);
	cin>>ob.ch1;
	if(ob.ch1=='X')
	ob.ch2='O';
	else
	ob.ch2='X';
	
	for(int x=0;x<3;x++)
	{
		for(int y=0;y<3;y++,iter++)
		{
			if(iter%2==0)
			{
				cout<<"\n\nMy turn\n";
				PlaySound(TEXT("my turn.wav"),NULL, SND_SYNC);
				if(x==0 && y==0)
				{
					mt=4;
					ar[1][1]=ob.ch2;
				}
				else if(iter==2)
				{
					mt=0;
					if(mt==yt)
					mt++;
					int r=ob.compare(mt,1,ar);
				}
				else
				{
					ob.play(ar);
				}
				ob.display(ar);
				ob.check_row(ar);
				ob.check_column(ar);
				ob.check_diagnol(ar);
			}
			else
			{
				turn:
				cout<<"\n\nYour turn : ";
				PlaySound(TEXT("your turn.wav"),NULL, SND_SYNC);
				cin>>yt;
				int r=ob.compare(yt,0,ar);
				if(r==0)
				{
					cout<<"\nWrong move! Enter again\n";
					PlaySound(TEXT("wrong move.wav"),NULL, SND_SYNC);
					goto turn;
				}
				
				cout<<"\n";
				ob.display(ar);
				ob.check_row(ar);
				ob.check_column(ar);
				ob.check_diagnol(ar);	
			}
			
		}
	}
	if(ob.flag!=1)
	cout<<"Match tied!";
	PlaySound(TEXT("match tied.wav"),NULL, SND_SYNC);
}
