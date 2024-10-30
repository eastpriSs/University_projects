
abstract class Node {
    abstract int accept(Visitor visitor);
}

final class IntValue extends Node {
    public int value;

    IntValue(int value) {
        this.value = value;
    }

    @Override
    int accept(Visitor visitor) {
        return visitor.visit(this);
    }
}

final class BinPlus extends Node {
    public Node left;
    public Node right;

    BinPlus(Node left, Node right) {
        this.left = left;
        this.right = right;
    }

    @Override
    int accept(Visitor visitor) {
        return visitor.visit(this);
    }
}

interface Visitor {
    int visit(IntValue node);
    int visit(BinPlus node);
}

class DefaultVisitor implements Visitor {
    @Override
    public int visit(IntValue node) {
        return node.value;
    }

    @Override
    public int visit(BinPlus node) {
        return node.left.accept(this) + node.right.accept(this);
    }
}

public class Main {
    public static void main(String[] args) {
        // 7+4+0
        Node a = new IntValue(7);
        Node b = new IntValue(4);
        Node c = new IntValue(0);
        Node plusAB = new BinPlus(a, b);
        Node plusABC = new BinPlus(plusAB, c);
        Visitor visitor = new DefaultVisitor();
        System.out.println(plusABC.accept(visitor)); // Output: 11
    }
}
