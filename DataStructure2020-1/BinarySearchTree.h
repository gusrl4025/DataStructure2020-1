#pragma once

template <typename ItemType>
struct BinaryTreeNode
{
	ItemType data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

template<typename ItemType>
class BinarySearchTree
{
public:
	/*
		constructor
	*/
	BinarySearchTree();

	/*
		Destructor
	*/
	~BinarySearchTree();

	/*
		
	*/
	BinaryTreeNode<ItemType>* GetRoot() {
		return root;
	}

	/*
		@brief	tree를 비운다
		@pre	none
		@post	tree가 비워진다
	*/
	void MakeEmpty();

	/*
		@brief	m_Length를 반환한다
		@pre	none
		@post	none
		@return m_Length
	*/
	int GetLength() const;

	/*
		@brief	tree가 비었는지 검사한다
		@pre	tree가 iniitialize 돼야한다
		@post	none
		@return	tree가 empty면 return true, 아니면 return false
	*/
	bool IsEmpty() const;

	/*
		@brief	add new record in tree
		@pre	tree should be initialize
		@post	added the new record in tree
		@paran	data	new data
		@return	return 1 if record is added to tree successfully otherwise return 0
	*/
	bool Add(const ItemType& item);

	/*
		@brief	find item which has same keynumber of parameter in tree
		@pre	tree should be initilized
		@post	parameter changed to item which has same keynumber in tree
		@param	data	data to find
		@return	if function works successfully return true, otherwise return false
	*/
	bool Retrieve(ItemType& item);

	/*
		@brief	delete item which is same with param
		@pre	tree should be initilized
		@post	deleted data which you want to delete in tree
		@param	data	data to delete
		@return	if function works successfully return true, otherwise return false
	*/
	bool Delete(ItemType& item);
	
