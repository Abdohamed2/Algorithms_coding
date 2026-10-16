public class quicksort {

    public static int partition(int[] arr, int first, int last) {
        int pivot = arr[first];
        int high = last;
        int low = first + 1;
        while (high > low) {
            while (arr[high] > pivot) {
                high--;
            }
            while (high >= low && arr[low] < pivot) {
                low++;
            }
            if (high > low) {
                swap(arr, low, high);

            }

        } // now let say we out the loop cuz high became lower than low so you need to
          // swap pivot with elment of index high
        if (pivot > arr[high]) {
            arr[first] = arr[high];
            arr[high] = pivot;
            return high;// the position of last pivot
        }

        else
            return first;

    }

    public static void swap(int arr[], int f, int l) {
        int tmp = arr[f];
        arr[f] = arr[l];
        arr[l] = tmp;

    }

    public static void quicksorts(int[] arr, int first, int last) {
        if (last > first) {
            int pivotindex = partition(arr, first, last);
            quicksorts(arr, first, pivotindex - 1);
            quicksorts(arr, pivotindex + 1, last);
        }

    }

    public static void main(String[] args) {
        int arr[] = { 3, 5, 4, 8, 0, 1, 2, 4, 6, 7 };
        quicksorts(arr, 0, 9);
        for (int i : arr) {
            System.out.print(i + " ");
        }

    }
}
