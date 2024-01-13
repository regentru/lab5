#include <stdio.h>

int main(void) {
	int x, y, z, status;

	printf("Input 3 space-separated integers x, y, z: ");
	status = scanf("%d %d %d" , &x, &y, &z);

	printf("Number of correctly processed arguments: %d\n" , status);
	printf("The variables x, y, z took the values: %d, %d, %d\n", x, y, z);

	return 0;
}
