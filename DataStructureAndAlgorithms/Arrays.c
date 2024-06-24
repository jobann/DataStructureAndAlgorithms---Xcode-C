//
//  Arrays.c
//  DataStructureAndAlgorithms
//
//  Created by Jobanpreet Singh on 2024-06-24.
//

#include <stdio.h>
#include <stdlib.h>

//Define structure of the array
struct Array{
    int *A;
    int size;
    int length;
};

//Display the Array
void display(struct Array arr){
    printf("Displaying array of size: %d and length: %d:\n", arr.size, arr.length);
    
    for(int i=0;i<arr.length;i++){
        printf("%d\n", arr.A[i]);
    }
    
}

// Append an element at the end of the Array
void append(struct Array *arr, int x){
    
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
    
}

// Insert an element at the given index in the Array
void insert(struct Array *arr, int index, int x){
    if( index >=0 && index <= arr->length && arr->length < arr->size ){
        
        //Shifting elements to the right
        for(int i=arr->length; i>=index; i--){
            arr->A[i] = arr->A[i-1];
        }
        
        arr->A[index] = x;
        arr->length++;
        
    }else if(arr->length >= arr->size){
        printf("Index out of size!\n");
    }
    
}

// Deleting an element from the given index of the Array and returning the value of the element
int delete(struct Array *arr, int index){
    
    int value = arr->A[index];
    
    for(int i= index; i < arr->length; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
    return value;
}

int main(int argc, const char * argv[]) {
    
    struct Array arr;
    arr.length=0;
    int i,flag=1,n;
    char input;
    
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
    
    while(flag){
        printf("\n***Menu***\n1. Append an element\n2. Insert an element\n3. Display Array\n4. Delete from an index\n5. Exit\nSelect an option: ");
        fflush(stdin);
        scanf("%c", &input);
        
        switch(input){
            case '1':
                printf("Enter the element to append: ");
                scanf("%d", &n);
                append(&arr, n);
                break;
            case '2':
                printf("Enter the element to insert: ");
                scanf("%d", &n);
                printf("Enter the index of the element: ");
                scanf("%d", &i);
                insert(&arr, i, n);
                break;
            case '3':
                display(arr);
                break;
            case '4':
                printf("Enter the index of the element to be delete: ");
                scanf("%d", &i);
                printf("Deleted element: %d", delete(&arr, i));
                break;
            case '5':
                flag=0;
                printf("\nBye...\n\n");
                break;
            default:
                printf("\nInvalid Option!\n");
                break;
                
        }
        
        
    }
    
    
    
   
    
    return 0;
}
