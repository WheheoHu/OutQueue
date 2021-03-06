#pragma once

//结点结构
template<typename T>
struct CycleNode
{
	T data;
	CycleNode  *nextnode;
	int index;
	bool isOut;
	CycleNode(const T &d) :data(d), nextnode(NULL), index(0) ,isOut(false){}
	CycleNode(const T &d, const int index) :data(d), nextnode(NULL), index(index),isOut(false) {}

};

//双循环链表
//head节点默认为0
//head->nextnode为第一个节点
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
	void CycleListInsert(int location, T elem, int index);
	void CycleListDelete(int location);
	void CycleListDelete(int location, T &elem);
	T getElem(int location);
	int getindex(int location);
	void Joseph(int *op, int maxnum, int num_human);
private:
	CycleNode<T> *head;
	CycleNode<T> *find(int location) {
		CycleNode<T> *p = head;
		for (int i = 0; i < location - 1; i++)
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
	head->isOut = true;
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
	if (location<1 || location>CycleListLength() + 1)
	{
		exit(OVERFLOW);
	}
	CycleNode<T> *insertnode = new CycleNode<T>(elem);
	CycleNode<T> *temp = find(location);
	insertnode->nextnode = temp->nextnode;
	temp->nextnode = insertnode;
}

template<class T>
inline void Cycle_Linked_List<T>::CycleListInsert(int location, T elem, int index)
{
	if (location<1 || location>CycleListLength() + 1)
	{
		exit(OVERFLOW);
	}
	CycleNode<T> *insertnode = new CycleNode<T>(elem,index);
	CycleNode<T> *temp = find(location);
	insertnode->nextnode = temp->nextnode;

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
	delete temp;
}

template<class T>
inline T Cycle_Linked_List<T>::getElem(int location)
{
	CycleNode<T> *p = find(location);
	return p->nextnode->data;
}

template<class T>
inline int Cycle_Linked_List<T>::getindex(int location)
{
	CycleNode<T> *p = find(location);

	return p->nextnode->index;
}


template<class T>
inline void Cycle_Linked_List<T>::Joseph(int * mans, int maxnum, int num_human)
{
	CycleNode<T> *p = head;
	int mans_index = 0;
	int numtocount = maxnum;
	/*for (int i = 0; i < num_human; i++){

		while (count <= numtocount)
		{
			if (p->nextnode->isOut==true)
			{
				p = p->nextnode->nextnode;
				count++;
			}
			else
			{
				p = p->nextnode;
				count++;
			}
		}
		if (p->nextnode==head)
		{
			mans[mans_index] = p->nextnode->nextnode->index;
			p->nextnode->nextnode->isOut = true;
		}
		else
		{
			mans[mans_index] = p->nextnode->index;
			p->nextnode->isOut = true;
		}
		mans_index++;
		if (p->nextnode==head)
		{
			numtocount = p->nextnode->nextnode->data;
		}
		else
		{
			numtocount = p->nextnode->data;
		}
	}*/
	while (num_human>0)
	{
		for (int i = 1; i < numtocount; i++)
		{
			if (p->nextnode==head)
			{
				p = p->nextnode->nextnode;
			}
			else
			{
				p = p->nextnode;
			}
			
		}
		if (p->nextnode==head)
		{
			p = p->nextnode;
		}
		numtocount = p->nextnode->data;
		mans[mans_index] = p->nextnode->index;
		mans_index++;
		p ->nextnode= p->nextnode->nextnode;
	
		num_human--;
	}
}




