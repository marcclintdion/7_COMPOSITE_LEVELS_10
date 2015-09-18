//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    //-----------------------------------------------------------------    
    if(drawMainColor_PRIMARY_FBO != 0)                                                                                                      
    {                                                                                                                                              
        glDeleteFramebuffers(1, &drawMainColor_PRIMARY_FBO);
        drawMainColor_PRIMARY_FBO = 0;                                                                                                  
    }                    
    //-----------------------------------------------------------------
    if(drawMainColor_PRIMARY_FBO_COLOR_TEXTURE  != 0)                                                                                                    
    {                                                                                                                                              
        glDeleteTextures(1, &drawMainColor_PRIMARY_FBO_COLOR_TEXTURE);                                                                               
        drawMainColor_PRIMARY_FBO_COLOR_TEXTURE  = 0;                                                                                                
    } 
    //-----------------------------------------------------------------
    if(drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE != 0)                                                                                                      
    {                                                                                                                                              
        glDeleteTextures(1, &drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE);                                                                                
        drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE = 0;                                                                                                  
    }                                                                                                                                              
    //-----------------------------------------------------------------    
