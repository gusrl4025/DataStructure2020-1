#pragma once

class Application
{
public:

	/*
		constructor
	*/
	Application() {
		m_Command = 0;
	}

	/*
		destructor
	*/
	~Application() {}

	/*
		@brief	run program(receive the command and execute the function)
		@pre	application is initialized
		@post	program is finished
	*/
	void Run();
	void RunMaster();
	int RunStorage();
	void RunContainer(int InStorageId);
	void RunTemp();

	/*
		@brief	shows menu and receive the command from keyboard
		@pre	none
		@post	receive the command
		@return	command
	*/
	int GetCommand();
	int GetCommandMaster();
	int GetCommandStorage();
	int GetCommandContainer(int InStorageId);
	int GetCommandTemp();

	/*
		@brief	Item�� �Է¹޾� ContainerId�� ������ MasterList -1�̸� TempList�� �ִ´�.
		@pre	MasterList�� TempList should be initialized
		@post	new item is added to list
		@return if function works return true, otherwise return false
	*/
	bool AddItem();
	bool AddItem(ItemType item);

	/*
		@brief	Id�� �Է¹޾� MasterList�� Container���� ������
		@pre	MasterList, Container�� �ʱ�ȭ �ž��Ѵ�
		@post	the record is deleted in MasterList, Container
		@return if function works return true, otherwise return false
	*/
	bool DeleteItemMasterList();

	/*
		@brief	Item�� �Է¹޾� MasterList�� Container���� ������
		@pre	MasterList, Container�� �ʱ�ȭ �ž��Ѵ�
		@post	the record is replaced in MasterList, Container
		@return if function works return true, otherwise return false
	*/
	bool ReplaceItemMasterList();

	/*
		@brief	Id�� �Է¹޾� MasterList���� �˻���
		@pre	MasterList�� �ʱ�ȭ �ž��Ѵ�
		@post	record user wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool RetrieveItemMasterList();

	/*
		@brief	item ������ �Է¹޾� MasterList���� �˻���
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByKindMasterList();

	/*
		@brief	item �̸��� �Է¹޾� MasterList���� �˻���
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByNameMasterList();

	/*
		@brief	item ������ �Է¹޾� MasterList���� �˻���
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByPurchaseDayMasterList();

	/*
		@brief	make MasterList, StorageList empty
		@pre	none
		@post	make MasterList, StorageList empty
	*/
	void MakeEmptyMasterList();

	/*
		@brief	display all records in list on screen
		@pre	list should be initialized
		@post	display all records in list on screen
	*/
	void DisplayAllItemMasterList();

	/*
		@brief	move item in MasterList to TempList
		@pre	MasterList and TempList should be initialized
		@post	item in MasterList moved to TempList
		@return if function works return true, otherwise return false
	*/
	bool MoveItemMasterToTemp();

	//----------------------- RunStorage -----------------------------------------------------


	int GetStorageId();

	void DisplayAllContainer();

	void DisPlayAllDetailsContainer();
	//----------------------- RunContainer ---------------------------------------------------

	/*
		@brief	receive keynumber from keyboard and find item in Masterlist which same keynumber and delete that item
		@pre	MasterList should be initialized
		@post	the record is deleted in MasterList
		@return if function works return true, otherwise return false
	*/
	void PrintContainerList(StorageType& storage);

	/*
		@brief
		@pre
		@post
		@return
	*/
	bool AddPhoto(StorageType& storage);

	/*
		@brief	receive Goods record from keyboard and find item has same keynumber and replace the record with new record
		@pre	MasterList should be initialized
		@post	the record is replace with new record
		@return if function works return true, otherwise return false
	*/
	bool DeletePhoto(StorageType& storage);

	/*
		@brief	
		@pre	
		@post	
		@return	
	*/
	bool UpdatePhoto(StorageType& storage);

	/*
		@brief
		@pre
		@post
		@return
	*/
	bool PrintPhotoList(StorageType& storage);

	/*
		@brief	receive ID from keyboard and find item which has same ID and display that record on screen
		@pre	Masterlist should be initialized
		@post	record user wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool RetrieveItemContainerList(StorageType& storage);

	/*
		@brief	receive word from keyboard and display the kind of item Kind display that record on screen
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByKindContainerList(StorageType& storage);

	/*
		@brief	receive Name from keyboard and find item which Name include the Name and display that record on screen
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByNameContainerList(StorageType& storage);

	/*
		@brief	make MasterList empty
		@pre	none
		@post	make MasterList empty
	*/
	void MakeEmptyContainer(StorageType& storage);

	/*
		@brief	display all records in list on screen
		@pre	list should be initialized
		@post	display all records in list on screen
	*/
	void DisplayAllItemContainer(StorageType& storage);

	//---------------TempList--------------------------------

		/*
		@brief	receive keynumber from keyboard and find item in TempList which same keynumber and delete that item
		@pre	TempList should be initialized
		@post	the record is deleted in MasterList
		@return if function works return true, otherwise return false
	*/
	bool DeleteItemTempList();

	/*
		@brief	receive Goods record from keyboard and find item has same keynumber and replace the record with new record
		@pre	TempList should be initialized
		@post	the record is replace with new record
		@return if function works return true, otherwise return false
	*/
	bool ReplaceItemTempList();

	/*
		@brief	receive ID from keyboard and find item which has same ID and display that record on screen
		@pre	TempList should be initialized
		@post	record user wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool RetrieveItemTempList();

	/*
		@brief	receive word from keyboard and display the kind of item Kind display that record on screen
		@pre	TempList should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByKindTempList();

	/*
		@brief	receive Name from keyboard and find item which Name include the Name and display that record on screen
		@pre	TempList should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByNameTempList();

	/*
		@brief	receive PurchaseDay from keyboard and find item which Name include the PurchaseDay and display that record on screen
		@pre	TempList should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByPurchaseDayTempList();

	/*
		@brief	make TempList empty
		@pre	none
		@post	make TempList empty
	*/
	void MakeEmptyTempList();

	/*
		@brief	display all records in list on screen
		@pre	TempList should be initialized
		@post	display all records in list on screen
	*/
	void DisplayAllItemTempList();

	/*
		@brief	move item in TempList to MasterList
		@pre	MasterList and TempList should be initialized
		@post	item in TempList moved to MasterList
		@return if function works return true, otherwise return false
	*/
	void MoveItemTempToMaster();
private:
	SortedList<ItemType> m_MasterList;
	TempType m_TempList;
	SortedList<StorageType> m_StorageList;
	int m_Command;
};


