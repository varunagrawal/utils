#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

long gcd(long a, long b){

	while(true){
		if(a == 0)
			return b;
		else if(b == 0)
			return a;
		else{
			a = a % b;

            a = a + b;
			b = a - b;
			a = a - b;
		}
	}
}

int extendedEuclidean(int a, int b){
    int p = a; //Saving the original value of a for negative remainders

    std::vector<int> r, q, x, y;
	r.clear();
	q.clear();
	x.clear();
	y.clear();

	int i = 0;
	r.push_back(a);
	r.push_back(b);

	q.push_back(-1);
	q.push_back(-1);

	x.push_back(1);
	x.push_back(0);

	y.push_back(0);
	y.push_back(1);

	i = 2;
	while(true){

		r.push_back((abs(a)) % b);
		q.push_back( a/b );
		x.push_back( x[i-2] - q[i]*x[i-1] );
		y.push_back( y[i-2] - q[i]*y[i-1] );

		if(r[i] == 0)
			break;

        a = b;
		b = r[i];

		i++;
	}

	if(y[i-1] >= 0) return y[i-1];
    else return (p + y[i-1]);
}

int parse(std::vector<int>& n, std::vector<int> &a)
{
    n.clear();
    a.clear();

    int t, ni, ai;
    scanf("%d", &t);
    // printf("%d\n", t);
    for(int j=0;j<t;j++)
    {
        std:: string s = "";
        for(int i=0;i<5;i++)
        {
            if(i == 2)
                std::cin >> ai;
            else if(i == 4)
                std::cin >> ni;
            else std::cin >> s;

        }

        a.push_back(ai);
        n.push_back(ni);

    }

    return t;
}

int main(int argc, char** argv)
{

    std:: vector<int> n;
    std:: vector<int> a;

    int M, x, t;

    t = parse(n, a);

    /*
    n.resize(t);
    a.resize(t);

    for(int i=0;i<t;i++)
    {
        scanf("%d %d", &n[i], &a[i]);
    }
    */

    M = 1;
    for(int i=0;i<t;i++)
    {
        M *= n[i];
    }

    x = 0;
    for(int i=0;i<t;i++)
    {
        int Mi = M/n[i];
        x += a[i] * Mi * extendedEuclidean(n[i], Mi);
    }
    x = x % M;

    printf("x = %d\n", x);

    return 0;
}
