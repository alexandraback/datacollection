import string
from Queue import PriorityQueue as pq

inputFile = open('senators.in', 'r')
inputData = inputFile.read().strip()

numCases  = int(inputData.split('\n')[0])
caseData  = inputData.split('\n')

def formatAnswer(index, answer):
  return "Case #" + str(index) + ": " + str(answer)

def removeOneSenator(senatorQueue):
  [numMembers, groupName] = senatorQueue.get()
  if numMembers < -1:
    senatorQueue.put( (numMembers + 1, groupName))
  return groupName


def computeAnswer(senatorCounts):
  senatorQueue = pq()
  answer       = ""

  # put all senators on the queue, then pop off the largest size.
  # put them on the queue by the negative size since python pqueues are mins
  for index in xrange(len(senatorCounts)):
    senatorQueue.put( (-1 * senatorCounts[index], chr(index + 65)))

  numSenatorsLeft = sum(senatorCounts)
  while numSenatorsLeft > 0:
    firstSenator = removeOneSenator(senatorQueue)
    if numSenatorsLeft != 3:
      secondSenator    = removeOneSenator(senatorQueue)
      exitString       = firstSenator + secondSenator
      numSenatorsLeft -= 2
    else:
      exitString       = firstSenator
      numSenatorsLeft -= 1
    answer            += " " + exitString

  return answer.strip()

for case in xrange(1, numCases+1):
  numParties    = caseData[case*2-1]
  senatorCounts = [int(x) for x in string.split(caseData[case*2])]

  answer        = computeAnswer(senatorCounts)
  print formatAnswer(case, answer)

