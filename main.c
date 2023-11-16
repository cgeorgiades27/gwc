#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define IN 1
#define OUT 0

void print_result(int total)
{
    printf("\t%d", total);
}

int main(int argc, char *argv[])
{
    int c, character, word, line;
    c = character = word = line = 0;
    FILE *input_stream = stdin;

    while ((c = getopt(argc, argv, "cwlf:")) != -1)
    {
        switch (c)
        {
        case 'c':
            character = 1;
            break;
        case 'w':
            word = 1;
            break;
        case 'l':
            line = 1;
            break;
        case 'f':
            input_stream = fopen(optarg, "r");
            if (input_stream == NULL)
            {
                perror("unable to open input file");
                exit(1);
            }
            break;
        case '?':
            printf("illegal option %c\n", c);
            return 1;
        }
    }

    int nc, nw, nl, state;
    state = OUT;

    c = nc = nw = nl = 0;
    while ((c = fgetc(input_stream)) != EOF)
    {
        ++nc;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    if (input_stream != stdin)
        fclose(input_stream);

    // print results
    if (character)
        print_result(nc);

    if (word)
        print_result(nw);

    if (line)
        print_result(nl);

    if (!(character || word || line))
    {
        print_result(nc);
        print_result(nw);
        print_result(nl);
    }

    printf("\n");

    return 0;
}
