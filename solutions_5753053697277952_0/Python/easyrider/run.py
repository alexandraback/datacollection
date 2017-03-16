#!/usr/bin/python3
import numpy

nr_of_tasks = int(input())

def p_name(ind):
    return chr(ind + ord('A'))

def find_index_of_max_value(_list):
    max_value = 0
    counter = -1
    for item in _list:
        counter = counter + 1
        if item > max_value:
            max_value = item + 0
            pos = counter + 0

    return p_name(pos), pos

def check_if_one_more(_list):
    name, pos = find_index_of_max_value(_list)
    total = sum(_list) - 1
    for ind, item in enumerate(_list):
        if item > int(total / 2) and ind is not pos:
            return None, None

    return name, pos




for task_index in range(1,nr_of_tasks+1):
    nr_of_parties = int(input())
    parties = [int(item) for item in input().split()]
    nr_of_parties_left = len(parties)
    nr_of_people = sum(parties)
    result = []
    while sum(parties) > 0:
        res = ""
        name1, pos1 = find_index_of_max_value(parties)
        parties[pos1] = parties[pos1] - 1
        res = name1
        name, pos = check_if_one_more(parties)
        if name is not None:
            parties[pos] = parties[pos] - 1
            res = "".join([name1, name])
        result.append(res)


    print("Case #{task}: {result}".format(task=task_index,
                             result=" ".join(result)))