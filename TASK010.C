                      /*CLOUD STORAGE - STRING COMPRESSION*/
#include <stdio.h>
#include <string.h>

// Count how many times a character repeats
int countRepeat(char s[], int i)
{
    if (s[i] == s[i + 1])
        return 1 + countRepeat(s, i + 1);
    else
        return 1;
}

// Compress the string
void compress(char s[], int i, char out[], int j)
{
    int count;

    if (s[i] == '\0')
    {
        out[j] = '\0';
        return;
    }

    count = countRepeat(s, i);

    out[j] = s[i];
    out[j + 1] = count + '0';

    compress(s, i + count, out, j + 2);
}

// Expand the compressed string
void expand(char in[], int i, char out[], int j)
{
    int count, k;

    if (in[i] == '\0')
    {
        out[j] = '\0';
        return;
    }

    count = in[i + 1] - '0';

    for (k = 0; k < count; k++)
    {
        out[j] = in[i];
        j++;
    }

    expand(in, i + 2, out, j);
}

int main()
{
    char original[] = "AAAAAABBBCCCCD";
    char compressed[50];
    char expanded[50];

    compress(original, 0, compressed, 0);

    expand(compressed, 0, expanded, 0);

    printf("Original: %s\n", original);
    printf("Compressed: %s\n", compressed);
    printf("Expanded: %s\n", expanded);

    if (strcmp(original, expanded) == 0)
        printf("Match: Yes");
    else
        printf("Match: No");

    return 0;
}
