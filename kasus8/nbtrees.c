#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    // Membuat tree sesuai struktur yang diinginkan
    X[1] = (nbtree){'A', 2, 0, 0};     // A adalah root, first child = B (index 2)
    X[2] = (nbtree){'B', 4, 3, 1};     // B, first child = D (index 4), next brother = C (index 3), parent = A (index 1)
    X[3] = (nbtree){'C', 6, 0, 1};     // C, first child = F (index 6), parent = A (index 1)
    X[4] = (nbtree){'D', 0, 5, 2};     // D, next brother = E (index 5), parent = B (index 2)
    X[5] = (nbtree){'E', 9, 0, 2};     // E, first child = I (index 9), parent = B (index 2)
    X[6] = (nbtree){'F', 0, 7, 3};     // F, next brother = G (index 7), parent = C (index 3)
    X[7] = (nbtree){'G', 0, 8, 3};     // G, next brother = H (index 8), parent = C (index 3)
    X[8] = (nbtree){'H', 0, 0, 3};     // H, parent = C (index 3)
    X[9] = (nbtree){'I', 0, 10, 5};    // I, next brother = J (index 10), parent = E (index 5)
    X[10] = (nbtree){'J', 0, 0, 5};    // J, parent = E (index 5)

    // Inisialisasi sisa array dengan nilai kosong
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
    // PreOrder: Root -> Left -> Right
    if (pos != nil && P[pos].info != ' ') {
        printf("%c ", P[pos].info);  // Cetak node saat ini
        
        // Kunjungi semua anak
        int child = P[pos].ps_fs;  // Mulai dari first child
        while (child != nil) {
            PreOrder(P, child);
            child = P[child].ps_nb;  // Pindah ke next brother
        }
    }
}

void InOrder(Isi_Tree P, int pos) {
    // InOrder: Left children -> Root -> Right children
	int i;
    if (pos == 0) return;

    // Simpan semua anak dalam array
    int children[20], cnt = 0;
    int c = P[pos].ps_fs;
    while (c != nil) {
        children[cnt++] = c;
        c = P[c].ps_nb;
    }

    // Jika tidak punya anak, langsung cetak node
    if (cnt == 0) {
        printf("%c ", P[pos].info);
        return;
    }

    // Tentukan titik tengah untuk membagi anak menjadi 2 bagian
    int mid = (cnt + 1) / 2;

    // Proses setengah anak pertama
    for (i = 0; i < mid; i++) {
        InOrder(P, children[i]);
    }

    // Cetak root
    printf("%c ", P[pos].info);

    // Proses setengah anak sisanya
    for (i = mid; i < cnt; i++) {
        InOrder(P, children[i]);
    }
}

void PostOrder(Isi_Tree P, int pos) {
    // PostOrder: Semua anak -> Root
    if (pos != nil && P[pos].info != ' ') {
        // Kunjungi semua anak terlebih dahulu
        int child = P[pos].ps_fs;
        while (child != nil) {
            PostOrder(P, child);
            child = P[child].ps_nb;
        }
        // Cetak root setelah semua anak dikunjungi
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
    printf("Seluruh Node pada Non Binary Tree:\n\n");
    
    int i;
    for (i = 1; i <= Jml_Node; i++) {
        if (P[i].info != ' ') {
            printf("--> Indeks ke-%d\n", i);
            printf("----------------------------------\n");
            printf("info array ke %d              : %c\n", i, P[i].info);
            printf("first son array ke %d         : %d\n", i, P[i].ps_fs);
            printf("next brother array ke %d      : %d\n", i, P[i].ps_nb);
            printf("parent array ke %d            : %d\n", i, P[i].ps_pr);
            printf("----------------------------------\n");
        }
    }
}

boolean Search(Isi_Tree P, infotype X) {
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ' && P[i].info == X) {
            return true;
        }
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
        // Node adalah daun jika: tidak kosong DAN tidak punya first child
        if (P[i].info != ' ' && P[i].ps_fs == nil)
            count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    int i;
    // Cari node dengan info = X
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            int parent = P[i].ps_pr;
            // Hitung level dengan naik ke parent sampai root
            while (parent != nil) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1;  // Node tidak ditemukan
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

boolean compareNodes(Isi_Tree P, infotype node1, infotype node2) {
    int index1 = -1, index2 = -1;
    int i;
    
    // Cari index kedua node
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == node1) index1 = i;
        if (P[i].info == node2) index2 = i;
    }
    
    // Jika salah satu node tidak ditemukan
    if (index1 == -1 || index2 == -1) {
        return false;
    }
    
    // Bandingkan struktur (first son, next brother, parent)
    if (P[index1].ps_fs == P[index2].ps_fs &&
        P[index1].ps_nb == P[index2].ps_nb &&
        P[index1].ps_pr == P[index2].ps_pr) {
        return true;
    }
    
    return false;
}

void showNodeComparison(Isi_Tree P, infotype node1, infotype node2) {
    int index1 = -1, index2 = -1;
    int i;
    
    // Cari index kedua node
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == node1) index1 = i;
        if (P[i].info == node2) index2 = i;
    }
    
    if (index1 == -1) {
        printf("Node '%c' tidak ditemukan!\n", node1);
        return;
    }
    if (index2 == -1) {
        printf("Node '%c' tidak ditemukan!\n", node2);
        return;
    }
    
    printf("\n=== DETAIL PERBANDINGAN ===\n");
    printf("Node '%c' (Index-%d):\n", node1, index1);
    printf("  First Son    : %d\n", P[index1].ps_fs);
    printf("  Next Brother : %d\n", P[index1].ps_nb);
    printf("  Parent       : %d\n", P[index1].ps_pr);
    
    printf("\nNode '%c' (Index-%d):\n", node2, index2);
    printf("  First Son    : %d\n", P[index2].ps_fs);
    printf("  Next Brother : %d\n", P[index2].ps_nb);
    printf("  Parent       : %d\n", P[index2].ps_pr);
    
    printf("\n=== HASIL PERBANDINGAN ===\n");
    printf("First Son    : %s\n", (P[index1].ps_fs == P[index2].ps_fs) ? "SAMA" : "BEDA");
    printf("Next Brother : %s\n", (P[index1].ps_nb == P[index2].ps_nb) ? "SAMA" : "BEDA");
    printf("Parent       : %s\n", (P[index1].ps_pr == P[index2].ps_pr) ? "SAMA" : "BEDA");
}

int Max(int a, int b) {
    return a > b ? a : b;
}

void ilustrasiTree(){
    printf("======================== ILUSTRASI TREE ====================\n\n");
    printf("\t\t\t                 A\n");
    printf("\t\t\t               /   \\\n");
    printf("\t\t\t              B      C\n");
    printf("\t\t\t             / \\   / | \\\n");
    printf("\t\t\t            D   E F  G  H\n");
    printf("\t\t\t               / \\\n");
    printf("\t\t\t              I   J\n\n");
    printf("Keterangan:\n");
    printf("- A adalah ROOT (level 0)\n");
    printf("- B, C adalah anak A (level 1)\n");
    printf("- D, E adalah anak B; F, G, H adalah anak C (level 2)\n");
    printf("- I, J adalah anak E (level 3)\n");
    printf("- Node DAUN: D, F, G, H, I, J (tidak punya anak)\n");
    printf("------------------------------------------------------------\n");
}
