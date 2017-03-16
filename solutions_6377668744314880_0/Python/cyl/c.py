#!/usr/bin/env python
# encoding: utf-8

from contextlib import nested
#from scipy.spatial import ConvexHull

debug = True


def is_left(p0, p1, p2):
    return ((p1[0] - p0[0]) * (p2[1] - p0[1]) -
            (p2[0] - p0[0]) * (p1[1] - p0[1]))


def find(idx, coor):
    p0 = coor[idx]
    min_cut = len(coor)
    for i, p1 in enumerate(coor):
        left_idxs = []
        right_idxs = []
        remain_idxs = []
        #left_points = []
        #right_points = []
        #remain_points = []
        if i == idx:
            continue
        for j, p2 in enumerate(coor):
            if j == idx or j == i:
                continue
            is_left_pos = is_left(p0, p1, p2)
            if is_left_pos > 0:
                left_idxs.append(j)
                #left_points.append(p2)
            elif is_left_pos < 0:
                right_idxs.append(j)
                #right_points.append(p2)
            else:
                remain_idxs.append(j)
                #remain_points.append(p2)
        #points = remain_points + left_points
        #left_hull = ConvexHull(points)

        if len(left_idxs) < min_cut:
            min_cut = len(left_idxs)
        if len(right_idxs) < min_cut:
            min_cut = len(right_idxs)
    return min_cut


def solve(N, coor):
    ret = []
    for idx in range(len(coor)):
        ret.append(find(idx, coor))
    return ret

if __name__ == '__main__':
    finame = 'C-small-attempt2.in'
    foname = 'C-small-attempt2.out'
    #finame = 'C-large.in'
    #foname = 'C-large.out'
    #if debug:
        #finame = 'C-small.in'
        #foname = 'C-small.out'

    with nested(open(finame), open(foname, 'w')) as (fi, fo):
        num_case = int(fi.readline().strip())
        for case_id in range(1, num_case + 1):
            N = int(fi.readline().strip())
            coor = []
            for i in range(N):
                coor.append(map(int, fi.readline().strip().split(' ')))

            ret = solve(N, coor)

            output_str = 'Case #%d: \n%s' % (case_id, '\n'.join(map(str, ret)))
            print output_str
            fo.write(output_str + '\n')
