#include "StorageType.h"

int StorageType::GetId() const
{
	return m_sId;
}

int StorageType::GetCurrentNum() const
{
	return CurrentNum;
}

int StorageType::GetMaxNum() const
{
	return MaxNum;
}

bool StorageType::IsFull() const
{
	if (CurrentNum == MaxNum) return true;
	return false;
}

bool StorageType::GetContainer(ContainerType& container)
{
	return ContainerList.Get(container);
}

bool StorageType::AddContainer(ContainerType& container)
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

bool StorageType::DeleteContainer(ContainerType& container)
{
	if (ContainerList.Delete(container)) {
		CurrentNum--;
		return true;
	}
	return false;
}

bool StorageType::UpdateContainer(ContainerType& container)
{
	return ContainerList.Replace(container);
}

void StorageType::DisplayAllContainer()
{
}

void StorageType::DisplayAllDetailsContainer(SortedList<ItemType>& ItemList)
{
}
