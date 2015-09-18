//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    
    //-----------------------------------------------------------------    
    if(hardEdgeShadow_FBO != 0)                                                                                                      
    {                                                                                                                                              
        glDeleteFramebuffers(1, &hardEdgeShadow_FBO);
        hardEdgeShadow_FBO = 0;                                                                                                  
    }                    
    //-----------------------------------------------------------------
    if(hardEdgeShadow_TEXTURE  != 0)                                                                                      
    {                                                                                                              
        glDeleteTextures(1, &hardEdgeShadow_TEXTURE);                                                                 
        hardEdgeShadow_TEXTURE  = 0;                                                                                  
    }                                                                                                              
    //-----------------------------------------------------------------




