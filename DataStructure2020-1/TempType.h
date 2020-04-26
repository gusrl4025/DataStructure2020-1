#pragma once
#include "pch.h"

class TempType
{
public:
	/*
		Constructor
	*/
	TempType();

	/*
		Destructor
	*/
	~TempType();

	/*
		@brief	TempList의 item 개수를 return
		@pre	none
		@post	none
		@return	return NumOfItems
	*/
	int GetNumOfItems() const;

	/*
		@brief	TempList에 item을 Enqueue한다
		@pre	TempList가 initialize돼야한다
		@post	TempList에 item이 Enqueue되고 NumOfItems++
		@param	item	Enqueue할 item
		@return	Enqueue가 되었으면 return true, 아니면 return false
	*/
	bool EnQueue(const ItemType& item);

	/*
		@brief	TempList을 Dequeue한다.
		@pre	TempList가 initialize돼야한다
		@post	TempList에 item이 Dequeue되고 NumOfItems--
		@param	item	Dequeue된 item을 참조
		@return Dequeue가 되었으면 return true, 아니면 return false
	*/
	bool DeQueue(ItemType& item);

	/*
		@brief	TempItemList를 비운다.
		@pre	TempItemList가 initialize돼야한다
		@post	TempItemList가 empty된다.
	*/
	void MakeEmpty();

	/*
		@brief	param의 Id와 같은 Id를 가진 item을 TempItemList에서 찾아 참조함
		@pre	TempItemList가 initialized 돼야한다.
		@post	param의 Id와 같은 Id를 가진 item을 참조함
		@param	item	같은 Id를 가진 TempItemList의 item을 참조함
		@return	item을 찾으면 return true, 아니면 return false

	*/
	bool Retrieve(ItemType& item);

	/*
		@brief	param의 Id와 같은 Id를 가진 item을 TempItemList에서 찾아 삭제하고 참조함
		@pre	TempItemList가 initialized 돼야한다.
		@post	param의 Id와 같은 Id를 가진 item이 TempItemList에서 삭제되고 참조됨
		@param	item	같은 Id를 가진 TempItemList의 item을 참조함
		@return	item을 성공적으로 삭제하면 return true, 아니면 return false
	*/
	bool Delete(ItemType& item);

	/*
		@brief	param의 Id와 같은 Id를 가진 item을 TempItemList에서 찾아 정보를 Replace한다.
		@pre	TempItemList가 initialized 돼야한다.
		@post	param의 Id와 같은 Id를 가진 item이 param으로 replace된다.
		@param	item	교체하고자 하는 item
		@return	item을 성공적으로 교체하면 return true, 아니면 return false
	*/
	bool Replace(const ItemType& item);

	/*
		@brief	TempItemList에 있는 모든 원소를 Display한다.
		@pre	TempItemList가 initialize 돼야한다.
		@post	TempItemList의 모든 원소가 display된다.
	*/
	bool DisplayAllTempItems();
private:
	int NumOfItems;
	Queue<ItemType> m_TempItemList;
};

