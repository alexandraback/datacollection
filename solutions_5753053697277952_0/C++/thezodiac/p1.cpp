#include <bits/stdc++.h>
#define fore(i,j,k) for(int i = j;i<k;i++)
#define forr(i,j,k) for(int i = j;i>k;i--)
#define LL long long

using namespace std;


int main () {
    ios_base :: sync_with_stdio(false);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin >> t;

    fore(tc,1,t+1){
        cout << "case #" << tc << ": ";

        int n;
        cin >> n;
        int a[n],b[n],tot = 0;
        fore(i,0,n){
            cin >> a[i];
            tot += a[i];
            b[i] = a[i];
        }

        vector <int> ans;
        int rem[1001] = {0};


        fore(i,0,tot){

            int mx = 0,ind = -1;
            fore(j,0,n)
                if(a[j]>mx){
                    mx = a[j];
                    ind = j;
                }
            if(2*a[ind] > tot-i){
                //cout << "LOLLLLLLLLLLLLLLLLLLLLLLLLL\n";
                //cout << a[ind] << " " << tot-i << endl;
                rem[i] = 1;
            }

            ans.push_back(ind);
            a[ind]--;
        }


        fore(i,0,ans.size()-2){
            if(i+1<=ans.size()-3 && rem[i+1]==1){
                char ch = ans[i] + 'A',ch1 = ans[i+1]+'A';
                cout << ch << ch1 << " ";
                i++;
                b[ans[i]]--; b[ans[i+1]]--;

            } else {
                char ch = ans[i] + 'A';
                cout << ch << " ";
                b[ans[i]]--;
            }

            int sum = 0,mx = 0;
            fore(j,0,n){
                sum = sum + b[j];
                mx = max (b[j],mx);
            }

            if(2*mx > sum){

                cout << "\nLOL\n";
            }


        }

        char ch = ans[ans.size()-1]+'A',ch1 = ans[ans.size()-2]+'A';
        cout << ch << ch1 << endl;
    }



    return 0;
}

/// flaw = orders are indeed not in order
