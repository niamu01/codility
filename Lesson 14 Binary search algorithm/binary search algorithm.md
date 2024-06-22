Binary search in O(log n).
```python
def binarySearch(A, x):
	n = len(A)
	beg = 0
	end = n - 1
	result = -1
	while (beg <= end):
		mid = (beg + end) / 2
		if (A[mid] <= x):
			beg = mid + 1
			result = mid
		else:
			end = mid - 1
	return result
```

Binary search in O(log n).
```python
def boards(A, k):
	n = len(A)
	beg = 1
	end = n
	result = -1
	while (beg <= end):
		mid = (beg + end) / 2
		if (check(A, mid) <= k):
			end = mid - 1
			result = mid
		else:
			beg = mid + 1
	return result
```

Greedily check in O(n).
```python
def check(A, k):
	n = len(A)
	boards = 0
	last = -1
	for i in xrange(n):
		if A[i] == 1 and last < i:
		boards += 1
		last = i + k - 1
	return boards
```