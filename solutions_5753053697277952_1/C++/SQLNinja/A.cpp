#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
	freopen("A.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;cin>>tc;
	for(int t=1;t<=tc;t++){
		int N;cin>>N;double sum=0,avg;
		vector<int>v(N);
		for(int i=0;i<N;i++){
			cin>>v[i];
			sum+=v[i];
		}
		printf("Case #%d: ",t);
		bool ok = true;
		while(*max_element(v.begin(),v.end())){
            int j = max_element(v.begin(),v.end())-v.begin();
            int save = -1,count=0;
            for(int i=0;i<N;i++){
                if(v[i]==v[j]&&i!=j){
                    save=i;count++;
                }
            }
            if(count==1){
                cout<<(char)('A'+save)<<(char)('A'+j)<<" ";
                   v[j]--;
                   v[save]--;
                }
            else {
                cout<<(char)('A'+j)<<" ";
                v[j]--;
            }

		}
		cout<<endl;


	}
}
