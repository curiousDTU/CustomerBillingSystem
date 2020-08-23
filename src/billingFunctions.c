 #include<stdio.h>
 #include<string.h> //string functions
 #include<stdlib.h>
 #include<curses.h>
 #include"billingFunctions.h"
void clrscr(void)
{
    system("clear");
}


void input()
{
	printf("\nHow many customer accounts would you like to add?\t");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
  
		FILE *fp=fopen("data.dat","ab");
		fseek (fp,0,SEEK_END);
		tl=ftell(fp);
		sl=sizeof(customer);
		ts=tl/sl;
		fseek(fp,(ts-1)*sl,SEEK_SET);
		fread(&customer,sizeof(customer),1,fp);
		printf("\nCustomer no:%d\n",++customer.number);
		fclose(fp);
		printf("         Account number:\t");
		scanf("%d",&customer.acct_no);
		printf("\n        Name:\t");
		scanf("%*c%[^\n]%*c",customer.name);
		printf("\n        Mobile no:\t");
		scanf("%ld",&customer.mobile_no);
		printf("\n        Street:\t");
		scanf("%*c%[^\n]%*c",customer.street);
		printf("\n        City:\t");
		scanf("%*c%[^\n]&*c",customer.city);
		printf("\n        Previous balance:\t");
		scanf("%f",&customer.oldbalance);
		printf("\n        Current payment:\t");
		scanf("%f",&customer.payment);
		printf("\n        Payment date(mm/dd/yyyy):\t");
		scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
		printf("Account Added.");
		writeFile();
		
	}
	if(customer.payment>0){
		if(customer.payment<0.1*customer.oldbalance){ 
			customer.acct_type='O';
		}
		else{
			customer.acct_type='C';
		}
	}
	else{
		if(customer.oldbalance>0){ 
			customer.acct_type='D';
		}
		else{
			customer.acct_type='C';
		}
	}
	customer.newbalance=customer.oldbalance - customer.payment;
}
void writeFile()
{
	FILE *fp;
	fp=fopen("data.dat","ab");
	fwrite(&customer, sizeof(customer),1,fp);
	fclose(fp);
	return;
}
void search()
{	printf("\nHow would you like to search?\n");
	printf("1. Search by customer number\n");
	printf("2. Search by customer name\n");
	int ch;
	char nam[100];
	int n,i,m=1;;
	FILE *fp;
	fp=fopen("data.dat","rb");
	do{
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
	}while(ch!=1 && ch!=2);
	switch(ch){
		case 1:
			fseek(fp,0,SEEK_END);
			tl=ftell(fp);
			sl=sizeof(customer);
			ts=tl/sl;
			do{
				printf("\nEnter customer number: ");
				scanf("%d",&n);
				if(n<=0 || n>ts)
				printf("\nINVALID ACCOUNT NUMBER\n");
				else{
					fseek(fp,(n-1)*sl,SEEK_SET);
					fread(&customer,sl,1,fp);
					output();
				}
				printf("\n Want to TRY AGAIN?(YES = 1/ NO = 0)");
				scanf("%d",&ch);
			}while(ch==1);
			fclose(fp);
		break;

		case 2:
			fseek(fp,0,SEEK_END);
			tl=ftell(fp);
			sl=sizeof(customer);
			ts=tl/sl;
			fseek(fp,(ts-1)*sl,SEEK_SET);
			fread(&customer,sizeof(customer),1,fp);
			n=customer.number;

		    do{
				printf("\nEnter the name of customer:\t");
				scanf("%[^\n]%*c",nam);
				fseek(fp,0,SEEK_SET);
				for(i=1;i<=n;i++)
				{
					fread(&customer,sizeof(customer),1,fp);
					if(strcmp(customer.name,nam)==0){
						output();
						m=0;
						break;
					}
				}
				if(m!=0){
					printf("\n\nCustomer Not found\n");
				}
				printf("\nTry again?(YES = 1/NO = 0) ");
				scanf("%d", &ch);

		    }while(ch== 1);
			printf("\n");
		    fclose(fp);
		break;
	}
	return;
}
	
	
void output()
{
printf("\n\n    Customer no    :%d\n",customer.number);
	   printf("    Name 	   :%s\n",customer.name);
	   printf("    Mobile no      :%ld\n",customer.mobile_no);
	   printf("    Account number :%d\n",customer.acct_no);
	   printf("    Street         :%s\n",customer.street);
	   printf("    City           :%s\n",customer.city);
	   printf("    Old balance    :%.2f\n",customer.oldbalance);
	   printf("    Current payment:%.2f\n",customer.payment);
	   printf("    New balance    :%.2f\n",customer.newbalance);
	   printf("    Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
	   printf("    Account status :");
	   switch(customer.acct_type){
			case 'C':
			printf("CURRENT\n\n");
			break;
			case 'O':
			printf("OVERDUE\n\n");
			break;
			case 'D':
			printf("DELINQUENT\n\n");
			break;
			default:
			printf("CURRENT\n\n");
	    }
return;
}

