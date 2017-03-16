input = open('B-small-attempt1.in', 'r')
output = open('B-small1.out', 'w')
t = int(input.readline().rstrip())
for test in range(t):
    r, d, n = map(int, input.readline().rstrip().split())
    ans = 0
    total = 2 * r * d - r - d
    if n > ((r * d + 1) // 2):
        ans += (n - (r * d + 1) // 2) * 2
        if n > (r * d + 1) // 2 + ((r * d + 1) % 2) * 2:
            ans += n - ((r * d + 1) // 2 + ((r * d + 1) % 2) * 2)
            if n > (r * d + 1) // 2 + ((r * d + 1) % 2) * 2 + (d - 1) // 2 * 2 + (r - 1) // 2 * 2:
                ans += n - ((r * d + 1) // 2 + ((r * d + 1) % 2 - 1) * 2 + (d - 1) // 2 * 2 + (r - 1) // 2 * 2)
    if r * d - n <= ((r - 2) * (d - 2) + 1) // 2:
        ans = total - (r * d - n) * 4
    output.write("Case #" + str(test + 1) + ": " + str(ans) + "\n")

input.close()
output.close()
