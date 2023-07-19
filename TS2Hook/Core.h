#pragma once
template <typename T>
struct LinkedList {
	struct Node {
		Node* Next;
	    Node* Previous;
		T* Pointer;
		bool IsHead() {
			// Weird
			return (int)Pointer == 0x00000010;
		}
	};
	Node* Head;
	Node* First()
	{
		return Head->Next;
	}
	int Count() {
		int count = 0;
		Node* pNode = Head;
		Node* pNextNode = Head->Next;
		while (!pNextNode->IsHead())
		{
			pNextNode = pNextNode->Next;
			count++;
		}
		return count;
	}
};
class cIGZUnknown {
private:
	virtual void* QueryInterface(int unk, void** unk2) = 0;
public:
	virtual void AddRef() = 0;
	virtual int Release() = 0;
};