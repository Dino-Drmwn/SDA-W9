#ifndef nbtrees_h
#define nbtrees_h

#include "boolean.h"

#define jml_maks 20
#define kebawah  1
#define keatas   2
#define kekanan  3
#define nil 0

typedef char infotype;
typedef int address;

typedef struct {
    infotype info;       // Informasi yang disimpan dalam node
    address ps_fs;       // Pointer ke First Son (anak pertama)
    address ps_nb;       // Pointer ke Next Brother (saudara berikutnya)
    address ps_pr;       // Pointer ke Parent (orangtua)
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

// Fungsi dasar tree
void Create_tree(Isi_Tree X, int Jml_Node);
boolean IsEmpty(Isi_Tree P);

// Fungsi traversal
void PreOrder(Isi_Tree P, int pos);
void InOrder(Isi_Tree P, int pos);
void PostOrder(Isi_Tree P, int pos);
void Level_order(Isi_Tree X, int Maks_node);

// Fungsi output dan pencarian
void PrintTree(Isi_Tree P, int Jml_Node);
boolean Search(Isi_Tree P, infotype X);

// Fungsi analisis tree
int nbElmt(Isi_Tree P);
int nbDaun(Isi_Tree P);
int Level(Isi_Tree P, infotype X);
int Depth(Isi_Tree P);

// Fungsi perbandingan 2 node dalam tree yang sama
boolean compareNodes(Isi_Tree P, infotype node1, infotype node2);
void showNodeComparison(Isi_Tree P, infotype node1, infotype node2);

// Fungsi utilitas
int Max(int a, int b);
void ilustrasiTree();

#endif
