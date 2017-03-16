import heapq
def barber(n,times):
    if n==1:
        return 1
    barber_nextfreetime=[]
    free_barbers=range(len(times),0,-1)

    cur_time=0
    for i in xrange(n-1):
        if not free_barbers:
            cur_time, _ =barber_nextfreetime[0] # heap top
            while barber_nextfreetime and barber_nextfreetime[0][0]==cur_time:
                _, k=heapq.heappop(barber_nextfreetime)
                free_barbers.append(k)
            free_barbers.sort(reverse=True)

        k=free_barbers.pop()
        heapq.heappush(barber_nextfreetime,(cur_time+times[k-1],k))


    if not free_barbers:
        cur_time, _ =barber_nextfreetime[0] # heap top
        while barber_nextfreetime and barber_nextfreetime[0][0]==cur_time:
            _, k=heapq.heappop(barber_nextfreetime)
            free_barbers.append(k)
        free_barbers.sort(reverse=True)

    return free_barbers.pop()

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def lcm(a,b):
    return a*b/gcd(a,b)


def list_lcm(numbers):

    if len(numbers)==1:
        return numbers[0]
    ret=numbers[0]
    for num in numbers[1:]:
        ret=lcm(ret,num)
    return ret


def term(numbers):
    x=list_lcm(numbers)
    t=0
    for num in numbers:
        t+=x/num
    return t

input_file='B-small-attempt1.in'
output_file='B-small-attempt1.out'
with open(input_file) as input:
    with open(output_file,'w') as output:
        cases=int(input.readline().strip())
        for i in xrange(cases):
            line=input.readline().strip().split()
            n=int(line[1])
            line=input.readline().strip().split()
            b=[int(time) for time in line]
            n=((n-1) % term(b))+1
            k=barber(n,b)
            print >>output, 'Case #%s: %s'%(str(i+1),str(k))
