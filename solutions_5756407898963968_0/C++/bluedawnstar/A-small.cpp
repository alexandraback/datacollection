#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int g_nRow1;
int g_aCards1[4][4];
int g_nRow2;
int g_aCards2[4][4];

int g_nCommCount;
int g_aCommCards[4];

void findCommCards(void)
{
    g_nCommCount = 0;

    int* pRow1 = g_aCards1[g_nRow1 - 1];
    int* pRow2 = g_aCards2[g_nRow2 - 1];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (pRow1[i] == pRow2[j])
            {
                g_aCommCards[g_nCommCount++] = pRow1[i];
                break;
            }
        }
    }
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, j, count;

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%d", &g_nRow1);
        for (j = 0; j < 16; j++)
            fscanf(pfIn, "%d", &g_aCards1[0][j]);
        fscanf(pfIn, "%d", &g_nRow2);
        for (j = 0; j < 16; j++)
            fscanf(pfIn, "%d", &g_aCards2[0][j]);

        findCommCards();

        fprintf(pfOut, "Case #%d: ", i);
        if (g_nCommCount <= 0)
        {
            fprintf(pfOut, "Volunteer cheated!\n");
        }
        else if (g_nCommCount == 1)
        {
            fprintf(pfOut, "%d\n", g_aCommCards[0]);
        }
        else
        {
            fprintf(pfOut, "Bad magician!\n");
        }
    }
}

//-----------------------------------------------------------------------------

void process(const char* pcszInFile, const char* pcszOutFile)
{
    FILE* pfIn = fopen(pcszInFile, "rt");
    if (pfIn == NULL)
    {
        printf("file not found! \"%s\"\n", pcszInFile);
        exit(-2);
    }

    FILE* pfOut = fopen(pcszOutFile, "wt");
    if (pfOut == NULL)
    {
        printf("can't create file! \"%s\"\n", pcszOutFile);
        exit(-3);
    }

    process(pfIn, pfOut);

    fclose(pfIn);
    fclose(pfOut);
}

void main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage : %s <input_file> <output_file>\n", argv[0]);
        exit(-1);
    }

    process(argv[1], argv[2]);
}
