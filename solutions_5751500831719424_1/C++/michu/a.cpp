#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t,n;
vector<char> wzo;
vector<int> tab;
string s[1000];
int war[101][101];
bool zle;
int mediana,wynik,ind;

bool zgadza_sie(int ktory){
     if(s[ktory][0] != wzo[0])return 0;
     
     int ind = 0;
     
     for(int i=1;i<s[ktory].size();i++){
             if(s[ktory][i] != s[ktory][i-1]){
                   ind++;
                   if(ind == wzo.size())return 0;
                   if(s[ktory][i] != wzo[ind])return 0;                       
             }        
     }
     if(ind != (wzo.size()-1))return 0;
     return 1;     
}

int main(){
    ios_base::sync_with_stdio(0);
    
    cin>>t;
    
    for(int q=1;q<=t;q++){
            cin>>n;
            for(int i=0;i<n;i++){
                    cin>>s[i];
            }
            //1. utworz wzorzec
            wzo.clear();
            wzo.push_back(s[0][0]);
            for(int i=1;i<s[0].size();i++){
                    if(s[0][i] != s[0][i-1])wzo.push_back(s[0][i]);        
            }
            /*
            cout<<"wzorzec: ";
            for(int i=0;i<wzo.size();i++)cout<<wzo[i];
            cout<<endl;
            */
            //2. sprawdz poprawnosc ze wzorcem pozostalych slow
            for(int i=1;i<n;i++){
                    if(!zgadza_sie(i)){
                          zle = 1;
                          break;                   
                    }        
            }
            //3. policz wartosci liter
            if(zle == 1){
                   cout<<"Case #"<<q<<": Fegla won"<<endl;
                   zle = 0;       
            }
            else{
                 for(int i=0;i<n;i++){
                         war[i][0] = 1;
                         ind = 0;
                         for(int j=1;j<s[i].size();j++){
                                 if(s[i][j] != s[i][j-1]){
                                        ind++;
                                 }
                                 war[i][ind]++;  
                         }           
                 }    
                 
            /*     cout<<"war:"<<endl;
                 for(int i=0;i<n;i++){
                         for(int j=0;j<wzo.size();j++){
                                 cout<<war[i][j]<<" ";        
                         }
                         cout<<endl;        
                 }
            */
            //4. dla kazdej kolumny policz mediane i dodaj do wyniku |wszystko-mediana|
                 for(int i=0;i<wzo.size();i++){
                    tab.clear();
                    for(int j=0;j<n;j++){
                            tab.push_back(war[j][i]);        
                    }
                    sort(tab.begin(),tab.end());
                    mediana = tab[n/2];
                    for(int j=0;j<tab.size();j++){
                            wynik+=abs(tab[j]-mediana);        
                    }
                 }    
            cout<<"Case #"<<q<<": "<<wynik<<endl;
            wynik = 0;
            for(int i=0;i<n;i++){
                    for(int j=0;j<wzo.size();j++){
                            war[i][j] = 0;        
                    }        
            }
            }
    }
    
    
    
    return 0;
}
