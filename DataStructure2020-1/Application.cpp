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

// shows menu and receive the command from keyboard
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t집안물품 정리 프로그램에 접속하신 것을 환영합니다!!\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : Add Item\n";
	cout << "\t 2 : MasterList에 접근하기\n";
	cout << "\t 3 : StorageList에 접근하기\n";
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

int Application::GetCommandStorage()
{
	int command;
	cout << "\n\n";
	cout << "\tStorageList에서 실행할 command를 입력하세요\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : 접근할 Storage 입력\n";
	cout << "\t 2 : Storage 하나의 컨테이너들의 정보 출력\n";
	cout << "\t 3 : Storage 하나의 컨테이너들의 상세 정보 출력\n";
	cout << "\t 0 : 목록으로 돌아가기\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

int Application::GetCommandContainer(int InStorageId)
{
	int command;
	cout << endl << endl;
	cout << "\tStorage ID : " << InStorageId << "\n";
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
	cout << "\t=====================Add item=====================\n";
	ItemType item;
	item.SetGoodsFromKB(); // item을 입력받는다
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1이면 TemptList에 저장
		m_TempList.EnQueue(item);
		return true;
	}
	else { // StorageId, ContainerList가 -1이 아니면
		StorageType storage; // StorageId를 가진 storage를 하나 생성
		storage.SetId(item.GetStorageId());
		if (m_MasterList.Add(item)) {
			if (m_StorageList.Retrieve_Binary(storage)) { // StorageId와 같은 storage가 존재하면
				ContainerType container;
				container.SetIdFromKB();
				if (storage.GetContainer(container)) {
					if (container.AddItem(item)) {
						cout << "\n\t Item저장에 성공했습니다.\n";
						cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
						container.DisplayAllItem();
					}
				}
				else {
					cout << "\t해당하는 container가 없어 새로 만듭니다\n";
					container.SetLocationFromKB();
					if (storage.AddContainer(container)) {
						storage.GetContainer(container);
						if (container.AddItem(item)) {
							cout << "\n\t Item저장에 성공했습니다.\n";
							cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
						}
					}
				}
			}
			else {
				int InMaxNum;
				ContainerType container;
				cout << "\t해당하는 storage가 없어 새로 만듭니다.\n";
				cout << "\t최대 보관가능한 컨테이터의 개수를 입력하시오 : ";
				cin >> InMaxNum;
				storage.SetMaxNum(InMaxNum);
				container.SetId(item.GetContainerId());
				container.SetLocationFromKB();
				storage.AddContainer(container);
				container.AddItem(item);
				if (container.AddItem(item)) {
					m_StorageList.Add(storage);
					cout << "\n\t Item저장에 성공했습니다.\n";
					cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
					container.DisplayAllItem();
				}
				else {
					cout << "\t해당하는 container가 없어 새로 만듭니다\n";
					container.SetLocationFromKB();
					storage.AddContainer(container);
					if (container.AddItem(item)) {
						cout << "\n\t Item저장에 성공했습니다.\n";
						cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
						container.DisplayAllItem();
					}
					else {
						cout << "\tItem 저장에 실패했습니다\n";
						return false;
					}
				}
			}
		}
		return false;
	}
	return false; 
}

bool Application::AddItem(ItemType item) {
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1이면 TemptList에 저장
		m_TempList.EnQueue(item);
		return true;
	}
	else { // StorageId, ContainerList가 -1이 아니면
		StorageType storage; // StorageId를 가진 storage를 하나 생성
		storage.SetId(item.GetStorageId());
		m_MasterList.Add(item);
		if (m_StorageList.Retrieve_Binary(storage)) { // StorageId와 같은 storage가 존재하면
			ContainerType container;
			container.SetIdFromKB();
			if (storage.GetContainer(container)) {
				return container.AddItem(item);
			}
			else {
				cout << "\t해당하는 container가 없어 새로 만듭니다\n";
				container.SetLocationFromKB();
				return storage.AddContainer(container);
			}
		}
		else {
			int InMaxNum;
			cout << "\t해당하는 storage가 없어 새로 만듭니다.\n";
			cout << "\t최대 보관가능한 컨테이터의 개수를 입력하시오 : ";
			cin >> InMaxNum;
			storage.SetMaxNum(InMaxNum);
			ContainerType container;
			container.SetIdFromKB();
			if (storage.GetContainer(container)) {
				return container.AddItem(item);
			}
			else {
				cout << "\t해당하는 container가 없어 새로 만듭니다\n";
				container.SetLocationFromKB();
				storage.AddContainer(container);
				return container.AddItem(item);
			}
		}
	}
	return false;
}

