#ifndef NBTREES_H
#define NBTREES_H

#include <stdbool.h>

#define MAX_NODES 20
#define NIL 0

typedef char TreeData;
typedef int NodePtr;

typedef struct TreeNode {
    TreeData data;
    NodePtr first_child;
    NodePtr next_sibling;
    NodePtr parent;
} TreeNode;

typedef TreeNode TreeArray[MAX_NODES + 1];

void InitializeTree(TreeArray tree, int node_count);
bool IsTreeEmpty(TreeArray tree);
void TraversePreOrder(TreeArray tree, NodePtr current);
void TraverseInOrder(TreeArray tree, NodePtr current);
void TraversePostOrder(TreeArray tree, NodePtr current);
void TraverseLevelOrder(TreeArray tree, int max_nodes);
void DisplayTreeStructure(TreeArray tree, int node_count);
bool FindNode(TreeArray tree, TreeData target);
int CountNodes(TreeArray tree);
int CountLeaves(TreeArray tree);
int GetNodeLevel(TreeArray tree, TreeData target);
int CalculateTreeDepth(TreeArray tree);
int FindMaximum(int x, int y);
void DrawTreeIllustration();

#endif
