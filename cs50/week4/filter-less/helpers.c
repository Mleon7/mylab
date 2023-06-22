#include "helpers.h"
#include "math.h"

// 2023-06-18：个人踩坑：length是从1开始数的，index是从0开始数的；踩坑在：for循环的条件判断，没正确处理index值和height,width的关系
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width; row++)
        {
            BYTE blue = image[column][row].rgbtBlue;
            BYTE green = image[column][row].rgbtGreen;
            BYTE red = image[column][row].rgbtRed;

            BYTE gray = round((blue + green + red) / 3.0);

            image[column][row].rgbtBlue = gray;
            image[column][row].rgbtGreen = gray;
            image[column][row].rgbtRed = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width; row++)
        {
            int originalBlue  = image[column][row].rgbtBlue;
            int originalGreen = image[column][row].rgbtGreen;
            int originalRed   = image[column][row].rgbtRed;

            int sepiaBlue  = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaRed   = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);

            image[column][row].rgbtBlue  = (sepiaBlue <= 255) ? sepiaBlue : 255;
            image[column][row].rgbtGreen = (sepiaGreen <= 255) ? sepiaGreen : 255;
            image[column][row].rgbtRed   = (sepiaRed <= 255) ? sepiaRed : 255;
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width/2; row++) // 要注意这里不能用 <= ； 比如width=4, 但index是从0开始的！（第3列的index是2！）
        {
            RGBTRIPLE temp = image[column][row];
            image[column][row] = image[column][width - (row+1)];
            image[column][width - (row+1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a temporary image to be blurred
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_blue;
            int sum_green;
            int sum_red;
            float counter;
            sum_blue = sum_green = sum_red = counter = 0; // CORNERS            //corner pixel on bottom right
            if (i >= 0 && j >= 0)
            {
                sum_red += temp[i][j].rgbtRed;
                sum_green += temp[i][j].rgbtGreen;
                sum_blue += temp[i][j].rgbtBlue;
                counter++;
            }
            // corner pixel on bottom left
            if (i >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i][j - 1].rgbtRed;
                sum_green += temp[i][j - 1].rgbtGreen;
                sum_blue += temp[i][j - 1].rgbtBlue;
                counter++;
            }
            // corner pixel on top left
            if (i - 1 >= 0 && j >= 0)
            {
                sum_red += temp[i - 1][j].rgbtRed;
                sum_green += temp[i - 1][j].rgbtGreen;
                sum_blue += temp[i - 1][j].rgbtBlue;
                counter++;
            }
            // corner pixel on top right
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i - 1][j - 1].rgbtRed;
                sum_green += temp[i - 1][j - 1].rgbtGreen;
                sum_blue += temp[i - 1][j - 1].rgbtBlue;
                counter++;
            } // FOUR EDGES            //pixels on bottom edge
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                sum_red += temp[i][j + 1].rgbtRed;
                sum_green += temp[i][j + 1].rgbtGreen;
                sum_blue += temp[i][j + 1].rgbtBlue;
                counter++;
            } // pixels on top edge
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                sum_red += temp[i - 1][j + 1].rgbtRed;
                sum_green += temp[i - 1][j + 1].rgbtGreen;
                sum_blue += temp[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            // pixels on left edge
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                sum_red += temp[i + 1][j].rgbtRed;
                sum_green += temp[i + 1][j].rgbtGreen;
                sum_blue += temp[i + 1][j].rgbtBlue;
                counter++;
            }
            // pixels on right edge
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                sum_red += temp[i + 1][j - 1].rgbtRed;
                sum_green += temp[i + 1][j - 1].rgbtGreen;
                sum_blue += temp[i + 1][j - 1].rgbtBlue;
                counter++;
            } // MIDDLE PIXELS            //middle pixels
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                sum_red += temp[i + 1][j + 1].rgbtRed;
                sum_green += temp[i + 1][j + 1].rgbtGreen;
                sum_blue += temp[i + 1][j + 1].rgbtBlue;
                counter++;
            }
            // find average colour value
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}
