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
		case 1:		// ��ǰ ������ �Է� �޾� ����Ʈ�� �߰�					
			AddItem();
			break;
		case 2:		// ��ǰ�� ������ȣ�� �Է� �޾� ����Ʈ���� ����					
			RunMaster();
			break;
		case 3:		// ��ǰ ������ �Է� �޾Ƽ� ����Ʈ���� �ش� ��ǰ ������ ����			
			RunStorage();
			break;
		case 4:		// �Էµ� ������ ��� ��ǰ�� ȭ�鿡 ���
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
		case 1:		// Item�� �Է¹޾� ContainerId�� ������ MasterList -1�̸� TempList�� �ִ´�.					
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
			case 1:		// ��ǰ ������ �Է� �޾� ����Ʈ�� �߰�					
				AddItem();
				break;
			case 2:		// ��ǰ�� ������ȣ�� �Է� �޾� ����Ʈ���� ����					
				PrintContainerList(storage);
				break;
			case 3:		// ��ǰ ������ �Է� �޾Ƽ� ����Ʈ���� �ش� ��ǰ ������ ����			
				AddPhoto(storage);
				break;
			case 4:		// �Էµ� ������ ��� ��ǰ�� ȭ�鿡 ���
				DeletePhoto(storage);
				break;
			case 5:		// ��ǰ�� �Էµ� �ܾ ���Ե� ��� ��ǰ�� ȭ�鿡 ���
				UpdatePhoto(storage);
				break;
			case 6:		// �Էµ� ������ ����Ʈ���� ��ǰ�� ã�Ƽ� ȭ�鿡 ���				
				PrintPhotoList(storage);
				break;
			case 7:		// ����Ʈ�� ����� ��� ��ǰ�� ȭ�鿡 ���
				RetrieveItemContainerList(storage);
				break;
			case 8: 	// ����Ʈ�� �Էµ� ��� ��ǰ�� ����
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
		cout << "\tã������ ����Ұ� �������� �ʽ��ϴ�.\n";
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
		case 1:		// ��ǰ ������ �Է� �޾� ����Ʈ�� �߰�					
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
	cout << "\t���ȹ�ǰ ���� ���α׷��� �����Ͻ� ���� ȯ���մϴ�!!\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : Add Item\n";
	cout << "\t 2 : MasterList�� �����ϱ�\n";
	cout << "\t 3 : StorageList�� �����ϱ�\n";
	cout << "\t 4 : TempList�� �����ϱ�\n";
	cout << "\t 0 : ���α׷� ����" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

