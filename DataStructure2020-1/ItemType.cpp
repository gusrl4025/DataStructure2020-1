#include "ItemType.h"

// set Kind of Goods from keyboard
void ItemType::SetKindFromKB() {
	cout << "\t물품의 종류을 입력하시오(책=1, 학용품=2, 화장품=3, 전자제품=4, 기타=0) : ";
	cin >> m_Kind;
}

// set PurchaseDay of Goods from keyboard
void ItemType::SetPurchaseDayFromKB() {
	cout << "\t물품의 구매일를 입력하시오 : ";
	cin >> m_PurchaseDay;
}

// set Name of Goods from keyboard
void ItemType::SetNameFromKB() {
	cout << "\t물품의 이름을 입력하시오 : ";
	cin >> m_Name;
}

// set Price of Goods from keyboard
void ItemType::SetPriceFromKB() {
	cout << "\t물품의 수를 입력하시오 : ";
	cin >> m_Price;
}

// set Id of Goods from keyboard
void ItemType::SetIdFromKB() {
	cout << "\t물품의 고유번호를 입력하시오 : ";
	cin >> m_Id;
}

// set Id of Goods from keyboard
void ItemType::SetContainerIdFromKB() {
	cout << "\t물품을 저장할 박스의 번호를 입력하시오(어디에 저장할지 모를 때 -1로 입력하시오) : ";
	cin >> m_ContainerId;
}

// set Goods record from keyboard
void ItemType::SetGoodsFromKB() {
	SetKindFromKB();
	SetPurchaseDayFromKB();
	SetNameFromKB();
	SetPriceFromKB();
	SetIdFromKB();
	SetContainerIdFromKB();
}

// display Kind of Goods on screeen
void ItemType::DisplayKindOnScreen() {
	cout << "\tKind : " << m_Kind << "\n";
}

// display PurchaseDay of Goods on
void ItemType::DisplayPurchaseDayOnScreen() {
	cout << "\tPurchaseDay : " << m_PurchaseDay << "\n";
}

// display Name of Goods on screeen
void ItemType::DisplayNameOnScreen() {
	cout << "\tName : " << m_Name << "\n";
}

// display Price of Goods on screeen
void ItemType::DisplayPriceOnScreen() {
	cout << "\tPrice : " << m_Price << "\n";
}

// display Id of Goods on screeen
void ItemType::DisplayIdOnScreen() {
	cout << "\tId : " << m_Id << "\n";
}

// display Id of Goods on screeen
void ItemType::DisplayContainerIdOnScreen() {
	cout << "\tContainerId : " << m_ContainerId << "\n";
}

// display Goods record on screeen
void ItemType::DisplayGoodsOnScreen() {
	DisplayKindOnScreen();
	DisplayPurchaseDayOnScreen();
	DisplayNameOnScreen();
	DisplayPriceOnScreen();
	DisplayIdOnScreen();
	DisplayContainerIdOnScreen();
	cout << "\n\n";
}
