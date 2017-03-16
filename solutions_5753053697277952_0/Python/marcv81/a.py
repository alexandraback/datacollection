class Parties:

	def __init__(self, parties):
		self.parties = parties
		self.count = 0
		for i in xrange(len(self.parties)):
			self.count += self.parties[i]

	def find_largest(self):
		max_i = -1
		max_val = -1
		for i in xrange(len(self.parties)):
			if self.parties[i] > max_val:
				max_i = i
				max_val = self.parties[i]
		assert max_i != -1
		return max_i

	def next_step(self):
		party1 = self.find_largest()
		self.parties[party1] -= 1
		self.count -= 1
		if self.count != 2:
			party2 = self.find_largest()
			self.parties[party2] -= 1
			self.count -= 1
			return chr(ord('A') + party1) + chr(ord('A') + party2)
		else:
			return chr(ord('A') + party1)

	def build_plan(self):
		plan = []
		while self.count > 0:
			plan.append(self.next_step())
		return ' '.join(plan)

def evacuate(parties):
	party1 = find_max_party(parties)
	parties[party1] -= 1

with open('A-small-attempt0.in', 'r') as f:
	tc_len = int(f.readline().strip())
	for tc in xrange(1, tc_len + 1):
		_ = int(f.readline().strip())
		parties = Parties([int(i) for i in f.readline().strip().split()])
		print 'Case #' + str(tc) + ': ' + parties.build_plan()
