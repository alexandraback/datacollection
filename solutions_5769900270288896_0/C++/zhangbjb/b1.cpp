#include<iostream>
#include<map>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stack>
#include<sstream>
#include<math.h>

using namespace std;

int main() {

    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for (int cas=1;cas<=t;cas++) {
        cout<<"Case #"<<cas<<": ";
        int r,c,n;
        cin>>r>>c>>n;
        bool graph[r+3][c+3];
        memset(graph,false,sizeof(graph));
        for (int i=1;i<=r;i++)
            for (int j=1;j<=c;j++) graph[i][j]=true;
        int ans=0;
        int total=r*c;
        while (total>n) {
                //cout<<"aaa"<<endl;
            int maxCell=0;
            int maxCelli=0;
            int maxCellj=0;
            int maxCellz=0;
            for (int i=1;i<=r;i++)
                for (int j=1;j<=c;j++)
                if (graph[i][j]) {
                    int temp=0;
                    if (graph[i-1][j]) temp++;
                    if (graph[i+1][j]) temp++;
                    if (graph[i][j-1]) temp++;
                    if (graph[i][j+1]) temp++;
                    int temp2=4-temp;
                    if (i-1<1) temp2--;
                    if (i+1>r) temp2--;
                    if (j-1<1) temp2--;
                    if (j+1>c) temp2--;
                    if (maxCell<temp) {
                        maxCell=temp;
                        maxCelli=i;
                        maxCellj=j;
                        maxCellz=temp2;
                    }
                    else if (maxCell==temp) {
                        if (temp2>maxCellz) {
                        maxCell=temp;
                        maxCelli=i;
                        maxCellj=j;
                        maxCellz=temp2;
                        }
                    }
                }
            graph[maxCelli][maxCellj]=false;
            total--;
        }

        for (int i=1;i<=r;i++)
            for (int j=1;j<=c;j++)
                if (graph[i][j]) {
                    if (graph[i-1][j]) ans++;
                    if (graph[i+1][j]) ans++;
                    if (graph[i][j-1]) ans++;
                    if (graph[i][j+1]) ans++;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}
