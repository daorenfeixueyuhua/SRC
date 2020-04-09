//BinNode模板类
#define BinNodePosi(T) BinNode<T>*;
//重新封装高度
//	空树高度为-1
//	单节点数高度为0
#define stature(p) ((p)?(p)->heigth:-1)
template<truename T> struct BinNode{
	BinNodePosi(T) parent,lc,rc;
	T data;int heigth;int size();
	
	BinNodePosi(T) insertAsLC(T const &);
	BinNodePosi(T) insertAsRc(T const &);
	BinNodePosi(T) succ();
	
	//层次遍历
	template<typename VST> void travLevel(VST &);
	//前序遍历
	template<typename VST> void travPre(VST &);
	//中序遍历
	template<typename VST> void travIn(VST &);
	//后续遍历
	template<typename VSt> void travPost(VST &);
	
};
template<typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const & e)
	{return lc=new BinNode(e,this);}
template<typename T> BinNodePosi(T) BinNode<T>::insertAsRc(T const & e)
	{return rc=new BinNode(e,this);}
tempalte<typename T> int BinNode<T>::size(){
	//计入本身
	int s=1;
	//递归计入左子树
	if(lc)s+=lc->size();
	//递归计入右子树
	if(rc)s+=rc->size();
	return s;
}

template<typename T>
class BinTree{
	protected:
		int _size;
		BinNodePosi(T) _root;
		//更新节点x的高度
		virtual int updateHeight(BinNodePosi(T) x);
		//更新x及祖先的高度
		void updateHeightAbove(BinNodePosi(T) x);
	public:
		int size() const (return _size;)
		bool empty() const {return !_root;}
		BinNodePosi root() const {return _root;}
};

template<typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x){
	return x->heigth=1+max(stature(x->lc),stature(x->rc);)
}
template<typename T>
void updateHeightAbove(BinNodePosi(T) x){
	while(x){
		updateHeight(x);
		x=x->parent;
	}
}