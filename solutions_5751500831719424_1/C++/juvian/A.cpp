#include <iostream>
#include <vector>
#include <fstream>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    int t;
    ifstream in("A-large.in");
    ofstream out("A-large.out");
    in>>t;
    for(int casen=1;casen<=t;casen++){
            int n;
            in>>n;
            vector<string> v;
            for(int j=0;j<n;j++){
                    string s;
                    in>>s;
                    v.push_back(s);        
            }
            vector <string> v2;
            vector <int> apariciones[n];
            for(int j=0;j<n;j++){
                    string s=v[j];
                    string ne="";
                    char c=s[0];
                    int count = 1;
                    for(int g=1;g<s.length();g++){
                            if(c != s[g]) {
                                 ne+=c;
                                 c=s[g];
                                 apariciones[j].push_back(count);
                                 count = 1; 
                            }
                            else{
                                 count++;
                            }             
                    } 
                    ne+=c;
                    apariciones[j].push_back(count);
                    //forn(k, apariciones[j].size()) cout<<apariciones[j][k]<<" ";       
                    //cout<<"\n";
                    
                    v2.push_back(ne);
                   // cout<<ne<<"\n";
            }
            bool feglaWon = false;
            forn(j, n){
                    if ( v2[0] != v2[j])
                       feglaWon= true;  
            }
            
            if(feglaWon){
               out<<"Case #"<<(casen)<<": Fegla Won\n";          
            }else {
                 int sum=0;
                 forn(k,v2[0].size()){
                     vector<int> sorted_aps;                 
                     forn(j, n){
                             sorted_aps.push_back(apariciones[j][k]);
                     }
                     sort(sorted_aps.begin(), sorted_aps.end());
                     int best=sorted_aps[n/2];
                     forn(j, n){
                             sum+=abs(sorted_aps[j]-best);
                     }
                 }
                 out<<"Case #"<<(casen)<<": "<<sum<<"\n";                             
            }
                    
    }   
    
    system("pause");
    
    
}
