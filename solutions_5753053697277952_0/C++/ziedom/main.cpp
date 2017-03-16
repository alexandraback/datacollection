#include <bits/stdc++.h>

using namespace std;
int tab[26];
pair<int,int> getmax(int n){
    int m=0 , c=0;
    for(int i = 0 ; i< n; i++){
        if(tab[i]>m) m=tab[i] ,c=1 ;
        else if(tab[i]==m) c++;
    }
    //cout << m << ' ' ;
    if(m==0) return  make_pair(-1,-1) ;
    vector<int> A ;
    for(int i = 0 ; i< n ; i++) if(tab[i]==m) A.push_back(i);
    if(A.size()>1 ) {
        if(c!=3) return make_pair(A[0],A[1]) ;
        else return make_pair(A[0],-1) ;
    }
    else if( A.size()==1) return make_pair(A[0],-1) ;
    else return make_pair(-1,-1) ;
}
int main()
{
    ifstream cin("A-small-attempt1 (1).in");
    ofstream cout("out.txt");
    int t ;
    cin >>t ;
    int cp = 1 ;
    while(t--){
            cout << "Case #" << cp++ << ":" ;
      int n ;
      cin >> n ;
      for(int i = 0 ; i< n ; i++){
        cin >> tab[i];
      }
      pair<int,int> a ;
      while((a=getmax(n))!=make_pair(-1,-1)){
        cout <<' ' << (char)(a.first+'A') ;
        tab[a.first]--;
        if(a.second!=-1)tab[a.second]--, cout << (char)(a.second+'A') ;
      }
      cout <<endl;
    }
    return 0;
}
