import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		Queue<Integer> q = new LinkedList<>();
		for (int i = 1; i <= n; i++) q.add(i);
		while (q.size() > 1) {
			q.remove();
			q.add(q.peek());
			q.remove();
		}
		System.out.println(q.peek());
	}
}
