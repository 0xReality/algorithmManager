#include "algorithms.h"
#include "alocator.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("usage error\n");
    perror(" usage: ./algorithmsManager (1 or 2 for input method 1 => "
           "automatic, 2 => "
           "manual), (size of array min 2), (1 or 2 for printing values before "
           "algorithms 1 => true, 2 => false), (1 or 2 after algorithms) ");
    exit(2);
  }
  int option = strtol(argv[1], NULL, 10);
  int taille = strtol(argv[2], NULL, 10);
  int printBefore = strtol(argv[3], NULL, 10);
  int printAfter = strtol(argv[4], NULL, 10);

  if (option < 1 || taille < 2 || printBefore < 1 || printAfter < 1) {
    printf("usage error\n");
    perror(" usage: ./algorithmsManager (1 or 2 for input method 1 => "
           "automatic, 2 => "
           "manual), (size of array min 2), (1 or 2 for printing values before "
           "algorithms 1 => true, 2 => false), (1 or 2 after algorithms) ");
    exit(2);
  }
  printf("Algorithm tester => SDA\n");
  float *tab = allocate(taille);
  if (option == 1)
    generate(tab, taille);
  if (option == 2)
    manual(tab, taille);
  if (printBefore == 1)
    printTab(tab, taille);
  algorithmManager(tab, taille);
  if (printAfter == 1)
    printTab(tab, taille);
  return 0;
}
