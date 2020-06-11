/*
Design, develop and implement a C/Java program to generate the machine code using Triples for the statement 
A = -B * (C + D) 
whose intermediate code in three-address form is:
T1 = -B
T2 = C + D
T3 = T1 + T2 
A = T3
*/

#include<stdio.h>
#include<string.h>

int main() {
	char icode[10][30], optr;
	char op1[5], op2[5], res[5];
	int i=0, n, j, k;
	
	printf("Enter the no. of intermediate statements: ");
	scanf("%d",&n);
	
	printf("\nEnter the set of intermediate code:\n");
	for(i=0;i<n;i++)
		scanf("%s",icode[i]);
	printf("\n");
	
	for(i=0;i<n;i++) {
		j=0; k=0;
		while(icode[i][j]!='=') {
			res[k] = icode[i][j];
			j = j+1;
			k = k+1;
		}
		res[j] = '\0';
		k = 0;
		j++;
		
		if(icode[i][j]=='-') {
			j++;
			while(icode[i][j]!='\0') {
				op1[k] = icode[i][j];
				j++;
				k++;
			}
			op1[k] = '\0';
			printf("\nLOAD R1,%s\n",op1);
			printf("NEG R1\n");
			printf("STORE R1,%s\n",res);
		} else {
			k=0;
			while(icode[i][j]!='\0' && icode[i][j]!='+' 
				&& icode[i][j]!='-' && icode[i][j]!='*') {
				op1[k]=icode[i][j];
				j++; k++;
			}

			op1[k]='\0';
			
			if(icode[i][j]=='\0') {
				printf("\nLOAD R1,%s\n",op1);
				printf("STORE %s,R1\n",res);
				continue;
			} else {
				optr=icode[i][j];
				k=0;j++;
				while(icode[i][j]!='\0') {
					op2[k] = icode[i][j];
					j++; k++;
				}
				op2[k]='\0';
			}
			
			switch(optr) {
				case '+':
					printf("\nLOAD R2,%s\n",op1);
					printf("LOAD R3,%s\n",op2);
					printf("ADD R2,R3\n");
					printf("STORE R2,%s\n",res);
					break;
				
				case '-':
					printf("\nLOAD R2,%s\n",op1);
					printf("LOAD R3,%s\n",op2);
					printf("SUB R2,R3\n");
					printf("STORE R2,%s\n",res);
					break;
				
				case '*':
					printf("\nLOAD R1,%s\n",op1);
					printf("LOAD R2,%s\n",op2);
					printf("MUL R1,R2\n");
					printf("STORE R1,%s\n",res);
					break;

				default: printf("\nInvalid Statement!!\n");
			}
		}
	}
	return 0;
}
