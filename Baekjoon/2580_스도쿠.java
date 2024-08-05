import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

class Pair {
	int x;
	int y;
	Pair (int x, int y) {
		this.x = x;
		this.y = y;
	}
}
public class Main {
	static String ans = "";
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int[][] v = new int[9][9];
        for (int i= 0; i < 9; i++) {
        	st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) v[i][j] = Integer.parseInt(st.nextToken());
        }

        List<Pair> zero = new ArrayList<Pair>();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int val = v[i][j];
                if (val == 0)zero.add(new Pair(i, j));
            }
        }
        
        search(v, zero, 0);
        System.out.println(ans);
	}
	
	static void search(int[][] v, List<Pair> zero, int idx) {
		System.out.println("cur idx: " + idx);
		for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(v[i][j]+  " ");
                
            }
            System.out.println();
            
        }
		if (!ans.equals("")) return;
		if (idx == zero.size()) {
			StringBuilder sb = new StringBuilder();
	        for (int i = 0; i < 9; i++) {
	            for (int j = 0; j < 9; j++) {
	                sb.append(v[i][j] + " ");
	            }
	            sb.append("\n");
	        }
	        ans = sb.toString();
		}
		else {
			boolean[] c = new boolean[10];
			for (int i = 0; i < 9; i++) {
				if (v[zero.get(idx).x][i] != 0) c[v[zero.get(idx).x][i]] = true; 
				if (v[i][zero.get(idx).y] != 0) c[v[i][zero.get(idx).y]] = true;
			}
			int xinit = zero.get(idx).x / 3 * 3, yinit = zero.get(idx).y / 3 * 3;
			System.out.println("init: " + xinit + " " + yinit);
			for (int i = xinit; i < xinit + 3; i++) {
				for (int j = yinit; j < yinit + 3; j++) {
					if (v[i][j] != 0) c[v[i][j]] = true;
				}
			}
			
			for (int i = 1; i <= 9; i++) {
				if (!c[i]) {
					v[zero.get(idx).x][zero.get(idx).y] = i;
					search(v, zero, idx+1);
				}
			}
		}
	}
}
