#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
using namespace std;

bool mask_bit(char*,int);

bool compare_func (pair<char,int>A,pair<char,int>B){  return ( A.second > B.second );  }

int main(int argc,char *argv[]){

    fstream fs(argv[1],fstream::in);

    int N;
    fs >> N;

    for(int in_index=0; in_index<N; in_index++){
        int party_num;
        int each_party_num;
        fs >> party_num;

        vector<pair<char,int> > party_list;
        for (int i=0; i<party_num;i++){
            fs >> each_party_num;
            pair<char,int> tmp (i+65  ,each_party_num);
            party_list.push_back(tmp);
        }

        sort(party_list.begin(), party_list.end(), compare_func);
        /*
        for (int i=0; i<party_num;i++){
            cout <<"first "<< party_list[i].first<<" snd "<< party_list[i].second<<endl;
        }
        */


        cout<<"Case #"<<in_index+1<<":";

        while( party_list.size() !=0 ){
            int tmp = party_list[0].second;
            if((party_list.size()==2)  && (tmp== 1)){
                cout <<" "<< party_list[0].first << party_list[1].first ;
                break;
            }
            if(party_list.size()>=2 && (party_list[0].second == party_list[1].second)){
                if(party_list[0].second == 1){
                    cout<<" "<<party_list[0].first;
                    party_list[0].second--;
                }
                else {
                    cout <<" "<< party_list[0].first << party_list[1].first ;
                    party_list[0].second--;
                    party_list[1].second--;
                }
            }
            else {
                cout <<" "<< party_list[0].first;
                party_list[0].second--; 
            }


            while (party_list[0].second == 0){
                party_list.erase( party_list.begin(), party_list.begin()+1);
            }
            if(party_list.size() == 0){
                break;
            }
            sort(party_list.begin(), party_list.end(), compare_func);
            //cout<<"  size: "<< party_list.size()<<endl;



            // check answer
            int total_man=0;
            for(int i=0; i< party_list.size();i++){
                total_man += party_list[i].second;
            }
            for(int i=0; i<party_list.size();i++){
                float a = (float)party_list[i].second / (float)total_man;
                if (a > 0.5){
                    cout <<"error!!\n";
                }
            }
            
        }
/*
        for (int i=0; i<party_num;i++){
            for(int cnt=0; cnt< party_list[i].second; cnt++ ){
                cout <<" " << party_list[i].first;
            }
        }
*/
        cout <<endl;

    }

    fs.close();
    return 0;
}

bool mask_bit(char* array,int N){
   bool pass = false; 

   while(N != 0){
      int mod_num = N%10;
      array[mod_num] = 1;
      N /= 10;
   }
    int cnt=0;
    for(cnt=0;cnt<10;cnt++){
        if(array[cnt] == 0){
            break;
        }
    }
    if(cnt == 10){
        pass = true;
    }
    return pass;
}
