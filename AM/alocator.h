#ifndef ALOCATOR_H
#define ALOCATOR_H
#include <stdio.h>
#include <stdlib.h>

/**
 * Allocates memory for an array of floats.
 *
 * @param taille The size of the array to allocate.
 * @return A pointer to the allocated array.
 */
float *allocate(int taille);

/**
 * Copies the content of one float array to another.
 *
 * @param tab Pointer to the source array.
 * @param taille The size of the source array.
 * @return A pointer to a new array containing the copied values.
 */
float *copy(float *tab, int taille);

/**
 * Allows manual input of values into a float array.
 *
 * @param tab Pointer to the array to fill with manual input.
 * @param taille The size of the array.
 * @return A pointer to the filled array.
 */
float *manual(float *tab, int taille);

/**
 * Generates random float values and fills an array.
 *
 * @param tab Pointer to the array to fill with random values.
 * @param taille The size of the array.
 * @return A pointer to the filled array.
 */
float *generate(float *tab, int taille);

/**
 * Prints the contents of a float array.
 *
 * @param tab Pointer to the array to be printed.
 * @param taille The size of the array.
 */
void printTab(float *tab, int taille);

#endif // ALOCATOR_H
