#pragma once
#include <iostream>
using namespace std;

//���ȶ�����

template <class K,class V>

struct NodeTree
{

	pair<K, V> _kv;//�����������
	NodeTree<K,V>* _left;
	NodeTree<K,V>* _right;
	NodeTree<K,V>* _parent;//ΪʲôҪ������һ����ָ���أ�Ϊ�˺������ϸ���ƽ�����ӷ���

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
		//AVL���Ĳ�������������Ĳ���+����ƽ������
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		//˵���ö��������ǿ�������ô�ͽ��бȽ��ҵ�λ��
		Node* cur = _root;
		
		while (cur)
		{
			
			if()
		}
	}


private:
	Node* _root;
};
