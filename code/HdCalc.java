import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

class Node {
  public int value;
  public Node left;
  public Node right;

  public Node(int value) {
    this.value = value;
    this.left = this.right = null;
  }

}

class Tree {
  Node root;

  public Tree() {
    this.root = null;
  }

  public void add(int v) {
    root = addHelper(root, v);
  }

  private Node addHelper(Node cnode, int v) {
    if (cnode == null) {
      return new Node(v);
    }
    if (v < cnode.value) {
      cnode.left = addHelper(cnode.left, v);
    } else {
      cnode.right = addHelper(cnode.right, v);
    }
    return cnode;
  }

  public void inorder() {
    inorderHelper(root);
  }

  private void inorderHelper(Node cnode) {
    if (cnode == null)
      return;
    inorderHelper(cnode.left);
    System.out.println(cnode.value);
    inorderHelper(cnode.right);
  }

  public void verticalOrder() {
    HashMap<Integer, Vector<Node>> hash = new HashMap<Integer, Vector<Node>>();
    verticalOrderHelper(root, 0, hash);
    for (Map.Entry<Integer, Vector<Node>> m : hash.entrySet()) {
      System.out.print(m.getKey() + "-");
      for (int i = 0; i < m.getValue().size(); i++) {
        System.out.print(m.getValue().get(i).value + " ");
      }
      System.out.println("");
    }
  }

  private void verticalOrderHelper(Node cnode, int hd, HashMap<Integer, Vector<Node>> hash) {
    if (cnode == null)
      return;
    if (hash.get(hd) == null) {
      Vector<Node> v = new Vector<Node>();
      v.add(cnode);
      hash.put(hd, v);
    } else {
      hash.get(hd).add(cnode);
    }
    verticalOrderHelper(cnode.left, hd - 1, hash);
    verticalOrderHelper(cnode.right, hd + 1, hash);
  }

  public void leftView

}

public class HdCalc {
  public static void main(String[] args) {
    Tree t = new Tree();
    t.add(10);
    t.add(8);
    t.add(20);
    t.add(4);
    t.add(9);
    t.add(15);
    t.add(18);
    t.add(19);
    t.verticalOrder();
  }
}