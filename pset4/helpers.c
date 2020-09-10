#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float averageRGB; // to make sure the red, ggreen, blue values are all the sam evalue
    for(int i = 0; i < height; i++){ // iterating the height
        for(int j = 0; j < width; j++){ // iterating the width
            averageRGB = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtRed = averageRGB;
            image[i][j].rgbtGreen = averageRGB;
            image[i][j].rgbtBlue = averageRGB;
        }
    }
}

int limit(int color)
{
    if (color > 255)
    {
        color = 255;
    }
    return color;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    int colors[3];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            colors[0] = limit(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue));
            colors[1] = limit(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue));
            colors[2] = limit(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue));

            image[j][i].rgbtRed = colors[0];
            image[j][i].rgbtGreen = colors[1];
            image[j][i].rgbtBlue = colors[2];
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3]; // an array of temp to atteempt swap
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width / 2; j++){
            temp[0] = image[i][j].rgbtRed;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;


            image[i][width-j-1].rgbtRed = temp[0];
            image[i][width-j-1].rgbtGreen = temp[1];
            image[i][width-j-1].rgbtBlue = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sum[3];
    float count;
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sum[0] = 0;
            sum[1] = 0;
            sum[2] = 0;
            count = 0.00;

            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sum[0] += image[j + k][i + h].rgbtRed;
                    sum[1] += image[j + k][i + h].rgbtGreen;
                    sum[2] += image[j + k][i + h].rgbtBlue;
                    count++;
                }
            }

            temp[j][i].rgbtRed = round(sum[0] / count);
            temp[j][i].rgbtGreen = round(sum[1] / count);
            temp[j][i].rgbtBlue = round(sum[2] / count);
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
        }
    }
}
