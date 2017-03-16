input = open('A-small-attempt0.in', 'r')
output = open('A-small-attempt0.out', 'w')
t = int(input.readline().rstrip())
for test in range(t):
    n = int(input.readline().rstrip())
    np = list(map(int, input.readline().rstrip().split()))
    for i in range(n):
        np[i] = [np[i], chr(ord("A") + i)]
    np.sort(reverse=True)
    ans = ""
    ans += (np[0][1] + " ") * (np[0][0] - np[1][0])
    np[0][0] = np[1][0]    
    while n > 2:
        ans += (np[n-1][1] + " ") * np[n-1][0]
        n -= 1 
    ans += (np[0][1] + np[1][1] + " ") * np[0][0]
    output.write("Case #" + str(test + 1) + ": " + str(ans) + "\n")

input.close()
output.close()