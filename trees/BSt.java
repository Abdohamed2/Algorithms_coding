
class node {

    int data = 0;
    node right = null;
    node left = null;

}

class BST {

    public node root;

    public node insert(node r, int data) {
        if (r == null) {
            node newnode = new node();
            newnode.data = data;
            r = newnode;

        } else if (data < r.data) {
            r.left = insert(r.left, data);
        } else {
            r.right = insert(r.right, data);
        }
        return r;
    }

    public void preorder(node r) {
        if (r == null) {
            return;
        }
        System.out.print(r.data + " ");
        preorder(r.left);
        preorder(r.right);
    }

    public static void main(String[] args) {

        BST instance = new BST();
        instance.root = instance.insert(instance.root, 0);
        instance.root = instance.insert(instance.root, 50);
        instance.root = instance.insert(instance.root, 10);
        instance.preorder(instance.root);
    }
}
