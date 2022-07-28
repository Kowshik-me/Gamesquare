#include<windows.h>							//For Sleep() and console
#include<stdlib.h>							//For fflush() and random
#include<string.h>							//For using string functions
#include<stdio.h>							//For standard input/output
#include<conio.h>							//For getch()
#include<time.h>							//For time(NULL)

//Some define macros
#define ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

//Function Declarations for Hand cricket
int toss(char name[]);
int batting(int overs,char name[]);
void result(int score_p,int score_c,char name[]);
void handcricket();
//Global variables for Hand cricket
int over=0,temp=-1,count=0;

//Function Declarations for Matchtrix
void matchtrix();
void play();
void win();

//Function Declarations Puzznic
int checkWin(int mat[][4]);
void showMat(int mat[][4]);
void setMat(int mat[][4]);
int right(int mat[][4]);
int down(int mat[][4]);
int left(int mat[][4]);
int up(int mat[][4]);
void puzznic();
int input();
int menu();
 
//Other functions
void gotoxy(short,short);
void mainmenu();
void welcome();

//Main function
int main()
{
	welcome();
	mainmenu();
	return 0;
}

void welcome()								//Function for opening screen
{
	system("color 07");				//Function to change background and font colour
	Sleep(500);
	gotoxy(0,10);	
	printf("   _____          __  __ ______  _____  ____           _    _ _____  ______ ");
	gotoxy(0,11);Sleep(350);
	printf("  / ____|   /\\   |  \\/  |  ____|/ ____|/ __ \\     /\\  | |  | |  __ \\|  ____|");
	gotoxy(0,12);Sleep(350);
	printf(" | |  __   /  \\  | \\  / | |__  | (___ | |  | |   /  \\ | |  | | |__) | |__   ");
	gotoxy(0,13);Sleep(350);
	printf(" | | |_ | / /\\ \\ | |\\/| |  __|  \\___ \\| |  | |  / /\\ \\| |  | |  _  /|  __|  ");
	gotoxy(0,14);Sleep(350);
	printf(" | |__| |/ ____ \\| |  | | |____ ____) | |__| | / ____ \\ |__| | | \\ \\| |____ ");
	gotoxy(0,15);Sleep(350);
	printf("  \\_____/_/    \\_\\_|  |_|______|_____/ \\___\\_\\/_/    \\_\\____/|_|  \\_\\______|");
	do{
	    Sleep(500);
	    gotoxy(45,18);
	    printf("                              ");
	    Sleep(500);
	    gotoxy(45,18);
		
	    printf("Enter any key to start......\n");
	}while(!kbhit());
	getch();
}

