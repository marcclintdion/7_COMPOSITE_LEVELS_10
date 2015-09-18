    char *ext = (char*)glGetString( GL_EXTENSIONS );

    if( strstr( ext, "GL_ARB_shading_language_100" ) == NULL )
    {
        // This extension string indicates that the OpenGL Shading Language,
        // version 1.00, is supported.
        MessageBox(NULL,"GL_ARB_shading_language_100 extension was not found",
            "ERROR",MB_OK|MB_ICONEXCLAMATION);
       
    }
              
       //glGetIntegeri_v                               = (PFNGLGETINTEGERI_VPROC)wglGetProcAddress("glGetIntegeri_v");              
      
      
       glUniform3fv                               = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");              
       glUniformMatrix3fv                               = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");            
       glPatchParameteri                               = (PFNGLPATCHPARAMETERIPROC)wglGetProcAddress("glPatchParameteri");           
       glGenVertexArrays                               = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");                          
       glBindVertexArray                               = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");                       
                  
                             
       glCreateProgram                               = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");       
       glDeleteProgram                               = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
       glDetachShader                                = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader"); 
       glDeleteShader                                = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");     
          
       glUseProgram                                  = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
       glCreateShader                                = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");       
       glShaderSource                                = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
       glBindAttribLocation                          = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
       glCompileShader                               = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
       glAttachShader                                = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");      
       glLinkProgram                                 = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
       glGetUniformLocation                          = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
       glGetAttribLocation                           = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
       glUniform1i			                         = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");      
       //-----------
       glUniform1f			                         = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
       glUniform2f			                         = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");      
       glUniform3f			                         = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");      
       glUniform4f			                         = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
       //-----------       
       glActiveTexture                            = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");       
       glUniform4fv                                  = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
       glUniformMatrix4fv	                         = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
       
       glGenBuffers                               = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
       glBindBuffer                               = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
       glBufferData                               = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
       glBufferSubData                            = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
       glDeleteBuffers                            = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
              
                                       
       
       glGenRenderbuffers                            = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");              
       glBindRenderbuffer                            = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");                
       glRenderbufferStorage                         = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");                
       glDeleteRenderbuffers                         = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");                 
        
        
        
        
              
              
       //glGenVertexArrays                           = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
       //glBindVertexArray                           =  (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
       glVertexAttribPointer                         = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
       glEnableVertexAttribArray                     = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");

       glGenFramebuffersEXT                          = (PFNGLGENFRAMEBUFFERSEXTPROC)wglGetProcAddress("glGenFramebuffersEXT");
       glDeleteFramebuffersEXT                       = (PFNGLDELETEFRAMEBUFFERSEXTPROC)wglGetProcAddress("glDeleteFramebuffersEXT");
       glBindFramebufferEXT                          = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
       glCheckFramebufferStatusEXT                   = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckFramebufferStatusEXT");
       glGetFramebufferAttachmentParameterivEXT      = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferAttachmentParameterivEXT");
       glGenerateMipmapEXT                           = (PFNGLGENERATEMIPMAPEXTPROC)wglGetProcAddress("glGenerateMipmapEXT");
       glFramebufferTexture2DEXT                     = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glFramebufferTexture2DEXT");
       glFramebufferRenderbufferEXT                  = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glFramebufferRenderbufferEXT");
       
       glFramebufferRenderbuffer                 = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
        
       glGenRenderbuffersEXT                         = (PFNGLGENRENDERBUFFERSEXTPROC)wglGetProcAddress("glGenRenderbuffersEXT");
       glDeleteRenderbuffersEXT                      = (PFNGLDELETERENDERBUFFERSEXTPROC)wglGetProcAddress("glDeleteRenderbuffersEXT");
       glBindRenderbufferEXT                         = (PFNGLBINDRENDERBUFFEREXTPROC)wglGetProcAddress("glBindRenderbufferEXT");
       glRenderbufferStorageEXT                      = (PFNGLRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glRenderbufferStorageEXT");    

