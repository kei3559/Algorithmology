/* 氏名：八代 航太朗 学年：２ クラス：５ 番号：４９
   参考にした資料：氏名：鈴木 啓 学年：２ クラス：６ 番号：２２ のプログラム
   感想：先週まであまりにも内容を理解することができていなかったので、今週は鈴木氏に質問するなどして理解に努めたので、内容を８割程度理解することができた。
         また、鈴木氏のプログラムを若干改変している。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct item{
	int data;
	struct item *next;
} *pointer;

void show_list(pointer p){

	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n\n");
}

int count_list(pointer p){
	int count = 0;

	while(p != NULL){
		count++;
		p = p->next;
	}

	return(count);
}

pointer insert_first(int x, pointer p){
	pointer q;

	q = malloc(sizeof *q);
	if(q == NULL){
		printf("メモリ不足\n");
	}
	q->data = x;
	q->next = p;

	return(q);
}

void insert_last(int x, pointer p){
	pointer q;

	q = malloc(sizeof *q);
	if(q == NULL){
		printf("メモリ不足\n");
	}

	while(p->next != NULL){
		p = p->next;
	}
	q->data = x;
	p->next = q;
}

void insert_any(int x, int i, pointer p){
	int count = count_list(p);
	int k = count-i;

	while(k != 0){
		p = p->next;
		k--;
	}

	pointer q, r;

	r = p->next;
	q = malloc(sizeof *q);
	if(q == NULL){
		printf("メモリ不足\n");
	}
	q->data = x;
	q->next = r;
	p->next = q;
}

pointer delete_any(int i, pointer p){
	pointer q = p;
	int k = i-1;

	if(k == 0){
		q = p->next;
		free(p);

		return(q);
	}
	else{
		while(k != 1){
			p = p->next;
			k--;
		}
		pointer r, s;

		r = p->next;
		s = r->next;
		free(r);
		p->next = s;

		return(q);
	}
}

int main(){
	int i = 7;
	int x, j;
	pointer box;

	printf("リストの先頭に要素を追加する\n");
	box = NULL;
	for(j=9; j>=0; j--){
		box = insert_first(j, box);
	}
	show_list(box);

	printf("リストの末尾に要素を追加する\n");
	insert_last(10, box);
	show_list(box);

	printf("リストの先頭からi番目に要素を追加する\n");
	if(i == 1){
		box = insert_first(11, box);
	}
	else{
		if(i >= 13){
			i = 12;
		}
		insert_any(11, 13-i, box);
	}
	show_list(box);

	printf("リストの先頭からi番目の要素を削除する\n");
	if(i >= 13){
		i = 12;
	}
	box = delete_any(i, box);
	show_list(box);

	return(0);
}