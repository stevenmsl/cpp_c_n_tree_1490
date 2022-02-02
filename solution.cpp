#include "solution.h"

#include <functional>
#include <unordered_map>
using namespace sol1490;
using namespace std;

/* takeaways
   - technically speaking we don't need
     the map to remember which nodes have
     been visited as we are visiting
     the tree top-down and not jumping
     around in any case - ref question 1485
   - but this should help if we are cloning
     graphs with cycles

*/

Node *Solution::clone(Node *root)
{
  /*
    - used to mark which node has been visited
      in the original tree
    - check if this can be used to clone a
      graph
  */
  unordered_map<Node *, Node *> cloned;

  function<Node *(Node * node)> copy =
      [&copy, &cloned](Node *node)
  {
    if (node == nullptr)
      /* C++
         - don't return nullptr directly
           or the code will fail to compile
      */
      return node;

    /* - node has been visited;
       - return the copied node
    */
    if (cloned.count(node))
    {
      return cloned[node];
    }

    /* visit the node and its children */
    auto newNode = new Node(node->val);
    cloned[node] = newNode;

    for (auto c : node->children)
      newNode->children.push_back(copy(c));

    return newNode;
  };

  copy(root);
  /*
    - return the root of the cloned tree
  */
  return cloned[root];
  // return copy(root);
}