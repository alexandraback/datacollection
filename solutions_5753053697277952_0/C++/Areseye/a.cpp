#include"iostream"
#include"map"
#include"vector"
#include"string"
#include"cstring"
#include"cstdio"
#include"set"
#include"algorithm"


using namespace std;

int getMax(const vector<int>&vc){
    int N = vc.size();
    int tmp(vc[0]);
    for(auto it:vc){
        tmp = max(tmp,it);
    }
    return tmp;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    cin>>T;
    int casenum = 0;
    while(casenum++<T){
        int N(0);
        cin>>N;
        vector<int>Party;
        int Psum(0);
        for(int i = 0;i<N;i++){
            int tmp;
            cin>>tmp;
            Psum+=tmp;
            Party.push_back(tmp);
        }
        //solution
        vector<string>sol;
        while(Psum>0){
            int maxval = getMax(Party);
            string cursol = "";
            if(maxval==1){
                if(Psum>2){
                    for(int i = 0;i<N;i++){
                        if(Party[i]==1){
                            cursol.push_back('A'+i);
                            Party[i]--;
                            break;
                        }
                    }
                    Psum--;
                    sol.push_back(cursol);
                }
                else{
                    for(int i = 0;i<N;i++){
                        if(Party[i]==1){
                            cursol.push_back('A'+i);
                            Party[i]--;
                        }
                    }
                    sol.push_back(cursol);
                    Psum-=2;
                }
            }else{
                for(int i = 0;i<N&&cursol.size()<2;i++){
                    if(Party[i]==maxval){
                        cursol.push_back('A'+i);
                        Party[i]--;
                    }
                }
                sol.push_back(cursol);
                Psum-=(int)cursol.size();
                 
            }
        }
        printf("Case #%d:",casenum);
        for(auto it:sol){
            cout<<" "<<it;
        }
        cout<<endl;
    }

return 0;}
