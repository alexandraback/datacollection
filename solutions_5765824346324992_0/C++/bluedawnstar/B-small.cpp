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

int gB;
int gM[100001];
int gN;

I64 gcd(I64 p, I64 q)
{
    return q == 0 ? p : gcd(q, p%q);
}
 
I64 gcd2(I64 p, I64 q)
{
    if (p < q)
        swap(p, q);
    int t;
    while (q != 0)
    {
        t = q;
        q = p % q;
        p = t;
    }
    return p;
}
 
I64 lcm(I64 p, I64 q)
{
    return (p / gcd2(p, q)) * q;
}

I64 calcLcm()
{
    I64 p, q = gM[0];
    for (int i = 1; i < gB; i++) {
        p = q;
        q = lcm(p, gM[i]);
    }

    return q;
}

I64 calcPeriod()
{
    I64 res = 0;
    I64 lcm = calcLcm();

    for (int i = 0; i < gB; i++)
        res += lcm / gM[i]; // + 1;

    return res;
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, count;

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%d %d", &gB, &gN);
        for (int j = 0; j < gB; j++) {
            fscanf(pfIn, "%d", &gM[j]);
        }

        I64 p = calcPeriod();

        gN %= p;
        if (gN == 0)
            gN = (int)p;

        int n = 0, ans = 1;
        if (gN <= gB)
            ans = gN;
        else
        {
            n = gB;
            ans = 0;
            for (int j = 1; n < gN; j++) {
                for (int k = 0; k < gB; k++) {
                    if (j % gM[k] == 0)
                    {
                        if (++n >= gN)
                        {
                            ans = k + 1;
                            break;
                        }
                    }
                }
            }
        }

        fprintf(pfOut, "Case #%d: %d\n", i, ans);
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
