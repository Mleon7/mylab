#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int row = 0; row <= width - 1; row++)
    {
        for (int column = 0; column <= height - 1; column++)
        {
            if (image[column][row].rgbtBlue == 0 && image[column][row].rgbtGreen == 0 && image[column][row].rgbtRed == 0)
            {
                image[column][row].rgbtBlue = 0xff;
            }
        }
    }
}
