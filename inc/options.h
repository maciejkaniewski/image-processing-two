#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <stdio.h>
#include <string.h>
#include "image.h"
#include "defines.h"

/**
 * @brief Struct to store options data
 *
 */
typedef struct Options
{
    FILE *input_file, *output_file;

    int negative,
        thresholding,
        thresholding_black,
        thresholding_white,
        gamma_correction,
        change_levels,
        contouring,
        horizontal_blur, vertical_blur,
        display,
        convert_to_gray;

    int threshold_level, white, black, colour_to_process;
    float gamma_parameter;
    char name_to_display[100];

} Options;

/**
 * @brief Resets all options to default values
 *
 * @param options pointer to structure with options information
 */
void reset_options(Options *options);

/**
 * @brief Handle calling program with arguments
 *
 */
int process_options(int argc, char **argv, Image *image, Options *options);

#endif // OPTIONS_H_