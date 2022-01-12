#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct player_record
{
    char name[20], country[20], category[20];
    int age, no_0f_Odi, no_of_T20s, avg_batting_score, wickets_taken;
};

void takeInput(struct player_record player[], int no_of_player);
void print_data(struct player_record player[], int no_of_player);
void Batsman_country(struct player_record player[], int no_of_player);
void Bowler_country(struct player_record player[], int no_of_player);
void WicketKeeper_country(struct player_record player[], int no_of_player);
void Avg_batting_score(struct player_record player[], int no_of_player);
void Max_age(struct player_record player[], int no_of_player);
void Maximum_wickets(struct player_record player[], int no_of_player);

int main()
{
    struct player_record player[10];

    int no_of_players;
    printf("Input the number of players: ");
    scanf("%d", &no_of_players);

    takeInput(player, no_of_players);

    int choice;
    do
    {
        printf("\n1.Display_record\n2.No_of_Batsmen of a particular_country\n3.No_of_Bolwers of a particular_country\n4.No_of Wicket_keepers of a particular_country\n5.Sort the Batsmens as per their average batting score\n6.Batsmen with highest age\n7.The_Bolwer that has taken a max_wickets\n0.exit\n");

        printf("\nInput the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            print_data(player, no_of_players);
            break;

        case 2:
            Batsman_country(player, no_of_players);
            break;

        case 3:
            Bowler_country(player, no_of_players);
            break;

        case 4:
            WicketKeeper_country(player, no_of_players);
            break;

        case 5:
            Avg_batting_score(player, no_of_players);
            break;

        case 6:
            Max_age(player, no_of_players);
            break;

        case 7:
            Maximum_wickets(player, no_of_players);
            break;

        default:
            printf("\nThank You!\n");
            break;
        }
    } while (choice != 0);
}

void takeInput(struct player_record player[], int no_of_player)
{
    int i;

    printf("\n-- Enter the info of player --\n");

    for (i = 0; i < no_of_player; i++)
    {
        printf("\nName: ");
        scanf("%s", player[i].name);
        printf("Age: ");
        scanf("%d", &player[i].age);
        printf("Country: ");
        scanf("%s", player[i].country);
        printf("Category_(Batsmen/Bolwer/Wicket_keeper): ");
        scanf("%s", player[i].category);
        printf("No_of_Odis_played: ");
        scanf("%d", &player[i].no_0f_Odi);
        printf("No_of_T20s_played: ");
        scanf("%d", &player[i].no_of_T20s);
        printf("Average_batting score: ");
        scanf("%d", &player[i].avg_batting_score);
        printf("Wickets_taken: ");
        scanf("%d", &player[i].wickets_taken);
    }
}

void print_data(struct player_record player[], int no_of_player)
{
    printf("\n-- Record of players --\n");

    int i;
    for (i = 0; i < no_of_player; i++)
    {
        printf("\nName: %s\n", player[i].name);
        printf("Age: %d\n", player[i].age);
        printf("Country: %s\n", player[i].country);
        printf("Category: %s\n", player[i].category);
        printf("No_of_Odis_played: %d\n", player[i].no_0f_Odi);
        printf("No_of_T20s_played: %d\n", player[i].no_of_T20s);
        printf("Average Batting_score: %d\n", player[i].avg_batting_score);
        printf("Wickets_taken: %d\n", player[i].wickets_taken);
    }
}

void Batsman_country(struct player_record player[], int no_of_player)
{
    int ctr = 0, i;
    char country[20];
    printf("Enter the country to find the Batsmens of that: ");
    scanf("%s", country);

    for (i = 0; i < no_of_player; i++)
    {
        if (strcmp(country, player[i].country) == 0 && strcmp("Batsmen", player[i].category) == 0)
        {
            ctr++;
        }
    }

    printf("\nThere are %d Batsmens in %s\n", ctr, country);
}

void Bowler_country(struct player_record player[], int no_of_player)
{
    int ctr = 0, i;
    char country[20];
    printf("Enter the country to find the Bolwers of that: ");
    scanf("%s", country);

    for (i = 0; i < no_of_player; i++)
    {
        if (strcmp(country, player[i].country) == 0 && strcmp("Bolwer", player[i].category) == 0)
        {
            ctr++;
        }
    }

    printf("\nThere are %d Bolwers in %s.\n", ctr, country);
}

void WicketKeeper_country(struct player_record player[], int no_of_player)
{
    int ctr = 0, i;
    char country[20];
    printf("Enter the country to find the Wicket_keepers of that: ");
    scanf("%s", country);

    for (i = 0; i < no_of_player; i++)
    {
        if (strcmp(country, player[i].country) == 0 && strcmp("Wicket_keeper", player[i].category) == 0)
        {
            ctr++;
        }
    }

    if (ctr == 0)
    {
        printf("\nNoneone is the wicket keeper present in %s\n", country);
    }
    else
    {
        printf("\nThere are %d Wicket_keepers in %s.\n", ctr, country);
    }
}

void Avg_batting_score(struct player_record player[], int no_of_player)
{
    int ctr = player[0].avg_batting_score;
    int index = 0;
    for (int i = 0; i < no_of_player; i++)
    {
        if (strcmp("Batsmen", player[i].category) == 0)
        {
            if (player[i].avg_batting_score > ctr)
            {
                ctr = player[i].avg_batting_score;
                index = i;
            }
        }
    }

    printf("\n%s scored %d which is the highest score among others\n", player[index].name, ctr);
}

void Max_age(struct player_record player[], int no_of_player)
{
    int max_age = 0, i, index = 0;
    for (i = 0; i < no_of_player; i++)
    {
        if (player[i].age > max_age)
        {
            max_age = player[i].age;
            index = i;
        }
    }

    printf("\n%s having %d age which is the highest\n", player[index].name, max_age);
}

void Maximum_wickets(struct player_record player[], int no_of_player)
{
    int ctr = 0, i;
    int index = 0;
    for (i = 0; i < no_of_player; i++)
    {
        if (strcmp("Bolwer", player[i].category) == 0)
        {
            if (player[i].wickets_taken > ctr)
            {
                ctr = player[i].wickets_taken;
                index = i;
            }
        }
    }

    printf("\n%s has taken maximum wickets\n", player[index].name);
}