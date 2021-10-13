#include <stdio.h>
#include <string.h>

struct STORE
    {
        int code;
        char name[10];
        int price;
    }products[4];

int DisplayMenu(struct STORE * product){
    printf("\n\nPRODUCT : \n");
    printf("%d\n",product->code);
    printf("%s\n",product->name);
    printf("%d\n",product->price);
}

int main(){
    int total_price = 0;

    products[0].code = 1;
    strcpy(products[0].name,"Laptop");
    products[0].price = 40000;

    products[1].code = 2;
    strcpy(products[1].name,"Mobile");
    products[1].price = 10000;

    products[2].code = 3;
    strcpy(products[2].name,"IOT");
    products[2].price = 6000;
    
    products[3].code = 4;
    strcpy(products[3].name,"Another");
    products[3].price = 40000;

    for (int i = 0; i < 4; i++)
    {
        DisplayMenu(&products[i]);
    }
    for (int j = 0; j < 4; j++)
    {
        total_price += products[j].price;
    }
    
    printf("\n\nYou need to pay : %d\n\n",total_price);
}