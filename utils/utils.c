#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

char *fileRead(FILE *fp){
  char *source;
  char *buffer;
  if (fseek(fp, 0L, SEEK_END) == 0){
    long bufsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    source = malloc(sizeof(char) * (bufsize + 1));
    buffer = source;
    size_t newLen = fread(source, sizeof(char), bufsize, fp);
    if (ferror(fp) != 0)
      fprintf(stderr, "Error reading the file!");
    else
      source[newLen+1] = '\0';

  }

  return buffer;
}
