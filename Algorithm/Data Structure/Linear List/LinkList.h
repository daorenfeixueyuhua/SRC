#define TRUE                1
#define FALSE               0
#define OK                  1
#define ERROR               0
#define INFEASIBLE          -1
#define OVERFLOW            -2

typedef int Status;
typedef int ElemType;


typedef struct LNode {
	ElemType data;
	struct LNode *next;
}*Link, *Position;

typedef struct {
	Link head, tail;			// 线性链表中的头节点和最后一个节点
	int len;					// 线性链表中的元素个数
}LinkList;

Status MakeNode(Link &p, ElemType e);
	// 分配由p指向的值为e的节点，并返回OK；若分配失败，则返回ERROR
void FreeNode(Link &p);
	// 释放p所指的节点
Status InitList(LinkList &L);
	// 构造一个空的线性链表L
Status DestoryList(LinkList &L);
	// 销毁线性链表L，L将不再存在
Status ClearList(LinkList &L);
	// 将线性链表重置为空表，并释放原链表的节点空间
Status InsFirst(Link h, Link s);
	// 一直h指向线性链表的头节点，将所指节点插入在第一个点之前
Status DelFirst(Link h, Link &q);
	// 一直h指向线性链表的头节点，删除链表中的第一个节点并用q返回
Status Append(LinkList &L, Link s);
	// 将指针s所指（彼此已指针相连）的一串节点链接在线性链表L的最后一个节点
	// 之后，并改变线性链表L的尾指针指向新的尾节点
Status Remove(LinkList &L, Link &q);
	// 删除线性链表中的尾节点并以q返回，改变链表L的尾指针指向新的尾节点
Status InsBefore(LinkList &lL, Link &q, Link s);
	// 已知p指向线性链表中的某个节点，将s所指向的节点，插入在p所指的节点之前
	// 并修改指针p指向新插入的节点
Status InsAfter(LinkList &L, Link &p, Link s);
	// 已知p指向线性链表中的某个节点，将s所指向的节点，插入在p所指向的节点之后
	// 并修改指针p指向新插入的节点
Status SetCurElem(Link &p, ElemType e);
	// 已知p指向线性链表中一个节点，用e跟新p所指节点中的数据元素的值
ElemType GetCurElem(Link p);
	// 已知p指向线性链表中一个节点，返回p所指节点中的数据元素的值
Status ListEmpty(LinkList L);
	// 若线性链表为空，返回TRUE，否则返回FASEL
int ListLength(LinkList L);
	// 返回线性链表中的元素个数
Position GetHead(LinkList L);
	// 返回线性链表L中的头节点的位置
Position GetLast(LinkList L);
	// 返回线性链表L中最后一个节点的位置
Position PriorPos(LinkList L, Link p);
	// 已知p指向线性链表L中的一个节点，返回p所指向节点的直接前驱的位置
	// 若无前驱，返回NULL
Position NextPos(LinkList L, Link p);
	// 已知p指向线性链表L中的一个节点，返回p所指向节点的直接后继的位置
	// 若无后继，返回NULL
Status LocatePos(LinkList L, int i, Link &q);
	// 返回p指示线性链表L中第i个节点的位置，并返回OK，i值不合法时返回ERROR
Position LocateElem(LinkList L, ElemType e, Status (* compare(ElemType, ElemType)));
	// 返回线性链表L中第1个于元素e满足函数compare()判定关系的元素的位置
	// 若不存在这样的元素，则返回NULL
Status ListTraverse(LinkList L, Status(*visit)());
	// 依次对L中的每个元素调用函数visit()。一旦visit()失败，则操作失败.
Status OrderInsert(LinkList L, ElemType e, Position &q, int (* compare(ElemType, ElemType)))
	// 按有序判定函数compare()的与约定，将值e插入到有序链表L的适当位置上
