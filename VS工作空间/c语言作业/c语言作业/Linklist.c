#include <stdio.h>
#include <stdlib.h>

struct stud_node {
	unsigned int    num;
	char   name[20];
	unsigned int    score;
	struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
	int min_score;
	struct stud_node *p, *head = NULL;

	head = createlist();
	scanf_s("%d", &min_score);
	head = deletelist(head, min_score);
	for ( p = head; p != NULL; p = p->next )
		printf("%d %s %d\n", p->num, p->name, p->score);
	system("pause");	
	return 0;
}

struct stud_node *createlist()
{
	int Num;
	struct stud_node *p,*l,*r;
	l=(struct stud_node*)malloc(sizeof(struct stud_node));
	scanf_s("%d",&l->num);
	scanf_s("%s %d",&l->name,&l->score);
	scanf_s("%d",&Num);
	r=l;
	while(Num != 0)
	{
		p=(struct stud_node*)malloc(sizeof(struct stud_node));
		p->num=Num;
		scanf_s("%s %d",&p->name,&p->score);
		r->next=p;
		r=p;
		scanf_s("%d",&Num);
	}
	r->next=NULL;
	return l;
}

struct stud_node *deletelist( struct stud_node *head, int min_score )
{
	struct stud_node *p,*l,*r,*m;
	l=(struct stud_node*)malloc(sizeof(struct stud_node));
	r=l;
	p=head;
	
	for (p;p!=NULL;p=p->next)
	{
		if (p->score>=min_score)
		{
			r->next=p;
			r=p;
		}
	}
	r->next=NULL;
	
	m=l->next;
	return m;
}

/*struct stud_node *deletelist( struct stud_node *head, int min_score )
{
	struct stud_node *p,*l,*r,*m;
	l=(struct stud_node*)malloc(sizeof(struct stud_node));
	r=l;
	strcpy(l->name,head->name);
	l->num=head->num;
	l->score=head->score;
	p=head;
	for (p;p!=NULL;p=p->next)
	{
		if (p->score>=min_score)
		{
			r->next=p;
			r=p;
		}
	}
	r->next=NULL;
	return l;
}*/