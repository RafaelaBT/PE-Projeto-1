#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
int printImage(char *file)
{
  FILE *fp;
  char con[1000];
  fp = fopen(file, "r");
  if (!fp)
  {
    printf("Erro ao carregar arquivo: %s", file);
    return 1;
  }
  while (fgets(con, 1000, fp) != NULL)
    printf("%s", con);
  fclose(fp);
  return 0;
}

#endif
