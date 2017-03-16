#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<climits>
#include<fstream>
#include<sstream>

#define forn(i,n) for(int i=0;i<n;i++)
#define forv(it,v,type) for(vector<type>::iterator it=v.begin();it!=v.end();it++)

using namespace std;
ifstream fin ("A-large.in");
ofstream fout ("output.out");

void evac(int a[],int nbparty){
int mmax=0;
forn(i,nbparty){
    if(a[i]>mmax){
        mmax = a[i];
    }
}
if(mmax==0){fout << endl;
            return;}
else{vector<int> v;
    forn(j,nbparty){
        if(a[j]==mmax)v.push_back(j);
    }
    if(v.size()==2){
        fout << " " << char(v.front()+65) << char(v.back()+65);
        a[v.front()]--;a[v.back()]--;
        evac(a,nbparty);
    }
    else{
        fout << " " << char(v.front()+65);
        a[v.front()]--;
        evac(a,nbparty);
    }
}
}

int main(){
int T,nbparty;
fin >> T;
forn(i,T){
fin >> nbparty;
int a[nbparty];
forn(j,nbparty){
    fin >> a[j];
}
cout << "case " << i+1 << endl;
fout << "Case #" << i+1 << ":";
evac(a,nbparty);
}
}
