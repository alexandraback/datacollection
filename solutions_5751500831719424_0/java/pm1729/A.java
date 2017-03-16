import java.util.Arrays;
import java.util.Scanner;
public class A {
    public static String common(String a)
    {
        String c_a="";
        for(int i=0;i<a.length();)
        {
            c_a+=a.charAt(i);
            int j;
            for( j=i+1;j<a.length() && a.charAt(i)==a.charAt(j);++j)
            {    
            }
            i=j;
        }
        return c_a;
    }
    public static boolean allSame(String a[])
    {
        String a0=a[0];
        for(String b : a)
        {
            if(!a0.equals(b))
            {
                return false;
            }
        }
        return true;
    }
    public static int distsfrommed(int arr[])
    {
        Arrays.sort(arr);
        int med=arr[arr.length/2];
        int ans=0;
        for(int i=0;i<arr.length;++i)
        {
            ans+=Math.abs(arr[i]-med);
        }    
        return ans;
    }
    public static int solve(String arr[],int n)
    {
        boolean t_i_p=false;
        String converted[]=new String[n];
        for(int i=0;i<n;++i)
        {
            converted[i]=common(arr[i]);
        }
        int ans=0;
        if(allSame(converted))
        {
            t_i_p=true;
            String a0=converted[0];
            int ind[]=new int[n];
            for(int i=0;i<a0.length();++i)
            {
                int occi[]=new int[n];
                for(int j=0;j<n;++j)
                {
                    while(ind[j]<arr[j].length() && arr[j].charAt(ind[j])==a0.charAt(i)){occi[j]++;ind[j]++;}
                }
                ans+=distsfrommed(occi);
            }
            return ans;
        }
    
        return -1;
    }
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        int t=s.nextInt();
        for(int i=1;i<=t;++i)
        {
            int n=s.nextInt();
            String arr[]=new String[n];
            for(int j=0;j<n;++j)
            {
                arr[j]=s.next();
            }
            int ans=solve(arr,n);
            System.out.print("Case #"+i+": ");
            if(ans==-1)
            {
                System.out.println("Fegla won");
            }
            else
            {
                System.out.println(ans);
            }
        }
    }
}

