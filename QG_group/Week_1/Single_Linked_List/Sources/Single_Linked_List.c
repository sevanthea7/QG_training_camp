#include <stdio.h>
#include <stdlib.h>
#include "../Headers/S_LinkedList.h"


int main(){
	LinkedList L;
	InitList( &L );
	CreateList( &L );
	PrintList( &L );
	PrintMenu();
	int n;
	scanf( "%d", &n );
	EType e;
	Node *q, *mid;
	do{
		switch( n ){
			case 1:
				q = ( LinkedList )malloc( sizeof( Node ) );
				printf( "please enter the data of the new node: " );
				scanf( "%d", &( q -> data ) );
				printf( "please enter the data of node before the position you want to insert the new node: " );
				scanf( "%d", &e );
				Node* p = SearchListNode( &L, e );
				InsertList( &L, p, q );
				PrintList( &L );
				break;
			case 2:
				printf( "please enter the data of the node you want to search: " );
				scanf( "%d", &e );
				SearchList( &L, e );
				break;
			case 3:
				printf( "please enter the data of the node you want to delete: " );
				scanf( "%d", &e );
				DeleteList( &L, e );
				PrintList( &L );
				break;
			case 4:
				DestroyList( &L );
				printf( "\nsuccess.\n\n" );
				break;
			case 5:
				PrintList( &L );
				break; 
			case 6:
				ExchangeOddEven( &L );
				PrintList( &L ); 
				break;
			case 7:
				mid = FindMid( &L );
				printf( "\nthe data of the middle node is %d\n", mid -> data );
				printf( "*If the list's length is even, then the result will be the previous one of the center.\n\n");
				break;
			case 8:
				IsLoop( &L );
				break; 
			case 9:
				ReverseList( &L );
				PrintList( &L ); 
				break;
			case 10:
				L = ReverseList_Recursive( &L );
				PrintList2( &L ); 
				break;
			case 0:
				return 0;
		}
		PrintMenu();
		scanf( "%d", &n );
	} while(1);
} 

// ���ܲ˵� 
void PrintMenu() {
    printf("******************************\n");
    printf("*          1.insert          *\n");
    printf("*          2.search          *\n");
    printf("*          3.delete          *\n");
    printf("*          4.destroy         *\n");
    printf("*          5.print           *\n");
    printf("*     6.exchange odd&even    *\n");
    printf("*     7.find middle node     *\n");
    printf("*      8.is loop or not      *\n");
    printf("*       9.reverse list       *\n");
    printf("*  10.reverse list recursive *\n");
    printf("******************************\n");
    printf("Enter 0 to exit.\n");
    printf("Enter the number of the function you want: ");
}

// ��ʼ�������� 
Status InitList( LinkedList *head ){
	*head = ( LinkedList )malloc( sizeof( Node ) );		// ����ͷ�ڵ㣬Ϊ������ڴ� 
	( *head ) -> next = NULL; 
	return OK;
}

// �����б���
Status CreateList( LinkedList *L ){
	*L = ( LinkedList )malloc( sizeof( Node ) );	// Ϊͷ�������ڴ� 
	LinkedList p, q;
	p = *L;											// pָ��ͷ���
	p -> next = NULL;
	int i = 1;
	while(1){
		q = ( Node* )malloc( sizeof( Node ));		// Ϊ�½ڵ�����ڴ�ռ�
		printf( "Please enter the %d element of the List(enter '-1' to stop entering): ", i );
		scanf( "%d", &q -> data );
		if( q -> data == -1 ){						// ������� -1����������벢�ͷ��½ڵ���ڴ�ռ�
			free( q );
			break;
		}
		q -> next = NULL;							// �½ڵ����һ�����Ϊ��
		p -> next = q;								// ���½ڵ����ӵ�������
		p = p -> next;								// �ƶ�pָ�뵽��һ���ڵ�
		i ++;
	}
	p -> next = NULL;								// �����һ���ڵ��nextָ����Ϊ��
	return OK;
} 

// ���ٵ����� 
Status DestroyList( LinkedList *L ){
	if( *L == NULL ){
		return ERROR;
	}
	LinkedList p = *L;		// pָ��ָ��ͷ�ڵ�
	while( *L ){
		*L = ( *L ) -> next;	// ָ��Ҫ�ͷ�Ԫ�ص�ָ��Lָ��Ҫɾ������һ�� 
		free( p );			// �ͷ�Lԭ���ڵ�λ�õ��ڴ� 
		p = *L;				// ָ��pָ���һ���ҵ�����һ��Ҫɾ���Ľ�� 
	}
	return OK; 
} 

// �������Ԫ�ز���
Status SearchList( LinkedList *L, EType e ){
	LinkedList p;
	for( p = ( *L ) -> next; p; p = p -> next ){
		if( p -> data == e ){
			printf( "\nelement found: data=%d\n\n", p -> data );
			return OK;
		}
		p = p -> next;
	}
	printf( "Not found.\n" );
	return ERROR;
} 

