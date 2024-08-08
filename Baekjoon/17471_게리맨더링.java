import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

class Graph {
	int val;
	ArrayList<Integer> next;
}

public class Main {
	private static int n, sum = 0, ans = Integer.MAX_VALUE;
	private static Graph[] g;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		g = new Graph[n+1];
		for (int i = 0; i <= n; i++) {
			g[i] = new Graph();
			g[i].next = new ArrayList<Integer>();
		}
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			g[i].val = Integer.parseInt(st.nextToken());
			sum += g[i].val;
		}
		for (int i = 1; i <= n; i++) {
			String[] str = br.readLine().split(" ");
			for (int j = 1; j < str.length; j++) {
				int node = Integer.parseInt(str[j]);
				g[i].next.add(node);
				g[node].next.add(i);
			}
		}
		subset(1, new ArrayList<Integer>());
		if (ans == Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(ans);
	}
	
	public static void subset(int idx, ArrayList<Integer> sel) {
		if (idx > n) {
			int p = 0;
			for (int i: sel) p += g[i].val;
			if (Math.abs(sum - p - p) < ans && check(sel)) ans = Math.abs(sum - p - p);
			return;
		}
		sel.add(idx);
		subset(idx+1, sel);
		sel.remove(sel.indexOf(idx));
		subset(idx+1, sel);
	}
	
	private static boolean check(ArrayList<Integer> sel) {
		if (sel.size() == 0 || sel.size() == n) return false;
		boolean[] v = new boolean[n+1];
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.offer(sel.get(0));
		v[sel.get(0)] = true;
		int cnt = 1;
		while (!q.isEmpty()) {
			Graph cur = g[q.poll()];
			for (int ne: cur.next) {
				if (sel.contains(ne) && !v[ne]) {
					v[ne] = true;
					cnt++;
					q.offer(ne);
				}
			}
		}
		if (cnt != sel.size()) return false;
		for (int i = 1; i <= n; i++) {
			if (!v[i]) {
				q.offer(i);
				v[i] = true;
				cnt++;
				while (!q.isEmpty()) {
					Graph cur = g[q.poll()];
					for (int ne: cur.next) {
						if (!v[ne]) {
							v[ne] = true;
							cnt++;
							q.offer(ne);
						}
					}
				}
				break;
			}
		}
		return cnt == n ? true : false;
	}
}
