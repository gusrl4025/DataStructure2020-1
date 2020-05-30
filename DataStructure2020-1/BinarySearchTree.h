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
		@brief	tree�� ����
		@pre	none
		@post	tree�� �������
	*/
	void MakeEmpty();

	/*
		@brief	m_Length�� ��ȯ�Ѵ�
		@pre	none
		@post	none
		@return m_Length
	*/
	int GetLength() const;

	/*
		@brief	tree�� ������� �˻��Ѵ�
		@pre	tree�� iniitialize �ž��Ѵ�
		@post	none
		@return	tree�� empty�� return true, �ƴϸ� return false
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

// tree�� ����
template<typename ItemType>
inline void BinarySearchTree<ItemType>::MakeEmpty()
{
	MakeEmptyTree(root);
}

// tree�� node ���� ��ȯ�Ѵ�
template<typename ItemType>
inline int BinarySearchTree<ItemType>::GetLength() const
{
	return CountNodes(root);
}

// tree�� ������� Ȯ���Ѵ�
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::IsEmpty() const
{
	if (root == nullptr)
		return true;
	return false;
}

// tree�� item�� �߰�
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::Add(const ItemType& item)
{
	return InsertNode(root, item);
}

// tree���� item�� �˻�
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::Retrieve(ItemType& item)
{
	return RetrieveNode(root, item);
}

// tree���� item�� ����
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::Delete(ItemType& item)
{
	return FindItemToDelete(root, item);
}

// tree���� item�� ����
template<typename ItemType>
inline bool BinarySearchTree<ItemType>::Replace(const ItemType& item)
{
	return ReplaceNode(root, item);
}

// tree�� ����
template<typename ItemType>
void MakeEmptyTree(BinaryTreeNode<ItemType>*& root)
{
	if (root != nullptr) {	// root�� null�� ������(leaf ���) �ϳ��� �����Ѵ�
		MakeEmptyTree(root->left);
		MakeEmptyTree(root->right);
		delete root;
	}
}

// Node�� ���� ����
template<typename ItemType>
int CountNodes(BinaryTreeNode<ItemType>*& root, const ItemType& item)
{
	if (root == nullptr)
		return 0;
	// �ϳ��� ������ ������ ���� ī��Ʈ�� 1���ø���
	return CountNodes(root->left) + CountNodes(root->right) + 1;
}

// BinarySearchTree�� ���ο� ��� �߰�
template<typename ItemType>
bool InsertNode(BinaryTreeNode<ItemType>*& root, const ItemType& item)
{
	if (root == nullptr)				// root�� null�� ��� 
	{
		root = new BinaryTreeNode<ItemType>;	// root ��� ����
		root->left = nullptr;			// root ����̹Ƿ� left�� right�� NULL�� ����
		root->right = nullptr;
		root->data = item;			// root ����� ��
		return true;
	}
	else if (root->data == item)
			return false;
	else if (root->data > item)		// root�� �����ϰ�, �� ���� ���ο� item ������ Ŭ ��
		InsertNode(root->left, item);	// root�� �������� Insert �Լ� �ٽ� ȣ��
	else if (root->data < item)		// root�� �����ϰ�, �� ���� ���ο� item ������ ���� ��
		InsertNode(root->right, item);	// root�� ���������� Insert �Լ� �ٽ� ȣ��
}

// ���� ū ���� ã�� �Լ� 
template<typename ItemType>
void GetPredecessor(BinaryTreeNode<ItemType>* root, ItemType& item)
{
	while (root->right != nullptr)			// root�� �������� ������ ���
		root = root->right;				// root�� ������ ��尪�� root�� ������ �Ѵ�
	item = root->data;					// root ����� ���� item�� �����Ѵ�.
}

// ������� ��带 ã���� ������ Ʈ������ �� ��带 ����� �Լ�
template<typename ItemType>
void DeleteNode(BinaryTreeNode<ItemType>*& root)
{
	ItemType item;
	BinaryTreeNode<ItemType>* tempPtr;			// �ӽ� ��带 �����ϰ� root ��带 �ӽ� ��忡 ����
	tempPtr = root;

	if (root->left == nullptr)				// ���ʳ�尡 ���� ��
	{
		root = root->right;				// ������ ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else if (root->right == nullptr)		// �����ʳ�尡 ���� ��
	{
		root = root->left;				// ���� ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// �߰��� �ִ� ��带 ����� ���� �� (left, right, child ��� ���� ���)
		root->data = item;					// ������� ��庸�� ���� ���� �߿� ���� ū ��带 ã��
		FindItemToDelete(root->left, item);			// �� ���� ���� ��忡 ���縦 �ؼ� ���� ��ó�� ������
	}
}

// ���� ������� �ϴ� ��带 ã�� recursive �Լ�
template<typename ItemType>
bool FindItemToDelete(BinaryTreeNode<ItemType>*& root, ItemType item)
{
	if (item < root->data)				// root��尪���� item��尡 ���� ��
		FindItemToDelete(root->left, item);		// ���ʳ��� ���� delete�Լ� ȣ��
	else if (item > root->data)			// root��尪���� item��尡 Ŭ ��
		FindItemToDelete(root->right, item);		// �����ʳ��� ���� delete�Լ� ȣ��
	else {
		DeleteNode(root);				// ã���� �ϴ� ���� ��ġ�ϴ� ��� deletenode �Լ� ȣ��
		return true;
	}
}

// Tree���� node�� �˻��ϴ� �Լ�
template<typename ItemType>
bool RetrieveNode(BinaryTreeNode<ItemType>* root, ItemType& item)
{
	if (root == nullptr)						// root�� NULL�� ��� found�� false 
		return false;
	else if (item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		RetrieveNode(root->left, item);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		RetrieveNode(root->right, item);	// ������ ���� ���� retrieve �Լ� ȣ��
	else
	{										// ã���� �ϴ� ���� ��ġ�� ��
		item = root->data;					// item�� ��� ������ ����
		return true;						// ã������ true�� return
	}
}

// Tree���� node�� �����Ѵ�
template<typename ItemType>
bool ReplaceNode(BinaryTreeNode<ItemType>* root, const ItemType& item)
{
	if (root == nullptr)				// root�� NULL�� ��� found�� false
		return false;
	else if (root->data > item)			// ã���� �ϴ� ������ ���� root ������ ���� ��
		ReplaceNode(root->left, item);	// ���� ���� ���� replace �Լ� ȣ��
	else if (root->data < item)			// ã���� �ϴ� ������ ���� root ������ Ŭ ��
		ReplaceNode(root->right, item);	// ������ ���� ���� replace �Լ� ȣ��
	else
	{									// ã���� �ϴ� ���� ��ġ�� ��
		root->data = item;				// item�� ��� ������ ����
		return true;					// ã������ true�� return
	}
}