// �������Ԫ�ؽ����� 
Node* SearchListNode( LinkedList *L, EType e ){
	LinkedList p;
	for( p = ( *L ) -> next; p; p = p -> next ){
		if( p -> data == e ){
			return p;
		}
	}
	printf( "Not found.\n" );
	return NULL;
}

// �������Ԫ�ز���
Status InsertList( LinkedList *L, Node *p, Node *q ){
	if( *L == NULL || q == NULL || p == NULL ){	// ��������Ƿ�Ϊ�ա�ָ���Ƿ�Ϊ�� 
		return ERROR;
	}
	LinkedList m = *L; 		// mָ��ͷ��� 
	while( m != NULL ){
		if( m == p ){		// �ҵ�Ҫ����λ�� 
			q -> next = m -> next;	// ��q��nextָ��ָ��p����һ�����
			m -> next = q;	// ��p��nextָ��ָ��q
			return OK;
		}
		m = m -> next;		// mָ����һ���ڵ� 
	}
	return ERROR;
}


// ������Ԫ�ش�ӡ
Status PrintList( LinkedList *L ){
	LinkedList prt;
	if ( *L == NULL ) { 		// ��������Ƿ�Ϊ��
        return ERROR;
    }
    printf( "\n\n" );
	for( prt = ( *L ) -> next; prt; prt = prt -> next ){
		printf( "%d -> ", prt -> data );		// ������ӡ�������� 
	}
	printf( "\n\n\n" );
	return OK;
} 

Status PrintList2( LinkedList *L ){
	LinkedList prt;
	if ( *L == NULL ) { 		// ��������Ƿ�Ϊ��
        return ERROR;
    }
    printf( "\n\n" );
	for( prt = *L ; prt -> next; prt = prt -> next ){
		printf( "%d -> ", prt -> data );		// ������ӡ�������� 
	}
	printf( "\n\n\n" );
	return OK;
} 

// ������Ԫ��ɾ�� 
Status DeleteList( LinkedList *L, EType e ){
	LinkedList p, q;
	p = *L;								// pָ��ͷ���
	q = ( *L ) -> next;					// qָ���һ���ڵ�
	if( !p ){
		return ERROR;
	}
	while( q ){
		if( q -> data == e ){
			p -> next = q -> next;		// ��p��nextָ��ָ��q����һ���ڵ�
			free( q );					// �ͷ�q��ָ��ڵ���ڴ�
			return OK;
		}
		p = q;							// �ƶ�p��qָ�뵽���Ե���һ���ڵ�
		q = q -> next;
	}
	return ERROR;						// û�ҵ�Ҫɾ���� 
}


// ��������żλ����
Status ExchangeOddEven( LinkedList *L ){
	if( *L == NULL ){
		return ERROR;
	}
	LinkedList p = ( *L ) -> next;
	while( p && p -> next ){
		EType tmp = p -> data;				// �������ڽڵ�����
		p -> data = p -> next -> data;
		p -> next -> data = tmp;
		p = p -> next -> next;				// pָ���Ƶ���һ������λ
	}
	return OK;
} 

// ���м�λ��
Node* FindMid( LinkedList *L ){
	if( *L == NULL || ( *L ) -> next == NULL ){
		return *L;
	}
	LinkedList slow, fast;
	slow = *L;
	fast = *L;
	while( fast && fast -> next ){
		slow = slow -> next;
		fast = fast -> next -> next;
	} 
	return slow;
}

// �ж��Ƿ�ɻ� 
Status IsLoop( LinkedList *L ){
	if( *L == NULL || ( *L ) -> next == NULL ){
		return ERROR;
	}
	LinkedList slow, fast;
	slow = *L;
	fast = ( *L ) -> next;
	while( fast && fast -> next ){	
		if( fast == slow ){	
			printf( "\nIS LOOP.\n\n" );
			break;
		}
		slow = slow -> next;
		fast = fast -> next -> next; 
	}
	printf( "\nNOT LOOP.\n\n");
	return OK;
}

// ��ת������
Status ReverseList( LinkedList *L ){
	if( *L == NULL ){
		return ERROR; 
	} 
	LinkedList head, p, q;
	head = *L;
	p = head -> next;
	head -> next = NULL; 
	while( p ){
		q = p -> next;
		p -> next = head -> next;
		head -> next = p;
		p = q;
	}
	return OK; 
} 


// �ݹ���ת������
Node* ReverseList_Recursive( LinkedList *head ){
	if( *head == NULL || ( *head ) -> next == NULL ){
		return *head;							 		// �ݵ���ֹ����������Ϊ�ջ�ֻ��һ��Ԫ��ʱ���� 
	}
	Node* reverse_head = ReverseList_Recursive( &( ( *head ) -> next ) );
	( *head ) -> next -> next = *head;						// ͷָ�����һ��Ԫ�ص�nextָ��ָ��ͷָ�룬ʵ������Ԫ��֮���˳�򽻻� 
	( *head ) -> next = NULL;								// ͷָ���next�ÿգ���Ϊ�µ�����β
	return reverse_head; 
} 
