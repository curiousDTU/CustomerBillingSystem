 /* include file */
 
 void input();
 void writeFile();
 void search();
 void output();
 void clrscr(void);

struct date{
	int month;
	int day;
	int year;
};

struct account{
	int number;
	char name[100];
	int acct_no;
	long int mobile_no;
	char street[100];
	char city[100];
	char acct_type;
	float oldbalance;
	float newbalance;
	float payment;
	struct date lastpayment;
}customer;
int tl,sl,ts,n;
