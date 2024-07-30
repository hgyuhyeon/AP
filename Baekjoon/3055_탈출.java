import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Loc {
	int x;
	int y;
	
	Loc (int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		String [][] arr = new String[n][m];
		Queue<Loc> q = new ArrayDeque<>(), water = new ArrayDeque<>();
		
		
		if (n == 1 && m == 1) {
			System.out.println("KAKTUS");
		}
		
		for (int i = 0; i < n; i++) {
			String[] str = br.readLine().split("");
	        arr[i] = str;
	        for (int j = 0; j < m; j++) {
	        	if (arr[i][j].equals("S")) q.offer(new Loc(i, j));
	        	if (arr[i][j].equals("*")) water.offer(new Loc(i, j));
	        }
	    }
		
		int[] dr = {1,0,-1,0}, dc = {0,1,0,-1};
		int ans = 1;
		
		while (!q.isEmpty()) {
			int size = water.size();
			while (size-- > 0) {
				Loc cur = water.poll();
				for (int k = 0; k < 4; k++) {
        			int nr = cur.x + dr[k], nc = cur.y + dc[k];
        			if (nr >= 0 && nr < n && nc >= 0 && nc < m && arr[nr][nc].equals(".")) {
        				arr[nr][nc] = "*";
        				water.offer(new Loc(nr, nc));
        			}
        		}
			}
			
			size = q.size();
			while (size-- > 0) {
				Loc cur = q.poll();
				for (int k = 0; k < 4; k++) {
        			int nr = cur.x + dr[k], nc = cur.y + dc[k];
        			if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        				if (arr[nr][nc].equals("D")) {
        					System.out.print(ans);
        					return;
        				} else if (arr[nr][nc].equals(".")) {
        					arr[nr][nc] = "S";
        					q.offer(new Loc(nr, nc));
        				}
        			}
        		}
			}
			ans++;
		}
		System.out.print("KAKTUS");
	}
}
