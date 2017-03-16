tests = int(input())

for test_case in range(1, tests+1):
    print("Case #" + str(test_case) + ": ", end="")
    parties = int(input())
    senators = [int(x) for x in input().split()]
    senators_count = sum(senators)
    while senators_count > 0:
        out = None
        for i in range(0, parties):
            if senators[i] > 0 and out == None:
                senators[i] -= 1
                if max(senators) <= (senators_count-1)/2:
                    out = chr(ord('A') + i)
                    senators_count -= 1
                    break
                else:
                    senators[i] += 1
        if out == None:
            for i in range(0, parties):
                if out == None:
                    for j in range(i, parties):
                        if senators[i] > 0 and senators[j] > 0 and out == None:
                            senators[i] -= 1
                            senators[j] -= 1
                            if max(senators) <= (senators_count-2)/2:
                                out = chr(ord('A') + i) + chr(ord('A') + j)
                                senators_count -= 2
                                break
                            else:
                                senators[i] += 1
                                senators[j] += 1
        print(out, end=" ")
    print()
