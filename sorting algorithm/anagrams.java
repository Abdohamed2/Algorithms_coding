import java.util.Scanner;

public class anagrams {
    static char[] arrchar;
    static int size;
    static int count = 0;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.err.println("please Enter string");
        arrchar = input.next().toCharArray();

        size = arrchar.length;
        // rotate(4);
        // display();
        doAnagram(3);

    }

    public static void doAnagram(int newsize) {
        if (newsize == 1) {
            display();

        }
        for (int i = 0; i < newsize; i++) {
            doAnagram(newsize - 1);
            rotate(newsize);

        }

    }

    public static void rotate(int n) {
        int position = size - n;
        int i;
        char tmp = arrchar[position];
        for (i = position + 1; i < arrchar.length; i++) {
            char c = arrchar[i];
            arrchar[i - 1] = c;

        }
        arrchar[size - 1] = tmp;
        // arrchar[i] = tmp;
    }

    public static void display() {
        System.out.print(" " + (++count) + " ");

        for (int i = 0; i < arrchar.length; i++) {
            System.out.print(arrchar[i]);

        }

        if (count % 6 == 0) {
            System.out.println();

        }
    }
}
