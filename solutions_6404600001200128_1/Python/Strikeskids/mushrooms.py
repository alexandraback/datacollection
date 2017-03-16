
def test():
    size = int(input())
    stamps = [int(x) for x in input().split(' ')]
    difs = [stamps[i]-stamps[i+1] for i in range(len(stamps)-1)]
    dropMax = max(difs)
    type1 = sum(filter(lambda x: x > 0, difs))
    type2 = sum(max(0, min(x, dropMax)) for x in stamps[:-1])
    return '%d %d'%(type1, type2)

def main():
    cases = int(input())
    for case in range(1, cases+1):
        print('Case #%d: %s'%(case, test()))

if __name__ == '__main__': main()