void mainmenu()
{
	int choice;
	do
	{
		system("cls");
		printf("-------------------------WELCOME TO GAMESQUARE-------------------------\n");
		printf("MainMenu\n");
		printf("1. Hand Cricket\n2. Matchtrix\n3. Puzznic\n4. Exit\n");
		fflush(stdin);
		scanf("%d",&choice);
		if(choice==1)
			handcricket();
		else if(choice==2)
			matchtrix();
		else if(choice==3)
			puzznic();
		else if(choice==4)
		{
			printf("Thanks for playing!!Hope you enjoyed\n");
			exit(0);
		}		
			
		else
			system("cls");	
	}while(choice<1||choice>4);
	
}
//Code for Hand Cricket
void handcricket()
{
	system("cls");
	int choice,choose;
	char name[50],ch;
	srand(time(NULL));
	printf("------------------------WELCOME TO HAND CRICKET------------------------\n");
	lb:
	printf("Choose the option\n");
	printf("1.Play until out\n");
	printf("2.Play for limited over\n");
	printf("3.How to play\n");
	printf("4.Exit\n");
	fflush(stdin);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
		case 1:	printf("------------------------------GAMEPLAY------------------------------\n");
				printf("Enter your name-");
				fflush(stdin);
				gets(name);
				choose=toss(name);
				break;
		case 2:	printf("------------------------------GAMEPLAY------------------------------\n");
				printf("Enter your name-");
				fflush(stdin);
				gets(name);
				printf("Enter number of overs-");
				scanf("%d",&over);
				choose=toss(name);
				break;
		case 3:	printf("---------------------------------INSTRUCTIONS---------------------------------\n");
				printf("This game is build to refresh your memories of childhood.\n");
				printf("Let's go through the basic rules:\n");
				printf("The game is simple,you just have to beat the computer with more runs and make \n");
				printf("the computer feel inferior, to win you have to make more runs than the computer\n");
				printf("or don't let the computer to make more runs than you unless you want computer \n");
				printf("to win.\n");
				printf("To start the game,Toss will be done between you and the computer. You can choose");
				printf("head or tail for the toss and if you won the toss it is your call to bat or ball");
				printf("if you lose let computer make the decision for itself.\n");
				printf("\nAfter the toss is done;\n");
				printf("You have to either bat/bowl according to the result.\n");
				printf("For playing,you have to choose a number between 1 to 6 and then a number is \n");
				printf("choosen by the computer.\n");
				printf("In case,both choose a different number then score of the player batting is equal");
				printf("to the number choosen by him. The total score keeps on adding until both comes \n");
				printf("up with the same number. After that,batsman will out.\n");
				printf("Thus, a target is set for the bowler to chase while batting in the next inning.\n");
				printf("\nNow,Press any key to start the game\n");
				getch();
				system("cls");
				printf("------------------------WELCOME TO HAND CRICKET------------------------\n");
				goto lb;
				break;
		case 4:	printf("Thanks for playing,Hope you enjoyed!!!\n");
				Sleep(1000);
				mainmenu();
				break;
		default:printf("------------------------WELCOME TO HAND CRICKET------------------------\n");
				goto lb;
	}
	printf("-------------------------------------------------------------------------\n");
	printf("Do you want to play again(Y/N)-");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
	{	system("cls");
		printf("------------------------WELCOME TO HAND CRICKET------------------------\n");
		goto lb;
	}		
	else
		printf("\nThanks for playing,Hope you enjoyed!!!\n");
		mainmenu();
}
int toss(char name[])											//Toss function
{	
	int t,x,choose,score_p=0,score_c=0;
	printf("\n%s,Let's Toss! Select your choice\n1.Head 2.Tail\n",name);
	do
	{	
		fflush(stdin);
		scanf("%d",&t);
		if(t==1)
			printf("You choose Head\n");
		else if(t==2)
			printf("You choose Tail\n");
		else{
			system("cls");
			printf("%s,Enter your choice for toss\n1.Head 2.Tail\n",name);}
	}while(t<1||t>2);
	x=rand()%(2)+1;
	if(x==t)
	{	
		tos:
		printf("%s,You won the toss\n",name);
		printf("Choose\n1.Batting\n2.Bowling\n");
		fflush(stdin);
		scanf("%d",&choose);
		if(choose==1)
		{
			printf("You chooses to Bat\n");
			printf("\nEnter any key to start the game\n");
			getch();
			system("cls");
			printf("Let's start the game..............\n");
			score_p=batting(over,name);
			printf("\n%s,your total score is %d\n",name,score_p);
			score_c=batting(over,"Computer");
			printf("\nComputer's total score is %d\n",score_c);
			result(score_p,score_c,name);
		}
		else if(choose==2)
		{
			printf("You chooses to Bowl\n");
			printf("\nEnter any key to start the game\n");
			getch();
			system("cls");
			printf("Let's start the game..............\n");
			score_c=batting(over,"Computer");
			printf("\nComputer's total score is %d\n",score_c);
			score_p=batting(over,name);
			printf("\n%s,your total score is %d\n",name,score_p);
			result(score_p,score_c,name);
		}
		else
		{
			system("cls");
			printf("Invalid choice!!!Try once again\n");
			printf("---------------------------------------------------\n");
			goto tos;
		}
	}
	else
	{
		printf("%s,You lose the toss\n",name);
		choose=x;
		if(x==1)
		{
			printf("Computer chooses to Bat\n");
			printf("\nEnter any key to start the game\n");
			getch();
			system("cls");
			printf("Let's start the game..............\n");
			score_c=batting(over,"Computer");
			printf("\nComputer's total score is %d\n",score_c);
			score_p=batting(over,name);
			printf("\n%s,your total score is %d\n",name,score_p);
			result(score_p,score_c,name);
		}
		else
		{
			printf("Computer chooses to Ball\n");
			printf("\nEnter any key to start the game\n");
			getch();
			system("cls");
			printf("Let's start the game..............\n");
			score_p=batting(over,name);
			printf("\n%s,your total score is %d\n",name,score_p);
			score_c=batting(over,"Computer");
			printf("\nComputer's total score is %d\n",score_c);
			result(score_p,score_c,name);
		}
	}
}

