from sys import stdin, stdout

def count(string):
    result = []
    for c in string:
        if len(result) == 0 or result[-1][0] != c:
            result.append((c,1))
        else:
            count = result[-1][1]
            result[-1] = (c, count+1)
    return result

def all_equal(arr):
    first = arr[0] if arr else None
    return all(a == first for a in arr[1:])

def solve(strings):
    counts = map(count, strings)

    if not all_equal(map(len, counts)):
        return None

    # All the same length
    total = 0

    length = len(counts[0])

    for idx in range(length):
        position = [ c[idx] for c in counts ] 
        
        if not all_equal([c for c, _ in position]):
            return None

        position_counts = sorted(c for _, c in position) 
        median = position_counts[len(position_counts)//2]
        total += sum(abs(x-median) for x in position_counts)

    return total

if __name__ == "__main__":

    T = int(stdin.readline())

    for case in range(1, T+1):
        
        N = int(stdin.readline())
        
        strings = [ stdin.readline().strip() for _ in range(N) ]

        result = solve(strings)
        if result is None:
            result = "Fegla Won"

        stdout.write("Case #{}: {}\n".format(case, result)) 
            
        
