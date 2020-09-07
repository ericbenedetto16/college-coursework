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
