import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.lang.Math;

public class Main
{
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st = new StringTokenizer(br.readLine());
	    int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
		int[] coins = new int[n], dp = new int[k+1];
		Arrays.fill(dp, 10001);
		for (int i = 0; i < n; i++) {
		    st = new StringTokenizer(br.readLine());
		    coins[i] = Integer.parseInt(st.nextToken());
		    if (coins[i] <= k) dp[coins[i]] = 1;
		}
		
		for (int i = 1; i <= k; i++) {
		    for (int j = 0; j < n; j++) {
		        if (i - coins[j] < 0) continue;
		        dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
		    }
		}
		
		if (dp[k] == 10001) System.out.println(-1);
		else System.out.println(dp[k]);
	}
}