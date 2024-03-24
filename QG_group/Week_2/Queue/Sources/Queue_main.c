#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/LinkQueue.h"
#include "./Link_Queue.c"

int main(){
	char s[30];
	int k, e, r, n, len;
	int cnt = 1;
	pQueue Q;
	InitLQueue( &Q ); 
	while(1){
			again:
			printf("********************************\n");
			printf("*     	   1.Ԫ�����          *\n");
		    printf("*          2.Ԫ�س���          *\n");
		    printf("*       3.�ж϶��Ƿ�Ϊ��       *\n");
		    printf("*         4.ȡ����Ԫ��         *\n");
		    printf("*          5.��ն�            *\n");
		    printf("*          6.���ٶ�            *\n");
		    printf("*        7.���ӵĳ���        *\n");
		    printf("*        8.���³�ʼ����        *\n");
		    printf("*          9.��ӡ��            *\n");
		    printf("*         10.�˳�����          *\n");
		    printf("********************************\n");
		    printf("��ѡ����Ҫ�Ĺ��ܣ�");
		    scanf( "%s", s );
			k = test_option( s, 10 ); 
			switch( k ){
				case 1:
					if( Q == NULL ){
						printf( "\n���������٣������³�ʼ�����У�\n\n" ); 
						goto again;
					}
					while(1){
						printf( "��������еĵ�%d��Ԫ��(Element Type: int)������xֹͣ��ӣ�", cnt );
						scanf( "%s", s );
						if( strcmp( s, "x" ) == 0 ){
							break;
						} 
						n = test_number( s );
						InLQueue( Q, n );
						cnt ++;
					}
					break;
				case 2:
					if( Q == NULL ){
						printf( "\n���������٣������³�ʼ�����У�\n\n" ); 
						goto again;
					}
					OutLQueue( Q, &e );
					cnt --;
					printf( "\n����Ԫ��%d���ӳɹ���\n\n", e );
					break;
				case 3:
					if( Q == NULL ){
						printf( "\n���������٣������³�ʼ�����У�\n\n" ); 
						goto again;
					}
					r = IsEmpty( Q );
					if( r == 1 ){
						printf( "\n************�Ӳ�Ϊ��************\n\n" );
					} else if( r == 0 ) {
						printf( "\n*************��Ϊ��*************\n\n" );
					}
					break;
				case 4:
					if( Q == NULL ){
						printf( "\n���������٣������³�ʼ�����У�\n\n" ); 
						goto again;
					}
					GetHeadElement( Q, &e );
					printf( "\n����Ԫ��Ϊ��%d\n\n", e );
					break;
				case 5:
					if( Q == NULL ){
						printf( "\n���������٣������³�ʼ�����У�\n\n" ); 
						goto again;
					}
					if( ClearLQueue( Q ) == 1 ){
						printf( "\n��ճɹ���\n\n" ); 
					}
					break;
				case 6:
					if( Q == NULL ){
						printf( "\n�����Ѳ����ڣ��������٣�\n\n" ); 
						goto again;
					}
					if( DestroyLQueue( &Q ) == 1 ){
						printf("\n���ٳɹ���\n\n" );
					}
					break;
				case 7:
					if( Q == NULL ){
						printf( "\n���������٣������³�ʼ�����У�\n\n" ); 
						goto again;
					}
					len = GetLength( Q );
					printf( "\nջ�ĳ���Ϊ��%d\n\n", len-1 );
					break;
				case 8: 
					if( Q != NULL ){
						printf( "\n���в���Ҫ��ʼ������ֱ�Ӳ�����\n\n" ); 
						goto again;
					}
					InitLQueue( &Q );
					printf( "\n��ʼ���ɹ���\n\n" );
					break;
				case 9: 
					if( Q == NULL ){
						printf( "\n���������٣������³�ʼ�����У�\n\n" ); 
						goto again;
					}
					PrintLQueue( Q );
					break;
				case 10:
					return 0;
			}
		}
}
