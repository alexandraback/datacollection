import os
problem = '.'.join(os.path.basename(__file__).split('.')[:-1])
  
def main():
  inf = open(get_input_file())
  outf = open(problem + '.out', 'w')
  num_cases = int(inf.readline())
  problem_output = []
  for case_num in range(1, num_cases + 1):
    result = ''
    # per case stuff goes here
    # if only setting one variable, remember the comma after the variable name
    string_count = int(inf.readline())
    lines = []
    first_pattern = []
    result = ''
    for unused_i in range(string_count):
      line = inf.readline().strip()
      last_char = ''
      count = 0
      this_line = []
      char_pattern = []
      for char in line:
        if char != last_char:
          if last_char:
            this_line.append(count)
            char_pattern.append(last_char)
            count = 0
          last_char = char
        count += 1
      this_line.append(count)
      char_pattern.append(last_char)
      if len(first_pattern) == 0:
        first_pattern.extend(char_pattern)
      if first_pattern != char_pattern:
        result = 'Fegla Won'
        break
      lines.append(this_line)
    print lines
    if not result:
      cost = 0
      for i in range(len(first_pattern)):
        counts = []
        for j in range(len(lines)):
          counts.append(lines[j][i])
        counts.sort()
        median_index = len(lines) / 2
        median = counts[median_index]
        for j in range(len(lines)):
          if j < median_index:
            cost += median - counts[j]
          elif j > median_index:
            cost += counts[j] - median
      result = str(cost)
    # end per-case stuff
    problem_output.append('Case #' + str(case_num) + ': ' + result)
  outf.write('\n'.join(problem_output))
  print '\n'.join(problem_output)
  outf.close()
  inf.close()

def get_input_file():
  download_dir = os.path.expanduser('~/Downloads')
  last_updated = 0
  newest = ''
  example = '../examples/' + problem + '.exin'
  if os.path.exists(example):
    last_updated = os.path.getmtime(example)
  for fname in os.listdir(download_dir):
    if (fname.endswith('.in') and 
        fname.startswith(problem) and 
        os.path.getmtime(download_dir + '/' + fname) > last_updated):
      newest = fname
      last_updated = os.path.getmtime(download_dir + '/' + fname)
  if newest == '':
    return example
  else:
    return download_dir + '/' + newest

def fetch_spaced_types(inf, typ=int):
  return map(typ, inf.readline().strip().split(' '))

if __name__ == '__main__':
  main()
