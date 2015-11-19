#include<stdio.h>
#include<unistd.h>

int main( int argc, char** argv )
{
	char* options = "xzf;abc;;";
	char c;

	while( (c = getopt(argc, argv, options)) != -1 )
	{
		if(c == 'x')
			printf("X is the option\n");
		else if(c == 'z')
			printf("z is the option\n");
		else if(c == 'f')
			printf("f is the option\n");
		else if(c == 'a')
			printf("a is the option\n");
		else if(c == 'b')
			printf("b is the option\n");
		else if(c == 'c')
			printf("c is the option\n");
		else
			printf("No options\n");
	}

	return 0;
}
