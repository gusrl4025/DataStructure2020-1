#include "pch.h"

template <typename T>
struct NodeType {
	T info;
	NodeType* next;
};

template<typename T>
class SingleLinkedList {
private:
	NodeType<T>* m_pList;
	NodeType<T>* m_pCurPointer;
	int m_Length;
public:
	/*
		constructor
	*/
	SingleLinkedList();

	/*
		Destructor
	*/
	~SingleLinkedList();

	/*
		@brief	List를 비운다
		@pre	none
		@post	List가 비워진다
	*/
	void MakeEmpty();

	/*
		@brief	m_Length를 반환한다
		@pre	none
		@post	none
		@return m_Length
	*/
	int GetLength();

	/*
		@brief	List에 item을 추가한다
		@pre	list가 초기화돼야한다.
		@post	List가 꽉 차있지 않고 중복된 ID가 아니면 List에 추가된다.
		@param	item	추가하려는 아이템
		@return	아이템이 추가되었으면 return true,아니면 return false
	*/
	bool Add(const T& item);

	/*
		@brief	List에서 원하는 item을 가져온다
		@pre	List가 초기화돼야한다
		@post	parameter에 찾고자하는 item이 참조된다
		@param	item	찾고자하는 아이템
		@return	아이템을 찾았으면 return true, 아니면 return false
	*/
	bool Get(T& item);

	/*
		@brief	List에서 원하는 item을 제거한다
		@pre	List가 초기화돼야한다
		@post	parameter에 제거한 item이 참조된다
		@param	item	제거하려는 아이템
		@return	아이템을 제거했으면 return true, 아니면 return false
	*/
	bool Delete(T& item);

	/*
		@brief	List에서 원하는 item을 수정한다.
		@pre	List가 초기화돼야한다
		@post	원하는 item이 paramter에 있는 item으로 수정된다
		@param	item	수정하려는 item
		@return	item을 수정했으면 return true, 아니면 return false
	*/
	bool Replace(const T& item);

	/*
		@brief	List의 Pointer를 초기화시킨다
		@pre	none
		@post	m_pCurPointer = nullptr
	*/
	void ResetList();

	/*
		@brief	현재 pointer의 next item을 불러온다
		@pre	List가 초기화돼야한다
		@post	next item이 있으면 parameter에 next item이 참조된다
		@param	item	next item이 여기에참조된다
		@return	next item을 참조하면 return true, 아니면 return false
	*/
	bool GetNextItem(T& item);

	void operator=(SingleLinkedList& list) {
		MakeEmpty();
		m_Length = 0;

		if (list.GetLength()) {
			list.ResetList();
			T item;
			while (list.GetNextItem(item)) {
				Add(item);
			}
		}
	}
};

template<typename T>
SingleLinkedList<T>::SingleLinkedList()
{
	m_pList = nullptr;
	m_pCurPointer = nullptr;
	m_Length = 0;
}

template<typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	MakeEmpty();
}

template<typename T>
void SingleLinkedList<T>::MakeEmpty()
{
	NodeType<T>* TempPtr;
	TempPtr = m_pList;

	while (TempPtr != nullptr) {
		TempPtr = m_pList;
		m_pList = m_pList->next;
		delete TempPtr;
	}

	m_Length = 0;
}

template<typename T>
inline int SingleLinkedList<T>::GetLength()
{
	return m_Length;
}

template<typename T>
bool SingleLinkedList<T>::Add(const T& item)
{
	bool found = false;

	NodeType<T>* PredLoc;
	NodeType<T>* TempPtr;
	TempPtr = new NodeType<T>;

	TempPtr->info = item;

	if (m_Length == 0) {
		m_pList = TempPtr;
		TempPtr->next = nullptr;
		m_Length++;
	}
	else {
		PredLoc = m_pList;
		m_pCurPointer = m_pList;
		while (m_pCurPointer != nullptr) {
			if (m_pCurPointer->info == item) {
				cout << "\t중복된 ID가 있습니다\n";
				return false;
			}
			if (m_pCurPointer->info > item) {
				found = true;
				break;
			}
			if (m_pCurPointer->info < item) {
				PredLoc = m_pCurPointer;
				m_pCurPointer = m_pCurPointer->next;
			}
		}

		if (PredLoc == m_pCurPointer) {
			TempPtr->next = m_pList;
			m_pList = TempPtr;
		}

		else {
			PredLoc->next = TempPtr;
			TempPtr->next = m_pCurPointer;
		}
		m_Length++;
		return true;
	}
}

template<typename T>
bool SingleLinkedList<T>::Get(T& item)
{
	m_pCurPointer = m_pList;

	while (m_pCurPointer != nullptr) {
		if (m_pCurPointer->info == item) {
			item = m_pCurPointer->info;
			return true;
		}
		if (m_pCurPointer->info < item) {
			m_pCurPointer = m_pCurPointer->next;
		}
		if (m_pCurPointer->info > item) {
			return false;
		}
	}
}

template<typename T>
inline bool SingleLinkedList<T>::Delete(T& item)
{
	bool found = false;
	NodeType<T>* PredLoc;
	NodeType<T>* TempPtr;
	TempPtr = new NodeType<T>;

	TempPtr->info = item;

	if (m_Length == 0) {
		return false;
	}

	else {
		PredLoc = m_pList;
		m_pCurPointer = m_pList;
		while (m_pCurPointer == nullptr) {
			if (TempPtr->info == m_pCurPointer->info) {
				found = true;
			}
			if (TempPtr->info > m_pCurPointer->info) {
				return false;
			}
			if (TempPtr->info < m_pCurPointer->info) {
				PredLoc = m_pCurPointer;
				m_pCurPointer = m_pCurPointer->next;
			}
		}
		if (!found) return false;
		else {
			if (m_pCurPointer == m_pList) {
				m_pList = m_pList->next;
				delete PredLoc;
			}
			if (m_pCurPointer->next == nullptr) {
				PredLoc->next = nullptr;
				delete m_pCurPointer;
			}
			PredLoc->next = m_pCurPointer->next;
			delete m_pCurPointer;
			return true;
		}
	}
}

template<typename T>
inline bool SingleLinkedList<T>::Replace(const T& item)
{
	m_pCurPointer = m_pList;

	while (m_pCurPointer != nullptr) {
		if (m_pCurPointer->info == item) {
			m_pCurPointer->info = item;
			return true;
		}
		if (m_pCurPointer->info < item) {
			m_pCurPointer = m_pCurPointer->next;
		}
		if (m_pCurPointer->info > item) {
			return false;
		}
	}
}

template<typename T>
void SingleLinkedList<T>::ResetList()
{
	m_pCurPointer = nullptr;
}

template<typename T>
bool SingleLinkedList<T>::GetNextItem(T& item)
{
	if (m_pCurPointer == nullptr) {
		m_pCurPointer = m_pList;
		item = m_pCurPointer->info;
		return true;
	}

	if (m_pCurPointer->next == nullptr) {
		ResetList();
		return false;
	}

	m_pCurPointer = m_pCurPointer->next;
	item = m_pCurPointer->info;
	return true;
}