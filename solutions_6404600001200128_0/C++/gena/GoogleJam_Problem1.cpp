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


int SolveLarge(int * pres2)
{
    //memset(g_hash, 0, g_hashSize);

    int res = 0;
    *pres2 = 0;
    int n = i_lx.size();

    int maxd = 0;
    // 1st
    for (int i = 1; i < n; ++i)
    {
        int d = i_lx[i] - i_lx[i-1];
        if (d < 0)
        {
            res -= d;
        }

        if (-d > maxd)
            maxd = -d;
    }

    for (int i = 1; i < n; ++i)
    {
        int d = i_lx[i] - i_lx[i - 1];
        *pres2 += min(i_lx[i-1], maxd);
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
        c++;
        i_lx = splitLongInt(l[c++]);
        //const string& line = l[c++];

        //i_l = line;

        int res2 = 0;
        int res = SolveLarge(&res2);
        //int res = SolveSmall();

        //if(((long long)i_lx[1])*i_lx[2] <= 20 && i_lx[0] <= 4)
        //{
        //    int ress = SolveSmall();
        //    if(res != ress)
        //    {
        //        printf("Error: small != large\n");
        //    }
        //}
        
        fprintf(fout, "Case #%d: %d %d\n", t, res, res2);
        //fprintf(fout, "Case #%d: %s\n", t, res ? "GABRIEL" : "RICHARD");
    }

    //fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

    return 0;
}

