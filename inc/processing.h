#ifndef PROCESSING_H_
#define PROCESSING_H_

#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "defines.h"
#include "image.h"
#include "options.h"

/**
 * @brief Negative operation
 *
 * @param image pointer to structure with image information
 * @param options pointer to structure with options information
 */
void negative(Image *image, Options *options);

/**
 * @brief Thresholding operation
 *
 * @param image pointer to structure with image information
 * @param options pointer to structure with options information
 * @param threshold_level
 */
void thresholding(Image *image, Options *options, int threshold_level);

/**
 * @brief Half-thresholding operation, thresholding black colour
 *
 * @param image pointer to structure with image information
 * @param options pointer to structure with options information
 * @param threshold_level
 */
void thresholding_black(Image *image, Options *options, int threshold_level);

/**
 * @brief Half-thresholding operation, thresholding white colour
 *
 * @param image pointer to structure with image information
 * @param options pointer to structure with options information
 * @param threshold_level
 */
void thresholding_white(Image *image, Options *options, int threshold_level);

/**
 * @brief Gamma correction operation
 *
 * @param image pointer to structure with image information
 * @param options pointer to structure with options information
 * @param gamma_parameter
 */
void gamma_correction(Image *image, Options *options, float gamma_parameter);

/**
 * @brief Change levels of white and black colour
 *
 * @param image pointer to structure with image information
 * @param options pointer to structure with options information
 * @param white new white level
 * @param black new black level
 */
void change_levels(Image *image, Options *options, int white, int black);

/**
 * @brief Contouring operation
 *
 * @param image pointer to structure with image information
 * @param options pointer to structure with options information
 */
void contouring(Image *image, Options *options);

/**
 * @brief Horizontal blur operation with 2 radius.
 *
 * @param image pointer to structure with image information
 * @param options pointer to structure with options information
 */
void horizontal_blur(Image *image, Options *options);

/**
 * @brief Vertical blur operation with 2 radius.
 *
 * @param image pointer to structure with image information
 * @param options pointer to structure with options information
 */
void vertical_blur(Image *image, Options *options);

/**
 * @brief Converts PPM image to PGM image.
 *
 * @param image pointer to structure with image information
 */
void convert_to_gray(Image *image);

#endif // PROCESSING_H_