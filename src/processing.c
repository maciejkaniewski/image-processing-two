#include "processing.h"

void negative(Image *image, Options *options)
{
    if (image->image_type == 2) // PGM grayscale image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                image->pgm_image[i][j] = image->gray_scale - image->pgm_image[i][j];
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (options->colour_to_process == 1) // Process only red colour
                {
                    image->ppm_red[i][j] = (image->gray_scale) - (image->ppm_red[i][j]);
                }
                else if (options->colour_to_process == 2) // Process only green colour
                {
                    image->ppm_green[i][j] = (image->gray_scale) - (image->ppm_green[i][j]);
                }
                else if (options->colour_to_process == 3) // Process only blue color
                {
                    image->ppm_blue[i][j] = (image->gray_scale) - (image->ppm_blue[i][j]);
                }
                else if (options->colour_to_process == 4) // Process red, green and blue colours
                {
                    image->ppm_red[i][j] = (image->gray_scale) - (image->ppm_red[i][j]);
                    image->ppm_green[i][j] = (image->gray_scale) - (image->ppm_green[i][j]);
                    image->ppm_blue[i][j] = (image->gray_scale) - (image->ppm_blue[i][j]);
                }
            }
        }
    }
}

void thresholding(Image *image, Options *options, int threshold_level)
{
    int local_threshold_level = (threshold_level * image->gray_scale) / 100;

    if (image->image_type == 2) // PGM grayscale image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (image->pgm_image[i][j] <= local_threshold_level)
                {
                    image->pgm_image[i][j] = 0;
                }
                else
                {
                    image->pgm_image[i][j] = image->gray_scale;
                }
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (options->colour_to_process == 1) // Process only red colour
                {
                    if (image->ppm_red[i][j] <= local_threshold_level)
                    {
                        image->ppm_red[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_red[i][j] = image->gray_scale;
                    }
                }
                else if (options->colour_to_process == 2) // Process only green colour
                {
                    if (image->ppm_green[i][j] <= local_threshold_level)
                    {
                        image->ppm_green[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_green[i][j] = image->gray_scale;
                    }
                }
                else if (options->colour_to_process == 3) // Process only blue color
                {
                    if (image->ppm_blue[i][j] <= local_threshold_level)
                    {
                        image->ppm_blue[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_blue[i][j] = image->gray_scale;
                    }
                }
                else if (options->colour_to_process == 4) // Process red, green and blue colours
                {
                    if (image->ppm_red[i][j] <= local_threshold_level)
                    {
                        image->ppm_red[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_red[i][j] = image->gray_scale;
                    }

                    if (image->ppm_green[i][j] <= local_threshold_level)
                    {
                        image->ppm_green[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_green[i][j] = image->gray_scale;
                    }

                    if (image->ppm_blue[i][j] <= local_threshold_level)
                    {
                        image->ppm_blue[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_blue[i][j] = image->gray_scale;
                    }
                }
            }
        }
    }
}

void thresholding_black(Image *image, Options *options, int threshold_level)
{
    int local_threshold_level = (threshold_level * image->gray_scale) / 100;

    if (image->image_type == 2) // PGM grayscale image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (image->pgm_image[i][j] <= local_threshold_level)
                {
                    image->pgm_image[i][j] = 0;
                }
                else
                {
                    image->pgm_image[i][j] = image->pgm_image[i][j];
                }
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (options->colour_to_process == 1) // Process only red colour
                {
                    if (image->ppm_red[i][j] <= local_threshold_level)
                    {
                        image->ppm_red[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_red[i][j] = image->ppm_red[i][j];
                    }
                }
                else if (options->colour_to_process == 2) // Process only green colour
                {
                    if (image->ppm_green[i][j] <= local_threshold_level)
                    {
                        image->ppm_green[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_green[i][j] = image->ppm_green[i][j];
                    }
                }
                else if (options->colour_to_process == 3) // Process only blue color
                {
                    if (image->ppm_blue[i][j] <= local_threshold_level)
                    {
                        image->ppm_blue[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_blue[i][j] = image->ppm_blue[i][j];
                    }
                }
                else if (options->colour_to_process == 4) // Process red, green and blue colours
                {
                    if (image->ppm_red[i][j] <= local_threshold_level)
                    {
                        image->ppm_red[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_red[i][j] = image->ppm_red[i][j];
                    }

                    if (image->ppm_green[i][j] <= local_threshold_level)
                    {
                        image->ppm_green[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_green[i][j] = image->ppm_green[i][j];
                    }

                    if (image->ppm_blue[i][j] <= local_threshold_level)
                    {
                        image->ppm_blue[i][j] = 0;
                    }
                    else
                    {
                        image->ppm_blue[i][j] = image->ppm_blue[i][j];
                    }
                }
            }
        }
    }
}

void thresholding_white(Image *image, Options *options, int threshold_level)
{
    int local_threshold_level = (threshold_level * image->gray_scale) / 100;

    if (image->image_type == 2) // PGM grayscale image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (image->pgm_image[i][j] <= local_threshold_level)
                {
                    image->pgm_image[i][j] = image->pgm_image[i][j];
                }
                else
                {
                    image->pgm_image[i][j] = image->gray_scale;
                }
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (options->colour_to_process == 1) // Process only red colour
                {
                    if (image->ppm_red[i][j] <= local_threshold_level)
                    {
                        image->ppm_red[i][j] = image->ppm_red[i][j];
                    }
                    else
                    {
                        image->ppm_red[i][j] = image->gray_scale;
                    }
                }
                else if (options->colour_to_process == 2) // Process only green colour
                {
                    if (image->ppm_green[i][j] <= local_threshold_level)
                    {
                        image->ppm_green[i][j] = image->ppm_green[i][j];
                    }
                    else
                    {
                        image->ppm_green[i][j] = image->gray_scale;
                    }
                }
                else if (options->colour_to_process == 3) // Process only blue color
                {
                    if (image->ppm_blue[i][j] <= local_threshold_level)
                    {
                        image->ppm_blue[i][j] = image->ppm_blue[i][j];
                    }
                    else
                    {
                        image->ppm_blue[i][j] = image->gray_scale;
                    }
                }
                else if (options->colour_to_process == 4) // Process red, green and blue colours
                {
                    if (image->ppm_red[i][j] <= local_threshold_level)
                    {
                        image->ppm_red[i][j] = image->ppm_red[i][j];
                    }
                    else
                    {
                        image->ppm_red[i][j] = image->gray_scale;
                    }

                    if (image->ppm_green[i][j] <= local_threshold_level)
                    {
                        image->ppm_green[i][j] = image->ppm_green[i][j];
                    }
                    else
                    {
                        image->ppm_green[i][j] = image->gray_scale;
                    }

                    if (image->ppm_blue[i][j] <= local_threshold_level)
                    {
                        image->ppm_blue[i][j] = image->ppm_blue[i][j];
                    }
                    else
                    {
                        image->ppm_blue[i][j] = image->gray_scale;
                    }
                }
            }
        }
    }
}

void gamma_correction(Image *image, Options *options, float gamma_parameter)
{
    if (image->image_type == 2) // PGM grayscale image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                image->pgm_image[i][j] = (pow(image->pgm_image[i][j], (1 / (gamma_parameter)))) / (pow(image->gray_scale, (1 - gamma_parameter) / (gamma_parameter)));
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (options->colour_to_process == 1) // Process only red colour
                {
                    image->ppm_red[i][j] = (pow(image->ppm_red[i][j], (1 / (gamma_parameter)))) / (pow(image->gray_scale, (1 - gamma_parameter) / (gamma_parameter)));
                }
                else if (options->colour_to_process == 2) // Process only green colour
                {
                    image->ppm_green[i][j] = (pow(image->ppm_green[i][j], (1 / (gamma_parameter)))) / (pow(image->gray_scale, (1 - gamma_parameter) / (gamma_parameter)));
                }
                else if (options->colour_to_process == 3) // Process only blue color
                {
                    image->ppm_blue[i][j] = (pow(image->ppm_blue[i][j], (1 / (gamma_parameter)))) / (pow(image->gray_scale, (1 - gamma_parameter) / (gamma_parameter)));
                }
                else if (options->colour_to_process == 4) // Process red, green and blue colours
                {
                    image->ppm_red[i][j] = (pow(image->ppm_red[i][j], (1 / (gamma_parameter)))) / (pow(image->gray_scale, (1 - gamma_parameter) / (gamma_parameter)));
                    image->ppm_green[i][j] = (pow(image->ppm_green[i][j], (1 / (gamma_parameter)))) / (pow(image->gray_scale, (1 - gamma_parameter) / (gamma_parameter)));
                    image->ppm_blue[i][j] = (pow(image->ppm_blue[i][j], (1 / (gamma_parameter)))) / (pow(image->gray_scale, (1 - gamma_parameter) / (gamma_parameter)));
                }
            }
        }
    }
}

