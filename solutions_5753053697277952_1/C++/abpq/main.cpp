#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
    ifstream fcin;
    ofstream fout;
    fcin.open("input.txt");
    fout.open("output.out");
    int T;
    pair<int,char> arr[27];
    fcin>>T;
    for(int i=1;i<=T;i++){
        int n;
        fcin>>n;
        for(int j=0;j<n;j++){
            fcin>>arr[j].first;
            arr[j].second='A'+j;
        }
        arr[n].first=0;
        arr[n].second='Z';
        fout<<"Case #"<<i<<": ";
        while(1){
            sort(arr,arr+n+1);
            if(arr[n].first==0)
                break;
            if(arr[n-2].first==0){
                fout<<arr[n].second<<arr[n-1].second;
                arr[n].first--;
                arr[n-1].first--;
            }
            else if(arr[n].first>arr[n-2].first){
                if(arr[n].first>arr[n-1].first){
                    fout<<arr[n].second;
                    arr[n].first--;
                }
                else{
                    fout<<arr[n].second<<arr[n-1].second;
                    arr[n].first--;
                    arr[n-1].first--;
                }
            }
            else{
                fout<<arr[n].second;
                arr[n].first--;
            }
            fout<<' ';
        }
        fout<<"\n";
    }
}

