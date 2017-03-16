import sys
import time

start_time = time.time()

sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
# sys.stdout = sys.__stdout__

n = int(input())
arr = list(map(int,input().split()))
arr.sort()
avg = sum(arr)/2
a,b = 0,0
for i in arr:
    if a + i > avg:
        b += i
    else:
        a += i
print(abs(b - a) + 1)

sys.stdout = sys.__stdout__
print(time.time() - start_time)
