#pragma once
#include <iostream>
using namespace std;

//���ȶ�����

template <class K, class V>

struct NodeTree
{
	int _bf;//ƽ������
	pair<K, V> _kv;//�����������
	NodeTree<K, V>* _left;
	NodeTree<K, V>* _right;
	NodeTree<K, V>* _parent;//ΪʲôҪ������һ����ָ���أ�Ϊ�˺������ϸ���ƽ�����ӷ���

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
		//AVL���Ĳ�������������Ĳ���+����ƽ������
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		//˵���ö��������ǿ�������ô�ͽ��бȽ��ҵ�λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				//��¼����λ��
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
		//�ߵ��������curΪ���ˣ�����λ���Ѿ��ҵ���
		cur = new Node(kv);
		
		if (kv.first>parent->_kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		//ע�����������������Ҫע�⸸ָ��
		cur->_parent = parent;
		//�����������Ѿ���ɣ�������AVL������Ҫ����ƽ������
		while (parent)//���ϲ��ϸ��£�ֱ�����µ�����㣬���������Ͳ���Ҫ������
		{
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//˵���������߶ȸı䣬��Ӱ�����ȣ���Ҫ���ϸ���ƽ������
				parent = parent->_parent;
				cur = parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//˵������������ˣ���Ҫ��������ת,����ƽ��
				//���ľ�����cur�������Ϊparent���ҽ�㣬��parent��Ϊcur�����㡣
				//Ҫ����ת����Ȼ��һ����������
				// ��ת��ƽ�⣬�߶ȱ��
				
			     
				//��ƽ���������кܶ���
				if (parent->_bf == 2 && cur->_bf == 1)//��������ǵ����ұ߸ߣ��������ɽ��
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)//��������ǵ�����߸ߣ��ҵ������ɽ��
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
	void RotateL(Node* parent)//����
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
			//��ô����cur���Ǹ������
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
			//��ת��cur��parent bf��Ϊ0?
			cur->_bf = parent->_bf = 0;

		}
	}
	void RotateR(Node* parent)//�ҵ���
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
			//˵��cur�ͱ�ɸ��ڵ���
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
