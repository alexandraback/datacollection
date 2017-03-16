def find_jumps(numbers):
    jumps = []
    for i in range(len(numbers) - 1):
        a = numbers[i]
        b = numbers[i+1]
        jumps.append(a - b)
    return jumps

def method_1(numbers):
    jumps = find_jumps(numbers)
    return sum([j for j in jumps if j > 0])

def method_2(numbers):
    largest_jump = max(find_jumps(numbers))
    # print(largest_jump)
    total = 0
    for i in range(len(numbers) - 1):
        n = numbers[i]
        if n <= largest_jump:
            total += n
        else:
            total += largest_jump
    return total

tests = int(input())
for i in range(tests):
    input()
    numbers = [int(j) for j in input().split()]
    ans_1 = method_1(numbers)
    ans_2 = method_2(numbers)
    print("Case #{}: {} {}".format(i + 1, ans_1, ans_2))