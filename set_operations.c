#include <stdio.h>
#define SIZE 5

void accept(int *ptr);
void display(int *ptr, int n);
int find_unioun(int array1[], int array2[], int * unioun_array);
int find_intersection(int array1[], int array2[], int * intersection_array);
int find_difference(int array1[], int array2[], int * difference_array);
int find_semantic_difference_unioun(int array1[], int array2[], int * semantic_difference_array, int difference_1_size, int difference_2_size);


int main(){
    int array1[SIZE], array2[SIZE], unioun_array[2*SIZE], intersection_array[SIZE], difference_array_1[SIZE], difference_array_2[SIZE], semantic_difference_array[SIZE], n, i, j;

    printf("Enter First Set :\n");
    accept(array1);
    display(array1, SIZE);

    printf("Enter Second Set :\n");
    accept(array2);
    display(array2, SIZE);

    n = find_unioun(array1, array2, unioun_array);
    printf("Unioun Array :");
    display(unioun_array, n);

    n = find_intersection(array1, array2, intersection_array);
    printf("Intersection Array :");
    display(intersection_array, n);

    i = find_difference(array1, array2, difference_array_1);
    printf("A - B :");
    display(difference_array_1, i);

    j = find_difference(array2, array1, difference_array_2);
    printf("B - A :");
    display(difference_array_2, j);

    n = find_semantic_difference_unioun(difference_array_1, difference_array_2, semantic_difference_array, i, j);
    printf("Semantic Difference Array :");
    display(semantic_difference_array, n);

    return 0;
}

void accept(int *ptr){
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter %d th element :",i+1);
        scanf("%d",&ptr[i]);
    }
}

void display(int *ptr, int n){
    printf("{");
    for (int i = 0; i < n; i++)
    {
        if (i==n-1)
        {
            printf(" %d ",ptr[i]);
        }
        else{
            printf(" %d,",ptr[i]);
        }
    }
    printf("}\n\n");
}

int find_unioun(int array1[], int array2[], int * unioun_array){
    int k = 0;

    //adding all elements from first array
    for (int i = 0; i < SIZE; i++)
    {
        unioun_array[k] = array1[i];
        k++;
    }

    //adding elements of array2 which are not in array1
    for (int i = 0; i < SIZE; i++)
    {
        int j=0;
        for (j = 0; j < SIZE; j++)
        {
            if (array2[i]==array1[j])
            {
                break;
            }
        }
        if (j==SIZE)
        {
            unioun_array[k] = array2[i];
            k++;
        }
    }
    return k;
}

int find_intersection(int array1[], int array2[], int * intersection_array){
    int k=0;

    //if element is present in both adding them to new array
    for (int i = 0; i < SIZE; i++)
    {
        int j=0;
        for (j = 0; j < SIZE; j++)
        {
            if (array1[i]==array2[j])
            {
                intersection_array[k] = array1[i];
                k++;
                break;
            }
        }
    }
    return k;

}

int find_difference(int array1[], int array2[], int * difference_array){
    int k=0;

    for (int i = 0; i < SIZE; i++)
    {
        int j=0;
        for (j = 0; j < SIZE; j++)
        {
            if (array1[i]==array2[j])
            {
                break;
            }
        }
        if (j==SIZE)
        {
            difference_array[k] = array1[i];
            k++;
        }
    }
    return k;
}
int find_semantic_difference_unioun(int array1[], int array2[], int * semantic_difference_array, int difference_1_size, int difference_2_size){
    int k = 0;

    //adding all elements from first array
    for (int i = 0; i < difference_1_size; i++)
    {
        semantic_difference_array[k] = array1[i];
        k++;
    }

    //adding elements of array2 which are not in array1
    for (int i = 0; i < difference_1_size; i++)
    {
        int j=0;
        for (j = 0; j < difference_2_size; j++)
        {
            if (array2[i]==array1[j])
            {
                break;
            }
        }
        if (j==difference_2_size)
        {
            semantic_difference_array[k] = array2[i];
            k++;
        }
    }
    return k;
}