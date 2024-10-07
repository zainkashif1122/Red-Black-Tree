# Red-Black Tree Data Structure
Take a look at my Red-Black Tree Data Structure project in C++, featuring efficient operations like insertion, deletion, search, and more, while maintaining balance! 🌳

## Table of Contents
1. [Introduction](#introduction)
2. [Project Overview](#project-overview)
3. [Features](#features)
4. [Installation](#installation)
5. [Live Preview of the Recording](#live-preview-of-the-recording)
6. [File Structure](#file-structure)
7. [Technologies Used](#technologies-used)
8. [Code Explanation](#code-explanation)
9. [Future Improvements](#future-improvements)
10. [Conclusion](#conclusion)

## Introduction
Explore my implementation of the **Red-Black Tree (RBT)** in C++! This project demonstrates the key operations of a Red-Black Tree, a balanced binary search tree that ensures efficient search, insertion, and deletion operations. By enforcing properties like color-coding of nodes (red or black) and maintaining tree height balance through rotations, this implementation optimizes performance to O(log n) for common operations.

The Red-Black Tree provides robust support for common tree operations, including insertion and deletion, while ensuring that the tree remains balanced. Additionally, it includes features to search for elements, find the minimum and maximum values, as well as compute the predecessor and successor of any node.

## Project Overview
The project includes a C++ implementation of a Red-Black Tree. It maintains balance by enforcing rules such as every node being either red or black, the root and leaves (NIL nodes) always being black, and no two consecutive red nodes. Additionally, all paths from a node to its descendant NIL nodes must have the same number of black nodes.

## Features
- **Insertion**:  
  Inserts new elements into the tree while maintaining the Red-Black Tree properties. The tree rebalances itself using rotations and color changes where necessary.

- **Deletion**:  
  Removes elements from the tree and ensures the structure remains balanced by applying appropriate rebalancing operations, such as rotations and color adjustments.

- **In-Order Display**:  
  Displays the elements of the tree in an in-order sequence (left subtree, root, right subtree). This ensures that the elements are printed in sorted order.

- **Pre-Order Display**:  
  Displays the elements of the tree in a pre-order sequence (root, left subtree, right subtree), which is useful for tasks like copying the tree structure.

- **Post-Order Display**:  
  Displays the elements of the tree in a post-order sequence (left subtree, right subtree, root), which is typically used for tree deletion or cleanup operations.

- **Minimum Value**:  
  Retrieves and returns the minimum value in the tree, which is located at the leftmost node.

- **Maximum Value**:  
  Retrieves and returns the maximum value in the tree, located at the rightmost node.

- **Search**:  
  Efficiently searches for a specified value in the tree. If the value exists, the function returns the corresponding node; otherwise, it indicates that the value is not 
  found.

- **Height Calculation**:  
  Computes and returns the height of the tree, or the height of a subtree rooted at a specified node. The height helps determine the longest path from the root to a leaf.

- **Successor**:  
  Finds the successor of a given node, which is the node with the smallest value greater than the specified node.

- **Predecessor**:  
  Finds the predecessor of a given node, which is the node with the largest value smaller than the specified node.

## Installation
To run the **Red-Black Tree Data Structure**, ensure you have a C++ compiler installed (like g++ or Visual Studio) and follow these steps:

1. **Download the Source Code**: Clone or download the source files from this repository.
   
2. **Compile the Code**: Open your terminal or command prompt, navigate to the directory containing the source code, and use the following command to compile:

   ```bash
   g++ Main.cpp -o RedBlackTree
   ```

3. **Run the Program**: After compiling, you can run the program with:

   ```bash
   ./RedBlackTree
   ```

## Live Preview of the Recording
Experience a real-time demonstration of the Red-Black Tree operations, showcasing insertion, deletion, and traversal functionalities in action!

[Screen Recording](screenRecording.mp4)

> **Note:** The quality of these screen recordings has been reduced to comply with GitHub's 25MB file size limit.

## File Structure

Here’s a breakdown of the files included in the project:

- [Main.cpp](Main.cpp)  
  Main file where program execution begins. It interacts with the user to insert, delete, search, and display Red-Black Tree elements.

- [MyRBT.h](MyRBT.h)  
  Header file containing the implementation of the Red-Black Tree class, including all major operations like insertion, deletion, and balance maintenance.

- [RBT.h](RBT.h)  
  Additional helper functions and classes related to Red-Black Tree functionality.

- [Node.h](Node.h)  
  Defines the structure of a node in the Red-Black Tree, including properties like color (red/black), pointers to parent and child nodes, and data.

## Technologies Used

- **Software/Compilers**: Visual Studio, Visual Studio Code, Dec-C++
- **Languages**: C++

## Code Explanation

The core functionality of a Red-Black Tree (RBT) revolves around ensuring a balanced tree structure while maintaining efficient search, insertion, and deletion operations. This is achieved through a set of rules that enforce balance and rotations to restore balance when necessary. Below is an in-depth explanation of each component in the code:

### **Node Structure**

- Each node in the Red-Black Tree contains multiple key attributes:
  - **Data (T value)**: The actual value that the node holds, where `T` is a templated data type to allow for flexibility (integers, floats, etc.).
  - **Color**: The node is either **red** or **black**, with the root always being black and additional constraints placed on red nodes (no two consecutive red nodes).
  - **Parent Pointer**: A reference to the node’s parent, which is critical for rebalancing after insertions and deletions.
  - **Left and Right Pointers**: These point to the node's left and right children in the tree. If a child does not exist, the pointer may reference a **NIL node** (a sentinel representing null).

### **Insertion**

- **Objective**: Insert a new element while preserving the Red-Black Tree properties.
  
  After inserting a node in the tree (typically at a leaf position), the following operations ensure the tree maintains balance:
  
  1. **Color the New Node Red**: Initially, the new node is colored red because it is less disruptive to the tree's black-height property.
  
  2. **Check Violations**: If the parent node is also red, this leads to a violation of the Red-Black Tree properties (no two consecutive red nodes). To fix this, rotations and color changes are applied.
  
  3. **Rotations and Color Flips**:
     - **Left and Right Rotations**: These are fundamental operations that adjust the tree structure without violating the binary search tree (BST) properties. Rotations are used to fix unbalanced portions of the tree.
     - **Recoloring**: If the inserted node’s parent and uncle are both red, a simple recoloring of the parent, uncle, and grandparent may fix the violation.
  
  4. **Recur Up the Tree**: This process continues recursively until either the tree becomes balanced or the root is reached. If the root is red, it is recolored to black to maintain tree balance.

### **Deletion**

- **Objective**: Remove a node from the tree and maintain the Red-Black properties.
  
  The deletion process is slightly more complex than insertion due to the need to fix violations after removing a node. The key steps are:
  
  1. **Standard Binary Search Tree Deletion**: First, find the node to be deleted using regular BST deletion. This may involve finding the in-order predecessor or successor if the node has two children.
  
  2. **Fix Double Black**: After removing the node, a **double black** condition may occur, especially when a black node is deleted. A double black node violates the Red-Black Tree property that all paths from the root to leaves must have the same number of black nodes.
  
  3. **Resolve Double Black with Rotations**:
     - **Sibling is Red**: A rotation is performed, and the sibling is recolored to fix the double black issue.
     - **Sibling is Black with Red Child**: Perform rotations and recolor nodes to eliminate the double black condition.
     - **Sibling and its Children are Black**: In this case, recoloring is performed, and the double black moves up the tree until it reaches the root or is resolved.
  
  4. **Root Case**: If the double black condition reaches the root, the root is recolored to black, and the process terminates.

### **In-Order, Pre-Order, and Post-Order Traversals**

- **Objective**: Display the elements of the tree in different orders (in-order, pre-order, and post-order), showcasing the structure of the Red-Black Tree.

  1. **In-Order Traversal**:
     - Visits nodes in ascending order. It first visits the left subtree, then the current node, and finally the right subtree. This traversal method is the most commonly used for binary search trees as it outputs a sorted list of elements.

  2. **Pre-Order Traversal**:
     - Visits nodes in a root-first manner. The current node is visited first, followed by the left and right subtrees. This traversal is useful for saving the structure of the tree.

  3. **Post-Order Traversal**:
     - Visits nodes in a left-right-root manner. It first processes the left subtree, then the right subtree, and finally the current node. This is used when deleting or freeing nodes in memory since it processes children before the parent.

### **Finding Minimum and Maximum Values**

- **Objective**: Return the smallest or largest element in the Red-Black Tree.
  
  1. **Minimum Value**: Traverse the left-most path of the tree to find the minimum element, as smaller values are always stored in the left subtree in a binary search tree.
  
  2. **Maximum Value**: Similarly, traverse the right-most path of the tree to find the largest element.

### **Search Operation**

- **Objective**: Locate a specific element in the tree in O(log n) time.
  
  The search operation follows the rules of binary search: if the current node’s value matches the search key, the node is returned. If the search key is smaller, the search continues recursively in the left subtree, and if larger, in the right subtree.

### **Calculating Height**

- **Objective**: Determine the height of the tree from the root to the farthest leaf.
  
  The height is a measure of the longest path from the root to any leaf. The tree's height is important for evaluating its efficiency and balance.

### **Finding Successor and Predecessor**

- **Objective**: Find the next higher (successor) or next lower (predecessor) node for a given node in the tree.
  
  1. **Successor**: The successor of a node is the smallest node that is larger than the current node. It can be found by:
     - Moving to the right subtree and finding the left-most node (if the right subtree exists).
     - Moving up the tree to the first ancestor where the node lies in the left subtree (if no right subtree exists).
  
  2. **Predecessor**: The predecessor of a node is the largest node that is smaller than the current node. It can be found by:
     - Moving to the left subtree and finding the right-most node.
     - Moving up the tree to the first ancestor where the node lies in the right subtree.

## Future Improvements

- **Visualization**:  
  Develop a GUI to visualize the tree structure dynamically as operations are performed.
  
- **Performance Testing**:  
  Add features to test the performance of the tree on large datasets and compare it with other tree structures.
  
- **Threading**:  
  Implement multithreading to handle tree operations in parallel for large datasets.

## Conclusion

The Red-Black Tree Data Structure project is a robust implementation that efficiently manages dynamic data. Its self-balancing property ensures optimal performance for insertion, deletion, and search operations.
