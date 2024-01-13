#include<cstdio>
#include<cstdlib>
#include<ctime>

unsigned long lines_of_file ( const char * file_name ) ;

int main(int argc, char ** argv) {
	if(argc < 2) {
		fprintf(stderr, "No file name !\n");
		return 1;
	}
	srand(time(NULL));
	try {
		for (int i = 1; i < argc; i ++) {
			unsigned long res = lines_of_file(argv[i]);
			printf("The file %s contains %ld lines\n ", argv[i], res);
		}
	}
	catch(const char *exception) {
		fprintf(stderr, "Exception (string): %s\n ", exception);
		return 1;
	}
	catch (int x) {
		fprintf(stderr, "Exception (int): %d\n ", x);
	return 1;
	}
	catch (...) {
		fprintf(stderr, "Something strange happened\n");
	return 1;
	}
	return 0;
}

unsigned long lines_of_file(const char *file_name) {
	FILE *fp = fopen(file_name, "r");

	if(fp == NULL) {
		int x = rand()%4;
		switch(x) {
			case 1: throw "file open error";
			case 2: throw rand();
			case 3: throw 2.5;
			default: throw;
		}
	}

	unsigned long n = 0;
	int c = 0;

	while ((c = fgetc(fp)) != EOF)
		if(c == ’\n’)
			n++;

	fclose ( fp );

	return n;
}
