#pragma once

#define BLACK 0
#define RED 1


typedef struct HT_RBNODE *HT_RBnode_ptr;
typedef struct HT_RBNODE {
	int Key; // Price
	int Hotel_Num; // hotel Num 
	HT_RBnode_ptr left;
	HT_RBnode_ptr right;
	HT_RBnode_ptr p;
	unsigned short color : 1;
}HT_RBNode;

// ===========================================================
HT_RBnode_ptr HT_MakeRBNode(int KEY, int hotelNum);
void HT_LEFT_ROTATE(HT_RBnode_ptr *Root, HT_RBnode_ptr x);
void HT_RIGHT_ROTATE(HT_RBnode_ptr *Root, HT_RBnode_ptr x);
HT_RBnode_ptr HT_TREE_SUCCESSOR(HT_RBnode_ptr target);
HT_RBnode_ptr HT_TREE_PREDECESSOR(HT_RBnode_ptr target);
HT_RBnode_ptr HT_TREE_SEARCH(HT_RBnode_ptr root, int KEY);
HT_RBnode_ptr HT_TREE_MIN(HT_RBnode_ptr root);
HT_RBnode_ptr HT_TREE_MAX(HT_RBnode_ptr root);

HT_RBnode_ptr HT_Sentinel; // Global 1
void HT_MakeSentinel();
HT_RBnode_ptr HT_MakeRBT(void);
// INSERT ===========================================================
bool HT_RB_INSERT(HT_RBnode_ptr *Root, int KEY, int hotelNum);
void HT_RB_INSERT_FIXUP(HT_RBnode_ptr *Root, HT_RBnode_ptr z);

// DELETE===========================================================
HT_RBnode_ptr HT_RB_DELETE(HT_RBnode_ptr *root, int KEY);
void HT_RB_DELETE_FIXUP(HT_RBnode_ptr *root, HT_RBnode_ptr x);

