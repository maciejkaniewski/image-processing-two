#include "options.h"

void reset_options(Options *options)
{
    options->input_file = NULL;
    options->output_file = NULL;

    options->negative = 0;
    options->thresholding = 0;
    options->thresholding_black = 0;
    options->thresholding_white = 0;
    options->gamma_correction = 0;
    options->change_levels = 0;
    options->contouring = 0;
    options->horizontal_blur = 0;
    options->vertical_blur = 0; 
    options->display = 0;
    options->convert_to_gray = 0;

    options->threshold_level = 0;
    options->white = 0;
    options->black = 0;
    options->gamma_parameter = 0;
}

int process_options(int argc, char **argv, Image *image, Options *options)
{
    int i, threshold_level, black, white;
    float gamma_parameter;
    char *name_of_input_file, *name_of_output_file;
    char input_images[100] = INPUT_DIRECTORY;
    char output_images[100] = OUTPUT_DIRECTORY;

    reset_options(options);
    options->input_file = stdout; // In case the "-o" option is not given

    // Look for "s" option to save converted image in PGM fromat
    for (int j = 0; j < argc; ++j)
    {
        if (strcmp(argv[j], "s") == 0)
        {
            options->convert_to_gray = 1;
        }
    }

    for (i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-') // This is not an option - no "-" sign
        {
            return INCORRECT_OPTION;
        }

        switch (argv[i][1])
        {
        case 'i':
        {
            if (++i < argc) // Option with input file name
            {
                name_of_input_file = argv[i]; // Loading another argument as a file name

                if (strcmp(name_of_input_file, "-") == 0) // When file name is "-"
                {
                    options->input_file = stdin; // Setting the input to stdin
                }
                else
                {
                    strcat(input_images, name_of_input_file); // Append filename to path

                    int len = strlen(name_of_input_file);                 // Get length of name_of_input file
                    const char *last_four = &name_of_input_file[len - 4]; // Get last four characters it is file extension

                    // Check type of loaded image and set it in Image structure
                    if (strcmp(last_four, ".pgm") == 0)
                    {
                        image->image_type = 2; // PGM image type
                    }
                    else if (strcmp(last_four, ".ppm") == 0)
                    {
                        image->image_type = 3; // PPM image type
                    }

                    options->input_file = fopen(input_images, "r"); // Opening the indicated file
                }
            }
            else
                return NO_FILE_NAME; // No filename
            break;
        }
        case 'o':
        {
            if (++i < argc) // Option with output file name
            {
                name_of_output_file = argv[i]; // Loading another argument as a file name

                if (strcmp(name_of_output_file, "-") == 0) // When file name is "-"
                {
                    options->output_file = stdout; // Setting the output to stdout
                }
                else
                {
                    strcat(output_images, name_of_output_file); // Append filename to path

                    // Check type of loaded image and set it in Image structure
                    if (image->image_type == 2)
                    {
                        strcat(output_images, ".pgm"); // PGM image type
                    }
                    else if (image->image_type == 3 && options->convert_to_gray == 1)
                    {
                        strcat(output_images, ".pgm"); // PGM image type
                    }
                    else if (image->image_type == 3)
                    {
                        strcat(output_images, ".ppm"); // PPM image type
                    }

                    options->output_file = fopen(output_images, "w"); // Opening the indicated file
                    strcpy(options->name_to_display, output_images);  // Copy final file with its path to name_to_display
                }
            }
            else
                return NO_FILE_NAME; // No filename
            break;
        }
        case 'm': // Colour to process
        {
            if (++i < argc) // Get next argument
            {
                switch (argv[i][0])
                {
                case 'r': // Red colour processing
                {
                    options->colour_to_process = 1;
                    break;
                }
                case 'g': // Green colour processing
                {
                    options->colour_to_process = 2;
                    break;
                }
                case 'b': // Blue colour processing
                {
                    options->colour_to_process = 3;
                    break;
                }
                case 'a': // All colours processing
                {
                    options->colour_to_process = 4;
                    break;
                }
                case 's': // Convert PPM to PGM
                {
                    // Already set
                    options->convert_to_gray = 1;
                    break;
                }
                default:

                    return NO_VALUE;
                }
            }
            else
            {
                return NO_VALUE;
            }
            break;
        }
        case 'n': // Executing negative operation
        {
            options->negative = 1;
            break;
        }
        case 't': // Execute thresholding operation
        {
            if (++i < argc)
            {
                if (sscanf(argv[i], "%d", &threshold_level) == 1) // Loading another argument as threshold value
                {
                    options->thresholding = 1;
                    options->threshold_level = threshold_level;
                }
                else
                    return NO_VALUE; // Invalid threshold value
            }
            else
                return NO_VALUE; // No threshold value
            break;
        }
        case 'b': // Execute thresholding black operation
        {
            if (++i < argc)
            {
                if (sscanf(argv[i], "%d", &threshold_level) == 1) // Loading another argument as threshold value
                {
                    options->thresholding_black = 1;
                    options->black = threshold_level;
                }
                else
                    return NO_VALUE; // Invalid threshold value
            }
            else
                return NO_VALUE; // No threshold value
            break;
        }
        case 'w': // Execute thresholding white operation
        {
            if (++i < argc)
            {
                if (sscanf(argv[i], "%d", &threshold_level) == 1) // Loading another argument as threshold value
                {
                    options->thresholding_white = 1;
                    options->white = threshold_level;
                }
                else
                    return NO_VALUE; // Invalid threshold value
            }
            else
                return NO_VALUE; // No threshold value
            break;
        }
        case 'g': // Execute gamma correction operation
        {
            if (++i < argc)
            {
                if (sscanf(argv[i], "%f", &gamma_parameter) == 1) // Loading another argument as gamma parameter
                {
                    options->gamma_correction = 1;
                    options->gamma_parameter = gamma_parameter;
                }
                else
                    return NO_VALUE; // Invalid gamma parameter value
            }
            else
                return NO_VALUE; // No gamma parameter value
            break;
        }
        case 'l': // Execute changing levels operation
        {
            if (++i < argc)
            {
                if (sscanf(argv[i], "%d", &white) == 1) // Loading another argument as new white value
                {
                    options->white = white;
                }
                else
                    return NO_VALUE; // Invalid white value
            }
            else
                return NO_VALUE; // No white value

            if (++i < argc)
            {
                if (sscanf(argv[i], "%d", &black) == 1) // Loading another argument as new black value
                {
                    options->change_levels = 1;
                    options->black = black;
                }
                else
                    return NO_VALUE; // Invalid black value
            }
            else
                return NO_VALUE; // No black value
            break;
        }
        case 'c': // Executing contouring operation
        {
            options->contouring = 1;
            break;
        }
        case 'h': // Executing horizontal blur operation
        {
            options->horizontal_blur = 1;
            break;
        }
        case 'v': // Executing vertical blur operation
        {
            options->vertical_blur = 1;
            break;
        }
        case 'd': // Executing display operation
        {
            options->display = 1;
            break;
        }
        default:
            return INCORRECT_OPTION;
        }
    }

    if (options->input_file != NULL) // Input stream correctly initialized
    {
        return OK;
    }
    else
    {
        return NO_FILE; // Input file not opened
    }
}