
import com.sun.xml.internal.ws.api.pipe.NextAction;
import java.io.File;
import java.util.Formatter;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Mahmoud J00N
 */
public class template {
    public static void main(String []args){
        try{
            Scanner in = new Scanner(new File("aaaa.in"));
            Formatter out = new Formatter("out.txt");
            int numTestCase = in.nextInt();
            for(int kk=0;kk<numTestCase;kk++){
                int N = in.nextInt();
                in.nextLine();
                String strs[] = new String[N];
                for(int k=0;k<N;k++){
                    strs[k] = in.next();
                }
                char prevChar =' ';
                int totalMove = 0;
                while(true){
                    if(ends(strs)){
                        System.out.println(totalMove);
                        out.format("Case #"+(kk+1)+": %d\n", totalMove);
                        break;
                    }
                    if(!checkIfNot(strs))
                    {
                        out.format("Case #"+(kk+1)+": Fegla Won\n");
                        break;
                    }
                    prevChar = strs[0].charAt(0);
                    while(checkIfNot(strs)){
//                        System.out.println("delete " + prevChar);
                        prevChar = removeFirst(strs);
//                        break;
                    }
                    
                    int sameNextWithFirst = getSameNextWithFirst(strs, prevChar);
                    while(sameNextWithFirst>0){
//                        System.out.println("sameNextWithFirst" + sameNextWithFirst);
                        if(sameNextWithFirst>=(strs.length+1)/2){
                            totalMove+= strs.length- sameNextWithFirst;   
                        }
                        else{
                            totalMove+= sameNextWithFirst;
                        }
                        removeFirstSame(strs, prevChar);
                            
                        sameNextWithFirst = getSameNextWithFirst(strs, prevChar);
                    }
                }
            }
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }

    private static boolean checkIfNot(String[] strs) {
        if(strs[0].length()==0)return false;
        char f = strs[0].charAt(0);
        for(int i =1;i<strs.length;i++){
            if(strs[i].length()==0 || strs[i].charAt(0)!=f)
                return false;
        }
        return true;
    }

    private static char  removeFirst(String[] strs) {
            char ret = strs[0].charAt(0);
            for(int i =0;i<strs.length;i++){
                strs[i] = strs[i].substring(1);
            }
            return ret;
    }

    private static boolean ends(String[] strs) {
        for(int i =0;i<strs.length;i++){
            if(strs[i].length()!=0)
                return false;
        }
        return true;
    }

    private static int getSameNextWithFirst(String[] strs, char prevChar) {
        int ret = 0;
        for(int i =0;i<strs.length;i++){
            if(strs[i].length()>0 && strs[i].charAt(0)==prevChar)
                ret++;
        }
        return ret;
    }

    private static void removeFirstSame(String[] strs, char prevChar) {
        for(int i =0;i<strs.length;i++){
            if(strs[i].length()>0 && strs[i].charAt(0)==prevChar)
                strs[i] = strs[i].substring(1);
        }
    }

    private static boolean checkIfNot(String[] strs, char prevChar) {
        
        char f = prevChar;
        for(int i =0;i<strs.length;i++){
            if(strs[i].length()==0 || strs[i].charAt(0)!=f)
                return false;
        }
        return true;
    }
}
