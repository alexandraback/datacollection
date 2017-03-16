import java.io.*;
import java.util.*;

public class MathTest {
	//private DataInputStream in;
	private PrintWriter out;
	private Scanner in;
	
	MathTest() throws IOException {
		/*in = new DataInputStream(new
				BufferedInputStream(new FileInputStream(file+".in")));
		*/
		out = new PrintWriter(new FileWriter("output.txt"), true);		
	
		in = new Scanner(new File("input.txt"));
	}
	
	public void run() throws IOException {
		int a = in.nextInt();
		//out.writeInt(a);
		int[] timesAppear = new int[17];
		for(int i=0; i<17;i++) {
			timesAppear[i] = 0;
		}
		int temp;
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j< 4; j++) {
				temp = in.nextInt();
				if (i+1 == a) {
					timesAppear[temp]++;
				}
			}
		}
		a = in.nextInt();
		//out.writeInt(a);
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j< 4; j++) {
				temp = in.nextInt();
				if (i+1 == a) {
					timesAppear[temp]++;
				}
			}
		}	
		int what = 0;
		int num =0;
		for(int i = 1; i <= 16; i++) {
			if (timesAppear[i]==2) {
				num++;
				what = i;
			}
		}
		String Output="";
		if (num == 0)
			Output = "Volunteer cheated!";	
		else if (num == 1)
			Output = ""+what;
		else if (num >= 2)
			Output = "Bad magician!";
		else
			Output ="huh";
		out.println(Output);
		
	}
	
	public static void main(String[] args) throws IOException {

		MathTest m = new MathTest();

		int T = m.in.nextInt();
		for(int i=1; i<=T; i++) {
			m.out.print("Case #" + i + ": ");
			m.run();
		}
		return;
	}
}
