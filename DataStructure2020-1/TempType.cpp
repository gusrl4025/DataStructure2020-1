#include "pch.h"
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

bool TempType::IsFull() const
{
	if (NumOfItems == MAXQUEUE) return true;
	return false;
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
void TempType::DisplayAllTempItems()
{
	ItemType item;
	m_TempItemList.ResetList();
	for (int i = 0; i < NumOfItems; i++) {
		m_TempItemList.GetNextItem(item);
		item.DisplayGoodsOnScreen();
	}
}

bool TempType::SearchByKind()
{
	ItemType item;
	ItemType temp;
	bool found;
	item.SetKindFromKB();
	m_TempItemList.ResetList();
	while (m_TempItemList.GetNextItem(temp) == true) {
		if (temp.GetKind() == item.GetKind()) {
			temp.DisplayGoodsOnScreen();
			found = true;
		}
	}
	if (!found) {
		cout << "\t찾는 종류의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

bool TempType::SearchByName()
{
	ItemType item;
	ItemType temp;
	bool found;
	item.SetNameFromKB();
	m_TempItemList.ResetList();
	while (m_TempItemList.GetNextItem(temp) == true) {
		if (temp.GetName() == item.GetName()) {
			temp.DisplayGoodsOnScreen();
			found = true;
		}
	}
	if (!found) {
		cout << "\t찾는 이름의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

bool TempType::SearchByPurchaseDay()
{
	ItemType item;
	ItemType temp;
	bool found;
	item.SetPurchaseDayFromKB();
	m_TempItemList.ResetList();
	while (m_TempItemList.GetNextItem(temp) == true) {
		if (temp.GetPurchaseDay() == item.GetPurchaseDay()) {
			temp.DisplayGoodsOnScreen();
			found = true;
		}
	}
	if (!found) {
		cout << "\t찾는 구매일의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

