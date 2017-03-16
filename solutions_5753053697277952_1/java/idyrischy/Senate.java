import java.util.*;
import java.io.*;
public class Senate {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter("prob1l.out");
		
		int a = sc.nextInt();
		
		for (int i = 0; i < a; i++) {
			int num = sc.nextInt();
			
			int[] senators = new int[num];
			
			for (int j = 0; j < num; j++) {
				senators[j] = sc.nextInt();
			}
			
			System.out.println(Arrays.toString(senators));
			
			boolean az = false;
			String s = "";
			
			while(!az) {
				int highest = 0;
				int second = 0;
				
				int hid = -1;
				int sid = -1;
				for (int j = 0; j < senators.length; j++) {
					if (senators[j] >= highest) {
						sid = hid;
						second = highest;
						
						hid = j;
						highest = senators[j];

					} else if (senators[j] >= second) {
						sid = j;
						second = senators[j];
					}
					
					
				}
				//System.out.println(Arrays.toString(senators));
				//System.out.println(hid + " " + highest + " " + sid + " " + second);
				if (can_remove(hid, sid, senators)) {
					senators[hid]--;
					senators[sid]--;
					
					s += "" + (char) ('A' + hid) + (char) ('A' + sid) + " ";
				} else if (can_remove(hid, -1, senators)) {
					senators[hid]--;
					
					s += "" + (char) ('A' + hid) + " ";
				} else if (can_remove(sid, -1, senators)) {
					senators[sid]--;
					
					s += "" + (char) ('A' + sid) + " ";
				} else if (can_remove(hid, hid, senators)) {
					senators[hid] -= 2;
					
					s += "" + (char) ('A' + hid) + (char) ('A' + hid) + " ";
				} else {
					System.out.println(hid + " " + highest + " " + sid + " " + second);
					az = true;
				}
				
			}
			
			out.printf("Case #%d: %s%n", i + 1, s.trim());
		}
		
		out.close();

	}
	
	public static boolean can_remove(int id1, int id2, int[] numbers) {
		int[] clone = numbers.clone();
		
		clone[id1]--;
		if (id2 != -1)
			clone[id2]--;
		
		int sum = 0;
		
		for (int i: clone) {
			if (i < 0) {
				return false;
			}
		}
		
		for (int i: clone) {
			sum += i;
		}
		
		for (int i: clone) {
			if (sum < i * 2 && i != 0) {
				return false;
			}
		}
		
		return true;
	}

}
