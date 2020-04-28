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

// TempList�� item ������ return	
int TempType::GetNumOfItems() const
{
	return NumOfItems;
}

// TempList�� item�� Enqueue�Ѵ�
bool TempType::EnQueue(const ItemType& item)
{
	if (m_TempItemList.EnQueue(item)) {
		NumOfItems++;
		return true;
	};
	return false;
}

// TempList�� Dequeue�Ѵ�.
bool TempType::DeQueue(ItemType& item)
{
	if (m_TempItemList.DeQueue(item)) {
		NumOfItems++;
		return true;
	};
	return false;
}

// TempItemList�� ����.
void TempType::MakeEmpty()
{
	m_TempItemList.MakeEmpty();
}

// param�� Id�� ���� Id�� ���� item�� TempItemList���� ã�� ������
bool TempType::Retrieve(ItemType& item)
{
	if (m_TempItemList.Retrieve(item)) return true;
	return false;
}

// param�� Id�� ���� Id�� ���� item�� TempItemList���� ã�� �����ϰ� ������1
bool TempType::Delete(ItemType& item)
{
	if (Delete(item)) {
		NumOfItems--;
		return true;
	}
	return false;
}

// param�� Id�� ���� Id�� ���� item�� TempItemList���� ã�� ������ Replace�Ѵ�.
bool TempType::Replace(const ItemType& item)
{
	if (Replace(item)) return true;
	return false;
}

// TempItemList�� �ִ� ��� ���Ҹ� Display�Ѵ�.	
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
		cout << "\tã�� ������ item�� �������� �ʽ��ϴ�.\n";
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
		cout << "\tã�� �̸��� item�� �������� �ʽ��ϴ�.\n";
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
		cout << "\tã�� �������� item�� �������� �ʽ��ϴ�.\n";
		return false;
	}
	return true;
}

