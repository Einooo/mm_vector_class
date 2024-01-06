<h1 align="center">mmVector Class</h1>

## Overview
* **mmVector** is a C++ mini vector class designed to mimic the functionality of the STL vector class. It provides dynamic sizing and efficient element access, making it a versatile container for managing sequences of objects.
* This project was part of OOP course at [FCAI CU](https://fcai.cu.edu.eg)

---

### Features

- **Dynamic sizing:** Automatically adjusts its capacity to accommodate varying numbers of elements.
- **Efficient element access:** Provides random access to elements using array notation.
- **Copy and Move semantics:** Supports both copy and move assignment to facilitate efficient data management.
- **Iterator support:** Allows iteration through the elements using iterators similar to STL vectors.
- **Various modifying operations:** Supports push_back, pop_back, erase, insert, clear, etc.
- **Capacity operations:** Retrieve information about the current size, capacity, and resize the vector as needed.
- **Comparison operators:** Supports comparison with other mmVector instances.

---

### Usage

* #### Initializing a mmVector

```cpp
// Initialize with a specific capacity
mmVector<int> myVector(10);

// Initialize with an array of elements
int array[] = {};
mmVector<int> arrayVector(array, 5);

// Initialize with an initializer list
mmVector<int> initListVector = {1, 2, 3, 4, 5};
```


* ### Modifying operations

```cpp
// Add an element to the end
myVector.push_back(42);

// Remove the last element
int lastElement = myVector.pop_back();

// Remove an element at a specific iterator position
myVector.erase(myVector.begin() + 2);

// Insert an element at a specific iterator position
myVector.insert(myVector.begin() + 1, 99);

// Clear all elements
myVector.clear();
```


* ### Capacity Operations

```cpp
// Get the current size and capacity
int size = myVector.size();
int capacity = myVector.capacity();

// Resize the vector
myVector.resize(20);

// Check if the vector is empty
bool isEmpty = myVector.empty();
```

* ### Iteration

```cpp
// Iterate through the vector
for (auto it = myVector.begin(); it != myVector.end(); ++it) {
    // Do something with *it
}

```
* ### Comparison

```cpp
// Compare vectors
if (vector1 == vector2) {
    // Vectors are equal
}

if (vector1 < vector2) {
    // Vector1 is less than vector2
}
```


---
### Authors
* [Mina Albert](https://github.com/minaalbert33)
* [Muhannad Eino](https://github.com/Einooo)

