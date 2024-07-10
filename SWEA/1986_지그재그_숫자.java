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
            int num = sc.nextInt();
			System.out.print("#" + test_case + " ");
            if (num % 2 == 1) System.out.println(num / 2 * -1 + num);
            else System.out.println(num / 2 * -1);
		}
	}
}