int batting(int overs,char name[])								//function for game
{
	int score=0,i=0,j=1;
	char decide[5];
	count++;
	if(strcmp(name,"Computer")==0)
	{
		printf("-----------------------You are going to bowl now-------------------------\n");	
		strcpy(decide,"Bowl");
	}
	
	else
	{
		printf("-----------------------You are going to bat now-------------------------\n");
		strcpy(decide,"Bat");
	}
	again:
	printf("Enter from 1-6");
	int bat,bowl;
	if(overs>0)
	{
		for(i=0;i<overs;i++)
		{
			for(j=1;j<=6;j++)
			{
				printf("\n\t\tCurrent score=%d\n",score);
				printf("%d.%d Bowl\n",i,j);
				printf("%s : ",decide);
				fflush(stdin);
				scanf("%d",&bat);
				if(bat>0&&bat<7)
				{
					bowl=rand()%6+1;
					printf("Computer : %d",bowl);
					if(bat==bowl)
					{
						if(score==0)
							printf("\nOhhhhh!!Duck out");
						else
							printf("\nOhhh!! It's Out");
						temp=score;
						return score;
					}
					else
					{
						if(strcmp(name,"Computer")==0)
						{
							if(bowl==6)
								printf("\nOhhhhh!!Its a six");
							else if(bowl==4)
								printf("\nIt's boundary!!");
							score+=bowl;
						}
						else
						{
							if(bat==6)
								printf("\nSixerrrrrr!!Go ahead");
							else if(bat==4)
								printf("\nIt's a four!Keep it up");
							score+=bat;
						}
					}
					if(count%2==0&&temp<score)
						return score;
				}
				else
				{
					printf("Invalid input!!!Try once again\n");
					printf("---------------------------------------------------\n");
					goto again;
				}
			}
		printf("\n%d over completed\n",i+1);
		}
		return score;
	}
	else
	{	
		while(1)
		{
			printf("\n\t\tCurrent score=%d\n",score);
			printf("%d.%d Bowl\n",i,j);
			if(j!=6)
				j++;
			else{
				j=1;
				++i;
			}
			printf("%s : ",decide);
			fflush(stdin);
			scanf("%d",&bat);
			if(bat>0&&bat<7)
			{
				bowl=rand()%6+1;
				printf("Computer : %d",bowl);
				if(bat==bowl)
				{
					if(score==0)
						printf("\nOhhhhh!!Duck out");
					else
						printf("\nOhhh!! It's Out");
					temp=score;
					return score;
				}
				else
				{
					if(strcmp(name,"Computer")==0)
					{
						if(bowl==6)
							printf("\nOhhh its a six!!");
						else if(bowl==4)
							printf("\nIts a boundary!!");
						score+=bowl;
					}
					else
					{
						if(bat==6)
							printf("\nSixerrrrrr!!Go ahead");
						else if(bat==4)
							printf("\nIt's a four!Keep it up");
						score+=bat;
					}
				}
				if(count%2==0&&temp<score)
						return score;
			}
			else
			{
				printf("Invalid input!!!Try once again\n");
				printf("---------------------------------------------------\n");
				j--;
				goto again;
			}		
		}	
	}
}

void result(int score_p,int score_c,char name[])				//Result function
{
	printf("-----------------------------------------------------------------------\n");
	printf("\nScores are counting wait..........\n");
	Sleep(2000);
	printf("\nResults are ready!!Enter any key to see the results\n");
	getch();
	system("cls");
	printf("-----------------------Time for result-----------------------\n");
	if(score_p>score_c)
		printf("Hurray!!!You win by %d runs\n\n",score_p-score_c);
	else if(score_p<score_c)
		printf("Oops!You lose by %d runs\n\n",score_c-score_p);
	else
		printf("Match is draw.Both scored %d\n\n",score_c);
}
//End for Hand Cricket