// Id를 입력받아 MasterList와 Container에서 지워줌
bool Application::DeleteItemMasterList() {
	ItemType item;
	item.SetIdFromKB();
	if (m_MasterList.Retrieve_Binary(item)) {
		StorageType storage;
		storage.SetId(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container;
		container.SetId(item.GetContainerId());
		storage.GetContainer(container);
		if (container.DeleteItem(item)) {
			m_MasterList.Delete(item);
			cout << "\t성공적으로 삭제되었습니다\n";
			cout << "\t---------------삭제 후 ContainerList---------------\n";
			container.DisplayAllItem();
			return true;
		}
	}
	cout << "\tItem 삭제에 실패했습니다\n";
	return false;

}

// Item을 입력받아 MasterList와 Container에서 수정함
bool Application::ReplaceItemMasterList()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_MasterList.Retrieve_Binary(item)) {
		StorageType storage;
		storage.SetId(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container;
		container.SetId(item.GetContainerId());
		storage.GetContainer(container);
		if (container.UpdateItem(item)) {
			m_MasterList.Replace(item);
			cout << "\t성공적으로 수정되었습니다\n";
			return true;
		}
	}
	cout << "\tItem 수정에 실패했습니다\n";
	return false;
}

bool Application::RetrieveItemMasterList()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_MasterList.Retrieve_Binary(item)) {
		item.DisplayGoodsOnScreen();
		return true;
	}
	cout << "\t찾는 item이 존재하지 않습니다.\n";
	return false;
}

