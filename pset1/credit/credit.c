#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card_number = get_long("Card Number: ");
    long card_temp = card_number; // to store the value of the card temporarily so that the real card_number will be left untouched when needed

    int checksum = 0; // to store the actual checksum
    int checksum_temp = 0; // to split the digits of the first multiplication if it exceeds 1 digit

    bool flag = false;

    while(card_temp){
        if(flag){
        checksum_temp += 2*(card_temp%10);
        while(checksum_temp){
            checksum += checksum_temp%10;
            checksum_temp /= 10;
            }
        }
        flag = !flag;
        card_temp /= 10;
    }

    card_temp = card_number; // reassigning the card number because the previous assignment has now been cleared
    flag = true; // assigning true
    while(card_temp){
        if(flag){
            checksum += card_temp%10;
        }
        flag = !flag;
        card_temp /= 10;
    }

    if(checksum%10 == 0){
        flag = true;
    } else {
        flag = false;
    }

    int count = 0; // to count the number of digits present in the card number
    int two_digits = 0;
    card_temp = card_number;

    do {
        count++;
        card_temp /= 10;
    } while(card_temp != 0);

    card_temp = card_number;
    while(card_temp >= 100){
        card_temp /= 10;
    }

    if(flag){
        if(card_temp == 34 || card_temp == 37){
            if(count==15){
                printf("AMEX\n");
            }
        } else if (card_temp >= 51 && card_temp <=55) {
            if(count == 16){
                printf("MASTERCARD\n");
            }
        } else if ((card_number > 4000000000000 && card_number < 5000000000000) || (card_number > 4000000000000000 && card_number < 5000000000000000)){
            if(count == 13 || count == 16){
                printf("VISA\n");
            }
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
}