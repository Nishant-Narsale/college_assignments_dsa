#include <stdio.h>

struct Passenger
{
    char name[30];
    int PRN, age, seat;
} p, rp[30];

void read_passenger()
{
    FILE *dataread = fopen("data.txt", "r");
    int count = 0;
    char c = getc(dataread);
    while (c != EOF)
    {
        if (c == '\n')
            count++;
        c = getc(dataread);
    }
    rewind(dataread);
    int find = 0, prn;
    printf("Enter thr PRN No. : ");
    scanf("%d", &prn);
    int i = 0;
    for (; i < count; i++)
    {
        fscanf(dataread, "%s %d %d %d", rp[i].name, &rp[i].age, &rp[i].seat, &rp[i].PRN);
        if (rp[i].PRN == prn)
        {
            find = i;
            break;
        }
    }
    if (i == count)
        printf("NO PASSENGER FOUND");
    else
        printf("Name : %s\nAge : %d\nSeat No. : %d\nPRN No. : %d\n", rp[find].name, rp[find].age, rp[find].seat, rp[find].PRN);
    fclose(dataread);
}

void display_passenger()
{
    FILE *dataread = fopen("data.txt", "r");
    int count = 0;
    char c = getc(dataread);
    while (c != EOF)
    {
        if (c == '\n')
            count++;
        c = getc(dataread);
    }
    rewind(dataread);
    int temp = count;
    printf("\nSr.No.\tName\tAge\tSeat\tPRN No.\n");
    while (count--)
    {
        fscanf(dataread, "%s %d %d %d", p.name, &p.age, &p.seat, &p.PRN);
        printf("%d.\t%s\t%d\t%d\t%d\n", temp - count, p.name, p.age, p.seat, p.PRN);
    }
    fclose(dataread);
}

void delete_data()
{
    FILE *dataread = fopen("data.txt", "r");
    int count = 0;
    char c = getc(dataread);
    while (c != EOF)
    {
        if (c == '\n')
            count++;
        c = getc(dataread);
    }
    rewind(dataread);
    int prn;
    printf("Enter thr PRN No. which is to be deleted : ");
    scanf("%d", &prn);
    int i = 0;
    for (; i < count; i++)
    {
        fscanf(dataread, "%s %d %d %d", rp[i].name, &rp[i].age, &rp[i].seat, &rp[i].PRN);
    }
    FILE *del = fopen("data.txt", "w");
    for (int i = 0; i < count; i++)
    {
        if (rp[i].PRN == prn)
            continue;
        fprintf(del, "%s %d %d %d", rp[i].name, rp[i].age, rp[i].seat, rp[i].PRN);
        fputc('\n', del);
    }
    fclose(dataread);
    fclose(del);
}

void write_data()
{
    FILE *datawrite = fopen("data.txt", "a");
    printf("Enter the Passeger Name : ");
    scanf("%s", &p.name);
    printf("Enter the Passenger Age : ");
    scanf("%d", &p.age);
    printf("Enter the Passenger Seat No. : ");
    scanf("%d", &p.seat);
    printf("Enter The PRN number : ");
    scanf("%d", &p.PRN);
    fprintf(datawrite, "%s %d %d %d", p.name, p.age, p.seat, p.PRN);
    fputc('\n', datawrite);
    fclose(datawrite);
}

int main()
{
    while (1)
    {
        int choice;
        printf("\n\n\tChoose a Option : \n1. Read the Passenger Data\n2. Add a Passenger\n3. Delete a Passenger\n4. Display All Passengers\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            read_passenger();
            break;
        case 2:
            write_data();
            break;
        case 3:
            delete_data();
            break;
        case 4:
            display_passenger();
            break;
        case 5:
            return 1;
            break;
        default:
            printf("Invalid Option");
        }
    }

    return 0;
}