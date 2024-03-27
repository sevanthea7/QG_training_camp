#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/stack_calculator.h"
#include "./Stack_Calculator.c"

int main(){
	char s[30];
	int k, n, e, len, r;
	Stack S;
    InitLStack( &S );							// ��ʼ����ջ
    printf("***************************\n");
	printf("*        1.��ջ           *\n");
	printf("*        2.������         *\n");
	printf("***************************\n");
	printf( "��ѡ����Ҫ�Ĺ��ܣ�");
	scanf( "%s", s );
	k = test_option( s, 2 ); 					// �ж��û�ѡ��Ĺ���
	if( k == 1 ){
		while(1){
			again:
			printf("********************************\n");
			printf("*     	   1.Ԫ����ջ          *\n");
		    printf("*          2.Ԫ�س�ջ          *\n");
		    printf("*       3.�ж�ջ�Ƿ�Ϊ��       *\n");
		    printf("*         4.ȡջ��Ԫ��         *\n");
		    printf("*          5.���ջ            *\n");
		    printf("*          6.����ջ            *\n");
		    printf("*        7.���ջ�ĳ���        *\n");
		    printf("*        8.���³�ʼ��ջ        *\n");
		    printf("*          9.��ӡջ            *\n");
		    printf("*         10.�˳�����          *\n");
		    printf("********************************\n");
		    printf("��ѡ����Ҫ�Ĺ��ܣ�");
		    scanf( "%s", s );
			k = test_option( s, 10 ); 
			switch( k ){
				case 1:
					if( S == NULL ){
						printf( "ջ�����٣������³�ʼ��ջ��\n" ); 
						goto again;
					}
					while(1){
						printf( "��������ջ�ĵ�%d��Ԫ��(Element Type: int)������xֹͣ��ջ��", ( S -> cnt + 1 ) );
						scanf( "%s", s );
						if( strcmp( s, "x" ) == 0 ){
							break;
						} 
						n = test_number( s );
						PushLStack( S, n );
					}
					break;
				case 2:
					r = EmptyLStack( S );
					if ( r == 0 ){
						printf( "ջΪ�գ�û�п��Գ�ջ��Ԫ�ء�\n" );
						goto again;
					} else if( r == -1 ){
						goto again;
					}
					PopLStack( S, &e );
					printf( "ջ��Ԫ��%d��ջ�ɹ���\n", e );
					break;
				case 3:
					r = EmptyLStack( S );
					if( r == 1 ){
						printf( "\n************ջ��Ϊ��************\n\n" );
					} else if( r == 0 ) {
						printf( "\n*************ջΪ��*************\n\n" );
					}
					break;
				case 4:
					r = EmptyLStack( S );
					if ( r == 0 ){
						printf( "ջΪ�գ�û�п�ȡ��Ԫ�ء�\n" );
						goto again;
					} else if( r == -1 ){
						goto again;
					}
					GetTopElement( S, &e );
					printf( "ջ��Ԫ��Ϊ��%d\n", e );
					break;
				case 5:
					r = EmptyLStack( S );
					if ( r == 0 ){
						printf( "ջ��Ϊ�ա�\n" );
						goto again; 
					}else if( r == -1 ){
						goto again;
					}else if( ClearStack( S ) == 1 ){
						printf( "��ճɹ���" ); 
					}
					break;
				case 6:
					if( DestroyStack( &S ) == 1 ){
						printf("���ٳɹ���\n" );
					}
					break;
				case 7:
					if( S == NULL ){
						printf( "ջ�����٣������³�ʼ��ջ��\n" ); 
						goto again;
					} else {
						len = GetLength( S );
						printf( "ջ�ĳ���Ϊ��%d\n", len );
					}
					break;
				case 8: 
					if( S != NULL ){
						printf( "ջ����Ҫ��ʼ������ֱ�Ӳ�����\n" ); 
						goto again;
					}
					InitLStack( &S );
					printf("��ʼ���ɹ���\n");
					break;
				case 9: 
					if ( EmptyLStack( S ) == 0 ){
						printf( "ջΪ�գ�û�пɴ�ӡԪ�ء�\n" );
						goto again;
					}
					PrintStack( S );
					break;
				case 10:
					return 0;
			}
		}
	} else {
		do{
			char f[256] = { 0 };
		    char postf[512] = { 0 };
		    printf( "��������ʽ(����xͣ�˳�����)��");
		    scanf( "%s", f );
		    if( strcmp( f, "x" ) == 0 ){
		    	break;
			} 
			ClearStack( S );
			r = transform( f, postf );
		    if( r == 1 ){
		        printf("��׺���ʽ��%s\n", postf );
			    r = calculate( S, postf );
			    if( r == 1 ){
			    	int ans;
				    GetTopElement( S, &ans );
				    printf( "%s=%d\n", f, ans );
				}
			}
		} while( 1 );
		
	}
    return 0;
}
