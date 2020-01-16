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
	int accp;//account password
	int balance;
	int updates;//show the account turnovers
	char last_updates[1000000];
};
FILE *ptf;//file pointer
struct customer cost[100];//variable of all costomers
void changePasword(int);//change the pasword
void accessAcc();//access to the account
void transfer(int);//transfer money betwen accounts
void balance(int);//show the money
void recentUpdate(int);//show the 10 last updates(turnovers)
void employAcc();//get access to developer
void menu();//list of main menu
void deleteAcc();//delete accounts by change thier money to 0
void updateAcc();//update the account by employer
void employe();//employer menu
void custom(int);//customer menu
void addacc();//create the new accounts
void cash(int);//get cash money
void end();//end the program
void listArchiv();//list of removed acounts
int main()
{
	int i;
	for(i=0;i<100;i++)
		cost[i].updates=0;
	for(i=0;i<100;i++)
		cost[i].balance=1;//put 1 balance for all the accounts couse of acc acces
	
	ptf = fopen("C:\\Users\\Radin\\Desktop\\project\\text.txt","a+");//geting file
	for(i=10;feof(ptf)==0;i++)
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
    	char ch;
		ch = getch();
    	if(ch=='1'||ch=='2'||ch=='3')
   			switch(ch)
  	    	{
    			case '1' :	employAcc();
    			break;
    			case '2' :	accessAcc();
    			break;
    			case '3' :	end();
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
	char ch;
	for(;;)
	{
		ch = getch();
		if(ch == '1'||ch == '2'||ch == '3'||ch == '4'||ch == '5')
		{
			switch(x)
    		{
    			case '1' : addacc();//create account
    				break;
   		 		case '2' : updateAcc();//update account
   			 		break;
    			case '3' : deleteAcc();//remove account
					break;
				case '4' : listArchiv();//list of remove accounts	
					break;
				case '5' : menu();//back to menue
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
	int copy = n;
	char ch;
	for(;;)
	{	
		ch = getch();
		if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6')
		switch(ch)
	    {
	    	case '1' :	balance(copy);
	    		break;
	    	case '2' :	transfer(copy);
	    		break;
	    	case '3' :	cash(copy);
				break;
			case '4' :	recentUpdate(copy);
				break;
			case '5' :	changePasword(copy);
				break;
			case '6' :	menu();
				break;
		}
	}	
}
void addacc()//create the acounts
{
	system("cls");
	int n ,i;
	printf("Enter the first name : ");
	scanf("%s",cost[i].fname);
	fprintf(ptf,"%s ",cost[i].fname);
	printf("Enter the last name : ");
	scanf("%s",cost[i].lname);
	fprintf(ptf,"%s ",cost[i].lname);
	printf("Enter the account number <%d> : ",i+1);
	scanf("%s",cost[i].accn);//put card number
	fprintf(ptf,"%s ",cost[i].accn);
	printf("Enter the account pasword <%d> : ",i+1);
	for(;;)//only pass more then 4 number 
	{
		scanf("%d",&cost[i].accp);//get pasword
		if(cost[i].accp < 999)
			printf("Short pasword!\nEnter another pasword <%d> : ",i+1);
		else
		{
			fprintf(ptf,"%d ",cost[i].accp);
			break;
		}
	}	
	printf("Enter the lnitial balance costomer <%d> : ",i+1);
	scanf("%d",&cost[i].balance);//put balance
	fprintf(ptf,"%d\n",cost[i].balance);
	system("cls");
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
	char ch;
	for(;;)
	{	
		ch = getch();
		if(ch == '1'||ch == '2')
			switch(ch)
			{
				case '1' : custom(copy);//got back to costomer menu
				break;
				case '2' : end();//close program	
			}
		else	continue;
	}
}
void accessAcc()//customer acces
{
	int i, pas, count = 0, copy;//copy = number of account 
	system("cls");
	char accn[max];
	printf("Enter your card number : ");
	for(;;)//cheack that the number is excist or not
	{
		scanf("%s",accn);
		for(i=0 ;i<100 ;i++)//compare with all
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
		if (cost[copy].balance==0&&count==1)//check the account is removed or not
		{
			printf("Account has been deleted");
			recentUpdate(copy);
		}
		if (count == 1)
		{
			printf("Enter pasword : ");//put pasword
			scanf("%d",&pas);
			if(pas == cost[copy].accp)//check pasword
				custom(copy);
		}		
	}
}
void changePasword(int copy)//put new password
{
	system("cls");
	int pas;
	printf("Enter the new password : ");//put the new password
	for(;;)
	{
		scanf("%d",&pas);//check that pass is more then 4 number
		if(pas > 999) break;
		printf("short pasword ! \nput another pasword");
	}
	cost[copy].accp=pas;//chenge password
		printf("\nAny another request : \n1_yes\n2_no \n");
	char ch;
	for(;;)
	{	
		ch = getch();
		if(ch == '1'||ch == '2')
			switch(ch)
			{
				case '1' : custom(copy);//got back to costomer menu
					break;
				case '2' : end();//close program
					break;	
			}
		else	continue;
	}
}
void cash(int copy)//get the cash money
{
	system("cls");
	printf("Enter how much you want to withdraw : ");
	int money;
	char ch;
	scanf("%d",&money);//put how much cash you want to get
	if(money >= cost[copy].balance)
	{
		printf("Not enough inventory");
		printf("\nAny another request : \n1_yes\n2_no \n");
		for(;;)
		{	
			ch = getch();
			if(ch == '1'||ch == '2')
				switch(ch)
				{
					case '1' : custom(copy);//got back to costomer menu
					break;
					case '2' : end();//close program	
				}
			else	continue;
		}
	}
	else
	{
		printf("\n\ntake your money");//get money 
		cost[copy].balance -= money;//low off money
		cost[copy].updates++;
		snprintf(cost[copy].last_updates, sizeof(cost[copy].last_updates), "%scash withdrawal         %d\n\n",cost[copy].last_updates,money);//put variables in string
		printf("\n\nthe left over is : %d",cost[copy].balance);//show the money left
		printf("\n\nAny another request : \n1_yes\n2_no \n");
		for(;;)
		{	
			ch = getch();
			if(ch == '1'||ch == '2')
				switch(ch)
				{
					case '1' : custom(copy);//got back to costomer menu
						break;
					case '2' : end();//close program
						break;	
				}
			else	continue;
		}
	}
}
void end()//end the program
{
	fclose(ptf);
	exit(0);//ending the program
}
void updateAcc()//update an acount 
{
	int i, count = 0, pas;
	system("cls");
	char accn[max];
	printf("Enter the card number : ");
	for(;;)//cheack that the number is excist or not
	{
		scanf("%s",accn);
		for(i=0 ; i<100 ; i++)//compare with all
		{
			if(strcmp(accn,cost[i].accn) == 0)//finding acount
			{
				count++;
				break;
			}
		}
		if(count == 0)
		{
			printf("The account does not exist");
			printf("\nEnter the card number again : ");
			continue;//go to first
		}
		printf("Enter the new first name : ");
		scanf("%s",cost[i].fname);//chenge first name
		printf("Enter the new last name : ");
		scanf("%s",cost[i].lname);//chenge last name
		printf("Enter the new pasword for the account : ");
		for(;;)//check to pasword be bigger then 3 character
		{
			scanf("%d",&pas);
			if(pas > 999) 
				break;//check password
			printf("short pasword ! \nput another pasword");
		}
		cost[i].accp = pas;
		printf("Press enter for going back to employ menu : ");
		getchar();//to cancel the last Enter
		getchar();
		employe();	
	}
}
void employAcc()//check access of the employer
{
	system("cls");
	char n[max] = "admin", n1[max];//user name of employer
	char p[max] = "admin", p1[max];//pasword of employer
	for(;;)
	{
		printf("Enter the username : ");
		scanf("%s",n1);//get null usename
		printf("Enter the pasword : ");
		scanf("%s",p1);//get null pasword
		if(strcmp(n,n1) == 0 && strcmp(p,p1) == 0)//check the user name and password
			employe();
		else
			printf("wrong username or pasword\n");
	}
}
void transfer(int copy)//transfer money betwen accounts
{
	system("cls");
	char accn2[max],update[max];//,massage1[max]="\nThe transfer   ",massage2[max]="\nreceive    ";
	int i, copy2, count = 0, money;
	printf("Enter the destination number : ");
	scanf("%s",accn2);
	for(i=0;i<100;i++)//compare with all
	{
		if(strcmp(accn2,cost[i].accn) == 0)//finding acount
		{
			copy2 = i;//number of distention account
			count++;
			break;
		}		
	}
	if(count==0)
		{
		printf("the acount does not exist ");
		end();
		}
	printf("Enter the amount of money : ");
	scanf("%d",&money);
	if(cost[copy].balance < money)//checking account have anouph money to tranfer
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
	printf("transfer  %d  to < %s >",money,cost[copy2].accn);//transfer information
	printf("\n          %s  %s\n\n",cost[copy2].fname,cost[copy2].lname);//transfer information
	printf("1_confirmation\n2_go back\n");//confirmation the transfer
	int z;
	scanf("%d",&z);
	switch(z)
	{
		case 1 : 
		{
			cost[copy].balance -= money;//reduce money for origin card
			cost[copy2].balance += money;//move money to distention card
			cost[copy].updates++;
			snprintf(cost[copy].last_updates, sizeof(cost[copy].last_updates), "%sTransfer %d to %s\n\n",cost[copy].last_updates,money,cost[copy2].accn);//put variables in string
			snprintf(cost[copy2].last_updates, sizeof(cost[copy2].last_updates), "%sRecive %d from %s\n\n",cost[copy2].last_updates,money,cost[copy].accn);//put variables in string	
			break;
		}
		case 2 : end();
	}
	printf("\n\n\nAny another request : \n1_yes\n2_no \n");
	int y;
	for(;;)
	{	
		scanf("%d",&y);
		if(y == 1||y == 2)
			switch(y)
			{
				case 1 :	custom(copy);//got back to costomer menu
					break;
				case 2 :	end();//close program	
			}
		else	continue;
	}
	printf("transfer done\n");
}
void recentUpdate(int copy)//show last 10 updates
{
	system("cls");
	printf("%s",cost[copy].last_updates);
	printf("\n\n\nAny another request : \n1_yes\n2_no \n");
	char ch;
	for(;;)
	{	
		ch = getch();
		if(ch == '1'||ch == '2')
			switch(ch)
			{
				case '1' :	custom(copy);//got back to costomer menu
					break;
				case '2' :	end();//close program	
					break;
			}
		else	continue;
	}	
}
void deleteAcc()//delect accounts
{
	int i, count = 0, x;
	system("cls");
	char accn[max],ch;
	printf("Enter the card number : ");//get the card number
	for(;;)
	{
		scanf("%s",accn);
		for(i=0;i<100;i++)//compare with all
		{
			if(strcmp(accn,cost[i].accn) == 0)//finding acount
			{
				count++;
				break;
			}
		}
		if(count == 1);//find the account
			break;
		printf("The acount does not exist\n");
		printf("Enter the account again : ");
	}
	system("cls");
	printf("The account < %s > ",cost[i].accn);//the acount informations
	printf("by name ( %s %s )",cost[i].fname,cost[i].lname);//the acount informations
	printf("\nAre you sure you want to delete this acount :");
	printf(" \n1_Yes\n2_No\n3_Go to employee menu\n");//request permission
	for(;;)
	{
		ch = getch();
		if(ch == '1'||ch == '2'||ch == '3')
		switch(ch)
		{
			case '1' : 
			{	
				cost[i].balance = 0;//delete account by put tha balance 0;
				printf("Account deleted\n");
				printf("/n/nPress Enter to go back menu");
				getchar();
				getchar();	
				employe();//going back to menu	
			}
			case '2' : deleteAcc();//change the account that want to remove
				break;
			case '3' : employe();//go back to menu
				break;
		}	
	}
}
void listArchiv()//show the list of removed accounts
{
	system("cls");
	int i, count = 0;
	for(i=0 ; i<99 ; i++)//check all acounts
	{
		if(cost[i].balance == 0)//find accounts whose money is zero
		{
			count++;//to make list
			printf("%d_account number < %s >",count, cost[i].accn);//acount informations
			printf(" by name %s %s\n",cost[i].fname, cost[i].lname);//acount informations
		}
	}
	printf("Push Enter to go back menu");
	getchar();
	getchar();
	employe();//go back to menu
}
