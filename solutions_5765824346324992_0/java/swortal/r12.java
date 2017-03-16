

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: WANG
 * Date: 4/17/15
 * Time: 5:49 PM
 * To change this template use File | Settings | File Templates.
 */
public class r12 {
    public static void main(String[] args) {
        try {

            Scanner input=new Scanner(new File("F:\\code\\googlecodejam2015\\out\\production\\googlecodejam2015\\codejam2015\\sampleinput"));
            PrintWriter output=new PrintWriter("F:\\code\\googlecodejam2015\\out\\production\\googlecodejam2015\\codejam2015\\out") ;
            int casenumber = input.nextInt();
            for(int i=0;i<casenumber;i++){
                int B = input.nextInt();
                Long N=input.nextLong();
                int[] mk= new int[B];
                double totalfraction = 0;
                for(int j=0;j<B;j++){
                   mk[j] =   input.nextInt();
                    totalfraction +=1.0/(double) mk[j];
                }
                long upper =(long) Math.ceil((double) N/ totalfraction ),
                lower =(long) Math.ceil((double) (N-B)/ totalfraction ) ;
                long curnum =0,mid=0;
                while(curnum!=N-1&&upper-lower>1){
                     mid = (upper+lower)/2;
                    curnum =0;
                    for(int j=0;j<B;j++){
                       curnum+=Math.ceil((double) mid/(double) mk[j]);
                    }
                    if(curnum>N-1){
                       upper  =mid;
                    } else {
                        lower = mid;
                    }

                }

                long mindiff = mid%mk[0];
                int mindiffindex = 0;
                if(curnum>=N){
                    for(int j=0;j<B;j++){
                        long tempmin =    mid%mk[j];
                        if(tempmin<mindiff){

                            mindiff=tempmin;
                        }
                    }
                    for(int j=B-1;j>=0;j--){
                        long tempmin =    mid%mk[j];
                        if(tempmin==mindiff){
                            if(curnum==N){
                                mindiffindex=j    ;
                                break;
                            }   else
                            curnum--;
                        }

                    }
                }   else {
                    for(int j=0;j<B;j++){
                        long tempmin =    mid%mk[j];
                        if(tempmin<mindiff){
                            mindiffindex = j;
                            mindiff=tempmin;
                        }
                    }
                }

                output.println("Case #"+(i+1)+": "+(mindiffindex+1));
                output.flush();
            }

        }catch(FileNotFoundException e){}

    }
}
