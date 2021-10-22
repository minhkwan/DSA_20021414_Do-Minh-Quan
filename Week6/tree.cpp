#include <iostream>
using namespace std;

// Một Node trong cây
class Node
{
  // Chứa thông tin của Node đó
  int data;
  // Con trỏ đến Node cha
  Node *fatherNode;

  // Con trỏ đến các Node con
  // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
  // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
  Node *firstChild;

  Node *nextSibling;

public:
  Node(int data)
  {
    this->data = data;
    this->fatherNode = NULL;
    this->firstChild = NULL;
    this->nextSibling = NULL;
  }
  // Các hàm khởi tạo khác nếu cần thiết

  friend class Tree;
};

// Lớp Cây
class Tree
{
  // Chứa một Node gốc
  Node *root;
  int count;

public:
  Tree()
  {
    root = NULL;
    // ...
  }

  Tree(int data)
  {
    root = new Node(data);
    // ...
  }
  // Các hàm khởi tạo khác nếu cần thiết

  // Hàm thêm một Node vào cây
  // Hàm trả về false nếu Node cha không tồn tại trên cây
  // hoặc Node father đã có con là data
  bool insert(int father, int data)
  {
    if (root == NULL)
    {
      Node *newNode = new Node(data);
      root = newNode;
    }
    else
    {
      Node *nodeF = findNode(root, father);
      if (nodeF == NULL)
      {
        return false;
      }
      Node *newNode = new Node(data);
      newNode->fatherNode = nodeF;
      insertToSortedLinkedList(nodeF->firstChild, newNode);
      return true;
    }
  }

  void insertToSortedLinkedList(Node *head, Node *newNode)
  {
    Node *p = head;
    while (p->nextSibling->data < newNode->data)
    {
      p = p->nextSibling;
    }
    newNode->nextSibling = p->nextSibling;
    p->nextSibling = newNode;
  }

  Node *findNode(Node *r, int father)
  {
    if (r == NULL)
    {
      return NULL;
    }
    if (r->data == father)
    {
      return r;
    }
    Node *foundNode = findNode(r->firstChild, father);
    if (foundNode != NULL)
    {
      return foundNode;
    }
    foundNode = findNode(r->nextSibling, father);
    if (foundNode != NULL)
    {
      return foundNode;
    }
    return NULL;
  }

  // Hàm xoá một Node trên cây
  // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
  // Hàm trả về số lượng Node đã xoá
  // Nếu Node data không tồn tại trả về 0 (zero)
  int remove(int data)
  {
    Node *nodeD = findNode(root, data);
    if (nodeD == NULL)
    {
      return -1;
    }
  }

  int countNode(Node *r)
  {
    if (r == NULL)
    {
      return 0;
    }
    return 1 + countNode(r->nextSibling);
  }

  bool isBinaryTree(Node *r)
  {
    if (r == NULL)
    {
      return false;
    }
    else
    {
      int count = countNode(r->firstChild);
      if (count > 2)
      {
        return false;
      }
      else
      {
        if (count == 0)
        {
          return true;
        }
        else if (count == 1)
        {
          return isBinaryTree(r->firstChild);
        }
        else
        {
          return isBinaryTree(r->firstChild) && isBinaryTree(r->firstChild->nextSibling);
        }
      }
    }
  }

  // Hàm in ra các Node theo thứ tự preorder
  void preorder(Node *node)
  {
    cout << node->data << " ";
    if (node->firstChild != NULL)
    {
      preorder(node->firstChild);
    }
    if (node->nextSibling != NULL)
    {
      preorder(node->nextSibling);
    }
  }
  // Hàm in ra các Node theo thứ tự postorder
  void postorder(Node *node)
  {
    if (node->firstChild != NULL)
    {
      postorder(node->firstChild);
    }
    if (node->nextSibling != NULL)
    {
      postorder(node->nextSibling);
    }
    cout << node->data << " ";
  }
  // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
  void inorder(Node *node)
  {
    if (node->firstChild != NULL)
    {
      inorder(node->firstChild);
    }
    cout << node->data << " ";
    if (node->nextSibling != NULL)
    {
      inorder(node->nextSibling);
    }
  }

  // Hàm trả về độ cao của cây
  int height(Node *r)
  {
    if (r == NULL)
    {
      return -1;
    }
    if (r->firstChild == NULL)
    {
      return 0;
    }
    int maxHeight = -1;
    while (root != NULL)
    {
      int h = height(root->firstChild) + 1;
      if (maxHeight < h)
      {
        maxHeight = h;
      }
      r = r->nextSibling;
    }
    return 1 + maxHeight;
  }

  // Hàm trả về độ sâu của một Node
  int depth(Node *r)
  {
    if (r == NULL)
    {
      return -1;
    }
    return 1 + depth(r->fatherNode);
  }
};

int main(int argc, char const *argv[])
{
  // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
  // Test thử các hàm của lớp cây

  // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại

  // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
  return 0;
}
