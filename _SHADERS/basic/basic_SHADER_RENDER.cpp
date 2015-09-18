
    MultiplyMatrix(modelView, view, modelWorld);
    //----------------------------------------------------------------------------------------------------------    
    LoadIdentity(shadowLight_textureMatrix);
    MultiplyMatrix(shadowLight_textureMatrix, biasMatrix, light_projection);    
    MultiplyMatrix(shadowLight_textureMatrix, shadowLight_textureMatrix, light_view);    //MULTIPLY THESE TO A TEMP MATRIX TO AVOID ROUND OFF ERRORS  
   
    //----------------------------------------------------------------------------------------------------------
    LoadIdentity(lightMatrix);
    InvertMatrix(lightMatrix, modelRotation);
    //----------------------------------------------------------------------------------------------------------

 
 glUseProgram(basic_SHADER);
          //------------------------------------------------------------------------------
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
          glEnableVertexAttribArray(0);
          glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
          glEnableVertexAttribArray(1);
          glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
          glEnableVertexAttribArray(2);
          //------------------------------------------------------------------------------------------------
          glUniformMatrix4fv(UNIFORM_MODELVIEW_basic,                        1, 0,    modelView);
          glUniformMatrix4fv(UNIFORM_PROJECTION_basic,                       1, 0,    projection);
          glUniformMatrix4fv(UNIFORM_VIEW_basic,                             1, 0,    view);          
          glUniformMatrix4fv(UNIFORM_MODELWORLD_basic,                       1, 0,    modelWorld);          
          glUniformMatrix4fv(UNIFORM_VIEW_ROTATE_basic,                      1, 0,    view_rotate);  
          glUniformMatrix4fv(UNIFORM_MOVESET_MATRIX_basic,                   1, 0,    moveSetMatrix);            
          //---------------
          glUniformMatrix4fv(UNIFORM_SHADOW_LIGHT_TEXTURE_MATRIX_basic,      1, 0,    shadowLight_textureMatrix);          
          //---------------
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_basic,                     1, 0,    lightMatrix);
          //------------------------------------------------------------------------------------------------
          glUniform4f(UNIFORM_LIGHT_POSITION_01_basic,              basic_LIGHT_POSITION_01[0],
                                                                       basic_LIGHT_POSITION_01[1],
                                                                       basic_LIGHT_POSITION_01[2],
                                                                       basic_LIGHT_POSITION_01[3]);

          glUniform1f(UNIFORM_shininess_basic,                      shininess_basic);
          glUniform1f(UNIFORM_ambient_LIGHT_01_basic,               ambient_LIGHT_01_basic);

          //-------------------------------------------------------------------------------------------------
          glUniform1i(UNIFORM_ShadowTexture_basic,  3);


          glUniform1i(UNIFORM_TEXTURE_DOT3_basic,   1);
          glUniform1i(UNIFORM_TEXTURE_basic,        0);
    //====================================================================================================================

//---------------------------------------------------------------
glActiveTexture ( GL_TEXTURE3 );                                                                                                                                          
glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          

