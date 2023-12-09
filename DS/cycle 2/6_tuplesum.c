#include<stdio.h>
#define max 100

int main(){
    int a[50][50], A[max][3], b[50][50], B[max][3], r1, c1, r2, c2, i, j, n, n1, n2, S[50][3];
    int k=1, k1=1, k2;
    printf("Enter the no. of rows of first matrix: ");
    scanf("%d", &r1);
    printf("Enter the no. of columns of first matrix: ");
    scanf("%d", &c1);
    printf("Enter the no. of rows of second matrix: ");
    scanf("%d", &r2);
    printf("Enter the no. of columns of second matrix: ");
    scanf("%d", &c2);
    printf("Enter the elements of the first matrix: ");
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Sparse matrix: \n");
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            printf("%d \t ", a[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            if(a[i][j]!=0){
                A[k][0]=i;
                A[k][1]=j;
                A[k][2]=a[i][j];
                k++;
            }
        }
    }
    A[0][0]=r1;
    A[0][1]=c1;
    A[0][2]=k-1;
    n=A[0][2];
    printf("Tuple form of first matrix: \n");
    for(i=0; i<k; i++){
        printf("%d \t %d \t %d \n", A[i][0], A[i][1], A[i][2]);
    }
    printf("Enter the elements of the second matrix: ");
    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            scanf("%d", &b[i][j]);
        }
    }
    printf("Sparse matrix: \n");
    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            printf("%d \t ", b[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            if(b[i][j]!=0){
                B[k1][0]=i;
                B[k1][1]=j;
                B[k1][2]=b[i][j];
                k1++;
            }
        }
    }
    B[0][0]=r2;
    B[0][1]=c2;
    B[0][2]=k1-1;
    n=B[0][2];
    printf("Tuple form of second matrix: \n");
    for(i=0; i<k1; i++){
        printf("%d \t %d \t %d \n", B[i][0], B[i][1], B[i][2]);
    }
    if(A[0][0]!=B[0][0] || A[0][1]!=B[0][1]){
        printf("Invalid matrix");
        exit(0);
    }
    n1=A[0][2];
    n2=B[0][2];
    S[0][0]=A[0][0];
    S[0][1]=A[0][1];
    i=0;
    j=0;
    k2=0;

    while(i<=n1&&j<=n2){
        if(A[i][0]<B[j][0]){
            S[k2][0]=A[i][0];
            S[k2][1]=A[i][1];
            S[k2][2]=A[i][2];
            i++;
            k2++;
        }else if(B[j][0]<A[i][0]){
            S[k2][0]=B[j][0];
            S[k2][1]=B[j][1];
            S[k2][2]=B[j][2];
            j++;
            k2++;
        }else if(A[j][1]<B[i][1]){
            S[k2][0]=A[i][0];
            S[k2][1]=A[i][1];
            S[k2][2]=A[i][2];
            i++;
            k2++;
        }else if(B[j][1]<A[i][1]){
            S[k2][0]=B[j][0];
            S[k2][1]=B[j][1];
            S[k2][2]=B[j][2];
            j++;
            k2++;
        }else{
            S[k2][1]=A[i][1];
            S[k2][2]=A[i][2]+B[i][2];
            i++;
            j++;
            k2++;
        }
    }
    while(i<=n1){
        S[k2][0]=A[i][0];
        S[k2][1]=A[i][1];
        S[k2][2]=A[i][2];
        i++;
        k2++;
    }
    while(j<=n2){
        S[k2][0]=B[j][0];
        S[k2][1]=B[j][1];
        S[k2][2]=B[j][2];
        j++;
        k2++;
    }
    S[0][2]=k2-1;
    printf("\n Sum: \n");
    for(i=0; i<k2; i++){
        printf("%d \t %d \t %d \n", S[i][0], S[i][1], S[i][2]);
    }
    return 0;
}
