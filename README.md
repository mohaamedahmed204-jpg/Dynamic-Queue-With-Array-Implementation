# Dynamic-Queue-With-Array-Implementation

An efficient, template-based C++ implementation of a dynamic array `(clsDynamicArray)` and a generic queue data structure `(clsMyQueueArr)`. This repository demonstrates low-level memory management, dynamic reallocation strategies, and object-oriented structure design without relying on the standard template library (`std::vector` or `std::queue`).

## 🏗️ Overview

This project provides a ground-up implementation of fundamental container data structures in modern C++. It contains two main components:

`clsDynamicArray<T>`: A highly flexible dynamic array abstraction that handles manual heap memory allocation, resizing, item insertion, deletion, and searching.

`clsMyQueueArr<T>`: A FIFO (First-In, First-Out) Queue adapter built on top of `clsDynamicArray<T>`, showcasing code reuse and data encapsulation.

## 🏛️ Architecture & Design

The project uses a layered architecture relying on composition and encapsulation:

    +------------------------------------+
    |          clsMyQueueArr<T>          |  <-- High-Level Queue Interface (FIFO)
    +------------------------------------+
                      |
                 (uses-a / composition)
                      v
    +------------------------------------+
    |         clsDynamicArray<T>         |  <-- Low-Level Memory & Array Operations
    +------------------------------------+
                      |
                 (manages)
                      v
    +------------------------------------+
    |          Heap Memory (T*)          |  <-- Raw Dynamic Allocations (new[] / delete[])
    +------------------------------------+

### Design Highlights:

Generics via C++ Templates: Compatible with both primitive data types (`int`, `double`, `char`) and custom user-defined classes/structs.

Composition & Reusability: `clsMyQueueArr` encapsulates `clsDynamicArray` as a protected member attribute, mapping high-level queue behaviors (`push`, `pop`, `front`, `back`) directly to dynamic array operations.

RAII (Resource Acquisition Is Initialization): Dynamic memory allocated dynamically inside class constructors is automatically managed and freed via destructors to prevent memory leaks.

## ⚡ Core Operations

1. Dynamic Array Operations (`clsDynamicArray<T>`)

| Category | Method |	Description |	Time Complexity |
| :--- | :--- | :--- | :--- |
| Capacity | `Size()` | Returns the current element count. | O(1) |
| | `IsEmpty()` |	Checks if the array length is zero. | O(1) |
| | `Resize(NewSize)` |	Reallocates contiguous heap memory and preserves existing items up to `NewSize`. | O(N) |
| | `Clear()` |	Deallocates heap memory and resets state to zero size. | O(1) |
| Access | `GetItem(Index)` |	Retrieves an item at a specified array position. | O(1) |
| | `SetItem(Index, Value)` |	Bounds-checked replacement of an element at Index. | O(1) |
| | `Find(Item)` | Linear search for the first matching occurrence of Item. | O(N) |
| Insertion |	`InsertAt(Index, Value)` |	Reallocates memory and shifts items to insert Value at Index. | O(N) |
| | `InsertAtBeginning(Value)` |	Inserts an item at index 0. | O(N) |
| | `InsertAtEnd(Value)` | Appends an item to the end of the array. | O(N) |
| | `InsertBefore(Index, Value)` | Inserts Value before the specified index with safety bounds. | O(N) |
| | `InsertAfter(Index, Value)` |	Inserts Value immediately after the target index. | O(N) |
| Deletion | `DeleteItemAt(Index)` | Removes element at Index and resizes the internal buffer. | O(N) |
| | `DeleteFirstItem()` |	Removes the head element (index 0). | O(N) |
| | `DeleteLastItem()` | Removes the tail element. | O(N) |
| | `DeleteItem(Value)` |	Finds target Value and deletes its first occurrence. | O(N) |
| Utility	| `Reverse()` |	Inverts array elements in-place using symmetric swapping. | O(N) |
| | `PrintList()` |	Outputs array contents line-by-line to standard output (cout). | O(N) |
                                                                                                                                                                                                                                                                                                                                                                                                            
2. Queue Operations (`clsMyQueueArr<T>`)

| Method | Description | Underlying Operation |	Time Complexity |
| :--- | :--- | :--- | :--- |
| `push(Value)` | Enqueues a new item to the back of the queue. | `InsertAtEnd(Value)` | O(N) |
| `pop()` | Dequeues the front item from the queue. | `DeleteFirstItem()` | O(N) |
| `front()` | Returns the head item without removal. Returns default `T()` if empty. | `GetItem(0)` | O(1) |
| `back()` | Returns the tail item without removal. Returns default `T()` if empty. | `GetItem(Size - 1)` | O(1) |
| `Size()` | Returns total items currently queued. | `Size()` | O(1) |
| `IsEmpty()` | Returns true if queue contains no elements. | `IsEmpty()` | O(1) |
| `Clear()` | Empties all queue elements and resets memory. | `Clear()` | O(1) |
