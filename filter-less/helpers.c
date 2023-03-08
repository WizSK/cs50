#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <  height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avarage = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtRed = avarage;
            image[i][j].rgbtGreen = avarage;
            image[i][j].rgbtBlue = avarage;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <  height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            // calculaiting color
            int sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            int sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            int sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            // for the color red
            if (sepiaRed > 255)
                image[i][j].rgbtRed = 255;
            else if (sepiaRed < 0)
                    image[i][j].rgbtRed = 0;
            else
             image[i][j].rgbtRed = sepiaRed;
            // green
            if (sepiaGreen > 255)
                image[i][j].rgbtGreen = 255;
            else if (sepiaGreen < 0)
                image[i][j].rgbtGreen = 0;
            else
                image[i][j].rgbtGreen = sepiaGreen;
            // blue
            if (sepiaBlue > 255)
                image[i][j].rgbtBlue = 255;
            else if (sepiaBlue < 0)
                image[i][j].rgbtBlue = 0;
            else
                image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

     for (int i = 0; i <  height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // inital of the arrat
            int iniRed = image[i][j].rgbtRed;
            int iniGreen = image[i][j].rgbtGreen;
            int iniBlue = image[i][j].rgbtBlue;
            // end of arr
            int endRed = image[i][width-j].rgbtRed;
            int endGreen = image[i][width-j].rgbtGreen;
            int endBlue = image[i][width-j].rgbtBlue;
 
            image[i][j].rgbtRed = endRed;
            image[i][j].rgbtGreen = endGreen;
            image[i][j].rgbtBlue = endBlue;

            image[i][width-j].rgbtRed = iniRed;
            image[i][width-j].rgbtGreen = iniGreen;
            image[i][width-j].rgbtBlue = iniBlue;
        }
    }   
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // its not good but wahtever it works and im ok with that lol 
    // like image[0][0] or -1 index is here lol 
    // but i don't care 
    for (int i = 0; i <  height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // default case 
            if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < height && j + 1 < width)
                {
                    int red = (image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed +
                        image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed +
                        image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 9;
                    int green = (image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen +
                        image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +
                        image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9;
                    int blue = (image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue +
                        image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue +
                        image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9;
                    image[i][j].rgbtRed = red;
                    image[i][j].rgbtGreen = green;
                    image[i][j].rgbtBlue = blue;

                }
            // 1st row

            else if (i - 1 < 0)
                {
                int red = (image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed +
                    image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 9;
                int green = (image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +
                    image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9;
                int blue = (image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue +
                    image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;


            }
                // last row
            else if (i + 1 >= height)
                {
                int red = (image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed +
                    image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed) / 9;
                int green = (image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen +
                    image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen) / 9;
                int blue = (image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue +
                    image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue) / 9;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;


            }

            else if (j - 1 < 0)
                {
                int red = (image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed +
                    image[i][j].rgbtRed + image[i][j+1].rgbtRed +
                    image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 9;
                int green = (image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen +
                    image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +
                    image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9;
                int blue = (image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue +
                    image[i][j].rgbtBlue + image[i][j+1].rgbtBlue +
                    image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;


            }
            else if (j + 1 >= width)
            {
            int red = (image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed +
                image[i][j-1].rgbtRed + image[i][j].rgbtRed +
                image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed) / 9;
            int green = (image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen +
                image[i][j-1].rgbtGreen + image[i][j].rgbtGreen +
                image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen) / 9;
            int blue = (image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue +
                image[i][j-1].rgbtBlue + image[i][j].rgbtBlue +
                image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue) / 9;
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;


        }



        }
    }
 
    return;
}