bool Application::SearchByKindMasterList()
{
	ItemType item;
	ItemType temp;
	bool found;
	item.SetKindFromKB();

	m_MasterList.ResetList();
	for (int CurPos = 0; CurPos < m_MasterList.GetLength(); CurPos++) {
		m_MasterList.GetNextItem(temp);
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

bool Application::SearchByNameMasterList()
{
	ItemType item;
	ItemType temp;
	bool found;
	item.SetNameFromKB();

	m_MasterList.ResetList();
	for(int CurPos = 0; CurPos < m_MasterList.GetLength(); CurPos++) {
		m_MasterList.GetNextItem(temp);
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

bool Application::SearchByPurchaseDayMasterList()
{
	ItemType item;
	ItemType temp;
	bool found;
	item.SetPurchaseDayFromKB();

	m_MasterList.ResetList();
	for (int CurPos = 0; CurPos < m_MasterList.GetLength(); CurPos++) {
		m_MasterList.GetNextItem(temp);
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

void Application::MakeEmptyMasterList()
{
	m_MasterList.MakeEmpty();
	StorageType storage;
	m_StorageList.ResetList();
	for (int CurPos = 0; CurPos < m_StorageList.GetLength(); CurPos++) {
		m_StorageList.GetNextItem(storage);
		storage.MakeEmpty();
	}
}

void Application::DisplayAllItemMasterList()
{
	ItemType item;
	m_MasterList.ResetList();
	cout << "\t--------------------전체 item List-----------------\n";
	for (int CurPos = 0; CurPos < m_MasterList.GetLength(); CurPos++) {
		m_MasterList.GetNextItem(item);
		item.DisplayGoodsOnScreen();
	}
}

bool Application::MoveItemMasterToTemp()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_MasterList.Retrieve_Binary(item)) {
		StorageType storage;
		storage.SetId(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container;
		container.SetId(item.GetContainerId());
		storage.GetContainer(container);
		
		if (!m_TempList.IsFull()) {
			if (container.DeleteItem(item)) {
				item.SetContainerId(-1);
				m_TempList.EnQueue(item);
				m_MasterList.Delete(item);
				cout << "\t성공적으로 이동했습니다\n";
				return true;
			}
		}
		else {
			cout << "\t임시저장소가 가득 찼습니다\n";
			return false;
		}
	}

	cout << "\t이동시키려는 Item이 존재하지 않습니다\n";
	return false;
}

int Application::GetStorageId()
{
	int InStorageId;
	cout << "\t접근하고자 하는 저장소의 ID를 입력하시오 : ";
	cin >> InStorageId;
	return InStorageId;
}

void Application::DisplayAllContainer()
{
	StorageType storage;
	int storageId;
	cout << "\t저장소의 ID를 입력하시오 : ";
	cin >> storageId;
	storage.SetId(storageId);
	m_StorageList.Retrieve_Binary(storage);
	storage.DisplayAllContainer();
}

void Application::DisPlayAllDetailsContainer()
{
	StorageType storage;
	int storageId;
	cout << "\t저장소의 ID를 입력하시오 : ";
	cin >> storageId;
	storage.SetId(storageId);
	m_StorageList.Retrieve_Binary(storage);
	storage.DisplayAllDetailsContainer(m_MasterList);
}

void Application::PrintContainerList(StorageType& storage)
{
	storage.DisplayAllContainer();
}

bool Application::AddPhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t추가할 Photo를 입력하시오 : \n";
		cin >> photo;
		if (container.AddPhoto(photo)) {
			cout << "\tPhoto를 성공적으로 추가했습니다.\n";
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

bool Application::DeletePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t제거할 Photo를 입력하시오 : \n";
		cin >> photo;
		if (container.DeletePhoto(photo)) {
			cout << "\tPhoto를 성공적으로 제거했습니다.\n";
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

bool Application::UpdatePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t수정할 Photo를 입력하시오 : \n";
		cin >> photo;
		if (container.UpdatePhoto(photo)) {
			cout << "\tPhoto를 성공적으로 수정했습니다.\n";
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

bool Application::PrintPhotoList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		container.DisplayAllPhoto();
		return true;
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

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

bool Application::SearchByKindContainerList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		SimpleItemType item;
		item.SetKindFromKB();
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

bool Application::SearchByNameContainerList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		SimpleItemType item;
		item.SetNameFromKB();
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

void Application::MakeEmptyContainer(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	int InContainerId = container.GetId();
	if (storage.GetContainer(container)) {
		container.MakeEmpty();
		ItemType item;
		m_MasterList.ResetList();
		int length = m_MasterList.GetLength();
		for (int i = 0; i < length; i++) {
			m_MasterList.GetNextItem(item);
			if (item.GetContainerId() == container.GetId() && item.GetStorageId() == storage.GetId()) {
				m_MasterList.Delete(item);
			}
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
	}
}

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

bool Application::DeleteItemTempList()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_TempList.Delete(item)) {
		cout << "\t성공적으로 삭제했습니다\n";
		cout << "\t-----------------삭제 후 TempList--------------------\n";
		m_TempList.DisplayAllTempItems();
		return true;
	}
	else {
		cout << "\t찾고있는 item이 존재하지 않습니다\n";
		return false;
	}
}

bool Application::ReplaceItemTempList()
{
	ItemType item;
	item.SetKindFromKB();
	item.SetPurchaseDayFromKB();
	item.SetNameFromKB();
	item.SetPriceFromKB();
	item.SetIdFromKB();

	if (m_MasterList.Replace(item)) {
		cout << "\t성공적으로 item을 수정했습니다.\n";
		return true;
	}
	else {
		cout << "\t찾으려는 itme이 존재하지 않습니다.\n";
		return false;
	}
}

bool Application::RetrieveItemTempList()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_TempList.Retrieve(item)) {
		item.DisplayGoodsOnScreen();
		return true;
	}
	else {
		cout << "\t찾으려는 item이 존재하지 않습니다\n";
		return false;
	}
}

bool Application::SearchByKindTempList()
{
	return m_TempList.SearchByKind();
}

bool Application::SearchByNameTempList()
{
	return m_TempList.SearchByName();
}

bool Application::SearchByPurchaseDayTempList()
{
	return m_TempList.SearchByPurchaseDay();
}

void Application::MakeEmptyTempList()
{
	m_TempList.MakeEmpty();
}

void Application::DisplayAllItemTempList()
{
	m_TempList.DisplayAllTempItems();
}

void Application::MoveItemTempToMaster()
{
	ItemType item;
	int length = m_TempList.GetNumOfItems();
	for (int i = 0; i < length; i++) {
		m_TempList.DeQueue(item);
		item.DisplayGoodsOnScreen();
		int ContainerId, StorageId;
		cout << "\t옮기고 싶은 StorageId를 입력하시오 : \n";
		cin >> StorageId;
		cout << "\t옮기고 싶은 ContainerId를 입력하시오 : \n";
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
