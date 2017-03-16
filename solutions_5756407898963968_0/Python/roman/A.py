#!/usr/bin/python2.7
import sys

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    for tc in range(n):
        candidates = []
        raw = int(sys.stdin.readline())
        for i in range(4):
            line = sys.stdin.readline()
            if i + 1 == raw:
                candidates.extend(line.split())
        raw = int(sys.stdin.readline())
        for i in range(4):
            line = sys.stdin.readline()
            if i + 1 == raw:
                candidates.extend(line.split())
        ans = ""
        cnt = dict()
        for c in candidates:
            if c in cnt:
                if ans != "":
                    ans = "Bad magician!"
                else:
                    ans = c
            cnt[c] = 1
        if ans == "":
            ans = "Volunteer cheated!"

        print "Case #" + str(tc + 1) + ": " + ans
