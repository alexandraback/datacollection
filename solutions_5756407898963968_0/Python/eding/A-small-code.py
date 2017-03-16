import codecs
import sys

N_ROWS = 4

def main():
    file = codecs.open(sys.argv[1], "r", "utf-8-sig")
    lines = [line.strip() for line in file]

    T = int(lines[0])

    cards1 = []
    cards2 = []

    index = 1
    for trial in xrange(0,T):
        ans1 = int(lines[index])
        
        cards1 = map(int, lines[index+ans1].split())
        index += 5
       
        ans2 = int(lines[index])
        
        cards2 = map(int, lines[index+ans2].split())
        index += 5
        
        intersect = [card for card in cards1 if card in cards2]
        sys.stdout.write("Case #%d: " % (trial+1))
        if len(intersect) < 1:
            sys.stdout.write("Volunteer cheated!\n")
        elif len(intersect) == 1:
            sys.stdout.write("%d\n" % intersect[0])
        elif len(intersect) > 1:
            sys.stdout.write("Bad magician!\n")

if __name__ == '__main__':
    main()
