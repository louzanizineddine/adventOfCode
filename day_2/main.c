#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_RED_CUBES 12
#define MAX_GREEN_CUBES 13
#define MAX_BLUE_CUBES 14

bool check_game(char *buffer)
{
    int green = 0, red = 0, blue = 0;
    char *game_details = strtok(buffer, ":");
    game_details = strtok(NULL, ":");
    char *set = strtok(game_details, ";");

    while (set != NULL)
    {
        int subset_green = 0, subset_red = 0, subset_blue = 0;

        char *token = strtok(set, ",");
        while (token != NULL)
        {
            printf("token = %s | ", token);
            int count = 0;
            sscanf(token, "%d", &count);

            if (strstr(token, "green") != NULL)
            {
                subset_green += count;
            }
            else if (strstr(token, "red") != NULL)
            {
                subset_red += count;
            }
            else if (strstr(token, "blue") != NULL)
            {
                subset_blue += count;
            }
            token = strtok(NULL, ",");
        }

        green += subset_green;
        red += subset_red;
        blue += subset_blue;

        if (red > MAX_RED_CUBES || green > MAX_GREEN_CUBES || blue > MAX_BLUE_CUBES)
        {
            return false;
        }

        set = strtok(NULL, ";");
    }

    return true;
}


int main()
{

    FILE *f = fopen("test.txt", "r");

    char *buffer = NULL;
    size_t buffer_size = 0;
    size_t sum_ids = 0;
    int counter = 1;
    while (getline(&buffer, &buffer_size, f) != -1)
    {
        if (check_game(buffer))
        {
            printf("\ncounter = %d \n", counter);
            sum_ids = sum_ids + counter;
        }

        counter++;
    }


    printf("sum_ids = %ld\n", sum_ids);
}