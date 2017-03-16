import java.util.*;

public class A
{
    public static int no_test;
    public static int N, curN;
    public static int [][] cost;
    public static String canon_string;
    public static ArrayList<String> str_list;


    public static boolean make_canon(String S)
    {
        ArrayList<Character> cList = new ArrayList<Character>();
        ArrayList<Integer> iList = new ArrayList<Integer>();
        int curSeek = 0;
        int curI = 0;
        cList.add(S.charAt(0));
        for(int i=1; i<S.length(); i++)
        {
            if(S.charAt(curSeek)!=S.charAt(i))
            {
                cList.add(S.charAt(i));
                iList.add(curI);
                curI=0;
                curSeek=i;
            }
            else
                curI++;
        }
        iList.add(curI);
        StringBuffer sb = new StringBuffer();
        for(Character C: cList)
            sb.append(C);
        String test_string = sb.toString();
//        System.out.println(S+"->"+test_string);
        if(test_string.compareTo(canon_string)!=0)
            return false;

        for(int i=0; i<iList.size(); i++)
            cost[curN][i] = iList.get(i);
        return true;
    }
    public static void make_first(String S)
    {
        ArrayList<Character> cList = new ArrayList<Character>();
        ArrayList<Integer> iList = new ArrayList<Integer>();
        int curSeek = 0;
        int curI = 0;
        cList.add(S.charAt(0));
        for(int i=1; i<S.length(); i++)
        {
            if(S.charAt(curSeek)!=S.charAt(i))
            {
                cList.add(S.charAt(i));
                iList.add(curI);
                curI=0;
                curSeek=i;
            }
            else
                curI++;
        }
        iList.add(curI);

        StringBuffer sb = new StringBuffer();
        for(Character C: cList)
            sb.append(C);
        canon_string = sb.toString();
//        System.out.println(S+"->"+canon_string);
        cost = new int[N][cList.size()];
        for(int i=0; i<iList.size(); i++)
            cost[0][i] = iList.get(i);
            
    }

    public static int find_least(int [] arr )
    {
        Arrays.sort(arr);
        int med = arr.length/2;
//        System.out.println("med:"+med);
        int med_sum = 0;

        for(int i=0; i<arr.length; i++)
            med_sum+=Math.abs(arr[i]-arr[med]);
        int med0_sum = 0;
        for(int i=0; i<arr.length; i++)
            med0_sum+=Math.abs(arr[i]-arr[med-1]);
        if(arr.length%2==1)
            return med_sum;
        else 
            return Math.min(med_sum, med0_sum);
        
    }
    public static void main (String [] args)
    {
        Scanner sc = new Scanner(System.in);
        no_test = sc.nextInt();
        OUTER:
        for(int test=1; test<=no_test; test++)
        {
            canon_string = "";
            N = sc.nextInt(); sc.nextLine();
            curN=0;
            str_list = new ArrayList<String>();
            for(int n=0; n<N; n++)
                str_list.add(sc.nextLine());
            
 //           System.out.println(str_list);
            for(String S: str_list)
            {
                if(canon_string.length()==0)
                    make_first(S);
                else
                    if(!make_canon(S))
                    {
                        System.out.printf("Case #%d: Fegla Won\n", test);
                        continue OUTER;
                    }
                curN++;
            }
/*
            System.out.println(canon_string);
            for(int i=0; i<cost.length; i++)
                System.out.println(Arrays.toString(cost[i]));*/
            int tot=0;
            for(int i=0; i<cost[0].length; i++)
            {
                int [] temp = new int [N];
                for(int j=0; j<N; j++)
                    temp[j] = cost[j][i];
                int cur = find_least(temp);
                tot+=cur;
//                System.out.println(Arrays.toString(temp)+":"+cur);

            }

    
            System.out.printf("Case #%d: %d\n",test, tot);
        }
    }
}
