     if(SHADER_shadow_32bit_Stride != 0)
     {
         glDeleteProgram(SHADER_shadow_32bit_Stride); 
         SHADER_shadow_32bit_Stride = 0;
     }
                    
                    
                    if(m_uiShadowMapTexture != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &m_uiShadowMapTexture);                                                                  
                            m_uiShadowMapTexture = 0;                                                                                    
                    }           
                    if(m_uiFrameBufferObject != 0)                                                                                        
                    {                                                                                                              
                            glDeleteFramebuffers(1, &m_uiFrameBufferObject);                                                                  
                            m_uiFrameBufferObject = 0;                                                                                    
                    }           
        
