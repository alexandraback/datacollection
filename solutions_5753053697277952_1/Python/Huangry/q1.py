import heapq
alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

with open ('A-large (9).in', 'r') as f:
    with open ('q1solution.txt', 'w') as solution:
        t = int(f.readline())
        for case in range(t):
            N = int(f.readline())
            p = [int(x) for x in f.readline().split()]
            total = sum(p)
            answer = ''
            heap = []
            for i in range(len(p)):
                heapq.heappush(heap, (-p[i], i))

            while len(heap) > 0:
                first = heapq.heappop(heap)
                if total == 3:
                    answer += alphabet[first[1]] + ' '
                    total -= 1
                    if first[0] + 1 < 0:
                        heapq.heappush(heap, ((first[0]) + 1, first[1]))
                elif heap[0][0] < first[0] and first[0] < -1:
                    answer += alphabet[first[1]] * 2 + ' '
                    total -= 2
                    if first[0] + 2 < 0:
                        heapq.heappush(heap, ((first[0]) + 2, first[1]))
                else:
                    second = heapq.heappop(heap)
                    answer += alphabet[first[1]] + alphabet[second[1]] + ' '
                    total -= 2
                    if first[0] + 1 < 0:
                        heapq.heappush(heap, (first[0] + 1, first[1]))
                    if second[0] + 1 < 0:
                        heapq.heappush(heap, (second[0] + 1, second[1]))

            solution.write('Case #' + str(case+1) + ': ' + answer + '\n')

        solution.closed
    f.closed