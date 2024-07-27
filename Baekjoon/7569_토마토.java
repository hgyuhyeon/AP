import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Loc {
	int p;
	int n;
	int m;
	public Loc(int p, int n, int m) {
		this.p = p;
		this.n = n;
		this.m = m;
	}
}

public class Main {
	static int cnt;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken()), p = Integer.parseInt(st.nextToken());
		int[][][] arr = new int[p][n][m];
		cnt = 0;
		Queue<Loc> q = new ArrayDeque<Loc>();
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < n; j++) {
				st = new StringTokenizer(br.readLine());
				for (int k = 0; k < m; k++) {
					arr[i][j][k] = Integer.parseInt(st.nextToken());
					if (arr[i][j][k] == 1) q.offer(new Loc(i, j, k));
					if (arr[i][j][k] == 0) cnt++;
				}
			}
		}
		
		int ans = -1;
		int[] dr = {1,-1,0,0,0,0}, dc = {0,0,1,-1,0,0}, dh = {0,0,0,0,1,-1};
		while (!q.isEmpty()) {
			int size = q.size();
			while (size-- > 0) {
				Loc cur = q.poll();
				for (int i = 0; i < 6; i++) {
					int nr = cur.n + dr[i];
					int nc = cur.m + dc[i];
					int nh = cur.p + dh[i];
					if (nr >= 0 && nr < n && nc >=0 && nc < m && nh >= 0 && nh < p && arr[nh][nr][nc] == 0) {
						arr[nh][nr][nc] = 1;				
						cnt--;
						q.offer(new Loc(nh, nr, nc));
					}
				}
			}			
			ans++;
		}
		
		if (cnt > 0) System.out.println(-1);
		else System.out.println(ans);
	}
}
