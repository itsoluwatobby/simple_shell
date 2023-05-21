#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* value = getenv("MY_CUS");
	
	if (value != NULL)
	{
		printf("Environment variable value: %s\n", value);
	}
	else
	{
		printf("Environment variable not found.\n");
	}

	return 0;
}