	/*
		@brief	replace item which has same keynumber with param
		@pre	tree should be initilized
		@post	replaced data which you want to replace in tree
		@param	data	data to replace
		@return	if function works successfully return true, otherwise return false
	*/
	bool Replace(const ItemType& item);

private:
	BinaryTreeNode<ItemType>* root;
};

// constructor
template<typename ItemType>
inline BinarySearchTree<ItemType>::BinarySearchTree()
{
	root = nullptr;
}

// destructor
template<typename ItemType>
inline BinarySearchTree<ItemType>::~BinarySearchTree()
{
	MakeEmptyTree(root);
}

// tree를 비운다
template<typename ItemType>
inline void BinarySearchTree<ItemType>::MakeEmpty()
{
	MakeEmptyTree(root);
}

// tree의 node 수를 반환한다
template<typename ItemType>
inline int BinarySearchTree<ItemType>::GetLength() const
{
	return CountNodes(root);
}

// tree가 비었는지 확인한다
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::IsEmpty() const
{
	if (root == nullptr)
		return true;
	return false;
}

// tree에 item을 추가
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::Add(const ItemType& item)
{
	return InsertNode(root, item);
}

// tree에서 item을 검색
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::Retrieve(ItemType& item)
{
	return RetrieveNode(root, item);
}

// tree에서 item을 제거
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::Delete(ItemType& item)
{
	return FindItemToDelete(root, item);
}

// tree에서 item을 수정
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::Replace(const ItemType& item)
{
	return ReplaceNode(root, item);
}

// tree를 비운다
template<typename ItemType>
void MakeEmptyTree(BinaryTreeNode<ItemType>*& root)
{
	if (root != nullptr) {	// root가 null일 때까지(leaf 노드) 하나씩 제거한다
		MakeEmptyTree(root->left);
		MakeEmptyTree(root->right);
		delete root;
	}
}

// Node의 수를 센다
template<typename ItemType>
int CountNodes(BinaryTreeNode<ItemType>*& root, const ItemType& item)
{
	if (root == nullptr)
		return 0;
	// 하나씩 내려갈 때마다 숫자 카운트를 1씩늘린다
	return CountNodes(root->left) + CountNodes(root->right) + 1;
}

// BinarySearchTree에 새로운 노드 추가
template<typename ItemType>
bool InsertNode(BinaryTreeNode<ItemType>*& root, const ItemType& item)
{
	if (root == nullptr)				// root가 null일 경우 
	{
		root = new BinaryTreeNode<ItemType>;	// root 노드 생성
		root->left = nullptr;			// root 노드이므로 left와 right는 NULL로 설정
		root->right = nullptr;
		root->data = item;			// root 노드의 값
		return true;
	}
	else if (root->data == item)
			return false;
	else if (root->data > item)		// root가 존재하고, 그 값이 새로운 item 값보다 클 때
		InsertNode(root->left, item);	// root의 왼쪽으로 Insert 함수 다시 호출
	else if (root->data < item)		// root가 존재하고, 그 값이 새로운 item 값보다 작을 때
		InsertNode(root->right, item);	// root의 오른쪽으로 Insert 함수 다시 호출
}

// 가장 큰 값을 찾는 함수 
template<typename ItemType>
void GetPredecessor(BinaryTreeNode<ItemType>* root, ItemType& item)
{
	while (root->right != nullptr)			// root의 오른쪽이 존재할 경우
		root = root->right;				// root의 오른쪽 노드값이 root에 오도록 한다
	item = root->data;					// root 노드의 값을 item에 복사한다.
}

// 지우려는 노드를 찾으면 실제로 트리에서 그 노드를 지우는 함수
template<typename ItemType>
void DeleteNode(BinaryTreeNode<ItemType>*& root)
{
	ItemType item;
	BinaryTreeNode<ItemType>* tempPtr;			// 임시 노드를 생성하고 root 노드를 임시 노드에 복사
	tempPtr = root;

	if (root->left == nullptr)				// 왼쪽노드가 없을 때
	{
		root = root->right;				// 오른쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else if (root->right == nullptr)		// 오른쪽노드가 없을 때
	{
		root = root->left;				// 왼쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// 중간에 있는 노드를 지우고 싶을 때 (left, right, child 노드 있을 경우)
		root->data = item;					// 지우려는 노드보다 작은 노드들 중에 가장 큰 노드를 찾음
		FindItemToDelete(root->left, item);			// 그 값을 지울 노드에 복사를 해서 지운 것처럼 눈속임
	}
}

// 내가 지우려고 하는 노드를 찾는 recursive 함수
template<typename ItemType>
bool FindItemToDelete(BinaryTreeNode<ItemType>*& root, ItemType item)
{
	if (item < root->data)				// root노드값보다 item노드가 작을 때
		FindItemToDelete(root->left, item);		// 왼쪽노드로 가서 delete함수 호출
	else if (item > root->data)			// root노드값보다 item노드가 클 때
		FindItemToDelete(root->right, item);		// 오른쪽노드로 가서 delete함수 호출
	else {
		DeleteNode(root);				// 찾고자 하는 값이 일치하는 경우 deletenode 함수 호출
		return true;
	}
}

// Tree에서 node를 검색하는 함수
template<typename ItemType>
bool RetrieveNode(BinaryTreeNode<ItemType>* root, ItemType& item)
{
	if (root == nullptr)						// root가 NULL인 경우 found는 false 
		return false;
	else if (item < root->data)				// 찾고자 하는 아이템값이 root값보다 작을 때 
		RetrieveNode(root->left, item);	// 왼쪽 노드로 가서 retrieve 함수 호출
	else if (item > root->data)				// 찾고자 하는 아이템값이 root값보다 클 때
		RetrieveNode(root->right, item);	// 오른쪽 노드로 가서 retrieve 함수 호출
	else
	{										// 찾고자 하는 값과 일치할 때
		item = root->data;					// item에 노드 정보를 복사
		return true;						// 찾았으니 true를 return
	}
}

// Tree에서 node를 수정한다
template<typename ItemType>
bool ReplaceNode(BinaryTreeNode<ItemType>* root, const ItemType& item)
{
	if (root == nullptr)				// root가 NULL인 경우 found는 false
		return false;
	else if (root->data > item)			// 찾고자 하는 아이템 값이 root 값보다 작을 때
		ReplaceNode(root->left, item);	// 왼쪽 노드로 가서 replace 함수 호출
	else if (root->data < item)			// 찾고자 하는 아이템 값이 root 값보다 클 때
		ReplaceNode(root->right, item);	// 오른쪽 노드로 가서 replace 함수 호출
	else
	{									// 찾고자 하는 값과 일치할 때
		root->data = item;				// item에 노드 정보를 복사
		return true;					// 찾았으니 true를 return
	}
}
