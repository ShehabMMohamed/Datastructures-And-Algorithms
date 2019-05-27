#define d 256

void KarpRabinSearch(char text[], char pattern[], int q)    // q is a prime number for hashing.
{
    int N = strlen(text), M = strlen(pattern);
    int i, j;
    int ht = 0, hp = 0, h = 1;

    for (i = 0; i < M - 1; i++)
        h = (d * h) % q;

    for (i = 0; i < M; i++) {
        hp = (d * hp + pattern[i]) % q;
        ht = (d * ht + pattern[i]) % q;
    }

    for (i = 0; i < N - M; i++) {
        if (hp == ht)    //possible match, compare char by char.
        {
            for (j = 0; j < M; j++)
                if (pattern[j] != text[i + j]) break;
            if (j == M)
                printf("Found a match at index %d", i);
        }
        ht = (d * (ht[i] - (text[i] * h)) + text[i + M]) % q;

        if (ht < 0)
            ht += q;
    }
}