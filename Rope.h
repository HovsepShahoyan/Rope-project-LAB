#ifndef ROPE_H
#define ROPE_H
#include <iostream>

class Rope {
public:
    Rope(std::string);
    Rope(const Rope&);
    Rope(Rope&&);
    Rope(std::initializer_list<std::string> init_list);
    ~Rope();
public:
    void insert(int, std::string);
    int length() const;
private:
    struct RopeNode {
        std::string text {};
        RopeNode* left;
        RopeNode* right;
        int weight;
        RopeNode();
        ~RopeNode();
};
private:
    RopeNode* root;
};

#endif // ROPE_H