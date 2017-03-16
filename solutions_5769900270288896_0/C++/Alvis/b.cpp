//Template

// By Anurag :P
//Includes
#include <bits/stdc++.h>

using namespace std;

//Shortforms
typedef long long ll;
typedef vector <int> vi;
typedef vector <long long> vl;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define dg(s,n); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()

vector<vector<int> >v; 

void KSubset(int *a,int n,int *s,int sindex,int index,int k){
	vector<int> v1;
    if (index>n)
        return;

    if (k==0){
        for(int i=0;i<sindex;i++)
            {
				v1.push_back(s[i]);
			}
        v.push_back(v1);
        return ;
        }

    s[sindex]=a[index];
    KSubset(a,n,s,sindex+1,index+1,k-1);
    KSubset(a,n,s,sindex,index+1,k);
}

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		v.clear();
		int r,c,n,ans;
		ans = 1000;
		cin>>r>>c>>n;
		int a[r*c];
		for(int k=0;k<r*c;k++) a[k] = k+1;
		int s[n];
		KSubset(a,r*c,s,0,0,n);
		//cout<<"vector size is"<<v[0].size()<<endl;
		for(int k = 0;k<v.size();k++){
			int grid[17][17];
			for(int q=0;q<17;q++){
				for(int w=0;w<17;w++) grid[q][w] = 0;
			}
		
			for(int l=0;l<v[k].size();l++){
				//cout<< "nume is "<<v[k][l]<<" ";
				if(v[k][l] < c) grid[1][v[k][l]] = 1;
				else if(v[k][l]%c==0) grid[(v[k][l]-1)/c+1][c] = 1;
				else if(v[k][l]%c!=0) grid[(v[k][l]-1)/c+1][(v[k][l])%c] = 1;
			}
			
			//~ for(int l=0;l<v[k].size();l++) cout << v[k][l]<<" ";
			//~ cout<<endl;
			//~ 
			
			
			int cnt = 0;
			
			for(int k=1;k<=r;k++){
				for(int l = 1;l<c;l++){
					if(grid[k][l] == 1 && grid[k][l+1]==1) cnt++;
				}
			}
			for(int p=1;p<=c;p++){
				for(int l = 1;l<r;l++){
					if(grid[l][p] == 1 && grid[l+1][p]==1) cnt++;
				}
			}
			//cout<<"cnt is "<<cnt<<endl;
			
			//~ for(int q=1;q<=r;q++){
				//~ for(int w=1;w<=c;w++) cout<<grid[q][w];
				//~ cout<<endl;
			//~ }
			//cout<<endl;
			
			ans = min(cnt,ans);			
					
		}
		
		cout <<"Case #"<<i<<": "<<ans<<endl;
	}

		
	
	
	
	
	
	return 0;
}
