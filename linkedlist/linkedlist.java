package linkedlist;

class node {
    int data;
    node next;

    public node(int data) {
        this.data = data;

    }
}

public class linkedlist {
    node head;// the most important thing in all program

    public void append(int item) {
        node newnode = new node(item);
        if (head == null) {
            head = newnode;

        } else {
            node current = head;
            while (current.next != null) {
                current = current.next;

            }
            current.next = newnode;

        }
    }

    public void insretionfirst(int item) {

        node newnode = new node(item);
        newnode.next = head;
        head = newnode;

    }

    public void insertatindex(int item, int pos) {
        node newnode = new node(item);
        node current = head;
        if (pos == 0) {
            insretionfirst(item);
            return;
        }

        else {

            int index = 0;
            while (current != null && index < pos - 1) {
                current = current.next;
                index++;
            }
            if (current == null) {
                System.out.println("out of bounds");
                return;
            }
            newnode.next = current.next;
            current.next = newnode;

        }

    }

    public void delete(int item) {
        node current = head;
        if (item == head.data) {
            head = head.next;
            return;
        }
        while (current.next != null)

        {
            if (current.next.data == item) {
                current.next = current.next.next;
            }
            current = current.next;

        }
        if (current.next == null)
            current.next = null;

    }

    public void merge(linkedlist lin) {
        if (head == null) {
            head = lin.head;
        }
        node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = lin.head;

    }

    public void traverse() {
        node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;

        }
        System.out.println("null");
    }

}

class Main {
    public static void main(String[] args) {
        linkedlist link = new linkedlist();

        linkedlist lind = new linkedlist();
        lind.append(56);
        lind.append(56);
        lind.append(56);
        lind.append(56);
        link.merge(lind);
        lind.delete(56);

        lind.traverse();

    }
}
