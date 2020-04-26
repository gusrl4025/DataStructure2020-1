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
			GetCommandMaster();
			break;
		case 3:		// ��ǰ ������ �Է� �޾Ƽ� ����Ʈ���� �ش� ��ǰ ������ ����			
			GetCommandContainer();
			break;
		case 4:		// �Էµ� ������ ��� ��ǰ�� ȭ�鿡 ���
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
void Application::RunContainer()
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
			PrintContainerList();
			break;
		case 3:		// ��ǰ ������ �Է� �޾Ƽ� ����Ʈ���� �ش� ��ǰ ������ ����			
			AddPhoto();
			break;
		case 4:		// �Էµ� ������ ��� ��ǰ�� ȭ�鿡 ���
			DeletePhoto();
			break;
		case 5:		// ��ǰ�� �Էµ� �ܾ ���Ե� ��� ��ǰ�� ȭ�鿡 ���
			UpdatePhoto();
			break;
		case 6:		// �Էµ� ������ ����Ʈ���� ��ǰ�� ã�Ƽ� ȭ�鿡 ���				
			PrintPhotoList();
			break;
		case 7:		// ����Ʈ�� ����� ��� ��ǰ�� ȭ�鿡 ���
			RetrieveItemContainerList();
			break;
		case 8: 	// ����Ʈ�� �Էµ� ��� ��ǰ�� ����
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
	cout << "\t 3 : ContainerList�� �����ϱ�\n";
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

int Application::GetCommandContainer()
{
	int command;
	cout << endl << endl;
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
	ItemType item;
	item.SetGoodsFromKB(); // item�� �Է¹޴´�
	if (item.GetContainerId() == -1) {	// ContainerId == -1�̸� TemptList�� ����
		m_TempList.EnQueue(item);
		return true;
	}
	else { // ContainerId�� -1�� �ƴϸ�
		ContainerType container(item.GetContainerId()); // ContainerId�� ���� container�� �ϳ� ����
		if (m_ContainerList.Retrieve_Binary(container)) {
			container.AddItem(item);
			m_ContainerList.Replace(container);
			return true;
		}
		else { // Container�� �������� ������
			cout << "\tContainer�� �������� �ʾ� ���� ��������ϴ�\n";
			m_ContainerList.Add(container); // List�� container�� �߰�
			container.AddItem(item); // �׸��� �� container�� item�� �߰�
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
		cout << "\t�����Ϸ��� Goods�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// receive Id from keyboard and find item which has same Id and display that record on screen
int Application::ReplaceGoods() {
	ItemType data;
	data.SetGoodsFromKB();
	if (m_List.Replace(data)) return 1;
	cout << "\t�ٲٷ��� Goods�� �������� �ʽ��ϴ�\n";
}

// receive word from keyboard and display the kind of item Kind display that record on screen
int Application::SearchByKind() {
	ItemType data;
	string inKind;
	cout << "\t���ϴ� ��ǰ�� ������ �Է��Ͻÿ�(1:�ʱ��, 2:å) : ";
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
	if (!found) cout << "\tã������ ������ ��ǰ�� �������� �ʽ��ϴ�\n";

	return found;

}

// receive word from ID and find item which name include the word and display that record on screen
int Application::SearchByName() {
	ItemType data;
	string inName;
	cout << "\t���ϴ� ��ǰ���� �Է��Ͻÿ� : ";
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
	if (!found) cout << "\tã������ ��ǰ�� �������� �ʽ��ϴ�\n";

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
	cout << "\t����Ϸ��� Goods�� �������� �ʽ��ϴ�\n";
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