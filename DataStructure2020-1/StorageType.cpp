#include "pch.h"
#include "StorageType.h"

StorageType::StorageType()
{
	m_sId = 0;
	CurrentNum = 0;
	MaxNum = MAXSTORAGE;
}

StorageType::StorageType(int max)
{
	m_sId = 0;
	CurrentNum = 0;
	MaxNum = max;
}

StorageType::~StorageType()
{

}

// Id�� ��ȯ�Ѵ�
int StorageType::GetId() const
{
	return m_sId;
}

// ���� �����̳� ������ ��ȯ�Ѵ�
int StorageType::GetCurrentNum() const
{
	return CurrentNum;
}

// �ִ� �����̳� ������ ��ȯ�Ѵ�
int StorageType::GetMaxNum() const
{
	return MaxNum;
}

void StorageType::SetId(int InId)
{
	m_sId = InId;
}

void StorageType::SetMaxNum(int InMaxNum)
{
	MaxNum = InMaxNum;
}

// �����̳ʸ���Ʈ�� �� á���� Ȯ��
bool StorageType::IsFull() const
{
	if (CurrentNum == MaxNum) return true;
	return false;
}
// �����̳ʸ���Ʈ�� ����
void StorageType::MakeEmpty()
{
	ContainerList.MakeEmpty();
}

// ���ϴ� container�� ã�Ƽ� parameter�� �����Ѵ�
bool StorageType::GetContainer(ContainerType& container)
{
	return ContainerList.Get(container);
}

// container�� list�� �߰��Ѵ�
bool StorageType::AddContainer(const ContainerType& container)
{
	if (IsFull()) {
		return false;
	}
	if (ContainerList.Add(container)) {
		CurrentNum++;
		return true;
	}
	return false;
}

// container�� list���� �����Ѵ�
bool StorageType::DeleteContainer(ContainerType& container)
{
	if (ContainerList.Delete(container)) {
		CurrentNum--;
		return true;
	}
	return false;
}

// ���ϴ� container�� list�� �����Ѵ�
bool StorageType::UpdateContainer(const ContainerType& container)
{
	return ContainerList.Replace(container);
}

// ���� container�� �ҷ��´�
bool StorageType::GetNextContainer(ContainerType& container)
{
	return ContainerList.GetNextItem(container);
}

// container����� ����Ѵ�
void StorageType::DisplayAllContainer()
{
	ContainerType container;
	ContainerList.ResetList();
	cout << "\t----------------------Container ���-----------------------\n";
	for (int i = 0; i < CurrentNum; i++) {
		ContainerList.GetNextItem(container);
		container.DisplayContainerOnScreen();
		container.DisplayAllPhoto();
		container.DisplayAllItem();
	}
}

// matserlist�� ������ container�� ���� ��� ������ ����Ѵ�
void StorageType::DisplayAllDetailsContainer(SortedList<ItemType>& ItemList)
{
	ContainerType container;
	ContainerList.ResetList();
	for (int i = 0; i < CurrentNum; i++) {
		ContainerList.GetNextItem(container);
		container.DisplayContainerOnScreen();
		container.DisplayAllPhoto();
		container.DisplayAllDetailsItem(ItemList);
	}
}
