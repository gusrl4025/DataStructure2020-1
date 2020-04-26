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

// m_ContainerId를 가져온다
int ContainerType::GetContainerId() const
{
	return m_ContainerId;
}

// item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 추가한다.
bool ContainerType::AddItem(const ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Add(SimpleItem)) return true;
	return false;
}

// item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 제거한다.
bool ContainerType::DeleteItem(ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Delete(SimpleItem)) return true;
	return false;
}

// item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 교체한다.
bool ContainerType::UpdateItem(const ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Replace(SimpleItem)) return true;
	return false;
}

// photo를 m_photoList에 추가한다.
bool ContainerType::AddPhoto(const string& photo)
{
	if (m_PhotoList.Add(photo)) return true;
	return false;
}

// photo를 m_photoList에 제거한다.
bool ContainerType::DeletePhoto(string& photo)
{
	if (m_PhotoList.Delete(photo)) return true;
	return false;
}

// photo를 m_photoList에 교체한다.
bool ContainerType::UpdatePhoto(const string& photo)
{
	if (m_PhotoList.Replace(photo)) return true;
	return false;
}

// m_SimpleItemList에 있는 모든 item을 display한다.
void ContainerType::DisplayAllItem()
{
	SimpleItemType item;
	m_SimpleItemList.ResetList();
	int length = m_SimpleItemList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_SimpleItemList.GetNextItem(item);
	}
}

// m_PhotoList에 있는 모든 photo를 display한다.
void ContainerType::DisplayAllPhoto()
{
	string photo;
	m_PhotoList.ResetList();
	int length = m_PhotoList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_PhotoList.GetNextItem(photo);
	}
}

// SimpleItem의 Name을 입력받아 m_SimpleItemList에서 같은 Name을 가진 item을 참조한다.
bool ContainerType::FindByName(SimpleItemType& item)
{
	m_SimpleItemList.ResetList();
	string InName;
	cout << "\t찾으려는 item의 이름을 입력하시오 : ";
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

// SimpleItem의 Kind을 입력받아 m_SimpleItemList에서 같은 Kind을 가진 item을 참조한다.
bool ContainerType::FindByKind(SimpleItemType& item)
{
	m_SimpleItemList.ResetList();
	string InKind;
	cout << "\t찾으려는 item의 종류를 입력하시오 : ";
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