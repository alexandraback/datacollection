from string import ascii_uppercase as letters

def solve(l):
    s = sum(l)
    result = []
    indices = range(len(l))
    while s > 0:
        i = max(indices, key=lambda i: l[i])
        l[i] -= 1
        s -= 1
        result.append(letters[i])
        i = max(indices, key=lambda i: l[i])
        if l[i] <= s - l[i]:
            result.append(' ')
    return ''.join(result)

output = 'Case #{}: {}'
num_tests = int(input())
for i in range(num_tests):
    n = int(input())
    l = list(map(int, input().split()))
    print(output.format(i + 1, solve(l)))
