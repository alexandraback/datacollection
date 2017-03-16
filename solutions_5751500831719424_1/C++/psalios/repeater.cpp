#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

int N;
string w[110];
int pos[110];
map<int,int> Q;

int main(){
    freopen( "repeater.in", "r", stdin );
    freopen( "repeater.out", "w", stdout );
    
    int T; cin>>T;
    
    for(int t=1;t<=T;t++){
            
            cin>>N;
            for(int i=0;i<N;i++){
                    cin>>w[i];
                    pos[i] = 0;
                    }
            
            bool ok = true;
            for(int i=1;i<N;i++)
                    if( w[i][0] != w[0][0] )
                        ok = false;
            
            int c = 0;
            while( ok ){
                int counter = 0;
                for(int i=0;i<N;i++)
                        if( pos[i] == w[i].size() )
                            counter++;
                if( counter== N )
                    break;
                else if( counter > 0 ){
                     ok = false;
                     break;
                     }
                   
                Q.clear();
                char target = w[0][pos[0]];
                for(int i=0;i<N;i++){                        
                        int t = pos[i];
                        while( (t<w[i].size()) && (w[i][t] == target) ){
                               t++;
                               Q[t-pos[i]]++;
                               }
                        if( t == pos[i] ){
                            ok = false;
                            break;
                            }
                        pos[i] = t;
                        }
                
                map<int,int>::iterator it;
                for( it = Q.begin(); it != Q.end(); ++it ){
                     int posa = it->second;
                     if( posa > N/2 )
                         c += N - posa;
                     else
                         c += posa;
                         }
                }
            
            cout<<"Case #"<<t<<": ";
            if( ok )
                cout<<c<<'\n';
            else
                cout<<"Fegla Won\n";
            }
    
    return 0;
}
                 
