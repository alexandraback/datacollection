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

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{

    int a, c, e, f, g, m, n, p, q,z;
    int x[10], y[10];
    bool h, i;
    vector <int> v;
    fin >> a;
    go(b,a){
        cout << "WORKING ON CASE" << b+1 << endl;
        fin >> c >> n;
        p=n;
        q=1;
        z=0;
        go(d,c){
            fin >> e;
            x[d]=e;
            y[d]=0;
            q=lcm(q,x[d]);
        }
        go(d,c){
            z+=q/x[d];
        }
        while(n>z){
            n-=z;
        }
        while(n>0){
            h=false;

            g=25;
            go(d,c){
                if(y[d]==0){
                    y[d]=x[d];
                    n--;
                    if(n==0){
                        m=d+1;
                    }
                    h=true;
                }

                if(y[d]<g){
                    g=y[d];
                }

            }
            if(!h){
                go(d,c){
                    y[d]-=g;
                }
            }

        }

        case(b+1) m << endl;



    }

}

