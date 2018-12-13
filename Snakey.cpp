#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

#define height 25
#define width 25

const int eachStep = height*width;
char road[height][width];

void gotoxy(int x,int y)    
{
    COORD coord;
    coord.X=x;
    coord.Y=y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class board
{
	public:
		//char road[height][width];
		long long recordTime;
		board();
		void food();
		void welcome();
		void print(int grade,int score,int gamespeed);
};

board::board()
{
	srand(time(NULL));
	for(int i=1;i<=height-2;++i)
	{
		for(int j=1;j<=width-2;++j)
		{
			road[i][j]=' ';
		}
	}
	for(int i=0;i<=height-1;++i)
		road[i][0]=road[i][width-1]='#';
	for(int j=0;j<=width-1;++j)
		road[0][j]=road[height-1][j]='#';
}

void board::welcome()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN);                                                                                                                                                                                                                              
	cout << "   SSSSSSSSSSSSSSS                                   kkkkkkkk" << endl;                                                   
	cout << " SS:::::::::::::::S                                  k::::::k" << endl;                                                   
	cout << "S:::::SSSSSS::::::S                                  k::::::k" << endl;                                                   
	cout << "S:::::S     SSSSSSS                                  k::::::k" << endl;                                                   
	cout << "S:::::S          nnnn  nnnnnnnn      aaaaaaaaaaaaa    k:::::k    kkkkkkk eeeeeeeeeeee  yyyyyyy           yyyyyyy" << endl;
	cout << "S:::::S          n:::nn::::::::nn    a::::::::::::a   k:::::k   k:::::kee::::::::::::ee y:::::y         y:::::y" << endl; 
	cout << " S::::SSSS       n::::::::::::::nn   aaaaaaaaa:::::a  k:::::k  k:::::ke::::::eeeee:::::eey:::::y       y:::::y" << endl;  
	cout << "  SS::::::SSSSS  nn:::::::::::::::n           a::::a  k:::::k k:::::ke::::::e     e:::::e y:::::y     y:::::y" << endl;   
	cout << "    SSS::::::::SS  n:::::nnnn:::::n    aaaaaaa:::::a  k::::::k:::::k e:::::::eeeee::::::e  y:::::y   y:::::y" << endl;    
	cout << "       SSSSSS::::S n::::n    n::::n  aa::::::::::::a  k:::::::::::k  e:::::::::::::::::e    y:::::y y:::::y" << endl;     
	cout << "            S:::::Sn::::n    n::::n a::::aaaa::::::a  k:::::::::::k  e::::::eeeeeeeeeee      y:::::y:::::y" << endl;      
	cout << "            S:::::Sn::::n    n::::na::::a    a:::::a  k::::::k:::::k e:::::::e                y:::::::::y" << endl;       
	cout << "SSSSSSS     S:::::Sn::::n    n::::na::::a    a:::::a k::::::k k:::::ke::::::::e                y:::::::y" << endl;        
	cout << "S::::::SSSSSS:::::Sn::::n    n::::na:::::aaaa::::::a k::::::k  k:::::ke::::::::eeeeeeee         y:::::y" << endl;         
	cout << "S:::::::::::::::SS n::::n    n::::n a::::::::::aa:::ak::::::k   k:::::kee:::::::::::::e        y:::::y" << endl;          
	cout << " SSSSSSSSSSSSSSS   nnnnnn    nnnnnn  aaaaaaaaaa  aaaakkkkkkkk    kkkkkkk eeeeeeeeeeeeee       y:::::y" << endl;           
	cout << "                                                                                             y:::::y" << endl;            
	cout << "________________________________________________________________________________________     y:::::y" << endl;             
	cout << "_::::::::::::::::::::::_::::::::::::::::::::::_::::::::::::::::::::::_::::::::::::::::::   y:::::y" << endl;              
	cout << "                                                                                          y:::::y" << endl;               
	cout << "                                                                                         yyyyyyy" << endl; 
	//cout << "____________________________________________________________________________________________________________________" << endl;
	//cout << "_::::::::::::::::::::::_::::::::::::::::::::::_::::::::::::::::::::::_::::::::::::::::::::::_::::::::::::::::::::::_" << endl;
	//cout << "____________________________________________________________________________________________________________________" << endl;                                                                                                       
    
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_BLUE);                                                                                                            
	
	//cout << "\n\n\tThe game is about to begin." << endl;
	
	recordTime = clock();
	while(clock()-recordTime<=4000);
	system("cls");
	
	for(int i=3;i>=0;--i)
	{
		recordTime = clock();
		while(clock()-recordTime<=1300);
		system("cls");
		if(i>0)
			cout << "\n\n\t\tCountDown: " << i << endl;
	}
}

