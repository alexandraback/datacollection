def solve(chosen1, list1, chosen2, list2):
    result = set(list1[chosen1 - 1]).intersection(set(list2[chosen2 - 1]))
    if result:
        if len(result) > 1:
            return 'Bad magician!'
        else:
            return result.pop()
    return 'Volunteer cheated!'

def main():
    T = int(input())
    for i in range(1, T + 1):
        chosen1 = int(input())
        list1 = [[int(s) for s in input().strip().split()] for k in range(4)]
        chosen2 = int(input())
        list2 = [[int(s) for s in input().strip().split()] for k in range(4)]
        res = solve(chosen1, list1, chosen2, list2)
        print('Case #', i, ': ', res, sep='')

if __name__ == "__main__":
    main()
