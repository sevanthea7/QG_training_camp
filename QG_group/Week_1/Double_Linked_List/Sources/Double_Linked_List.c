#include <stdio.h>
#include <stdlib.h>
#include "../Headers/D_LinkedList.h"


int main(){
	DLinkedList L, head;
	int n;
	InitDList( &L );
	printf("******************************\n");
    printf("*        1.create(head)      *\n");
	printf("*        2.create(tail)      *\n");
	printf("******************************\n");
	printf( "Please choose a way to create the list: ");
	scanf( "%d", &n );
	switch( n ){
		case 1:
			CreateList_Head( &L );
			break;
		case 2:
			CreateList_Tail( &L );
			break;
	}
	PrintMenu();
	scanf( "%d", &n );
	EType e;
	DNode *q;
	do{
		switch( n ){
			case 1:
				q = ( DLinkedList )malloc( sizeof( DNode ) );
				printf( "please enter the data of the new node: " );
				scanf( "%d", &( q -> data ) );
				printf( "please enter the data of node before the position you want to insert the new node: " );
				scanf( "%d", &e );
				DNode* p = SearchDListNode( &L, e );
				if (p != NULL) {
                    InsertDList(&L, p, q);
                    PrintDList(&L);
                } else {
                    printf("Node not found.\n");
                }
				break;
			case 2:
				printf( "please enter the data of the node you want to search: " );
				scanf( "%d", &e );
				SearchDList( &L, e );
				break;
			case 3:
				printf( "please enter the data of the node you want to delete: " );
				scanf( "%d", &e );
				DeleteDList( &L, e );
				PrintDList( &L );
				break;
			case 4:
				DestroyDList( &L );
				printf( "\nsuccess.\n\n" );
				break;
			case 5:
				PrintDList( &L );
				break;
			case 6:
				PrintDList_reverse( &L );
				break; 
			case 0:
				return 0;
		}
		PrintMenu();
		scanf( "%d", &n );
	} while(1);
} 


// ���ܲ˵� 
void PrintMenu(){
    printf("******************************\n");
    printf("*          1.insert          *\n");
    printf("*          2.search          *\n");
    printf("*          3.delete          *\n");
    printf("*          4.destroy         *\n");
    printf("*          5.print           *\n");
    printf("*       6.print(reverse)     *\n");
    printf("******************************\n");
    printf("Enter 0 to exit.\n");
    printf("Enter the number of the function you want: ");
}


// ˫�����ʼ��
Status InitDList( DLinkedList *head ){
    *head = ( DLinkedList )malloc( sizeof( DNode ) );
	( *head ) -> next = NULL;
	( *head ) -> prev = NULL;
	return OK;
}


// ˫���������
Status DestroyDList( DLinkedList *L ){
	if( *L == NULL ){
		return ERROR;
	}
	DLinkedList p = *L;
	while( p ){
		*L = ( *L ) -> next;
		free( p );
		p = *L;
	}
	return OK;
}


// �����ӡ˫����
void PrintDList( DLinkedList *L ){
    DLinkedList prt;
    printf("\n\n");
    for( prt = ( *L ) -> next; prt; prt = prt -> next ){
    	printf( "%d <-> ", prt -> data );
	}
    printf("\n\n\n");
}


// �����ӡ˫����
void PrintDList_reverse( DLinkedList *L ){
    DLinkedList tail = *L;
    while( tail -> next != NULL ){
        tail = tail -> next;
    }
    printf("\n\n");
    while( tail != *L ){
        printf( "%d <-> ", tail -> data );
        tail = tail -> prev;
    }
    printf("\n\n\n");
}


