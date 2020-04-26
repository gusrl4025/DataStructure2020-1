#include "SimpleItemType.h"

// m_Id을 가져온다
int SimpleItemType::GetId() const
{
	return m_Id;
}

// m_Name을 가져온다
string SimpleItemType::GetName() const
{
	return m_Name;
}

// m_Kind를 가져온다
int SimpleItemType::GetKind() const
{
	return m_Kind;
}

// m_Id를 Set한다
void SimpleItemType::SetId(int InId)
{
	m_Id = InId;
}

// m_Name을 set한다.
void SimpleItemType::SetName(string InName)
{
	m_Name = InName;
}

void SimpleItemType::SetKind(int InKind)
{
	m_Kind = InKind;
}

// item의 정보를 set한다.
void SimpleItemType::SetSimpleItem(int InId, string InName, int InKind)
{
	SetId(InId);
	SetName(InName);
	SetKind(InKind);
}

// m_Name을 display한다.
void SimpleItemType::DisplayNameOnScreen() {
	cout << "\tName : " << m_Name << "\n";
}

// m_Kind을 display한다.
void SimpleItemType::DisplayKindOnScreen()
{
	cout << "\tKind : " << m_Kind << "\n";
}

// m_Id를 display한다.
void SimpleItemType::DisplayIdOnScreen() {
	cout << "\tId : " << m_Id << "\n";
}

// item의 정보를 display한다.
void SimpleItemType::DisplaySimpleItemOnScreen() {
	DisplayNameOnScreen();
	DisplayKindOnScreen();
	DisplayIdOnScreen();
	cout << "\n\n";
}
