#ifndef ROPE.H
#define ROPE.H
#include <iostream>

class Rope {
private:
    Rope(std::string);
    Rope(const Rope&);
    Rope(Rope&&);
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

#endif // ROPE.H