#include <iostream>


int main() {
	int A, B, V;

	scanf("%d%d%d", &A, &B, &V);

	int result = (V - A) / (A - B);
	++result;
	
	if(((V - A) % (A - B)) == 0) printf("%d", result);
	else printf("%d", result + 1);

	return 0;

}