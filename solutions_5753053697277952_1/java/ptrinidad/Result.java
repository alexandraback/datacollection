package commons;

import java.util.LinkedList;
import java.util.List;

public class Result {
	List<String> sequence;
	
	public Result () {
		sequence = new LinkedList<String>();
	}
	
	public void addSequence(char first, char second) {
		sequence.add(String.valueOf(first) + String.valueOf(second));
		
	}
	
	public void addSequence(char first) {
		sequence.add(String.valueOf(first));
	}
	
	@Override
	public String toString() {
		String res = "";
		for (String evacuation: sequence) {
			res += " " + evacuation;
		}
		return res;
	}
}
