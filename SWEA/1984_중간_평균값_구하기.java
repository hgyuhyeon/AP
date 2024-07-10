import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			System.out.print("#" + test_case + " ");
            int max_v = 0, min_v = Integer.MAX_VALUE, sum = 0;
            for (int i =0; i < 10; i++) {
            	int num = sc.nextInt();
                sum += num;
                max_v = Math.max(max_v, num);
                min_v = Math.min(min_v, num);
            }
            sum -= (max_v + min_v);
            int ans = sum / 8 + (sum % 8 >= 4 ? 1 : 0);
            System.out.println(ans);
		}
	}
}