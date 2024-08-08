import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		int[] prev = new int[1000001], next = new int[1000001];
		String[] str = br.readLine().split(" ");
		prev[Integer.parseInt(str[0])] = Integer.parseInt(str[n-1]);
		next[Integer.parseInt(str[0])] = Integer.parseInt(str[1]);
		for (int i = 1; i < n-1; i++) {
			prev[Integer.parseInt(str[i])] = Integer.parseInt(str[i-1]);
			next[Integer.parseInt(str[i])] = Integer.parseInt(str[i+1]);
		}
		prev[Integer.parseInt(str[n-1])] = Integer.parseInt(str[n-2]);
		next[Integer.parseInt(str[n-1])] = Integer.parseInt(str[0]);
		
		StringBuilder sb = new StringBuilder();
		while (m-- > 0) {
			String[] cmd = br.readLine().split(" ");
			int idx = Integer.parseInt(cmd[1]), ndx;
			switch (cmd[0]) {
			case "BN":
				ndx = Integer.parseInt(cmd[2]);
				sb.append(next[idx] + "\n");
				prev[ndx] = idx;
				next[ndx] = next[idx];
				prev[next[idx]] = ndx;
				next[idx] = ndx;
				break;
			case "BP":
				ndx = Integer.parseInt(cmd[2]);
				sb.append(prev[idx] + "\n");
				prev[ndx] = prev[idx];
				next[ndx] = idx;
				next[prev[idx]] = ndx;
				prev[idx] = ndx;
				break;
			case "CN":
				sb.append(next[idx] + "\n");
				prev[next[next[idx]]] = idx;
				next[idx] = next[next[idx]];
				break;
			case "CP":
				sb.append(prev[idx] + "\n");
				next[prev[prev[idx]]] = idx;
				prev[idx] = prev[prev[idx]];
				break;
			}
		}
		System.out.println(sb.toString());
	}
}
