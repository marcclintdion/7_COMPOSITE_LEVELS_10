//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    glUseProgram(finalComposite_SHADER);                                                                                                                                              

    //======================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //-------------------------------------------------       
    glUniform1i (UNIFORM_TEXTURE_2_finalComposite, 2 );                                                                                                                          
    glUniform1i (UNIFORM_TEXTURE_1_finalComposite, 1 );                                                                                                                          
    glUniform1i (UNIFORM_TEXTURE_0_finalComposite, 0 );                                                                                                                                 
    //-------------------------------------------------
    glUniform1f (UNIFORM_DEPTH_LUMIN_finalComposite, rawDepthLuminance );     
    //======================================================================                                                                
         
