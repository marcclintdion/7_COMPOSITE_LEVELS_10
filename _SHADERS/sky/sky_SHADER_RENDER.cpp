
    MultiplyMatrix(modelView, view, modelWorld);
    //----------------------------------------------------------------------------------------------------------    

    //----------------------------------------------------------------------------------------------------------
    LoadIdentity(lightMatrix);
    InvertMatrix(lightMatrix, modelRotation);
    //----------------------------------------------------------------------------------------------------------

 
 glUseProgram(sky_SHADER);
          //------------------------------------------------------------------------------
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
          glEnableVertexAttribArray(0);
          glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
          glEnableVertexAttribArray(1);
          glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
          glEnableVertexAttribArray(2);
          //------------------------------------------------------------------------------------------------
          glUniformMatrix4fv(UNIFORM_MODELVIEW_sky,                        1, 0,    modelView);
          glUniformMatrix4fv(UNIFORM_PROJECTION_sky,                       1, 0,    projection);
          glUniformMatrix4fv(UNIFORM_VIEW_sky,                             1, 0,    view);          
          glUniformMatrix4fv(UNIFORM_MODELWORLD_sky,                       1, 0,    modelWorld);          
          glUniformMatrix4fv(UNIFORM_VIEW_ROTATE_sky,                      1, 0,    view_rotate);  
          glUniformMatrix4fv(UNIFORM_MOVESET_MATRIX_sky,                   1, 0,    moveSetMatrix);            
        //------------------------------------------------------------------------------------------------

          glUniform1i(UNIFORM_TEXTURE_sky,        0);
    //====================================================================================================================

