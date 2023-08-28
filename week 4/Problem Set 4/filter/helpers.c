#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            float average = (image[row][column].rgbtRed + image[row][column].rgbtBlue + image[row][column].rgbtGreen) / 3.00;
            image[row][column].rgbtRed = round(average);
            image[row][column].rgbtBlue = round(average);
            image[row][column].rgbtGreen = round(average);
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            float sepiaRed =
                .393 * image[row][column].rgbtRed + .769 * image[row][column].rgbtGreen + .189 * image[row][column].rgbtBlue;
            float sepiaGreen =
                .349 * image[row][column].rgbtRed + .686 * image[row][column].rgbtGreen + .168 * image[row][column].rgbtBlue;
            float sepiaBlue =
                .272 * image[row][column].rgbtRed + .534 * image[row][column].rgbtGreen + .131 * image[row][column].rgbtBlue;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[row][column].rgbtRed = round(sepiaRed);
            image[row][column].rgbtBlue = round(sepiaBlue);
            image[row][column].rgbtGreen = round(sepiaGreen);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        int currentWidth = width - 1;
        for (int column = 0; column < (width / 2); column++)
        {
            if (currentWidth >= (width / 2))
            {
                int redTemp = image[row][column].rgbtRed;
                int blueTemp = image[row][column].rgbtBlue;
                int greenTemp = image[row][column].rgbtGreen;

                image[row][column].rgbtRed = image[row][currentWidth].rgbtRed;
                image[row][column].rgbtBlue = image[row][currentWidth].rgbtBlue;
                image[row][column].rgbtGreen = image[row][currentWidth].rgbtGreen;

                image[row][currentWidth].rgbtRed = redTemp;
                image[row][currentWidth].rgbtBlue = blueTemp;
                image[row][currentWidth].rgbtGreen = greenTemp;
                currentWidth--;
            }
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy_img[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_img[i][j] = image[i][j];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            float blue = 0.00;
            float red = 0.00;
            float green = 0.00;
            int count = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (row + k >= 0 && row + k < height && column + l >= 0 && column + l < width)
                    {
                        blue += copy_img[row + k][column + l].rgbtBlue;
                        green += copy_img[row + k][column + l].rgbtGreen;
                        red += copy_img[row + k][column + l].rgbtRed;
                        count++;
                    }
                }
            }
            image[row][column].rgbtRed = round(red / count);
            image[row][column].rgbtBlue = round(blue / count);
            image[row][column].rgbtGreen = round(green / count);
        }
    }
}