void change_levels(Image *image, Options *options, int white, int black)
{

    int local_white = (white * image->gray_scale) / 100;
    int local_black = (black * image->gray_scale) / 100;

    if (image->image_type == 2) // PGM grayscale image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (image->pgm_image[i][j] <= local_black)
                {
                    image->pgm_image[i][j] = 0;
                }
                else if ((local_black < image->pgm_image[i][j]) && (image->pgm_image[i][j] < local_white))
                {
                    image->pgm_image[i][j] = (image->pgm_image[i][j] - local_black) * (image->gray_scale / (local_white - local_black));
                }
                else
                {
                    image->pgm_image[i][j] = image->gray_scale;
                }
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        for (int i = 0; i < image->height; i++)
        {
            for (int j = 0; j < image->width; j++)
            {
                if (options->colour_to_process == 1) // Process only red colour
                {
                    if (image->ppm_red[i][j] <= local_black)
                    {
                        image->ppm_red[i][j] = 0;
                    }
                    else if ((local_black < image->ppm_red[i][j]) && (image->ppm_red[i][j] < local_white))
                    {
                        image->ppm_red[i][j] = (image->ppm_red[i][j] - local_black) * (image->gray_scale / (local_white - local_black));
                    }
                    else
                    {
                        image->ppm_red[i][j] = image->gray_scale;
                    }
                }
                else if (options->colour_to_process == 2) // Process only green colour
                {
                    if (image->ppm_green[i][j] <= local_black)
                    {
                        image->ppm_green[i][j] = 0;
                    }
                    else if ((local_black < image->ppm_green[i][j]) && (image->ppm_green[i][j] < local_white))
                    {
                        image->ppm_green[i][j] = (image->ppm_green[i][j] - local_black) * (image->gray_scale / (local_white - local_black));
                    }
                    else
                    {
                        image->ppm_green[i][j] = image->gray_scale;
                    }
                }
                else if (options->colour_to_process == 3) // Process only blue color
                {
                    if (image->ppm_blue[i][j] <= local_black)
                    {
                        image->ppm_blue[i][j] = 0;
                    }
                    else if ((local_black < image->ppm_blue[i][j]) && (image->ppm_blue[i][j] < local_white))
                    {
                        image->ppm_blue[i][j] = (image->ppm_blue[i][j] - local_black) * (image->gray_scale / (local_white - local_black));
                    }
                    else
                    {
                        image->ppm_blue[i][j] = image->gray_scale;
                    }
                }
                else if (options->colour_to_process == 4) // Process red, green and blue colours
                {
                    if (image->ppm_red[i][j] <= local_black)
                    {
                        image->ppm_red[i][j] = 0;
                    }
                    else if ((local_black < image->ppm_red[i][j]) && (image->ppm_red[i][j] < local_white))
                    {
                        image->ppm_red[i][j] = (image->ppm_red[i][j] - local_black) * (image->gray_scale / (local_white - local_black));
                    }
                    else
                    {
                        image->ppm_red[i][j] = image->gray_scale;
                    }

                    if (image->ppm_green[i][j] <= local_black)
                    {
                        image->ppm_green[i][j] = 0;
                    }
                    else if ((local_black < image->ppm_green[i][j]) && (image->ppm_green[i][j] < local_white))
                    {
                        image->ppm_green[i][j] = (image->ppm_green[i][j] - local_black) * (image->gray_scale / (local_white - local_black));
                    }
                    else
                    {
                        image->ppm_green[i][j] = image->gray_scale;
                    }

                    if (image->ppm_blue[i][j] <= local_black)
                    {
                        image->ppm_blue[i][j] = 0;
                    }
                    else if ((local_black < image->ppm_blue[i][j]) && (image->ppm_blue[i][j] < local_white))
                    {
                        image->ppm_blue[i][j] = (image->ppm_blue[i][j] - local_black) * (image->gray_scale / (local_white - local_black));
                    }
                    else
                    {
                        image->ppm_blue[i][j] = image->gray_scale;
                    }
                }
            }
        }
    }
}

