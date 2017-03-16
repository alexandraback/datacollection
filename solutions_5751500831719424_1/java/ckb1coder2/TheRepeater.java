import java.util.Scanner;

public class TheRepeater {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		int N;
		int i, j, k;
		boolean isPossible;
		String str[];
		int ans;
		int count[];
		int index[];
		char ch;
		boolean flag;
		int min, temp;

		for (k = 0; k < T; k++) {
			N = scanner.nextInt();
			str = new String[N];
			isPossible = true;
			flag = true;
			ans = 0;

			for (i = 0; i < N; i++) {
				str[i] = scanner.next();
			}

			index = new int[N];
			for (i = 0; i < N; i++) {
				index[i] = 0;
			}

			do {
				count = new int[N];
				if (index[0] >= str[0].length()) {
					flag = false;
					for(i=1;i<N;i++){
						if(index[i]<str[i].length()){
							isPossible=false;
							break;
						}
					}
				} else {
					ch = str[0].charAt(index[0]);
					for (i = 0; i < N; i++) {
						count[i] = 0;
						if (index[i] >= str[i].length()) {
							flag = false;
							isPossible = false;
							break;
						} else if (str[i].charAt(index[i]) != ch) {
							isPossible = false;
							flag = false;
							break;
						}
					}

					if (flag == true) {
						for (i = 0; i < N; i++) {
							while (index[i] < str[i].length()) {
								if (str[i].charAt(index[i]) == ch) {
									index[i]++;
									count[i]++;
								} else
									break;
							}
						}

						min = Integer.MAX_VALUE;
						for (i = 1; i <= 100; i++) {
							temp = 0;
							for (j = 0; j < N; j++) {
								temp += Math.abs(i - count[j]);
							}
							if (temp < min) {
								min = temp;
							}
						}
						ans += min;
					}
				}
			} while (flag);

			System.out.print("Case #" + (k + 1) + ": ");
			if (isPossible == false) {
				System.out.println("Fegla Won");
			} else {
				System.out.println("" + ans);
			}
		}
	}
}
