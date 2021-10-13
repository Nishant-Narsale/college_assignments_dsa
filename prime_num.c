#include <stdio.h>

int printPrime(int start, int end){
    if(start<=1){
        start=2;
    }

    for(int i=start; i <= end; i++){
        int isPrime = 1;
        for (int j = 2; j < i; j++)
        {
            if (i%j==0)
            {
                isPrime=0;
            }
        }
        if (isPrime==1)
        {
            printf("%d\n",i);
        }
    }
}

int main(){
    int start, end;

    printf("Enter the starting number:");
    scanf("%d",&start);

    printf("Enter the Ending number:");
    scanf("%d",&end);

    printPrime(start, end);
}