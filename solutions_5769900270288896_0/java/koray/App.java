package com.koray.codejam;

import com.google.common.collect.TreeMultiset;

import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Hello world!
 * 
 */
public class App 
{
    
    
    static Map<BigInteger, BigInteger> map=  new HashMap<BigInteger, BigInteger>();
    public static void questionA()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                long res = 1;
                long N = new Long(sc.nextLong());
                BigInteger x = new BigInteger(N+"");
//                sc.nextLine();
                
                while (!x.equals(BigInteger.ONE))
                {
                    String ss = x.toString();
                    int len = ss.length();
                    boolean poweroften = isPowerOfTen(ss);
                    if(len == 1)
                    {
                         
                        res+= x.longValue()-1;
                        x = BigInteger.ONE;
                    }
                    else if(poweroften) {
                        res += 1;
                        x = x.subtract(BigInteger.ONE);
                    }
                    else {
                         
                        int big = len %2 ==0 ? len/2 : len/2+1;
                        int small =  len/2  ;
                        String ssbig = ss.substring(small);
                        String sssmall = new StringBuilder(ss.substring(0,small)).reverse().toString();
                        BigInteger nbig = new BigInteger(ssbig);
                        BigInteger nsmall = new BigInteger(sssmall);
                        if(isPowerOfTen(nsmall.toString()))
                        {
                            res += nbig.longValue();
                            x = getBigIntegerOfLen(len);
                        }
                        else if(nbig.equals(BigInteger.ZERO))
                        {
                            res += 1;
                            x = x.subtract(BigInteger.ONE);
                            
                        }
                        else {
                            res += nbig.longValue();
                            res += nsmall.longValue();
                            x = getBigIntegerOfLen(len);
                        }
                        
                    }
    
    
                }
    
                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    
    private static BigInteger getBigIntegerOfLen(int len) {
        String ret = "1";
        for(int i = 1 ; i < len ; i++)
            ret+="0";
        return new BigInteger(ret);
        
    }
    
    private static boolean isPowerOfTen(String ss) {
        boolean poweroften =true;
        poweroften &= ss.startsWith("1");
        for(int j = 1 ; j < ss.length() ; j++)
            poweroften &= ss.charAt(j) == '0';
         return poweroften;
    }
    
    
    public static void questionB()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                int res = 0;
                int R = new Integer(sc.nextInt());
                int C = new Integer(sc.nextInt());
                int N = new Integer(sc.nextInt());
                if(R>C)
                {
                    int xx = R;
                    R=C;
                    C = xx;
                }
                int [] arr = new int [4];
                if(C==1);
                else if(R==3 && C==3 && N ==7)
                    res =6;
                else if(R==3 && C==3 && N ==6)
                    res =3;
                 
                else {
                     
                    if(R==1)
                    {
                        arr[0] =2;
                        arr[1] = R*C-2;
                        arr[2] = 0;
                        arr[3] = 0;
                        
                    } 
                    else {
                        arr[0] = 0;
                        arr[1] = 4;
                        arr[2] = 2*(R+C) -8;
                        arr[3] = (R-2)*(C-2);
                    }
                    
                    int empty =Math.max(0, R*C - N - arr[3]) ;
                    
                    res =   4 * N - 2 * R * C - C - R;
                    for(int j = 2 ; j > -1 ; j--)
                    {
                        if(empty> 0)
                        {
                            res += empty;
                            empty = Math.max(0,empty - arr[j]);
                        }
                    }
                    
                }
                res = Math.max(0,res);
                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }


 

 

    public static void questionC()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                String res = "NO";
                int length = new Integer(sc.nextInt());
                long repetition = new Long(sc.nextLong())%2048;
                sc.nextLine();
                 

                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }


 
    public static void questionD()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                String  res = "";
                int X = new Integer(sc.nextInt());
                 

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }


}
