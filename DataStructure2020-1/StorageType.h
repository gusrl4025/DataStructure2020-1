#pragma once

class ContainerType;

class StorageType
{
public:
	/*
		constructor
	*/
	StorageType();

	StorageType(int max);
	/*
		Destructor
	*/
	~StorageType();
		
	/*
		@brief	Id�� ��ȯ�Ѵ�
		@pre	none
		@post	none
		@return	return m_sId
	*/
	int GetId() const;

	/*
		@brief	���� �����̳� ������ ��ȯ�Ѵ�
		@pre	none
		@post	none
		@return	return CurrentNum
	*/
	int GetCurrentNum() const;

	/*
		@brief	�ִ� �����̳� ������ ��ȯ�Ѵ�
		@pre	none
		@post	none
		@return	return MaxNum
	*/
	int GetMaxNum() const;

	/*
		@brief	Id�� �Է��Ѵ�
		@pre	none
		@post	none
	*/
	void SetId(int InId);

	/*
		@brief	MaxNum�� �����Ѵ�
		@pre	none
		@post	none
	*/
	void SetMaxNum(int InMaxNum);

	/*
		@brief	�����̳ʸ���Ʈ�� �� á���� Ȯ��
		@pre	list�� �ʱ�ȭ�ž��Ѵ�
		@post	none
		@return	list�� full �̸� return true, �ƴϸ� return false
	*/
	bool IsFull() const;

	/*
		@brief	�����̳ʸ���Ʈ�� ����
		@pre	none
		@post	�����̳ʸ���Ʈ�� �������
	*/
	void MakeEmpty();

	/*
		@brief	���ϴ� container�� ã�Ƽ� parameter�� �����Ѵ�
		@pre	list�� �ʱ�ȭ�ž��Ѵ�
		@post	ã�� container�� parameter�� �����ȴ�
		@param	container	ã�� container�� ������
		@return	���ϴ� container�� ã������ return true, �ƴϸ� return false
	*/
	bool GetContainer(ContainerType& container);

	/*
		@brief	container�� list�� �߰��Ѵ�
		@pre	list�� �ʱ�ȭ�ž��Ѵ�
		@post	new container�� list�� �߰���
		@param	container	�߰��� container
		@return	container�� �߰������� return true, �ƴϸ� return false
	*/
	bool AddContainer(const ContainerType& container);

	/*
		@brief	container�� list���� �����Ѵ�
		@pre	list�� �ʱ�ȭ�ž��Ѵ�
		@post	list���� container�� ���ŵ�
		@param	container	���ŵ� container
		@return	container�� ���ŵ����� return true, �ƴϸ� return false
	*/
	bool DeleteContainer(ContainerType& container);

	/*
		@brief	���ϴ� container�� list�� �����Ѵ�
		@pre	list�� �ʱ�ȭ�ž��Ѵ�
		@post	container�� list���� ������
		@param	container	������ container
		@return	container�� �߰������� return true, �ƴϸ� return false
	*/
	bool UpdateContainer(const ContainerType& container);

	/*
		@brief	���� container�� �ҷ��´�
		@pre	containerList�� �ʱ�ȭ�ž��Ѵ�.
		@post	parameter�� ���� container�� ������
		@param	container	���� container�� ������
		@return ���� container�� ������ return true, �ƴϸ� return false
	*/
	bool GetNextContainer(ContainerType& container);

	/*
		@brief	container����� ����Ѵ�
		@pre	containerlist�� �ʱ�ȭ�ž��Ѵ�
		@post	container����� ��µȴ�
	*/
	void DisplayAllContainer();

	/*
		@brief	matserlist�� ������ container�� ���� ��� ������ ����Ѵ�
		@pre	containerlist�� �ʱ�ȭ�ž��Ѵ�, MasterList�� �ʱ�ȭ�ž��Ѵ�
		@post	��� containerlist�� ������ ��µȴ�.
		@param	ItemList	MasterList�� �����Ѵ�	
	*/
	void DisplayAllDetailsContainer(SortedList<ItemType>& ItemList);

	bool operator==(StorageType& storage) {
		if (GetId() == storage.GetId()) return true;
		return false;
	}

	bool operator>(StorageType& storage) {
		if (GetId() > storage.GetId()) return true;
		return false;
	}

	bool operator<(StorageType& storage) {
		if (GetId() < storage.GetId()) return true;
		return false;
	}

	void operator=(StorageType& storage) {
		m_sId = storage.GetId();
		CurrentNum = storage.GetCurrentNum();
		MaxNum = storage.GetMaxNum();
		ContainerList = storage.ContainerList;
	}
private:
	int m_sId;
	int CurrentNum;
	int MaxNum;
	SingleLinkedList<ContainerType> ContainerList;
};