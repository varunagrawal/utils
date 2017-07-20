#include<iostream>
#include<cstdio>
#include<vector>

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
    int p = a;

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

		r.push_back(a % b);
		q.push_back( a/b );
		x.push_back( x[i-2] - q[i]*x[i-1] );
		y.push_back( y[i-2] - q[i]*y[i-1] );

		if(r[i] == 0)
			break;

        a = b;
		b = r[i];

		i++;
	}

    for(int j=0;j<i;j++){
        printf("%3d | %3d | %3d | %3d | %3d\n", j, r[j], q[j], x[j], y[j]);
    }

    printf("%d\n", y[i-1]);
	if(y[i-1] >= 0) return y[i-1];
    else return (p + y[i-1]);
}


int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int ans = extendedEuclidean(a, b);
    printf("Inverse of %d mod %d = %d\n", b, a, ans);

    return 0;
}
