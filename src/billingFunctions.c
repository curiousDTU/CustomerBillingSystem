 #include<stdio.h>
 #include<string.h> //string functions
 #include<stdlib.h>
 #include<curses.h>
 #include<billingFunctions.h>



void input()
{

  int tl,sl,ts;
  struct date{
	   int month;
	   int day;
	   int year;
	   };

   struct account {
	int number;
	char name[100];
	int acct_no;
	float mobile_no;
	char street[100];
	char city[100];
	char acct_type;
	float oldbalance;
	float newbalance;
	float payment;
	struct date lastpayment;
  }customer;
  
 	FILE *fp=fopen("aadarsh.dat","rb");
	  fseek (fp,0,SEEK_END);
	  tl=ftell(fp);
	  sl=sizeof(customer);
	  ts=tl/sl;
	  fseek(fp,(ts-1)*sl,SEEK_SET);
	  fread(&customer,sizeof(customer),1,fp);
	  printf("\ncustomer no:%d\n",++customer.number);
	  fclose(fp);
	  printf("         Account number:");
	  scanf("%d",&customer.acct_no);
	  printf("\n       Name:");
	  scanf("%s",customer.name);
	  printf("\n       mobile no:");
	  scanf("%f",&customer.mobile_no);
	  printf("         Street:");
	  scanf("%s",customer.street);
	  printf("         City:");
	  scanf("%s",customer.city);
	  printf("         Previous balance:");
	  scanf("%f",&customer.oldbalance);
	  printf("         Current payment:");
	  scanf("%f",&customer.payment);
	  printf("         Payment date(mm/dd/yyyy):");
	  scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
	  return;
   }
 	


 	printf("inside input()\n");
 	writeFile();
	return;
}

void writeFile()
{
	printf("inside writeFile()\n");
	return;
}
void search()
{
	printf("inside search()\n");
	output(); 
	return;
}
void output()
{
printf("inside output()\n");
return;
}

