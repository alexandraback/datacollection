def board_to_poss(row, board):
  return set(board[row - 1])

def parse_board():
  return [[int(card) for card in raw_input().split(" ")] for i in xrange(4)]

def solve():
  row1 = int(raw_input())
  board1 = parse_board()
  row2 = int(raw_input())
  board2 = parse_board()
  result = list(board_to_poss(row1, board1)
                & board_to_poss(row2, board2))
  if len(result) == 0:
    return "Volunteer cheated!"
  elif len(result) == 1:
    return str(result[0])
  else:
    return "Bad magician!"

if __name__ == "__main__":
  for i in xrange(int(raw_input())):
    print "Case #" + str(i + 1) + ": " + solve()
