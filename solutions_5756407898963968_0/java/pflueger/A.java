import java.io.IOException;
import java.util.*;

public class A extends CodeJammer {

	@Override
	public void process() throws IOException {
		int row1 = reader.readInt();
		int[] choice1 = null;
		for (int i=1; i<=4; i++) {
			int[] row = reader.readArray();
			if (i == row1) choice1 = row;
		}
		int row2 = reader.readInt();
		int[] choice2 = null;
		for (int i=1; i<=4; i++) {
			int[] row = reader.readArray();
			if (i==row2) choice2 = row;
		}
		Set<Integer> set1 = new HashSet<Integer>();
		for (int n : choice1) 
			set1.add(n);
		Set<Integer> set2 = new HashSet<Integer>();
		for (int n : choice2) 
			set2.add(n);
		set1.retainAll(set2);
		
		switch (set1.size()) {
		case 0: 
			output("Volunteer cheated!");
			break;
		case 1:
			output((Integer) set1.toArray()[0]);
			break;
		default:
			output("Bad Magician!");
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		A a = new A();
		a.run(args);
	}

}
