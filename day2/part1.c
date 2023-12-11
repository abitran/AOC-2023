#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "../utils/utils.h"

#define MAXLINES 10000

typedef struct set{
  int rcubes;
  int gcubes;
  int bcubes;
}set;

typedef struct game{
  int id;
  set sets[100];
  int nsets;
}game;

void process(game *, char *);

int main(int argc, char **argv){

  FILE *fp = fopen(argv[1], "r");
  
  if (fp == NULL){
    fprintf(stderr, "Unable to open file %s", argv[1]);
    return EXIT_FAILURE;
  }
  
  char *puzzle = fileRead(fp);

  int lines = 0;
  game Game[1000];

  int sumgames = 0;
  
  const int red = 12, green = 13, blue = 14;
  
  fclose(fp);
  

  char *del = strtok(puzzle, "\n");
  
  while (del != NULL){
    process(&Game[lines], del);
    del = strtok(NULL, "\n");
    lines++;
  }

  for (int i = 0; i < lines; i++){
    int wsets = 0;
    printf("structure: %d\n", Game[i].id);
    for (int j = 0; j < Game[i].nsets; j++){
      printf("[%d %d %d]\n", Game[i].sets[j].rcubes, Game[i].sets[j].gcubes, Game[i].sets[j].bcubes);
      if ((Game[i].sets[j].rcubes <= red) && (Game[i].sets[j].gcubes <= green) && (Game[i].sets[j].bcubes <= blue)){
        wsets++;
      }
    }
    if (wsets == Game[i].nsets){
      sumgames += Game[i].id;
    }
  }
  
  printf("Total: %d\n", sumgames);

  return EXIT_SUCCESS;
}


void process(game *G, char *str){
  char data[256];

  sscanf(str, "Game %d:", &G->id);
  sscanf(str, "%*[^:]: %[^\n]", data);

  int numsets = 0;
  char *pointer;
  
  char *psets = strtok_r(data, ";", &pointer);

  while (psets != NULL){
    char *p = psets;
    while (*p != '\0'){
      if (isdigit(*p)){
        int num = *p - '0';
        if (isdigit(*(p+1))){
          char digit[3];
          digit[0] = *p;
          digit[1] = *(p+1);
          digit[2] = '\0';
          num = atoi(digit);
          p++;
        }
        p += 2;
        switch(*p){
          case 'r':
            G->sets[numsets].rcubes = num;
            break;

          case 'g':
            G->sets[numsets].gcubes = num;
            break;

          case 'b':
            G->sets[numsets].bcubes = num;
            break;

          default:
            break;
        }
      }
      p++;
    }
    numsets++;
    psets = strtok_r(NULL, ";", &pointer);
  }
  G->nsets = numsets;
}
