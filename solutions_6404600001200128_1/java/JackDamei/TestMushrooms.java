package mushrooms;

public class TestMushrooms {
	
	private int res1;
	private int res2;

	public TestMushrooms(int N, int[] s) {
		res1 = 0;
		res2 = 0;
		int tmp;
		int biggest = 0;
		
		for (int i=1; i<N; i++) {
			if ((tmp = s[i-1]-s[i]) > 0) {
				res1 += tmp;
			}
			if (tmp > biggest) {
				biggest = tmp;
			}
		}
		System.out.println(biggest);
		for (int i=1; i<N; i++) {
			res2 += Math.min(biggest, s[i-1]);
		}		
	}

	public int getRes1() {
		return res1;
	}

	public int getRes2() {
		return res2;
	}	
	
}