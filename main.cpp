#include <iostream>
#include <vector>
#include <unordered_map>
#include "solution.h"

using namespace std;
using namespace sol1490;

/*
 Input: root = [1,null,3,2,4,null,5,6]
 Output: [1,null,3,2,4,null,5,6]
*/

Node *testFixture1()
{
  /* build the tree first */
  auto *tree = new Node(1);
  tree->children.push_back(new Node(3));
  tree->children.push_back(new Node(2));
  tree->children.push_back(new Node(4));

  tree->children[0]->children.push_back(new Node(5));
  tree->children[0]->children.push_back(new Node(6));

  return tree;
}

/*
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
*/

Node *testFixture2()
{
  /* build the tree first */
  auto *tree = new Node(1);
  tree->children.push_back(new Node(2));
  tree->children.push_back(new Node(3));
  tree->children.push_back(new Node(4));
  tree->children.push_back(new Node(5));

  /* level 3 */
  tree->children[1]->children.push_back(new Node(6));
  tree->children[1]->children.push_back(new Node(7));

  tree->children[2]->children.push_back(new Node(8));

  tree->children[3]->children.push_back(new Node(9));
  tree->children[3]->children.push_back(new Node(10));

  /* level 4 */
  tree->children[1]->children[1]->children.push_back(new Node(11));
  tree->children[2]->children[0]->children.push_back(new Node(12));
  tree->children[3]->children[0]->children.push_back(new Node(13));

  /* level 5 */
  tree->children[1]->children[1]->children[0]->children.push_back(new Node(14));

  return tree;
}

void test1()
{
  Solution sol;
  auto fixture = testFixture1();
  cout << "Test 1 - expect to see a cloned tree" << endl;
  auto cloned = sol.clone(fixture);
  cout << "result: use debugger to verify" << endl;
}

void test2()
{
  Solution sol;
  auto fixture = testFixture2();
  auto cloned = sol.clone(fixture);
  cout << "Test 2 - expect to see a cloned tree" << endl;
  cout << "result: use debugger to verify" << endl;
}

main()
{
  test1();
  test2();

  return 0;
}