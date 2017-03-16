#include <iostream>
#include <fstream>
using namespace std;



int main (){
    ifstream in("Al.in");
    ofstream out("aloutput.txt");
    int testcases;
    in >> testcases;
    int testcasses = testcases;
    while (testcasses -->0){
        int N;
        in>>N;
        int sen[30];
        for(int i=0;i<N;i++){
            in>>sen[i];
        }
        out<<"Case #"<<testcases-testcasses<<": ";
        while(true){
            if(N==2){
                if(sen[0]==sen[1] and sen[0]!=0){
                    out<<"AB ";
                sen[0]--;
                sen[1]--;
                    continue;
                }
            }
            int iets=0;
            for(int i=0;i<N;i++){
                iets+=sen[i];
            }
            if(iets==2){
                int a;
                int b;
                for(int i=0;i<N;i++){
                    if(sen[i]==1){
                        a=i;
                        break;
                    }
                }
                for(int i=a+1;i<N;i++){
                    if(sen[i]==1){
                        b=i;
                        break;
                    }
                }
                out<<char('A'+a)<<char('A'+b)<<' ';
                break;
            }
            int maxi=sen[0];
            int partij=0;
            for(int i=1;i<N;i++){
                if(sen[i]>maxi){
                    maxi=sen[i];
                    partij=i;
                }
            }
            if(maxi==0)break;
            sen[partij]--;
            out<<char('A'+partij)<<" ";
        }
        out<<endl;
    }
    return 0;
}
