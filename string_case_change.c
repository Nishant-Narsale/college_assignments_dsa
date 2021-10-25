#include <stdio.h>

int main(){
    int counter = 0;
    char ch, str[1000];

    printf("Enter a string to change it's case:");
    gets(str);

    while (str[counter] != '\0') {
        ch = str[counter];
        if (ch >= 'A' && ch <= 'Z')
            str[counter] = str[counter] + 32;
        else if (ch >= 'a' && ch <= 'z')
            str[counter] = str[counter] - 32;  
        counter++;  
    }

    printf("%s\n", str);

    return 0;

}