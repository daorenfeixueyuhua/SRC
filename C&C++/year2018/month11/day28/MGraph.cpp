#define INFINITY		INT_MAX
#define MAX_VERTEX_NUM	20
typedef enum {
	DG,BN,UDG,UDM						//����ͼ��������������ͼ�������� 
}GraphKind; 

typedef struct ArcCell{
	VRType		abj;					//VRType��ʾ�����ϵ���ͣ�����Ȩͼ����1/0��ʾ�����Ƿ񣻶Դ�Ȩͼ����ΪȨֵ���� 
	InfoType	* info;					//�û������Ϣָ�� 
}ArcCell, AdjMatrix[MAX]; 
