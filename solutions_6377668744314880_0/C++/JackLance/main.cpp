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

    int a, c, e, f, g, h, n, p, q;
    double z;
    long long x[15], y[15], m[15];

    vector <int> v;
    fin >> a;
    go(b,a){
        cout << "ON CASE: " << b+1 << endl;
        fin >> c;
        go(d,c){

            fin >> x[d] >> y[d];

            m[d]=15;
        }

        go(d,c){
        go(e,c){


            n=0;
            q=0;
            if(d!=e){
                go(f,c){
                    if(d!=f&&e!=f){
                        if((x[e]-x[d])*(y[f]-y[d])>(y[e]-y[d])*(x[f]-x[d])){
                            n++;
                        }
                        if((x[e]-x[d])*(y[f]-y[d])<(y[e]-y[d])*(x[f]-x[d])){
                            q++;
                        }
                    }
                }
                if(n<m[d]){
                m[d]=n;
            }
            if(n<m[e]){
                m[e]=n;
            }
            if(q<m[d]){
                m[d]=q;
            }
            if(q<m[e]){
                m[e]=q;
            }
            }


        }
    }

    case(b+1) endl;
    go(d,c){
        fout << m[d] << endl;
    }
    }


}



