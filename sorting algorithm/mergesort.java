public class mergesort {
    public static void mergesrt(int a[], int b[], int c[]) {
        int indexa = 0;
        int indexb = 0;
        int indexc = 0;
        while (indexa < a.length && indexb < b.length) {
            if (a[indexa] < b[indexb])
                c[indexc++] = a[indexa++];
            else
                c[indexc++] = b[indexb++];
        }
        while (indexa < a.length) {
            c[indexc++] = a[indexa++];

        }
        while (indexb < b.length) {
            c[indexc++] = b[indexb++];

        }

    }

    public static void merge(int[] list) {
        if (list.length > 1) {
            int[] firstHalf = new int[list.length / 2];
            System.arraycopy(list, 0, firstHalf, 0, firstHalf.length);
            merge(firstHalf);
            int secochalflength = list.length - firstHalf.length;
            int[] secondHalf = new int[secochalflength];
            System.arraycopy(list, firstHalf.length, secondHalf, 0, secochalflength);
            merge(secondHalf);
            mergesrt(firstHalf, secondHalf, list);

        }
    }

    public static void main(String[] args) {
        int a[] = { 1, 3, 5, 7 };

        int b[] = { 2, 4, 6, 8 };
        int[] c = new int[a.length + b.length];
        int array[] = { 2, 8, 0, 4, 1, 3, 7, 5 };
        // mergesrt(a, b, c);
        merge(array);
        for (int i : array) {
            System.out.print(i + " ");
        }

    }
}
