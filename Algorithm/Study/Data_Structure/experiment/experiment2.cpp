#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>


typedef struct polymerization
{
	int ratio[100];//系数
	int index[100];//指数
	int length;		//项数
}polymer;

void init(polymer * p);//初始化
polymer create();//建立空的多项式
void sort(polymer * p);//按指数排序
void print(polymer p);//打印多项式
void reverse(polymer & p);//多项式取反，系数全部变为相反数
polymer addto(polymer p1, polymer p2);//多项式相加
polymer subtraction(polymer p1, polymer p2);//多项式相减

int main()
{
	/*
	1 1 3 3 5 5 7 7 9 9 10 0 -1 -1
	2 2 4 4 6 6 8 8 0 0 7 0 -1 -1
	 */
	polymer p1, p2, p3, p4;
	init(&p1); init(&p2);
	sort(&p1); sort(&p2);
	p3 = addto(p1, p2);
	p4 = subtraction(p1, p2);
	sort(&p3); sort(&p4);
	printf("the result of p1 is:");
	print(p1);
	printf("the result of p2 is:");
	print(p2);
	printf("the result of p1 and p2 is:");
	print(p3);
	printf("the result of p1 sub p2 is:");
	print(p4);
}

void init(polymer * p)//初始化
{
	int r, i;
	memset(p->ratio, 0, sizeof(p->ratio));
	memset(p->index, 0, sizeof(p->index));
	p->length = 0;
	printf("ratio: index:\n");
	scanf("%d %d", &r, &i);
	while (i >= 0)
	{
		p->ratio[p->length] = r;
		p->index[p->length++] = i;
		scanf("%d %d", &r, &i);
	}
}

polymer create()//建立空的多项式
{
	polymer p;
	memset(p.ratio, 0, sizeof(p.ratio));
	memset(p.index, 0, sizeof(p.index));
	p.length = 0;
	return p;
}

void sort(polymer * p)//按指数排序
{
	for (int i = 0; i < p->length - 1; ++i)
		for (int j = 0; j < p->length - 1 - i; ++j)
		{
			if (p->index[j] >= p->index[j + 1])
			{
				//				printf("swap\n");
				std::swap(p->index[j], p->index[j + 1]);
				std::swap(p->ratio[j], p->ratio[j + 1]);
			}
		}
}
void print(polymer p)//打印多项式
{
	printf("P(x)=");
	for (int i = 0; i < p.length; ++i)
	{
		if (p.ratio[i] < 0)
			printf("-");
		if (p.ratio[i] == 0)
			continue;
		if (p.ratio[i] > 0)
		{
			if (i == 0);
			else printf("+");
		}
		printf("%d", abs(p.ratio[i]));
		if (p.index[i] == 0);
		if (p.index[i] == 1)printf("x");
		if (p.index[i] > 1)printf("x^%d", p.index[i]);
	}
	printf("\n");
}
void reverse(polymer & p)
{
	for (int i = 0; i < p.length; ++i)
		p.ratio[i] = -p.ratio[i];
}
polymer addto(polymer p1, polymer p2)//多项式相加
{
	polymer p = create();
	int i = 0, j = 0;
	while (i <= p1.length&&j <= p2.length)
	{//按指数来选择，相同指数的项相加
		if (p1.index[i] < p2.index[j])
		{
			p.ratio[p.length] = p1.ratio[i];
			p.index[p.length++] = p1.index[i++];
		}
		if (p1.index[i] == p2.index[j])
		{
			p.ratio[p.length] = p1.ratio[i] + p2.ratio[j++];
			p.index[p.length++] = p1.index[i++];
		}if (p1.index[i] > p2.index[j])
		{
			p.ratio[p.length] = p2.ratio[j];
			p.index[p.length++] = p2.index[j++];
		}
		//print(p);
	}
	while (i <= p1.length)
	{
		p.ratio[p.length] = p1.ratio[i];
		p.index[p.length++] = p1.index[i++]; //print(p);
	}
	while (j <= p2.length)
	{
		p.ratio[p.length] = p2.ratio[j];
		p.index[p.length++] = p2.index[j++]; //print(p);
	}
	return p;
}
polymer subtraction(polymer p1, polymer p2)
{
	reverse(p2);//将p2取反
	polymer p = addto(p1, p2);
	return p;
}
