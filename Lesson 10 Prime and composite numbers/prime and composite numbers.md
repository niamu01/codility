- still we continue to search for fast new algorithms that can check the primality of numbers
- A prime number is a natural number greater than 1 that has exactly two divisors (1 and itself)
- A composite number has more than two divisors.

### coutn the number of divisors of n
The easiest approach is to iterate through all the numbers from 1 to n and check whether or not each one is a divisor (The time complexity of this solution is O(n).)

if number a is a divisor of n, then n/a is also a divisor.<br>

One of these two divisors is less than or equal to √n. <br>
Thus, iterating through all the numbers from 1 to √n allows us to find all the divisors. <br>
If number n is of the form k^2, then the symmetric divisor of k is also k. (This divisor should be
counted just once.)

### Counting the number of divisors — O(√n).
```python
def divisors(n):
	i = 1
	result = 0
	while (i * i < n):
		if (n % i == 0):
			result += 2
		i += 1
	if (i * i == n):
		result += 1
	return result
```

### Primality test — O(√n).
```python
def primality(n):
	i = 2
	while (i * i <= n):
		if (n % i == 0):
			return False
		i += 1
	return True
```
We assume that 1 is neither a prime nor a composite number, so the above algorithm works only for n >= 2.
