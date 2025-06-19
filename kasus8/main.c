#include "nbtrees.h"

void tampilkanMenu() {
    printf("\n=================== MENU NON BINARY TREE ===================\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 node Tree\n");
    printf("11. Exit\n");
    printf("=============================================================\n");
    printf("Pilih menu (1-11): ");
}

void KlikToContinue() {
    printf("\nKlik ENTER pun untuk melanjutkan!.............\n");
    printf("-------------------------------------------------------------\n");
    getchar(); 
    getchar();
}

int main() {
    Isi_Tree P;
    int pilihan;
    char cariNode, node1, node2;
    
    // Langsung buat tree di awal program
    printf("========= SELAMAT DATANG DI PROGRAM NON BINARY TREE ========\n");

    Create_tree(P, 10);
    
    do {
        system("cls");
        ilustrasiTree();
        tampilkanMenu();
        scanf("%d", &pilihan);

        system("cls");
        
        switch(pilihan) {
            case 1:
                ilustrasiTree();
                printf("\n==================== TRAVERSAL PREORDER ====================\n");
                printf("Hasil PreOrder: ");
                PreOrder(P, 1);
                printf("\n");
                KlikToContinue();
                break;
                
            case 2:
                ilustrasiTree();
                printf("\n==================== TRAVERSAL INORDER ====================\n");
                printf("Hasil InOrder: ");
                InOrder(P, 1);
                printf("\n");
                KlikToContinue();
                break;
                
            case 3:
                ilustrasiTree();
                printf("\n==================== TRAVERSAL POSTORDER ====================\n");
                printf("Hasil PostOrder: ");
                PostOrder(P, 1);
                printf("\n");
                KlikToContinue();
                break;
                
            case 4:
                ilustrasiTree();
                printf("\n==================== TRAVERSAL LEVEL ORDER ====================\n");
                printf("Hasil Level Order: ");
                Level_order(P, 10);
                printf("\n");
                KlikToContinue();
                break;
                
            case 5:
                ilustrasiTree();
                printf("\n==================== PRINT TREE =======================\n");
                PrintTree(P, 10);
                KlikToContinue();
                break;
                
            case 6:
                printf("\n====================== SEARCH NODE ====================\n");
                printf("Masukkan node yang ingin dicari: ");
                scanf(" %c", &cariNode);
                
                if (Search(P, cariNode)) {
                    printf("Node '%c' DITEMUKAN dalam tree!\n", cariNode);
                } else {
                    printf("Node '%c' TIDAK DITEMUKAN dalam tree!\n", cariNode);
                }
                KlikToContinue();
                break;
                
            case 7:
                ilustrasiTree();
                printf("\n==================== JUMLAH DAUN ======================\n");
                printf("Jumlah Daun dalam tree: %d\n", nbDaun(P));
                printf("Node Daun: D, F, G, H, I, J\n");
                KlikToContinue();
                break;
                
            case 8:
                ilustrasiTree();
                printf("\n======================= LEVEL NODE ====================\n");
                printf("Masukkan node yang ingin dicari levelnya: ");
                scanf(" %c", &cariNode);
                
                int levelNode = Level(P, cariNode);
                if (levelNode != -1) {
                    printf("Level node '%c': %d\n", cariNode, levelNode);
                } else {
                    printf("Node '%c' tidak ditemukan dalam tree!\n", cariNode);
                }
                KlikToContinue();
                break;
                
            case 9:
                ilustrasiTree();
                printf("\n==================== KEDALAMAN TREE ====================\n");
                printf("Kedalaman/Depth tree: %d\n", Depth(P));
                printf("Kedalaman adalah level maksimum dari semua node.\n");
                printf("Level maksimum berada pada node I dan J (level 3)\n");
                KlikToContinue();
                break;
                
            case 10:
                printf("\n=============== MEMBANDINGKAN 2 NODE TREE ==============\n");
                printf("Masukkan node pertama: ");
                scanf(" %c", &node1);
                printf("Masukkan node kedua: ");
                scanf(" %c", &node2);
                
                if (compareNodes(P, node1, node2)) {
                    printf("Node '%c' dan '%c' memiliki struktur yang SAMA!\n", node1, node2);
                } else {
                    printf("Node '%c' dan '%c' memiliki struktur yang BERBEDA!\n", node1, node2);
                }
                
                showNodeComparison(P, node1, node2);
                KlikToContinue();
                break;
                
            case 11:
                system("cls");
                printf("\n========== TERIMA KASIH =========\n");
                printf("Program selesai. Sampai jumpa!\n");
                printf("===================================\n");
                break;
                
            default:
                printf("\nPilihan tidak valid! Silakan pilih 1-11.\n");
                KlikToContinue();
                break;
        }
        
    } while (pilihan != 11);
    
    return 0;
}
