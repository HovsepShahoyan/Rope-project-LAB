#include <iostream>
#include "Rope.h"
   
Rope::Node::Node(std::string m_text) {
    _text = m_text;
    _length = _text.length(); 
}

void Rope::Node::print() const {
    std::cout << _text;
}

int Rope::get_length() {
    return _root->_length;
}

void Rope::insert(std::string m_text) {
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

char Rope::Index(int index) {
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

    Rope Rope::concat(Rope& m_rope, Rope& m_rope1) {
    Rope _tmp;
    _tmp._root->left = m_rope._root;
    _tmp._root->right = m_rope1._root;
    if ( _tmp._root->left->right != nullptr ) {
        _tmp._root->_length = m_rope1._root->left->_length + m_rope._root->left->right->_length;
    } else {
        _tmp._root->_length = m_rope1._root->left->_length; 
    }
    return _tmp;
}

