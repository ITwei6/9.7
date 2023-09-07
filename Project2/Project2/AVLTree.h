#pragma once
#include <iostream>
using namespace std;

//首先定义结点

template <class K,class V>

struct NodeTree
{

	pair<K, V> _kv;//结点里存的数据
	NodeTree<K,V>* _left;
	NodeTree<K,V>* _right;
	NodeTree<K,V>* _parent;//为什么要多增加一个父指针呢？为了后面往上更新平衡因子方便

	NodeTree(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{}
};

template <class K, class V>
class AVLTree
{
public:
	typedef NodeTree<K, V> Node;
	
	AVLTree()
		:_root(nullptr);
	{}
	bool Insert(const pair<K, V> kv)
	{
		//AVL树的插入就是搜索树的插入+更新平衡因子
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		//说明该二叉树不是空树，那么就进行比较找到位置
		Node* cur = _root;
		
		while (cur)
		{
			
			if()
		}
	}


private:
	Node* _root;
};
