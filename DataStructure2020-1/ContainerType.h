#include "pch.h"

class ContainerType
{
public:
	ContainerType();
	ContainerType(int InContainerId);
	ContainerType(int InContainerId, string InLocation);
	~ContainerType();

	/*
		@brief	m_ContainerId를 가져온다
		@pre	ContainerType이 initialize 돼야한다.
		@post	none
	*/
	int GetContainerId() const;

	/*
		@brief	item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 추가한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	m_SimpleItemList에 item이 추가됐다.
		@param	item	SimpleItem으로 바꿔줄 data
		@return	return true if function works, otherwise return false
	*/
	bool AddItem(const ItemType& item);

	/*
		@brief	item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 제거한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	m_SimpleItemList에 item이 제거됐다.
		@param	item	SimpleItem으로 바꿔줄 data
		@return	return true if function works, otherwise return false
	*/
	bool DeleteItem(ItemType& item);

	/*
		@brief	item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 교체한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	m_SimpleItemList에 item이 교체됐다.
		@param	item	SimpleItem으로 바꿔줄 data
		@return	return true if function works, otherwise return false
	*/
	bool UpdateItem(const ItemType& item);

	/*
		@brief	photo를 m_photoList에 추가한다.
		@pre	m_photoList가 initialize돼야한다
		@post	m_photoList에 photo가 추가됐다.
		@param	photo	list에 추가할 photo
		@return	return true if function works, otherwise return false
	*/
	bool AddPhoto(const string& photo);

	/*
		@brief	photo를 m_photoList에 제거한다.
		@pre	m_photoList가 initialize돼야한다
		@post	m_photoList에 photo가 제거됐다.
		@param	photo	list에서 제거할 photo
		@return	return true if function works, otherwise return false
	*/
	bool DeletePhoto(string& photo);

	/*
		@brief	photo를 m_photoList에 교체한다.
		@pre	m_photoList가 initialize돼야한다
		@post	m_photoList에 photo가 교체됐다.
		@param	photo	list에 교체할 photo
		@return	return true if function works, otherwise return false
	*/
	bool UpdatePhoto(const string& photo);

	/*
		@brief	m_SimpleItemList에 있는 모든 item을 display한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	m_SimpleList에 있는 모든 item이 display된다.
	*/
	void DisplayAllItem();

	/*
		@brief	m_PhotoList에 있는 모든 photo를 display한다.
		@pre	m_PhotoList가 initialize돼야한다
		@post	m_PhotoList에 있는 모든 photo가 display된다.
	*/
	void DisplayAllPhoto();

	/*
		@brief	SimpleItem의 Name을 입력받아 m_SimpleItemList에서 같은 Name을 가진 item을 참조한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	찾으려는 Name을 가진 item이 참조된다.
		@param	item	param에 찾으려는 item을 참조한다.
		@return	원하는 item을 찾으면 return true, 아니면 return false
	*/
	bool FindByName(SimpleItemType& item);

	/*
		@brief	SimpleItem의 Kind을 입력받아 m_SimpleItemList에서 같은 Kind을 가진 item을 참조한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	찾으려는 Kind을 가진 item이 참조된다.
		@param	item	param에 찾으려는 item을 참조한다.
		@return	원하는 item을 찾으면 return true, 아니면 return false
	*/
	bool FindByKind(SimpleItemType& item);

	bool operator==(const ContainerType& container) {
		if (GetContainerId() == container.GetContainerId()) return true;
		return false;
	}

	bool operator>(const ContainerType& container) {
		if (GetContainerId() > container.GetContainerId()) return true;
		return false;
	}

	bool operator<(const ContainerType& container) {
		if (GetContainerId() < container.GetContainerId()) return true;
		return false;
	}

private:
	int m_ContainerId;
	string m_Location;
	UnSortedList<string> m_PhotoList;
	UnSortedList<SimpleItemType> m_SimpleItemList;
};
