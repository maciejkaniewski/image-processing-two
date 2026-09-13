#ifndef IMAGE_H_
#define IMAGE_H_

/**
 * @brief Struct to store information about an image
 *
 */
typedef struct Image
{
    int width, height, gray_scale, image_type, loaded;
    int **pgm_image;
    int **ppm_red, **ppm_green, **ppm_blue;
} Image;

#endif // IMAGE_H_