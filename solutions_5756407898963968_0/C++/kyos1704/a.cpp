#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int ans;
int a[2];
vector<vector<int>> f[2];
void input(){
  for(int k=0;k<2;k++){
    cin>>a[k];a[k]--;
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        cin>>f[k][i][j];
      }
    }
  }
}
void solve(){
  vector<int> l[2];
  for(int i=0;i<2;i++){
    for(int j=0;j<4;j++){
      l[i].push_back(f[i][a[i]][j]);
    }
  }
  for(int i=0;i<2;i++){
    sort(l[i].begin(),l[i].end());
  }
  vector<int> ll;
  { 
    int i=0,j=0;
    while(i<4&&j<4){
      if(l[0][i]==l[1][j]){
        ll.push_back(l[0][i]);
        i++;j++;
      }else{
        if(l[0][i]<l[1][j]){
          i++;
        }else{
          j++;
        }
      }
    }
  }
  //for(auto i:ll)cout<<i<<endl;
  if(ll.size()==1){
    ans = ll[0];
  }else if(ll.size()==0){
    ans = -2;
  }else{
    ans = -1;
  }

}



void print(int n){
  cout<<"Case #"<<n<<": ";

  switch(ans){
    case -1:
      cout<<"Bad magician!"<<endl;
      break;
    case -2:
      cout<<"Volunteer cheated!"<<endl;
      break;
    default:
      cout<<ans<<endl;
  }
}


int main(){
  int t;
  cin>>t;
  for(int k=0;k<2;k++){
    f[k].resize(4);
    for(int i=0;i<4;i++){
      f[k][i].resize(4);
    }
  }
  for(int i=0;i<t;i++){
    input();
    solve();
    print(i+1);
  }
}
