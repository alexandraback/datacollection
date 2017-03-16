import java.io.FileInputStream;
import java.util.Scanner;

public class B {

	private static String process(Scanner in) {
		int R = in.nextInt();
		int C = in.nextInt();
		int N = in.nextInt();
		
		int r1 = (C+1)/2;
		int r2 = C/2;
		int c1 = (R+1)/2;
		int c2 = R - c1;
		int ok = r1*c1 + r2*c2;

		int remain = N - ok;
		
		if ( remain <= 0 )
			return "0";
		
		if ( Math.min(R, C) == 1 ) 
			return Integer.toString((N - ok) * 2);

		int corners = 0;
		int sides = 0;
		
		if ( C % 2 == 1 && R % 2 == 1 ) {
			corners = 0;
			sides = (C / 2 + R / 2) * 2;
		}
		else if ( C % 2 == 0 && R % 2 == 0 ) {
			corners = 2;
			sides = C + R - corners * 2;
		}
		else {
			corners = 2;
			sides = C + R - corners * 2;
		}

		int result = 0;

		if ( remain <= corners ) {
			result += remain * 2;
			return Integer.toString(result);
		}
		else {
			result += corners * 2;
			remain -= corners;
		}

		if ( remain > sides ) {
			result += sides * 3;
			remain -= sides;
			result += remain * 4;
		}
		else {
			//if ( R == 3 && C == 3 && N == 8 ) {
			int X = Math.max(R, C);
			if ( Math.min(R, C) == 3 && R*C - N <= (X-1) / 2 ) 
				result = ((R-1)*C + (C-1)*R) - (R*C - N) * 4;
			else
				result += remain * 3;
		}

		return Integer.toString(result);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