void board::food()
{
	//srand(time(NULL));
	int x,y;
	do
	{
		x=rand()%height;
		y=rand()%width;
	}while(road[x][y]!=' ');
	road[x][y]='$';
}

void board::print(int grade,int score,int gamespeed)
{
	//cout << endl;
	for(int i=0;i<height;++i)
	{
		//cout << "\t";
		for(int j=0;j<width;++j)
		{
			cout << road[i][j];
		}
		if(i==height/4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\tscore: " << score;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_BLUE);
		}
		if(i==height/4+2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\tgrade: " << grade;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_BLUE);
		}
		if(i==height/4+4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\tgameSpeed: " << gamespeed << "ms";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_BLUE);
		}
		cout << endl;
	}
}

class snake:public board
{
	public:
		int length,head,tail,grade,score,gamespeed;
		int x,y;
		int lastX,lastY;
		int mark;
		char direction;
		char lastDirection;
		char testButton;
		int p[2][eachStep];
		snake();
		void move();
};

snake::snake()
{
	for(int i=1;i<4;++i)
	{
		road[1][i]='*';
	}
	road[1][4]='@';
	lastX = 1;
	lastY = 3;
	for(int i=0;i<4;++i)
	{
		p[0][i]=1;
		p[1][i]=i+1;
	}
	score = 0,head = 3,tail = 0,length = 4;
	grade = 1,gamespeed = 500;
	lastDirection = direction = 77;
}

void snake::move()
{
	while(1)
	{
		mark = 1;
		recordTime = clock();
		while((mark=((clock()-recordTime)<=gamespeed)) && !kbhit());
		if(mark)
		{
			testButton = getch();
			if(testButton != (char)224)
			{
				direction = lastDirection;	
			}
			else
			{
				direction = getch();
			}
		}
		switch(direction)
		{
			case 77 :
				x = p[0][head];
				y = p[1][head]+1;
				break;
			case 75	:
				x = p[0][head];
				y = p[1][head]-1;
				break;
			case 72 :
				x = p[0][head]-1;
				y = p[1][head];
				break;
			case 80:
				x = p[0][head]+1;
				y = p[1][head];
				break;
			default:
				break;
		}
		if(x==lastX && y==lastY)
		{
			direction = lastDirection;
			continue;
		}
		else
		{
			lastX = p[0][head];
			lastY = p[1][head];
			lastDirection = direction;
		}
		if((x==0 || y==0 || x==height-1 || y==width-1) || (road[x][y]!=' ' && road[x][y]!='$'))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
			gotoxy(width+6,height-12);
			cout << "   ___   _   __  __ ___    _____   _____ ___ " << endl;  
			gotoxy(width+6,height-11);
			cout << "  / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\" << endl; 
			gotoxy(width+6,height-10);
			cout << " | (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /" << endl;
			gotoxy(width+6,height-9);
			cout << "  \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\" << endl; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_BLUE);
			gotoxy(0,height);
            break;
		}
		if(road[x][y]=='$')
		{
			++length;
			score+=100;
			if(length==8)
			{
				++grade;
				length-=8;
				if(gamespeed>=200)
					gamespeed = 550-grade*50;		
			}
			road[x][y]='@';
			road[p[0][head]][p[1][head]] = '*';
			head = (head+1)%eachStep;
			p[0][head]=x;
			p[1][head]=y;
			food();
			system("cls");
			print(grade,score,gamespeed);	
		}
		else
		{
			gotoxy(y,x);
			cout << '@';
			road[x][y]='@';
			gotoxy(p[1][tail],p[0][tail]);
			cout << ' ';
			road[p[0][tail]][p[1][tail]] = ' ';
			tail = (tail+1)%eachStep;
			gotoxy(p[1][head],p[0][head]);
			cout << '*';			
			road[p[0][head]][p[1][head]] = '*';
			head = (head+1)%eachStep;
			p[0][head] = x;
			p[1][head] = y;
			//print(grade,score,gamespeed);
		}
	}
}

int main()
{
	board Board;
	snake Snake;
	Board.welcome();
	Board.food();
	Board.print(Snake.grade,Snake.score,Snake.gamespeed);
	Snake.move();
	return 0;
} 
