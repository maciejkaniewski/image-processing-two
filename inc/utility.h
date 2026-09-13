#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"
#include "image.h"
#include "options.h"

/**
 * @brief Frees memory alocated for images
 *
 * @param image pointer to structure with image information
 */
void free_memory(Image *image);

/**
 * @brief Loads a PGM or PPM image from a file into a dynamic array
 *
 * @param input_file image file in PGM or PPM format
 * @param Image pointer to structure with image information
 * @return int number of loaded pixels
 */
int read_image(FILE *input_file, Image *image);

/**
 * @brief Saves a PGM image from an array into a file
 *
 * @param output_file image file in PGM or PPM format
 * @param Image pointer to structure with image information
 * @return int int number of saved pixels
 */
int save_image(FILE *output_file, Image *image);

/**
 * @brief Display image with built in application
 *
 * @param file_name name of the file we want to display
 */
void display(char *file_name);

/**
 * @brief Dispalys menu
 *
 */
void display_menu();

/**
 * @brief Dispalys menu for color selection
 *
 */
void display_colour_menu();

#endif // UTILITY_H_