#include "alocator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *allocate(int taille) {
  float *tab = malloc(sizeof(float) * taille);
  if (tab == NULL) {
    exit(2);
  }
  return tab;
}

float *copy(float *tab, int taille) {
  float *target = allocate(sizeof(float) * taille);
  for (int i = 0; i < taille; i++) {
    target[i] = tab[i];
  }
  return target;
}

float *manual(float *tab, int taille) {
  if (taille > 100) {
    printf("WARNING: Do you really want to fill up all those values? (y/n): ");
    char response;
    scanf(" %c", &response);

    if (response != 'y' && response != 'Y') {
      printf("filling the array automaticly.\n");
      generate(tab, taille);
      return tab;
    }
  }

  printf("Enter values:\n");
  for (int i = 0; i < taille; i++) {
    printf("tab[%d] = ", i);
    scanf("%f", &tab[i]); // Use %f to scan a float value into the array
  }
  return tab;
}

float *generate(float *tab, int taille) {
  srand(time(NULL));
  for (int i = 0; i < taille; i++) {
    tab[i] = rand() % 100;
  }
  return tab;
}

void printTab(float *tab, int taille) {
  for (int i = 0; i < taille; i++) {
    printf("tab[%d] = %f\n", i, tab[i]);
  }
}
