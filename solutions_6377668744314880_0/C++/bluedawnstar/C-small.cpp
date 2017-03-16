#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define IT                  iterator
#define VEC(T)              vector<T >
#define VIT(T)              vector<T >::IT

typedef long long           I64;
typedef unsigned long long  UI64;

using namespace std;

int gN;

struct Pt {
    int X;
    int Y;
} gP[3001];

int gX[3001];
int gY[3001];

int countEdge(int x, int y)
{
    int gL = 0;
    int gR = 0;
    int gT = 0;
    int gB = 0;

    gL = lower_bound(gX, gX + gN, x) - gX;
    gR = gN - (upper_bound(gX, gX + gN, x) - gX);

    gT = lower_bound(gY, gY + gN, y) - gY;
    gB = gN - (upper_bound(gY, gY + gN, y) - gY);

    return min(min(gL, gR), min(gT, gB));
}

int countCorner(int p, int mx)
{
    int res = mx;
    for (int i = 0; i < gN; i++)
    {
        if (i == p)
            continue;

        int up = 0;
        int dn = 0;

        I64 dx = gP[i].X - gP[p].X;
        I64 dy = gP[i].Y - gP[p].Y;

        if (dx == 0 || dy == 0)
            continue;

        for (int j = 0; j < gN; j++)
        {
            if (j == i || j == p)
                continue;

            I64 r1 = (gP[j].Y - gP[p].Y) * dx;
            I64 r2 = (gP[j].X - gP[p].X) * dy;

            if (r1 > r2)
                up++;
            else if (r1 < r2)
                dn++;

            if (up >= mx && dn >= mx)
                break;
        }

        res = min(res, min(up, dn));
    }
    
    return res;
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, count;

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%d", &gN);
        for (int j = 0; j < gN; j++)
        {
            fscanf(pfIn, "%d %d", &gP[j].X, &gP[j].Y);
            gX[j] = gP[j].X;
            gY[j] = gP[j].Y;
        }
        sort(gX, gX + gN);
        sort(gY, gY + gN);

        fprintf(pfOut, "Case #%d:\n", i);
        for (int j = 0; j < gN; j++)
        {
            int c = countEdge(gP[j].X, gP[j].Y);
            if (c > 0)
                c = countCorner(j, c);
            fprintf(pfOut, "%d\n", c);
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
