#include <stdio.h>
#include <stdlib.h>
int main() {
	pid_t id;
	printf("Este es el ID de este proceso %d\n";
	(int) getpid());
	id = fork();
	if (id != 0) {
		printf("Este es el proceso padre, con ID %d\n",(int) getpid());
		printf("El ID del hijo es: %d\n", (int) id);
	}
	
}