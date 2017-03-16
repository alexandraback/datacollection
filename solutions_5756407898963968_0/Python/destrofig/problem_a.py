

import sys

def read_arrangement(fd):
    arr = []
    for _ in xrange(4):
        arr.append(map(int, fd.readline().split()))
    return arr

def get_answer(an1, arr1, an2, arr2):
    possible1 = set(arr1[an1-1])
    possible2 = set(arr2[an2-1])
    #possible2 = set(row[an2-1] for row in arr2)
    intersect = possible1 & possible2
    if len(intersect) == 1:
        answer = str(list(intersect)[0])
    elif len(intersect) == 0:
        answer = "Volunteer cheated!"
    elif len(intersect) > 1:
        answer = "Bad magician!"
    #print("arrangement 1: %s" %arr1 )
    #print("arrangement 2: %s" %arr2 )
    #print("Choice1: %s - %s" % (an1, possible1))
    #print("Choice2: %s - %s" % (an2, possible2))
    #print("=============")
    return answer

def solve(fd=None):
    if fd is None:
        fd = sys.stdin
    cases_count = int(fd.readline())
    solution = []
    for case_no in xrange(1, cases_count+1):
        first_answer = int(fd.readline())
        first_arrangement = read_arrangement(fd)
        second_answer = int(fd.readline())
        second_arrangement = read_arrangement(fd)
        answer = get_answer(first_answer, first_arrangement, second_answer, second_arrangement)
        
        solution.append("Case #%d: %s" % (case_no, answer))
    return '\n'.join(solution)

def main():
    if sys.argv[1:]:
        fn = sys.argv[1]
        with open(fn, 'r') as fd:
            res = solve(fd)
        print(res)
    else:
        test()
    

        
def test():
    import StringIO
    testcase="""3
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 5 4
3 11 6 15
9 10 7 12
13 14 8 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
"""
    ans = solve(StringIO.StringIO(testcase))
    expected_ans = """Case #1: 7
Case #2: Bad magician!
Case #3: Volunteer cheated!"""
    #print ans
    #print expected_ans
    assert ans == expected_ans
    print("Test ok") 

if __name__ == '__main__':
    main()