#include <iostream>
class Rope;
struct Node;

class Rope {
public:
struct Node {
public:
std::string _text = "";
int _length = 0;
Node* left = nullptr;
Node* right = nullptr;

Node(){

}

Node(std::string m_text) {
    _text = m_text;
    _length = _text.length(); 
}

void print() const {
    std::cout << _text;
}

};


public:
Node* _root = new Node();


Rope(){

}

void insert(std::string m_text){
   Node* mainNode = new Node(m_text);
   Node* root = new Node(); 
   root->right = mainNode;
   root->left = _root;
   if ( root->left->right == nullptr ){
        root->_length = root->left->_length;
   }  
   else {
        root->_length = root->left->_length + root->left->right->_length;
   }
   _root = root;
}

char Index(int index){
    Node* temp_root = _root;
    if(index >= temp_root->_length){
        index = index - temp_root->_length;
            return temp_root->right->_text[index];      
    } 
    while (index < temp_root->_length){
        temp_root = temp_root->left;
    }
    index = index - temp_root->_length;
    return temp_root->right->_text[index];  
}

void concat(Rope m_rope) {
    std::string str= "";
    for(int i = 0; i < m_rope._root->_length; i++) {
        str = str + m_rope.Index(i);
    }
    this->insert(str);
}
};

class List {
private:
    
    Node* _head;
    Node* _current;
    Node* _temp;

public:
    
    List() {
    }

    void addNode(Node* _node) {
        _head = new Node();
        if(_head == nullptr) {
            _head = _node;
        }
        else {
             _head->
        }
    }

};









int main(){
Rope rp ;
Rope rp1;
rp1.insert("Wor");
rp1.insert("l");
rp1.insert("d");
rp.insert("Hel");
rp.insert("lo");
rp.insert("!");
rp.concat(rp1);
std::cout << rp.Index(9);
}
