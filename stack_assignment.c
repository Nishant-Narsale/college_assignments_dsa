#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char data;
    struct node *next;
} STACK;

STACK *push(STACK *top, char c)
{
    STACK *new_node = (STACK *)malloc(sizeof(STACK));
    new_node->data = c;
    new_node->next = NULL;
    if (top == NULL)
    top = new_node;
    else
    {
    new_node->next = top;
    top = new_node;
    }
    return top;
    }
    void display(STACK *top)
    {
    STACK *temp = top;
    while (temp)
    {
        printf("| %c |\n", temp->data);
        temp = temp->next;
    }
}

STACK *pop(STACK *top)
{
    STACK *temp = top;
    top = top->next;
    free(temp);
    return top;
}

int isEmpty(STACK *top)
{
    if (top == NULL)
    return 1;
    else
    return 0;
}

char readTop(STACK *top)
{
    return top->data;
}

int presedence(char token)
{
    switch (token)
    {
    case '(':
        return 0;
    case ')':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    }
    return -1;
}

int Isdigit(char token)
{
    if (token >= '0' && token <= '9')
        return 1;
    else
        return 0;
}

char *string_rev(char a[20], char rev[])
{
    int l = strlen(a);
    int j = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        rev[j] = a[i];
        j++;
    }
    rev[j] = '\0';
    return rev;
}

char *infix_to_postfix(char infix[20], char postfix[20])
{
    int i, j = 0;
    char token;
    STACK *top = NULL;
    for (i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if (token == '(')
        {
            top = push(top, token);
        }
        else if (Isdigit(token))
        {
            postfix[j] = token;
            j++;
        }
        else if (token == ')')
        {
            while (readTop(top) != '(')
            {
                char x = readTop(top);
                postfix[j] = x;
                j++;
                top = pop(top);
            }
            top = pop(top);
        }
        else
        {
            while (!isEmpty(top) && presedence(token) <= presedence(readTop(top)))
            {
                postfix[j] = readTop(top);
                j++;
                top = pop(top);
            }
            top = push(top, token);
        }
    }
    while (!isEmpty(top))
    {
        postfix[j] = readTop(top);
        j++;
        top = pop(top);
    }
    postfix[j] = '\0';
    return postfix;
}

void infix_to_prefix(char infix[], char prefix[])
{
    char rev_infix[20];
    int l = strlen(infix);
    int j = 0;
    char rev[20];
    for (int i = l - 1; i >= 0; i--)
    {
        if (infix[i] == '(')
            rev_infix[j] = ')';
        else if (infix[i] == ')')
            rev_infix[j] = '(';
        else
            rev_infix[j] = infix[i];
        j++;
    }
    rev_infix[j] = '\0';
    strcpy(prefix, infix_to_postfix(rev_infix, prefix));
    printf("%s ", string_rev(prefix, rev));
}
int eval_postfix(char postfix[20])
{
    STACK *top = NULL;
    int i = 0;
    char token, x;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        token = postfix[i];
        if (Isdigit(token))
        {
            top = push(top, token - 48);
        }
        else
        {
            int op1, op2;
            op2 = readTop(top);
            top = pop(top);
            op1 = readTop(top);
            top = pop(top);
            switch (token)
            {
                case '+':
                    x = op1 + op2;
                    break;
                case '-':
                    x = op1 - op2;
                    break;
                case '*':
                    x = op1 * op2;
                    break;
                case '/':
                    x = op1 / op2;
                    break;
            }
            top = push(top, x);
        }
    }
    x = readTop(top);
    top = pop(top);
    return x;
}

int eval_prefix(char prefix[20])
{
    char prefix_rev[20];
    strcpy(prefix_rev, string_rev(prefix, prefix_rev));
    STACK *top = NULL;
    int i = 0;
    char token, x;
    for (i = 0; prefix_rev[i] != '\0'; i++)
    {
        token = prefix_rev[i];
        if (Isdigit(token))
        {
            top = push(top, token - 48);
        }
        else
        {
            int op1, op2;
            op1 = readTop(top);
            top = pop(top);
            op2 = readTop(top);
            top = pop(top);
            switch (token)
            {
                case '+':
                    x = op1 + op2;
                    break;
                case '-':
                    x = op1 - op2;
                    break;
                case '*':
                    x = op1 * op2;
                    break;
                case '/':
                    x = op1 / op2;
                    break;
            }
            top = push(top, x);
        }
    }
    x = readTop(top);
    top = pop(top);
    return x;
}

int main()
{
    char postfix[20];
    char infix[20];
    char prefix[20];
    int choice;
    do
    {
        printf("\n\n1.infix_to_postfix\n2.infix_to_prefix\n3.postfix evaluation\n4.prefix evaluation\n0.Exit");
        printf("\nInput the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter infix expression ");
                scanf("%s", infix);
                printf("%s", infix_to_postfix(infix, postfix));
                break;
            case 2:
                printf("\nEnter infix expression ");
                scanf("%s", infix);
                infix_to_prefix(infix, prefix);
                break;
            case 3:
                printf("\nEnter postfix expression ");
                scanf("%s", postfix);
                printf("\nAns= %d ", eval_postfix(postfix));
                break;
            case 4:
                printf("\nEnter prefix expression ");
                scanf("%s", prefix);
                printf("Ans= %d ", eval_prefix(prefix));
                break;
            case 0:
                break;
        }
    } while (choice != 0);
}