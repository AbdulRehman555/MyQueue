#include<iostream>
using namespace std;
#define SIZE 10
class Queue {
	int arr[SIZE];
	int front;
	int rear;
public:
	Queue();
	void enqueue(int);
	int dequeue();
	bool isFull();
	bool isEmpty();
	void makeNull();
	int front_of_queue();
	
	int size();
};
Queue::Queue() {
	front = rear = -1;
	for (int i = 0; i < SIZE; i++)
		arr[i] = 0;
}																			
void Queue::enqueue(int value) {											
	if (isFull()) {															
		cout << "-: Queue is full (OVERFLOW!) :-\n";
		exit(-1);
	}
	else {
		if (isEmpty())
			front = 0;
		arr[++rear] = value;
	}
}
int Queue::dequeue() {
	if (isEmpty()) {														
		cout << "-: Queue is empty (UNDERFLOW!) :-\n";						
		exit(-1);															
	}
	else {
		int temp;
		temp = arr[front];
		if (front == 0 && rear == 0)
			front = rear = -1;
		else
			front++;
		return temp;
	}
}
bool Queue::isFull() {
	if (rear == SIZE-1)
		return true;
	else
		return false;
}
bool Queue::isEmpty() {
	if (front<0 ||front>rear)
		return true;
	else
		return false;
}
void Queue::makeNull() {
	front = rear = -1;
	cout << "Now Queue is empty!\n ";
}
int Queue::front_of_queue() {
	return arr[front];
}
int Queue::size() {
	return (rear - front) + 1;
}
int main() {
	Queue Q; 
	int choice;
	int number;
	while (true) {
		cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\t\t\t            QUEUE  MENU             \n";
		cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\t\t\t             1. Enqueue             \n";
		cout << "\t\t\t             2. Dequeue             \n";
		cout << "\t\t\t             3. Size of queue       \n";
		cout << "\t\t\t             4. Front of queue      \n";
		cout << "\t\t\t             5. MakeNull            \n";
		cout << "\t\t\t             6. IsEmpty             \n";
		cout << "\t\t\t             7. IsFull              \n";
		cout << "\t\t\t             8. EXIT                \n";
		cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter an number you want to enqueue:";
			cin >> number;
			Q.enqueue(number);
			break;
		case 2:
			cout<<Q.dequeue()<<endl;
			break;
		case 3:
			cout << "Size of Queue is " << Q.size() << endl;
			break;
		case 4:
			cout << "Front of Queue is: "<<Q.front_of_queue()<<endl;
			break;
		case 5:
			Q.makeNull();
			break;
		case 6:
			if (Q.isEmpty())
				cout << "YES ----Queue is empty\n";
			else
				cout << "NO, Queue is not empty.\n";
			break;
		case 7:
			if (Q.isFull())
				cout << "YES ----Queue is full\n";
			else
				cout << "NO, Queue is not full.\n";
			break;
		case 8:
			exit(-1);
		default:
			cout << "Invalid Option\n";

		}
	}
	system("pause");
	return 0;
}
