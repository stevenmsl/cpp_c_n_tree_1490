

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;
namespace sol1490
{
    struct Node
    {
        int val;
        vector<Node *> children;

        Node() : val(0) {}
        Node(int val) : val(val) {}
    };
    class Solution
    {
    public:
        Node *clone(Node *root);
    };
}
#endif