//Code for Matchtrix
void matchtrix()
{
	system("cls");
	int choice,no;
	char ch;
	printf("----------------------WELCOME TO THE MATCHTRIX GAME----------------------\n");
	again:
	srand(time(NULL));
	printf("Choose the option\n");
	printf("1.Start the game\n2.How to play\n3.Exit\n");
	fflush(stdin);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
		case 1:	no=rand();
				if(no%2==0)
					win();
				else
					play();
				break;
		case 2:	printf("---------------------------------Instructions---------------------------------\n");
				printf("In this game there are total 21 matchsticks.\n");
				printf("You have to choose either 1,2,3,4 matchsticks at a time\nand then computer does its picking\n");
				printf("Whoever is forced to pick up the last matchstick loses the game.\n");
				printf("\nRules\n1.Total matchsticks should not exceed 21\n");
				printf("2.Choose either 1,2,3 or 4 matchsticks at a time\n");
				printf("Press any key to start the game\n");
				getch();
				system("cls");
				win();
				break;
		case 3:	printf("Thanks for playing!!Hope you enjoyed\n");
				Sleep(1000);
				mainmenu();
		default:printf("----------------------WELCOME TO THE MATCHTRIX GAME----------------------\n");
				goto again;
	}
	printf("--------------------------------------------------------\n");
	printf("\n\nWant to start a new game(Y/N))\n");
	fflush(stdin);
	scanf("%c",&ch);
	system("cls");
	if(ch=='y'||ch=='Y')
	{
		printf("----------------------WELCOME TO THE MATCHTRIX GAME----------------------\n");
		goto again;
	}
 	else
 		mainmenu();
		printf("Thanks for playing!!Hope you enjoyed\n");
}

void play()
{
	srand(time(NULL));
	int user,com,sum=0,flag=0;
	printf("----------------------WELCOME TO THE MATCHTRIX GAME----------------------\n");
	printf("Rules\n1.Total matchsticks should not exceed 21\n");
	printf("2.Choose either 1,2,3 or 4 matchsticks at a time\n\n");
	printf("------------------------------------------------------------------------\n");
	printf("Let's start Matchtrix game\n");
	start:
	do
	{	
		printf("Your turn : ");
		fflush(stdin);
		scanf("%d",&user);
		if (user>4)
		{
			printf("Please see rule no.2\n");
			goto start;
		}
		sum+=user;
		if(sum==21)
		{
			printf("-----------------------------------------------------------------\n");
			printf("You lose!!!!\n");
			flag=1;
			break;
		}
		if(sum>21)
		{
			printf("Please see rule no. 1\n");
			sum-=user;
			goto start;
		}
		ag:
		com=rand()%(4)+1;
		sum+=com;
		if(sum>21)
		{
			sum-=com;
			goto ag;
		}
		printf("My choice : %d\n",com);
		if(sum!=21)		
			printf("Total matchstick collected: %d(%d left)\n\n",sum,21-sum);
	}while(sum!=21);
	if(flag==0)
		printf("\nYou win!!!\n");
}

void win()
{
	int i,user,sum=0;
	printf("----------------------WELCOME TO THE MATCHTRIX GAME----------------------\n");
	printf("Rules\n1.Total matchsticks should not exceed 21\n");
	printf("2.Choose either 1,2,3 or 4 matchsticks at a time\n\n");
	printf("------------------------------------------------------------------------\n");
	printf("Let's start Matchtrix game\n");
	for (i=1;i<=5;i++)
	{ start:
		printf("Your turn: ");
		fflush(stdin);
		scanf("%d",&user);
		
		if (user>4)
		{
			printf("Please see rule no.2\n");
			goto start;
		}
		if ((sum==20)&&(user>1))
		{
			printf("Please see rule no.1\n");
			goto start;
		}
		sum+=user;
		if (sum==21)
		{
			printf("\nYou lose!!!!\n"); 
			break;
		}
		printf("My choice: %d\n",5*i-sum);
		sum=5*i;
		printf("Total Matchsticks collected: %d(%d left)\n\n",sum,21-sum);
	}
}
//End for Matchtrix

//Code for Puzznic
void puzznic()
{
	system("cls");
	start:
	printf("-------------------------WELCOME TO THE PUZZNIC-------------------------\n");
	int choice=menu();
	if(choice==1)
	{
		int mat[4][4],move=500;
		setMat(mat);
		while(move!=0)
		{
			printf("\nMove Remaining: %d",move);
			showMat(mat);
			if(checkWin(mat))
				{
					printf("\nYou win in %d moves",500-move);
					printf("\nPress any key to go menu....");
					getch();
					goto start;
				}
			switch(input())
			{
				case ESC:
					printf("Thanks for playing!!Hope you enjoyed\n");
					system("cls");
					goto start;
				case UP:
					if(!up(mat))
						move++;
					break;
				case DOWN:
					if(!down(mat))
						move++;
					break;
				case RIGHT:
					if(!right(mat))
						move++;
					break;
				case LEFT:
					if(!left(mat))
						move++;
					break;
				default:
					move++;
			}
			system("cls");
			move--;
			if(move==0)
			{
				printf("OUT OF MOVE\n");
				printf("Enter any key for menu\n");
				getch();
				goto start;
			}
		}
		getch();
	}
}
int checkWin(int mat[4][4])					//Checking function for winning
{
	int i,j,k=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{	
			k<15?k++:(k=0);
			if(mat[i][j]!=k)
			return(0);
		}
	}
	return 1;
}

