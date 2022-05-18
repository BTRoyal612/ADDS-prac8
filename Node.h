#ifndef NODE
#define NODE

class Node {
    private:
        int data;
        Node * next;

    public:
        Node();
        Node(int _data, Node * _next);
        void setData(int _data);
        int getData();
        void setNext(Node * _next);
        Node * getNext();
};  

#endif