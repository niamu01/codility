- Use of time complexity makes it easy to estimate the running time of a program.
- just a measurement of a certain order of magnitude.
- Regular operations are single additions, multiplications, assignments etc.
- The complexity is described in Big-O notation

### Comparison of different time complexities
Constant time — O(1).
```python
def constant(n):
	result = n * n
	return result
```

Logarithmic time — O(log n).
```python
def logarithmic(n):
	result = 0
	while n > 1:
		n //= 2
		result += 1
	return result
```
The value of n is halved on each iteration of the loop. If n = 2^x then log n = x.

Linear time — O(n).
```python
def linear(n, A):
	for i in xrange(n):
		if A[i] == 0:
			return 0
	return 1
```

Quadratic time — O(n^2).
```python
def quadratic(n):
	result = 0
	for i in xrange(n):
		for j in xrange(i, n):
			result += 1
	return result
```

Linear time — O(n + m).
```python
def linear2(n, m):
	result = 0
	for i in xrange(n):
		result += i
	for j in xrange(m):
		result += j
	return result
```

### Space complexity
In short, if you have constant numbers of variables, you also have constant space complexity: in Big-O notation this is O(1). If you need to declare an array with n elements, you have linear space complexity — O(n).
