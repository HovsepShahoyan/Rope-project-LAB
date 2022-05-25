#include <iostream>

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


};





int main(){
Rope* rp = new Rope();
rp->insert("Hel");
rp->insert("lo");
rp->insert("!");
rp->insert(" Friend");
std::cout << rp->Index(7);

}
