T = int(input())

for t in range(T):
    N = int(input())

    points = []
    for n in range(N):
        points.append(tuple(map(int, input().split())))

    print("Case #" + str(t+1) + ":")
    for p in points:
        numbers = []
        for q in points:
            if p == q:
                continue

            number1 = 0
            number2 = 0
            if p[0] == q[0]:
                for z in points:
                    if z[1] < p[1]:
                        number1 += 1
                    elif z[1] > p[1]:
                        number2 += 2
            elif p[1] == q[1]:
                for z in points:
                    if z[0] < p[0]:
                        number1 += 1
                    elif z[0] > p[0]:
                        number2 += 2
            else:
                a = (q[1] - p[1])
                a2 = (q[0] - p[0])
                b = p[1]*a2 - p[0] * a

                for z in points:
                    if a * z[0] + b > z[1]*a2:
                        number1 += 1
                    elif a * z[0] + b < z[1]*a2:
                        number2 += 1
            numbers.append(min(number1, number2))

        if numbers:
            print(min(numbers))
        else:
            print(0)

                

                
        
