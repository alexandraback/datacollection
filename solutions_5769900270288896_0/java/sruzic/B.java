import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();

		for (int t = 1; t <= T; t++) {

			int R = in.nextInt();
			int C = in.nextInt();
			int N = in.nextInt();

			System.out.format("Case #%d: %d\n", t, solve(R, C, N));
		}

		in.close();
	}

	private static int solve(int r, int c, int n) {
		if (r > c)
			return solve(c, r, n);
		// r <= c
		if (n <= 1)
			return 0;
		if (n <= (r * c + 1) / 2)
			return 0;
		int base = r * (c - 1) + (r - 1) * c;
		int free = r * c - n;

		if (free == 0) {
			return base;
		}

		switch (r) {
		case 1:
			return base - (c - n) * 2;
		case 2:
			base -= Math.min(c - 2, free) * 3;
			if (free == c-1 ) base -= 2;
			if (free == c) base -=4;
			return base;
		case 3:
			if (c == 3) {
				if (free == 1)
					return base - 4;
				if (free == 2)
					return base - 6;
				// if (free == 3)
				return base - 9;
			} else if (c == 4) {
				switch (free) {
				case 1:
					return base - 4;
				case 2: 
					return base - 7;
				case 3:
					return base - 10;
				case 4:
					return base - 13;
				case 5:
					return base - 15;
				}
			} else if (c == 5) {
				switch (free) {
				case 1:
					return base - 4;
				case 2: 
					return base - 8;
				case 3:
					return base - 11;
				case 4:
					return base - 14;
				case 5:
					return base - 16;
				case 6:
					return base - 19;
				case 7:
					return base - 21;
				}
				
			}

		case 4:
			switch (free) {
			case 1:
				return base - 4;
			case 2: 
				return base - 8;
			case 3:
				return base - 11;
			case 4:
				return base - 14;
			case 5:
				return base - 17;
			case 6:
				return base - 20;
			case 7:
				return base - 22;
			}
		default:
			break;
		}

		return 0;
	}

}