// ͷ�巨���� 
Status CreateList_Head( DLinkedList * L){
    DLinkedList p, q;
    *L = ( DLinkedList )malloc( sizeof( DNode ) );
    p = *L;				// ָ��pʼ��ָ��ͷ��� 
    p -> next = NULL; 
    EType e;
    int i = 1;
    while(1){
        q = ( DLinkedList )malloc( sizeof( DNode ) );
        printf( "Please enter the %d element of the List(enter '-1' to stop entering): ", i );
		scanf( "%d", &( q -> data ) );
		if( q -> data == -1 ){
			free( q );			// �ͷŲ���Ҫ�Ľڵ��ڴ�
			break;
		}
        q -> next = p -> next; // ���½ڵ�嵽����ͷ��
        if( p -> next != NULL ){
            p -> next -> prev = q; // ԭͷ�ڵ����һ���ڵ��ǰһ���ڵ�ָ���½ڵ�
        }
        q -> prev = p; // �½ڵ��ǰһ���ڵ�ָ��ͷ�ڵ�
        p -> next = q; // ͷ�ڵ����һ���ڵ�ָ���½ڵ�
        i ++;
	}
	return OK;
}


// β�巨���� 
Status CreateList_Tail( DLinkedList *L ){
	DLinkedList p, q;
	*L = ( DLinkedList )malloc( sizeof( DNode ) );
	p = *L;
	p -> next = NULL;
	p -> prev = NULL;
	int i = 1;
	while(1){
		q = ( DLinkedList )malloc( sizeof( DNode ) );
		printf( "Please enter the %d element of the List(enter '-1' to stop entering): ", i );
		scanf( "%d", &( q -> data ) );
		if( q -> data == -1 ){
			free( q );			// �ͷŲ���Ҫ�Ľڵ��ڴ�
			break;
		}
		q -> next = NULL;
		p -> next = q;			// ���½ڵ����ӵ�����ĩβ
		q -> prev = p;			// �����½ڵ��ǰ��ָ��
		p = p -> next;			// �ƶ�����һ���ڵ�
		i ++; 
	}
	return OK;
} 


// ɾ���ڵ�
Status DeleteDList( DLinkedList *L, EType e ){
	if( *L == NULL ){
		return ERROR;
	} 
	DLinkedList p, q;
	p = *L;
	q = ( *L ) -> next;
	while( q ){							// �����������Ҫɾ���Ľڵ�
		if( q -> data == e ){
			p -> next = q -> next;		// ��Ҫɾ���Ľڵ��������ȥ�� 
			if( p -> next != NULL ){
				q -> next -> prev = p;	// ������һ���ڵ��ǰ��ָ��		
			}
			free( q );					// �ͷ�ɾ���ڵ���ڴ�
			return OK;
		}
		p = q;
		q = q -> next;
	}
	return ERROR;						// û�ҵ� 
} 


// Ԫ�ز���
Status SearchDList( DLinkedList *L, EType e ){
	DLinkedList p;
	for( p = ( *L ) -> next; p; p = p -> next ){
		if( p -> data == e ){
			printf( "\nelement found: data=%d\n\n", p -> data );
			return OK;
		}
	}
	printf( "Not found.\n" );
	return ERROR;
} 


// Ԫ�ؽ����� 
DNode* SearchDListNode( DLinkedList *L, EType e ){
	DLinkedList p;
	for( p = ( *L ) -> next; p; p = p -> next ){
		if( p -> data == e ){
			return p;
		}
	}
	printf( "Not found.\n" );
	return NULL;
}

// Ԫ�صĲ���
Status InsertDList( DLinkedList *L, DNode *p, DNode *q ){
	if( *L == NULL || q == NULL || p == NULL ){	// ��������Ƿ�Ϊ�ա�ָ���Ƿ�Ϊ�� 
		return ERROR;
	}
	DLinkedList m = *L; 		// mָ��ͷ��� 
	while( m != NULL ){
		if( m == p ){		// �ҵ�Ҫ����λ�� 
			q -> next = m -> next;	// ��q��nextָ��ָ��p����һ�����
			m -> next = q;	// ��p��nextָ��ָ��q
			q -> prev = m;
            if (q -> next != NULL) {
                q -> next -> prev = q;
            }
			return OK;
		}
		m = m -> next;		// mָ����һ���ڵ� 
	}
	return ERROR;
}




