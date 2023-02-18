#include <iostream>
#include <vector>

using namespace std;

class ListNode {
	private:
		int val;
		ListNode *next;
		/*
			返回第index位的链表节点
		*/
		ListNode *indexToNext(int index) {
			int count = 0;
			ListNode* temp = this;
			while (temp) {
				// 保证没到空指针(链表尾)

				if (count == index) {
					//判断是不是要找的位置
					return temp;
				}
				// 跳转到下一位
				temp = temp->next;
				// 把计数器加一
				count++;
			}
		}
	public:
		/*
			默认构造
		*/
		ListNode(int val = 0) {
			this->val = val;
			this->next = nullptr;
		}
		
		/*
			通过vector数组构造
		*/
		ListNode(vector<int> vals) {
			ListNode* temp = this;
			
			for (int i = 0; i < (int)vals.size() - 1; i++) {
				temp->setValue(vals[i]);
				temp->setNext(new ListNode());
				temp = temp->getNext();
			}
			temp->setValue(vals[vals.size() - 1]);
		}
		
		/*
			通过arr数组与数组大小size构造
		*/
		ListNode(int *arr, int size) {
			ListNode* temp = this;
			for (int i = 0; i < size - 1; i++) {
				temp->setValue(arr[i]);
				temp->setNext(new ListNode());
				temp = temp->getNext();
			}
			temp->setValue(arr[size - 1]);
		}

		/*
			析构
		*/
		~ListNode() {
			// TODO
			ListNode* temp = this;
			while (temp) {
				//TODO
				ListNode* t = temp->next;
				delete temp;
				temp = t;
			}
		}

		/*
			存取器
		*/
		int getValue() {
			return this->val;
		}

		void setValue(int val) {
			this->val = val;
		}

		ListNode* getNext() {
			return this->next;
		}

		void setNext(ListNode* next) {
			this->next = next;
		}

		/*
			创建下一个链表节点
			并返回新创建的节点
		*/
		ListNode* createNext(int val = 0) {
			this->next = new ListNode(val);
			return this->next;
		}

		/*
			返回index位的节点的值
			错误返回d的值
		*/
		int getIndex(int index, int d = -1) {
			if (index < 0) {
				// 小于0的下标返回错误值
				return d;
			}

			// 如果到链表尾部了还没找到 返回错误值
			return indexToNext(index) == nullptr ? d : indexToNext(index)->getValue();
		}

		/*
			在index位置上插入val节点
			返回val节点所对应的指针
		*/
		ListNode* insert(int index, int val) {
			if (index < 1) {
				// 不能改变头指针
				return nullptr;
			}
			index--;
			ListNode* temp = indexToNext(index);
			if (temp == nullptr) {
				return nullptr;
			}
			ListNode* add = new ListNode(val);
			add->setNext(temp->getNext());
			temp->setNext(add);
			return add;
		}

		/*
			删除index下标下的节点
			返回删除的下一个节点
		*/

		ListNode* del(int index) {
			if (index < 1) {
				// 不能改变头指针
				return nullptr;
			}
			index--;

			ListNode* temp = indexToNext(index);
			if (temp == nullptr) {
				return temp;
			}
			temp->setNext(temp->getNext()->getNext());
			return temp->getNext();
		}

		/*
			打印链表里所有元素
		*/
		void printAll() {
			ListNode* node = this;
			while (node) {
				cout << node->val << endl;
				node = node->next;
			}
		}

		/*
			搜索val值的节点下标
			没找到返回-1
		*/
		int serachValue(int val) {
			int index = 0;
			ListNode* node = this;
			while (node) {
				if (val == node->val) {
					return index;
				}
				node = node->next;
				index++;
			}
			return -1;
		}
};

int main() {
	ListNode* myListNode = new ListNode(-1);
	myListNode->createNext(1)->createNext(2);
	myListNode->insert(3, 10);
	cout << "遍历链表" << endl;
	myListNode->printAll();
	myListNode->del(2);
	cout << "------------------" << endl;
	myListNode->printAll();
	cout << "------------------" << endl;

	int arr[] = {10, 20, 30};
	ListNode* from_arr = new ListNode(arr, 3);
	from_arr->printAll();
	cout << "------------------" << endl;
	vector<int> vecarr = {10, 20, 30};
	ListNode* from_vector = new ListNode(vecarr);
	from_vector->printAll();
	return 0;
}
