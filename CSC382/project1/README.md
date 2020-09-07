# CSC 382 - Project 1 (Eric Benedetto)

Comparing Fibonacci Recursion vs. Bottom Up.

## Project Description

In this project we will compare the computational time taken by a recursive algorithm to determine the Fibonacci number of an integer n and the time taken by a bottom-up approach (using a loop)  to calculate the Fibonacci number of the same integer n.

Write an algorithm that computes the time (in seconds using ctime.h header library file that takes to determine Fibonacci (n) using FiboR and the time taken by FiboNR on the same input n.
Try to run both routines using different values of n (n={1,5,10,15,20,25,30,35,40,45,50,55,60…) 


## Fibonacci Recursive vs. Non-Recursive Algorithm

```c++

#include <iostream>
#include <ctime>

using namespace std;

int FiboR(int n);
int FiboNR(int n);

int main()
{
	printf("%-10s%-20s%-20s%s","Number", "FibR (Seconds)","FiboNR (Seconds)", "Fibo-Value\n");
	for(int i = 1; i <= 60; i+=5)
	{
		clock_t t;
		t = clock();
		FiboR(i);
		t = clock() - t;

		float rs = ((float)t)/CLOCKS_PER_SEC;

		t = clock();
		int fv = FiboNR(i);
		t = clock() - t;

		float nrs = ((float)t)/CLOCKS_PER_SEC;
		printf("%02d%-8s%-20f%-20f%d\n", i, "", rs, nrs, fv); 
		
		if(i == 1) i = 0; // Reset to Iterate By 5s
	}
	

	return 0;
}

int FiboR(int n)
{
	if(n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return FiboR(n-1) + FiboR(n-2);
	}
}

int FiboNR(int n)
{
	int F[n];

	F[0] = 0;
	F[1] = 1;
	
	for(int i = 2; i <= n; i++)
	{
		F[i] = F[i-1] + F[i-2];
	}

	return F[n];

}
```

## Output

```txt
Number    FibR (Seconds)      FiboNR (Seconds)    Fibo-Value
01        0.000001            0.000011            1
05        0.000000            0.000000            5
10        0.000001            0.000001            55
15        0.000006            0.000000            610
20        0.000075            0.000000            6765
25        0.000782            0.000001            75025
30        0.007622            0.000001            832040
35        0.084945            0.000001            9227465
40        0.925959            0.000001            102334155
45        10.250280           0.000002            1134903170
50        113.741066          0.000002            12586269025
55        1270.145142         0.000001            139583862445
60        14145.756836        0.000001            1548008755920
```
