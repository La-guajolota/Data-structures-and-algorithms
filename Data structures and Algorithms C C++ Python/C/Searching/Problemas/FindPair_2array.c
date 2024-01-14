/*
Given two array X and Y. Find a pair of elements (xi, yi) such
that xi∈X and yi∈Y where xi+yi=value.
*/

/*
!First approach:
Exhaustive search or Brute force, loop through element xi of
X and see if you can find (value – xi) in Y. Two for loop.
The Time Complexity is O(n**2) and Space Complexity is O(1)
*/

/*
!Second approach:
Sorting, Sort all the elements in the second array Y. For
each element if X you can see if that element is there in Y by using binary
search.
Sorting algorithms take O(m. log m) and searching will take O(n. log m)
time.
The Time Complexity of an algorithm is O(n.log m) or O(m.log m) and
Space Complexity is O(1)
*/

/*
!Third approach:
Sorting, Steps are as follows:
1. Sort the elements of both X and Y in increasing order.
2. Take the sum of the smallest element of X and the largest element of Y.
3. If the sum is equal to value, we got our pair.
4. If the sum is smaller than value, take next element of X
5. If the sum is greater than value, take the previous element of Y

Sorting algorithms take O(n.log n) + O(m.log m) for sorting and searching
will take O(n+m)time.
The Time Complexity of an algorithm is O(n.log n) Space Complexity is
O(1)
*/

/*
!Forth approach:
Hash-Table, Steps are as follows:
1. Scan through all the elements in the array Y and insert them into Hashtable.
2. Now scan through all the elements of array X, let us suppose the current element is xi see if you can find (value - xi) in the Hashtable.
3. If you find the value, you got your pair.
4. If not, then go to the next value in the array X.

Hash-Table insert and find take constant time O(1) so the total Time
Complexity of the algorithm is O(n) time. Space Complexity is also O(n)
*/

/*
!Fifth approach:
Counting, This approach is only possible if we know the
range of the input. Same as Hashtable implementation just use a simple array
in place of Hashtable and you are done.
Counting approach just uses an array so insert and find take constant time
O(1) so the total Time Complexity of the algorithm is O(n) time. Space
Complexity for creating count array is also O(n).
*/