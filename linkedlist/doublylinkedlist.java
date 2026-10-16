package linkedlist;

class node {
    int data;
    node next;
    node prev;

    public node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;

    }
}

public class doublylinkedlist {

    node head = null;

    public void append(int x) {
        node newnode = new node(x);
        newnode.data = x;
        if (head == null) {

            head = newnode;
            return;
        } else {
            node current = head;
            while (current.next != null) {
                current = current.next;

            }

            current.next = newnode;
            newnode.prev = current;
        }

    }

    public void traverse() {
        node current = head;
        while (current != null) {
            System.err.print(current.data + " ");
            current = current.next;

        }
    }

}

class Main {
    public static void main(String[] args) {
        doublylinkedlist link = new doublylinkedlist();
        link.append(50);
        link.traverse();
    }
}
