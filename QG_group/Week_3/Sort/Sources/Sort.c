#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/Sort.h"


int Menu1(){
	char s[30];
	int k;
	printf("********************************\n");
	printf("*     	   1.��������          *\n");
	printf("*          2.�鲢����          *\n");
	printf("*        3.��������-�ݹ�       *\n");
	printf("*       4.��������-�ǵݹ�      *\n");
	printf("*          5.��������          *\n");
	printf("*        6.������������        *\n");
	printf("*          7.�˳�����          *\n");
	printf("********************************\n");
	printf("��ѡ����Ҫ�Ĺ��ܣ�");
	scanf( "%s", s );
	k = test_option( s, 7 );
	return k;
}

void generate( int *a, int len ){
	int i;
    for( i = 0; i < len; i ++ ){
        a[i] = rand() % MAX;									// ����MAX��Χ�ڵ������ 
    }
}

Status print( int* a, int len ){
	if( len <= 0 ){
		return ERROR;
	}
	int i;
	for( i = 0; i < len; i ++ ){
		printf( "%d ", a[i] );
	}
	printf( "\n" );
	return OK; 
}

Status InsertSort( int* a, int len ){
	int i = 0, last;
	int insert;
	if( len <= 0 ){
		printf( "����Ϊ�գ�\n" );
		return ERROR;
	}
	for( i = 0; i < len - 1; i ++ ){
		last = i;												
		insert = a[last+1];										// �洢Ҫ�������ֵ����� 
		while( last >= 0 && ( insert < a[last] ) ){				// ������Ҫ��������һλ 
			a[last+1] = a[last];
			last --;
		}
		a[last+1] = insert;										//����λ����Ĵ洢������ 
	}
	return OK;
}


void Merge( int *a, int head, int mid, int tail ){
    int m = mid - head + 1;
    int n = tail - mid;
    int h[m], t[n];
	int i, j;
    for( i = 0; i < m; i ++ ){
    	h[i] = a[head+i];
	}
    for( i = 0; i < n; i ++ ){
    	t[i] = a[mid+1 +i];
	}
	i = 0, j = 0;
	int k = head;
    while( i < m && j < n ){
        if( h[i] <= t[j] ){								// �����ְ�˳�����αȽϺ���һ�� 
            a[k] = h[i];
            i ++;
        } else {
            a[k] = t[j];
            j ++;
        }
        k ++;
    }
    while( i < m ){										// �������֮һ��ʣ����������� 
        a[k] = h[i];
        i ++;
        k ++;
    }
    while( j < n ){
        a[k] = t[j];
        j ++;
        k ++;
    }
}

void MergeSort( int *a, int head, int tail ){
    if( head < tail ){
        int mid = head + ( tail - head ) / 2;
        MergeSort( a, head, mid );
        MergeSort( a, mid + 1, tail );
        Merge( a, head, mid, tail );
    }
}


void swap( int *x, int *y ){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int SideSort( int *a, int head, int tail ){
    int key = a[tail];										// �涨��׼ֵ
    int p = head - 1;
    int i;
    for( i = head; i <= tail - 1; i ++ ){
        if( a[i] < key ){									// �Ȼ�׼ֵС��ʱ��ͷ��ָ�����һλ��������ָλ�õ�ֵ 
            p ++;
            swap( &a[p], &a[i] );
        }
    }
    swap( &a[p+1], &a[tail] );
    return p+1;
}

void QuickSortRec( int *a, int head, int tail ){
    if( head < tail ){
        int k = SideSort( a, head, tail );
        QuickSortRec( a, head, k - 1);
        QuickSortRec( a, k + 1, tail );
    }
}

void QuickSortNonRec( int *a, int head, int tail ){
    int s[tail-head + 1];
    int top = -1;
    s[++ top] = head;
    s[++ top] = tail;

    while(top >= 0){
        tail = s[top --];
        head = s[top --];
        int k = SideSort( a, head, tail );
        if( k - 1 > head ){
    		s[++ top] = head;
            s[++ top] = k - 1;
        }
        if( k + 1 < tail ){
            s[++ top] = k + 1;
            s[++ top] = tail;
        }
    }
}



int findmax( int *a, int len ){
    int m = a[0];
    int i; 
	for( i = 1; i < len; i ++ ){
        if( a[i] > m ){
            m = a[i];
        }
    }
    return m;
}

Status CountSort( int *a, int len ){
	if( len <= 0 ){
		printf( "����Ϊ�գ�/n" );
		return ERROR;
	}
    int max = findmax( a, len );
    int i;
    int cnt[max + 1];
    for( i = 0; i <= max; i ++ ){
        cnt[i] = 0;
    }
    for( i = 0; i < len; i ++ ){
        cnt[ a[i] ] ++;
    }
    for( i = 1; i <= max; i ++ ){
        cnt[i] += cnt[i-1];
    }
    int s[len];
    for( i = 0; i < len; i ++ ){
        s[i] = 0;
    }
    for( i = len - 1; i >= 0; i -- ){
        s[-- cnt[ a[i] ]] = a[i];
    }
    for( i = 0; i < len; i ++ ){
        a[i] = s[i];
    }
    return OK;
}

Status RadixCountSort( int *a, int len ){
	if( len <= 0 ){
		printf( "����Ϊ�գ�/n" );
		return ERROR;	
	}
    int max = findmax( a, len );
    int step;
	for( step = 1; max / step > 0; step *= 10 ){
    	CountSort2( a, len, step );
	}
	return OK;
}

void CountSort2( int *a, int len, int step ){
    int s[len];
    int cnt[10] = {0};
    int i;
    for( i = 0; i < len; i ++ ){
        cnt[(a[i] / step ) % 10] ++;
    }
    for( i = 1; i < 10; i ++ ){
        cnt[i] += cnt[i - 1];
    }
    for( i = len - 1; i >= 0; i -- ){
        s[cnt[(a[i] / step) % 10] - 1] = a[i];
        cnt[(a[i] / step) % 10] --;
    }
    for( i = 0; i < len; i ++) {
        a[i] = s[i];
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

