/* 
A project on "Customer Billing System"
**This project is the developed by students of section F (CC& GAG) batch 2019, 

Department of Computer Science and Engineering, Faculty of Engineering and Technology, 
=======
Department of Computer Science and Enineering, Faculty of Engineering and Technology, 

Manav Rachna International Institute of Research & Studies.  
*/
#include <stdio.h>
#include<stdlib.h> 
#include "billingFunctions.h"
 
 
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

 int main()
{
 	  int ch;
	do{
	  printf("   CUSTOMER BILLING SYSTEM:\n\n");
	  printf("===============================\n");
	  printf("\n1:   To add account on list\n");
	  printf("2:   To search customer account\n");
	  printf("3:   Exit\n");
	  printf("\n================================\n");

	  printf("\nselect what do you want to do?");
	  scanf("%d",&ch);
	  switch(ch)
		{
	 		case 1:input();
				 break;
		
		 	case 2:search();
			   	 break;
		 	case 3: exit(1);	
		}	


	 }while( ch>=1 || ch<3);

	 }while( ch>=0||ch<3);

  }



