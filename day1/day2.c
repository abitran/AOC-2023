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
  char nums[3];

  // check if the first and last indexes are numbers.

  if (isdigit(str[0]) && isdigit(str[strlen(str)-1])){
    for (; *str != '\0'; str++){
      if (isdigit(*str))
        *temp++ = *str;
    }
    
    *temp = '\0';

    if (strlen(digits) > 1){
      nums[0] = digits[0];
      nums[1] = *(digits + strlen(digits)-1);
    }
    else{
      nums[0] = digits[0];
      nums[1] = digits[0];
    }
  }

  else if (isdigit(str[0]) && isalpha(str[strlen(str)-1])){
    nums[0] = str[0];
    
    for (int i = strlen(str)-1; i >= 0; i--){

      if (str[i] == 'e'){
        if (str[i-1] == 'n' && str[i-2] == 'o'){
          nums[1] = '1';
          break;
        }
        else if (str[i-1] == 'e' && str[i-2] == 'r' && str[i-3] == 'h' && str[i-4] == 't'){
          nums[1] = '3';
          break;
        }
        else if (str[i-1] == 'n' && str[i-2] == 'i' && str[i-3] == 'n'){
          nums[1] = '9';
          break;
        }
        else if (str[i-1] == 'v' && str[i-2] == 'i' && str[i-3] == 'f'){
          nums[1] = '5';
          break;
        }
      }

      else if (str[i] == 'r'){
        if (str[i-1] == 'u' && str[i-2] == 'o' && str[i-3] == 'f'){
          nums[1] = '4';
          break;
        }
      }

      else if (str[i] == 'x'){
        if (str[i-1] == 'i' && str[i-2] == 's'){
          nums[1] = '6';
          break;
        }
      }

      else if (str[i] == 'n'){
        if (str[i-1] == 'e' && str[i-2] == 'v' && str[i-3] == 'e' && str[i-4] == 's'){
          nums[1] = '7';
          break;
        }
      }

      else if (str[i] == 'o'){
        if (str[i-1] == 'w' && str[i-2] == 't'){
          nums[1] = '2';
          break;
        }
      }

      else if (str[i] == 't'){
        if (str[i-1] == 'h' && str[i-2] == 'g' && str[i-3] == 'i' && str[i-4] == 'e'){
          nums[1] = '8';
          break;
        }
      }
      
      else if (isdigit(str[i])){ 
        nums[1] = str[i];
        break;
      }
    }
  }
  
  else if (isalpha(str[0]) && isdigit(str[strlen(str)-1])){
    nums[1] = str[strlen(str)-1];
    
    int pos;
    int index = strlen(str) - 1;
    char *found = NULL;
      
    if ((found = strstr(str, "one")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '1';
        index = pos;
      }
    }

    if ((found = strstr(str, "two")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '2';
        index = pos;
      }
     }
      
    if ((found = strstr(str, "three")) != NULL){
      pos = found - str; 
      if (pos < index){
        nums[0] = '3';
        index = pos;
      }
     }

    if ((found = strstr(str, "four")) != NULL){
      pos = found - str; 
      if (pos < index){
        nums[0] = '4';
        index = pos;
      }
     }
    
    if ((found = strstr(str, "five")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '5';
        index = pos;
      }
     }
    
    if ((found = strstr(str, "six")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '6';
        index = pos;
      }
    }

    if ((found = strstr(str, "seven")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '7';
        index = pos;
      }
    }
    
    if ((found = strstr(str, "eight")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '8';
        index = pos;
      }
    }

    if ((found = strstr(str, "nine")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '9';
        index = pos;
      }
    }

    for (int i = 0; i < strlen(str); i++)
      if (isdigit(str[i]) && i <= index){
        nums[0] = str[i];
        break;
      }
  }

  else if (isalpha(str[0]) && isalpha(str[strlen(str)-1])){

    int pos;
    int index = strlen(str) - 1;
    char *found = NULL;
      
    if ((found = strstr(str, "one")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '1';
        index = pos;
      }
    }

    if ((found = strstr(str, "two")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '2';
        index = pos;
      }
     }
      
    if ((found = strstr(str, "three")) != NULL){
      pos = found - str; 
      if (pos < index){
        nums[0] = '3';
        index = pos;
      }
     }

    if ((found = strstr(str, "four")) != NULL){
      pos = found - str; 
      if (pos < index){
        nums[0] = '4';
        index = pos;
      }
     }
    
    if ((found = strstr(str, "five")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '5';
        index = pos;
      }
     }
    
    if ((found = strstr(str, "six")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '6';
        index = pos;
      }
    }

    if ((found = strstr(str, "seven")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '7';
        index = pos;
      }
    }
    
    if ((found = strstr(str, "eight")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '8';
        index = pos;
      }
    }

    if ((found = strstr(str, "nine")) != NULL){
      pos = found - str;
      if (pos < index){
        nums[0] = '9';
        index = pos;
      }
    }
    
    for (int i = 0; i < strlen(str); i++){
      if (isdigit(str[i]) && i < index){
        nums[0] = str[i];
        break;
      }
    }

    for (int i = strlen(str)-1; i >= 0; i--){
      if (str[i] == 'e'){
        if (str[i-1] == 'n' && str[i-2] == 'o'){
          nums[1] = '1';
          break;
        }
        else if (str[i-1] == 'e' && str[i-2] == 'r' && str[i-3] == 'h' && str[i-4] == 't'){
          nums[1] = '3';
          break;
        }
        else if (str[i-1] == 'n' && str[i-2] == 'i' && str[i-3] == 'n'){
          nums[1] = '9';
          break;
        }
        else if (str[i-1] == 'v' && str[i-2] == 'i' && str[i-3] == 'f'){
          nums[1] = '5';
          break;
        }
      }

      else if (str[i] == 'r'){
        if (str[i-1] == 'u' && str[i-2] == 'o' && str[i-3] == 'f'){
          nums[1] = '4';
          break;
        }
      }

      else if (str[i] == 'x'){
        if (str[i-1] == 'i' && str[i-2] == 's'){
          nums[1] = '6';
          break;
        }
      }

      else if (str[i] == 'n'){
        if (str[i-1] == 'e' && str[i-2] == 'v' && str[i-3] == 'e' && str[i-4] == 's'){
          nums[1] = '7';
          break;
        }
      }

      else if (str[i] == 'o'){
        if (str[i-1] == 'w' && str[i-2] == 't'){
          nums[1] = '2';
          break;
        }
      }

      else if (str[i] == 't'){
        if (str[i-1] == 'h' && str[i-2] == 'g' && str[i-3] == 'i' && str[i-4] == 'e'){
          nums[1] = '8';
          break;
        }
      }
      else if (isdigit(str[i])){ 
        nums[1] = str[i];
        break;
      }
    }
  }

  nums[2] = '\0';
  printf("%s\n", nums);

  return atoi(nums);

}
