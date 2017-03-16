#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
vector<string> vs;
int vi[103][103];
char vc[103][103];
int vk[103];

int n;
string st;

int clc(int x, int tar){
    int tot=0;
    for(int i=0;i<n;i++){
        tot+= abs(vi[i][x]-tar);
    }
    return tot;
}


int clc(int x){
    int mx=vi[0][x];
    int mn=vi[0][x];

    for(int i=1;i<n;i++){
        mx= max(mx,vi[i][x]);
        mn= min(mn,vi[i][x]);
    }

    int nowmn= clc(x,mn);
    for(int i=mn;i<=mx;i++){
        nowmn= min(nowmn, clc(x,i));
    }
    return nowmn;
}


int main() {
	freopen("as.in","rt",stdin);
    //freopen("out.txt","wt",stdout);
    int gt;
	cin>>gt;
    for(int run=1;run<=gt;run++)
	{
	    vs.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>st;
            vs.push_back(st);
        }

        int k;

        for(int i=0;i<n;i++){
            int j=0;
            k=0;
            char pr= vs[i][j];
            while(j<vs[i].size()){
                pr= vs[i][j];
                int ct=0;
                while(j<vs[i].size() && vs[i][j]==pr) {j++;ct++;}
                vi[i][k]=ct;
                vc[i][k++]=pr;
            }
            vk[i]=k;
        }
        bool flag=1;
        int fk=vk[0];
        for(int i=1;i<n;i++){
            if(vk[i]!=fk) flag=0;
        }
        if(flag){
            for(int i=1;i<n;i++){
                for(int j=0;j<fk;j++) if(vc[i][j]!=vc[0][j]) flag=0;
            }
        }

        int sum=0;
    if(flag){
        for(int i=0;i<fk;i++){
            sum+= clc(i);
        }
    }
        printf("Case #%d: ",run);
        if(flag==0) cout<<"Fegla Won\n";
        else cout<<sum<<"\n";



	}





	return 0;
}

