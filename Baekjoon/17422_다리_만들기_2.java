package Baekjoon.b_17422;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;

public class Main {
	static int n, m;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str[] = br.readLine().split(" ");
		n = Integer.parseInt(str[0]);
		m = Integer.parseInt(str[1]);
		int[][] map = new int[n][m];
		for (int i = 0; i < n; i++) {
			str = br.readLine().split(" ");
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(str[j]);
			}
		}
		
		boolean[][] v = new boolean[n][m];
		int cnt = 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					v[i][j] = true;
					map[i][j] = cnt;
					dfs(map, v, i, j, cnt); // 각 섬을 숫자로 나누기
					cnt++;
				}
			}
		}
		
		int[][] g = new int[cnt][cnt];
		for (int i = 2; i < cnt; i++) {
			for (int j = 2; j < cnt; j++) {
				if (i == j) continue;
				g[i][j] = 100;
			}
		}
		
		v = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0) {
					v[i][j] = true;
					dfs2(map, v, g, i, j, map[i][j]); // 각 섬별로 거리 측정하기
				}
			}
		}
		
		int ans = check(g, 2, cnt-2);
		System.out.println(ans); 
	}

	private static int[] dr = {1, -1, 0, 0}, dc = {0,0, 1, -1};
	private static void dfs(int[][] map, boolean[][] v, int i, int j, int cnt) {
		for (int d = 0; d < 4; d++) {
			int nr = i + dr[d], nc = j + dc[d];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && !v[nr][nc] && map[nr][nc] != 0) {
				v[nr][nc] = true;
				map[nr][nc] = cnt;
				dfs(map, v, nr, nc, cnt);
			}
		}
	}
	

	private static void dfs2(int[][] map, boolean[][] v, int[][] g, int i, int j, int val) {
		search(map, g, i, j, val);
		
		for (int d = 0; d < 4; d++) {
			int nr = i + dr[d], nc = j + dc[d];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && !v[nr][nc] && map[nr][nc] == val) {
				v[nr][nc] = true;
				dfs2(map, v, g, nr, nc, val);
			}
		}
	}


	private static void search(int[][] map, int[][] g, int i, int j, int cur) {
		// 거리 측정
		for (int d = 0; d < 4; d++) {
			int dist = 0;
			int nr = i + dr[d], nc = j + dc[d];
			while (nr >= 0 && nr < n && nc >= 0 && nc < m) {
				if (map[nr][nc] == 0) {
					nr += dr[d];
					nc += dc[d];
					dist++;
				}
				else if (map[nr][nc] != cur && dist >= 2) {
					g[cur][map[nr][nc]] = Math.min(dist, g[cur][map[nr][nc]]);
					break;
				}
				else break;
				
			}
		}
	}
	
	static class Edge {
		int src;
		int dest;
		int cost;
		Edge (int src, int dest, int cost) {
			this.src = src;
			this.dest = dest;
			this.cost = cost;
		}
	}
	
	private static void union(int src, int dest, int[] parent) {
		int x = find(src, parent);
		int y = find(dest, parent);
		
		if (x != y) parent[y] = x;
	}
	
	private static int find(int x, int[] parent) {
		if (x == parent[x]) return x;
		else return find(parent[x], parent);
	}
	
	private static int check(int[][] g, int idx, int size) {		
		// 간선 리스트에 모든 간선 추가
		ArrayList<Edge> edges = new ArrayList<Edge>();
		for (int i = 2; i < size+2; i++) {
			for (int j = 2; j < size+2; j++) {
				if (i != j && g[i][j] != 100) edges.add(new Edge(i, j, g[i][j]));
			}
		}
		
		edges.sort(new Comparator<>() { // 간선을 적은 비용 순으로 sort
			@Override
			public int compare(Edge e1, Edge e2) {
				return e1.cost - e2.cost;
			}
		});
		
		// 각 섬이 모두 이어져있는지 검사
		int cost = 0;
		int[] parent = new int[size+2];
		for (int i = 2; i < size+2; i++) parent[i] = i;
		for (Edge e: edges) {
			if (find(e.src, parent) == find(e.dest, parent)) continue;
			union(e.src, e.dest, parent);
			cost += g[e.src][e.dest];
		}
		
		for (int i = 2; i < size+2; i++) parent[i] = find(i, parent);
		
		int p = parent[2];
		for (int i = 3; i < size+2; i++) if (parent[i] != p) return -1;
		
		return cost;
	}
}
