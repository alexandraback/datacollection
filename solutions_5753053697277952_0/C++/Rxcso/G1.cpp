#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <iomanip>
#include <vector>
#include <ctime>
 
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define clr(a, v) memset( a , v , sizeof(a) )
#define pb push_back
#define mp make_pair
#define sz size()
#define FORN( i , s , n ) for( int i = (s) ; i < (n) ; i++ )
#define FOR( i , n ) FORN( i , 0 , n )
#define FORIT( i , x ) for( typeof x.begin() i = x.begin() ; i != x.end() ; i++ )
#define trace(x)    cout << #x << ": " << x << endl;
#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define read ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;
 
typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;
typedef pair<ii,int> tri;


int A[100];

int main(){
    
    int T,caso=1;
    cin>>T;
    
    while(T--){
        int n;
        cin>>n;
        FOR(i,n) scanf("%d",&A[i]);        
        
        int tot=0;
        set<ii> S;
        FOR(i,n)S.insert(mp(-A[i],i));
        FOR(i,n) tot+=A[i];
        
        printf("Case #%d: ",caso++);
         
        ii ini,seg; 
        while(tot){
            set<ii>::iterator it = S.begin();
            ini = *it; it++;
            seg = *it;
            
            if(ini.fst < seg.fst){
                it--;
                S.erase(it);
                if(tot > 3){
                    printf(" %c%c",'A'+ini.snd,'A'+ini.snd);
                    tot-=2;
                    ini.fst-=2;
                    S.insert(ini);
                }
                else{
                    printf(" %c",'A'+ini.snd);
                    tot--;
                    ini.fst--;
                    S.insert(ini);
                }
            }    
            else{
                it--;
                S.erase(it);
                if(tot == 2 or tot>3){
                    printf(" %c%c",'A'+ini.snd,'A'+seg.snd);
                    tot-=2;
                    ini.fst--;
                    seg.fst--;
                    S.insert(ini);
                    S.insert(seg);
                }
                else{
                    printf(" %c",'A'+ini.snd);
                    tot--;
                    ini.fst--;
                    S.insert(ini);
                }
                
            }
            
            printf("\n");
        }
        
        
        
        
        

              
                    
    }    
    

    return 0;
}




