#include "utility.h"

void free_memory(Image *image)
{
    // Free PGM
    if (image->image_type == 2)
    {
        for (int i = 0; i < image->height; i++)
        {
            free(image->pgm_image[i]);
            image->pgm_image[i] = NULL;
        }

        free(image->pgm_image);
        image->pgm_image = NULL;
    }
    else
    {
        // Free PPM
        for (int i = 0; i < image->height; i++)
        {
            free(image->ppm_red[i]);
            image->ppm_red[i] = NULL;
        }
        free(image->ppm_red);
        image->ppm_red = NULL;

        for (int i = 0; i < image->height; i++)
        {
            free(image->ppm_green[i]);
            image->ppm_green[i] = NULL;
        }
        free(image->ppm_green);
        image->ppm_green = NULL;

        for (int i = 0; i < image->height; i++)
        {
            free(image->ppm_blue[i]);
            image->ppm_blue[i] = NULL;
        }
        free(image->ppm_blue);
        image->ppm_blue = NULL;
    }
}

int read_image(FILE *input_file, Image *image)
{
    char buffer[LINE_LENGTH]; /* auxiliary buffer for reading the header and comments */
    int hash_sign;            /* auxiliary variable for reading comments */
    int end_of_data = 0;      /* whether the end of data in the file is encountered */
    int i, j;

    /* Verifies that a valid file is provided */
    if (input_file == NULL)
    {
        fprintf(stderr, "Error: A file handle was not specified!\n");
        return 0;
    }

    /* Magic number check - should be P2 or P3*/
    if (fgets(buffer, LINE_LENGTH, input_file) == NULL) /* Reading the first line of the file into the buffer */
    {
        end_of_data = 1; /* Failed, end of data! */
    }

    if ((buffer[0] != 'P') || ((buffer[1] != '2') && (buffer[1] != '3')) || end_of_data)
    { /* Is there a magic "P2" or "P3" ? */
        fprintf(stderr, "Error: This is not a PGM or PPM file!\n");
        return 0;
    }

    // If image was loaded free memory for new one
    if (image->loaded == 1)
    {
        free_memory(image);
    }

    if (buffer[1] == '2') // Set the picture type based on the magic number
    {
        image->image_type = 2; // PGM picture
    }
    else
    {
        image->image_type = 3; // PPM picture
    }

    /* Skipping comments */
    do
    {
        if ((hash_sign = fgetc(input_file)) == '#') /* Does the line begin with '#'? */
        {
            if (fgets(buffer, LINE_LENGTH, input_file) == NULL)
            {
                end_of_data = 1;
            }
        }
        else
        {
            ungetc(hash_sign, input_file); /* If the read character is not '#' return it */
        }
    } while (hash_sign == '#' && !end_of_data); /* Repeat as long as there are comment lines and no data end_of_data occurred*/

    /* Get image dimensions and number of shades of gray */
    if (fscanf(input_file, "%d %d %d", &(image->width), &(image->height), &(image->gray_scale)) != 3)
    {
        fprintf(stderr, "Error: No image dimensions or number of grayscale!\n");
        return 0;
    }

    if (image->image_type == 2) // PGM grayscale image
    {
        // Allocate memory for PGM image
        image->pgm_image = (int **)malloc(image->height * sizeof(Image));

        for (i = 0; i < image->height; i++)
        {
            image->pgm_image[i] = (int *)malloc(image->width * sizeof(Image));
        }

        /* Image download and save to dynamic pgm_image array */
        for (i = 0; i < image->height; i++)
        {
            for (j = 0; j < image->width; j++)
            {
                if (fscanf(input_file, "%d", &(image->pgm_image[i][j])) != 1)
                {
                    fprintf(stderr, "Error: Wrong image dimensions!\n");
                    return 0;
                }
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        // Allocate memory for three colors R, G, B in PPM image
        image->ppm_red = (int **)malloc(image->height * sizeof(Image));

        for (i = 0; i < image->height; i++)
        {
            image->ppm_red[i] = (int *)malloc(image->width * sizeof(Image));
        }

        image->ppm_green = (int **)malloc(image->height * sizeof(Image));

        for (i = 0; i < image->height; i++)
        {
            image->ppm_green[i] = (int *)malloc(image->width * sizeof(Image));
        }

        image->ppm_blue = (int **)malloc(image->height * sizeof(Image));

        for (i = 0; i < image->height; i++)
        {
            image->ppm_blue[i] = (int *)malloc(image->width * sizeof(Image));
        }

        for (i = 0; i < image->height; i++)
        {
            for (j = 0; j < image->width; j++)
            {
                fscanf(input_file, "%d %d %d", &(image->ppm_red[i][j]), &(image->ppm_green[i][j]), &(image->ppm_blue[i][j]));
            }
        }
    }

    return (image->width) * (image->height); /* Successful reading */
} /* Return the number of loaded pixels */

int save_image(FILE *output_file, Image *image)
{
    int line_breaker = 0;
    int i, j;

    /* Verifies that a valid file is provided */
    if (output_file == NULL)
    {
        fprintf(stderr, "Error: A file handle was not specified!\n");
        return 0;
    }

    if (image->image_type == 2) // PGM grayscale image
    {

        /*Print magic number and image parameters */
        fprintf(output_file, "P2\n");
        fprintf(output_file, "%d %d\n%d\n", image->width, image->height, image->gray_scale);

        for (i = 0; i < image->height; i++)
        {
            for (j = 0; j < image->width; j++)
            {
                fprintf(output_file, "%d ", (image->pgm_image[i][j]));
                line_breaker++;
                /*Go to new line after PGM_LINE characters*/
                if (line_breaker % PGM_LINIE == 0)
                {
                    fprintf(output_file, "\n");
                    line_breaker = 0;
                }
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        /*Print magic number and image parameters */
        fprintf(output_file, "P3\n");
        fprintf(output_file, "%d %d\n%d\n", image->width, image->height, image->gray_scale);

        for (i = 0; i < image->height; i++)
        {
            for (j = 0; j < image->width; j++)
            {
                fprintf(output_file, "%d %d %d ", image->ppm_red[i][j], image->ppm_green[i][j], image->ppm_blue[i][j]);
                line_breaker++;
                /*Go to new line after PGM_LINE characters*/
                if (line_breaker % PGM_LINIE == 0)
                {
                    fprintf(output_file, "\n");
                    line_breaker = 0;
                }
            }
        }
    }
    
    return (image->width) * (image->height); /* Successful saving */
} /* Return the number of saved pixels */

void display(char *file_name)
{
    char command[LINE_LENGTH]; /* auxiliary buffer */

    strcpy(command, "display "); /* command structure */
    strcat(command, file_name);  /* display "file_name" */
    strcat(command, " &");
    // printf("%s\n", command); /* command test print */
    system(command); /* execute the command */
}

void display_menu()
{
    system("clear");
    printf("\nImage processing:\n\n");
    printf(" 1. Load image\n");
    printf(" 2. Save and display image\n");
    printf(" 3. Negative\n");
    printf(" 4. Thresholding\n");
    printf(" 5. Thresholding black\n");
    printf(" 6. Thresholding white\n");
    printf(" 7. Gamma correction\n");
    printf(" 8. Change levels\n");
    printf(" 9. Contouring\n");
    printf("10. Horizontal blur\n");
    printf("11. Vertical blur\n");
    printf("12. Convert to gray\n");
    printf("13. End program\n\n");
}

void display_colour_menu()
{
    system("clear");
    printf("Colours:\n\n");
    printf("1. Red\n");
    printf("2. Green\n");
    printf("3. Blue\n");
    printf("4. All of them\n\n");

    printf("Select colour you would like to process: ");
}