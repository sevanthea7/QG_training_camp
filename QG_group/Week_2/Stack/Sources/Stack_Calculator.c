#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/stack_calculator.h"


// ������������
int operate_cal( int left, int right, char opr ){
	switch( opr ){
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			if( right == 0 ){		// ����Ϊ0ʱ����Ϊ����
				return 999999; 
			}
			return left / right;
		default:
			break;
	}
}


// �����׺���ʽ
Status calculate( Stack S, char pf[512] ){
	char num[6];
	int i = 0;
	EType e;
	while( pf[i] ){
		int j = 0;
		if( is_number( pf[i] ) ){
			while( is_number( pf[i] ) ){			// ѭ�������������֣���֤��λ��������ջ 
				num[j] = pf[i];
				j ++;
				i ++;
			}
			num[j] = '\0';
			PushLStack( S, atoi( num ) );			// ����λ��������ջ
		} else if( is_operator( pf[i] ) ){
			if( GetLength( S ) < 2 ){				// ���������ֲ�����λ������ 
                printf( "�����ʽ�Ӳ��Ϲ淶��\n" );
                return ERROR;
            }
			PopLStack( S, &e );
			int right = e;							// ������һ��ջ��Ԫ�� 
			PopLStack( S, &e );
			int left = e;							// �����ڶ���ջ��Ԫ�� 
			int ans = operate_cal( left, right, pf[i] );	// �Ⱥ���м��� 
			if( ans == 999999 ){
				printf( "�����ʽ�Ӳ��Ϲ淶��\n" );
    			return ERROR;
			}
   			PushLStack( S, ans );					// ����������ѹ��ջ 
		} else if( pf[i] == ' ' ){
			continue;
		} else{
			printf( "�����ʽ�Ӳ��Ϲ淶��\n" );
			return ERROR;
		}
		i ++;
	}
	if( GetLength( S ) != 1 ){						// ���ʣ�µĲ���һ��Ԫ�أ����� 
        printf( "�����ʽ�Ӳ��Ϲ淶��\n" );
        return ERROR;
    }
	return OK;
}


// ת����׺���ʽΪ��׺���ʽ
Status transform( char f[256], char postf[512] ){
	Stack S;
	EType e;
	int i;
	int j = 0;
	InitLStack( &S );
	for( i = 0; f[i]; i ++ ){
		if( is_number( f[i] ) ){
			postf[j ++] = f[i];
			while (is_number(f[i + 1])) {			// �����һ���ַ��Ƿ�Ϊ���֣�ѭ�������λ�� 
		        i++;
		        postf[j++] = f[i];
		    }
    		postf[j++] = ' ';						 // ����֮����ӿո� 
		} else if ( f[i] == '(' ){
			PushLStack( S, f[i] );
		} else if ( f[i] == ')' ){
			PopLStack( S, &e );
			while( e != '(' ){						//���ϵ����������ֱ��������Ӧ�������� 
                postf[j ++] = e;
                if( EmptyLStack( S ) == 0 ){
                	printf( "�����ʽ�Ӳ��Ϲ淶��\n" );
    				return ERROR;
				}
                PopLStack( S, &e );
            }	
		} else if( is_operator( f[i] ) ){
			if( f[i+1] == '0' && f[i] == '/' ){		// 0������������ 
               	printf( "�����ʽ�Ӳ��Ϲ淶��\n" );
    			return ERROR;
            }
			while ( EmptyLStack( S ) ){
				if( priority( f[i] ) <= priority( S -> top -> data ) ){	// ��������ȼ�Сʱ���� 
					PopLStack( S, &e );
	                postf[j ++] = e;
	                postf[j ++] = ' ';
				} else{
					break;
				}
            }
            PushLStack( S, f[i] );
		}else if( f[i] == ' '){
			continue;
		}else {
			printf( "�����ʽ�Ӳ��Ϲ淶��\n" );
    		return ERROR;
		}
	}
	while( EmptyLStack( S ) && PopLStack( S, &e ) ){					// ʣ�����ݳ�ջ 
        postf[j ++] = e;
    }
    postf[j] = '\0';
    return OK;
	
}


int is_number( char x ){
	if( x <= '9' && x >= '0' ){
		return 1;
	}
	return 0;
}


