#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "alocator.h"
#include <stdio.h>
#include <time.h>
/**
 * Swaps the values of two float variables.
 *
 * @param x Pointer to the first float variable.
 * @param y Pointer to the second float variable.
 */
void swap(float *x, float *y);

/**
 * Sorts an array of floats using the Insertion Sort algorithm.
 *
 * @param tab Pointer to the array of floats to be sorted.
 * @param taille The size of the array.
 * @return A pointer to the sorted array.
 */
float *insertion(float *tab, int taille);

/**
 * Sorts an array of floats using the Bubble Sort algorithm.
 *
 * @param tab Pointer to the array of floats to be sorted.
 * @param taille The size of the array.
 */
void bubbleSort(float *tab, int taille);

/**
 * Sorts an array of floats using the Selection Sort algorithm.
 *
 * @param arr Pointer to the array of floats to be sorted.
 * @param size The size of the array.
 */
void selectionSort(float *arr, int size);

/**
 * Allows the user to manage and benchmark multiple sorting algorithms.
 *
 * @param tab Pointer to the array of floats to be sorted.
 * @param taille The size of the array.
 */
void algorithmManager(float *tab, int taille);

#endif // ALGORITHMS_H
