
    MultiplyMatrix(modelView, view, modelWorld);
    //----------------------------------------------------------------------------------------------------------    
    LoadIdentity(shadowLight_textureMatrix);
    MultiplyMatrix(shadowLight_textureMatrix, biasMatrix, light_projection);    
    
    MultiplyMatrix(shadowLight_textureMatrix, shadowLight_textureMatrix, light_view);    //MULTIPLY THESE TO A TEMP MATRIX TO AVOID ROUND OFF ERRORS  
  //MultiplyMatrix(ShadowLight_TextureMatrix, ShadowLight_TextureMatrix, invertView);    //MULTIPLY THESE TO A TEMP MATRIX TO AVOID ROUND OFF ERRORS
   
    //----------------------------------------------------------------------------------------------------------
    LoadIdentity(lightMatrix);
    InvertMatrix(lightMatrix, modelRotation);
    //----------------------------------------------------------------------------------------------------------

 
 glUseProgram(baseRoom_SHADER);
          //------------------------------------------------------------------------------
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
          glEnableVertexAttribArray(0);
          glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
          glEnableVertexAttribArray(1);
          glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
          glEnableVertexAttribArray(2);
          //------------------------------------------------------------------------------------------------
          glUniformMatrix4fv(UNIFORM_MODELVIEW_baseRoom,                        1, 0,    modelView);
          glUniformMatrix4fv(UNIFORM_PROJECTION_baseRoom,                       1, 0,    projection);
          glUniformMatrix4fv(UNIFORM_VIEW_baseRoom,                             1, 0,    view);          
          glUniformMatrix4fv(UNIFORM_MODELWORLD_baseRoom,                       1, 0,    modelWorld);          
          glUniformMatrix4fv(UNIFORM_VIEW_ROTATE_baseRoom,                      1, 0,    view_rotate);  
          glUniformMatrix4fv(UNIFORM_MOVESET_MATRIX_baseRoom,                   1, 0,    moveSetMatrix);            
          //---------------
          glUniformMatrix4fv(UNIFORM_SHADOW_LIGHT_TEXTURE_MATRIX_baseRoom,      1, 0,    shadowLight_textureMatrix);          
          //---------------
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_baseRoom,                     1, 0,    lightMatrix);
          //------------------------------------------------------------------------------------------------
          glUniform4f(UNIFORM_LIGHT_01_POSITION_baseRoom,              baseRoom_LIGHT_01_POSITION[0],
                                                                       baseRoom_LIGHT_01_POSITION[1],
                                                                       baseRoom_LIGHT_01_POSITION[2],
                                                                       baseRoom_LIGHT_01_POSITION[3]);
          
          glUniform4f(UNIFORM_LIGHT_02_POSITION_baseRoom,              baseRoom_LIGHT_02_POSITION[0],
                                                                       baseRoom_LIGHT_02_POSITION[1],
                                                                       baseRoom_LIGHT_02_POSITION[2],
                                                                       baseRoom_LIGHT_02_POSITION[3]);         
    
          glUniform1f(UNIFORM_ambient_LIGHT_01_baseRoom,               ambient_LIGHT_01_baseRoom);
          glUniform1f(UNIFORM_ambient_LIGHT_02_baseRoom,               ambient_LIGHT_02_baseRoom);
       
          glUniform1f(UNIFORM_shininess_LIGHT_01_baseRoom,             shininess_LIGHT_01_baseRoom);     
          glUniform1f(UNIFORM_bias_baseRoom,                           shadow_BIAS);          
          //-------------------------------------------------------------------------------------------------
          glUniform1i(UNIFORM_ShadowTexture_baseRoom,    3);
          glUniform1i(UNIFORM_TEXTURE_cornerSoftDiffuse, 2);
          glUniform1i(UNIFORM_TEXTURE_DOT3_baseRoom,     1);
          glUniform1i(UNIFORM_TEXTURE_baseRoom,          0);
    //====================================================================================================================

//---------------------------------------------------------------
glActiveTexture ( GL_TEXTURE3 );                                                                                                                                          
glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
//---  
glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
glBindTexture(GL_TEXTURE_2D, softDiffuse_FBO_TEXTURE);                                                                                                                          
//---  
