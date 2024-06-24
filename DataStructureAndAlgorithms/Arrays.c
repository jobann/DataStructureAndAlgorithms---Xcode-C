//
//  Arrays.c
//  DataStructureAndAlgorithms
//
//  Created by Jobanpreet Singh on 2024-06-24.
//

#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};


void display(struct Array arr){
    printf("Displaying array:\n");
    
    for(int i=0;i<arr.length;i++){
        printf("%d\n", arr.A[i]);
    }
    
}


int main(int argc, const char * argv[]) {
    
    struct Array arr;
    arr.length=0;
    int i,n;
    
    printf("Enter  the size of the array: ");
    scanf("%d", &arr.size);
    
    arr.A = (int *) malloc( sizeof(int) * arr.size);
    
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    
    
    for(i=0;i<n;i++){
        printf("Enter the element[%d]: ",i);
        scanf("%d", &arr.A[i]);
        arr.length++;
    }
    
    display(arr);
    
    return 0;
}
