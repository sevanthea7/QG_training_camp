#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/Sort.h"


int Menu1(){
	char s[30];
	int k;
	printf("********************************\n");
	printf("*     	   1.插入排序          *\n");
	printf("*          2.归并排序          *\n");
	printf("*        3.快速排序-递归       *\n");
	printf("*       4.快速排序-非递归      *\n");
	printf("*          5.计数排序          *\n");
	printf("*        6.基数计数排序        *\n");
	printf("*          7.退出程序          *\n");
	printf("********************************\n");
	printf("请选择需要的功能：");
	scanf( "%s", s );
	k = test_option( s, 7 );
	return k;
}

void generate( int *a, int len ){
	int i;
    for( i = 0; i < len; i ++ ){
        a[i] = rand() % MAX;									// 生成MAX范围内的随机数 
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
		printf( "数组为空！\n" );
		return ERROR;
	}
	for( i = 0; i < len - 1; i ++ ){
		last = i;												
		insert = a[last+1];										// 存储要插入数字的内容 
		while( last >= 0 && ( insert < a[last] ) ){				// 不符合要求的向后移一位 
			a[last+1] = a[last];
			last --;
		}
		a[last+1] = insert;										//最后空位插入的存储的内容 
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
        if( h[i] <= t[j] ){								// 两部分按顺序依次比较合在一起 
            a[k] = h[i];
            i ++;
        } else {
            a[k] = t[j];
            j ++;
        }
        k ++;
    }
    while( i < m ){										// 如果两侧之一有剩余的则放在最后 
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
    int key = a[tail];										// 规定基准值
    int p = head - 1;
    int i;
    for( i = head; i <= tail - 1; i ++ ){
        if( a[i] < key ){									// 比基准值小的时候，头部指针向后一位并交换所指位置的值 
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
		printf( "数组为空！/n" );
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
		printf( "数组为空！/n" );
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

