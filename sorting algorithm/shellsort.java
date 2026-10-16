public class shellsort {
    public static void shellsort(int[] arr) {
        int h = 1;
        while (h * 3 + 1 < arr.length)// while(h<=arr.length/3) and // this loop for type of diffrent size of groups
                                      // like knuth's sequence interval
        {
            h = h * 3 + 1;
        }
        while (h > 0) {
            for (int i = h; i < arr.length; i++)// this loop for all groups with the same size
            {
                int temp = arr[i];
                int inner = i;
                while (inner - h >= 0 && temp < arr[inner - h]) {

                    arr[inner] = arr[inner - h];
                    inner -= h;
                }
                arr[inner] = temp;
            }
            h = (h - 1) / 3;

        }
        for (int i = 0; i < arr.length; i++) {
            System.err.print(arr[i] + " ");
        }

    }

    public static void main(String[] args) {
        int[] arr = { 8, 6, 9, 4 };
        shellsort(arr);

    }
}
// mostafa kamel youtube
