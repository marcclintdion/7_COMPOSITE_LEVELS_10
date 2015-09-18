    if(BEAMS_01_B_NORMALMAP != 0)                      
    {                                                              
        glDeleteTextures(1, &BEAMS_01_B_NORMALMAP);    
        BEAMS_01_B_NORMALMAP = 0;                      
    }                                                              
    if(BEAMS_01_B_TEXTUREMAP  != 0)                    
    {                                                              
        glDeleteTextures(1, &BEAMS_01_B_TEXTUREMAP);   
        BEAMS_01_B_TEXTUREMAP  = 0;                    
    }                                                              
    //===========================================================  

    if(BEAMS_01_B_VBO  != 0)                           
    {                                                              
        glDeleteBuffers(1, &BEAMS_01_B_VBO);           
        BEAMS_01_B_VBO  = 0;                           
    }                                                              
    if(BEAMS_01_B_INDICES_VBO  != 0)                   
    {                                                              
        glDeleteBuffers(1, &BEAMS_01_B_INDICES_VBO);   
        BEAMS_01_B_INDICES_VBO  = 0;                   
    }                                                              
