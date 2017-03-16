#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main(){
    int T=0,k=1;
    cin >> T;
    while(T--){
        string ans="";
        int n=0,num[30],total=0;
        cin >> n;
        for(int a=0;a<n;a++){
            cin >> num[a];
            total += num[a];
        }
        
        while(total>0){
            ans=ans+" ";
            int cnt=0;
            while(cnt<2){
                /*
                cout << total << " " << cnt << endl;
                for(int a=0;a<n;a++){
                    cout << "#" << num[a];
                }
                cout << endl;
                */
                int maxx=0,maxx_a=-1;;
                for(int a=0;a<n;a++){
                    if(num[a]>maxx){
                        maxx_a=a;
                        maxx=num[a];
                    }
                }
                num[maxx_a]--;
                int half=(total-cnt)/2;
                if(half==1&&total==3){
                    num[maxx_a]++;
                    int tmp_a=0;
                    for(int a=0;a<n;a++){
                        if(num[a]==1){
                            tmp_a=a;
                            break;
                        }
                    }
                    cnt++;
                    num[tmp_a]--;
                    char tmp='A'+tmp_a;
                    ans=ans+tmp;
                    break;
                }
                int flag=true;
                for(int a=0;a<n;a++){
                    if(num[a]>half){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    cnt++;
                    char tmp='A'+maxx_a;
                    ans=ans+tmp;
                }
                else{
                    num[maxx_a]++;
                    break;
                }
            }
            total=total-cnt;
        }

        cout << "Case #" << k << ":" << ans << endl;
        k++;
    }
    return 0;
}

