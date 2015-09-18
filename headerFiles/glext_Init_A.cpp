

     //PFNGLGETINTEGERI_VPROC              glGetIntegeri_v              = NULL;  
     
     
     
     PFNGLUNIFORM3FVPROC              glUniform3fv              = NULL;  
     PFNGLUNIFORMMATRIX3FVPROC        glUniformMatrix3fv        = NULL; 
     PFNGLPATCHPARAMETERIPROC         glPatchParameteri         = NULL; 
     PFNGLGENVERTEXARRAYSPROC         glGenVertexArrays         = NULL; 
     PFNGLBINDVERTEXARRAYPROC         glBindVertexArray         = NULL; 


     PFNGLCREATEPROGRAMPROC           glCreateProgram           = NULL;   
     PFNGLDELETEPROGRAMPROC           glDeleteProgram           = NULL;
     PFNGLDETACHSHADERPROC            glDetachShader            = NULL;
     PFNGLDELETESHADERPROC            glDeleteShader            = NULL;     
     PFNGLUSEPROGRAMPROC              glUseProgram              = NULL;
     PFNGLCREATESHADERPROC            glCreateShader            = NULL;
     PFNGLSHADERSOURCEPROC            glShaderSource            = NULL;
     PFNGLBINDATTRIBLOCATIONPROC      glBindAttribLocation      = NULL;     
     PFNGLCOMPILESHADERPROC           glCompileShader           = NULL;
     PFNGLATTACHOBJECTARBPROC         glAttachObjectARB         = NULL;
     PFNGLATTACHSHADERPROC            glAttachShader            = NULL;     
     PFNGLGETINFOLOGARBPROC           glGetInfoLogARB           = NULL;
     PFNGLLINKPROGRAMPROC             glLinkProgram             = NULL;
     PFNGLGETUNIFORMLOCATIONPROC      glGetUniformLocation      = NULL;
     PFNGLGETATTRIBLOCATIONPROC       glGetAttribLocation       = NULL;
     PFNGLUNIFORM1IPROC			      glUniform1i		        = NULL;     
     //---------------- 
     PFNGLUNIFORM1FPROC			      glUniform1f			    = NULL;
     PFNGLUNIFORM2FPROC			      glUniform2f			    = NULL;     
     PFNGLUNIFORM3FPROC			      glUniform3f			    = NULL;        
     PFNGLUNIFORM4FPROC			      glUniform4f			    = NULL;
     //---------------- 
     PFNGLUNIFORM4FVPROC              glUniform4fv              = NULL;
     PFNGLACTIVETEXTUREPROC		      glActiveTexture		    = NULL;    
     PFNGLUNIFORMMATRIX4FVPROC		  glUniformMatrix4fv	    = NULL;     

//void deleteVBO(const GLuint vboId);

             
               PFNGLGENBUFFERSPROC            glGenBuffers            = 0;
               PFNGLBINDBUFFERPROC            glBindBuffer            = 0;                 
               PFNGLBUFFERDATAPROC            glBufferData            = 0;               
               PFNGLBUFFERSUBDATAPROC         glBufferSubData         = 0;         
               PFNGLDELETEBUFFERSPROC         glDeleteBuffers         = 0;               
               
          
PFNGLGENRENDERBUFFERSPROC            glGenRenderbuffers            = 0;                 
PFNGLBINDRENDERBUFFERPROC            glBindRenderbuffer            = 0;                 
PFNGLRENDERBUFFERSTORAGEPROC         glRenderbufferStorage         = 0;                 
PFNGLDELETERENDERBUFFERSPROC         glDeleteRenderbuffers         = 0;                 
       
       
               
               
               //PFNGLGENVERTEXARRAYSPROC        glGenVertexArrays          = 0;
               //PFNGLBINDVERTEXARRAYPROC        glBindVertexArray          = 0;                 
               PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer      = 0;         
               PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray  = 0;  


                         PFNGLGENFRAMEBUFFERSEXTPROC                         pglGenFramebuffersEXT = 0;                      
                         PFNGLDELETEFRAMEBUFFERSEXTPROC                      pglDeleteFramebuffersEXT = 0;                   
                         PFNGLBINDFRAMEBUFFEREXTPROC                         pglBindFramebufferEXT = 0;                     
                         PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC                  pglCheckFramebufferStatusEXT = 0;              
                         PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC     pglGetFramebufferAttachmentParameterivEXT = 0;  
                         PFNGLGENERATEMIPMAPEXTPROC                          glGenerateMipmapEXT = 0;                       
                         PFNGLFRAMEBUFFERTEXTURE2DEXTPROC                    pglFramebufferTexture2DEXT = 0;             
                         PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC                 pglFramebufferRenderbufferEXT = 0;            

                         PFNGLFRAMEBUFFERRENDERBUFFERPROC                    glFramebufferRenderbuffer = 0;   

                         PFNGLGENRENDERBUFFERSEXTPROC                        pglGenRenderbuffersEXT = 0;                  
                         PFNGLDELETERENDERBUFFERSEXTPROC                     pglDeleteRenderbuffersEXT = 0;                 
                         PFNGLBINDRENDERBUFFEREXTPROC                        pglBindRenderbufferEXT = 0;                     
                         PFNGLRENDERBUFFERSTORAGEEXTPROC                     pglRenderbufferStorageEXT = 0;                  
                         PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC              pglGetRenderbufferParameterivEXT = 0;         
                         PFNGLISRENDERBUFFEREXTPROC                          pglIsRenderbufferEXT = 0;                      

                         #define glGenFramebuffersEXT                        pglGenFramebuffersEXT
                         #define glDeleteFramebuffersEXT                     pglDeleteFramebuffersEXT
                         #define glBindFramebufferEXT                        pglBindFramebufferEXT
                         #define glCheckFramebufferStatusEXT                 pglCheckFramebufferStatusEXT
                         #define glGetFramebufferAttachmentParameterivEXT    pglGetFramebufferAttachmentParameterivEXT
                         #define glGenerateMipmapEXT                         glGenerateMipmapEXT
                         #define glFramebufferTexture2DEXT                   pglFramebufferTexture2DEXT
                         #define glFramebufferRenderbufferEXT                pglFramebufferRenderbufferEXT

                         #define glGenRenderbuffersEXT                       pglGenRenderbuffersEXT
                         #define glDeleteRenderbuffersEXT                    pglDeleteRenderbuffersEXT
                         #define glBindRenderbufferEXT                       pglBindRenderbufferEXT
                         #define glRenderbufferStorageEXT                    pglRenderbufferStorageEXT
                         #define glGetRenderbufferParameterivEXT             pglGetRenderbufferParameterivEXT
                         #define glIsRenderbufferEXT                         pglIsRenderbufferEXT
