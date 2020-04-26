#include "ContainerType.h"

// Constructor
ContainerType::ContainerType()
{
	m_ContainerId = 0;
	m_Location = "";
}

// Constructor
ContainerType::ContainerType(int InContainerId)
{
	m_ContainerId = InContainerId;
	m_Location = "";
}

// Constructor
ContainerType::ContainerType(int InContainerId, string InLocation)
{
	m_ContainerId = InContainerId;
	m_Location = InLocation;
}

// Destructor
ContainerType::~ContainerType()
{
}

// m_ContainerId�� �����´�
int ContainerType::GetContainerId() const
{
	return m_ContainerId;
}

// item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� �߰��Ѵ�.
bool ContainerType::AddItem(const ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Add(SimpleItem)) return true;
	return false;
}

// item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� �����Ѵ�.
bool ContainerType::DeleteItem(ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Delete(SimpleItem)) return true;
	return false;
}

// item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� ��ü�Ѵ�.
bool ContainerType::UpdateItem(const ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Replace(SimpleItem)) return true;
	return false;
}

// photo�� m_photoList�� �߰��Ѵ�.
bool ContainerType::AddPhoto(const string& photo)
{
	if (m_PhotoList.Add(photo)) return true;
	return false;
}

// photo�� m_photoList�� �����Ѵ�.
bool ContainerType::DeletePhoto(string& photo)
{
	if (m_PhotoList.Delete(photo)) return true;
	return false;
}

// photo�� m_photoList�� ��ü�Ѵ�.
bool ContainerType::UpdatePhoto(const string& photo)
{
	if (m_PhotoList.Replace(photo)) return true;
	return false;
}

// m_SimpleItemList�� �ִ� ��� item�� display�Ѵ�.
void ContainerType::DisplayAllItem()
{
	SimpleItemType item;
	m_SimpleItemList.ResetList();
	int length = m_SimpleItemList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_SimpleItemList.GetNextItem(item);
	}
}

// m_PhotoList�� �ִ� ��� photo�� display�Ѵ�.
void ContainerType::DisplayAllPhoto()
{
	string photo;
	m_PhotoList.ResetList();
	int length = m_PhotoList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_PhotoList.GetNextItem(photo);
	}
}

// SimpleItem�� Name�� �Է¹޾� m_SimpleItemList���� ���� Name�� ���� item�� �����Ѵ�.
bool ContainerType::FindByName(SimpleItemType& item)
{
	m_SimpleItemList.ResetList();
	string InName;
	cout << "\tã������ item�� �̸��� �Է��Ͻÿ� : ";
	cin >> InName;
	int length = m_SimpleItemList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_SimpleItemList.GetNextItem(item);
		if (item.GetName() == InName) {
			return true;
		}
	}
	return false;
}

// SimpleItem�� Kind�� �Է¹޾� m_SimpleItemList���� ���� Kind�� ���� item�� �����Ѵ�.
bool ContainerType::FindByKind(SimpleItemType& item)
{
	m_SimpleItemList.ResetList();
	string InKind;
	cout << "\tã������ item�� ������ �Է��Ͻÿ� : ";
	cin >> InKind;
	int length = m_SimpleItemList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_SimpleItemList.GetNextItem(item);
		if (item.GetKind() == InKind) {
			return true;
		}
	}
	return false;
}