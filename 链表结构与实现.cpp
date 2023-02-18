#include <iostream>
#include <vector>

using namespace std;

class ListNode {
	private:
		int val;
		ListNode *next;
		/*
			���ص�indexλ������ڵ�
		*/
		ListNode *indexToNext(int index) {
			int count = 0;
			ListNode* temp = this;
			while (temp) {
				// ��֤û����ָ��(����β)

				if (count == index) {
					//�ж��ǲ���Ҫ�ҵ�λ��
					return temp;
				}
				// ��ת����һλ
				temp = temp->next;
				// �Ѽ�������һ
				count++;
			}
		}
	public:
		/*
			Ĭ�Ϲ���
		*/
		ListNode(int val = 0) {
			this->val = val;
			this->next = nullptr;
		}
		
		/*
			ͨ��vector���鹹��
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
			ͨ��arr�����������Сsize����
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
			����
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
			��ȡ��
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
			������һ������ڵ�
			�������´����Ľڵ�
		*/
		ListNode* createNext(int val = 0) {
			this->next = new ListNode(val);
			return this->next;
		}

		/*
			����indexλ�Ľڵ��ֵ
			���󷵻�d��ֵ
		*/
		int getIndex(int index, int d = -1) {
			if (index < 0) {
				// С��0���±귵�ش���ֵ
				return d;
			}

			// ���������β���˻�û�ҵ� ���ش���ֵ
			return indexToNext(index) == nullptr ? d : indexToNext(index)->getValue();
		}

		/*
			��indexλ���ϲ���val�ڵ�
			����val�ڵ�����Ӧ��ָ��
		*/
		ListNode* insert(int index, int val) {
			if (index < 1) {
				// ���ܸı�ͷָ��
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
			ɾ��index�±��µĽڵ�
			����ɾ������һ���ڵ�
		*/

		ListNode* del(int index) {
			if (index < 1) {
				// ���ܸı�ͷָ��
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
			��ӡ����������Ԫ��
		*/
		void printAll() {
			ListNode* node = this;
			while (node) {
				cout << node->val << endl;
				node = node->next;
			}
		}

		/*
			����valֵ�Ľڵ��±�
			û�ҵ�����-1
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
	cout << "��������" << endl;
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
