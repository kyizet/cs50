#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    float letters = 0;
    float words = 1;
    float sentences = 0;


    for(int i = 0; i < strlen(text); i++){
        if(text[i] != ' ' && text[i] != '.' && text[i] != '!' && text[i] != '\'' && text[i] != ',' && text[i] != '"' && text[i] != '?'){
            letters += 1;
        }
        if((text[i] == ' ' && text[i+1] != ' ') || (text[i] == ' ' && text[i+1]==' ')){
            words += 1;
        }
        if(text[i] == '!' || text[i] == '.' || text[i] == '?'){
            sentences += 1;
        }
    }

    float L = 0;
    float S = 0;
    if(words > 100.0){
        L = letters * words/100.0;
        S = sentences * words/100.0;
    } else {
        L = letters * 100.0/words;
        S = sentences * 100.0/words;
    }


    float index = 0.0588 * L  -  0.296 * S  - 15.8;
    int grade = round(index);
    if(grade < 1){
        printf("Before Grade 1");
    } else if(grade > 16){
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }
}