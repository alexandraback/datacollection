
#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;
int main(){
    ifstream fcin;
    ofstream fout;
    fcin.open("A-small-attempt0.in");
    fout.open("A.out");
    int testCase;
    char A='A';
    char Z='Z';
    for(int i=0;i<1000;i++){
    }
    pair<int,char> array[100];
    fcin>>testCase;
    for(int i=1;i<=testCase;i++){
        int n;
        fcin>>n;
        
        
        for(int j=0;j<n;j++){
            fcin>>array[j].first;
            array[j].second=A+j;
        }
        array[n].first=0;
        array[n].second=Z;
        fout<<"Case #"<<i<<": ";
        while(1){
            sort(array,array+n+1);
            if(array[n].first==0)
                break;
            if(array[n-2].first==0){
                fout<<array[n].second<<array[n-1].second;
                array[n].first--;
                array[n-1].first--;
            }
            else if(array[n].first>array[n-2].first){
                if(array[n].first>array[n-1].first){
                    fout<<array[n].second;
                    array[n].first--;
                }
                else{
                    
                    
                    
                    fout<<array[n].second<<array[n-1].second;
                    array[n].first--;
                    array[n-1].first--;
                }
            }
            else{
                
                
                fout<<array[n].second;
                array[n].first--;
            
            }
            fout<<' ';
        }
        fout<<"\n";
    }
}

