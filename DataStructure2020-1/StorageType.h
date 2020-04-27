#include "pch.h"

class StorageType
{
public:
	/*
		constructor
	*/
	StorageType();
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
		@brief	�����̳ʸ���Ʈ�� �� á���� Ȯ��
		@pre	list�� �ʱ�ȭ�ž��Ѵ�
		@post	none
		@return	list�� full �̸� return true, �ƴϸ� return false
	*/
	bool IsFull() const;

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
		@brief	container��ϰ� �������� ��� ����Ѵ�
		@pre	containerlist�� �ʱ�ȭ�ž��Ѵ�, MasterList�� �ʱ�ȭ�ž��Ѵ�
		@post	��� containerlist�� ������ ��µȴ�.
		@param	ItemList	MasterList�� �����Ѵ�	
	*/
	void DisplayAllDetailsContainer(SortedList<ItemType>& ItemList);
private:
	int m_sId;
	int CurrentNum;
	int MaxNum;
	SingleLinkedList<ContainerType> ContainerList;
};