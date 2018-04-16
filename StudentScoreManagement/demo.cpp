//引入自定义头文件
#include "consts.h"

// 数据结构定义
typedef struct node {
	char num[110];
	int shuxue;
	int yingyu;
	int yuwen;
	int wuli;
	int huaxue;
	struct node *next;
}LinkList;

// 函数原型
void CreateLinkList(LinkList *head, int *n);
void InsertStu(LinkList *head, char num[], int *n);
int DeleteStu(LinkList *head, char num[], int *n);
void DisplayStu(LinkList *head);

// 主函数
int main() {
	LinkList *head;
	char num[110];
	int flag = 0;
	int n = 0;

	head = (LinkList *)malloc(sizeof(LinkList));
	head->next = NULL;

	CreateLinkList(head, &n);

	printf_s("学生总数为: %d\n", n);
	if (head->next != NULL)
		DisplayStu(head);

	printf_s("\n请输入要插入的学生的学号, 以0结束:\n");
	scanf_s("%s", &num, sizeof(num));
	while (true){
		if (strcmp(num, "0") == 0)
			break;
		InsertStu(head, num, &n);
		printf_s("\n学生总数为: %d\n", n);
		DisplayStu(head);
		scanf_s("%s", &num, sizeof(num));
	}

	printf_s("请输入要删除的学生的学号, 以0结束\n");
	while (true){
		if (strcmp(num, "0") == 0)
			break;
		flag = DeleteStu(head, num, &n);
		printf_s("学生总数为: %d\n", n);
		DisplayStu(head);
		scanf_s("%s", &num, sizeof(num));
	}

	return 0;
}

void CreateLinkList(LinkList *head, int *n) {
	char num[110];
	int score, score1, score2, score3, score4;
	int i = 1;
	LinkList *p = head;
	LinkList *s;

	printf_s("\n请输入学生的学号, 以0结束\n");
	scanf_s("%s", &num, sizeof(num));
	while (true) {
		if (strcmp(num, "0") == 0)
			break;
		s = (LinkList *)malloc(sizeof(LinkList));
		strcpy_s(s->num, num);

		printf_s("请输入数学的成绩:\n");
		scanf_s("%d", &score);
		s->shuxue = score;

		printf_s("请输入英语的成绩:\n");
		scanf_s("%d", &score1);
		s->yingyu = score1;

		printf_s("请输入语文的成绩:\n");
		scanf_s("%d", &score2);
		s->yuwen = score2;

		printf_s("请输入物理的成绩:\n");
		scanf_s("%d", &score3);
		s->wuli = score3;

		printf_s("请输入化学的成绩:\n");
		scanf_s("%d", &score4);
		s->huaxue = score4;

		p->next = s;
		p = s;
		s->next = NULL;
		*n = *n + 1;

		printf_s("\n请输入学生的学号, 以0结束\n");
		scanf_s("%s", &num, sizeof(num));
	}
}

void InsertStu(LinkList *head, char num[], int *n) {
	LinkList *p;
	LinkList *s;
	int score, score1, score2, score3, score4;
	int flag = 0;

	printf_s("请输入数学的成绩:\n");
	scanf_s("%d", &score);
	
	printf_s("请输入英语的成绩:\n");
	scanf_s("%d", &score1);

	printf_s("请输入语文的成绩:\n");
	scanf_s("%d", &score2);
	
	printf_s("请输入物理的成绩:\n");
	scanf_s("%d", &score3);
	
	printf_s("请输入化学的成绩:\n");
	scanf_s("%d", &score4);

	p = head;

	while (p->next != NULL) {
		if (strcmp(p->next->num, num) == 0) {
			flag = 1;
			break;
		}
		p = p->next;
	}

	if (flag == 1) {
		p->next->shuxue = score;
		p->next->yingyu = score1;
		p->next->yuwen = score2;
		p->next->wuli = score3;
		p->next->huaxue = score4;
	} else {
		s = (LinkList *)malloc(sizeof(LinkList));
		strcpy_s(s->num, num);
		s->shuxue = score;
		s->yingyu = score1;
		s->yuwen = score2;
		s->wuli = score3;
		s->huaxue = score4;

		p->next = s;
		p = s;
		s->next = NULL;
		*n = *n + 1;
	}	
}

int DeleteStu(LinkList *head, char num[], int *n) {
	LinkList *p = head;
	LinkList *s;

	if (p->next == NULL) {
		printf_s("学生表中没有任何的学生记录\n");
		return ERROR;
	} else {
		while (p != NULL){
			s = p->next;
			if (s != NULL) {
				if (strcmp(s->num, num) == 0) {
					p->next = s->next;
					*n = *n - 1;
					break;
				}
			}
			p = p->next;
		}
		printf_s("学生表中没有改学生的记录");
		return ERROR;
	}
}

void DisplayStu(LinkList *head) {
	LinkList *h = head->next;

	printf_s("**********************************************************\n");
	printf_s("学号\t数学\t英语\t语文\t物理\t化学\n");
	while (h != NULL){
		printf_s("%s\t%d\t%d\t%d\t%d\t%d\n", h->num, h->shuxue, h->yingyu, h->yuwen, h->wuli, h->huaxue);
		h = h->next;
	}
	printf_s("**********************************************************\n");
}