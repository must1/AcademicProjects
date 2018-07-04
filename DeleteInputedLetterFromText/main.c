#include <stdio.h>
#include <stdlib.h>
char *readFileContent(FILE * f)
{
    char *buffer = NULL;
    int len = 0;
    char c;

    do
    {
        c = getc(f);
        buffer = realloc(buffer, len + 1);
        buffer[len] = c;
        ++len;
    }
    while(c != EOF);

    buffer[len - 1] = 0;
    return buffer;
}

char* removeSign(FILE * f,char sign, char *line)
{
    int di = 0;
    int si = 0;

    while(line[di] = line[si++])
    {
        if(line[di] != sign)
            ++di;
    }
    return line;
}

void Save(char *argv[], char *line, char sign)
{
    FILE *file2;
    file2 = fopen(argv[2], "w");
    if (file2 == NULL)
        printf("Can't open the file!");
    else
    {
        fprintf(file2, "The text without %c:  %s \n",sign, line);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Za malo argumentow");
        return 0;
    }

    char sign;

    printf("Text in text text file:\n\n");

    FILE *file = fopen(argv[1], "r");

    char *line;

    line = readFileContent(file);

    printf("%s\n", line);

    printf("Input sign to remove:\n");

    scanf("%c", &sign);

    line = removeSign(file,sign,line);

    printf("Text without '%c':\n", sign);

    printf("%s\n", line);

    Save(argv,line,sign);

    free(line);

    fclose(file);

    return 0;
}
