#include <stdio.h>
#include <string.h>

struct STORE
    {
        int code;
        char name[10];
        int price;
        int quantity;
    }products[10],productsToBuy[10];

int displayProduct(struct STORE * product){
    printf("\t%d\t%s\t%d\n",product->code,product->name,product->price);
}

int main(){
    int total_price = 0,i=1,j=1,ctr=0,newctr=0;

    while (i==1)
    {
        printf("***Enter a new product***\n");
        printf("Enter Product code :");
        scanf("%d",&products[ctr].code);
        printf("Enter Product name :");
        scanf("%s",products[ctr].name);
        printf("Enter product price :");
        scanf("%d",&products[ctr].price);
        ctr++;
        printf("Want to add a new product (yes-1) :");
        scanf("%d",&i);
    }
    
    printf("\t***Your inventory***\n\n");
    printf("\tCode\tName\tPrice\n");
    for (int i = 0; i < ctr; i++)
    {
        displayProduct(&products[i]);
    }

    while (j==1)
    {
        printf("Enter product code to buy that product :");
        scanf("%d",&productsToBuy[newctr].code);
        printf("Enter the quantity :");
        scanf("%d",&productsToBuy[newctr].quantity);

        newctr++;
        printf("Want to buy another product (yes=1) :");
        scanf("%d",&j);
    }
    


    for (int j = 0; j < newctr; j++)
    {
        total_price += productsToBuy[j].price;
    }
    
    printf("\n\nYou need to pay : %d\n\n",total_price);
}