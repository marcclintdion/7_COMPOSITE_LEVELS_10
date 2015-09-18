    if(BEAMS_01_A_NORMALMAP != 0)                      
    {                                                              
        glDeleteTextures(1, &BEAMS_01_A_NORMALMAP);    
        BEAMS_01_A_NORMALMAP = 0;                      
    }                                                              
    if(BEAMS_01_A_TEXTUREMAP  != 0)                    
    {                                                              
        glDeleteTextures(1, &BEAMS_01_A_TEXTUREMAP);   
        BEAMS_01_A_TEXTUREMAP  = 0;                    
    }                                                              
    //===========================================================  

    if(BEAMS_01_A_VBO  != 0)                           
    {                                                              
        glDeleteBuffers(1, &BEAMS_01_A_VBO);           
        BEAMS_01_A_VBO  = 0;                           
    }                                                              
    if(BEAMS_01_A_INDICES_VBO  != 0)                   
    {                                                              
        glDeleteBuffers(1, &BEAMS_01_A_INDICES_VBO);   
        BEAMS_01_A_INDICES_VBO  = 0;                   
    }                                                              
