#include <iostream>
#include <vector>
#include <set>

using namespace std;





void magician()
{
    int nb_case;
    cin >> nb_case;

    int first_choice, second_choice;

    set<int> choice1;
    vector<int> choice2;

    int tmp;

    int found, founded;
    for(int i=0; i<nb_case; i++)
    {
        choice1.clear();
        choice2.clear();
        cin >> first_choice;
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                cin >> tmp;
                if(j==first_choice-1)
                {
                    choice1.insert(tmp);
                }
            }
        }
        cin >> second_choice;
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                cin >> tmp;
                if(j==second_choice-1)
                {
                    choice2.push_back(tmp);
                }
            }
        }

        found = 0;
        for(int j=0; j<4; j++)
        {
            if(choice1.count(choice2[j])==1)
            {
                found++;
                founded = choice2[j];
            }
        }
        cout << "Case #" << i+1 << ": ";
        if(found==0)
        {
            cout << "Volunteer cheated!";
        }
        else if(found==1)
        {
            cout << founded;
        }
        else
        {
            cout << "Bad magician!";
        }
        cout << "\n";
    }

}

int main()
{
    magician();
    return 0;
}
