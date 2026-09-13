#include "menu.h"

int main(int argc, char **argv)
{
    int error_code = 0;

    Image *image = (Image *)malloc(sizeof(Image));

    Options *options = (Options *)malloc(sizeof(Options));
    image->loaded = 0;

    if (argc == 1) // When arguments are not specified, execute menu from ImageProcessing1
    {
        menu_ImageProcessing1(image, options);
    }
    else // Executing program with arguments
    {
        error_code = process_options(argc, argv, image, options); // Process options

        if (error_code) // Incorret options
        {
            fprintf(stderr, "Error code: %d\n", error_code);
        }
        else // Execute called options
        {
            /*The image processing operations will be performed 
            based on the options set in the process_options() function*/

            if ((options->input_file) != NULL)
            {
                read_image(options->input_file, image);
            }

            if ((options->convert_to_gray) == 1)
            {
                // Threre is no need to covert images, that are already in grayscale
                if (image->image_type == 3)
                {
                    convert_to_gray(image);
                }
            }

            if ((options->negative) == 1)
            {
                negative(image, options);
            }

            if ((options->thresholding) == 1)
            {
                thresholding(image, options, options->threshold_level);
            }

            if ((options->thresholding_black) == 1)
            {
                thresholding_black(image, options, options->black);
            }

            if ((options->thresholding_white) == 1)
            {
                thresholding_white(image, options, options->white);
            }

            if ((options->gamma_correction) == 1)
            {
                gamma_correction(image, options, options->gamma_parameter);
            }

            if ((options->change_levels) == 1)
            {
                change_levels(image, options, options->white, options->black);
            }

            if ((options->contouring) == 1)
            {
                contouring(image, options);
            }

            if ((options->horizontal_blur) == 1)
            {
                horizontal_blur(image, options);
            }

            if ((options->vertical_blur) == 1)
            {
                vertical_blur(image, options);
            }

            if ((options->output_file) != NULL)
            {
                save_image(options->output_file, image);
            }

            if ((options->display) == 1)
            {
                display(options->name_to_display);
            }
        }

        // Free memory alocated for images
        free_memory(image);

        // Free memory alocated for pointers to structures
        free(image);
        free(options);
    }

    return error_code;
}