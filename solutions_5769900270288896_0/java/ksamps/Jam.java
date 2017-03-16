import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;


public class Jam {

	public static void main(String[] args) throws IOException{
		FileReader in = new FileReader("src/B-small-attempt2.in");
		BufferedReader br = new BufferedReader(in);
		int T = Integer.parseInt(br.readLine());
				 
		File file = new File("src/output.txt");

		FileWriter fw = new FileWriter(file.getAbsoluteFile());
		BufferedWriter bw = new BufferedWriter(fw);		
		for(int i = 0; i < T; i++){
			String[] nums = br.readLine().split(" ");
			int R = Integer.parseInt(nums[0]);
			int C = Integer.parseInt(nums[1]);
			int N = Integer.parseInt(nums[2]);
			int total = (R*C*2) + (R-1)*C + (C-1)*R;
			int borders = (R*C*2);
			int mids = Math.max((R-2)*(C-2),0);
			int rest = total - mids;
			int diff = (R*C)-N;
			
			if(N <= (R*C+1)/2){
				bw.write("Case #" + Integer.toString(i+1)+": "+ Integer.toString(0));
				bw.newLine();
			}
			else if(N == R*C){
				bw.write("Case #" + Integer.toString(i+1)+": "+ Integer.toString(total - borders));
				bw.newLine();
			}
			else if(R == 3 && C ==3 && N==6){
					bw.write("Case #" + Integer.toString(i+1)+": "+ Integer.toString(4));
					bw.newLine();
			}
			else if(R == 3 && C ==3 && N==7){
				bw.write("Case #" + Integer.toString(i+1)+": "+ Integer.toString(6));
				bw.newLine();
			}
			else if(C == 1 || R == 1){
				bw.write("Case #" + Integer.toString(i+1)+": "+ Integer.toString(total - borders - 2*diff));
				bw.newLine();
			}
			else if(C == 2 || R == 2){
				int saved = 3*(N-(C*R/2));
				if(N == (R*C/2)+1){
					saved = saved - 1;
				}
				bw.write("Case #" + Integer.toString(i+1)+": "+ Integer.toString(total - borders - saved));
				bw.newLine();
			}
			else{
				int saved = 0 ;
				int middles = Math.min(diff,(mids+1)/2);
				saved = middles * 4;
				if(diff - (mids+1)/2 <= 0){
					bw.write("Case #" + Integer.toString(i+1)+": "+ Integer.toString(total - borders - saved));
					bw.newLine();

				}
				else{
					diff = diff - (mids+1)/2;
					saved = saved + (diff*3);
					if((R*C)%2==0 && N == (R*C/2)+1){
						saved = saved - 1;
					}
					if((R*C)%2==1){
						if(N == ((R*C+1)/2) ){
							saved = saved - 3;
						}
						if(N == ((R*C+1)/2) + 1){
							saved = saved - 2;
						}
						if(N == ((R*C+1)/2) + 2){
							saved = saved - 1;
						}
					}
					bw.write("Case #" + Integer.toString(i+1)+": "+ Integer.toString(total - borders - saved));
					bw.newLine();
				}
			}
		}
		in.close();
		bw.close();
	}
}
