#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int M=105;
const int N=105;
int n;
string a[N],b[N];
int num[N][M];

void get(const string &s, string &cur, int len[]){
    int pos=0;
    cur="";
    for(int i=0; i<s.size(); i++){
        if(s[i]==0 || s[i]!=s[i-1]){
            len[pos++]=1;
            cur += s[i];
        }
        else
            len[pos-1]++;
    }
}

int mi(int j){
    vector<int> v;
    for(int i=0; i<n; i++)
        v.push_back(num[i][j]);
    sort(v.begin(), v.end());
    int md = v[(v.size()-1)/2];
    int sum=0;
    for(int i=0; i<v.size(); i++)
        sum += abs(v[i]-md);
    return sum;
}

int main(int argc, const char * argv[])
{
    int ncase; cin>>ncase;
    for(int ca=1; ca<=ncase; ca++){
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];
        bool suc=true;
        for(int i=0; suc&&i<n; i++){
            get(a[i], b[i],num[i]);
            if(i>0 && b[i]!=b[i-1])
                suc=false;
        }
        cout<<"Case #"<<ca<<": ";
        if(suc){
            int sum=0;
            for(int i=0; i<b[0].size(); i++)
                sum += mi(i);
            cout<<sum<<endl;
        }
        else
            cout<<"Fegla Won"<<endl;
            
    }
    return 0;
}

