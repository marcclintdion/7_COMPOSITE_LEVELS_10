
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

 
 glUseProgram(softDiffuse_SHADER);
          //------------------------------------------------------------------------------
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
          glEnableVertexAttribArray(0);
          glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
          glEnableVertexAttribArray(1);
          glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
          glEnableVertexAttribArray(2);
          //------------------------------------------------------------------------------------------------
          glUniformMatrix4fv(UNIFORM_MODELVIEW_softDiffuse,                        1, 0,    modelView);
          glUniformMatrix4fv(UNIFORM_PROJECTION_softDiffuse,                       1, 0,    projection);
          glUniformMatrix4fv(UNIFORM_VIEW_softDiffuse,                             1, 0,    view);          
          glUniformMatrix4fv(UNIFORM_MODELWORLD_softDiffuse,                       1, 0,    modelWorld);          
          glUniformMatrix4fv(UNIFORM_VIEW_ROTATE_softDiffuse,                      1, 0,    view_rotate);  
          glUniformMatrix4fv(UNIFORM_MOVESET_MATRIX_softDiffuse,                   1, 0,    moveSetMatrix);            
          //---------------
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_softDiffuse,                     1, 0,    lightMatrix);
          //------------------------------------------------------------------------------------------------
          glUniform4f(UNIFORM_LIGHT_POSITION_01_softDiffuse,              softDiffuse_LIGHT_POSITION_01[0],
                                                                          softDiffuse_LIGHT_POSITION_01[1],
                                                                          softDiffuse_LIGHT_POSITION_01[2],
                                                                          softDiffuse_LIGHT_POSITION_01[3]);

          glUniform1f(UNIFORM_ambient_softDiffuse,                        ambient_softDiffuse);
          //-------------------------------------------------------------------------------------------------

          glUniform1i(UNIFORM_TEXTURE_softDiffuse,        0);
    //====================================================================================================================

//---------------------------------------------------------------
glActiveTexture ( GL_TEXTURE3 );                                                                                                                                          
glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
//---  
