import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static char[][] map;
	static boolean[] v = new boolean[26];
	static int[] dr = {1,0,-1,0}, dc = {0,1,0,-1};
	static int N, M, ans = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		for (int t = 1; t <= tc; t++) {
			ans = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			map = new char[N][M];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				String str = st.nextToken();
				for (int j = 0; j < M; j++) map[i][j] = str.charAt(j);
			}
			
			v = new boolean[26];
			v[map[0][0] - 'A'] = true;
			dfs(0, 0, 1);
			
			System.out.println("#" + t + " " + ans);
		}
	}
	
	static void dfs(int r, int c, int cnt) {
		ans = Math.max(ans, cnt);
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr >= 0 && nr < N && nc >= 0 && nc < M && !v[map[nr][nc] - 'A']) {
				v[map[nr][nc] - 'A'] = true;
				dfs(nr, nc, cnt+1);
				v[map[nr][nc] - 'A'] = false;
			}
		}
	}
}
