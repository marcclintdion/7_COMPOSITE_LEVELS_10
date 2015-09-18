//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    
    //==========================================================================
    glClearColor( 0.0f, 1.0f, 0.0f, 0.5f );
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //--------------------------------------------------------------------------

    glViewport(0, 0, (GLsizei)viewWidth/scaleFrameBufferPlaneViewPort, (GLsizei)viewHeight/scaleFrameBufferPlaneViewPort);
    //====================================================================



    //==================================================
    glBindBuffer(GL_ARRAY_BUFFER, frameBufferPlane_VBO);
    //==================================================
    
    //==============================                                                    
    SelectShader(shaderNumber);                                                                                                                              
    //============================== 
    
    glDrawArrays(GL_TRIANGLES, 0, 6);
