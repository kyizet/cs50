#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *input = fopen(argv[1], "r");
    FILE *img;

    if(argc != 2){
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    int buffer_size = 512;
    int count = 0;
    bool found = false;


    BYTE data[buffer_size];

    while(fread(data, buffer_size, 1, input)){
        if (data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff && (data[3] & 0xf0) == 0xe0){
            if (found)
            {
                fclose(img);
            }
            else
            {
                found = true;
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;
            if(img == NULL){
                return 1;
            }
            fwrite(data, buffer_size, 1, img);
        }
        else if (found)
        {
            fwrite(data, buffer_size, 1, img);
        }
    }
    fclose(input);
    fclose(img);
}
