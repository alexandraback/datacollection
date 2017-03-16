import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class B {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new  BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= t; i++) {
			int res = 0;
		
			int r,c,n;
			String[] next = in.readLine().split(" ");
			r = Integer.parseInt(next[0]);
			c = Integer.parseInt(next[1]);
			n = Integer.parseInt(next[2]);
			
			int boundary = r*c / 2 + (r*c) % 2;
			
			if (n <= boundary) res = 0;

			else if  (Math.min(r,c) == 1) {
				n -= boundary;
				int corners;
				
				if (r*c % 2 == 0) corners = 1;
				else corners = 0;
				
				while (n > 0 & corners > 0) {
					corners--;
					n--;
					res++;
				}
				
				res += n*2;
			} 
			
			else {
				res = 2*r*c - r - c;
				n = r*c - n;
				
				int copyres = res;
				int copyn = n;
				
				
				
				
				int center = (r-2)*(c-2) / 2;
				
				if (center >= copyn) copyres -= copyn*4;
				else {
					copyres -= center*4;
					copyn -= center;
					
					int corners, sides;
					if (r*c % 2 == 1) {
						corners = 0;
						sides = r + c - 2;
					}
					else {
						corners = 2;
						sides = r + c - 4;
					}
					
					while (sides > 0 & copyn > 0) {
						sides--;
						copyn--;
						copyres -= 3;
					}
					
					while (corners > 0 & copyn > 0) {
						corners--;
						copyn--;
						copyres -= 2;
					}
					
				}
				
				
				
				
				
				center = (r-2)*(c-2) / 2 + r*c % 2;
				
				if (center >= n) res -= n*4;
				else {
					res -= center*4;
					n -= center;
					
					int corners, sides;
					if (r*c % 2 == 1) {
						corners = 4;
						sides = r + c - 6;
					}
					else {
						corners = 2;
						sides = r + c -4;
					}
					
					while (sides > 0 & n > 0) {
						sides--;
						n--;
						res -= 3;
					}
					
					while (corners > 0 & n > 0) {
						corners--;
						n--;
						res -= 2;
					}
					
				}
				
				res = Math.min(res, copyres);
				
			}
			
			System.out.format("Case #%d: %d\n", i, res);
		}
	}

}
