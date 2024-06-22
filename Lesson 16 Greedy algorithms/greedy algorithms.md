- Greedy programming is a method by which a solution is determined based on making the locally optimal choice at any given moment.
- In other words, we <u>choose the best decision</u> from the viewpoint of the current stage of the solution.

### The Coin Changing problem
- you are asked to find the minimum number of coins with which a given amount of money can be paid.
- That problem can be approached by a greedy algorithm that always selects the largest denomination not exceeding the remaining amount of money to be paid.

The greedy algorithm for finding change.
```python
def greedyCoinChanging(M, k):
	n = len(M)
	result = []
	for i in xrange(n - 1, -1, -1):
		result += [(M[i], k // M[i])]
		k %= M[i]
	return result
```