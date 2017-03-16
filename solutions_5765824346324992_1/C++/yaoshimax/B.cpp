#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;

int main(){
  int n_case;
  cin >> n_case;
  int T[1001];
  for( int loop = 0 ; loop < n_case ; loop++ ){
    long long B,N;
    cin>>B>>N;
    for( int i = 0 ; i < B; i++ ) cin >> T[i];
    long long left=-1;
    long long right=N*200000;
    int just[1001];
    int ans=0;
    while( true ){
       long long mid=(left+right)/2;
       long long num=0;
       long long n_just=0;
       //cout << left << " "<< right<< " " << mid <<endl;
       for( int i = 0 ; i < B; i++ ){
         if( mid!=0 ) num+=1+(mid-1)/T[i];
         if( mid%T[i]==0 ) just[n_just++]=i;
       }
       if( num<N && num+n_just>=N ){
         //cout << mid <<" "<< num << ","<<n_just<<endl;
         //for( int i = 0 ; i < N-num; i++ ){
         //   cout << just[i] << " ";
         //}
         //cout << endl;
         ans=just[N-num-1]+1;
         break;
       }
       if( num>=N ){
         right=mid;
       }
       else{
         left=mid;
       }
    }
    cout << "Case #" << loop+1 << ": " <<ans<< endl;
  }
  return 0;
}
