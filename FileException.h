#include <cerrno>
#include <cstring>
class FileException {
                                                                                                                                                                    
        int err_code ;
                                                                                                                                                                    
        char * filename ;
                                                                                                                                                                    
        char * comment ;
                                                                                                                                                                    
        public :
                                                                                                                                                                    
                FileException ( const char * fn , const char * cmt ) ;
                                                                                                                                                                    
                FileException ( const FileException & other ) ;
                                                                                                                                                                    
                ~ FileException () ;                                                                                                                                
                                                                                                                                                                    
                const char * GetName () const { return filename ; }
                                                                                                                                                                    
                const char * GetComment () const { return comment ; }
                                                                                                                                                                    
                int GetErrno () const { return err_code ; }
                                                                                                                                                                    
        private :
                                                                                                                                                                    
                static char * strdup ( const char * str );
                                                                                                                                                                    
};
