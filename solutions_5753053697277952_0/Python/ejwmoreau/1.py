cases = int(input())

letters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
           "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]

for c in range(cases):
    n = int(input())

    parties = [int(i) for i in input().split()]

    pm = []
    for i in range(len(parties)):
        pm.append([parties[i], letters[i]])

    order = []
    while len(pm) > 0:
        pm = sorted(pm, key=lambda party: party[0], reverse=True)

        #print(n, ":", pm)

        if len(pm) == 3 and pm[0][0] == 1 and pm[1][0] == 1 and pm[2][0] == 1:
            pm[0][0] -= 1
            order.append(pm[0][1])

            if pm[0][0] == 0:
                del(pm[0])
        else:
            pm[0][0] -= 1
            pm[1][0] -= 1
            order.append(pm[0][1] + pm[1][1])

            if len(pm) > 1 and pm[1][0] == 0:
                del(pm[1])
            if pm[0][0] == 0:
                del(pm[0])

        #print(" ".join(order))

    print("Case #" + str(c+1) + ":", " ".join(order))
