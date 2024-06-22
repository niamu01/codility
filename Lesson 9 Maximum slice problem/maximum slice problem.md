- You are given a sequence of n integers a0, a1, . . . , an−1 
- and the task is to find the slice with the largest sum. 
- More precisely, we are looking for two indices p, q such that the total ap + ap+1 + . . . + aq is maximal. 

Maximal slice — O(n3)
- Analyzing all possible slices requires O(n2) time complexity, and for each of them we compute the total in O(n) time complexity.
```python
def slow_max_slice(A):
	n = len(A)
	result = 0
		for p in xrange(n):
			for q in xrange(p, n):
			sum = 0
			for i in xrange(p, q + 1):
				sum += A[i]
			result = max(result, sum)
	return result
```

Maximal slice — O(n2).
- Notice that the prefix sum allows the sum of any slice to be computed in a constant time. 
```python
def quadratic_max_slice(A, pref):
	n = len(A), result = 0
	for p in xrange(n):
		for q in xrange(p, n):
			sum = pref[q + 1] - pref[p]
			result = max(result, sum)
	return result
```

Maximal slice — O(n).
- For each position, we compute the largest sum that ends in that position. 
- If we assume that the maximum sum of a slice ending in position i equals max_ending, then the maximum slice ending in position i+1 equals max(0, max_ending+ ai+1).
- (max_ending: 합이 음수가 될 때 0이 되는 누적합)
```python
def golden_max_slice(A):
	max_ending = max_slice = 0
	for a in A:
		max_ending = max(0, max_ending + a)
		max_slice = max(max_slice, max_ending)
	return max_slice
```