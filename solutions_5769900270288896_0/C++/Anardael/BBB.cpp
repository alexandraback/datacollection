#include <fstream>
#include <string>
#include<iostream>
#include <map>
using namespace std;

int a[10000][10000];
int n=0,r=0,c=0;
int ccc(int i, int j){
    int cc=0;
    if (i>0)cc+=a[i-1][j];
    if (j>0)cc+=a[i][j-1];
    if (i+1<r)cc+=a[i+1][j];
    if (j+1<c)cc+=a[i][j+1];
    return cc;
}

int optimize(){
    int result=0;
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            for (int i1=0;i1<r;i1++)
                for (int j1=0;j1<c;j1++)
                    if (a[i][j]==1&&a[i1][j1]==0){
                        int t=ccc(i,j);
                        a[i1][j1]=1;
                        a[i][j]=0;
                        if (t-ccc(i1,j1)<=0){
                            a[i1][j1]=0;
                            a[i][j]=1;
                            continue;
                        }
                        result+=t-ccc(i1,j1);

                    }

    return result;
}

int main(){
    int T;
    ifstream f("input.txt");
    ofstream w("output.txt");
    f>>T;
    for (int tests=0;tests<T;tests++)
    {

        f>>r>>c>>n;
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
                a[i][j]=0;
        int h=0;
        for (int k=0;k<=4;k++)
        {
            int i=0;int j=0;
            while (n&&(i<r||j<c)){
                if (j==c)j=0,i++;
                if (i==r) break;
                int cc=0;
                if (i>0)cc+=a[i-1][j];
                if (j>0)cc+=a[i][j-1];

                if (i+1<r)cc+=a[i+1][j];
                if (j+1<c)cc+=a[i][j+1];
                if (cc==k&&a[i][j]==0){
                    n--;
                    h+=k;
                    a[i][j]=1;
                }
                j++;
            }
        }
        while (int t=optimize()){
            h-=t;
        }
        w<<"Case #"<<(tests+1)<<": "<<h<<endl;
    }
    f.close();
    w.close();

    return 0;
}

