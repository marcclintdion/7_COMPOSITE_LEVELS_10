//================================================__BLUR_SHADOW_01__===========================================  
//========================================================================__BLUR_SHADOW_01__===================  
    glBindFramebuffer(GL_FRAMEBUFFER, generic_01_FBO); //generic_01_TEXTURE
        //----------------------------------------------------------------
        shaderNumber = 6;//
        //---------------
        horizontalBlur_X = m_fTexelOffset/screenRatio  * adjustBlurOffset;
        horizontalBlur_Y = 0.0;
        //---------------
        glActiveTexture (GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_COLOR_TEXTURE);         
        #include "../../_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"

        //-------------------------------
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

     //=====================================================================
    glBindFramebuffer(GL_FRAMEBUFFER, generic_02_FBO); //generic_02_TEXTURE
        //----------------------------------------------------------------
        shaderNumber = 6;
        //---------------
        horizontalBlur_X = 0.0;
        horizontalBlur_Y = m_fTexelOffset  * adjustBlurOffset;
        //---------------     
        glActiveTexture (GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, generic_01_TEXTURE);
        #include "../../_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"
        //-------------------------------
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//========================================================================__BLUR_SHADOW_01__===================  
//================================================__BLUR_SHADOW_01__===========================================  


//__SECOND_PASS

/*
//================================================__BLUR_SHADOW_01__===========================================  
//========================================================================__BLUR_SHADOW_01__===================  
    glBindFramebuffer(GL_FRAMEBUFFER, generic_01_FBO); //generic_01_TEXTURE
        //----------------------------------------------------------------
        shaderNumber = 6;//
        //---------------
        horizontalBlur_X = m_fTexelOffset/screenRatio  * adjustBlurOffset;
        horizontalBlur_Y = 0.0;
        //---------------
        glActiveTexture (GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, generic_02_TEXTURE);         
        #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"
        //-------------------------------
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //=====================================================================                               
    glBindFramebuffer(GL_FRAMEBUFFER, generic_02_FBO); //generic_02_TEXTURE
        //----------------------------------------------------------------
        shaderNumber = 6;
        //---------------
        horizontalBlur_X = 0.0;
        horizontalBlur_Y = m_fTexelOffset  * adjustBlurOffset;
        //---------------     
        glActiveTexture (GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, generic_01_TEXTURE);
        #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"
        //-------------------------------
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//========================================================================__BLUR_SHADOW_01__===================  
//================================================__BLUR_SHADOW_01__===========================================  
*/
