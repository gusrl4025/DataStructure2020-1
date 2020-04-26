#include "pch.h"

class ContainerType
{
public:
	ContainerType();
	ContainerType(int InContainerId);
	ContainerType(int InContainerId, string InLocation);
	~ContainerType();

	/*
		@brief	m_ContainerId�� �����´�
		@pre	ContainerType�� initialize �ž��Ѵ�.
		@post	none
	*/
	int GetContainerId() const;

	/*
		@brief	item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� �߰��Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	m_SimpleItemList�� item�� �߰��ƴ�.
		@param	item	SimpleItem���� �ٲ��� data
		@return	return true if function works, otherwise return false
	*/
	bool AddItem(const ItemType& item);

	/*
		@brief	item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� �����Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	m_SimpleItemList�� item�� ���ŵƴ�.
		@param	item	SimpleItem���� �ٲ��� data
		@return	return true if function works, otherwise return false
	*/
	bool DeleteItem(ItemType& item);

	/*
		@brief	item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� ��ü�Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	m_SimpleItemList�� item�� ��ü�ƴ�.
		@param	item	SimpleItem���� �ٲ��� data
		@return	return true if function works, otherwise return false
	*/
	bool UpdateItem(const ItemType& item);

	/*
		@brief	photo�� m_photoList�� �߰��Ѵ�.
		@pre	m_photoList�� initialize�ž��Ѵ�
		@post	m_photoList�� photo�� �߰��ƴ�.
		@param	photo	list�� �߰��� photo
		@return	return true if function works, otherwise return false
	*/
	bool AddPhoto(const string& photo);

	/*
		@brief	photo�� m_photoList�� �����Ѵ�.
		@pre	m_photoList�� initialize�ž��Ѵ�
		@post	m_photoList�� photo�� ���ŵƴ�.
		@param	photo	list���� ������ photo
		@return	return true if function works, otherwise return false
	*/
	bool DeletePhoto(string& photo);

	/*
		@brief	photo�� m_photoList�� ��ü�Ѵ�.
		@pre	m_photoList�� initialize�ž��Ѵ�
		@post	m_photoList�� photo�� ��ü�ƴ�.
		@param	photo	list�� ��ü�� photo
		@return	return true if function works, otherwise return false
	*/
	bool UpdatePhoto(const string& photo);

	/*
		@brief	m_SimpleItemList�� �ִ� ��� item�� display�Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	m_SimpleList�� �ִ� ��� item�� display�ȴ�.
	*/
	void DisplayAllItem();

	/*
		@brief	m_PhotoList�� �ִ� ��� photo�� display�Ѵ�.
		@pre	m_PhotoList�� initialize�ž��Ѵ�
		@post	m_PhotoList�� �ִ� ��� photo�� display�ȴ�.
	*/
	void DisplayAllPhoto();

	/*
		@brief	SimpleItem�� Name�� �Է¹޾� m_SimpleItemList���� ���� Name�� ���� item�� �����Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	ã������ Name�� ���� item�� �����ȴ�.
		@param	item	param�� ã������ item�� �����Ѵ�.
		@return	���ϴ� item�� ã���� return true, �ƴϸ� return false
	*/
	bool FindByName(SimpleItemType& item);

	/*
		@brief	SimpleItem�� Kind�� �Է¹޾� m_SimpleItemList���� ���� Kind�� ���� item�� �����Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	ã������ Kind�� ���� item�� �����ȴ�.
		@param	item	param�� ã������ item�� �����Ѵ�.
		@return	���ϴ� item�� ã���� return true, �ƴϸ� return false
	*/
	bool FindByKind(SimpleItemType& item);

	bool operator==(const ContainerType& container) {
		if (GetContainerId() == container.GetContainerId()) return true;
		return false;
	}

	bool operator>(const ContainerType& container) {
		if (GetContainerId() > container.GetContainerId()) return true;
		return false;
	}

	bool operator<(const ContainerType& container) {
		if (GetContainerId() < container.GetContainerId()) return true;
		return false;
	}

private:
	int m_ContainerId;
	string m_Location;
	UnSortedList<string> m_PhotoList;
	UnSortedList<SimpleItemType> m_SimpleItemList;
};
