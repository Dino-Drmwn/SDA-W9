#include "nbtrees.h"
#include <stdio.h>

int main() {
    TreeArray myTree;
    InitializeTree(myTree, 10);
    
    DrawTreeIllustration();
    
    printf("============================ TREE STRUCTURE ===========================\n");
    DisplayTreeStructure(myTree, 10);
    printf("======================================================================\n\n");
    
    printf("\nPREORDER TRAVERSAL:\n");
    TraversePreOrder(myTree, 1);
    
    printf("\n\nINORDER TRAVERSAL:\n");
    TraverseInOrder(myTree, 1);
    
    printf("\n\nPOSTORDER TRAVERSAL:\n");
    TraversePostOrder(myTree, 1);
    
    printf("\n\nLEVEL ORDER TRAVERSAL:\n");
    TraverseLevelOrder(myTree, 10);
    
    printf("\n\n------------------");
    printf("\nTotal Nodes: %d\n", CountNodes(myTree));
    printf("\n------------------\n");
    printf("\n------------------");
    printf("\nTotal Leaves: %d\n", CountLeaves(myTree));
    printf("\n------------------\n");
    printf("\n------------------");
    printf("\nLevel of Node 'G': %d\n", GetNodeLevel(myTree, 'G'));
    printf("\n------------------\n");
    printf("\n------------------");
    printf("\nTree Depth: %d\n", CalculateTreeDepth(myTree));
    printf("\n------------------\n");

    return 0;
}
