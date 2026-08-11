#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;

int main() {
    clsMyQueueArr <int> MyQueue;

    MyQueue.Push(100);
    MyQueue.Push(200);
    MyQueue.Push(300);
    MyQueue.Push(400);
    MyQueue.Push(500);

    cout << "\nQueue :\n";
    MyQueue.Print();

    cout << "\nQueue Size  : " << MyQueue.Size() << endl;
    cout << "\nQueue Front : " << MyQueue.Front() << endl;
    cout << "\nQueue Back  : " << MyQueue.Back() << endl;

    MyQueue.Pop();
    cout << "\n\nQueue after pop() :\n";
    MyQueue.Print();

    cout << "\n\nItem (2) : " << MyQueue.GetItem(2);

    MyQueue.Reverse();
    cout << "\n\nQueue after Reverse() :\n";
    MyQueue.Print();

    MyQueue.UpdateItem(2, 600);
    cout << "\n\nQueue after updating Item(2) to 600 :\n";
    MyQueue.Print();

    MyQueue.InsertAfter(2, 800);
    cout << "\n\nQueue after Inserting 800 after Item(2) :\n";
    MyQueue.Print();

    MyQueue.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at Front :\n";
    MyQueue.Print();

    MyQueue.InsertAtBack(2000);
    cout << "\n\nQueue after Inserting 2000 at Back :\n";
    MyQueue.Print();

    MyQueue.Clear();
    cout << "\n\Queue after Clear() :\n";
    MyQueue.Print();

    return 0;
}
