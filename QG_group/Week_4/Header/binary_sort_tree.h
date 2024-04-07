#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H


// ¶¨Òå·µ»Ø×´Ì¬ 
#define OK 1
#define ERROR 0
typedef int Status;


typedef int EType;


typedef struct node{
    EType data;
    struct node *left, *right;
} TNode, *pTNode;

typedef struct BiSortTree{
    pTNode root;
} TSort, *pTSort;

Status BST_init( pTSort T );
pTNode BST_delete( pTNode root, EType e ); 
Status BST_search( pTSort T, EType e );
Status BST_preorderI( pTNode root );
Status BST_preorderR( pTSort T );
Status BST_inorderI( pTNode root );
Status BST_inorderR( pTSort T );
Status BST_postorderI( pTNode root );
Status BST_postorderR( pTSort T );
Status BST_levelOrder( pTSort T );

typedef struct _node{
	pTNode data;
	struct _node *next;
}qNode, *pqNode;

typedef struct LinkQueue{
	pqNode front;
	pqNode back;
}Queue, *pQueue;


Status InitLQueue( pQueue *Q );
Status IsEmpty( pQueue Q );
Status InLQueue( pQueue Q, pTNode e );
Status OutLQueue( pQueue Q, pTNode *e );


typedef struct _node1{
	pTNode data;
	struct _node1 *next;
}SNode, *LinkStack;


typedef struct _stack{
	LinkStack top;
	int cnt;
}*Stack, Stackptr;


int test_option( char s[30], int m );
int test_number( char s[30] );
Status InitLStack( Stack *S );
Status EmptyLStack( Stack S );
Status PushLStack( Stack S, pTNode e );
Status PopLStack( Stack S, pTNode *e );
Status GetTopElement( Stack S, pTNode *e );


#endif 
