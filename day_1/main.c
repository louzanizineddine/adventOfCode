#include <stdio.h>
#include <string.h>


int get_first_last_digit(const char *buffer){

    int first = 0;
    int last = 0;

    for (int i = 0; i < len(buffer); i++)
    {
        if (isdigit(buffer[i]) && first == 0){
            first = isdigit(buffer[i]);
        }

        
    }

}

int main ()
{

    FILE *f = fopen("input.txt", "r");

    char * buffer = NULL;
    size_t buffer_size = 0;
    int counter = 1;
    while (getline(&buffer, &buffer_size, f) != -1)
    {
        printf("%s | %d \n", buffer, counter);
        counter++;
    }
    
    return 0;
}