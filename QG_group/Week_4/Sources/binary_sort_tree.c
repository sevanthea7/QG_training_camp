#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/binary_sort_tree.h"

Status BST_init( pTSort T ){
	T -> root = NULL;
	return OK;
}

Status BST_insert( pTSort T, EType e ){
	pTNode _new = ( pTNode )malloc( sizeof( TNode ) );
	_new -> left = NULL;
	_new -> right = NULL; 
	_new -> data = e;
	if( T -> root == NULL ){
		T -> root = _new;
		return OK;
	}
	pTNode p = T -> root;										// p为当前操作的节点 
	pTNode q = NULL;											// q为p的上一级节点 
	while( p ){
		q = p;
		if( e < p -> data ){									// 插入元素的值小于当前节点的值的时候，向左边分支移动，寻找更小值 
			p = p -> left;
		} else if( e > p -> data ){								// 插入元素的值大于当前节点的值的时候，向右边分支移动，寻找更大值
			p = p -> right;
		} else{													// 相等时插入失败 
			printf( "含有相同元素，插入失败！\n" );
			free( _new );
			return ERROR;
		}
	}
	if( e < q -> data ){										// 在找到的分支的最后一个节点上根据大小关系插入新节点 
		q -> left = _new;
	} else{
		q -> right = _new;
	}
	return OK;
}


Status BST_search( pTSort T, EType e ){
	if( T -> root == NULL ){
		return ERROR;
	}
	pTNode p = T -> root;
	while( p ){
		if( p -> data == e ){
			return OK;
		} else if( e < p -> data ){									// 寻找元素的值小于当前节点的值的时候，向左边分支移动，寻找更小值 
			p = p -> left; 
		} else{														// 插入元素的值大于当前节点的值的时候，向右边分支移动，寻找更大值
			p = p -> right;
		}
	}
	return ERROR;
}


pTNode BST_delete( pTNode root, EType e ){
	if( root == NULL ){
		printf( "\n没有找到要删除的元素。\n\n" );
		return NULL;
	}
	pTNode inh;
	if( root -> left == NULL && root -> right == NULL ){ 				// 只有一个根节点 
        free( root );
        printf( "\n删除成功！\n\n" );
        return NULL;
    } else if( e < root -> data ){									// 寻找元素的值小于当前节点的值的时候，向左边分支移动，寻找更小值
        root -> left = BST_delete( root -> left, e );
	} else if( e > root -> data ){									// 插入元素的值大于当前节点的值的时候，向右边分支移动，寻找更大值
        root -> right = BST_delete( root -> right, e );
	} else{															// 相等，即找到 
        if( root -> left == NULL && root -> right != NULL ){		// 只有一个孩子时，直接继承 
            inh = root -> right;
            free( root );
            printf( "\n删除成功!\n\n" );
            return inh;
        } else if( root -> right == NULL && root -> left != NULL ){
            inh = root -> left;
            free( root );
            printf( "\n删除成功!\n\n" );
            return inh;
        } else{
        	pTNode inh = root -> right;
		    while( inh && inh -> left ){
		    	inh = inh -> left;										// 找当前分支的最小的元素 
			}
	        root -> data = inh -> data;									// 把继承的元素替换到要删除的元素上
	        root -> right = BST_delete( root -> right, inh -> data );	// 删除继承元素的节点 
	        return root;
		}
	}
	return root;
}

Status visit( pTNode p ){
	if( p ){
		printf( "%d  ", p -> data );
		return OK;
	} 
}

Status BST_preorderI( pTNode root ){
	if( root ){
		visit( root );
		BST_preorderI( root -> left );
		BST_preorderI( root -> right );
	}
	return OK;
}


Status BST_inorderI( pTNode root ){
	if( root ){
		BST_inorderI( root -> left );
		visit( root );
		BST_inorderI( root -> right );
	}
	return OK;
}

Status BST_postorderI( pTNode root ){
	if( root ){
		BST_postorderI( root -> left );
		BST_postorderI( root -> right );
		visit( root );
	}
	return OK;
}


Status BST_preorderR( pTSort T ){
	if( T -> root == NULL ){
		return ERROR;
	}
	Stack S;
	InitLStack( &S );
	int e;
	pTNode p = T -> root;
	while( p || EmptyLStack( S ) ){
		if( p ){
			visit( p );
			PushLStack( S, p );
			p = p -> left;
		} else{
			PopLStack( S, &p );
			p = p -> right;
		}
	}
	return OK;
}


