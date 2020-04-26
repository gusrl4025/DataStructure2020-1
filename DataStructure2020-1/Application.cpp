#include "Application.h"

// run program(receive the command and execute the function)
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 물품 정보를 입력 받아 리스트에 추가					
			AddItem();
			break;
		case 2:		// 물품의 고유번호를 입력 받아 리스트에서 삭제					
			GetCommandMaster();
			break;
		case 3:		// 물품 정보를 입력 받아서 리스트에서 해당 물품 정보를 갱신			
			GetCommandContainer();
			break;
		case 4:		// 입력된 종류의 모든 물품을 화면에 출력
			GetCommandTemp();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// run program(receive the command and execute the function)
void Application::RunMaster()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// Item을 입력받아 ContainerId가 있으면 MasterList -1이면 TempList에 넣는다.					
			AddItem();
			break;
		case 2:		// receive keynumber from keyboard and find item in Masterlist which same keynumber and delete that item
			DeleteItemMasterList();
			break;
		case 3:		// receive Goods record from keyboard and find item has same keynumber and replace the record with new record	
			ReplaceItemMasterList();
			break;
		case 4:		// receive ID from keyboard and find item which has same ID and display that record on screen
			RetrieveItemMasterList();
			break;
		case 5:		// receive word from keyboard and display the kind of item Kind display that record on screen
			SearchByKindMasterList();
			break;
		case 6:		// receive Name from keyboard and find item which Name include the Name and display that record on screen				
			SearchByNameMasterList();
			break;
		case 7:		// receive PurchaseDay from keyboard and find item which Name include the PurchaseDay and display that record on screen
			SearchByPurchaseDayMasterList();
			break;
		case 8:		// make MasterList empty
			MakeEmptyMasterList();
			break;
		case 9: 	// display all records in list on screen
			DisplayAllItemMasterList();
			break;
		case 10:	// move item in MasterList to TempList
			MoveItemMasterToTemp();
			break;
		case 0:
			Run();
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// run program(receive the command and execute the function)
void Application::RunContainer()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 물품 정보를 입력 받아 리스트에 추가					
			AddItem();
			break;
		case 2:		// 물품의 고유번호를 입력 받아 리스트에서 삭제					
			PrintContainerList();
			break;
		case 3:		// 물품 정보를 입력 받아서 리스트에서 해당 물품 정보를 갱신			
			AddPhoto();
			break;
		case 4:		// 입력된 종류의 모든 물품을 화면에 출력
			DeletePhoto();
			break;
		case 5:		// 물품명에 입력된 단어가 포함된 모든 물품을 화면에 출력
			UpdatePhoto();
			break;
		case 6:		// 입력된 정보로 리스트에서 물품을 찾아서 화면에 출력				
			PrintPhotoList();
			break;
		case 7:		// 리스트에 저장된 모든 물품을 화면에 출력
			RetrieveItemContainerList();
			break;
		case 8: 	// 리스트에 입력된 모든 물품을 삭제
			SearchByKindContainerList();
			break;
		case 9:		// load list data from a file.
			SearchByNameContainerList();
			break;
		case 10:	// save list data into a file.
			MakeEmptyContainer();
			break;
		case 11:	// save list data into a file.
			DisplayAllItemContainerList();
			break;
		case 0:
			Run();
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// run program(receive the command and execute the function)
void Application::RunTemp()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 물품 정보를 입력 받아 리스트에 추가					
			AddItem();
			break;
		case 2:		// receive keynumber from keyboard and find item in TempList which same keynumber and delete that item					
			DeleteItemTempList();
			break;
		case 3:		// receive Goods record from keyboard and find item has same keynumber and replace the record with new record		
			ReplaceItemTempList();
			break;
		case 4:		// receive ID from keyboard and find item which has same ID and display that record on screen
			RetrieveItemTempList();
			break;
		case 5:		// receive word from keyboard and display the kind of item Kind display that record on screen
			SearchByKindTempList();
			break;
		case 6:		// receive Name from keyboard and find item which Name include the Name and display that record on screen			
			SearchByNameTempList();
			break;
		case 7:		// receive PurchaseDay from keyboard and find item which Name include the PurchaseDay and display that record on screen
			SearchByPurchaseDayTempList();
			break;
		case 8: 	// make TempList empty
			MakeEmptyTempList();
			break;
		case 9:		// display all records in list on screen
			DisplayAllItemTempList();
			break;
		case 10:	// move item in TempList to MasterList
			MoveItemTempToMaster();
			break;
		case 0:
			Run();
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// shows menu and receive the command from keyboard
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t집안물품 정리 프로그램에 접속하신 것을 환영합니다!!\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : Add Item\n";
	cout << "\t 2 : MasterList에 접근하기\n";
	cout << "\t 3 : ContainerList에 접근하기\n";
	cout << "\t 4 : TempList에 접근하기\n";
	cout << "\t 0 : 프로그램 종료" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

