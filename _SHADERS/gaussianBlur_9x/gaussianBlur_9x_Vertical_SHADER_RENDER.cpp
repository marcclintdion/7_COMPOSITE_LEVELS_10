//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  
    glUseProgram(gaussianBlur_9x_Vertical_SHADER);          
    //----------------------------------------------------------------------
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //----------------------------------------------------------------------------       
    glUniform1f (UNIFORM_blurRadius_gaussianBlur_9x_Vertical, gaussianBlur_9x_Radius);                                                                                                                           
    glUniform1f (UNIFORM_screenRatio_gaussianBlur_9x_Vertical, screenRatio); 
    glUniform1f (UNIFORM_adjust_gaussianBlur_9x_Vertical, adjuster);  
     
    glUniform1i (UNIFORM_TEXTURE_gaussianBlur_9x_Vertical, 0 );                                                                                                                                 
    //-------------------------------------------------------           
               
  
