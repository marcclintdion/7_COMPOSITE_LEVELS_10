//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    
    //====================================================== 
    if(softDiffuse_FBO != 0)                                                                                                      
    {                                                                                                                                              
        glDeleteFramebuffers(1, &softDiffuse_FBO);
        softDiffuse_FBO = 0;                                                                                                  
    }                    
    //--------------------------------------------
    if(softDiffuse_FBO_TEXTURE  != 0)                                                                                      
    {                                                                                                              
        glDeleteTextures(1, &softDiffuse_FBO_TEXTURE);                                                                 
        softDiffuse_FBO_TEXTURE  = 0;                                                                                  
    }                                                                                                              
    //======================================================
