text = input("Text: ");
letters = 0;
words = 1;
sentences = 0;

for i in range(0, len(text)):
    if(text[i] != ' ' and text[i] != '.' and text[i] != '!' and text[i] != '\'' and text[i] != ',' and text[i] != '"' and text[i] != '?'):
        letters += 1;
    if((text[i] == ' ' and text[i+1] != ' ') or (text[i] == ' ' and text[i+1]==' ')):
        words += 1
    if(text[i] == '!' or text[i] == '.' or text[i] == '?'):
        sentences += 1

L = 0
S = 0
if(words > 100.0):
    L = letters * words/100.0
    S = sentences * words/100.0
else:
    L = letters * 100.0/words
    S = sentences * 100.0/words

index = 0.0588 * L  -  0.296 * S  - 15.8;
grade = round(index)
if(grade < 1):
    print("Before Grade 1")
elif(grade > 16):
    print("Grade 16+")
else:
    print("Grade ", grade);