def eaten_at_least_method_1(mushrooms):
    eaten_at_least = 0
    for i in range(len(mushrooms) - 1):
        if mushrooms[i] >= mushrooms[i + 1]:
            eaten_at_least += mushrooms[i] - mushrooms[i + 1]
    return eaten_at_least

def eaten_at_least_method_2(mushrooms):
    mushrooms = list(map(lambda x: x * 10, mushrooms))
    eating_rate = -100000000000000
    for i in range(len(mushrooms) - 1):
        if mushrooms[i] >= mushrooms[i + 1]:
            diff = mushrooms[i] - mushrooms[i + 1]
            if diff % 10 == 0:
                eating_rate = max(diff // 10, eating_rate)
            else:
                eating_rate = max((diff // 10) + 1, eating_rate)
    eaten_at_least = 0
    for i in range(len(mushrooms) - 1):
        eaten_at_least += min(mushrooms[i], eating_rate * 10)
    return eaten_at_least // 10

if __name__ == "__main__":
    with open("input.txt", "r") as input, open("output.txt", "w") as output:
        T = int(input.readline())
        for t in range(1, T + 1):
            N = int(input.readline())
            tokens = input.readline().split(" ")
            mushrooms = list(map(int, tokens))
            method_1_answer = eaten_at_least_method_1(mushrooms)
            method_2_answer = eaten_at_least_method_2(mushrooms)
            print("Case #{0}: {1} {2}".format(t, method_1_answer, method_2_answer), file=output)