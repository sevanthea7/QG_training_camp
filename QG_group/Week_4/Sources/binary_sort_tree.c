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
	pTNode p = T -> root;										// pΪ��ǰ�����Ľڵ� 
	pTNode q = NULL;											// qΪp����һ���ڵ� 
	while( p ){
		q = p;
		if( e < p -> data ){									// ����Ԫ�ص�ֵС�ڵ�ǰ�ڵ��ֵ��ʱ������߷�֧�ƶ���Ѱ�Ҹ�Сֵ 
			p = p -> left;
		} else if( e > p -> data ){								// ����Ԫ�ص�ֵ���ڵ�ǰ�ڵ��ֵ��ʱ�����ұ߷�֧�ƶ���Ѱ�Ҹ���ֵ
			p = p -> right;
		} else{													// ���ʱ����ʧ�� 
			printf( "������ͬԪ�أ�����ʧ�ܣ�\n" );
			free( _new );
			return ERROR;
		}
	}
	if( e < q -> data ){										// ���ҵ��ķ�֧�����һ���ڵ��ϸ��ݴ�С��ϵ�����½ڵ� 
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
		} else if( e < p -> data ){									// Ѱ��Ԫ�ص�ֵС�ڵ�ǰ�ڵ��ֵ��ʱ������߷�֧�ƶ���Ѱ�Ҹ�Сֵ 
			p = p -> left; 
		} else{														// ����Ԫ�ص�ֵ���ڵ�ǰ�ڵ��ֵ��ʱ�����ұ߷�֧�ƶ���Ѱ�Ҹ���ֵ
			p = p -> right;
		}
	}
	return ERROR;
}


pTNode BST_delete( pTNode root, EType e ){
	if( root == NULL ){
		printf( "\nû���ҵ�Ҫɾ����Ԫ�ء�\n\n" );
		return NULL;
	}
	pTNode inh;
	if( root -> left == NULL && root -> right == NULL ){ 				// ֻ��һ�����ڵ� 
        free( root );
        printf( "\nɾ���ɹ���\n\n" );
        return NULL;
    } else if( e < root -> data ){									// Ѱ��Ԫ�ص�ֵС�ڵ�ǰ�ڵ��ֵ��ʱ������߷�֧�ƶ���Ѱ�Ҹ�Сֵ
        root -> left = BST_delete( root -> left, e );
	} else if( e > root -> data ){									// ����Ԫ�ص�ֵ���ڵ�ǰ�ڵ��ֵ��ʱ�����ұ߷�֧�ƶ���Ѱ�Ҹ���ֵ
        root -> right = BST_delete( root -> right, e );
	} else{															// ��ȣ����ҵ� 
        if( root -> left == NULL && root -> right != NULL ){		// ֻ��һ������ʱ��ֱ�Ӽ̳� 
            inh = root -> right;
            free( root );
            printf( "\nɾ���ɹ�!\n\n" );
            return inh;
        } else if( root -> right == NULL && root -> left != NULL ){
            inh = root -> left;
            free( root );
            printf( "\nɾ���ɹ�!\n\n" );
            return inh;
        } else{
        	pTNode inh = root -> right;
		    while( inh && inh -> left ){
		    	inh = inh -> left;										// �ҵ�ǰ��֧����С��Ԫ�� 
			}
	        root -> data = inh -> data;									// �Ѽ̳е�Ԫ���滻��Ҫɾ����Ԫ����
	        root -> right = BST_delete( root -> right, inh -> data );	// ɾ���̳�Ԫ�صĽڵ� 
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


// ����ѡ����
int test_option( char s[30], int m ){
	int n, flag;
	do{
		flag = 1;
		n = atoi( s );
		if( n < 1 || n > m ){
        	flag = 0;
        	printf( "\nû��������ܣ�������ѡ��" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
} 


// ������������
int test_number( char s[30] ){
	int n, flag;
	do{
		flag = 1;
		if( strcmp( s, "0" ) == 0 ){
			n = 0;
			break;
		}
		if( strlen( s ) > 8 ){
			printf( "\n����̫�����������룺" );
			scanf( "%s", s );
			continue;
		}
		n = atoi( s );
		if( n == 0 ){
        	flag = 0;
        	printf( "\n�������֣����������룺" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
}

