#!/usr/bin/python

import sys, math

def get_angle(a, b):
    (ax, ay) = a
    (bx, by) = b
    x = bx - ax
    y = by - ay
    rad = math.atan2(-y, x)
    return round(math.degrees(rad) + 360, 11) % 360

if __name__ == '__main__':
    total_count = int(sys.stdin.readline().strip())

    for case in range(total_count):
        tree_count = int(sys.stdin.readline().strip())

        trees = []
        for tree_index in range(tree_count):
            (x_str, y_str) = sys.stdin.readline().strip().split()
            trees.append((int(x_str), int(y_str)))

        print 'Case #%d:' % (case + 1)

        if len(trees) <= 3:
            for _ in trees:
                print '0'
            continue

        for tree in trees:
            other_trees = [t for t in trees if t != tree]
            if len(other_trees) <= 2:
                print '0'
                continue
            angles = [get_angle(tree, other) for other in other_trees]

            angles.sort()

            angle_count = len(angles)
            min_trees_to_cut = sys.maxint
            for _ in range(angle_count):
                #print angles
                for i in range(angle_count - 1):
                    angle_diff = angles[-1] - angles[i]
                    if angle_diff <= 180:
                        min_trees_to_cut = min(min_trees_to_cut, i)
                        break
                # shift
                #derpido = list(angles)
                first_angle = angles.pop(0) # always 360
                angles.append(360)
                #herpido = list(angles)
                first_angle = angles[0]
                if first_angle != 0.0:
                    angles = [round((a + 360 - first_angle) % 360, 11) for a in angles]
                #derp = list(angles)
                #angles.sort()
                #herp = list(angles)
                #if derp != herp:
                    #pass
                    #print 'WAT'
                    #print derpido
                    #print herpido
                    #print derp
                    #print herp
                    #if angles[0] != 0.0:
                        #break
                    #if counter > 500:
                        #print 'WAT'
                        ##print angles
                        #break
            print min_trees_to_cut
