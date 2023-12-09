#include<stdio.h>

int main(){
    int arr[50], n, key, i, j;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Elements of the array: \n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        printf("\n");
    }
    for(j=1; j<=n; j++){
        key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
    printf("Sorted array: ");
    for(i=1; i<=n; i++){
        printf("%d \t", arr[i]);
    }
    return 0;
}

