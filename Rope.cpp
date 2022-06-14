#include <iostream>
#include "Rope.h"
   
Rope::RopeNode::RopeNode() {
    text = "";
    left = nullptr;
    right = nullptr;
}

Rope::RopeNode::~RopeNode() {
    if(left) { delete left; }
    if(right) { delete right; }
}

Rope::Rope(std::string m_text) {
    root = new RopeNode;
    root->text = "";
    root->left = nullptr;
    root->right = nullptr;
    root->weight = m_text.length();
    root->left = new RopeNode;
    root->left->text = m_text;
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->left->weight = m_text.length();
}

Rope::Rope(Rope&& obj) {
    root = obj.root;
    obj.root = nullptr;
}

Rope::Rope(const Rope& obj) {
    root = new RopeNode;
    root->left = new RopeNode;
    root->weight = obj.length();
    root->left->weight = obj.length();
    root->left->text = obj.root->text;
}

Rope::Rope(std::initializer_list<std::string> init_list) {
    root = new RopeNode;
    root->text = "";
    root->left = nullptr;
    root->right = nullptr;
    int index = 0;
    for(std::initializer_list<std::string>::iterator it = init_list.begin(); it != init_list.end(); it++) {
        index += it->length();
        this->insert(index, *it);
    }
}

Rope::~Rope() {
    if(root) { delete root; }
}

int Rope::length() const{
    return root->weight;
}

void Rope::insert(int index, std::string m_text) {
    if(index >= root->weight) {
        RopeNode* root_copy = new RopeNode;
        RopeNode* new_node = new RopeNode;
        new_node->text = m_text;
        new_node->weight = m_text.length();
        root_copy->left = root;
        root->right = new_node;
        root_copy->weight = new_node->weight + root->weight;
        root = root_copy;
    }
    else {
        ++index;
        RopeNode* root_copy = root;
        while(root_copy->text.length() != 1) {    
            if(index > root_copy->weight) {
                index = index - root_copy->weight;
                root_copy = root_copy->right;
            }
            else {
                root_copy->weight = root_copy->weight + m_text.length();
                root_copy = root->left;
            }
        }      
        RopeNode* new_left = new RopeNode;
        RopeNode* new_right = new RopeNode;
        RopeNode* new_content = new RopeNode;
        new_left->text= nullptr;
        new_left->weight = index;
        new_left->right = new_content;
        new_left->left = new RopeNode;
        new_left->left->text = root_copy->text;
        new_left->left->weight = index;
        new_right->text = root_copy->text;
        new_right->weight = root_copy->weight - index;
        new_content->text = m_text;
        new_content->weight = m_text.length();
        root_copy->text = nullptr;
        root_copy->left = new_left;
        root_copy->right = new_right;
    }
}