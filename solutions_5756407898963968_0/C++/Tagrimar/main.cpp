#include <fstream>
#include <vector>

using namespace std;


int main(int argc, const char * argv[])
{
    ifstream cin("A-small-attempt0.in.txt");
    ofstream cout("A-small-attempt0.out.txt");
    
    int T;
    cin>>T;
    for(int q = 0; q < T; q++)
    {
        int answer_one;
        cin>>answer_one;
        int position_one[4][4];
        for (int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin>>position_one[i][j];
        
        int answer_two;
        cin>>answer_two;
        int position_two[4][4];
        for (int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin>>position_two[i][j];
        
        int number_of_answers = 0;
        int answer;
        answer_one--; answer_two--;
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(position_one[answer_one][i] == position_two[answer_two][j]) {
                    number_of_answers++;
                    answer = position_one[answer_one][i];
                }
        cout << "Case #" << q + 1 << ": ";
        switch (number_of_answers) {
            case 0:
                cout << "Volunteer cheated!\n";
                break;
                
            case 1:
                cout << answer << "\n";
                break;
                
            default:
                cout << "Bad magician!\n";
                break;
        }
    }
    
}

