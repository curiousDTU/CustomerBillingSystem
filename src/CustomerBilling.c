/* 
A project on "Customer Billing System"
**This project is the developed by students of section F (CC& GAG) batch 2019, 

Department of Computer Science and Engineering, Faculty of Engineering and Technology, 
=======
Department of Computer Science and Enineering, Faculty of Engineering and Technology, 

Manav Rachna International Institute of Research & Studies.  
*/
#include <stdio.h>
#include <stdlib.h> 
#include "billingFunctions.h"



int main()
{
 	int op;
	do{
	  clrscr();
	  printf("\n\n   CUSTOMER BILLING SYSTEM:\n\n");
	  printf("===============================\n");
	  printf("\n1:   To add account on list\n");
	  printf("2:   To search customer account\n");
	  printf("3:   Exit\n");
	  printf("\n================================\n");

	  printf("\nPlease select what do you want to do?\t");
	  scanf("%d",&op);
	  switch(op)
		{
	 		case 1: input();
			break;
		
		 	case 2: search();
			break;

		 	case 3: printf("Project By Manav Rachna FOSS group\n");
			 		exit(1);	
		}	


	}while( op>0 && op<4);
	return 0;

}



