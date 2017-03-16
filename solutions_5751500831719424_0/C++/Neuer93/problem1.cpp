#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int t,n,m,ans;
string a[101];
int b[101];
int d[101][101];
string pattern;

string getPattern(int x,string s){
    string temp = "";
    char c = s[0];
    temp += c;
    int count = 0;
    d[x][count] = 1;
    for (int i = 1; i < s.length(); ++i)
        if (s[i] != c){
            c = s[i];
            temp += c;
            ++count;
            d[x][count] = 1;
        }else{
            ++d[x][count];
        }
    return temp;
}

int calculate(int x){
    int min = 10000000;
    for (int i = 0; i < n; ++i){
        int temp = 0;
        for (int j = 0; j < n; ++j)
            if (d[i][x] > d[j][x])
            {
                temp += (d[i][x] - d[j][x]);
            }else{
                temp += (-(d[i][x] - d[j][x]));
            }
        if (min > temp){
            min = temp;
        }
    }
    return min;
}

int main(){
    cin>>t;
    for (int ii = 0; ii < t; ++ii){
        cin>>n;
        ans = 0;
        for (int i = 0; i < n; ++i){
            cin>>a[i];
        }
        for (int i = 0; i < n; ++i)
            for(int j =0; j< a[i].length();++j)
                d[i][j] = 0;
        pattern = getPattern(0,a[0]);
        bool flag = false;
        for (int i = 1; i < n; ++i)
            if(getPattern(i,a[i]) != pattern){
                flag = true;
            }
        if (flag){
            cout<<"Case #"<<ii+1<<": Fegla Won"<<endl;
            continue;
        }

        cout<<"Case #"<<ii+1<<": ";

        for (int i = 0; i < pattern.length(); ++i){
            ans += calculate(i);
        }
        cout<<ans<<endl;
    }
}
