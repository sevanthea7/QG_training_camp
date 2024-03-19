#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/LinkedList.h"


int main(){
	int flag;
	char s[30];
	int n, k;

	printf("***************************\n");
	printf("*        1.Single         *\n");
	printf("*        2.Double         *\n");
	printf("***************************\n");
	printf( "Please choose the linked list you want: ");
	scanf( "%s", s );
	k = test_number( s );
	if( k == 1 ){
		LinkedList L;
		InitList( &L );
		CreateList( &L );
		PrintList( &L );
		EType e;
		Node *q, *mid;
		do{
			do{
				PrintMenu();
				if( strcmp( s, "0" ) == 0 ){
	     	  		return 0;
	    		}
				flag = 1;
				scanf( "%s", s );
				n = atoi( s );
				if( n <= 0 || n > 10 ){
	        		flag = 0;
	        		printf( "\nNot an option! Retry:\n\n" );
	    		}
			}while( flag == 0 );
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
			}
		} while(1);
	} else {
		DLinkedList L, head;
		int n;
		char s[30];
		InitDList( &L );
		
		printf("******************************\n");
		printf("*        1.create(head)      *\n");
		printf("*        2.create(tail)      *\n");
		printf("******************************\n");
		printf( "Please choose a way to create the list: ");
		scanf( "%s", s );
		k = test_numberD( s );

		switch( k ){
			case 1:
				CreateList_Head( &L );
				break;
			case 2:
				CreateList_Tail( &L );
				break;
		}
		do{
			PrintMenuD();
			if( strcmp( s, "0" ) == 0 ){
		    	return 0;
		    }
			flag = 1;
			scanf( "%s", s );
			n = atoi( s );
			if( n <= 0 || n > 6 ){
		        flag = 0;
		        printf( "\nNot an option! Retry:\n\n" );
		    }
		}while( flag == 0 );
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
			}
			PrintMenu();
			scanf( "%d", &n );
		} while(1);
	}
	return 0;
} 


int test_number( char s[30] ){
	int n, flag;
	do{
		flag = 1;
		if( strcmp( s, "0" ) == 0 ){
			n = 0;
			break;
		}
		n = atoi( s );
		if( n != 1 && n != 2 ){
        	flag = 0;
        	printf( "\nNot a choice! Reenter:\n\n" );
			printf("***************************\n");
			printf("*        1.Single         *\n");
			printf("*        2.Double         *\n");
			printf("***************************\n");
			printf( "Please choose the linked list you want: ");
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
}
int test_numberD( char s[30] ){
	int n, flag;
	do{
		flag = 1;
		if( strcmp( s, "0" ) == 0 ){
			n = 0;
			break;
		}
		n = atoi( s );
		if( n != 1 && n != 2 ){
        	flag = 0;
        	printf( "\nNot a choice! Reenter:\n\n" );
			printf("******************************\n");
			printf("*        1.create(head)      *\n");
			printf("*        2.create(tail)      *\n");
			printf("******************************\n");
			printf( "Please choose a way to create the list: ");
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
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


// ������������ 
int test_number_list( char s[30], int i ){
	int n, flag;
	do{
		flag = 1;
		if( strcmp( s, "0" ) == 0 ){
			n = 0;
			break;
		}
		n = atoi( s );
		if( n == 0 ){
        	flag = 0;
        	printf( "\nNot a number! Reenter:\n\n" );
    		printf( "Please enter the %d element of the List(enter '-1' to stop entering): ", i );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;	
}


// ������������
Status CreateList( LinkedList *L ){
	char s[30]; 
	int n; 
	*L = ( LinkedList )malloc( sizeof( Node ) );	// Ϊͷ�������ڴ� 
	LinkedList p, q;
	p = *L;											// pָ��ͷ���
	p -> next = NULL;
	int i = 1;
	while(1){
		q = ( Node* )malloc( sizeof( Node ));		// Ϊ�½ڵ�����ڴ�ռ�
		printf( "Please enter the %d element of the List(enter '-1' to stop entering): ", i );
		scanf( "%s", s );
		n = test_number_list( s, i );
		if( n == -1 ){						// ������� -1����������벢�ͷ��½ڵ���ڴ�ռ�
			free( q );
			break;
		}
		q -> data = n;
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



// ���ܲ˵� 
void PrintMenuD(){
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
	int n;
	char s[30];
	*L = ( DLinkedList )malloc( sizeof( DNode ) );
	p = *L;
	p -> next = NULL;
	p -> prev = NULL;
	int i = 1;
	while(1){
		q = ( DLinkedList )malloc( sizeof( DNode ) );
		printf( "Please enter the %d element of the List(enter '-1' to stop entering): ", i );
		scanf( "%s", s );
		n = test_number_list( s, i );
		if( n == -1 ){						// ������� -1����������벢�ͷ��½ڵ���ڴ�ռ�
			free( q );
			break;
		}
		q -> data = n;
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




