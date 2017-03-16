#include<bits/stdc++.h>
using namespace std;
vector<int> getListOfMax(int *arr,int n)
{
   vector<int> answer;
     int maxValue = -1;
     for(int i=0;i<n;i++)
     {
       if(arr[i]>maxValue)
       {
         maxValue=arr[i];
         answer.clear();
         answer.push_back(i);
       }
       else if(arr[i]==maxValue)
         answer.push_back(i);
     }
     return answer;
}
int main()
{
  int t;
  cin>>t;
  for(int gh=1;gh<=t;gh++)
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    cout<<"Case #"<<gh<<": ";
        while(1)
        {
          vector<int> temp = getListOfMax(arr,n);
          if(temp.empty())
            break;
          if(arr[temp[0]]<=0)
            break;

            if(temp.size()==1 || temp.size()==3)
          {
            cout<<(char)('A'+temp[0])<<" ";
            arr[temp[0]]--;
          }
          else
          {
            cout<<(char)('A'+temp[0])<<(char)('A'+temp[1])<<" ";
            arr[temp[0]]--;
            arr[temp[1]]--;
          }
        }
        cout<<endl;
  }
  return 0;
}
