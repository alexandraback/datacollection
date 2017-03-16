#!/usr/bin/python
import sys, os, copy


class TestCase:
  def __init__(self, strings):
    self.strings = strings
  def __repr__(self):
    return str(self.strings)

  def remove_repeats(self, string):
    new_str = ''
    for char in string:
      if len(new_str) > 0 and char == new_str[-1]:
        continue
      new_str += char
    return new_str

  
  def min_moves_for_letter(self, letter_freqs):
    letter_freqs.sort()
    num_moves = 0
    median  = letter_freqs[len(letter_freqs)/2]
    for letter_freq in letter_freqs:
      num_moves += abs(median - letter_freq)
    return num_moves

  def get_freq_list(self, string, nonrepeating_len):
    letter_list = [0]*nonrepeating_len
    prev_char = string[0]
    prev_ind = 0
    letter_ind = 0
    count = 1
    for i in range(1, len(string)):
      if prev_char != string[i]:
        letter_list[letter_ind] = count #i - prev_ind
        prev_ind = i
        prev_char = string[i]
        count = 1
        letter_ind += 1
      else:
        count +=1 
    letter_list[-1] = count
    return letter_list
    
  def result(self):
    # Fegla wins if the non-repeating strings are not the same
    nonrepeating_str = self.remove_repeats(self.strings[0])
    for string in self.strings[1:]:
      tmp_nonrepeating_str = self.remove_repeats(string)
      if tmp_nonrepeating_str != nonrepeating_str:
        return "Fegla Won"
    # Otherwise, compute min distance
    min_moves = 0  
    string_letter_freqs = []
    for string in self.strings:
      string_letter_freqs.append(self.get_freq_list(string, len(nonrepeating_str)))
    for i in range(len(nonrepeating_str)):
      letter_freqs = []
      for string_letter_freq in string_letter_freqs:
        letter_freqs.append(string_letter_freq[i])
      min_moves += self.min_moves_for_letter(letter_freqs)

    return str(min_moves)

def read_test_cases(input_filename):
  test_cases = []
  with open(input_filename) as input_file:
    lines = input_file.read().split("\n")
  num_test_cases = lines[0]
  i = 1
  while i < len(lines):
    if len(lines[i].replace(" ", '')) == 0:
      i += 1
      continue
    num_strings = int(lines[i])
    i += 1
    strings = []
    for j in range(i, i + num_strings):
      strings.append(lines[j])
    test_cases.append(TestCase(strings))
    i += num_strings

  return test_cases

def usage():
  print "Usage: problem_a.py input_file"

def main():
  if len(sys.argv) != 2:
    usage()
    sys.exit(1)

  input_filename = os.path.abspath(sys.argv[1])
  test_cases = read_test_cases(input_filename)

  for i, test_case in enumerate(test_cases):
    print "Case #%d: %s" % (i+1, test_case.result())

if __name__ == "__main__":
  main()
