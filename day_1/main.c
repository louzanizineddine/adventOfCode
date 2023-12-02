#include <ctype.h>
#include <stdio.h>
#include <string.h>
int get_first_last_digit(const char *buffer) {

  int first = -1;
  int last = -1;

  for (int i = 0; i < strlen(buffer); i++) {
    if ((isdigit(buffer[i]) != 0) && (first == -1)) {
      first = buffer[i] - '0'; 
    }

    if (isdigit(buffer[i]) != 0 && first != -1) {
      last = buffer[i] - '0';
    }
  }
  
  printf("first dig = %d last dig = %d \n", first, last);

  // only one digit in the buffer
  if (last == -1) {
    return first * 10 + first;
  }

  return first * 10 + last;
}

int main() {

  FILE *f = fopen("input.txt", "r");

  char *buffer = NULL;
  size_t buffer_size = 0;
  int counter = 1;
  int sum = 0;
  while (getline(&buffer, &buffer_size, f) != -1) {

    counter = get_first_last_digit(buffer);
    sum += counter; 
  }
  
  printf("sum = %d\n", sum);
  return 0;
}
