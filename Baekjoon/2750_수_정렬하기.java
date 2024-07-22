import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
		qsort(arr, 0, n-1);
		
		for (int i = 0; i < n; i++) System.out.println(arr[i]);
	}
	
	private static void qsort(int[] arr, int left, int right) {
		if (left < right) {
			int lo = left+1, hi = right, pivot = arr[left];
			do {
				while (lo <= right && arr[lo] < pivot) lo++;
				while (hi >= left && arr[hi] > pivot) hi--;
				if (lo < hi) {
					int tmp = arr[lo];
					arr[lo] = arr[hi];
					arr[hi] = tmp;
				}
			} while (lo < hi);
						
			int tmp = arr[left];
			arr[left] = arr[hi];
			arr[hi] = tmp;
			qsort(arr, left, hi-1);
			qsort(arr, hi+1, right);
		}
	}
}
