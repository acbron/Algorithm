二叉查找树（Binary Search Tree），也称有序二叉树（ordered binary tree）,排序二叉树（sorted binary tree），是指一棵空树或者具有下列性质的二叉树：
	若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
	任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
	任意节点的左、右子树也分别为二叉查找树。
	没有键值相等的节点（no duplicate nodes）。

查找，插入，删除的复杂度均有O(H),其中H是树的高度
查找操作：
1.普通查找：跟二分查找类似，从根节点开始，如果key比根节点小，则查找左子树，否则查找右子树。直到找到key为止
2.查找最小/最大值：不断往左/右查找，直到叶子节点
3.查找前驱：如果key有左子树，则查找左子树中的最大值；若key没有左子树，则查找key的祖先中，第一个含有右子树的节点
4.查找后续：如果key有右子树，则查找右子树中的最小值；若key没有右子树，则查找key的祖先中，第一个含有左子树的节点

插入操作：从根节点开始，一直找到叶子节点，再根据key和该叶子节点的大小关系来决定插入的新节点处于的位置（左或右）

删除操作（设删除的点为M）：
1.如果M是根节点：
	如果M只有左子树：将根修改为其左孩子
	如果M只有右节点：将根修改为其右孩子
	如果M有左，右节点：
		如果M的后续是其右孩子，则直接将其左子树作为其右孩子的左子树，将根修改为其右孩子
		否则，找出其后续S，将S的父亲的左孩子删除（必然是左孩子，因为只有左孩子比它小），然后将S作为根节点
2.如果M不是根节点：
	找出M的前驱P，将M的右子树改为P的右子树，将M的左子树作为M父亲的左子树，删除M

#include <cstdio>
#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node *lson,*rson,*parent;
	Node(){}
	Node(int v,Node *l,Node *r,Node *p):val(v),lson(l),rson(r),parent(p){}
}*root,*ptr;

Node* find(Node *node,int key)
{
	if(!node || node->val == key)
		return node;
	if(node->val > key)
		return find(node->lson,key);
	else
		return find(node->rson,key);
}

Node* getMaxi(Node *node)
{
	while(node->rson)
		node = node->rson;
	return node;
}

Node* getMini(Node *node)
{
	while(node->lson)
		node = node->lson;
	return node;
}

Node* successor(Node *node)
{
	if(node->rson)
		return getMini(node->rson);
	Node *fa = node->parent;
	while(fa && fa->lson != node)
	{
		node = fa;
		fa = node->parent;
	}
	return fa;
}

Node* predecessor(Node *node)
{
	if(node->lson)
		return getMaxi(node->lson);
	Node *fa = node->parent;
	while(fa && fa->rson != node)
	{
		node = fa;
		fa = node->parent;
	}
	return fa;
}

void insert(int key)
{
	Node *newNode = new Node(key,NULL,NULL,NULL);
	Node *fa = NULL;
	ptr = root;
	while(ptr)
	{
		fa = ptr;
		if(ptr->val > key)
			ptr = ptr->lson;
		else
			ptr = ptr->rson;
	}
	newNode->parent = fa;
	if(!fa)
		root = newNode;
	else
	{
		if(fa->val > key)
			fa->lson = newNode;
		else
			fa->rson = newNode;
	}
}

void remove(int key)
{
	ptr = root;
	Node *tempNode = find(ptr,key);
	if(!tempNode)
		return;
	if(tempNode == root)
	{
		if(!tempNode->lson || !tempNode->rson)
		{
			if(tempNode->lson) root = tempNode->lson;
			else if(tempNode->rson) root = tempNode->rson;
			else root = NULL;
		}
		else
		{
			ptr = successor(tempNode);
			if(ptr == tempNode->rson)
			{
				ptr->parent = NULL;
				ptr->lson = tempNode->lson;
				tempNode->lson->parent = ptr;
				root = ptr;
			}
			else
			{
				ptr->parent->lson = NULL;
				ptr->lson = tempNode->lson;
				ptr->rson = tempNode->rson;
				tempNode->lson->parent = ptr;
				tempNode->rson->parent = ptr;
				ptr->parent = NULL;
				root = ptr;
			}
		}
		delete tempNode;
		return;
	}
	if(!tempNode->lson || !tempNode->rson)
	{
		ptr = tempNode->parent;
		if(tempNode->lson)
		{
			tempNode->lson->parent = ptr;
			if(ptr->lson == tempNode) ptr->lson = tempNode->lson;
			else ptr->rson = tempNode->lson;
		}
		else if(tempNode->rson)
		{
			tempNode->rson->parent = ptr;
			if(ptr->lson == tempNode) ptr->lson = tempNode->rson;
			else ptr->rson = tempNode->rson;
		}
		else
		{
			if(ptr->lson == tempNode) ptr->lson = NULL;
			else ptr->rson = NULL;
		}
	}
	else
	{
		Node *fa = tempNode->parent;
		ptr = predecessor(tempNode);
		tempNode->rson->parent = ptr;
		ptr->rson = tempNode->rson;
		tempNode->lson->parent = fa;
		if(fa->lson == tempNode) fa->lson = tempNode->lson;
		else fa->rson = tempNode->lson;
	}
	delete tempNode;
}

