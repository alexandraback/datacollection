#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  int N;
  cin>>N;
  for (int n=1;n<=N;n++){
    int row1, row2, tmp;
    vector<int> nums1;
    vector<int> nums2;
    cin>>row1;
    for (int i=0;i<16;i++) {
      cin>>tmp;
      if (i/4 == row1-1) {
	nums1.push_back(tmp);
      }
    }
    cin>>row2;
    for (int i=0;i<16;i++) {
      cin>>tmp;
      if (i/4 == row2-1) {
	nums2.push_back(tmp);
      }
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> intersection(8);
    vector<int>::iterator it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), intersection.begin());

    cout<<"Case #"<<n<<": ";
    if (it-intersection.begin()>1) {
      cout<<"Bad magician!"<<endl;
    } else if (it-intersection.begin()<1) {
      cout<<"Volunteer cheated!"<<endl;
    } else {
      cout<<*intersection.begin()<<endl;
    }
  }
}
