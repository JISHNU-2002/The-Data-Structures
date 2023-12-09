#include<stdio.h>

int main(){
    int arr[50], n, key, i, j, small, temp, low, high, mid;
    int flag=0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Elements of the array: \n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        printf("\n");
    }
    for(j=0; j<n-1; j++){
        small=j;
        for(i=j+1; i<n; i++){
            if(arr[i]<arr[small]){
                small=i;
            }
        }
        if(small!=j){
            temp=arr[small];
            arr[small]=arr[j];
            arr[j]=temp;
        }
    }
    printf("Sorted array: \n");
    for(i=0; i<n; i++){
        printf("%d \t", arr[i]);
    }
    printf("\nEnter the element to be found: ");
    scanf("%d", &key);
    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(key<arr[mid]){
            high=mid-1;
        }else if(arr[mid]==key){
            flag=1;
            break;
        }else{
            low=mid+1;
        }
    }
    if(flag==1){
        printf("Element found");
    }else{ 
        printf("Element not found");
    }
    return 0;
}

