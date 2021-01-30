#include <stdio.h>
#include <math.h>
int main()
{
// variables
double tax;
double income;
int status;
	do {
// Status
	printf ("Enter 1-5 for filing status or 0 to quit:\n");
	printf ("1.Single\n");
	printf ("2.Married filing jointly\n");
	printf ("3.Married filing separately\n");
	printf ("4.Head of household\n");
	printf ("5.Qualifying widow(er)\n");
	printf ("0.Quit\n");
	printf ("What is your choice? ");
//identify
	
	scanf ("%d",&status);
	while (status < 0) {
	printf ("Invaild choice entered.\n ");
	scanf ("%d",&status);
	}
	while (status > 5) {
	printf ("Invalid choice entered.\n ");
	scanf ("%d", &status); 
	}	
//calculation
	//single
	if (status == 1) {
	printf ("Enter your estimated taxable income: ");
	scanf ("%lf",&income);
		if (income < 0) {
		printf("No negative income. It is reset to 0.\n ");
		income =0;
		}
		if ((income >= 0) && (income <= 9525)) { //level 1
		tax = income * 0.1;
		printf ("Your estimated tax is %.2f.\n",tax);	
		}		
		else if (income <= 38700) {  //level 2
		tax = 952.5 + (income-9525)*0.12;
		printf ("Your estimated tax is %.2f.\n",tax);
		}
		else if (income <= 82500) {//level 3
		tax = 4453.5 + (income-38700)*0.22;
		printf ("Your estimated tax is %.2f.\n",tax);
		}
		else if (income <= 157500) { // level 4
		tax = 14089.5 + (income-82500)*0.22;
		printf ("Your estimated tax is %.2f.\n",tax);
		}
		else if (income <= 200000) {// level 5
		tax = 32089.5 + (income-157500)*0.32;
		printf ("Your estimated tax is %.2f.\n",tax);
		}
		else if (income <= 500000) {// level 6
		tax = 45689.5 + (income-200000)*0.35;
		printf ("Your estimated tax is %.2f.\n",tax);
		}
		else if (income > 500000) {// level 7
		tax = 150689.5 + (income-500000)*0.37;
		printf ("Your estimated tax is %.2f.\n",tax);
		}
		 
		}
	
	// Married filing jointly & widow(er)
	else if ((status==2) ||(status==5)) {
	printf ("Enter your estimated taxable income: ");
	scanf ("%lf",&income);
		if (income < 0) {
                printf("No negative income. It is reset to 0\n ");
                income =0;
                }

		
		
		
		if ((income >= 0) && (income <= 19050)) {
		tax = income*0.1;
		printf ("Your estimated tax is %.2f.\n",tax);
		}
		
		else if(income <=77400) {
		tax = 1905 + (income-19050)*0.12;
		printf ("Your estimated tax is %.2f.\n",tax);
		}

		else if (income <= 165000) {
		tax = 8907 + (income-77400)*0.22;
		printf ("Your estimated tax is %.2f.\n",tax);
		}

		else if (income <= 315000) {
		tax = 28179 + (income-165000)*0.24;
		printf ("Your estimated tax is %.2f.\n",tax);
		}

		else if (income <= 400000) {
		tax = 64179 + (income-315000)*0.32;
		printf ("Your estimated tax is %.2f.\n",tax);
		}

		else if (income <=600000) {
		tax = 91379 + (income-400000)*0.35;
		printf ("Your estimated tax is %.2f.\n",tax);
		}

		else if (income > 600000) {
		tax = 161379 + (income - 600000)*0.37;
		printf ("Your estimated tax is %.2f.\n",tax);
		}	
		}

	//Married filing separetely
	else if (status==3) {
        printf ("Enter your estimated taxable income: ");
        scanf ("%lf",&income);
                
		if (income < 0) {
                printf("No negative income. It is reset to 0\n ");
                income =0;
                }

		
		if ((income >= 0) && (income <= 9525)) { //level 1
                tax = income * 0.1;
                printf ("Your estimated tax is %.2f.\n",tax);
                }
                else if (income <= 38700) {  //level 2
                tax = 952.5 + (income-9525)*0.12;
                printf ("Your estimated tax is %.2f.\n",tax);
                }
                else if (income <= 82500) {//level 3
                tax = 4453.5 + (income-38700)*0.22;
                printf ("Your estimated tax is %.2f.\n",tax);
                }
                else if (income <= 157500) { // level 4
                tax = 14089.5 + (income-82500)*0.22;
                printf ("Your estimated tax is %.2f.\n",tax);
		}
		else if (income <= 200000) {// level 5
                tax = 32089.5 + (income-157500)*0.32;
                printf ("Your estimated tax is %.2f.\n",tax);
                }
                else if (income <= 300000) {// level 6
                tax = 45689.5 + (income-200000)*0.35;
		printf ("Your estimated tax is %.2f.\n",tax);
                }
                else if (income > 300000) {// level 7
                tax = 80689.5 + (income-300000)*0.37;
                printf ("Your estimated tax is %.2f.\n",tax);
		}
		}

//Head of house
		else if (status==4) {
 		printf("Enter your estimated taxable income: ");
		scanf ("%lf",&income);
                if (income < 0) {
                printf("No negative income. It is reset to 0\n ");
                income =0;
                }
	
		if ((income >= 0) && (income <= 13600)) {
                tax = income*0.1;
                printf ("Your estimated tax is %.2f.\n",tax);
                }

                else if(income <=51800) {
                tax = 1360 + (income-13600)*0.12;
                printf ("Your estimated tax is %.2f.\n",tax);
                }

                else if (income <= 82500) {
                tax = 5944 + (income-51800)*0.22;
                printf ("Your estimated tax is %.2f.\n",tax);
                }

                else if (income <= 157500) {
                tax = 12698 + (income-82500)*0.24;
                printf ("Your estimated tax is %.2f.\n",tax);
                }

                else if (income <= 200000) {
                tax = 30698 + (income-157500)*0.32;
                printf ("Your estimated tax is %.2f.\n",tax);
		}

                else if (income <=500000) {
                tax = 44298 + (income-200000)*0.35;
                printf ("Your estimated tax is %.2f.\n",tax);
                }

                else if (income > 500000) {
                tax = 149298 + (income - 500000)*0.37;
                printf ("Your estimated tax is %.2f.\n",tax);
                }
       		}

	} while (status != 0);
	printf("Goodbye.\n");
	
	
return 0;
}
