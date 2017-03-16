#include<iostream>

using namespace std;


int main(int argv,char** argc){

    int ntest;
    cin>>ntest;
    int nums1[4];
    int nums2[4];

    for(int testi=0;testi<ntest;testi++){
        
        int fans;
        cin>>fans;

        for(int rowi=0;rowi<4;rowi++){
            for(int coli=0;coli<4;coli++){
                int temp;
                cin >> temp;
                if(rowi==fans-1){
                    nums1[coli]=temp;
                }
            }
        }
        
        int fans2;
        cin>>fans2;
        for(int rowi=0;rowi<4;rowi++){
            for(int coli=0;coli<4;coli++){
                int temp;
                cin >> temp;
                if(rowi==fans2-1){
                    nums2[coli]=temp;
                }
            }
        }

        int tans;
        int has=0;
        for(int i1=0;i1<4;i1++){
            for(int i2=0;i2<4;i2++){
                if(nums1[i1]==nums2[i2]){
                    if(has==1){
                        has++;
                        break;
                    }
                    tans=nums1[i1];
                    has++;
                }
            }
            if(has>1){
                break;
            }
        }

        cout<<"Case #"<<testi+1<<": ";
        
        if(has==1){
            cout<<tans;
        }else if(has>1){
            cout<<"Bad magician!";
        }else{
            cout<<"Volunteer cheated!";
        }

        cout<<endl;

    }

    return 0;
}


