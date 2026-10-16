package trace;

public class countsort {
    public static void countsorit(int arr[], int maxelment) {
        int size = arr.length;
        int[] arr2 = new int[size];
        int count[] = new int[maxelment];
        for (int i = 0; i < arr.length; i++) {
            count[arr[i]]++;
        }
        for (int i = 1; i <= count.length - 1; i++) {
            count[i] += count[i - 1];
        }
        for (int i = arr.length - 1; i >= 0; i--) {

            arr2[--count[arr[i]]] = arr[i];
        }
        for (int i : arr2) {
            System.out.print(i + " ");
        }
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 7, 8, 5, 4, 6, 0 };
        countsorit(arr, 9);

    }

}