Status BST_inorderR( pTSort T ){
	if( T -> root == NULL ){
		return ERROR;
	}
	Stack S;
	InitLStack( &S );
	int e;
	pTNode p = T -> root;
	while( p || EmptyLStack( S ) ){
		if( p ){
			PushLStack( S, p );
			p = p -> left;
		} else{
			PopLStack( S, &p );
			visit( p );
			p = p -> right;
		}
	}
	return OK;
}


Status BST_postorderR( pTSort T ){
	if( T -> root == NULL ){
		return ERROR;
	}
	Stack S;
	InitLStack( &S );
	pTNode p = T -> root;
	pTNode q = NULL;
	while( p || EmptyLStack( S ) ){
		if( p ){
			PushLStack( S, p );
			p = p -> left;
		} else{
			GetTopElement( S, &p ); 
			if( p -> right != q && p -> right != NULL ){
				p = p -> right;
				PushLStack( S, p );
				p = p -> left;
			} else{
				PopLStack( S, &p );
				visit( p );
				q = p;
				p = NULL;
			}
		}
	}
	return OK;
}


Status BST_levelOrder( pTSort T ){
	if( T -> root == NULL ){
		return ERROR;
	}
	pTNode p;
	pQueue Q;
	InitLQueue( &Q );
	InLQueue( Q, T -> root );
	while( IsEmpty( Q ) ){
		OutLQueue( Q, &p );
		visit( p );
		if( p -> left ){
			InLQueue( Q, p -> left );
		}
		if( p -> right ){
			InLQueue( Q, p -> right );
		}
	}
	return OK;
}


Status InitLStack( Stack *S ){
	*S = ( Stack )malloc( sizeof( Stackptr ) );
	if( *S != NULL ){
		(*S) -> top = NULL;
		(*S) -> cnt = 0;
		return OK;
	}
	return ERROR;
}

Status EmptyLStack( Stack S ){
	if( S -> top == NULL ){
		return 0;
	}
	return 1; 
} 

Status PushLStack( Stack S, pTNode e ){
	LinkStack p = ( LinkStack )malloc( sizeof( SNode ) );
	if( p == NULL ){
		return ERROR;
	}
	p -> data = e;
	p -> next = S -> top;
	S -> top = p;
	S -> cnt ++;
	return OK;
}


Status PopLStack( Stack S, pTNode *e ){
    if( EmptyLStack( S ) == 0 ) {
        return ERROR;
    }
    *e = S -> top -> data;
    LinkStack tmp = S -> top;
    S -> top = S -> top -> next;
    free( tmp );
    S -> cnt --;
    return OK;
}


Status GetTopElement( Stack S, pTNode *p ){
	if( S -> top == NULL ){
        return ERROR;
    }
    *p = S -> top -> data;
    return OK;
} 



Status InitLQueue( pQueue *Q ){
	*Q = ( pQueue )malloc( sizeof( Queue ) );
	pqNode p = ( pqNode )malloc( sizeof( qNode ) );
	(*Q) -> front = p;
	(*Q) -> back = p;
	(*Q) -> back -> next = NULL;
	return OK;
}


Status InLQueue( pQueue Q, pTNode e ){
	pqNode p = ( pqNode )malloc( sizeof( qNode ) );
	p -> data = e;
	p -> next = NULL;
	Q -> back -> next = p;
	Q -> back = p;
	return OK;
}

Status OutLQueue( pQueue Q, pTNode *e ){
	pqNode p = Q -> front -> next;
	*e = p -> data;
	Q -> front -> next = p -> next;
	free( p );
	if( p == Q -> back ){
		Q -> back = Q -> front;
	} 
	return OK;
}

Status IsEmpty( pQueue Q ){
	if( Q -> front == Q -> back ){
		return 0; 
	} else{
		return 1;
	}
}


// 测试选择功能
int test_option( char s[30], int m ){
	int n, flag;
	do{
		flag = 1;
		n = atoi( s );
		if( n < 1 || n > m ){
        	flag = 0;
        	printf( "\n没有这个功能！请重新选择：" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
} 


// 测试输入数字
int test_number( char s[30] ){
	int n, flag;
	do{
		flag = 1;
		if( strcmp( s, "0" ) == 0 ){
			n = 0;
			break;
		}
		if( strlen( s ) > 8 ){
			printf( "\n数字太大，请重新输入：" );
			scanf( "%s", s );
			continue;
		}
		n = atoi( s );
		if( n == 0 ){
        	flag = 0;
        	printf( "\n不是数字，请重新输入：" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
}

