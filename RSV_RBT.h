#pragma once
#include"HotelSiteMatch.h"
#define BLACK 0
#define RED 1
#define MAX_ID_SIZE 30

typedef struct RSV_NODE *RSV_node_ptr;
typedef struct RSV_NODE {
	char Key[MAX_ID_SIZE]; // Key : User ID
	int InputBudget; // 입력받은 예산
	hotel_site_ptr Path;

	RSV_node_ptr left;
	RSV_node_ptr right;
	RSV_node_ptr p;
	unsigned short color : 1;
}RSV_Node;

// ===========================================================
RSV_node_ptr RSV_MakeNode(char *KEY);
void LEFT_ROTATE(RSV_node_ptr *Root, RSV_node_ptr x);
void RIGHT_ROTATE(RSV_node_ptr *Root, RSV_node_ptr x);
RSV_node_ptr TREE_SUCCESSOR(RSV_node_ptr target);
RSV_node_ptr RSV_TREE_SEARCH(RSV_node_ptr root, char *KEY);
RSV_node_ptr TREE_MIN(RSV_node_ptr root);

RSV_node_ptr Sentinel; // Global 1
void MakeSentinel();
RSV_node_ptr RSV_MakeRBT(void);
// INSERT ===========================================================
bool RSV_RB_INSERT(RSV_node_ptr *Root, char *KEY, hotel_site_ptr DATA, int InputBudget);
void RB_INSERT_FIXUP(RSV_node_ptr *Root, RSV_node_ptr z);

// DELETE===========================================================
RSV_node_ptr RSV_RB_DELETE(RSV_node_ptr *root, char *KEY);
void RB_DELETE_FIXUP(RSV_node_ptr *root, RSV_node_ptr x);

