#ifndef ROPE.H
#define ROPE.H
#include <iostream>

class Rope { 
    struct Node {
    public: 
        std::string _text = "";
        int _length = 0;
        Node* left = nullptr;
        Node* right = nullptr;   
    public: // member functions
        Node() = default;   
        Node(std::string m_text);
        void print() const;
    };
public: 
Node* _root = new Node();
public: // member functions
Rope() = default;
int get_length();
void insert(std::string m_text);
char Index(int index);
Rope concat(Rope& m_rope, Rope& m_rope1);
};

#endif // ROPE.H