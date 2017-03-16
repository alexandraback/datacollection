#!/usr/bin/env python
# encoding: utf-8


def way1(samples):
    if len(samples) < 2:
        return 0

    min_pieces = 0
    last_pieces = samples[0]
    for s in samples[1:]:
        if s < last_pieces:
            min_pieces += last_pieces - s
        last_pieces = s
    return min_pieces


def way2(samples):
    if len(samples) < 2:
        return 0
    last_pieces = samples[0]
    max_eaten_pieces = 0
    for s in samples[1:]:
        if s < last_pieces:
            max_eaten_pieces = max(max_eaten_pieces, last_pieces - s)
        last_pieces = s

    min_pieces = 0
    last_pieces = samples[0]
    for s in samples[1:]:
        if s < last_pieces:
            min_pieces += min(max(max_eaten_pieces, last_pieces - s), last_pieces)
        else:
            min_pieces += min(max_eaten_pieces, last_pieces)
        last_pieces = s
    return min_pieces

def run(inputFile, outputFile):
    fp = open(inputFile, 'r')
    fw = open(outputFile, 'w')
    caseIndex = 0
    count = -1
    sampleCount = 0
    for line in fp:
        if (caseIndex == 0):
            count = int(line)
            caseIndex += 1
        elif sampleCount == 0:
            sampleCount = int(line)
        else:
            samples_strs = line.split(' ')
            samples = [int(s) for s in samples_strs]
            fw.write("Case #%d: %d %d\n" % (caseIndex, way1(samples), way2(samples)))
            caseIndex += 1
            count -= 1
            sampleCount = 0
        if (count == 0):
            break
    fp.close()
    fw.close()


if __name__ == "__main__":
    run("in", "out")
