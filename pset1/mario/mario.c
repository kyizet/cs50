#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int userinput;
    do {
        userinput = get_int("Please input a positive integer: ");
    } while(userinput < 1);

    int space = userinput - 1;
    for(int i = 1; i <= userinput; i++){
        for(int j = 0; j < space; j++){
            printf(" ");
        }
        space--;
        for(int j = 0; j < i; j++){
            printf("#");
        }
        printf("  ");
        for(int j = 0; j < i; j++){
            printf("#");
        }
        printf("\n");
    }
}