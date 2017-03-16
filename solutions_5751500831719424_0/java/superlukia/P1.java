package gcj2014.r1b;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



import gcj2013.round2.*;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author scbit
 */
public class P1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new P1().run();
    }
    PrintWriter pw;

    void run() throws Exception{
        File infile=new File("A-small-attempt3.in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int T=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        Scanner sc=new Scanner(infile);
        T=sc.nextInt();

        for(int case_i=1;case_i<=T;case_i++) {
            if(case_i==99){
                int a=0;
            }
            int result = 0;
            int N=sc.nextInt();
            String[] ss=new String[N];
            for(int i=0;i<N;i++){
                ss[i]=sc.next();
            }
            List<Character> cs=new ArrayList<Character>();
            char thisc=' ';
            for(char c:ss[0].toCharArray()){
                if(thisc==c){
                    
                }else{
                    cs.add(c);
                    thisc=c;
                }
            }
            int[][] nums=new int[N][cs.size()];
            boolean b=true;
all:          for(int i=0;i<N;i++){
                int cspos=0;
                for(char c:ss[i].toCharArray()){
                    if(c==cs.get(cspos)){
                        nums[i][cspos]++;
                    }else if(cspos<(cs.size()-1) && c==cs.get(cspos+1) && nums[i][cspos]!=0){
                        cspos++;
                        nums[i][cspos]++;
                    }else{
                        b=false;
                        break all;
                    }
                }
            }
            for(int i=0;i<N;i++){
                for(int j=0;j<cs.size();j++){
                    if(nums[i][j]==0) b=false;
                }
            }
            if(b){
                for(int cspos=0;cspos<cs.size();cspos++){
                    List<Integer> tmp=new ArrayList<Integer>();
                    for(int i=0;i<N;i++){
                        tmp.add(nums[i][cspos]);
                    }
                    int top=1;
                    int bot=1;
                    Collections.sort(tmp);
                    while(true){
                        if(tmp.get(0)==tmp.get(tmp.size()-1)) break;
                        if((top+bot)==tmp.size()){
                            int offset=tmp.get(tmp.size()-1)-tmp.get(0);
                            result+=top*offset;
                            break;
                        }
                        result+=(tmp.get(1)-tmp.get(0))*top;
                        tmp.remove(0);
                        top++;
                        result+=(tmp.get(tmp.size()-1)-tmp.get(tmp.size()-2))*bot;
                        tmp.remove(tmp.size()-1);
                        bot++;
                        
                    }
                }
//                for(int cspos=0;cspos<cs.size();cspos++){
//                    result+= Math.abs(nums[0][cspos]-nums[1][cspos]);
//                }
            }
            if(b){
                String outputstr=String.format("Case #%d: %s\n", case_i,result);
            pw.printf(outputstr);
            System.out.printf(outputstr);
            }else{
                String outputstr=String.format("Case #%d: Fegla Won\n", case_i);
            pw.printf(outputstr);
            System.out.printf(outputstr);
            }
            
        }
        pw.close();
    }

}
class data implements Comparable<data> {
    int num;
    int times;

    public data(int num, int times) {
        this.num = num;
        this.times = times;
    }

    @Override
    public int compareTo(data o) {
        return num-o.num;
    }
    
}