void contouring(Image *image, Options *options)
{
    if (image->image_type == 2) // PGM grayscale image
    {
        for (int i = 0; i < image->height - 1; i++)
        {
            for (int j = 0; j < image->width - 1; j++)
            {
                image->pgm_image[i][j] = abs(image->pgm_image[i + 1][j] - image->pgm_image[i][j]) + abs(image->pgm_image[i][j + 1] - image->pgm_image[i][j]);
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        for (int i = 0; i < image->height - 1; i++)
        {
            for (int j = 0; j < image->width - 1; j++)
            {
                if (options->colour_to_process == 1) // Process only red colour
                {
                    image->ppm_red[i][j] = abs(image->ppm_red[i + 1][j] - image->ppm_red[i][j]) + abs(image->ppm_red[i][j + 1] - image->ppm_red[i][j]);
                }
                else if (options->colour_to_process == 2) // Process only green colour
                {
                    image->ppm_green[i][j] = abs(image->ppm_green[i + 1][j] - image->ppm_green[i][j]) + abs(image->ppm_green[i][j + 1] - image->ppm_green[i][j]);
                }
                else if (options->colour_to_process == 3) // Process only blue color
                {
                    image->ppm_blue[i][j] = abs(image->ppm_blue[i + 1][j] - image->ppm_blue[i][j]) + abs(image->ppm_blue[i][j + 1] - image->ppm_blue[i][j]);
                }
                else if (options->colour_to_process == 4) // Process red, green and blue colours
                {
                    image->ppm_red[i][j] = abs(image->ppm_red[i + 1][j] - image->ppm_red[i][j]) + abs(image->ppm_red[i][j + 1] - image->ppm_red[i][j]);
                    image->ppm_green[i][j] = abs(image->ppm_green[i + 1][j] - image->ppm_green[i][j]) + abs(image->ppm_green[i][j + 1] - image->ppm_green[i][j]);
                    image->ppm_blue[i][j] = abs(image->ppm_blue[i + 1][j] - image->ppm_blue[i][j]) + abs(image->ppm_blue[i][j + 1] - image->ppm_blue[i][j]);
                }
            }
        }
    }
}

void horizontal_blur(Image *image, Options *options)
{
    if (image->image_type == 2) // PGM grayscale image
    {
        for (int i = 2; i < image->height - 2; i++)
        {
            for (int j = 2; j < image->width; j++)
            {
                image->pgm_image[i][j] = ((image->pgm_image[i - 2][j] + image->pgm_image[i - 1][j] + image->pgm_image[i][j] + image->pgm_image[i + 1][j] + image->pgm_image[i + 2][j])) / 5;
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        for (int i = 2; i < image->height - 2; i++)
        {
            for (int j = 2; j < image->width; j++)
            {
                if (options->colour_to_process == 1) // Process only red colour
                {
                    image->ppm_red[i][j] = ((image->ppm_red[i - 2][j] + image->ppm_red[i - 1][j] + image->ppm_red[i][j] + image->ppm_red[i + 1][j] + image->ppm_red[i + 2][j])) / 5;
                }
                else if (options->colour_to_process == 2) // Process only green colour
                {
                    image->ppm_green[i][j] = ((image->ppm_green[i - 2][j] + image->ppm_green[i - 1][j] + image->ppm_green[i][j] + image->ppm_green[i + 1][j] + image->ppm_green[i + 2][j])) / 5;
                }
                else if (options->colour_to_process == 3) // Process only blue color
                {
                    image->ppm_blue[i][j] = ((image->ppm_blue[i - 2][j] + image->ppm_blue[i - 1][j] + image->ppm_blue[i][j] + image->ppm_blue[i + 1][j] + image->ppm_blue[i + 2][j])) / 5;
                }
                else if (options->colour_to_process == 4) // Process red, green and blue colours
                {
                    image->ppm_red[i][j] = ((image->ppm_red[i - 2][j] + image->ppm_red[i - 1][j] + image->ppm_red[i][j] + image->ppm_red[i + 1][j] + image->ppm_red[i + 2][j])) / 5;
                    image->ppm_green[i][j] = ((image->ppm_green[i - 2][j] + image->ppm_green[i - 1][j] + image->ppm_green[i][j] + image->ppm_green[i + 1][j] + image->ppm_green[i + 2][j])) / 5;
                    image->ppm_blue[i][j] = ((image->ppm_blue[i - 2][j] + image->ppm_blue[i - 1][j] + image->ppm_blue[i][j] + image->ppm_blue[i + 1][j] + image->ppm_blue[i + 2][j])) / 5;
                }
            }
        }
    }
}

void vertical_blur(Image *image, Options *options)
{
    if (image->image_type == 2) // PGM grayscale image
    {
        for (int i = 2; i < image->height; i++)
        {
            for (int j = 2; j < image->width - 2; j++)
            {
                image->pgm_image[i][j] = ((image->pgm_image[i][j - 2] + image->pgm_image[i][j - 1] + image->pgm_image[i][j] + image->pgm_image[i][j + 1] + image->pgm_image[i][j + 2])) / 5;
            }
        }
    }
    else if (image->image_type == 3) // PPM colourful image
    {
        for (int i = 2; i < image->height; i++)
        {
            for (int j = 2; j < image->width - 2; j++)
            {
                if (options->colour_to_process == 1) // Process only red colour
                {
                    image->ppm_red[i][j] = ((image->ppm_red[i][j - 2] + image->ppm_red[i][j - 1] + image->ppm_red[i][j] + image->ppm_red[i][j + 1] + image->ppm_red[i][j + 2])) / 5;
                }
                else if (options->colour_to_process == 2) // Process only green colour
                {
                    image->ppm_green[i][j] = ((image->ppm_green[i][j - 2] + image->ppm_green[i][j - 1] + image->ppm_green[i][j] + image->ppm_green[i][j + 1] + image->ppm_green[i][j + 2])) / 5;
                }
                else if (options->colour_to_process == 3) // Process only blue color
                {
                    image->ppm_blue[i][j] = ((image->ppm_blue[i][j - 2] + image->ppm_blue[i][j - 1] + image->ppm_blue[i][j] + image->ppm_blue[i][j + 1] + image->ppm_blue[i][j + 2])) / 5;
                }
                else if (options->colour_to_process == 4) // Process red, green and blue colours
                {
                    image->ppm_red[i][j] = ((image->ppm_red[i][j - 2] + image->ppm_red[i][j - 1] + image->ppm_red[i][j] + image->ppm_red[i][j + 1] + image->ppm_red[i][j + 2])) / 5;
                    image->ppm_green[i][j] = ((image->ppm_green[i][j - 2] + image->ppm_green[i][j - 1] + image->ppm_green[i][j] + image->ppm_green[i][j + 1] + image->ppm_green[i][j + 2])) / 5;
                    image->ppm_blue[i][j] = ((image->ppm_blue[i][j - 2] + image->ppm_blue[i][j - 1] + image->ppm_blue[i][j] + image->ppm_blue[i][j + 1] + image->ppm_blue[i][j + 2])) / 5;
                }
            }
        }
    }
}

void convert_to_gray(Image *image)
{
    // Allocate memory for new grayscale PGM image
    image->pgm_image = (int **)malloc(image->height * sizeof(Image));

    for (int i = 0; i < image->height; i++)
    {
        image->pgm_image[i] = (int *)malloc(image->width * sizeof(Image));
    }

    // Converting to grey is about to get avareage value from three colours
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            image->pgm_image[i][j] = ((image->ppm_red[i][j]) + (image->ppm_green[i][j]) + (image->ppm_blue[i][j])) / 3;
            image->image_type = 2;
        }
    }

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