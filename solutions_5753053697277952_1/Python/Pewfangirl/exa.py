def case():
    n = int(input())
    amount = list(map(int, input().split()))
    for i in range(n):
        amount[i] = [amount[i], chr(ord("A") + i)]
    
    full = n
    amount = sorted(amount)
    while amount[-1][0] != 0:
        if full == 2 and amount[-2][0] == amount[-1][0]:
            amount[-1][0] -= 1
            amount[-2][0] -= 1
            print(amount[-2][1] + amount[-1][1], end = " ")
        else:
            amount[-1][0] -= 1
            if amount [-1][0] == 0:
                full -= 1
            print(amount[-1][1], end = " ")
        amount = sorted(amount)


t = int(input())
for i in range(t):
    print("Case #" + str(i + 1) + ": ", end = "")
    case()
    print()