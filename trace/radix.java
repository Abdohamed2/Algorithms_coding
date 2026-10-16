package trace;

public class radix {
    static void countsort(int arr[], int pos) {
        int size = arr.length;
        int[] count = new int[10];
        int arr2[] = new int[size];
        for (int i = 0; i < arr2.length; i++) {
            count[(arr[i] / pos) % 10]++;
        }
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];

        }
        for (int i = size - 1; i >= 0; i--) {

            arr2[--count[(arr[i] / pos) % 10]] = arr[i];

        }
        for (int i = 0; i < arr2.length; i++) {
            arr[i] = arr2[i];
        }
    }

    static void radixsort(int arr[], int maxelment) {
        for (int i = 1; maxelment / i > 0; i *= 10) {
            countsort(arr, i);

        }

    }

    public static void main(String[] args) {
        int arr[] = { 1, 500, 412, 15, 68, 48, 79, 0, 456, 100, 9 };
        radixsort(arr, 500);
        for (int i : arr) {
            System.out.print(i + " ");
        }

    }

}
