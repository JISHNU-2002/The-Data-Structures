#include <stdio.h>
#include <ctype.h> 
char stack[100]; 
int top = -1;

void push(char x) {
    stack[++top] = x; 
}

char pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--]; 
} 

char pop2(){
    return stack[top--]; 
} 

int priority(char x) {
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
} 

int main() {
    char exp[20];
    char *e, x;
    printf("enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;
    while (*e != '\0')
    {
        if(isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else{
            while(priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
        }
    while(top != -1)
    {
        printf("%c", pop());
    }
    char Postfix[20];
    char *P;
    int n1,n2,n3,num;
    printf("\nEnter the result to calculate :: ");
    scanf("%s",Postfix);
    P = Postfix;
    while(*P != '\0')
    {
        if(isdigit(*P)){
            num = *P - 48;
            push(num);
        }else{
            n1 = pop2();
            n2 = pop2();
            switch(*P){
                case '+':
                {
                    n3 = n1 + n2;
                    break;
                }
                case '-':
                {
                    n3 = n2 - n1;
                    break;
                }
                case '*':
                {
                    n3 = n1 * n2;
                    break;
                }
                case '/':
                {
                    n3 = n2 / n1;
                    break;
                }
            }
            push(n3);
        }
        P++;
    }
    printf("\nThe result of the converted postfix %s  =  %d\n\n",Postfix,pop2());
    return 0;
}
