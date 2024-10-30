#include <iostream>

class IntValue;
class BinPlus;

class Visitor
{
public:
    int visit(IntValue& rv);
    int visit(BinPlus& rbp);
};

class Node
{
private:

public:
    virtual ~Node() = default;
    virtual int accept(Visitor& visitor) = 0;
};


class IntValue final : public Node
{
public:
    int v;
    
    virtual int accept(Visitor& visitor)
    {
        return visitor.visit(*this);
    }
    
    IntValue(int&& x): v(x){}
    ~IntValue() = default;
};


class BinPlus final : public Node
{
public:
    Node* left;
    Node* right;
    
    virtual int accept(Visitor& visitor)
    {
        return visitor.visit(*this);
    }
    
    BinPlus(Node* l, Node* r): left(l), right(r){}
    ~BinPlus()
    {  
        delete left;
        delete right;
    }
};


int Visitor::visit(IntValue& rv) 
{
    return rv.v;
}

int Visitor::visit(BinPlus& rbp) 
{
    return rbp.left->accept(*this) + rbp.right->accept(*this);
}

int main()
{
    // 7+4+0
    // a+b+c
    Node* a = new IntValue(7);
    Node* b = new IntValue(4);
    Node* c = new IntValue(0);
    Node* plus_ab = new BinPlus(a, b);
    Node* plus_abc = new BinPlus(plus_ab, c);
    Visitor v;
    std::cout << plus_abc->accept(v);
}