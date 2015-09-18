//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    glUseProgram(gaussianBlur_9x_Horizontal_SHADER);         
    //----------------------------------------------------------------------          
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //-------------------------------------------------------------------------------        
    glUniform1f (UNIFORM_blurRadius_gaussianBlur_9x_Horizontal, gaussianBlur_9x_Radius);                                                                                                                           

    glUniform1f (UNIFORM_adjust_gaussianBlur_9x_Horizontal, adjuster);     
    
    glUniform1i (UNIFORM_TEXTURE_gaussianBlur_9x_Horizontal, 0 );      
    //---------------------------------------------------------

        
        
