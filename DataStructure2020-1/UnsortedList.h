#include "pch.h"

template<typename ItemType>
class UnSortedList
{
public:
	/*
	constructor
	*/
	UnSortedList() {}

	/*
		destructor
	*/
	~UnSortedList() {}

	/*
		@brief	make list empty
		@pre	none
		@post	clear list
	*/
	void MakeEmpty();

	/*
		@brief	get number of records in list
		@pre	none
		@post	none
		@return	a number of records in list
	*/
	int GetLength() const;

	/*
		@brief	check list is empty
		@pre	none
		@post	none
		@return	return true if list is empty, otherwise return false
	*/
	bool IsEmpty() const;

	/*
		@brief	check capacity of list is full
		@pre	none
		@post	none
		@return	return true if a number of records in list is MAXSIZE, otherwise return false
	*/
	bool IsFull() const;

	/*
		@brief	initilize list iterator
		@pre	list should be initilized
		@post	iterator is reset
	*/
	void ResetList();

	/*
		@brief	add new record in list
		@pre	list should be initialize
		@post	added the new record in list
		@paran	data	new data
		@return	return true if record is added to list successfully otherwise return false
	*/
	bool Add(ItemType data);

	/*
		@brief	find item which has same id of parameter in list
		@pre	list should be initilized
		@post	parameter changed to item which has same id in list
		@param	data	data to find
		@return	if function works successfully return true, otherwise return false
	*/
	bool Retrieve(ItemType& data);

	/*
		@brief	find item which has same id of parameter in list using binary search
		@pre	list should be initilized
		@post	parameter changed to item which has same id in list
		@param	data	data to find
		@return	if function works successfully return true, otherwise return false
	*/
	bool Delete(ItemType data);

	/*
		@brief	replace item which has same id with param
		@pre	list should be initilized
		@post	replaced data which you want to replace in list
		@param	data	data to replace
		@return	if function works successfully return true, otherwise return false
	*/
	bool Replace(ItemType data);

	/*
		@brief	move list iterator to the next item in list and get that item
		@pre	list should be initilized
		@post	iterator is reset
		@param	data	get current item of list
		@return	return -1 if current item is last item in list otherwise return index of current item
	*/
	int GetNextItem(ItemType& data);

private:
	ItemType* m_Array;
	int m_MaxSize;
	int m_Length;
	int m_CurPointer;
};

template<typename ItemType>
UnSortedList<ItemType>::UnSortedList() {
	m_MaxSize = MAXSIZE;
	m_Length = 0;
	ResetList();
	m_Array = new ItemType[m_MaxSize];
}

template<typename ItemType>
UnSortedList<ItemType>::~UnSortedList() {
	delete[] m_Array;
}

template<typename ItemType>
void UnSortedList<ItemType>::MakeEmpty() {
	delete[] m_Array;
	m_Length = 0;
	ResetList();
	m_Array = new ItemType[m_MaxSize];
}

template<typename ItemType>
int UnSortedList<ItemType>::GetLength() const {
	return m_Length;
}

template<typename ItemType>
bool UnSortedList<ItemType>::IsEmpty() const {
	if (m_Length == 0) return true;
	return false;
}


template<typename ItemType>
bool UnSortedList<ItemType>::IsFull() const {
	if (m_Length == m_MaxSize) return true;
}

template<typename ItemType>
void UnSortedList<ItemType>::ResetList() {
	m_CurPointer = -1;
}

template<typename ItemType>
bool UnSortedList<ItemType>::Add(ItemType item) {
	if (IsFull()) {
		ItemType* TempList = new T[m_Length];
		for (int i = 0; i < m_Length; ++i) {
			TepList[i] = m_Array[i];
		}
		delete[] m_Array;
		m_MaxSize += MAXSIZE;
		m_Array = new T[m_MaxSize];
		for (int i = 0; i < m_Length; ++i) {
			m_Array[i] = TempList[i];
		}
		delete[] TempList;
	}
	m_Array[m_Length++] = item;
	return true;
}

template<typename ItemType>
bool UnSortedList<ItemType>::Retrieve(ItemType& item) {
	for (int Pos = 0; Pos < m_Length; Pos++) {
		if (m_Array[Pos] == item) {
			item = m_Array[Pos];
			return true;
		}
	}
	return false;
}

template<typename ItemType>
bool UnSortedList<ItemType>::Delete(ItemType item) {
	for (int Pos = 0; Pos < m_Length; Pos++) {
		if (m_Array[Pos] == item) {
			for (int i = Pos; i < m_Length - 1; i++) {
				m_Array[i] = m_Array[i + 1];
			}
			m_Length--;
			return true;
		}
	}
	return false;
}

template<typename ItemType>
bool UnSortedList<ItemType>::Replace(ItemType data)
{
	for (int Pos = 0; Pos < m_Length; Pos++) {
		if (m_Array[Pos] == item) {
			m_Array[Pos] = item;
			return true;
		}
	}
	return false;
}


template<typename ItemType>
int UnSortedList<ItemType>::GetNextItem(ItemType& item) {
	m_CurPointer++;
	if (m_CurPointer == m_Length) return -1;
	item = m_Array[m_CurPointer];
	return m_CurPointer;
}
