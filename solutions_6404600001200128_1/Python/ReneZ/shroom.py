from util import *

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in range(num):
        maxtime = int(r.next())
        shrooms = map(int, r.next().split(" "))

        cur = 0
        sumShrooms = 0
        maxDiff = 0
        for shroom in shrooms:
            if shroom < cur:
                diff = cur - shroom
                if diff > maxDiff:
                    maxDiff = diff
                sumShrooms += diff
            cur = shroom

        sumShroomsRate = 0
        for shroom in shrooms[:-1]:
            sumShroomsRate += min(maxDiff, shroom)

        ans.append("%s %s" % (sumShrooms, sumShroomsRate))

    write("output", ans)

if __name__ == '__main__':
    main()
