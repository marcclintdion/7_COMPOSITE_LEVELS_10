//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    glUseProgram(transformedHardEdgeShadow_SHADER);                                                                                                                                              
    //======================================================================                                                                 
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //=========================================================================================  
    glUniform1f(UNIFORM_ADJUST_DARKNESS_transformedHardEdgeShadow,  adjustDarknessOfShadowMix_transformedHardEdgeShadow); 
    //------------------------------------------------------------    
    glUniform1i(UNIFORM_TEXTURE_0_transformedHardEdgeShadow, 0 );                                                                                                                                 
    //============================================================                                                                

