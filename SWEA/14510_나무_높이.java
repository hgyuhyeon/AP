import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine()), ans, maxTree;
		for (int t = 1; t <= tc; t++) {
			ans = 0;
			maxTree = 0;
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] trees = new int[n];
			for (int i = 0; i < trees.length; i++) {
				trees[i] = Integer.parseInt(st.nextToken());
				maxTree = Math.max(maxTree, trees[i]);
			}
			
			int one = 0, two = 0;
			for (int i = 0; i < trees.length; i++) {
				int diff = maxTree - trees[i];
				one += (diff % 2);
				two += (diff / 2);
			}
			
			int min_v = Math.min(one, two);
			ans += min_v * 2;
			one -= min_v;
			two -= min_v;
			
			if (one > 0) ans += (one * 2 > 0 ? one * 2 - 1 : 0);
			else if (two > 0) ans += ((two - 1) / 3 * 4 + (two % 3 == 0 ? 3 : two % 3) + 1);
						
			System.out.println("#" + t + " " + ans);
		}
	}
}
