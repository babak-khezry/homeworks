#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 50
struct customer//sturct
{
	char accn[max];
	char fname[20];
	char lname[20];
	int accp;
	int balance;
	int news[max][2];
};
struct customer cost[100];//variable of all costomers
void changePasword(int);//change the pasword
void accessAcc();//access to the account
void transfer(int);//transfer money betwen accounts
void balance(int);//show the money
void recentUpdate(int);//show the 10 last updates(turnovers)
void employAcc();//get access to developer
void menu();//menu
void deleteAcc();
void updateAcc();//update the account by employer
void employe();//employer menu
void custom(int);//customer menu
void addacc();//create the new accounts
void cash(int);//get cash money
int end();//end the program

int main()
{
	int i;
	FILE *ptf;//file
	ptf = fopen("C:\\Users\\Radin\\Desktop\\project\\text.txt","r+");//geting file
	for(i=0;i<2;i++)
	{	
		fscanf(ptf,"%s %s %s",cost[i].fname,cost[i].lname,cost[i].accn);//geting file informations
		fscanf(ptf,"%d %d",&cost[i].accp,&cost[i].balance);//geting file informations
	}
	menu();
	return 0;
}
void menu()
{
	system("cls");//clear the consol
    printf("1. Sign in as employee\n2. Sign in as customer\n3. Exit\n");
    for(;;)//just let put 1 or 2 or 3
    {
    	int x ;
		scanf("%d",&x);
    	if(x==1||x==2||x==3)
   			switch(x)
  	    	{
    			case 1 :	employAcc();
    			break;
    			case 2 :	accessAcc();
    			break;
    			case 3 :	end();
				break;
			}
		else	continue;
	}
}
void employe()
{
	system("cls");
	printf("1. Open an account\n2. Update an account");//employ menu
	printf("\n3. Settle and Archive an account\n");//employ menu
	printf("4. list Recent Archived Accounts\n5. Back to the main menu\n");//employ menu
	int x;
	for(;;)
	{
		scanf("%d",&x);
		if(x==1||x==2||x==3||x==4||x==5)
		{
			switch(x)
    		{
    			case 1 : addacc();//create account
    				break;
   		 		case 2 : updateAcc();//update account
   			 		break;
    			case 3 : deleteAcc();//remove account
					break;
				case 5 : menu();//back to menue
					break;
			}
		}
		else	continue;
	}
}
void custom(int n)
{
	system("cls");
	printf("1. Account balance\n2. Transfer\n");//menu
	printf("3. Cash withdrawal\n4. Recent account updates\n");
	printf("5. Change password\n6. Back to the main menu\n");
	int copy = n ;
	int x;
	scanf("%d",&x);
	switch(x)
    {
    	case 1 : balance(copy);
    		break;
    	case 2 : transfer(copy);
    		break;
    	case 3 : cash(copy);
			break;
		case 4 : recentUpdate(copy);
			break;
		case 5 : changePasword(copy);
			break;
		case 6 : menu();
	}
}
void addacc()//create the acounts
{
	system("cls");
	int n ,i;
	printf("Enter how much account you want to create : ");//the number of new acounts
	scanf("%d",&n);
	for(i=2;i<n+2;i++)//put accounts
	{
		printf("Enter the name : ");
		scanf("%s",cost[i].fname);
		printf("Enter the last name : ");
		scanf("%s",cost[i].lname);
		printf("Enter the account number <%d> : ",i+1);
		scanf("%s",cost[i].accn);//put card number
		printf("Enter the account pasword <%d> : ",i+1);
		for(;;)//only pass more then 4 number 
		{
			scanf("%d",&cost[i].accp);//get pasword
			if(cost[i].accp < 999)
				printf("Short pasword!\nEnter another pasword <%d> : ",i+1);
			else
				break;
		}	
	printf("Enter the lnitial balance costomer <%d> : ",i+1);
	scanf("%d",&cost[i].balance);//put balance
	system("cls");
	}
	printf("press Enter to go back to menu : ");//going back to menu
	getchar();
	getchar();
	employe();//return to employe menu
}
void balance(int copy)//show money available
{
	system("cls");
	printf("your balance is : %d",cost[copy].balance);//show balance
	printf("\n\nAny another request : \n1_yes\n2_no \n");
	int y;
	for(;;)
	{	
		scanf("%d",&y);
		if(y==1||y==2)
			switch(y)
			{
				case 1 : custom(copy);//got back to costomer menu
				break;
				case 2 : end();//close program	
			}
		else	continue;
	}
}
void accessAcc()//customer acces
{
	int copy;//number of account
	int i, pas ,count = 0;
	system("cls");
	char accn[max];
	printf("Enter your card number : ");
	for(;;)//cheack that the number is excist or not
	{
		scanf("%s",accn);
		for(i=0;i<100;i++)//compare with all
		{
			if(strcmp(accn,cost[i].accn)==0)//finding acount
			{
				count++;
				break;
			}	
		}
		copy = i;//number of account
		if (count == 0)
			printf("The acount does not exist\nEnter the account again : ");
		if (cost[copy].balance==0)//check the account is removed or not
			{
				printf("Account has been deleted");
				recentUpdate(copy);
			}
		if (count == 1)
		
		{
			printf("Enter pasword : ");//put pasword
			scanf("%d",&pas);
			if(pas==cost[copy].accp)//check pasword
				custom(copy);
		}		
	}
}
void changePasword(int copy)//put new password
{
	system("cls");
	int pas;
	printf("Enter the new password : ");
	for(;;)
	{
		scanf("%d",&pas);
		if(pas>999) break;
		printf("short pasword ! \nput another pasword");
	}
	cost[copy].accp=pas;
		printf("\nAny another request : \n1_yes\n2_no \n");
	int y;
	for(;;)
	{	
		scanf("%d",&y);
		if(y==1||y==2)
			switch(y)
			{
				case 1 : custom(copy);//got back to costomer menu
				break;
				case 2 : end();//close program	
			}
		else	continue;
	}
}
void cash(int copy)//get the cash money
{
	system("cls");
	printf("Enter how much you want to withdraw : ");
	int money;
	scanf("%d",&money);//put how much cash you want to get
	if(money>cost[copy].balance)
	{
		printf("Not enough inventory");
		printf("\nAny another request : \n1_yes\n2_no \n");
		int y;
		scanf("%d",&y);
		switch(y)
		{
			case 1 : custom(copy);//got back to costomer menu
				break;
			case 2 : end();//close program
		}	
	}
	else
	{
		printf("\n\ntake your money");
		cost[copy].balance-=money;
		printf("\n\nthe left over is : %d",cost[copy].balance);
		printf("\n\nAny another request : \n1_yes\n2_no \n");
		int y;
		for(;;)
		{	
			scanf("%d",&y);
			if(y==1||y==2)
			switch(y)
			{
				case 1 : custom(copy);//got back to costomer menu
					break;
				case 2 : end();//close program	
			}
			else	continue;
		}
	}
}
int end()//end the program
{
	exit(0);//ending the program
}
void updateAcc()//update an acount 
{
	int i, count = 0 ,pas;
	system("cls");
	char accn[max];
	printf("Enter the card number : ");
	for(;;)//cheack that the number is excist or not
	{
		scanf("%s",accn);
		for(i=0;i<100;i++)//compare with all
		{
			if(strcmp(accn,cost[i].accn)==0)//finding acount
			{
				count++;
				break;
			}	
		}
		printf("Enter the new pasword for the account : ");
		for(;;)//check to pasword be bigger then 3 character
		{
		scanf("%d",&pas);
		if(pas>999) break;
		printf("short pasword ! \nput another pasword");
		}
		cost[i].accp=pas;
		printf("Press enter for going back to employ menu : ");
		getchar();//to cancel the last Enter
		getchar();
		employe();
		
		
	}
}
void employAcc()//check access of the employer
{
	system("cls");
	char n[max]="admin", n1[max];//user name of employer
	char p[max]="admin", p1[max];//pasword of employer
	for(;;)
	{
		printf("Enter the usename : ");
		scanf("%s",n1);//get null usename
		printf("Enter the pasword : ");
		scanf("%s",p1);//get null pasword
		if(strcmp(n,n1)==0&&strcmp(p,p1)==0)//check the user name and password
			employe();
		else
			printf("wrong username or pasword\n");
	}
}
void transfer(int copy)//transfer money betwen accounts
{
	system("cls");
	char accn2[max];
	int i, copy2, count = 0;
	printf("Enter the destination number : ");
	scanf("%s",accn2);
	for(i=0;i<100;i++)//compare with all
	{
		if(strcmp(accn2,cost[i].accn)==0)//finding acount
		{
			copy2 = i;//number of distention account
			break;
		}
			
	}
	printf("Enter the amount of money : ");
	int mon;
	scanf("%d",&mon);
	if(cost[copy].balance<mon)//checking account have anouph money to tranfer
	{
		printf("not enouph inventory ! ");
		printf("\nAny another request : \n1_yes\n2_no \n");
		int y;
		for(;;)
		{	
			scanf("%d",&y);
			if(y==1||y==2)
				switch(y)
				{
					case 1 : custom(copy);//got back to costomer menu
						break;
					case 2 : end();//close program	
				}
			else	continue;
		}
	}
	printf("transfer  %d  to < %s >",mon,cost[copy2].accn);//transfer information
	printf("\n          %s  %s\n\n",cost[copy2].fname,cost[copy2].lname);//transfer information
	printf("1_confirmation\n2_go back\n");//confirmation the transfer
	int z;
	scanf("%d",&z);
	switch(z)
	{
		case 1 : 
		{
			cost[copy].balance-=mon;//reduce money for origin card
			cost[copy2].balance+=mon;//move money to distention card
			break;
		}
		case 2 : end();
	}
	
	printf("\nAny another request : \n1_yes\n2_no \n");
	int y;
	for(;;)
	{	
		scanf("%d",&y);
		if(y==1||y==2)
			switch(y)
			{
				case 1 : custom(copy);//got back to costomer menu
					break;
				case 2 : end();//close program	
			}
		else	continue;
	}
	printf("transfer done\n");
}
void recentUpdate(int copy)//show last 10 updates
{
	
}
void deleteAcc()
{
	
}

