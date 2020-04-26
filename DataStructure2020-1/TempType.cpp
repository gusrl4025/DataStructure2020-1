#include "TempType.h"

// constructor
TempType::TempType()
{
	NumOfItems = 0;
}

// destructor
TempType::~TempType()
{
}

// TempList의 item 개수를 return	
int TempType::GetNumOfItems() const
{
	return NumOfItems;
}

// TempList에 item을 Enqueue한다
bool TempType::EnQueue(const ItemType& item)
{
	if (m_TempItemList.EnQueue(item)) {
		NumOfItems++;
		return true;
	};
	return false;
}

// TempList을 Dequeue한다.
bool TempType::DeQueue(ItemType& item)
{
	if (m_TempItemList.DeQueue(item)) {
		NumOfItems++;
		return true;
	};
	return false;
}

// TempItemList를 비운다.
void TempType::MakeEmpty()
{
	m_TempItemList.MakeEmpty();
}

// param의 Id와 같은 Id를 가진 item을 TempItemList에서 찾아 참조함
bool TempType::Retrieve(ItemType& item)
{
	if (m_TempItemList.Retrieve(item)) return true;
	return false;
}

// param의 Id와 같은 Id를 가진 item을 TempItemList에서 찾아 삭제하고 참조함1
bool TempType::Delete(ItemType& item)
{
	if (Delete(item)) {
		NumOfItems--;
		return true;
	}
	return false;
}

// param의 Id와 같은 Id를 가진 item을 TempItemList에서 찾아 정보를 Replace한다.
bool TempType::Replace(const ItemType& item)
{
	if (Replace(item)) return true;
	return false;
}

// TempItemList에 있는 모든 원소를 Display한다.	
bool TempType::DisplayAllTempItems()
{
	ItemType item;
	m_TempItemList.ResetList();
	for (int i = 0; i < NumOfItems; i++) {
		m_TempItemList.GetNextItem(item);
		item.DisplayGoodsOnScreen();
	}
}

