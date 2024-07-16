import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int m = sc.nextInt(), n = sc.nextInt(), tc = sc.nextInt();
		int[][] arr = new int[tc+1][2];
		int[] road = new int[tc+1], dist = {0, 0, n+m, n+m*2, m};
		int total = 2 * (n + m);
		for (int t = 0; t < tc+1; t++) {
			arr[t][0] = sc.nextInt();
			arr[t][1] = sc.nextInt();
			if (arr[t][0] == 2) arr[t][1] = m - arr[t][1];
			else if (arr[t][0] == 3) arr[t][1] = n - arr[t][1];
			road[t] = dist[arr[t][0]] + arr[t][1];
		}
		
		int loc = road[tc], ans = 0;
		
		for (int i = 0; i < tc; i++) {
			ans += Math.min(Math.abs(road[i] - loc), (2*(n+m) - Math.max(loc, road[i])) + Math.min(loc, road[i]));
		}
		
		System.out.println(ans);
	}
}
