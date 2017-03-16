#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t,inputs,temp;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> inputs;
        vector<int> mushcount;
        for(int j=0;j<inputs;j++){
            cin >> temp;
            mushcount.push_back(temp);
        }

        //first assumption
        int retfirst=0;
        int mushdiff;
        for(unsigned int it=0;it<mushcount.size()-1;it++){
            mushdiff=mushcount[it]-mushcount[it+1];
            if(mushdiff>0){
                retfirst=retfirst+mushdiff;
            }
        }

        //second
        int retsecond=0;
        int max=0;
        for(unsigned int it=0;it<mushcount.size()-1;it++){
            if(mushcount[it]-mushcount[it+1]>max){
                max=mushcount[it]-mushcount[it+1];
            }
        }
        
        for(unsigned int it=0;it<mushcount.size()-1;it++){
          //  cout << mushcount[it] << max << endl;
            if(mushcount[it]<max){
                retsecond=retsecond+mushcount[it];
            } else {
                retsecond=retsecond+max;
            }
        }

        cout << "Case #" << i+1 << ": " << retfirst << " ";
        cout << retsecond << endl;
    }
}
