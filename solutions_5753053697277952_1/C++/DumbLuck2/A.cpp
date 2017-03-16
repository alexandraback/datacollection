#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

#define PRINT(var) cout << #var << " = " << var << " _________ line no : " << __LINE__ << "__________ TC : " << TC << endl;
#define PRINTin(a, in) cout << #a << "[" << in << "]" <<  " = " << a[in] << " _________ line no : " << __LINE__ << "__________ TC : " << TC << endl;

#define ForIt(i, a, b) for(i = (int)(a); i <= (int)(b); ++i)
#define ForItInt(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
int TC;
//#define SMALL 1
//#define DEBUG 1


template <class X> void printArray(X a[], int len);

struct pa
{
    int index, val;
};

int p[26];
void solve(fstream& fin , fstream& fout)
{
    int i, j, k;
    int N;
    fin >> N;
    int num = 0;
    ForIt(i, 0, N-1){
        fin >> p[i];
        num += p[i];
    }

    if(num < 0)
        cout << "Error\n";

    while(num > 0)
    {
        pa one,two, three;

        one.val = two.val = three.val = -1;

        ForIt(i, 0, N-1)
        {
            if(p[i] > one.val)
            {
                one.val = p[i];
                one.index = i;
            }
        }
        ForIt(i, 0, N-1)
        {
            if(p[i] == one.val && i != one.index)
            {
                two.val = p[i];
                two.index = i;
            }
        }
        ForIt(i, 0, N-1)
        {
            if(p[i] == one.val && i != one.index && i != two.index)
            {
                three.val = p[i];
                three.index = i;
            }
        }

        if(three.val != -1)
        {
            fout << (char)(three.index + 'A') << " ";
            num--;
            p[three.index]--;
        }
        else if(two.val != -1)
        {
            fout << (char)(one.index + 'A') << (char)(two.index + 'A') << " " ;
            num -= 2;
            p[one.index]--;
            p[two.index]--;
        }
        else
        {
            fout << (char)(one.index + 'A') << " ";
            num--;
            p[one.index]--;
        }
    }
    fout << endl;

}


int main()
{
#ifdef DEBUG
    fstream fin("Ztest.in", ios::in);
#endif

#ifndef DEBUG
    #ifdef SMALL
        fstream fin("A-small-attempt0.in", ios::in);
    #endif
    #ifndef SMALL
        fstream fin("A-large.in", ios::in);
    #endif
#endif

    fstream fout("Output.out", ios:: out);

    int T;
    fin >> T;

    ForIt( TC, 1, T )
    {
        fout << "Case #" << TC << ": ";
        solve(fin, fout);
    }

    fout.close();
    fin.close();

    return 0;
}


template <class X>
void printArray(X a[], int len)
{
    for(int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout <<  endl;
}
