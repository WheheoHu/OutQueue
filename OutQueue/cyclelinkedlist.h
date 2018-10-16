#pragma once

//结点结构
template<typename T>
struct CycleNode
{
	T data;
	CycleNode *prenode;
	CycleNode *nextnode;
	CycleNode(const T &d) :data(d), prenode(NULL), nextnode(NULL) {}
	
};

//双循环链表
//head节点默认为0
//head->nextnode为第一个节点
//head->prenode为最后节点
template <class T>

class Cycle_Linked_List {
public:
	Cycle_Linked_List();//创建一个head节点
	Cycle_Linked_List(T firstelem);//创建一个head节点并创建第一个节点值为firstelem
	~Cycle_Linked_List();
	void InitCycleList();
	bool isEmpty();
	int  CycleListLength();
	void CycleListInsert(int location, T elem);
	void CycleListDelete(int location);
	void CycleListDelete(int location, T &elem);
	T getElem(int location);
private:
	CycleNode<T> *head;
	CycleNode<T> *find(int location) {
		CycleNode<T> *p = head;
		for (int i = 0; i < location-1; i++)
		{
			p = p->nextnode;
		}
		return p;
	}
};

template<class T>
inline Cycle_Linked_List<T>::Cycle_Linked_List()
{
	InitCycleList();
}

template<class T>
inline Cycle_Linked_List<T>::Cycle_Linked_List(T firstelem)
{
	InitCycleList();
	CycleListInsert(1, firstelem);
}

template<class T>
inline Cycle_Linked_List<T>::~Cycle_Linked_List()
{
	free(head);
	head = NULL;
}

template<class T>
inline void Cycle_Linked_List<T>::InitCycleList()
{
	head = new CycleNode<T>(0);
	head->prenode = head;
	head->nextnode = head;
}

template<class T>
inline bool Cycle_Linked_List<T>::isEmpty()
{
	if (head->nextnode == head)
	{
		return true;
	}
	else
	{
		return false;
	}

}

template<class T>
inline int Cycle_Linked_List<T>::CycleListLength()
{
	int length = 0;
	CycleNode<T> *p = head;
	while (p->nextnode != head)
	{
		length++;
		p = p->nextnode;
	}
	return length;
}

template<class T>
inline void Cycle_Linked_List<T>::CycleListInsert(int location, T elem)
{
	if (location<1 || location>CycleListLength()+1)
	{
		exit(OVERFLOW);
	}
	CycleNode<T> *insertnode = new CycleNode<T>(elem);
	CycleNode<T> *temp = find(location);
	insertnode->nextnode = temp->nextnode;
	insertnode->nextnode->prenode = insertnode;
	insertnode->prenode = temp;
	temp->nextnode = insertnode;
}

template<class T>
inline void Cycle_Linked_List<T>::CycleListDelete(int location)
{
	if (location<1 || location>CycleListLength())
	{
		exit;
	}
	if (location == 1)
	{
		CycleNode<T> *temp = head;
		head = head->nextnode;
		delete temp;
		exit;
	}
	CycleNode *predeletnode = find(location);
	CycleNode *temp = predeletnode->nextnode;
	predeletnode->nextnode = temp->nextnode;
	temp->nextnode->prenode = predeletnode;
	delete temp;


}

template<class T>
inline void Cycle_Linked_List<T>::CycleListDelete(int location, T & elem)
{
	if (location<1 || location>CycleListLength())
	{
		exit;
	}
	if (location == 1)
	{
		CycleNode<T> *temp = head;
		head = head->nextnode;
		delete temp;
		exit;
	}
	CycleNode<T> *predeletnode = find(location);
	CycleNode<T> *temp = predeletnode->nextnode;
	elem = temp->data;
	predeletnode->nextnode = temp->nextnode;
	temp->nextnode->prenode = predeletnode;
	delete temp;
}

template<class T>
inline T Cycle_Linked_List<T>::getElem(int location)
{
	CycleNode<T> *p = find(location);
	return p->nextnode->data;
}


