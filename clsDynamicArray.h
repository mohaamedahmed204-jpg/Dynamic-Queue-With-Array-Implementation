#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray {

protected:
    size_t _Size = 0;
    T* _TempArray;
    
public:
    T* DynamicArray;

    clsDynamicArray(size_t Size = 0) {
        if (Size < 0) Size = 0;
        _Size = Size;

        DynamicArray = new T[_Size];
    }

    ~clsDynamicArray() {
        delete[] DynamicArray;
    }

    bool SetItem(size_t index, T Value) {
        if (index >= _Size || index < 0) {
            return false;
        }

        DynamicArray[index] = Value; // DynamicArray[index] == *(DynamicArray + index) == *(index + DynamicArray);
        return true;
    }

    size_t Size() {
        return _Size;
    }

    bool IsEmpty() {
        return (_Size == 0);
    }

    void PrintList() {
        for (size_t i = 0; i < _Size; cout << DynamicArray[i++] << " ");
        cout << "\n";
    }

    void Resize(size_t NewSize) {
        if(NewSize == _Size) return;

        if(NewSize < 0) NewSize = 0;

        _TempArray = new T[NewSize];

        //limit the original size to the new size if it is less.
        size_t mn = min(_Size, NewSize);

        //copy all data from original array until the size
        for (size_t i = 0; i < mn; _TempArray[i] = DynamicArray[i], ++i);

        _Size = NewSize;

        delete[] DynamicArray;
        DynamicArray = _TempArray;
    }

    T GetItem(size_t Item) {
        return DynamicArray[Item];
    }

    void Reverse() {
        for(size_t i = 0; i < _Size/2; swap(DynamicArray[i], DynamicArray[_Size - 1ull - i]), ++i);
    }

    void Clear() {
        delete[] DynamicArray;
        DynamicArray = nullptr;
        _Size = 0;
    }

    // This code does not support reusability

    // void DeleteItemAt(size_t Index) {
    //     if(Index < 0 || Index >= _Size) return;

    //     _TempArray = new T[_Size - 1];
    //     size_t Place = 0;
    //     for(size_t i = 0; i < _Size; ++i) {
    //         if(i != Index) _TempArray[i + Place] = DynamicArray[i];
    //         else Place = -1;
    //     }

    //     --_Size;
    //     delete[] DynamicArray;
    //     DynamicArray = _TempArray;
    // }

    // void DeleteFirstItem() {
    //     _TempArray = new T[_Size - 1];
    //     for(size_t i = 1; i < _Size; _TempArray[i] = DynamicArray[i], ++i);
    //     --_Size;
    //     delete[] DynamicArray;
    //     DynamicArray = _TempArray;
    // }

    // void DeleteLastItem() {
    //     _TempArray = new T[--_Size];
    //     for(size_t i = 0; i < _Size; _TempArray[i] = DynamicArray[i], ++i);
    //     delete[] DynamicArray;
    //     DynamicArray = _TempArray;
    // }


    // This code supports reusability
    
    void DeleteItemAt(int index) {
        if (index >= _Size || index <0) return ;

        _TempArray = new T[--_Size];

        //copy all before index
        for (int i = 0; i < index; ++i) {
            _TempArray[i] = DynamicArray[i];
        }

        //copy all after index
        for (int i = index + 1; i < _Size + 1; ++i) {
            _TempArray[i - 1] = DynamicArray[i];
        }

        delete[] DynamicArray;
        DynamicArray = _TempArray;
    }

    void DeleteFirstItem() {
        DeleteItemAt(0);
    }

    void DeleteLastItem() {
        DeleteItemAt(_Size - 1);
    }

    T Find(T Item) {
        for(size_t i = 0; i < _Size; ++i) {
            if(DynamicArray[i] == Item)
                return i;
        }
        return -1;
    }

    void DeleteItem(T Item) {
        size_t Index = Find(Item);
        DeleteItemAt(Index);
    }

    void InsertAt(size_t index, T Value) {
        if (index > _Size || index < 0) return ; // index >= _Size is wrong because you can insert an item at the end 

        _TempArray = new T[++_Size];

        //copy all before index
        for (int i = 0; i < index; ++i) {
            _TempArray[i] = DynamicArray[i];
        }

        _TempArray[index] = Value;

        //copy all after index
        for (int i = index + 1; i < _Size; ++i) {
            _TempArray[i] = DynamicArray[i - 1];
        }

        delete[] DynamicArray;
        DynamicArray = _TempArray;
    }

    void InsertAtBeginning(T Value) {
        InsertAt(0, Value);
    }

    void InsertAfter(size_t index, T Value) {
        InsertAt( (index >= _Size ? _Size : index + 1) , Value);
    }

    void InsertBefore(size_t index, T Value) {
        InsertAt( (index < 1 ? 0 : index - 1) , Value);
    }

    void InsertAtEnd(T Value) {
        InsertAt(_Size, Value);
    }
    
};  


