package commons;

public class Problem {
	int [] partyMembers;
	int totalMembers;
	int max, pos1, pos2;
	
	public Problem (int[] partyMembers, int totalMembers) {
		this.partyMembers = partyMembers;
		this.totalMembers = totalMembers;
		
	}
	

	public Result execute () {
		Result res = new Result();
		
		while (!end()) {
			searchMax();
			if (totalMembers == 3) {
				res.addSequence((char)(65 + pos1));
				partyMembers[pos1]--;
				totalMembers--;
			} else {
				if (pos2 != -1) {
					res.addSequence((char)(65 + pos1), (char)(65 + pos2));
					partyMembers[pos1]--;
					partyMembers[pos2]--;
					totalMembers -= 2;
				} else {
					res.addSequence((char)(65 + pos1));
					partyMembers[pos1]--;
					totalMembers--;
				}
			}
		}
		
		
		return res;
	}


	private boolean end() {
		boolean end = true;
		int pos = 0;
		while (end && pos < partyMembers.length) {
			if (partyMembers[pos] > 0) {
				end = false;
			}
			pos++;
		}
		
		return end;
	}


	private void searchMax() {
		max = Integer.MIN_VALUE;
		pos1 = -1;
		pos2 = -1;
		
		int i = 0;
		for (; i < partyMembers.length; i++) {
			if (partyMembers[i] > max) {
				max = partyMembers[i];
				pos1 = i;
			} else if (partyMembers[i] == max) {
				pos2 = i;
			}
		}
		
	}
}
