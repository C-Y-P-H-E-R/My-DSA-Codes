In its simplest form, Binary Search operates on a contiguous sequence with a specified left and right index.
This is called the Search Space. 
Binary Search maintains the left, right, and middle indicies of the search space and 
compares the search target or applies the search condition to the middle value of the collection; 
if the condition is unsatisfied or values unequal, the half in which the target cannot lie is eliminated 
and the search continues on the remaining half until it is successful. 
If the search ends with an empty half, 
the condition cannot be fulfilled and target is not found.

Binary Search Runtime complexity :- O(logN)

Binary Search is an algorithm that divides the search space in 2 after every comparison.
should be considered every time you need to search for an index or element in a collection.
if the collection is unordered, we can always sort it first before applying Binary Search.

## 3 main sections of binary search: ##

***Pre-processing  - Sort if collection is unsorted.***
***Binary Search - Using a loop or recursion to divide search space in half after each comparison.***
***Post-processing - Determine viable candidates in the remaining space.***


