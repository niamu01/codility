- Sorting is the process of arranging data in a certain order.
- There are many sorting algorithms, and they differ considerably in terms of their time complexity and use of memory.

Selection sort — O(n^2)
- Find the minimal element and swap it with the first element of an array.
- Next, just sort the rest of the array, without the first element, in the same way.
- The time complexity is quadratic.
```python
def selectionSort(A):
	n = len(A)
	for k in xrange(n):
		minimal = k
		for j in xrange(k + 1, n):
			if A[j] < A[minimal]:
				minimal = j
		A[k], A[minimal] = A[minimal], A[k] # swap A[k] and A[minimal]
	return A
```

Counting sort — O(n + k)
- _count array를 활용한 정렬 방법_
- First, count the elements in the array of counters
- Next, just iterate through the <u>array of counters</u> (the array used for counting should be of size k + 1.)
- The time complexity here is `O(n + k)` _(데이터개수+최댓값크기)_. We need additional memory `O(k)` to count all the elements
```python
def countingSort(A, k):
	n = len(A)
	count = [0] * (k + 1)
	for i in xrange(n):
		count[A[i]] += 1
	p = 0
	for i in xrange(k + 1):
		for j in xrange(count[i]):
			A[p] = i
			p += 1
	return A
```

Merge sort
- Divide the unsorted array into two halves, sort each half separately and then just merge them. 
- The length of the array is halved on each iteration. In this way, we get consecutive levels with 1, 2, 4, 8, . . . slices. 
- For each level, the merging of the all consecutive pairs of slices requires O(n) time. 
- The number of levels is O(log n), so the total time complexity is O(n log n)

Sorting functions
- If the range of sorted values is unknown, then there are algorithms which sort all the values in O(n log n) time
- A big advantage of many programming languages are their built-in sorting functions. 