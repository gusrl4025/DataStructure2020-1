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
		@brief	List�� ����
		@pre	none
		@post	List�� �������
	*/
	void MakeEmpty();

	/*
		@brief	m_Length�� ��ȯ�Ѵ�
		@pre	none
		@post	none
		@return m_Length
	*/
	int GetLength();

	/*
		@brief	List�� item�� �߰��Ѵ�
		@pre	list�� �ʱ�ȭ�ž��Ѵ�.
		@post	List�� �� ������ �ʰ� �ߺ��� ID�� �ƴϸ� List�� �߰��ȴ�.
		@param	item	�߰��Ϸ��� ������
		@return	�������� �߰��Ǿ����� return true,�ƴϸ� return false
	*/
	bool Add(const T& item);

	/*
		@brief	List���� ���ϴ� item�� �����´�
		@pre	List�� �ʱ�ȭ�ž��Ѵ�
		@post	parameter�� ã�����ϴ� item�� �����ȴ�
		@param	item	ã�����ϴ� ������
		@return	�������� ã������ return true, �ƴϸ� return false
	*/
	bool Get(T& item);

	/*
		@brief	List���� ���ϴ� item�� �����Ѵ�
		@pre	List�� �ʱ�ȭ�ž��Ѵ�
		@post	parameter�� ������ item�� �����ȴ�
		@param	item	�����Ϸ��� ������
		@return	�������� ���������� return true, �ƴϸ� return false
	*/
	bool Delete(T& item);

	/*
		@brief	List���� ���ϴ� item�� �����Ѵ�.
		@pre	List�� �ʱ�ȭ�ž��Ѵ�
		@post	���ϴ� item�� paramter�� �ִ� item���� �����ȴ�
		@param	item	�����Ϸ��� item
		@return	item�� ���������� return true, �ƴϸ� return false
	*/
	bool Replace(const T& item);

	/*
		@brief	List�� Pointer�� �ʱ�ȭ��Ų��
		@pre	none
		@post	m_pCurPointer = nullptr
	*/
	void ResetList();

	/*
		@brief	���� pointer�� next item�� �ҷ��´�
		@pre	List�� �ʱ�ȭ�ž��Ѵ�
		@post	next item�� ������ parameter�� next item�� �����ȴ�
		@param	item	next item�� ���⿡�����ȴ�
		@return	next item�� �����ϸ� return true, �ƴϸ� return false
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
				cout << "\t�ߺ��� ID�� �ֽ��ϴ�\n";
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