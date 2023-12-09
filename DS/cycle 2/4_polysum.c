#include<stdio.h>

struct poly{
    float coeff;
    int exp;
};

struct poly terms[100];

int main(){
    int sa=0, fa, n1, sb, fb, sc, fc, c, n2, i;
    printf("Number of terms of first polynomial: ");
    scanf("%d", &n1);
    fa=n1-1;
    sb=n1;
    printf("Enter the coefficients: ");
    for(i=0; i<=fa; i++){
        scanf("%f", &terms[i].coeff);
    }
    printf("Enter the exponents in decreasing order: ");
    for(i=0; i<=fa; i++){
        scanf("%d", &terms[i].exp);
    }
    printf("Number of terms of second polynomial: ");
    scanf("%d", &n2);
    fb=n1+n2-1;
    printf("Enter the coefficients: ");
    for(i=n1; i<=fb; i++){
        scanf("%f", &terms[i].coeff);
    }
    printf("Enter the exponents in decreasing order: ");
    for(i=n1; i<=fb; i++){
        scanf("%d", &terms[i].exp);
    }
    printf("\nFirst poynomial: \n");
    for(i=0; i<=fa-1; i++){
        printf("%fx^%d+", terms[i].coeff, terms[i].exp);
    }
    printf("%fx^%d", terms[fa].coeff, terms[fa].exp);
    printf("\nSecond poynomial: \n");
    for(i=n1; i<fb; i++){
        printf("%fx^%d+", terms[i].coeff, terms[i].exp);
    }
    printf("%fx^%d", terms[fb].coeff, terms[fb].exp);
    sc=fb+1;
    while(sa<=fa && sb<=fb){
        if(terms[sa].exp > terms[sb].exp){
            terms[sc].coeff=terms[sa].coeff;
            terms[sc].exp=terms[sa].exp;
            sa++;
            sc++;
        }else if(terms[sa].exp < terms[sb].exp){
            terms[sc].coeff=terms[sb].coeff;
            terms[sc].exp=terms[sb].exp;
            sb++;
            sc++;
        }else{
            c=terms[sa].coeff+terms[sb].coeff;
            terms[sc].coeff=c;
            terms[sc].exp=terms[sb].exp;
            sa++;
            sb++;
            sc++;
        }
    }
    while(sa<=fa){
        terms[sc].coeff=terms[sa].coeff;
        terms[sc].exp=terms[sa].exp;
        sa++;
        sc++;
    }
    while(sb<=fb){
        terms[sc].coeff=terms[sb].coeff;
        terms[sc].exp=terms[sb].exp;
        sb++;
        sc++;
    }
    printf("\n Sum: ");
    for(i=fb+1; i<sc; i++){
        printf("%fx^%d+", terms[i].coeff, terms[i].exp);
    }
    printf("%fx^%d+", terms[sc].coeff, terms[sc].exp);
    return 0;
}





