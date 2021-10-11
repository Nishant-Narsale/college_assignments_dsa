#include<stdio.h>

int main(){
  for(int i=0; i<100; i++){
    int operation, num1, num2;
    printf("1) Addition\n2) Substraction\n3) Division\n4) Multiplication\n");
    printf("Enter the number corresponding to operation:");
    scanf("%d",&operation);
    printf("Please Enter 1st value:");
    scanf("%d",&num1);
    printf("Please Enter 2nd value:");
    scanf("%d",&num2);
    switch (operation)
    {
    case 1:
        printf("Addition is %d\n",num1+num2);
        break;

    case 2:
        printf("Substraction is %d\n",num1-num2);
        break;

    case 3:
        printf("Division is %d\n",num1/num2);
        break;

    case 4:
        printf("Multiplication is %d\n",num1*num2);
        break;
    
    default:
        printf("Invalid Input\n");
        break;
    }
    printf("Enter 1 to continue or 0 to break:");
    int stop;
    scanf("%d",&stop);
    if(stop==1){
      continue;
    }else{
      break;
    }
  }
  return 0;
}