int is_operator( char x ){
	if( x == '+' || x == '-' || x == '*' || x == '/' ){
		return 1;
	}
	return 0;
}


int priority( char x ){
	if( x == '+' || x == '-' ){
		return 1;
	}else if( x == '*' || x == '/' ){
		return 2;
	}
	return 0;
}


// �ж��Ƿ�Ϊ��ջ
Status EmptyLStack( Stack S ){
	if( S == NULL ){
		printf( "ջ�����٣������³�ʼ��ջ��\n" ); 
		return WRONG;
	}
	if( S -> top == NULL ){
		return 0;
	}
	return 1; 
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
		n = atoi( s );
		if( n == 0 ){
        	flag = 0;
        	printf( "\nNot a number! Reenter:" );
    		scanf( "%s", s ); 
    	}
	}while( flag == 0 );
	return n;
}

// ��ʼ��ջ 
Status InitLStack( Stack *S ){
	*S = ( Stack )malloc( sizeof( Stackptr ) );
	if( *S != NULL ){
		(*S) -> top = NULL;
		(*S) -> cnt = 0;
		return OK;
	}
	return ERROR;
}


// Ԫ����ջ 
Status PushLStack( Stack S, EType e ){
	if( S == NULL ){
		printf( "ջ�����٣������³�ʼ��ջ��\n" ); 
		return WRONG;
	}
	LinkStack p = ( LinkStack )malloc( sizeof( Node ) );// �����½ڵ�
	if( p == NULL ){
		return ERROR;
	}
	p -> data = e;										// ��Ҫ��ջ��Ԫ�ظ�ֵ���½ڵ��������
	p -> next = S -> top;								// ���½ڵ���뵽ջ��	
	S -> top = p;										// ����ջ��ָ��
	S -> cnt ++;										// ջ��Ԫ��������һ
	return OK;
}

// Ԫ�س�ջ 
Status PopLStack( Stack S, EType *e ){
	if( S == NULL ){
		printf( "ջ�����٣������³�ʼ��ջ��\n" ); 
		return WRONG;
	}
	LinkStack tmp = S -> top;							// �ݴ�ջ��ָ��
	*e = tmp -> data;									// ��ջ��Ԫ�ظ�ֵ������Ĳ���
	S -> top = tmp -> next;								// ջ��ָ��ָ����һ��Ԫ��
	free( tmp );										// �ͷ�ջ��Ԫ����ռ�ڴ�
	S -> cnt --;										// ջԪ��������һ
	return OK;
}

// ȡջ��Ԫ�� 
Status GetTopElement( Stack S, EType *e ){
	if( S == NULL ){
		printf( "ջ�����٣������³�ʼ��ջ��\n" ); 
		return WRONG;
	}
	if( S -> top == NULL ){
        return ERROR;
    }
    *e = S -> top -> data;								// ��ջ��Ԫ�ظ�ֵ������Ĳ���
    return OK;
} 


// ���ջ�ĳ���
int GetLength( Stack S ){
	return  S -> cnt;
} 


// ���ջ
Status ClearStack( Stack S ){
	if( S == NULL ){
		printf( "ջ�����٣������³�ʼ��ջ��\n" ); 
		return WRONG;
	}
	LinkStack p = S -> top;
	while( p ){
		LinkStack tmp = p;
		p = p -> next;
		free( tmp );									// �ͷ�ÿ��ջԪ����ռ�ڴ�
	}
	S -> top = NULL;									// ��ջ��ָ���ÿ�
	S -> cnt = 0;										// ��ջ��Ԫ��������Ϊ0
	return OK;
} 


// ����ջ
Status DestroyStack( Stack *S ){
	if( *S == NULL ){
		printf( "ջ�����ڣ������³�ʼ��ջ��\n" ); 
		return WRONG;
	}
	ClearStack( *S );									// ���ջ
	free( *S );											// �ͷ�ջ��ռ�ڴ�
	*S = NULL;											// ��ջָ���ÿ�
	return OK;
}

// ��ӡջ 
Status PrintStack( Stack S ){
	if( S == NULL ){
		printf( "ջ�����٣������³�ʼ��ջ��\n" ); 
		return WRONG;
	}
	LinkStack p = S -> top;
	printf("\n");
	while( p ){
		printf( "|____%d____|\n", p -> data );
		p = p -> next;
	}
	printf("\n");
	return OK;
}

