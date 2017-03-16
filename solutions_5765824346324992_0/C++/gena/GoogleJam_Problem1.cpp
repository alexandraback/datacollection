// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"

vector<long long> i_lx;

char * g_hash = NULL; 
size_t g_hashSize = 500 * 1024 * 1024;

std::hash_map<unsigned int, short> g_h;

class Cmp
{
public:
    bool operator()(short l, short r)
    {
        return r < l;
    }
};

// ----------
// LARGE
//

long long GetNum(long long t)
{
    long long r = 0;
    for (int i = 0; i < i_lx.size(); ++i)
    {
        long long d = t / i_lx[i];
        r += d + 1;
    }

    return r;
}

long long SolveLarge(int b, long long  n)
{
    //memset(g_hash, 0, g_hashSize);

    if (n <= b)
    {
        return n;
    }

    long long res = 0;

    long long tmin = 1;
    long long tmax = 100000000000002ll;
    long long t = 0;
    long long n1 = n - 1;
    while (tmin < tmax)
    {
        t = (tmin + tmax) / 2;
        long long nc = GetNum(t);
        if (nc < n)
        {
            tmin = t + 1;
        }
        else if (nc >= n)
        {
            tmax = t;
        }
    }

    t = tmax;
    long long nc1 = GetNum(t);
    int going = 0;
    for (int i = 0; i < b; ++i)
    {
        long long d = t%i_lx[i];
        if (d != 0)
        {
            ++going;
        }
    }

    long long nc2 = nc1 - b + going;
    for (int i = 0; i < b; ++i)
    {
        long long d = t%i_lx[i];
        if (d == 0)
        {
            ++nc2;
            if (nc2 == n)
            {
                res = i + 1;
                break;
            }
        }
    }

    if (res == 0)
    {
        printf("error\n");
    }

    return res;
}


//char g_om[20][100][20][20];
//char g_os[20][100][3];
//
//int g_numo[20] = { 0, 1, 2, 6, 100 };

/// ---------------
//  SMALL
///
int SolveSmall()
{
    //memset(g_hash, 0, g_hashSize);
    int res = 0;

    return res;
}


void Test()
{
}

void Init()
{

}

int _tmain(int argc, _TCHAR* argv[])
{
    __int64 start = GetTickCount64();

    char * outPath = "S:\\progs\\GoogleJam_Problem1\\out.txt";

    if(argc < 2)
    {
        printf("Error. Need in and out files\n");
        return -1;
    }

    if (argc >= 3)
    {
        outPath = argv[2];
    }

    FILE * fin = NULL;
    FILE * fout = NULL;

    fout = _fsopen(outPath, "w", _SH_DENYNO);
    if(fout == NULL)
    {
        printf("Can't open %s\n", outPath);
        return -1;
    }

    vector<string> l = fileToLines(argv[1]);
    int c = 0;
    if (l.size() == 0)
    {
        printf("Can't open %s\n", argv[1]);
        return -1;
    }
    int numTests = atoi(l[c++].c_str());

    g_hash = (char *)VirtualAlloc((LPVOID)NULL, g_hashSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    Init();

    Test();

    for(int t = 1; t <= numTests; ++t)
    {
        // int b =
        vector<long long> bn = splitLongInt(l[c++]);
        int b = bn[0];
        long long n = bn[1];

        i_lx = splitLongInt(l[c++]);

        //i_l = line;

        long long res = SolveLarge(b, n);
        //int res = SolveSmall();

        //if(((long long)i_lx[1])*i_lx[2] <= 20 && i_lx[0] <= 4)
        //{
        //    int ress = SolveSmall();
        //    if(res != ress)
        //    {
        //        printf("Error: small != large\n");
        //    }
        //}
        
        fprintf(fout, "Case #%d: %d\n", t, res);
        //fprintf(fout, "Case #%d: %s\n", t, res ? "GABRIEL" : "RICHARD");
    }

    //fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

    return 0;
}

