       glUseProgram(SHADER_shadow_32bit_Stride);    
       //-----------------------------------------------------------------------------
       
       
        //MultiplyMatrix(light_ModelView, light_View, modelWorld);                                                                                                                         
       //-------------------------------------------------------------------------------------------
                           glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
                           glEnableVertexAttribArray(0);	
                           glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
                           glEnableVertexAttribArray(1);  
                           glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
                           glEnableVertexAttribArray(2);                                                       
                           //-----------------------------------------------------------------------
                           glUniformMatrix4fv(UNIFORM_LIGHT_MODELWORLD_shadow_32bit_Stride,  1, 0,  modelWorld);                           
                           glUniformMatrix4fv(UNIFORM_LIGHT_VIEW_shadow_32bit_Stride,        1, 0,  light_view);                             
                           glUniformMatrix4fv(UNIFORM_LIGHT_PROJECTION_shadow_32bit_Stride,  1, 0,  light_projection);
                           glUniformMatrix4fv(UNIFORM_MOVESET_MATRIX_shadow_32bit_Stride,    1, 0,    moveSetMatrix);  
