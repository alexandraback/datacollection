#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::string;
pair<string, vector<int> > get_unique(string input) {
    string out;
    vector<int> nums;
    for(int i = 0; i < input.size(); ++i) {
        if(out.size() == 0 || out.at(out.size()-1) != input[i]) {
            out.push_back(input[i]);
            nums.push_back(1);
        } else {
            nums[nums.size() -1] +=1;
        }
    }
    return make_pair(out, nums);
}


bool can_win(vector<string> strings) {
    string first= get_unique(strings[0]).first;

    for(int i = 1; i < strings.size(); ++i) {
        string newstr = get_unique(strings[i]).first;

        if(newstr != first) {
            return false;
        }
    }
    return true;
}

int min_edits(vector<int> nums) {
    int lowest = 100000;

    for(int i = 0; i < nums.size(); ++i) {
        int sum = 0;
        for(int j = 0; j < nums.size(); ++j) {
            sum+= abs(nums[i] - nums[j]);
        }
        if(sum < lowest) {
            lowest = sum;
        }
    }
    return lowest;
}


int get_min_edits(vector<string> strings) {
    vector<vector<int> > nums;
    int out;
    for(int i = 0; i < strings.size(); ++i) {
        nums.push_back(get_unique(strings[i]).second);
    }

    int strlengths  = nums[0].size();

    for(int i = 0; i < strlengths; ++i) {
        vector<int> tmp;
        for(int j = 0; j < nums.size(); ++j) {
            tmp.push_back(nums.at(j).at(i));
        }
        out += min_edits(tmp);
    }
    return out;
}



int main() {
    int num_p;
    cin >> num_p;
            string tmp;
    for(int i = 1; i <= num_p; ++i) {
        int num_s;
        cin >> num_s;
        std::getline(cin, tmp);
        vector<std::string> strings;
        for(int j = 0; j < num_s; ++j) {

            std::getline(cin, tmp);

            strings.push_back(tmp);

        }

        cout << "Case #" << i << ": ";
        if(!can_win(strings)) {
            cout << "Fegla Won" << endl;
        } else {
            cout << get_min_edits(strings) << endl;
        }
    }
}
