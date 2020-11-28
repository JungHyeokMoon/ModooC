#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("input number of array : ");
    scanf("%d", &n);

    int * arr=(int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    
    printf("\n");
    free(arr);
    arr=(int *)malloc(sizeof(int)*(n+5));
    for(int i=0; i<n+5; i++)
        scanf("%d",&arr[i]);
    for(int i=0; i<n+5; i++)
        printf("%d ",arr[i]);
    
    free(arr);
    return 0;
}