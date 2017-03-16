#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll X[3000];
ll Y[3000];
#define D(X) if(i==4){/*X*/}
int main()
{
	#ifdef DBG
	//freopen("case.in", "r" , stdin);
	#endif
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int T,N,c=1;
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0;i<N;++i)
			cin>>X[i]>>Y[i];
		cout<<"Case #"<<c++<<":"<<'\n';
		for(int i=0;i<N;++i)
		{
			int ans = N;
			//cout<<"D:"<<N<<endl;
			if( N==1 ||  N==2 ){
				cout<<"0\n";//<<endl;
				continue;
			}
			for(int j=0;j<N;++j)
			{
				if(i==j)continue;
				int fail = 0;
				D( 
					cout<<i<<'='<<j<<" fail:";
					cout<<endl<<"("<<X[j]-X[i]<<","<<(Y[j]-Y[i])<<")"<<endl;
				)
				for(int k=0;k<N;++k)
				{
					if( k==i || k==j )continue;
					if( (X[j]-X[i])*(Y[k]-Y[i]) < (X[k]-X[i])*(Y[j]-Y[i]) )
					{
						fail++;
						D(cout<<k<<' ';)
					}
				}D(cout<<endl;)
				ans = min( {ans,fail,N-fail} );
				D( 
					cout<<" fail"<<fail<<'\n';
				)
			}
			assert(ans!=N);
			assert(N-ans>=3);
			cout<<ans<<'\n';
		}
	}

}

