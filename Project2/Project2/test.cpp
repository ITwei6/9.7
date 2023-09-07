#pragma once
#include <iostream>
using namespace std;

//首先定义结点

template <class K, class V>

struct NodeTree
{
	int _bf;//平衡因子
	pair<K, V> _kv;//结点里存的数据
	NodeTree<K, V>* _left;
	NodeTree<K, V>* _right;
	NodeTree<K, V>* _parent;//为什么要多增加一个父指针呢？为了后面往上更新平衡因子方便

	NodeTree(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_bf(0)
	{ }
	
};

template <class K, class V>
class AVLTree
{

	typedef NodeTree<K, V> Node;
public:

	bool Insert(const pair<K, V>& kv)
	{
		//AVL树的插入就是搜索树的插入+更新平衡因子
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		//说明该二叉树不是空树，那么就进行比较找到位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				//记录结点的位置
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//走到这里表明cur为空了，表明位置已经找到了
		cur = new Node(kv);
		
		if (kv.first>parent->_kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		//注意这个是三叉链，还要注意父指针
		cur->_parent = parent;
		//正常插入结点已经完成，接下来AVL树还需要更新平衡因子
		while (parent)//往上不断更新，直到更新到根结点，根结点上面就不需要更新了
		{
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//说明该子树高度改变，会影响祖先，需要往上更新平衡因子
				parent = parent->_parent;
				cur = parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//说明这个树生病了，需要调整，旋转,将树平衡
				//核心就是让cur的左结点成为parent的右结点，让parent成为cur的左结点。
				//要求旋转后，仍然是一个颗搜索树
				// 旋转后平衡，高度变低
				
			     
				//不平衡的树情况有很多种
				if (parent->_bf == 2 && cur->_bf == 1)//这种情况是单纯右边高，左单旋即可解决
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)//这种情况是单纯左边高，右单旋即可解决
				{
					RotateR(parent);
				}

			}
			else
			{
				return false;
			}
		}
		return true;
	}
	void RotateL(Node* parent)//左单旋
	{

		Node* cur = parnet->left;

		Node* curright = cur->_right;
		parent->_left = curright;
		if (curright)
		{
			curright->_parent = parent;
		}
		cur->_right = parent;
		parent->_parent = cur;

		Node* pp = parent->_parent;

		if (pp == nullptr)
		{
			//那么这样cur就是根结点了
			_root = cur;
			cur->_parent = nullptr;
	   }
		else
		{
			if (pp->_left == parnet)
			{
				pp->_left = cur;
			}
			else
			{
				pp->_right = cur;
			}
			
			cur->_parent = pp;
			//旋转后cur和parent bf都为0?
			cur->_bf = parent->_bf = 0;

		}
	}
	void RotateR(Node* parent)//右单旋
	{
		Node* cur = parent->_left;

		Node* curright = cur->_right;
		Node* ppnode = parent->_parent;
		parent->_left = curright;
		if (curright)
		{
			curright->_parent = parent;
		}
		cur->_right = parent;
		parent->_parent = cur;

		if (ppnode == nullptr)
		{
			//说明cur就变成根节点了
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}
			cur->_parent = ppnode;
		}
		cur->_bf = parent->_bf = 0;

	}
private:
	Node* _root;
};
