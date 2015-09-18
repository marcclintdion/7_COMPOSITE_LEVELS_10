//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    //-----------------------------------------------------------------    
    if(drawMainColor_FBO != 0)
    {                                                                                                                                              
        glDeleteFramebuffers(1, &drawMainColor_FBO);
        drawMainColor_FBO = 0;
    }                    
    //-----------------------------------------------------------------
    if(drawMainColor_FBO_COLOR_TEXTURE  != 0)
    {                                                                                                                                              
        glDeleteTextures(1, &drawMainColor_FBO_COLOR_TEXTURE);
        drawMainColor_FBO_COLOR_TEXTURE  = 0;
    } 
    //-----------------------------------------------------------------
    if(drawMainColor_FBO_DEPTH_TEXTURE != 0)
    {                                                                                                                                              
        glDeleteTextures(1, &drawMainColor_FBO_DEPTH_TEXTURE);
        drawMainColor_FBO_DEPTH_TEXTURE = 0;
    }                                                                                                                                              
    //-----------------------------------------------------------------    
