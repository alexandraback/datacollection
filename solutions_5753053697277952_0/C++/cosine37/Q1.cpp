#include<iostream>
#include<fstream>
using namespace std;
int a[100];
ifstream in("small.txt");
ofstream out("Q1.out");
int findmax(int n){
    int max=0;
    int maxc=0;
    int i;
    for (i=0;i<n;i++) if (a[i]>max) {max=a[i];maxc=i;}
    return maxc;
}
bool onlytwo(int n){
     int i=0;
     int total=0;
     for (i=0;i<n;i++) total=total+a[i];
     if (total==2) return true;
     return false;
}
bool nobody(int n){
     int i=0;
     int total=0;
     for (i=0;i<n;i++) total=total+a[i];
     if (total==0) return true;
     return false;
}
int main(){
    int t;
    in>>t;
    int i,j,x,n;
    char ch;
    for (i=1;i<=t;i++){
        in>>n;
        out<<"Case #"<<i<<": ";
        for (j=0;j<n;j++) in>>a[j];
        while (1){
              x=findmax(n);
              a[x]--;
              x=x+65;
              ch=x;
              out<<ch;
              if (onlytwo(n)) {out<<" "; continue;}
              if (nobody(n)) {out<<endl; break;}
              x=findmax(n);
              a[x]--;
              x=x+65;
              ch=x;
              out<<ch;
              if (nobody(n)) {out<<endl; break;} else out<<" ";
        }
    }
}