int input()									//For taking input from user
{
	char ch;
	ch=getch();
	if(ch==224)
		ch=getch();
	switch(ch)
	{
		case 27: return(ESC);
		case 72: return(UP);
		case 80: return(DOWN);
		case 75: return(LEFT);
		case 77: return(RIGHT);
		default: return(5);
	}
}

int right(int mat[4][4])
{
	int i,j,temp,zero=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(mat[i][j]==0)
			{
				zero=1;
				break;
			}
		}
		if(zero)
			break;
	}
	if(j==0)
		return(0);
	else
	{
		temp=mat[i][j];
		mat[i][j]=mat[i][j-1];
		mat[i][j-1]=temp;
		return 1;
	}
}

int left(int mat[4][4])
{
	int i,j,temp,zero=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(mat[i][j]==0)
			{
				zero=1;
				break;
			}
		}
		if(zero)
			break;
	}
	if(j==3)
		return(0);
	else
	{
		temp=mat[i][j];
		mat[i][j]=mat[i][j+1];
		mat[i][j+1]=temp;
		return 1;
	}
	
}

int up(int mat[4][4])
{
	int i,j,temp,zero=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(mat[i][j]==0)
			{
				zero=1;
				break;
			}
		}
		if(zero)
			break;
	}
	if(i==3)
		return(0);
	else
	{
		temp=mat[i][j];
		mat[i][j]=mat[i+1][j];
		mat[i+1][j]=temp;
		return 1;
	}
	
}

int down(int mat[4][4])
{
	int i,j,temp,zero=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(mat[i][j]==0)
			{
				zero=1;
				break;
			}
		}
		if(zero)
			break;
	}
	if(i==0)
		return(0);
	else
	{
		temp=mat[i][j];
		mat[i][j]=mat[i-1][j];
		mat[i-1][j]=temp;
		return 1;
	}
}

void setMat(int mat[4][4])					//Function to set the value of matrix
{
	int numbers[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int maxindex=14,index,i,j;
	srand(time(NULL));
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(maxindex>=0)
			{
				index=rand()%(maxindex+1);
				mat[i][j]=numbers[index];
				numbers[index]=numbers[maxindex];
				maxindex--;
			}
			else
				mat[i][j]=0;
		}
	}
}

void showMat(int mat[4][4])					//Function to print matrix
{
	int i,j;
	printf("\n--------------------\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(mat[i][j]!=0)
				printf("%-2d | ",mat[i][j]);
			else
				printf("   | ");
		}
		printf("\n--------------------\n");
	}
	//printf("\t\t\tPRESS ESC FOR MENU\n");
}

int menu()									//Menu function for choice
{
	int choice;
	printf("Choose the option\n");
	printf("1.Start game\n2.Instuctions\n3.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			system("cls");
			return 1;
		case 2:
			system("cls");
			printf("---------------------------------INSTRUCTIONS----------------------------------\n");
			printf("\nIn this game,You have a matrix in which numbers upto 15 are arranged randomly.\n");
			printf("So you have to arrange them in a squencial manner under 500 moves.\n");
			printf("For moving in puzzle you have to use arrow keys,and at any time during the game\n");
			printf("use 'ESC' button for back to menu\n");
			printf("--------------------------------------------------------------------------------");
			printf("Enter any key to start the game\n");
			getch();
			system("cls");
			return 1;
		case 3:
			system("cls");
			printf("Thanks!!!For playing");
			Sleep(1000);
			mainmenu();
		default:
			system("cls");
			printf("-------------------------WELCOME TO THE PUZZNIC-------------------------\n");
			menu();
	}
}
//End for Puzznic

void gotoxy(short x, short y)           //definition of gotoxy function                                            
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
