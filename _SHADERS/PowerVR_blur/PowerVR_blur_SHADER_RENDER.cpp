
glUseProgram(PowerVR_blur_SHADER);
    //------------------------------------------------------------------------------
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);        
    //------------------------------------------------------------------------------------------------

    glUniform1f(UNIFORM_TexelOffsetX_PowerVR_blur,       horizontalBlur_X);
    glUniform1f(UNIFORM_TexelOffsetY_PowerVR_blur,       horizontalBlur_Y);

    glUniform2f(UNIFORM_adjustShadowPos_PowerVR_blur,    adjustShadowPos[0], adjustShadowPos[1]);

    glUniform1i (UNIFORM_TEXTURE_PowerVR_blur, 0 );
    //====================================================================================================================
    
    
    
    

