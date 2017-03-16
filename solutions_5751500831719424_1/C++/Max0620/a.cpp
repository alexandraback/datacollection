#include <iostream>
using namespace std;
string arr[120];
int count1[120];
int index1[120];
int n;
int abs(int a, int b) {
    int ret = a-b;
    if (ret < 0)
        return -ret;
    return ret;
}
void process() {
    cin>>n;
    int i,j;
    for(i=0;i<n;i++) {
        cin>>arr[i];
        count1[i] = 0;
        index1[i] = 0;
    }
    int ret = 0;
    while(true) {
        bool hasArr = false;
        for(i=0;i<n;i++) {
            count1[i] = 0;
            
            while(index1[i] < arr[i].length()) {
                count1[i]++;
                index1[i]++;
                if (index1[i] == arr[i].length() || arr[i][index1[i]] != arr[i][index1[i]-1]) {
                    if (index1[i] == arr[i].length()) {
                        hasArr = true;
                        //cout<<i<<" has arrive"<<endl;
                        //cout<<index1[i]<<endl;
                        
                        //cout<<index1[0]<<endl;
                    }
                    break;
                }
            }
        }
        
        for(i=0;i<n;i++) {
            if (arr[i][index1[i] -1] != arr[0][index1[0] -1]) {
                cout<<"Fegla Won"<<endl;
                return;
            }
            if (hasArr && index1[i] != arr[i].length()) {
                cout<<"Fegla Won"<<endl;
                //cout<<index1[i]<<endl;
                //cout<<count1[i]<<endl;
                //cout<<i<<endl;
                return;
            }
        }
        int min = 20000;
        for(j=1;j<110;j++) {
            int tot=0;
            for(i=0;i<n;i++) {
                tot += abs(count1[i], j);
            }
            if (tot < min) {
                min = tot;
            }
        }
        ret += min;
        if (hasArr) {
            break;
        }
    }
    cout<<ret<<endl;
}

int main() {
    int t,i;
    cin>>t;
    for(i=0;i<t;i++) {
        cout<<"Case #" <<(i+1)<<": ";
        process();
        //cout<<endl;
    }
    return 0;
}
