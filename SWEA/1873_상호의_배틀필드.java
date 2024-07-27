package SWEA;

import java.util.Scanner;

public class s_1873 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int tc = sc.nextInt();
		for (int t = 1; t <= tc; t++) {
			int n = sc.nextInt(), m = sc.nextInt();
			char[][] map = new char[n][m];
			int[] loc = new int[2];
			for (int i = 0; i < n; i++) {
				String str = sc.next();
				for (int j = 0; j < m; j++) {
					map[i][j] = str.charAt(j);
					if (map[i][j] == '<' || map[i][j] == '>' || map[i][j] == '^' || map[i][j] == 'v') {
						loc[0] = i;
						loc[1] = j;
					}
				}
			}
			
			int len = sc.nextInt();
			String cmd = sc.next();
			
			for (int l = 0; l < len; l++) {
				switch (cmd.charAt(l)) {
				case 'U':
					map[loc[0]][loc[1]] = '^';
					if (loc[0] > 0 && map[loc[0]-1][loc[1]] == '.') {
						map[loc[0]][loc[1]] = '.';
						map[--loc[0]][loc[1]] = '^';
					}
					break;
				case 'D':
					map[loc[0]][loc[1]] = 'v';
					if (loc[0] < n-1 && map[loc[0]+1][loc[1]] == '.') {
						map[loc[0]][loc[1]] = '.';
						map[++loc[0]][loc[1]] = 'v';
					}
					break;
				case 'L':
					map[loc[0]][loc[1]] = '<';
					if (loc[1] > 0 && map[loc[0]][loc[1]-1] == '.') {
						map[loc[0]][loc[1]] = '.';
						map[loc[0]][--loc[1]] = '<';
					}
					break;
				case 'R':
					map[loc[0]][loc[1]] = '>';
					if (loc[1] < m-1 && map[loc[0]][loc[1]+1] == '.') {
						map[loc[0]][loc[1]] = '.';
						map[loc[0]][++loc[1]] = '>';
					}
					break;
				default:
					switch (map[loc[0]][loc[1]]) {
					case '^':
						for (int i = loc[0]-1; i >= 0; i--) {
							if (map[i][loc[1]] == '#') break;
							else if (map[i][loc[1]] == '*') {
								map[i][loc[1]] = '.';
								break;
							}
						}
						break;
					case 'v':
						for (int i = loc[0]+1; i < n; i++) {
							if (map[i][loc[1]] == '#') break;
							else if (map[i][loc[1]] == '*') {
								map[i][loc[1]] = '.';
								break;
							}
						}
						break;
					case '<':
						for (int j = loc[1]-1; j >= 0; j--) {
							if (map[loc[0]][j] == '#') break;
							else if (map[loc[0]][j] == '*') {
								map[loc[0]][j] = '.';
								break;
							}
						}
						break;
					case '>':
						for (int j = loc[1]+1; j < m; j++) {
							if (map[loc[0]][j] == '#') break;
							else if (map[loc[0]][j] == '*') {
								map[loc[0]][j] = '.';
								break;
							}
						}
						break;
					}
					break;
				}
			}
			
			System.out.print("#" + t + " ");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) System.out.print(map[i][j]);
				System.out.println();
			}
		}
	}
}
