#include "StorageType.h"

// Id를 반환한다
int StorageType::GetId() const
{
	return m_sId;
}

// 현재 컨테이너 개수를 반환한다
int StorageType::GetCurrentNum() const
{
	return CurrentNum;
}

// 최대 컨테이너 개수를 반환한다
int StorageType::GetMaxNum() const
{
	return MaxNum;
}

// 컨테이너리스트가 꽉 찼는지 확인
bool StorageType::IsFull() const
{
	if (CurrentNum == MaxNum) return true;
	return false;
}

// 원하는 container를 찾아서 parameter에 참조한다
bool StorageType::GetContainer(ContainerType& container)
{
	return ContainerList.Get(container);
}

// container를 list가 추가한다
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

// container를 list에서 제거한다
bool StorageType::DeleteContainer(ContainerType& container)
{
	if (ContainerList.Delete(container)) {
		CurrentNum--;
		return true;
	}
	return false;
}

// 원하는 container를 list에 수정한다
bool StorageType::UpdateContainer(const ContainerType& container)
{
	return ContainerList.Replace(container);
}

// 다음 container를 불러온다
bool StorageType::GetNextContainer(ContainerType& container)
{
	return ContainerList.GetNextItem(container);
}

// container목록을 출력한다
void StorageType::DisplayAllContainer()
{
	ContainerType container;
	ContainerList.ResetList();
	for (int i = 0; i < CurrentNum; i++) {
		ContainerList.GetNextItem(container);
		container.DisplayContainerOnScreen();
	}
}



// container아이템을 모두 출력한다
void StorageType::DisplayAllDetailsContainer(SortedList<ItemType>& ItemList)
{
	
}
