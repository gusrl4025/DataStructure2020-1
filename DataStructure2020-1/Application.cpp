#include "pch.h"
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
			RunMaster();
			break;
		case 3:		// 물품 정보를 입력 받아서 리스트에서 해당 물품 정보를 갱신			
			RunStorage();
			break;
		case 4:		// 입력된 종류의 모든 물품을 화면에 출력
			RunTemp();
			break;
		case 5:
			RunAccountBook();
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
		m_Command = GetCommandMaster();

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
		case 8:
			SearchByPurchasePeriodMasterList();
			break;
		case 9:		// make MasterList empty
			MakeEmptyMasterList();
			break;
		case 10: 	// display all records in list on screen
			DisplayAllItemMasterList();
			break;
		case 11:	// move item in MasterList to TempList
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
int Application::RunStorage() {
	while (1)
	{
		m_Command = GetCommandStorage();

		switch (m_Command)
		{
		case 1:
			RunContainer(GetStorageId());
			break;
		case 2:
			DisplayAllContainer();
			break;
		case 3:
			DisPlayAllDetailsContainer();
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
void Application::RunContainer(int InStorageId)
{
	StorageType storage;
	storage.SetId(InStorageId);
	if (m_StorageList.Retrieve_Binary(storage)) {
		while (1)
		{
			m_Command = GetCommandContainer(InStorageId);

			switch (m_Command)
			{
			case 1:		// 물품 정보를 입력 받아 리스트에 추가					
				AddItem();
				break;
			case 2:		// 물품의 고유번호를 입력 받아 리스트에서 삭제					
				PrintContainerList(storage);
				break;
			case 3:		// 물품 정보를 입력 받아서 리스트에서 해당 물품 정보를 갱신			
				AddPhoto(storage);
				break;
			case 4:		// 입력된 종류의 모든 물품을 화면에 출력
				DeletePhoto(storage);
				break;
			case 5:		// 물품명에 입력된 단어가 포함된 모든 물품을 화면에 출력
				UpdatePhoto(storage);
				break;
			case 6:		// 입력된 정보로 리스트에서 물품을 찾아서 화면에 출력				
				PrintPhotoList(storage);
				break;
			case 7:		// 리스트에 저장된 모든 물품을 화면에 출력
				RetrieveItemContainerList(storage);
				break;
			case 8: 	// 리스트에 입력된 모든 물품을 삭제
				SearchByKindContainerList(storage);
				break;
			case 9:		// load list data from a file.
				SearchByNameContainerList(storage);
				break;
			case 10:	// save list data into a file.
				MakeEmptyContainer(storage);
				break;
			case 11:	// save list data into a file.
				DisplayAllItemContainer(storage);
				break;
			case 12:

			case 0:
				Run();
				break;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}
	else {
		cout << "\t찾으려는 저장소가 존재하지 않습니다.\n";
		RunStorage();
	}
}

// run program(receive the command and execute the function)
void Application::RunTemp()
{
	while (1)
	{
		m_Command = GetCommandTemp();

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

// run program(receive the command and execute the function)
void Application::RunAccountBook()
{
	while (1)
	{
		m_Command = GetCommandAccountBook();

		switch (m_Command)
		{
		case 1:
			DisplayDayExpenseRecord();
			break;
		case 2:		
			DisplayMonthExpenseRecord();
			break;
		case 3:		
			DisplayYearExpenseRecord();
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
	cout << "\t==================================================================\n";
	cout << "\t|집안물품 정리 및 가계부 관리 프로그램에 접속하신 것을 환영합니다|\n";
	cout << "\t=ID ======================= Command ==============================\n";
	cout << "\t 1 : Add Item\n";
	cout << "\t 2 : MasterList에 접근하기\n";
	cout << "\t 3 : StorageList에 접근하기\n";
	cout << "\t 4 : TempList에 접근하기\n";
	cout << "\t 5 : AccountBook에 접근하기\n";
	cout << "\t 0 : 프로그램 종료" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// shows menu and receive the command from keyboard
int Application::GetCommandMaster()
{
	int command;
	cout << endl << endl;
	cout << "\tMasterList에서 실행할 command를 입력하세요\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : Item 추가하기\n";
	cout << "\t 2 : Item 제거하기\n";
	cout << "\t 3 : Item 업데이트\n";
	cout << "\t 4 : Item 검색하기\n";
	cout << "\t 5 : 종류로 Item 검색하기\n";
	cout << "\t 6 : 이름으로 Item 검색하기\n";
	cout << "\t 7 : 구매일로 Item 검색하기\n";
	cout << "\t 8 : 일정기간 안에 구매한 Item 검색하기\n";
	cout << "\t 9 : MasterList 비우기\n";
	cout << "\t 10 : 모든 Item 출력하기\n";
	cout << "\t 11 : TempList로 Item 옮기기 \n";
	cout << "\t 0 : 목록으로 돌아가기\n" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// shows menu and receive the command from keyboard
int Application::GetCommandStorage()
{
	int command;
	cout << "\n\n";
	cout << "\tStorageList에서 실행할 command를 입력하세요\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : 접근할 Storage 입력\n";
	cout << "\t 2 : Storage 하나의 컨테이너들의 정보 출력\n";
	cout << "\t 3 : Storage 하나의 컨테이너들의 상세 정보 출력\n";
	cout << "\t 0 : 목록으로 돌아가기\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// shows menu and receive the command from keyboard
int Application::GetCommandContainer(int InStorageId)
{
	int command;
	cout << endl << endl;
	cout << "\t=====================Storage ID : " << InStorageId << "=====================\n";
	cout << "\tContainerList에서 실행할 command를 입력하세요\n";
	cout << "\t=ID ================= Command =====================\n";
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

// shows menu and receive the command from keyboard
int Application::GetCommandTemp()
{
	int command;
	cout << endl << endl;
	cout << "\tTempList에서 실행할 command를 입력하세요\n";
	cout << "\t=ID ================= Command =====================\n";
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

// shows menu and receive the command from keyboard
int Application::GetCommandAccountBook()
{
	int command;
	cout << endl << endl;
	cout << "\tAccountBook에서 실행할 command를 입력하세요\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : 원하는 날짜 소비 내역 보기\n";
	cout << "\t 2 : 원하는 달 소비 패턴 분석\n";
	cout << "\t 3 : 원하는 년도 소비 패턴 분석\n";
	cout << "\t 0 :	목록으로 돌아가기\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// receive Goods record from keyboard and add to list
bool Application::AddItem() {
	cout << "\t=====================Add item=====================\n";
	ItemType item;
	item.SetGoodsFromKB(); // item을 입력받는다
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1이면 TemptList에 저장
		if (!m_MasterList.Retrieve(item)) {
			if (m_TempList.EnQueue(item)) {
				cout << "\n\t Item저장에 성공했습니다\n";
				DisplayAllItemTempList();
				return true;
			}
			return false;
		}
		else {
			cout << "\n\t중복된 ID가 존재합니다\n";
			return false;
		}
	}
	else { // StorageId, ContainerList가 -1이 아니면
		StorageType storage; // StorageId를 가진 storage를 하나 생성
		storage.SetId(item.GetStorageId());
		if (!m_TempList.Retrieve(item)) {
			if (m_MasterList.Add(item)) {
				if (m_StorageList.Retrieve_Binary(storage)) { // StorageId와 같은 storage가 존재하면
					ContainerType container;
					container.SetId(item.GetContainerId());
					if (storage.GetContainer(container)) { // containerId와 같은 container가 존재하면
						if (container.AddItem(item)) {
							storage.UpdateContainer(container);
							m_StorageList.Replace(storage);
							cout << "\n\t Item저장에 성공했습니다.\n";
							cout << "\n\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
							return true;
						}
					}
					else { // containerId와 같은 container가 없을 시
						cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " 생성=====================\n";
						container.SetLocationFromKB();
						container.AddItem(item);
						if (storage.AddContainer(container)) {
							if (m_StorageList.Replace(storage)) {
								cout << "\n\t Item저장에 성공했습니다.\n";
								cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
								container.DisplayAllItem();
								return true;
							}
							else {
								cout << "\n\tItem저장에 실패했습니다\n";
								return false;
							}
						}
					}
				}
				else { // StorageId와 같은 storage가 존재하지 않을 때(container도 당연히 없다)
					int InMaxNum;
					cout << "\n\t=====================Storage:" << storage.GetId() << " 생성=====================\n";
					ContainerType container;
					cout << "\t해당하는 storage가 없어 새로 만듭니다.\n";
					cout << "\t최대 보관가능한 컨테이터의 개수를 입력하시오 : ";
					cin >> InMaxNum;
					storage.SetMaxNum(InMaxNum);
					cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << item.GetContainerId() << " 생성=====================\n";
					container.SetId(item.GetContainerId());
					container.SetLocationFromKB();
					container.AddItem(item);
					if (storage.AddContainer(container)) {
						if (m_StorageList.Add(storage)) {
							cout << "\n\t Item저장에 성공했습니다.\n";
							cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
							return true;
						}
					}
				}
			}
			return false;
		}
		return false;
	}
	return false;
}

// Item을 입력받아 ContainerId가 있으면 MasterList -1이면 TempList에 넣는다.
bool Application::AddItem(ItemType item) {
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1이면 TemptList에 저장
		if (!m_MasterList.Retrieve(item)) {
			if (m_TempList.EnQueue(item)) {
				cout << "\n\t Item저장에 성공했습니다\n";
				DisplayAllItemTempList();
				return true;
			}
			return false;
		}
		else return false;
	}
	else { // StorageId, ContainerList가 -1이 아니면
		StorageType storage; // StorageId를 가진 storage를 하나 생성
		storage.SetId(item.GetStorageId());
		if (!m_TempList.Retrieve(item)) {
			if (m_MasterList.Add(item)) {
				if (m_StorageList.Retrieve_Binary(storage)) { // StorageId와 같은 storage가 존재하면
					ContainerType container;
					container.SetId(item.GetContainerId());
					if (storage.GetContainer(container)) { // containerId와 같은 container가 존재하면
						if (container.AddItem(item)) {
							storage.UpdateContainer(container);
							m_StorageList.Replace(storage);
							cout << "\n\t Item저장에 성공했습니다.\n";
							cout << "\n\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
							return true;
						}
					}
					else { // containerId와 같은 container가 없을 시
						cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " 생성=====================\n";
						container.SetLocationFromKB();
						container.AddItem(item);
						if (storage.AddContainer(container)) {
							if (m_StorageList.Replace(storage)) {
								cout << "\n\t Item저장에 성공했습니다.\n";
								cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
								container.DisplayAllItem();
								return true;
							}
							else {
								cout << "\n\tItem저장에 실패했습니다\n";
								return false;
							}
						}
					}
				}
				else { // StorageId와 같은 storage가 존재하지 않을 때(container도 당연히 없다)
					int InMaxNum;
					cout << "\n\t=====================Storage:" << storage.GetId() << " 생성=====================\n";
					ContainerType container;
					cout << "\t해당하는 storage가 없어 새로 만듭니다.\n";
					cout << "\t최대 보관가능한 컨테이터의 개수를 입력하시오 : ";
					cin >> InMaxNum;
					storage.SetMaxNum(InMaxNum);
					cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << item.GetContainerId() << " 생성=====================\n";
					container.SetId(item.GetContainerId());
					container.SetLocationFromKB();
					container.AddItem(item);
					if (storage.AddContainer(container)) {
						if (m_StorageList.Add(storage)) {
							cout << "\n\t Item저장에 성공했습니다.\n";
							cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
							return true;
						}
					}
				}
			}
			return false;
		}
		return false;
	}
	return false;
}

// Id를 입력받아 MasterList와 Container에서 지워준다
bool Application::DeleteItemMasterList() {
	ItemType item;
	item.SetIdFromKB();
	if (m_MasterList.Retrieve(item)) {
		StorageType storage;
		storage.SetId(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container;
		container.SetId(item.GetContainerId());
		storage.GetContainer(container);
		if (container.DeleteItem(item)) {
			m_MasterList.Delete(item);
			cout << "\t=====================삭제 후 Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
			container.DisplayAllItem();
			return true;
		}
	}
	cout << "\tItem 삭제에 실패했습니다\n";
	return false;

}

// Item을 입력받아 MasterList와 Container에서 수정한다
bool Application::ReplaceItemMasterList()
{
	ItemType item;
	ItemType temp;
	item.SetGoodsExceptStorageFromKB();
	temp.SetId(item.GetId());
	if (m_MasterList.Retrieve(temp)) {
		item.SetContainerId(temp.GetContainerId());
		item.SetStorageId(temp.GetStorageId());
		StorageType storage;
		storage.SetId(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container;
		container.SetId(item.GetContainerId());
		storage.GetContainer(container);
		if (container.UpdateItem(item)) {
			m_MasterList.Replace(item);
			cout << "\t=====================수정 후 Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
			container.DisplayAllItem();
			return true;
		}
	}
	cout << "\tItem 수정에 실패했습니다\n";
	return false;
}

// Id을 입력받아 MasterList에서 검색한다
bool Application::RetrieveItemMasterList()
{
	ItemType item;
	item.SetIdFromKB();
	cout << "\n\t=====================Item ID:" << item.GetId() << "=====================\n";
	if (m_MasterList.Retrieve(item)) {
		item.DisplayGoodsOnScreen();
		return true;
	}
	cout << "\t찾는 item이 존재하지 않습니다.\n";
	return false;
}

// Inorder(ID 순서) 순으로 탐색하여 종류가 같은 아이템을 출력한다
void SearchByKind(BinaryTreeNode<ItemType>* root, const ItemType& item, bool& found) {
	if (root != NULL) {
		SearchByKind(root->left, item, found);
		if (root->data.GetKind() == item.GetKind()) {
			root->data.DisplayGoodsOnScreen();
			found = true;
		}
		SearchByKind(root->right, item, found);
	}
}

// item 종류를 입력받아 MasterList에서 검색한다
bool Application::SearchByKindMasterList()
{
	ItemType item;
	BinaryTreeNode<ItemType>* root = m_MasterList.GetRoot();
	bool found = false;
	item.SetKindFromKB();

	cout << "\n\t=====================Item Kind:" << item.GetKind() << "=====================\n";
	
	
	SearchByKind(root, item, found);

	if (!found) {
		cout << "\t찾는 종류의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;

}

// Inorder(ID 순서) 순으로 탐색하여 이름이 같은 아이템을 출력한다
void SearchByName(BinaryTreeNode<ItemType>* root, const ItemType& item, bool& found) {
	if (root != NULL) {
		SearchByKind(root->left, item, found);
		if (root->data.GetName() == item.GetName()) {
			root->data.DisplayGoodsOnScreen();
			found = true;
		}
		SearchByName(root->right, item, found);
	}
}

// item 이름을 입력받아 MasterList에서 검색한다
bool Application::SearchByNameMasterList()
{
	ItemType item;
	BinaryTreeNode<ItemType>* root = m_MasterList.GetRoot();
	bool found = false;
	item.SetNameFromKB();

	cout << "\n\t=====================Item Name:" << item.GetName() << "=====================\n";

	SearchByName(root, item, found);

	if (!found) {
		cout << "\t찾는 이름의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

// Inorder(ID 순서) 순으로 탐색하여 구매일 같은 아이템을 출력한다
void SearchByPurchaseDay(BinaryTreeNode<ItemType>* root, const ItemType& item, bool& found) {
	if (root != NULL) {
		SearchByPurchaseDay(root->left, item, found);
		if (root->data.GetPurchaseDay() == item.GetPurchaseDay()) {
			root->data.DisplayGoodsOnScreen();
			found = true;
		}
		SearchByPurchaseDay(root->right, item, found);
	}
}

// item의 구매일을 입력받아 MasterList에서 검색한다
bool Application::SearchByPurchaseDayMasterList()
{
	ItemType item;
	BinaryTreeNode<ItemType>* root = m_MasterList.GetRoot();
	bool found = false;
	item.SetPurchaseDayFromKB();

	cout << "\n\t=====================Item PurchaseDay:" << item.GetPurchaseDay() << "=====================\n";

	SearchByPurchaseDay(root, item, found);

	if (!found) {
		cout << "\t찾는 구매일의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
	
}

// Inorder(ID 순서) 순으로 탐색하여 구매 기간안의 아이템을 출력한다
void SearchByPurchasePeriod(BinaryTreeNode<ItemType>* root, const int& StartDay , const int& EndDay, bool& found) {
	if (root != NULL) {
		SearchByPurchasePeriod(root->left, StartDay, EndDay, found);
		if (root->data.GetPurchaseDay() >= StartDay && root->data.GetPurchaseDay() >= EndDay) {
			root->data.DisplayGoodsOnScreen();
			found = true;
		}
		SearchByPurchasePeriod(root->right, StartDay, EndDay, found);
	}
}

// item의 구매일을 구간으로 입력받아 MasterList에서 검색한다
bool Application::SearchByPurchasePeriodMasterList()
{
	BinaryTreeNode<ItemType>* root = m_MasterList.GetRoot();
	bool found = false;
	int StartDay, EndDay;
	cout << "\n\t찾으려는 구간의 시작일을 입력하시오(예: 19970602 (1997년6월2일)) :";
	cin >> StartDay;
	cout << "\t찾으려는 구간의 종료일을 입력하시오(예: 19970602 (1997년6월2일)) :";
	cin >> EndDay;
	if (StartDay > EndDay) {
		cout << "\t구간을 잘못 설정했습니다\n";
		return false;
	}

	cout << "\n\t=====================Item PurchaseDay:" << StartDay << "~" << EndDay << "=====================\n";
	
	SearchByPurchasePeriod(root, StartDay, EndDay, found);

	if (!found) {
		cout << "\t찾는 구간에 구매한 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

// make MasterList, StorageList empty
void Application::MakeEmptyMasterList()
{
	m_MasterList.MakeEmpty();
	StorageType storage;
	m_StorageList.ResetList();
	for (int CurPos = 0; CurPos < m_StorageList.GetLength(); CurPos++) {
		m_StorageList.GetNextItem(storage);
		ContainerType container;
		storage.ResetList();
		for (int i = 0; i < storage.GetCurrentNum(); i++) {
			storage.GetNextContainer(container);
			container.MakeEmpty();
			storage.UpdateContainer(container);
		}
		m_StorageList.Replace(storage);
	}
}

void DisplayAllItem(BinaryTreeNode<ItemType>* root) {
	if (root != NULL) {
		DisplayAllItem(root->left);
		root->data.DisplayGoodsOnScreen();
		DisplayAllItem(root->right);
	}
}

// display all records in MasterList on screen
void Application::DisplayAllItemMasterList()
{
	BinaryTreeNode<ItemType>* root = m_MasterList.GetRoot();

	cout << "\t=====================MastserList=====================\n";
	
	DisplayAllItem(root);
}

// move item in MasterList to TempList
bool Application::MoveItemMasterToTemp()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_MasterList.Retrieve(item)) {
		StorageType storage(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container(item.GetContainerId());
		storage.GetContainer(container);
		container.DeleteItem(item);
		storage.UpdateContainer(container);

		item.SetContainerId(-1);
		item.SetStorageId(-1);
		m_TempList.EnQueue(item);
		m_MasterList.Delete(item);
		cout << "\t성공적으로 이동했습니다\n";
		return true;
	}
	cout << "\t이동시키려는 Item이 존재하지 않습니다\n";
	return false;
}

// RunContainer에 쓸 StorageId를 입력받음	
int Application::GetStorageId()
{
	int InStorageId;
	cout << "\t접근하고자 하는 저장소의 ID를 입력하시오 : ";
	cin >> InStorageId;
	return InStorageId;
}

// StorageId를 입력받아 그 안에 있는 container의 정보와 리스트를 출력함
void Application::DisplayAllContainer()
{
	StorageType storage;
	int storageId;
	cout << "\t저장소의 ID를 입력하시오 : ";
	cin >> storageId;
	storage.SetId(storageId);
	if (m_StorageList.Retrieve_Binary(storage)) {
		cout << "\t=====================Storage:" << storage.GetId() << " Container 정보=====================\n";
		storage.DisplayAllContainer();
		cout << "\t-----------------------------------------------\n";
	}
	else {
		cout << "\t찾으려는 ID의 저장소가 없습니다.\n";
	}
}

// StorageId를 입력받아 그 안에 있는 container의 상세 정보와 리스트를 MasterList를 참조해 출력함
void Application::DisPlayAllDetailsContainer()
{
	StorageType storage;
	int storageId;
	cout << "\t저장소의 ID를 입력하시오 : ";
	cin >> storageId;
	storage.SetId(storageId);
	if (m_StorageList.Retrieve_Binary(storage)) {
		cout << "\t=====================Storage:" << storage.GetId() << " Container 정보=====================\n";
		storage.DisplayAllDetailsContainer(m_MasterList);
	}
	else {
		cout << "\t찾으려는 ID의 저장소가 없습니다.\n";
	}
}

// 저장소의 Container 목록을 출력한다
void Application::PrintContainerList(StorageType& storage)
{
	cout << "\t=====================Storage:" << storage.GetId() << " Container 정보=====================\n";
	storage.DisplayAllContainer();
}

// 저장소의 Container에 photo를 추가한다.
bool Application::AddPhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t추가할 Photo를 입력하시오 : ";
		cin >> photo;
		if (container.AddPhoto(photo)) {
			storage.UpdateContainer(container);
			cout << "\tPhoto를 성공적으로 추가했습니다.\n";
			cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto저장에 실패했습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 입력받은 photo를 제거한다.
bool Application::DeletePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
		container.DisplayAllPhoto();
		cout << "\n\t제거할 Photo를 입력하시오 : ";
		cin >> photo;
		if (container.DeletePhoto(photo)) {
			storage.UpdateContainer(container);
			cout << "\tPhoto를 성공적으로 제거했습니다.\n";
			cout << "\t=====================삭제 후 Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto삭제에 실패했습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 입력받은 photo를 수정한다.
bool Application::UpdatePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
		container.DisplayAllPhoto();
		cout << "\n\t수정할 Photo를 입력하시오 : \n";
		cin >> photo;
		if (container.UpdatePhoto(photo)) {
			storage.UpdateContainer(container);
			cout << "\tPhoto를 성공적으로 수정했습니다.\n";
			cout << "\t=====================수정 후 Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto수정에 실패했습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container의 photolist를 출력한다
bool Application::PrintPhotoList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
		container.DisplayAllPhoto();
		return true;
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 item을 검색한다.
bool Application::RetrieveItemContainerList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		SimpleItemType item;
		item.SetIdFromKB();
		if (container.GetItem(item)) {
			item.DisplaySimpleItemOnScreen();
			return true;
		}
		else {
			cout << "\t찾으려는 item이 존재하지 않습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 item을 kind로 검색한다.
bool Application::SearchByKindContainerList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	cout << "\n";
	if (storage.GetContainer(container)) {
		SimpleItemType item;
		if (container.FindByKind(item)) {
			return true;
		}
		else {
			cout << "\t해당하는 종류의 물품이 없습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 item을 Name으로 검색한다.
bool Application::SearchByNameContainerList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		SimpleItemType item;
		if (container.FindByName(item)) {
			return true;
		}
		else {
			cout << "\t해당하는 이름의 물품이 없습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container를 비운다.
void Application::MakeEmptyContainer(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		container.ResetSimpleList();
		SimpleItemType simpleitem;
		while (container.GetNextSimpleItem(simpleitem)) {
			ItemType item;
			item.SetId(simpleitem.GetId());
			m_MasterList.Delete(item);
		}
		container.MakeEmpty();
		cout << "\n\tContainer:" << container.GetId() << " 가 성공적으로 비워졌습니다\n\n";
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
	}
}

// 저장소의 container에 있는 모든 item을 출력한다.
void Application::DisplayAllItemContainer(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		container.DisplayAllItem();
	}
	else {
		cout << "\t찾으려는 containe가 존재하지 않습니다\n";
	}
}

// receive keynumber from keyboard and find item in TempList which same keynumber and delete that item
bool Application::DeleteItemTempList()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_TempList.Delete(item)) {
		cout << "\t성공적으로 삭제했습니다\n\n";
		cout << "\t=====================삭제 후 TempList=====================\n";
		m_TempList.DisplayAllTempItems();
		return true;
	}
	else {
		cout << "\t찾고있는 item이 존재하지 않습니다\n";
		return false;
	}
}

// receive Goods record from keyboard and find item has same keynumber and replace the record with new record
bool Application::ReplaceItemTempList()
{
	ItemType item;
	item.SetGoodsExceptStorageFromKB();
	item.SetContainerId(-1);
	item.SetStorageId(-1);

	if (m_TempList.Replace(item)) {
		cout << "\n\t성공적으로 item을 수정했습니다.\n";
		cout << "\t=====================수정 후 TempList=====================\n";
		m_TempList.DisplayAllTempItems();
		return true;
	}
	else {
		cout << "\t찾으려는 item이 존재하지 않습니다.\n";
		return false;
	}
}

// receive ID from keyboard and find item which has same ID and display that record on screen
bool Application::RetrieveItemTempList()
{
	ItemType item;
	item.SetIdFromKB();
	cout << "\n\t=====================Item ID:" << item.GetId() << "=====================\n";
	if (m_TempList.Retrieve(item)) {
		item.DisplayGoodsOnScreen();
		return true;
	}
	else {
		cout << "\t찾으려는 item이 존재하지 않습니다\n";
		return false;
	}
}

// receive word from keyboard and display the kind of item Kind display that record on screen
bool Application::SearchByKindTempList()
{
	return m_TempList.SearchByKind();
}

// receive Name from keyboard and find item which Name include the Name and display that record on screen
bool Application::SearchByNameTempList()
{
	return m_TempList.SearchByName();
}

// receive PurchaseDay from keyboard and find item which Name include the PurchaseDay and display that record on screen
bool Application::SearchByPurchaseDayTempList()
{
	return m_TempList.SearchByPurchaseDay();
}

// make TempList empty
void Application::MakeEmptyTempList()
{
	m_TempList.MakeEmpty();
}

// display all records in list on screen
void Application::DisplayAllItemTempList()
{
	cout << "\t=====================TempList=====================\n";
	m_TempList.DisplayAllTempItems();
}

// move all items in TempList to MasterList
void Application::MoveItemTempToMaster()
{
	ItemType item;
	while (m_TempList.DeQueue(item)) {
		cout << "\n\t=====================TempList NextItem=====================\n";
		item.DisplayGoodsExceptStorageOnScreen();
		int ContainerId, StorageId;
		cout << "\t옮기고 싶은 StorageId를 입력하시오 : ";
		cin >> StorageId;
		cout << "\t옮기고 싶은 ContainerId를 입력하시오 : ";
		cin >> ContainerId;

		if (StorageId == -1 || ContainerId == -1) {
			cout << "\t임시저장소는 입력하면 안됩니다. 다시 임시저장소에 보관합니다.\n";
			m_TempList.EnQueue(item);
		}
		else {
			item.SetStorageId(StorageId);
			item.SetContainerId(ContainerId);
			if (AddItem(item)) {
				cout << "\t성공적으로 저장소를 옮겼습니다\n";
			}
			else {
				cout << "\t저장소를 옮기는데 실패했습니다. 다시 임시저장소에 보관합니다.\n";
				m_TempList.EnQueue(item);
			}
		}
	}
}

// Inorder(ID 순서) 순으로 탐색하여 구매일이 같은 아이템을 출력하고 총액을 더한다
void AddExpenseSearchByPurchaseDay(BinaryTreeNode<ItemType>* root, const ItemType& item, int& sum, bool& found)
{
	if (root != NULL) {
		AddExpenseSearchByPurchaseDay(root->left, item, sum, found);
		if (root->data.GetName() == item.GetName()) {
			root->data.DisplayNameOnScreen();
			root->data.DisplayKindOnScreen();
			root->data.DisplayPriceOnScreen();
			root->data.DisplayIdOnScreen();
			cout << "\n";
			found = true;
			sum += root->data.GetPrice();
		}
		AddExpenseSearchByPurchaseDay(root->right, item, sum, found);
	}
}
// 날짜를 입력받아 그 날 구매한 물품 목록과 총액을 출력한다.
void Application::DisplayDayExpenseRecord()
{
	// 찾고자하는 날짜를 입력한다
	int m_Sum = 0;
	ItemType item;
	BinaryTreeNode<ItemType>* root = m_MasterList.GetRoot();
	bool found = false;
	item.SetPurchaseDayFromKB();

	// 출력한 후 총액을 더한다
	cout << "\n\t=====================Item PurchaseDay:" << item.GetPurchaseDay() << "=====================\n";
	
	AddExpenseSearchByPurchaseDay(root, item, m_Sum, found);

	if (!found) {
		cout << "\t해당하는 날에 구매한 item이 존재하지 않습니다.\n";
		return;
	}
	// 총액을 출력한다.
	cout << "\n\t===================" << item.GetPurchaseDay() << " 날 지출 총액 : " << m_Sum << "원===================\n";
}

// Inorder(ID 순서) 순으로 탐색하여 구매월이 같은 아이템을 출력하고 총액을 더한다
void AddExpenseSearchByPurchaseMonth(BinaryTreeNode<ItemType>* root, const int& month, int* ExpenseSumPerKind, bool& found)
{
	if (root != NULL) {
		AddExpenseSearchByPurchaseMonth(root->left, month, ExpenseSumPerKind, found);
		if (root->data.GetPurchaseDay() / 100 == month) {
			root->data.DisplayNameOnScreen();
			root->data.DisplayPriceOnScreen();
			root->data.DisplayKindOnScreen();
			root->data.DisplayIdOnScreen();
			cout << "\n";
			found = true;
			ExpenseSumPerKind[root->data.GetKind()] += root->data.GetPrice();
		}
		AddExpenseSearchByPurchaseMonth(root->right, month, ExpenseSumPerKind, found);
	}
}

// 달을 입력받아 그 해의 소비 분석 결과가 출력된다.
void Application::DisplayMonthExpenseRecord()
{
	// 물건 종류별로 배열을 만들어 값을 저장한다
	int* ExpenseSumPerKind = new int[5]();
	BinaryTreeNode<ItemType>* root = m_MasterList.GetRoot();
	bool found = false;
	int m_Month;
	cout << "\n\t소비 내역을 알고 싶은 달을 입력하시오 (예: 202005 (2020년 5월)) :";
	cin >> m_Month;
	while (m_Month < 190000 || m_Month > 210000 || m_Month % 100 == 0 || m_Month % 100 > 12) {
		cout << "\n\t잘못 입력하였습니다. 소비 내역을 알고 싶은 달을 다시 입력하시오 (예: 202005 (2020년 5월)) :";
	}

	// MasterList에서 Item을 찾고 출력한다.
	cout << "\n\t=====================Item PurchaseMonth:" << m_Month << "=====================\n";
	
	AddExpenseSearchByPurchaseMonth(root, m_Month, ExpenseSumPerKind, found);

	if (!found) {
		cout << "\t해당하는 달에 구매한 item이 존재하지 않습니다.\n";
		delete[] ExpenseSumPerKind;
	}

	// 해당 기간내 아이템을 종류별로 구분하여 가격을 따로따로 더한다
	else {
		int MaxExpenseKind = 0;
		for (int i = 1; i < 5; i++) {
			if (ExpenseSumPerKind[MaxExpenseKind] < ExpenseSumPerKind[i])
				MaxExpenseKind = i;
		}
		// 최대로 많이 쓴 것을 차트에서 네모 25칸을 기준으로 한다
		int PricePerBlock = ExpenseSumPerKind[MaxExpenseKind] / 25;
		if (PricePerBlock == 0) PricePerBlock = 1;

		int m_Sum = 0;

		// 최대로 많이 낸 달을 25칸을 기준으로 각 달마다 쓴돈을 차트로 표현한다
		cout << "\n\t=========================" << m_Month << " 달 소비 분석==========================\n";
		cout << "\t--------------------- 물건 종류 별 소비 막대차트 ---------------------\n\n";
		cout << "\t         │\n";
		for (int i = 0; i < 5; i++) {
			m_Sum += ExpenseSumPerKind[i];
			cout << "\tKind : " << i << " │ ";
			for (int BlockCount = 0; BlockCount < ExpenseSumPerKind[i] / PricePerBlock; BlockCount++) {
				cout << "■";
			}
			cout << " (" << ExpenseSumPerKind[i] << "원)\n";
			cout << "\t         │\n";
		}
		// 마지막으로 그 달에 쓴 총액을 출력한다.
		cout << "\n\t====================" << m_Month << " 달 지출 총액 : " << m_Sum << "원====================\n";

		delete[] ExpenseSumPerKind;
	}
}

// Inorder(ID 순서) 순으로 탐색하여 구매년도가 같은 아이템을 출력하고 총액을 더한다
void AddExpenseSearchByPurchaseYear(BinaryTreeNode<ItemType>* root, const int& year, int* ExpenseSumPerKind, int* ExpenseSumPerMonth, bool& found)
{
	if (root != NULL) {
		AddExpenseSearchByPurchaseYear(root->left, year, ExpenseSumPerKind, ExpenseSumPerMonth, found);
		if (root->data.GetPurchaseDay() / 10000 == year) {
			int month = root->data.GetPurchaseDay() / 100;
			root->data.DisplayNameOnScreen();
			root->data.DisplayPriceOnScreen();
			root->data.DisplayIdOnScreen();
			cout << "\n";
			found = true;
			ExpenseSumPerKind[root->data.GetKind()] += root->data.GetPrice();
			ExpenseSumPerMonth[month % 100 - 1] += root->data.GetPrice();
		}
		AddExpenseSearchByPurchaseYear(root->right, year, ExpenseSumPerKind, ExpenseSumPerMonth, found);
	}
}

// 해를 입력받아 그 해의 소비 분석 결과가 출력된다.
void Application::DisplayYearExpenseRecord()
{	
	// 물건 종류와 달 별로 배열을 만들어 각각에 값을 저장한다.
	int* ExpenseSumPerKind = new int[5]();	
	int* ExpenseSumPerMonth = new int[12]();
	BinaryTreeNode<ItemType>* root = m_MasterList.GetRoot();
	bool found = false;
	int m_Year;
	cout << "\n\t소비 내역을 알고 싶은 년도를 입력하시오 (예: 2020 (2020년)) :";
	cin >> m_Year;
	while (m_Year < 1900 || m_Year > 2100) {
		cout << "\t잘못 입력하였습니다. 소비 내역을 알고 싶은 년도를 입력하시오 (예: 2020 (2020년)) :";
		cin >> m_Year;
	}

	// MasterList에서 Item을 찾고 출력한다.
	cout << "\n\t=====================Item PurchaseYear:" << m_Year << "=====================\n";
	
	AddExpenseSearchByPurchaseYear(root->right, m_Year, ExpenseSumPerKind, ExpenseSumPerMonth, found);

	if (!found) {
		cout << "\t해당하는 해에 구매한 item이 존재하지 않습니다.\n";
		delete[] ExpenseSumPerKind;
		delete[] ExpenseSumPerMonth;
	}

	// 해당 기간내 아이템을 종류별로 구분하여 가격을 따로따로 더한다
	else {
		int MaxExpenseKind = 0;
		for (int i = 1; i < 5; i++) {
			if (ExpenseSumPerKind[MaxExpenseKind] < ExpenseSumPerKind[i])
				MaxExpenseKind = i;
		}
		// 최대로 많이 쓴 것을 차트에서 네모 25칸을 기준으로 한다
		int PricePerBlock = ExpenseSumPerKind[MaxExpenseKind] / 25;
		if (PricePerBlock == 0) PricePerBlock = 1;

		int m_Sum = 0;

		// 최대로 많이 낸 달을 25칸을 기준으로 각 달마다 쓴돈을 차트로 표현한다
		cout << "\n\t==========================" << m_Year << " 년 소비 분석===========================\n";
		cout << "\t--------------------- 물건 종류 별 소비 막대차트 ---------------------\n\n";
		cout << "\t         │\n";
		for (int i = 0; i < 5; i++) {
			// 해당 기간내 쓴 돈을 계산한다
			m_Sum += ExpenseSumPerKind[i];
			cout << "\tKind : " << i << " │ ";
			for (int BlockCount = 0; BlockCount < ExpenseSumPerKind[i] / PricePerBlock; BlockCount++) {
				cout << "■";
			}
			cout << " (" << ExpenseSumPerKind[i] << "원)\n";
			cout << "\t         │\n";
		}

		// 위와 동일하게 이번엔 물건 종류를 기준으로 차트를 생성한다
		int MaxExpenseMonth = 0;
		for (int i = 1; i < 12; i++) {
			if (ExpenseSumPerMonth[MaxExpenseMonth] < ExpenseSumPerMonth[i])
				MaxExpenseMonth = i;
		}
		PricePerBlock = ExpenseSumPerMonth[MaxExpenseMonth] / 25;
		if (PricePerBlock == 0) PricePerBlock = 1;

		cout << "\n\t----------------------- 월별 소비 막대차트 -----------------------\n\n";
		cout << "\t           │\n";
		for (int i = 0; i < 12; i++) {
			cout << "\tMonth : ";
			if (i < 9) cout << "0";
			cout << i + 1 << " │ ";
			for (int BlockCount = 0; BlockCount < ExpenseSumPerMonth[i] / PricePerBlock; BlockCount++) {
				cout << "■";
			}
			cout << " (" << ExpenseSumPerMonth[i] << "원)\n";
			cout << "\t           │\n";
		}

		// 마지막으로 연간 쓴 총액을 출력한다.
		cout << "\n\t=====================" << m_Year << " 년 지출 총액 : " << m_Sum << "원=====================\n";

		delete[] ExpenseSumPerKind;
		delete[] ExpenseSumPerMonth;
	}
}