int Application::GetCommandMaster()
{
	int command;
	cout << endl << endl;
	cout << "\tMasterList���� ������ command�� �Է��ϼ���\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : Item �߰��ϱ�\n";
	cout << "\t 2 : Item �����ϱ�\n";
	cout << "\t 3 : Item ������Ʈ\n";
	cout << "\t 4 : Item �˻��ϱ�\n";
	cout << "\t 5 : ������ Item �˻��ϱ�\n";
	cout << "\t 6 : �̸����� Item �˻��ϱ�\n";
	cout << "\t 7 : �����Ϸ� Item �˻��ϱ�\n";
	cout << "\t 8 : MasterList ����\n";
	cout << "\t 9 : ��� Item ����ϱ�\n";
	cout << "\t 10 : TempList�� Item �ű�� \n";
	cout << "\t 0 : ������� ���ư���\n" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

int Application::GetCommandStorage()
{
	int command;
	cout << "\n\n";
	cout << "\tStorageList���� ������ command�� �Է��ϼ���\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : ������ Storage �Է�\n";
	cout << "\t 2 : Storage �ϳ��� �����̳ʵ��� ���� ���\n";
	cout << "\t 3 : Storage �ϳ��� �����̳ʵ��� �� ���� ���\n";
	cout << "\t 0 : ������� ���ư���\n";
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
	cout << "\tContainerList���� ������ command�� �Է��ϼ���\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : Item �߰��ϱ�\n";
	cout << "\t 2 : Container ��� ����ϱ�\n";
	cout << "\t 3 : ���� �����ϱ�\n";
	cout << "\t 4 : ���� �����ϱ�\n";
	cout << "\t 5 : ���� ������Ʈ�ϱ�\n";
	cout << "\t 6 : ���� ��� ���\n";
	cout << "\t 7 : Item �˻��ϱ�\n";
	cout << "\t 8 : ������ Item �˻��ϱ�\n";
	cout << "\t 9 : �̸����� Item �˻��ϱ�\n";
	cout << "\t 10 : Container �ϳ� ����\n";
	cout << "\t 11 : Container �ϳ��� ��� Item ����ϱ�\n";
	cout << "\t 0 : ������� ���ư���\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

int Application::GetCommandTemp()
{
	int command;
	cout << endl << endl;
	cout << "\tTempList���� ������ command�� �Է��ϼ���\n";
	cout << "\t-ID ----- Command ------------\n";
	cout << "\t 1 : Item �߰��ϱ�\n";
	cout << "\t 2 : Item �����ϱ� \n";
	cout << "\t 3 : Item ������Ʈ�ϱ�\n";
	cout << "\t 4 :	Item �˻��ϱ�\n";
	cout << "\t 5 : ������ Item �˻��ϱ�\n";
	cout << "\t 6 : �̸����� Item �˻��ϱ�\n";
	cout << "\t 7 : �����Ϸ� Item �˻��ϱ�\n";
	cout << "\t 8 : TempList ����\n";
	cout << "\t 9 : ��� Item ����ϱ�\n";
	cout << "\t 10 : MasterList�� Item �ű�� \n";
	cout << "\t 0 : ������� ���ư���\n" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// receive Goods record from keyboard and add to list
bool Application::AddItem() {
	cout << "\t=====================Add item=====================\n";
	ItemType item;
	item.SetGoodsFromKB(); // item�� �Է¹޴´�
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1�̸� TemptList�� ����
		m_TempList.EnQueue(item);
		return true;
	}
	else { // StorageId, ContainerList�� -1�� �ƴϸ�
		StorageType storage; // StorageId�� ���� storage�� �ϳ� ����
		storage.SetId(item.GetStorageId());
		if (m_MasterList.Add(item)) {
			if (m_StorageList.Retrieve_Binary(storage)) { // StorageId�� ���� storage�� �����ϸ�
				ContainerType container;
				container.SetIdFromKB();
				if (storage.GetContainer(container)) {
					if (container.AddItem(item)) {
						cout << "\n\t Item���忡 �����߽��ϴ�.\n";
						cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
						container.DisplayAllItem();
					}
				}
				else {
					cout << "\t�ش��ϴ� container�� ���� ���� ����ϴ�\n";
					container.SetLocationFromKB();
					if (storage.AddContainer(container)) {
						storage.GetContainer(container);
						if (container.AddItem(item)) {
							cout << "\n\t Item���忡 �����߽��ϴ�.\n";
							cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
						}
					}
				}
			}
			else {
				int InMaxNum;
				ContainerType container;
				cout << "\t�ش��ϴ� storage�� ���� ���� ����ϴ�.\n";
				cout << "\t�ִ� ���������� ���������� ������ �Է��Ͻÿ� : ";
				cin >> InMaxNum;
				storage.SetMaxNum(InMaxNum);
				container.SetId(item.GetContainerId());
				container.SetLocationFromKB();
				storage.AddContainer(container);
				container.AddItem(item);
				if (container.AddItem(item)) {
					m_StorageList.Add(storage);
					cout << "\n\t Item���忡 �����߽��ϴ�.\n";
					cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
					container.DisplayAllItem();
				}
				else {
					cout << "\t�ش��ϴ� container�� ���� ���� ����ϴ�\n";
					container.SetLocationFromKB();
					storage.AddContainer(container);
					if (container.AddItem(item)) {
						cout << "\n\t Item���忡 �����߽��ϴ�.\n";
						cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
						container.DisplayAllItem();
					}
					else {
						cout << "\tItem ���忡 �����߽��ϴ�\n";
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
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1�̸� TemptList�� ����
		m_TempList.EnQueue(item);
		return true;
	}
	else { // StorageId, ContainerList�� -1�� �ƴϸ�
		StorageType storage; // StorageId�� ���� storage�� �ϳ� ����
		storage.SetId(item.GetStorageId());
		m_MasterList.Add(item);
		if (m_StorageList.Retrieve_Binary(storage)) { // StorageId�� ���� storage�� �����ϸ�
			ContainerType container;
			container.SetIdFromKB();
			if (storage.GetContainer(container)) {
				return container.AddItem(item);
			}
			else {
				cout << "\t�ش��ϴ� container�� ���� ���� ����ϴ�\n";
				container.SetLocationFromKB();
				return storage.AddContainer(container);
			}
		}
		else {
			int InMaxNum;
			cout << "\t�ش��ϴ� storage�� ���� ���� ����ϴ�.\n";
			cout << "\t�ִ� ���������� ���������� ������ �Է��Ͻÿ� : ";
			cin >> InMaxNum;
			storage.SetMaxNum(InMaxNum);
			ContainerType container;
			container.SetIdFromKB();
			if (storage.GetContainer(container)) {
				return container.AddItem(item);
			}
			else {
				cout << "\t�ش��ϴ� container�� ���� ���� ����ϴ�\n";
				container.SetLocationFromKB();
				storage.AddContainer(container);
				return container.AddItem(item);
			}
		}
	}
	return false;
}

// Id�� �Է¹޾� MasterList�� Container���� ������
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
			cout << "\t���������� �����Ǿ����ϴ�\n";
			cout << "\t---------------���� �� ContainerList---------------\n";
			container.DisplayAllItem();
			return true;
		}
	}
	cout << "\tItem ������ �����߽��ϴ�\n";
	return false;

}

// Item�� �Է¹޾� MasterList�� Container���� ������
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
			cout << "\t���������� �����Ǿ����ϴ�\n";
			return true;
		}
	}
	cout << "\tItem ������ �����߽��ϴ�\n";
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
	cout << "\tã�� item�� �������� �ʽ��ϴ�.\n";
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
		cout << "\tã�� ������ item�� �������� �ʽ��ϴ�.\n";
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
		cout << "\tã�� �̸��� item�� �������� �ʽ��ϴ�.\n";
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
		cout << "\tã�� �������� item�� �������� �ʽ��ϴ�.\n";
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
	cout << "\t--------------------��ü item List-----------------\n";
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
				cout << "\t���������� �̵��߽��ϴ�\n";
				return true;
			}
		}
		else {
			cout << "\t�ӽ�����Ұ� ���� á���ϴ�\n";
			return false;
		}
	}

	cout << "\t�̵���Ű���� Item�� �������� �ʽ��ϴ�\n";
	return false;
}

