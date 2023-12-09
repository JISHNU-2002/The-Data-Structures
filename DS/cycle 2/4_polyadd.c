#include<stdio.h>
#define max 100
typedef struct{
	int exp;
	int coeff;
}pol;
pol term[max];
void main(){
	int sA,sB,sC,fA,fB,fC;
	int i,j,p,q,c;
	printf("Enter the no of elements in polynomial 1 = ");
	scanf("%d",&p);
	printf("Enter the no of elements in polynomial 2 = ");
	scanf("%d",&q);
	sA=0;
	fA=p-1;
	sB=p;
	fB=p+q-1;
	sC=p+q;
	for(i=0;i<p;i++){
		printf("Coeff of 1st at index position %d = ",i);
		scanf("%d",&term[i].coeff);
		printf("Exp of 1st at index position %d = ",i);
		scanf("%d",&term[i].exp);
	}
	for(i=p;i<p+q;i++){
		printf("Coeff of 2nd at index position %d = ",(i-p));
		scanf("%d",&term[i].coeff);
		printf("Exp of second at index position %d = ",(i-p));
		scanf("%d",&term[i].exp);
	}
	while((sA<=fA) && (sB<=fB)){
		if(term[sA].exp > term[sB].exp){
			term[sC].exp=term[sA].exp;
			term[sC].coeff=term[sA].coeff;
			sA++;
			sC++;
		}
		else if(term[sA].exp < term[sB].exp){
			term[sC].exp=term[sB].exp;
			term[sC].coeff=term[sB].coeff;
			sB++;
			sC++;
		}
		else{
			c = term[sA].coeff + term[sB].coeff;
			if(c!=0){
				term[sC].exp= term[sA].exp;
				term[sC].coeff= c;
				sA++;
				sB++;
				sC++;
			}
		}
	}
	while(sA<=fA){
		term[sC].exp=term[sA].exp;
		term[sC].coeff=term[sA].coeff;
		sA++;
		sC++;
	}
	while(sB<=fB){
		term[sC].exp=term[sB].exp;
		term[sC].coeff=term[sB].coeff;
		sB++;
		sC++;
	}
	printf("The added polynomial is = ");
	for(i=(p+q);i<sC-1;i++){
		printf("%d x^%d +",term[i].coeff,term[i].exp);
	}
	printf("%d x^%d ",term[i].coeff,term[i].exp);
}

