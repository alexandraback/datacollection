#include <iostream>
#include <string>
#include <map>

using namespace std;

const int SIZE = 16;
const int NUMBER_ROOMS_PER_CHAR = 7;

int R, C, N;
int numberRooms;

map<string, int> bestCost[SIZE];

inline int RoomToCharPosInString(int room)
{
    return room / NUMBER_ROOMS_PER_CHAR;
}

inline int RoomToPosInChar(int room)
{
    return room % NUMBER_ROOMS_PER_CHAR;
}

bool IsRoomTaken(const string &rooms, int room)
{
    return rooms[RoomToCharPosInString(room)] & (1 << RoomToPosInChar(room));
}

void TakeRoom(string &rooms, int room)
{
    rooms[RoomToCharPosInString(room)] |= (1 << RoomToPosInChar(room));
}

void PrintOut(const string &rooms)
{
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            int pos = r * C + c;
            
            cout << IsRoomTaken(rooms, pos);
        }
        cout << '\n';
    }
}

// Only need to look left and above
int GetRoomCost(const string &rooms, int roomPos)
{
    int cost = 0;
    
    // If not in first row
    if (roomPos % C != 0 && IsRoomTaken(rooms, roomPos - 1))
    {
        ++cost;
    }
    
    if (roomPos >= C && IsRoomTaken(rooms, roomPos - C))
    {
        ++cost;
    }
    
    return cost;
}

int GetBest(const string &rooms, int roomPos, int numberTaken);

int TryWithTakingRoom(string rooms, int roomPos, int numberTaken)
{
    TakeRoom(rooms, roomPos);
    int costForCurrent = GetRoomCost(rooms, roomPos);
    
    return costForCurrent + GetBest(rooms, roomPos + 1, numberTaken + 1);
}

int GetBest(const string &rooms, int roomPos, int numberTaken)
{
    if (roomPos == numberRooms)
        return 0;
    
    map<string, int>::iterator cost = bestCost[roomPos].find(rooms);
    if (cost == bestCost[roomPos].end())
    {
        int currentBest = 0;
        if (numberTaken < N)
        {
            // Try it when using this room, try without using (if possible)
            currentBest = TryWithTakingRoom(rooms, roomPos, numberTaken);
            
            // There are enough spots left without taking this one
            int numRoomsLeft = numberRooms - roomPos - 1;
            int numberTakenRemaining = N - numberTaken - 1;
            if (numRoomsLeft > numberTakenRemaining)
            {
                int costWithout = GetBest(rooms, roomPos + 1, numberTaken);
                if (costWithout < currentBest)
                {
                    currentBest = costWithout;
                }
            }
        }
        cost = bestCost[roomPos].insert(std::pair<string, int>(rooms, currentBest)).first;
    }
    
    return cost->second;
}

int main()
{
    string rooms(SIZE / NUMBER_ROOMS_PER_CHAR + 1, '\0');
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        for (int i = 0; i < rooms.size(); ++i)
            rooms[i] = '\0';
        
        cin >> R >> C >> N;
        
        numberRooms = R * C;
        for (int i = 0; i < numberRooms; ++i)
            bestCost[i].clear();
        
        cout << "Case #" << t << ": " << GetBest(rooms, 0, 0) << '\n';
    }
}