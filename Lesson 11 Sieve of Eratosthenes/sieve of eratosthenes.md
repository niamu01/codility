### wiki
- https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes (소수 판정 방법: 소수를 고른 후 그의 제곱부터 배수를 없앤다)

```cpp
void Eratos(int n)
{
	if (n <= 1) return;

	bool* PrimeArray = new bool[n + 1];

	for (int i = 2; i <= n; i++)
	    PrimeArray[i] = true;

	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
		{
			for (int j = i * i; j <= n; j += i)
			    PrimeArray[j] = false;
		}
	}

}
```

### Sieve of Eratosthenes
- The Sieve of Eratosthenes is a very simple and popular technique for finding all the prime numbers in the range from 2 to a given number n.
- The above algorithm can be slightly improved. Notice that we needn’t cross out multiples of i which are less than i^2. Such multiples are of the form k · i, where k < i. These have already been removed by one of the prime divisors of k.

Sieve of Eratosthenes.
```python
def sieve(n):
	sieve = [True] * (n + 1)
	sieve[0] = sieve[1] = False
	i = 2
	while (i * i <= n):
		if (sieve[i]):
		k = i * i
		while (k <= n):
			sieve[k] = False
			k += i
		i += 1
	return sieve
```
### Factorization
- Factorization is the process of decomposition into prime factors
- Use of the sieve enables fast factorization.
- For every crossed number we will remember the smallest prime that divides this number.


Preparing the array F for factorization.
```python
def arrayF(n):
	F = [0] * (n + 1)
	i = 2
	while (i * i <= n):
		if (F[i] == 0):
			k = i * i
			while (k <= n):
				if (F[k] == 0):
					F[k] = i;
					k += i
		i += 1
	return F
```
For example, take an array F with a value of n = 20:
F[] = {0 0 0 0 2 0 2 0 2 3 2 0 2 0 2 3 2 0 2 0 2}

Factorization of x — O(log x).
```python
def factorization(x, F):
	primeFactors = []
	while (F[x] > 0):
		primeFactors += [F[x]]
		x /= F[x]
	primeFactors += [x]
	return primeFactors
```
Number x cannot have more than log x prime factors, because every prime factor is >= 2.
Factorization by the above method works in O(log x) time complexity.
Note that consecutive factors will be presented in non-decreasing order.