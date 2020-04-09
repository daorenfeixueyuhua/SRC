#include <vector>
using namespace::std;
//Vertex
typedef enum{
    UNDISCOVERED,
    DISCOVERED,
    VISITED
}VStstus;
template<typename Tv>
struct Vertex{//定点对象
    Tv data;
    int inDegree,outDegree;//数据，出入度
    VStstus status;
    int dTime,fTime;//时间标签
    int parent;//在遍历树的父节点
    int priority;//在遍历树的优先级
    Vertex(Tv const & d):
        data(d),inDegree(0),outDegree(0),status(UNDISCOVERED),
        dTime(-1),fTime(-1),parent(-1),priority(_INTEGRAL_MAX_BITS){}
};

//Edge
typedef enum{
    UNDIETERMTNED,
    TREE,
    CROSS,
    FORMARD,
    BACKWARD
}EType;
template<typename Te>
struct Edge{//边对象
    Te data;//数据
    int weight;//权重
    EType type;//在遍历树中所属的类型
    Edge(Te const & d,int w)://构造新边
        data(d), weight(w),type(UNDIETERMTNED){}

};

//GraphMatrix
template<typename Tv,typename Te>
class GraphMatrix{
    private:
        vector<vector<Vertex<Tv>>> V;//定点集
        vector<vector<Edge<Te>*>> E;//边集
    public:
        GraphMatrix(){n=e=0;}//构造
        ~GraphMatrix(){//析构
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    delete E[j][k];//清除所有动态申请的边记录
        }
        //定点的读写
        Tv& vertex(int i){return V[i].data;}//数据
        int inDegree(int i){return V[i].inDegree;}//入读
        int outDegree(int i){return V[i].outDegree;}//出度
        VStstus& status(int i){return V[i].status;}//状态
        int& dTime(int i){return V[i].dTime;}//时间标签dTime
        int& fTime(int i){return V[i].fTimr;}//时间标签fTime
        int& parent(int i){return V[i].parent;}//在遍历树中的父亲
        int& priority(int i){return V[i].priority;}//优先级数

        //边的读写
        bool exists(int i,int j{//判断边(i,j)是否存在（短路求径）
            return (0<=i)&&(i<n)&&(0<=j)&&(j<n)&&E[i][j]!=NULL;
        }
        Te& edge(int i,int j){return E[i][j]->data;}
        EType& type(int i,int j){return E[i][j]->type;}
        int& weight(int i,int j){return E[i][j]->weight;}

        //边的插入
        void inert(Te const& edge,int w,int i,int j){
            if(exists(i,j)) return;//该边已存在
            E[i][j]=new Edge<Te>(edge,w);
            e++;//更新边计数
            V[i].outDegree++;//更新关联点的出度
            V[j].inDegree++;//更新关联点的入度
        }

        //边的删除
        Te remove(int i,int j){//删除定点i和j之间的连边(exits(i,j))
            Te eBak=edge(i,j);//备份数据
            delete E[i][j];E[i][j]=NULL;
            e--;//跟新边数
            V[i].outDegree--;//跟新关联点的出度
            V[j].inDegree--;//跟新关联点的入读
            return eBak;//返回删除的数据
        }

        //定点插入
        int insert(Tv const& vertex){
            for(int j=0;j<n;j++)
                E[j].insert(NULL);
            n++;
            E.insert(vector<Edge<Te>*>(n,n,NULL));  
            return V.insert(Vertex<Tv>(vertex));
        }

        //定点删除
        int remove(int i){
            for(int j=0;j<n;j++)//删除所有出边
                if(exists(i,j)){
                    delete E[i][j];
                    V[j].inDegree--;
                }
            E.remove(i);n--;//删除第i行
            Tv vBak = vertex(i);
            V.remove(i);
            for(intj=0;j<n;j++){//删除所有入边和第i列
                if(Edge<Te>* e = E[j].remove(j)){
                    delete e;
                    V[j].outDegree--;
                }
            }
            return vBak;
        }
}