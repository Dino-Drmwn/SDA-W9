#include "nbtrees.h"
#include <stdio.h>

void InitializeTree(TreeArray tree, int node_count) {
    // Initialize all nodes
    for (int i = 1; i <= MAX_NODES; i++) {
        tree[i].data = ' ';
        tree[i].first_child = NIL;
        tree[i].next_sibling = NIL;
        tree[i].parent = NIL;
    }

    // Manually build the tree structure
    tree[1] = (TreeNode){'A', 2, NIL, NIL};    // Root
    
    // Level 2
    tree[2] = (TreeNode){'B', 4, 3, 1};        // B (child of A)
    tree[3] = (TreeNode){'C', 6, NIL, 1};      // C (sibling of B)
    
    // Level 3
    tree[4] = (TreeNode){'D', NIL, 5, 2};      // D (child of B)
    tree[5] = (TreeNode){'E', 9, NIL, 2};      // E (sibling of D)
    tree[6] = (TreeNode){'F', NIL, 7, 3};      // F (child of C)
    tree[7] = (TreeNode){'G', NIL, 8, 3};      // G (sibling of F)
    tree[8] = (TreeNode){'H', NIL, NIL, 3};    // H (sibling of G)
    
    // Level 4
    tree[9] = (TreeNode){'I', NIL, 10, 5};     // I (child of E)
    tree[10] = (TreeNode){'J', NIL, NIL, 5};   // J (sibling of I)
}

bool IsTreeEmpty(TreeArray tree) {
    return tree[1].data == ' ';
}

void PreOrderTraversal(TreeArray tree, NodePtr node) {
    if (node == NIL) return;
    printf("%c ", tree[node].data);
    PreOrderTraversal(tree, tree[node].first_child);
    PreOrderTraversal(tree, tree[node].next_sibling);
}

void TraversePreOrder(TreeArray tree, NodePtr root) {
    PreOrderTraversal(tree, root);
}

void InOrderTraversal(TreeArray tree, NodePtr node) {
    if (node == NIL) return;
    
    NodePtr child = tree[node].first_child;
    if (child != NIL) {
        InOrderTraversal(tree, child);
        child = tree[child].next_sibling;
    }
    
    printf("%c ", tree[node].data);
    
    while (child != NIL) {
        InOrderTraversal(tree, child);
        child = tree[child].next_sibling;
    }
}

void TraverseInOrder(TreeArray tree, NodePtr root) {
    InOrderTraversal(tree, root);
}

void PostOrderTraversal(TreeArray tree, NodePtr node) {
    if (node == NIL) return;
    
    NodePtr child = tree[node].first_child;
    while (child != NIL) {
        PostOrderTraversal(tree, child);
        child = tree[child].next_sibling;
    }
    
    printf("%c ", tree[node].data);
}

void TraversePostOrder(TreeArray tree, NodePtr root) {
    PostOrderTraversal(tree, root);
}

void TraverseLevelOrder(TreeArray tree, int max_nodes) {
    for (int i = 1; i <= max_nodes; i++) {
        if (tree[i].data != ' ') {
            printf("%c ", tree[i].data);
        }
    }
}

void DisplayTreeStructure(TreeArray tree, int node_count) {
    printf("| Index | Data | First Child | Next Sibling | Parent |\n");
    printf("=====================================================\n");
    for (int i = 1; i <= node_count; i++) {
        if (tree[i].data != ' ') {
            printf("| %5d | %4c | %11d | %12d | %6d |\n", 
                   i, tree[i].data, tree[i].first_child, 
                   tree[i].next_sibling, tree[i].parent);
        }
    }
}

bool FindNodeHelper(TreeArray tree, NodePtr node, TreeData target) {
    if (node == NIL) return false;
    if (tree[node].data == target) return true;
    return FindNodeHelper(tree, tree[node].first_child, target) || 
           FindNodeHelper(tree, tree[node].next_sibling, target);
}

bool FindNode(TreeArray tree, TreeData target) {
    return FindNodeHelper(tree, 1, target);
}

int CountNodes(TreeArray tree) {
    int count = 0;
    for (int i = 1; i <= MAX_NODES; i++) {
        if (tree[i].data != ' ') count++;
    }
    return count;
}

int CountLeavesHelper(TreeArray tree, NodePtr node) {
    if (node == NIL) return 0;
    if (tree[node].first_child == NIL) return 1;
    
    int count = 0;
    NodePtr child = tree[node].first_child;
    while (child != NIL) {
        count += CountLeavesHelper(tree, child);
        child = tree[child].next_sibling;
    }
    return count;
}

int CountLeaves(TreeArray tree) {
    return CountLeavesHelper(tree, 1);
}

int GetNodeLevel(TreeArray tree, TreeData target) {
    for (int i = 1; i <= MAX_NODES; i++) {
        if (tree[i].data == target) {
            int level = 0;
            NodePtr parent = tree[i].parent;
            while (parent != NIL) {
                level++;
                parent = tree[parent].parent;
            }
            return level;
        }
    }
    return -1;
}

int CalculateTreeDepthHelper(TreeArray tree, NodePtr node) {
    if (node == NIL) return 0;
    
    int max_depth = 0;
    NodePtr child = tree[node].first_child;
    while (child != NIL) {
        int current_depth = CalculateTreeDepthHelper(tree, child);
        if (current_depth > max_depth) {
            max_depth = current_depth;
        }
        child = tree[child].next_sibling;
    }
    return max_depth + 1;
}

int CalculateTreeDepth(TreeArray tree) {
    return CalculateTreeDepthHelper(tree, 1);
}

int FindMaximum(int x, int y) {
    return (x > y) ? x : y;
}

void DrawTreeIllustration() {
    printf("============================ TREE ILLUSTRATION ===========================\n\n");
    printf("\t\t\t                 A\n");
    printf("\t\t\t               /   \\\n");
    printf("\t\t\t              B      C\n");
    printf("\t\t\t             / \\   / | \\\n");
    printf("\t\t\t            D   E F  G  H\n");
    printf("\t\t\t               / \\\n");
    printf("\t\t\t              I   J\n\n");
}
