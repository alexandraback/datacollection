package barbers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class MainBarbers {

	public static void main(String[] args) {

		FileInputStream file;
		int T;
		ArrayList<TestBarbers> tests;

		try {

//			file = new FileInputStream("input_Barbers");
//			file = new FileInputStream("B-small-attempt0.in");
			file = new FileInputStream("B-large.in");

			BufferedReader in = new BufferedReader(new InputStreamReader(file));


			String buff = in.readLine();
			T = Integer.parseInt(buff);
			tests = new ArrayList<TestBarbers>();

			for (int i=0; i<T; i++){

				int B, N;
				buff = in.readLine();
				String[] data = buff.split(" ");				
				B = Integer.parseInt(data[0]);
				N = Integer.parseInt(data[1]);
				
				int[] s = new int[B];
				buff = in.readLine();
				data = buff.split(" ");				
				for (int j=0; j<B; j++) {
					s[j] = Integer.parseInt(data[j]);
				}
				
				tests.add(new TestBarbers(B, N, s));
			}

			in.close();


			BufferedWriter bw = new BufferedWriter(new FileWriter("output_Barbers"));

			for (int i=0; i<T; i++) {
				int ind = i+1;
				int res = tests.get(i).getResult() +1;
				System.out.println("Result "+ i + " : "+ res);
				bw.write("Case #"+ind+": "+res+"\n");
			}
			bw.close();





		} catch (Exception e) {
			e.printStackTrace();
		}
	}	
}
