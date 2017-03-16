import java.util.Scanner;


public class Pr1B2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		int r, c, n, min, pol, in, roz;
		int p2, p3, p4;
		z: for(int t=1; t<=T; t++){
			r = s.nextInt();
			c = s.nextInt();
			n = s.nextInt();
			pol = (r*c)/2 + (r*c)%2;
			
			if(n<=pol){
				System.out.println("Case #"+t+": "+0);
				continue z;
			}
			
			in = r*(c-1) + c*(r-1);
			if(n == r*c){
				System.out.println("Case #"+t+": "+in);
				continue z;
			}
			
			
			
			if(r==1){
				roz = n-pol;
				if((c%2) == 1){
					min = roz*2;
					System.out.println("Case #"+t+": "+min);
					continue z;
				}
				else {
					min = roz*2 -1;
					System.out.println("Case #"+t+": "+min);
					continue z;
				}
			}
			
			if(c==1){
				roz = n-pol;
				if((r%2) == 1){
					min = roz*2;
					System.out.println("Case #"+t+": "+min);
					continue z;
				}
				else {
					min = roz*2 -1;
					System.out.println("Case #"+t+": "+min);
					continue z;
				}
			}
			
			if(r==2 || c==2){
				roz = n - pol;
				if(roz>2)	min = 4 + 3*(roz-2);
				else min = roz*2;
				System.out.println("Case #"+t+": "+min);
				continue z;
			}
			
			if(((r*c)%2)==0){
				roz = n-pol;
				p2 = 2;
				p3 = r-2 + c-2;
				p4 = ((r-2)*(c-2))/2;
				if(roz <=2){
					min = roz*2;
					System.out.println("Case #"+t+": "+min);
				}
				else{
					min = 4;
					roz = roz-2;
					if(roz <= p3){
						min +=3*roz;
						System.out.println("Case #"+t+": "+min);
					}
					else{
						min += p3*3;
						roz -= p3;
						min += 4*roz;
						System.out.println("Case #"+t+": "+min);
					}
				}
				continue z;
			}
			
			if(((r*c)%2)==1){
				int m1, m2;
				roz = n-pol;
				
				p2 = 0;
				p3 = ((r-2)/2 + (r-2)%2)*2 + ((c-2)/2 + (c-2)%2)*2;
				p4 = ((r-2)*(c-2))/2;
				if(roz <= p3)
					m1 = roz*3;
				else
					m1 = p3*3 + (roz-p3)*4;
				
				
				roz = n - pol + 1;
				p2 = 4;
				p3 = 2*((r-2)/2 + (c-2)/2);
				p4 = ((r-2)*(c-2))/2 + ((r-2)*(c-2))%2;
				if(roz <=4){
					m2 = 2*roz;
				}
				else{
					m2 = 2*4;
					roz -= 4;
					if(roz <=p3){
						m2 +=roz*3;
					}
					else{
						m2 += p3*3 + (roz-p3)*4;
					}
				}
				
				if(m1<m2){
					min = m1;
				}
				else{
					min = m2;
				}
				System.out.println("Case #"+t+": "+min);
					
				
			}
			
		}
	}

}
