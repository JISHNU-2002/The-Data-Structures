#include<stdio.h>

int main(){
    int arr[100], n, key, flag=0, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n"); 
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        printf("\n");
    }
    printf("Enter element to be found: ");
    scanf("%d", &key);
    for(i=0; i<n; i++){
        if(key==arr[i]){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Element found at position %d", i);
    }else{
        printf("Element not found");
    }
    return 0;
}

