import sys
import time

start_time = time.time()

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
sys.stdout = sys.__stdout__

characters = [chr(i) for i in range(65,91)]
for testcases in range(int(input())):
    n = int(input())
    s = list(map(int,input().split()))
    ans =''
    res = 0
    arr = []
    for i in range(n):
        res += s[i]
        arr.append([s[i], characters[i]])
    arr.sort(reverse=True)
    while arr[0][0] > 0:
        c = arr[0][1]
        res -= 1
        arr[0][0] -= 1
        try:
            if (arr[1][0] - 1)/(res - 1) >= 0.5:
                c += arr[1][1]
                res -= 1
                arr[1][0] -= 1
        except ZeroDivisionError:
            c += arr[1][1]
            res -= 1
            arr[1][0] -= 1
        arr.sort(reverse=True)
        ans += c + " "
    sys.stdout = open("output.txt", "a")
    print("Case #" + str(testcases + 1) + ": " + ans)
    sys.stdout = sys.__stdout__
    print("Case #" + str(testcases + 1) + ": Done")

sys.stdout = sys.__stdout__
print(time.time() - start_time)