int Application::GetCommandMaster()
{
	int command;
	cout << endl << endl;
	cout << "\tMasterList에서 실행할 command를 입력하세요\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : Item 추가하기\n";
	cout << "\t 2 : Item 제거하기\n";
	cout << "\t 3 : Item 업데이트\n";
	cout << "\t 4 : Item 검색하기\n";
	cout << "\t 5 : 종류로 Item 검색하기\n";
	cout << "\t 6 : 이름으로 Item 검색하기\n";
	cout << "\t 7 : 구매일로 Item 검색하기\n";
	cout << "\t 8 : MasterList 비우기\n";
	cout << "\t 9 : 모든 Item 출력하기\n";
	cout << "\t 10 : TempList로 Item 옮기기 \n";
	cout << "\t 0 : 목록으로 돌아가기\n" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

int Application::GetCommandContainer()
{
	int command;
	cout << endl << endl;
	cout << "\tContainerList에서 실행할 command를 입력하세요\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : Item 추가하기\n";
	cout << "\t 2 : Container 목록 출력하기\n";
	cout << "\t 3 : 사진 저장하기\n";
	cout << "\t 4 : 사진 제거하기\n";
	cout << "\t 5 : 사진 업데이트하기\n";
	cout << "\t 6 : 사진 목록 출력\n";
	cout << "\t 7 : Item 검색하기\n";
	cout << "\t 8 : 종류로 Item 검색하기\n";
	cout << "\t 9 : 이름으로 Item 검색하기\n";
	cout << "\t 10 : Container 하나 비우기\n";
	cout << "\t 11 : Container 하나의 모든 Item 출력하기\n";
	cout << "\t 0 : 목록으로 돌아가기\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

int Application::GetCommandTemp()
{
	int command;
	cout << endl << endl;
	cout << "\tTempList에서 실행할 command를 입력하세요\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : Item 추가하기\n";
	cout << "\t 2 : Item 제거하기 \n";
	cout << "\t 3 : Item 업데이트하기\n";
	cout << "\t 4 :	Item 검색하기\n";
	cout << "\t 5 : 종류로 Item 검색하기\n";
	cout << "\t 6 : 이름으로 Item 검색하기\n";
	cout << "\t 7 : 구매일로 Item 검색하기\n";
	cout << "\t 8 : TempList 비우기\n";
	cout << "\t 9 : 모든 Item 출력하기\n";
	cout << "\t 10 : MasterList로 Item 옮기기 \n";
	cout << "\t 0 : 목록으로 돌아가기\n" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// receive Goods record from keyboard and add to list
bool Application::AddItem() {
	ItemType item;
	item.SetGoodsFromKB(); // item을 입력받는다
	if (item.GetContainerId() == -1) {	// ContainerId == -1이면 TemptList에 저장
		m_TempList.EnQueue(item);
		return true;
	}
	else { // ContainerId가 -1이 아니면
		ContainerType container(item.GetContainerId()); // ContainerId를 가진 container를 하나 생성
		if (m_ContainerList.Retrieve_Binary(container)) {
			container.AddItem(item);
			m_ContainerList.Replace(container);
			return true;
		}
		else { // Container가 존재하지 않으면
			cout << "\tContainer가 존재하지 않아 새로 만들었습니다\n";
			m_ContainerList.Add(container); // List에 container를 추가
			container.AddItem(item); // 그리고 그 container에 item을 추가
			return true;
		}
	}
	return false;
}

// receive Id from keyboard and find item in list which has same Id and delete that item
bool Application::DeleteItemMasterList() {
	ItemType data;
	data.SetIdFromKB();
	if (!m_MasterList.Delete(data)) {
		cout << "\t삭제하려는 Goods이 존재하지 않습니다\n";
		return false;
	}
}

// receive Id from keyboard and find item which has same Id and display that record on screen
int Application::ReplaceGoods() {
	ItemType data;
	data.SetGoodsFromKB();
	if (m_List.Replace(data)) return 1;
	cout << "\t바꾸려는 Goods이 존재하지 않습니다\n";
}

// receive word from keyboard and display the kind of item Kind display that record on screen
int Application::SearchByKind() {
	ItemType data;
	string inKind;
	cout << "\t원하는 물품의 종류를 입력하시오(1:필기류, 2:책) : ";
	cin >> inKind;
	int list_Length = m_List.GetLength();
	bool found = false;
	m_List.ResetList();
	for (int i = 0; i < list_Length; i++) {
		m_List.GetNextItem(data);
		if (data.GetKind() == inKind) {
			data.DisplayGoodsOnScreen();
			found = true;
		}
	}
	if (!found) cout << "\t찾으려는 종류의 물품이 존재하지 않습니다\n";

	return found;

}

// receive word from ID and find item which name include the word and display that record on screen
int Application::SearchByName() {
	ItemType data;
	string inName;
	cout << "\t원하는 물품명을 입력하시오 : ";
	cin >> inName;
	int list_Length = m_List.GetLength();
	bool found = false;
	m_List.ResetList();
	for (int i = 0; i < list_Length; i++) {
		m_List.GetNextItem(data);
		if (data.GetName().find(inName) != -1) {
			data.DisplayGoodsOnScreen();
			found = true;
		}
	}
	if (!found) cout << "\t찾으려는 물품이 존재하지 않습니다\n";

	return found;
}

// receive Id from keyboardand find item which has same Id and display that record on screen
int Application::RetrieveGoods() {
	ItemType data;
	data.SetIdFromKB();
	if (m_List.Retrieve_Binary(data)) {
		data.DisplayGoodsOnScreen();
		return 1;
	}
	cout << "\t출력하려는 Goods이 존재하지 않습니다\n";
	return 0;
}

// display all records in list on screen
void Application::DisplayAllGoods() {
	ItemType data;
	m_List.ResetList();
	int list_Length = m_List.GetLength();
	for (int i = 0; i < list_Length; i++) {
		m_List.GetNextItem(data);
		data.DisplayGoodsOnScreen();
	}
}