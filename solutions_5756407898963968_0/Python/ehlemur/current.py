msg = "Volunteer cheated!", "", "Bad magician!"

T = int(input())

for t in range(1, T + 1):
    row1 = int(input())
    cards1 = [set(map(int, input().split()))  for i in range(4)][row1 - 1]

    row2 = int(input())
    cards2 = [set(map(int, input().split()))  for i in range(4)][row2 - 1]

    both = cards1.intersection(cards2)
    print("Case #{}: {}".format(t, both.pop() if len(both) == 1 else msg[min(len(both), 2)]))
