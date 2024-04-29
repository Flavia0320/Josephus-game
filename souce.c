#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>

struct Nod
{
int info;
struct Nod* next;
};

typedef struct Nod Nod;

struct CircularQueue
{
Nod* first, * last;
};

typedef struct CircularQueue CircularQueue;

void push(CircularQueue* q, int x)
{
Nod* nod_nou = (Nod*)malloc(sizeof(Nod));
nod_nou->info = x;
if (q->first == NULL)
	q->first = nod_nou;
else
	q->last->next = nod_nou;
nod_nou->next = q->first;
q->last = nod_nou;
}


Nod* getNod(CircularQueue q, int m)
{
Nod* n = q.first;
for (int i = 0; i < m; i++)
n = n->next;
return n;
}

void game(CircularQueue* q, int m, int p)
{
while (q->first != q->last)
{
Nod* n = getNod(*q, p);
for (int i = 1; i < m; i++)
{
n = n->next;
}
Nod* noddesters = n->next;
n->next = noddesters->next;
if (noddesters == q->first)
q->first = noddesters->next;
else if (noddesters == q->last)
q->last = n;
printf(" %d ", noddesters->info);
free(noddesters);
}
printf("\n The winner is %d\n", q->first->info);
}

void empty(CircularQueue* q)
{
while (q->last != q->first)
{
Nod* n = q->first;
q->last->next = q->first->next;
q->first = q->first->next;
free(n);
}
free(q->first);
q->first = NULL;
q->last = NULL;
}


int main()
{
CircularQueue q;
q.first = NULL;
q.last = NULL;
int n, m, p;
scanf("%d%d%d", &n, &m, &p);
for (int i = 1; i <= n; i++)
push(&q, i);
game(&q, m, p);
empty(&q);
return 0;
}
