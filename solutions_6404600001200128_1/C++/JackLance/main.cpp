#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <time.h>
#define MAX 100
#define test(a) cout << "TEST " << a << endl;
#define go(a,b) for(int a=0; a<b; a++)
#define case(a) fout << "Case #"<< a << ": " <<

using namespace std;
ofstream fout ("output.txt");
ifstream fin ("input.txt");

int main()
{
    int a, c, e, f, g, m;
    int x[1000];
    fin >> a;
    go(b,a){
        f=0;
        g=0;
        m=0;
        fin >> c;
        go(d,c){
            fin >> e;
            x[d]=e;
            if(d>0){
                if(x[d]<x[d-1]){
                    f+=x[d-1]-x[d];
                    if(x[d-1]-x[d]>m){
                        m=x[d-1]-x[d];
                    }
                }
            }
        }
        go(d,c){
            if(d>0){
                if(x[d-1]>m){
                    g+=m;
                }
                else{
                    g+=x[d-1];
                }
            }
        }
        case(b+1) f << " " << g << endl;


    }

}

