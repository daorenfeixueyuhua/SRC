#include <iostream>

using namespace::std;
/*
 * 完全二叉树子节点x的父节点编号一定为x/2 
 */
int main()
{
	int x, y;
	while(cin >> x >> y&&(x>0&&y>0))
	{
		while(x!=y)
		{
			if(x<y)
			{
				y /= 2;
			}
			else
			{
				x /= 2;
			}
		}
		cout << x << endl;
	}
	return 0;
}
