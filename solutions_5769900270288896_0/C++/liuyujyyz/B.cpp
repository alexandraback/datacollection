#include <cstdio>
#include <cstdlib>

FILE * fin = fopen ("B-small-attempt0.in", "r"), * fout = fopen ("b-small.out", "w");

int P[16];
int R, C, N;

int pow (int p)
{
    int re = 1;
    for (int i = 0; i < p; i ++)
        re *= 2;
    return re;
}

int f(int q)
{
    if (q < 0 || q > R*C - 1) return 0;
    else return P[q];
}

void work (int r)
{
     fprintf (fout, "Case #%d: ", r);
     fscanf (fin, "%d%d%d", &R, &C, &N);
     int re = 4 * R * C;
     for (int i = 0; i < pow(R * C); i ++)
     {
         int tmp = i;
         int count = 0;
         for (int j = 0; j < R * C; j ++)
         {
             P[j] = tmp % 2;
             count += P[j];
             tmp = tmp / 2;
         }
         if (count == N)
         {
            int q = 0;
            for (int l = 0; l < R * C; l ++)
                q += f(l) * (f(l - R) + f(l + R) + (l % R == 0 ? 0 : f(l - 1)) + (l % R == R - 1 ? 0 : f(l + 1)));
            //if (r == 1) fprintf (fout, "q = %d,", q);
            if ((q / 2) < re)
               re = q / 2;
            //if (r == 1) fprintf (fout, "re = %d, ", re);
         }
     }
     fprintf (fout, "%d\n", re);
     return;
}

int main ()
{
    int T;
    fscanf (fin, "%d", &T);
    for (int i = 0; i < T; i ++)
    {
        work (i + 1);
    }
    return 0;
}