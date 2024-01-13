#include <stdio.h>
                                                                                                                                                                                                             
#include <string>
#include <ctime>
                                                                                                                                                                                                             
#include "FileException.h"
                                                                                                                                                                                                             
                                                                                                                                                                                                             
unsigned long lines_of_file(const char* file_name);
                                                                                                                                                                                                             
                                                                                                                                                                                                             
int main(int argc, char** argv) {
                                                                                                                                                                                                             
        if (argc < 2) {
                                                                                                                                                                                                             
                fprintf(stderr, "No file name!\n");
                                                                                                                                                                                                             
                return 1;
                                                                                                                                                                                                             
        }                                                                                                                                                                                                    
                                                                                                                                                                                                             
                                                                                                                                                                                                             
        srand(time(NULL));
                                                                                                                                                                                                             
                                                                                                                                                                                                             
        try {
                                                                                                                                                                                                             
                for (int i = 1; i < argc; i++) {
                                                                                                                                                                                                             
                        unsigned long res = lines_of_file(argv[i]);
                                                                                                                                                                                                             
                        printf("The file %s contains %ld lines\n", argv[i], res); 
                                                                                                                                                                                                             
                }                                                                                                                                                                                            
                                                                                                                                                                                                             
        }                                                                                                                                                                                                    
                                                                                                                                                                                                             
        catch (FileException& e) {
                                                                                                                                                                                                             
                fprintf(stderr, "FileException! %s\n%s\n", e.GetName(), e.GetComment());
                                                                                                                                                                                                             
                return 1;
                                                                                                                                                                                                             
        }                                                                                                                                                                                                    
                                                                                                                                                                                                             
        catch (...) {
				fprintf(stderr, "Something strange happened\n");
                                                                                                                                                                                                             
                return 1;
                                                                                                                                                                                                             
        }                                                                                                                                                                                                    
                                                                                                                                                                                                             
                                                                                                                                                                                                             
        return 0;
                                                                                                                                                                                                             
}                                                                                                                                                                                                            
                                                                                                                                                                                                             
                                                                                                                                                                                                             
unsigned long lines_of_file(const char* file_name) {
                                                                                                                                                                                                             
        FILE* fp = fopen(file_name, "r");
                                                                                                                                                                                                             
                                                                                                                                                                                                             
        if (fp == NULL) {  
                                                                                                                                                                                                             
                throw FileException(file_name, "Could not open file");
                                                                                                                                                                                                             
        }                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                                                                                                         
                                                                                                                                                                                                             
                                                                                                                                                                                                             
        fclose(fp);                                                                                                                                                                                          
                                                                                                                                                                                                             
                                                                                                                                                                                                             
        return 10001; 
                                                                                                                                                                                                             
}
