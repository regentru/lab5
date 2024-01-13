#include <cstdlib>
#include "FileException.h"
FileException::FileException(const char * fn, const char * cmt) {
                                                                                                                                                                    
        err_code = err_code;                                                                                                                                        
                                                                                                                                                                    
        filename = strdup( fn ) ;                                                                                                                                   
                                                                                                                                                                    
        comment = strdup( cmt ) ;                                                                                                                                   
                                                                                                                                                                    
}                                                                                                                                                                   
                                                                                                                                                                    
FileException::FileException(const FileException & other) {
                                                                                                                                                                    
        err_code = other.err_code;                                                                                                                                  
                                                                                                                                                                    
        filename = strdup(other.filename);                                                                                                                          
                                                                                                                                                                    
        comment = strdup(other.comment);                                                                                                                            
                                                                                                                                                                    
}                                                                                                                                                                   
                                                                                                                                                                    
FileException::~FileException() {                                                                                                                                   
                                                                                                                                                                    
delete[] filename;
                                                                                                                                                                    
delete[] comment;
                                                                                                                                                                    
}                                                                                                                                                                   

char* FileException::strdup(const char * str) {
                                                                                                                                                                    
        char* res = new char [ strlen(str) + 1];
                                                                                                                                                                    
        strcpy (res, str);                                                                                                                                          
                                                                                                                                                                    
        return res;
                                                                                                                                                                    
}
