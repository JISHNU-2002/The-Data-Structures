#include<stdio.h>
#define max 100

int main(){
    int a[50][50], b[max+1][3], t[max+1][3];
    int r, c, i, j, k=1, f=1;

    printf("Enter the no. of rows: ");
    scanf("%d", &r);
    printf("Enter the no. of columns: ");
    scanf("%d", &c);
    printf("Enter the elements of the array: ");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d", &a[i][j]);
        }   
    }
    printf("Sparse matrix: \n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            printf("%d \t ", a[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(a[i][j]!=0){
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    int n;
    b[0][0]=r;
    b[0][1]=c;
    b[0][2]=k-1;
    n=b[0][2];
    printf("Tuple form: \n");
    for(i=0; i<k; i++){
        printf("%d \t %d \t %d \n", b[i][0], b[i][1], b[i][2]);
    }

    t[0][0]=b[0][1];
    t[0][1]=b[0][0];
    t[0][2]=b[0][2];

    for(i=0; i<c; i++){
        for(j=1; j<=n; j++){
            if(b[j][1]==i){
                t[f][0]=i;
                t[f][1]=b[j][0];
                t[f][2]=b[j][2];
                f++;
            }
        }
    }
    printf("Transpose: \n");
    for(i=0; i<=n; i++){
        printf("%d \t %d \t %d \n", t[i][0], t[i][1], t[i][2]);
    }
    return 0;
}


