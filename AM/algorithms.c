#include "algorithms.h"
#include "menu.h"
#include <stdio.h>
#include <time.h>

void swap(float *x, float *y) {
  float temp = *x;
  *x = *y;
  *y = temp;
}

float *insertion(float *tab, int taille) {
  for (int i = 1; i < taille; i++) {
    float key = tab[i];
    int j = i - 1;

    while (j >= 0 && tab[j] > key) {
      swap(&tab[j], &tab[j + 1]);
      j--;
    }

    tab[j + 1] = key;
  }
  return tab;
}

void bubbleSort(float *tab, int taille) {
  int swapped;
  for (int i = 0; i < taille - 1; i++) {
    swapped = 0;
    for (int j = 0; j < taille - i - 1; j++) {
      if (tab[j] > tab[j + 1]) {
        swap(&tab[j], &tab[j + 1]);
        swapped = 1;
      }
    }

    // If no two elements were swapped in inner loop, the array is already
    // sorted
    if (swapped == 0) {
      break;
    }
  }
}

void selectionSort(float *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      // Swap arr[i] and arr[minIndex]
      swap(&arr[i], &arr[minIndex]);
    }
  }
}

void algorithmManager(float *tab, int taille) {
  int selectedAlgorithms[3]; // Array to store the selected algorithms
  int numSelected = 0;       // Number of selected algorithms
  int choice;
  printMenu();
  while (1) {
    printf("Enter your choice (1-5): ");

    scanf("%d", &choice);
    printf("choice is : %d\n", choice);
    if (choice > 5 || choice < 0) {
      fprintf(stderr, "not cool tho we said only numbers\n");
      exit(2);
    }
    if (choice == 0) {
      printf("Exiting Algorithm Manager...\n");
      return;
    }

    if (choice == 5) {
      if (numSelected == 0) {
        printf("No algorithms selected.\n");
      } else {
        printf("Selected Algorithms: \n");
        for (int i = 0; i < numSelected; i++) {
          int algorithmChoice = selectedAlgorithms[i];
          switch (algorithmChoice) {
          case 1:
            printf("1. Insertion\n");
            break;
          case 2:
            printf("2. Bubble sort\n");
            break;
          case 3:
            printf("3. Selection Sort\n");
            break;
          }
        }
      }
    } else if (choice == 4) {
      if (numSelected == 0) {
        printf("No algorithms selected. Please select at least one "
               "algorithm.\n");
      } else {
        double executionTimes[3];
        // Run the selected algorithms here
        for (int i = 0; i < numSelected; i++) {
          int algorithmChoice = selectedAlgorithms[i];
          switch (algorithmChoice) {
          case 1:
            printf(" "); // for some reason cannot put a clock_t in the
                         // beggening of the switch case;
            float *tabCopy1 = copy(tab, taille);
            clock_t startInsert = clock();
            insertion(tabCopy1, taille); // Run insertion algorithm
            clock_t endInsert = clock();
            double insertion_time =
                (double)(endInsert - startInsert) / CLOCKS_PER_SEC;
            printf("Insertion Sort took %.6f seconds to execute.\n",
                   insertion_time);
            executionTimes[i] = insertion_time;
            break;
          case 2:
            printf("");
            float *tabCopy2 = copy(tab, taille);
            clock_t startBubble = clock();
            bubbleSort(tabCopy2, taille); // Run bubbleSort
            clock_t endBubble = clock();
            double bubble_time =
                (double)(endBubble - startBubble) / CLOCKS_PER_SEC;
            printf("Bubble Sort took %.6f seconds to execute.\n", bubble_time);
            executionTimes[i] = bubble_time;
            break;
          case 3:
            printf("");
            clock_t startAlgorithm3 = clock();
            selectionSort(tab, taille); // Run Algorithm 3
            clock_t endAlgorithm3 = clock();
            double algorithm3_time =
                (double)(endAlgorithm3 - startAlgorithm3) / CLOCKS_PER_SEC;
            printf("Algorithm 3 took %.6f seconds to execute.\n",
                   algorithm3_time);
            executionTimes[i] = algorithm3_time;
            break;
          }
        }
        printf("All selected algorithms have finished.\n");

        // Calculate the fastest algorithm
        double fastestTime = executionTimes[0];
        int fastestIndex = 0;
        for (int i = 1; i < numSelected; i++) {
          if (executionTimes[i] < fastestTime) {
            fastestTime = executionTimes[i];
            fastestIndex = i;
          }
        }

        // Print the fastest algorithm and the ranking
        printf("Fastest Algorithm: ");
        switch (selectedAlgorithms[fastestIndex]) {
        case 1:
          printf("Insertion Sort\n");
          break;
        case 2:
          printf("Bubble Sort\n");
          break;
        case 3:
          printf("Selection Sort\n");
          break;
        }
      }
      printMenu();
      numSelected = 0; // Reset the number of selected algorithms
    } else if (choice >= 1 && choice <= 3) {
      if (numSelected < 3) { // Limit the number of selections to 3
        // Check if the selected algorithm is not already in the list
        int isAlreadySelected = 0;
        for (int i = 0; i < numSelected; i++) {
          if (selectedAlgorithms[i] == choice) {
            isAlreadySelected = 1;
            printf("Algorithm is already selected.\n");
            break;
          }
        }
        if (!isAlreadySelected) {
          selectedAlgorithms[numSelected] = choice;
          numSelected++;
          printf("Algorithm %d selected.\n", choice);
        }
      } else {
        printf("You can select up to 3 algorithms at a time.\n");
      }
    } else {
      printf("Invalid choice. Please select a valid option (1-5).\n");
    }
  }
}
