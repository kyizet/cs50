#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2 || !argv[1]){
        printf("Usage: ./substitution key.\n");
        return 1;
    }

    if(strlen(argv[1]) != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for(int i = 0; i < strlen(argv[1]); i++){
        if(!isalpha(argv[1][i])){
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    int count = strlen(argv[1]) - 1;
    for(int i = 0; i < strlen(argv[1]); i++){
        int k = i;
        for(int j = 0; j < count; j++){
            k++;
            if(argv[1][i] == argv[1][k]){
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
        count -= 1;
    }

    string text = get_string("plaintext: ");
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string cipher = text;

    for(int i = 0; i < strlen(text); i++){
        if(text[i] >= 'A' && text[i] <= 'Z'){
            for(int j = 0; j < strlen(alpha); j++){
                if(text[i] == toupper(alpha[j])){
                    cipher[i] = toupper(argv[1][j]);
                    break;
                }
            }
        } else if (text[i] >= 'a' && text[i] <= 'z'){
            for(int j = 0; j < strlen(alpha); j++){
                if(text[i] == tolower(alpha[j])){
                    cipher[i] = tolower(argv[1][j]);
                    break;
                }
            }
        } else {
            cipher[0] = text[0];
        }
    }

    printf("ciphertext: %s\n", cipher);
    return 0;
}