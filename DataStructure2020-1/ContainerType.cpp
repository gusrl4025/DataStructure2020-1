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

// m_Id�� �����´�
int ContainerType::GetId() const
{
	return m_Id;
}

// m_Location�� �����´�
string ContainerType::GetLocation() const
{
	return m_Location;
}

// Id�� �����Ѵ�
void ContainerType::SetId(int InId)
{
	m_Id = InId;
}

void ContainerType::SetLocation(string InLocation)
{
	m_Location = InLocation;
}

// Id�� Ű����κ��� �޾� �����Ѵ�
void ContainerType::SetIdFromKB()
{
	int InId;
	cout << "\tId�� �Է��Ͻÿ� : ";
	cin >> InId;
	m_Id = InId;
}

void ContainerType::SetLocationFromKB()
{
	string InLocation;
	cout << "\tLocation�� �Է��Ͻÿ� : ";
	cin >> InLocation;
	m_Location = InLocation;
}

// Container�� �⺻������ Ű����κ��� �޾� �����Ѵ�.
void ContainerType::SetContainerFromKB()
{
	SetIdFromKB();
	SetLocationFromKB();
}

// Id�� ����Ѵ�.
void ContainerType::DisplayIdOnScreen()
{
	cout << "\tID : " << m_Id << "\n";
}

void ContainerType::DisplayLocationOnScreen()
{
	cout << "Location : " << m_Location << "\n";
}

void ContainerType::DisplayContainerOnScreen()
{
	DisplayIdOnScreen();
	DisplayLocationOnScreen();
	cout << "\n";
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

// Container�� ������ ����Ѵ�
void ContainerType::DisplayContainerInfo()
{
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