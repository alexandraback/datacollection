#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys

def magic_trick(path_to_conf):

    with open(path_to_conf) as f:
        content = f.readlines()
    n = int(content[0].replace("\n", ""))

    for i in range(0, n):
        first_choosen_row = int(content[1 + 10*i].replace("\n", ""))
        possible_values = []
        for j in content[2 + 10*i + first_choosen_row - 1].split(" "):
            possible_values.append(int(j.replace("\n", "")))
        second_choosen_row = int(content[6 + 10*i].replace("\n", ""))
        values = []
        for j in content[7 + 10*i + second_choosen_row - 1].split(" "):
            tmp = int(j.replace("\n", ""))
            if tmp in possible_values:
                values.append(tmp)
        if len(values) == 0:
            print("Case #" + str(i+1) + ": Volunteer cheated!")
        elif len(values) > 1:
            print("Case #" + str(i+1) + ": Bad magician!")
        else:
            print("Case #" + str(i+1) + ": " + str(values[0]))

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_config>")
    else:
        magic_trick(sys.argv[1])