int Application::GetStorageId()
{
	int InStorageId;
	cout << "\t�����ϰ��� �ϴ� ������� ID�� �Է��Ͻÿ� : ";
	cin >> InStorageId;
	return InStorageId;
}

void Application::DisplayAllContainer()
{
	StorageType storage;
	int storageId;
	cout << "\t������� ID�� �Է��Ͻÿ� : ";
	cin >> storageId;
	storage.SetId(storageId);
	m_StorageList.Retrieve_Binary(storage);
	storage.DisplayAllContainer();
}

void Application::DisPlayAllDetailsContainer()
{
	StorageType storage;
	int storageId;
	cout << "\t������� ID�� �Է��Ͻÿ� : ";
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
		cout << "\t�߰��� Photo�� �Է��Ͻÿ� : \n";
		cin >> photo;
		if (container.AddPhoto(photo)) {
			cout << "\tPhoto�� ���������� �߰��߽��ϴ�.\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto���忡 �����߽��ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

bool Application::DeletePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t������ Photo�� �Է��Ͻÿ� : \n";
		cin >> photo;
		if (container.DeletePhoto(photo)) {
			cout << "\tPhoto�� ���������� �����߽��ϴ�.\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto������ �����߽��ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

bool Application::UpdatePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t������ Photo�� �Է��Ͻÿ� : \n";
		cin >> photo;
		if (container.UpdatePhoto(photo)) {
			cout << "\tPhoto�� ���������� �����߽��ϴ�.\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto������ �����߽��ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
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
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
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
			cout << "\tã������ item�� �������� �ʽ��ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
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
			cout << "\t�ش��ϴ� ������ ��ǰ�� �����ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
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
			cout << "\t�ش��ϴ� �̸��� ��ǰ�� �����ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
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
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
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
		cout << "\tã������ containe�� �������� �ʽ��ϴ�\n";
	}
}

bool Application::DeleteItemTempList()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_TempList.Delete(item)) {
		cout << "\t���������� �����߽��ϴ�\n";
		cout << "\t-----------------���� �� TempList--------------------\n";
		m_TempList.DisplayAllTempItems();
		return true;
	}
	else {
		cout << "\tã���ִ� item�� �������� �ʽ��ϴ�\n";
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
		cout << "\t���������� item�� �����߽��ϴ�.\n";
		return true;
	}
	else {
		cout << "\tã������ itme�� �������� �ʽ��ϴ�.\n";
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
		cout << "\tã������ item�� �������� �ʽ��ϴ�\n";
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
		cout << "\t�ű�� ���� StorageId�� �Է��Ͻÿ� : \n";
		cin >> StorageId;
		cout << "\t�ű�� ���� ContainerId�� �Է��Ͻÿ� : \n";
		cin >> ContainerId;

		if (StorageId == -1 || ContainerId == -1) {
			cout << "\t�ӽ�����Ҵ� �Է��ϸ� �ȵ˴ϴ�. �ٽ� �ӽ�����ҿ� �����մϴ�.\n";
			m_TempList.EnQueue(item);
		}
		else {
			item.SetStorageId(StorageId);
			item.SetContainerId(ContainerId);
			if (AddItem(item)) {
				cout << "\t���������� ����Ҹ� �Ű���ϴ�\n";
			}
			else {
				cout << "\t����Ҹ� �ű�µ� �����߽��ϴ�. �ٽ� �ӽ�����ҿ� �����մϴ�.\n";
				m_TempList.EnQueue(item);
			}
		}
	}
}
