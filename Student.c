#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define max 100

/*
学生标签结构体，包含学号，姓名，成绩
*/
typedef struct note
{ 
	int num;
	char name[max];
	int score;
	struct note *next;
}list;

/*
学生单链表的创建
*/
list *create()
{
	list *head,*p,*r;
	int i,n;
	head=(list*)malloc(sizeof(list));
	head->next=NULL;
	r=head;
	printf("请输入学生人数");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{ 
			p=(list*)malloc(sizeof(list));
			printf("请输入学生学号；\n");
			scanf("%d",&p->num);
			printf("请输入学生的名字；\n");
			scanf("%s",p->name);
			printf("请输入学生的成绩；\n");
			scanf("%d",&p->score);
			p->next=NULL;
			r->next=p;
			r=r->next;}
			return(head);
		}

/*
查询学生信息是否存在
*/
void find(list *h)
{
	int k;
	list *p;
	p=h->next;
	printf("请输入学生人数：\n");
	scanf("%d",&k);
	while (p!=NULL && p->num!=k)
	p=p->next;
	if(p)
		{
			printf("学号  姓名   成绩");
			printf("%d   %s   %d",p->num,p->name,p->score);
		}
	else 
			printf("查无此人");
}

/*
插人新的学生信息
*/
list *insert(list *h)
{
	list*p,*q,*r,*head;
	head=h;
	r=h;
	p=h->next;
	q=(list*)malloc(sizeof(list));
	printf("请输入待插入学生的学号；\n");
	scanf("%d",&q->num);
	printf("请输入待插入学生的姓名；\n");
	scanf("%s",&q->name);
	printf("请输入待插入学生的成绩；\n");
	scanf("%d",&q->score);
	q->next=NULL;
	while(p!=NULL)
	  {
		r=p;
		p=p->next;
	  }
	 r->next=q;
	 r=r->next;
	 return(head);
}

/*
删除某个学生的信息
*/
list *del(list*h)
{
	int k;
	list *p,*q;
	q=h;
	q=h->next;
	printf("请输入待删除学生的学号:\n");
	scanf("%d",&k);
	while(p&&p->num!=k)
		{
			q=p;
			p=p->next;
		}
	if(p)
		{
			q->next=p->next;
			free(p);
			printf("删除成功!\n"); 
		}
	else
			printf("没有这个学生成绩，无法删除\n");
			return(h);
}

/*
输出某个学生的信息
*/
void output(list *h)
{
	list *p;
	p=h->next;
	if(p==NULL)
		{
			printf("无记录!\n");
		}
	while(p!=NULL)
		{
			printf("学号\t 姓名\t 成绩\n");
			printf("%d\t%s\t%d\n",p->num,p->name,p->score);
			p=p->next;
		}
}

/*
建立一个带头结点的按学号单向有序链表
*/


/*插入一个元素使链表保持升序
*/
list *insertone(list *h;int x)
{
	list *p,*q,*head;
	int n=x;
	head=h;
	p=h->next;
	q=(list*)malloc(sizeof(list));
	printf("请输入待插入学生的学号；\n");
	scanf("%d",&q->num);
	printf("请输入待插入学生的姓名；\n");
	scanf("%s",&q->name);
	printf("请输入待插入学生的成绩；\n");
	scanf("%d",&q->score);
	q->next=NULL;
	for(i=0;i<n;i++)
		{
			if(q->num>p->num)
				p++;
		}
	p->next=q;
	q->next=p->next->next;
	return(head);
}


/*
用头插法将原链表中的元素逆序
*/
int HeadIntsd(list *head)
{

   int i;
   list *q,*p=head->next,*r;
   if(p!=NULL)
     {

        r=p->next;
        p->next=NULL;
        p=r;
        while(p!=NULL)
          {
              r=p->next;
              q=head;
              p->next=q->next;
              q->next=p;
              p=r;
          }
        return 1;
     }
  else
        return 0;
}

/*
删除学号为偶数的学生
*/
list *delo(list *h)
{
	int k;
	list *p,*q;
	q=h;
	q=h->next;
	while(p&&p->num%2)
		{
			q=p;
			p=p->next;
			p++;
		}
}

/*
遍历查询
*/
void show(list *h)
{   char b;
	int a;
	list *q;
	q=h;
    
	printf("输入查找学生学号或成绩");
    scanf("%d",&a);
	scanf("%s",&b);
	do
	{   if(a==q->num||a==q->score);
	{	   printf("学号为：%d,成绩：%d,姓名：%s",q->num,q->score,q->name);};
       	   q=q->next;	
	}
	while(q!=h);
	printf("\n");
}

void main()
{
	list *p;
	int n;
	int k;
	while(1)
		{	
			printf("   --------------------------------\n");
			printf("   |         学生成绩管理         |\n");
			printf("   --------------------------------\n");
			printf("             1.登记成绩            \n");
			printf("             2.查询成绩            \n");
			printf("             3.插入成绩            \n");
			printf("             4.删除成绩            \n");
			printf("             5.输出成绩            \n");
			printf("             6.按学号升序            \n");
			printf("             7.删除学号为偶数的学生            \n");
			printf("             8.插入一个学生保持学号升序            \n");
			printf("             9.逆序            \n");
			printf("             0.退出程序            \n");
			printf("   --------------------------------\n");
			printf("请输入你的选择:\n");
			scanf("%d",&k);
		switch(k)
			{
			  case 1:p=create();break;
			  case 2:find(p);break;
			  case 3:p=insert(p);break;
			  case 4:p=del(p);break;
			  case 5:output(p);break;
			  case 6:p=order(p,n);break;
			  case 7:p=delo(p);break;
			  case 8:p=insertone(p);break;
			  case 9:HeadIntsd(p);
			  case 0:exit(0);
			  default:printf("选择错误，请重新开始\n");
			}
		}
}




