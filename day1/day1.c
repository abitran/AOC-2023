#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../utils/utils.h"

int return_int(char *, int);

int main(int argc, char **argv) {

  FILE *fp = fopen(argv[1], "r");
  char *dest;
  int sum = 0;
  dest = fileRead(fp);
  fclose(fp);
  char *tok = strtok(dest, "\n");
  while (tok != NULL){
    size_t size = strlen(tok) + 1;
    sum += return_int(tok, size);
    tok = strtok(NULL, "\n");
  }
  printf("Part1: %d\n", sum);
}

int return_int(char *str, int size){
  
  char *temp = malloc(sizeof(size));
  char *digits = temp;

  for (; *str != '\0'; str++){
    if (isdigit(*str))
      *temp++ = *str;
  }
  
  *temp = '\0';

  char nums[3];
  if (strlen(digits) > 1){
    nums[0] = digits[0];
    nums[1] = *(digits + strlen(digits)-1);
  }
  else{
    nums[0] = digits[0];
    nums[1] = digits[0];
  }

  nums[2] = '\0';

  return atoi(nums);
}
