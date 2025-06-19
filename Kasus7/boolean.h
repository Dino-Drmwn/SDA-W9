#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    X[1] = (nbtree){'A', 2, 0, 0};
    X[2] = (nbtree){'B', 4, 3, 1};
    X[3] = (nbtree){'C', 6, 0, 1};
    X[4] = (nbtree){'D', 0, 5, 2};
    X[5] = (nbtree){'E', 9, 0, 2};
    X[6] = (nbtree){'F', 0, 7, 3};
    X[7] = (nbtree){'G', 0, 8, 3};
    X[8] = (nbtree){'H', 0, 0, 3};
    X[9] = (nbtree){'I', 0, 10, 5};
    X[10] = (nbtree){'J', 0, 0, 5};

    int i;
    for (i = 11; i <= jml_maks; i++) {
        X[i].info = ' ';
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;
    }
}

boolean IsEmpty(Isi_Tree P) {
    return P[1].info == ' ';
}

void PreOrder(Isi_Tree P, int pos) {
    if (pos != nil) {
        printf("%c ", P[pos].info);
        PreOrder(P, P[pos].ps_fs);
        PreOrder(P, P[pos].ps_nb);
    }
}

void InOrder(Isi_Tree P, int pos) {
	int i;
    if (pos == 0) return;

    int children[20], cnt = 0;
    int c = P[pos].ps_fs;
    while (c != nil) {
        children[cnt++] = c;
        c = P[c].ps_nb;
    }

    if (cnt == 0) {
        printf("%c ", P[pos].info);
        return;
    }

    int mid = (cnt + 1) / 2;

    for (i = 0; i < mid; i++) {
        InOrder(P, children[i]);
    }

    printf("%c ", P[pos].info);

    for (i = mid; i < cnt; i++) {
        InOrder(P, children[i]);
    }
}


void PostOrder(Isi_Tree P, int pos) {
    if (pos != nil) {
        int child = P[pos].ps_fs;
        while (child != nil) {
            PostOrder(P, child);
            child = P[child].ps_nb;
        }
        printf("%c ", P[pos].info);
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    int i;
    for (i = 1; i <= Maks_node; i++) {
        if (X[i].info != ' ')
            printf("%c ", X[i].info);
    }
}

void PrintTree(Isi_Tree P, int Jml_Node) {
    int i;
    printf("|Index\t|\tInfo\t|First Son\t|Next Brother\t|\tParent\t|\n");
    printf("=========================================================================\n");
    for (i = 1; i <= Jml_Node; i++) {
        if (P[i].info != ' ')
            printf("|%d\t|\t%c\t|\t%d\t|\t%d\t|\t%d\t|\n", i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
    }
}

boolean Search(Isi_Tree P, infotype X) {
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].ps_fs != nil && P[1].info == X)
            return true;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ')
            count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ' && P[i].ps_fs == nil)
            count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    int i;
    int level = 0;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int parent = P[i].ps_pr;
            while (parent != nil) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int Depth(Isi_Tree P) {
    int max = 0;
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            int level = Level(P, P[i].info);
            if (level > max)
                max = level;
        }
    }
    return max;
}

int Max(int a, int b) {
    return a > b ? a : b;
}

void ilustrasiTree(){
	printf("============================== ILUSTRASI TREE ============================\n\n");
    printf("\t\t\t                 A\n");
    printf("\t\t\t               /   \\\n");
    printf("\t\t\t              B      C\n");
    printf("\t\t\t             / \\   / | \\\n");
    printf("\t\t\t            D   E F  G  H\n");
    printf("\t\t\t               / \\\n");
    printf("\t\t\t              I   J\n\n");
}
