#define INFINITY		INT_MAX
#define MAX_VERTEX_NUM	20
typedef enum {
	DG,BN,UDG,UDM						//有向图、有向网、无向图、无向网 
}GraphKind; 

typedef struct ArcCell{
	VRType		abj;					//VRType表示定点关系类型，对无权图，用1/0表示相邻是否；对带权图，则为权值类型 
	InfoType	* info;					//该弧相关信息指针 
}ArcCell, AdjMatrix[MAX]; 
