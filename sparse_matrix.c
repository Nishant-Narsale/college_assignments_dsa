#include <stdio.h>

void display(int *A, int m, int n)
{
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("\t%d", *A++);
        printf("\n");
    }
    printf("\n");
}

int T[100][3];
int T1[100][3];

void convert(int *A, int m, int n)
{
    T[0][0] = m;
    T[0][1] = n;
    int k = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (*(A) != 0)
            {
                T[k][0] = i;
                T[k][1] = j;
                T[k++][2] = *A;
            }
            *(A++);
        }
    T[0][2] = k - 1;

    display(T[0], k, 3);
}

void _convert(int *A, int m, int n)
{
    T1[0][0] = m;
    T1[0][1] = n;
    int k = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (*(A) != 0)
            {
                T1[k][0] = i;
                T1[k][1] = j;
                T1[k++][2] = *A;
            }
            *(A++);
        }
    T1[0][2] = k - 1;

    display(T1[0], k, 3);
}

void fast_transpose()
{
    int Result[100][3], total[T[0][1]], index[(T[0][1]) + 1];
    for (int i = 0; i < T[0][1]; i++)
        total[i] = 0;
    for (int i = 1; i <= T[0][2]; i++)
        total[T[i][1]]++;
    index[0] = 1;
    for (int i = 1; i <= T[0][1]; i++)
        index[i] = index[i - 1] + total[i - 1];
    Result[0][0] = T[0][1];
    Result[0][1] = T[0][0];
    Result[0][2] = T[0][2];
    for (int i = 1; i <= T[0][2]; i++)
    {
        int loc = index[T[i][1]];
        Result[loc][0] = T[i][1];
        Result[loc][1] = T[i][0];
        Result[loc][2] = T[i][2];
        index[T[i][1]]++;
    }
    for (int i = 0; i <= Result[0][2]; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\t%d", Result[i][j]);
        }
        printf("\n");
    }
}

void accept(int *A, int m, int n)
{
    printf("\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &*(A++));
        }
    printf("\n");
}

void add(int *A, int m, int n)
{
    int S1[m][n], add[100][3];
    int c1 = 1, c2 = 1, cm = 0;
    accept(S1[0], m, n);
    _convert(S1[0], m, n);
    add[0][0] = m;
    add[0][1] = n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int flag = 0;
            if (T[c1][0] == i && T[c1][1] == j)
            {
                cm++;
                add[cm][0] = i;
                add[cm][1] = j;
                add[cm][2] = T[c1][2];
                c1++;
                flag = 1;
            }
            if (T1[c2][0] == i && T1[c2][1] == j)
            {
                if (!flag)
                {
                    cm++;
                    add[cm][2] = 0;
                }
                add[cm][0] = i;
                add[cm][1] = j;
                add[cm][2] += T1[c2][2];
                c2++;
            }
        }
    }
    add[0][2] = cm;
    display(add[0], cm + 1, 3);
}

int main()
{
    int m, n;
    printf("Enter no. of rows and columns : ");
    scanf("%d%d", &m, &n);
    int S[m][n];
    while (1)
    {
        int choice = 0;
        printf("1. Accept\n2. Display\n3. Convert\n4. FAST-TRANPOSE\n5. Add\n6. Exit\n");
        printf("Input the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            accept(S[0], m, n);
            break;
        case 2:
            display(S[0], m, n);
            break;
        case 3:
            convert(S[0], m, n);
            break;
        case 4:
            fast_transpose();
            break;
        case 5:
            add(S[0], m, n);
        case 6:
            return 0;
            break;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}