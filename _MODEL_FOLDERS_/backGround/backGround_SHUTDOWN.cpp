    if(backGround_NORMALMAP != 0)                      
    {                                                              
        glDeleteTextures(1, &backGround_NORMALMAP);    
        backGround_NORMALMAP = 0;                      
    }                                                              
    if(backGround_TEXTUREMAP  != 0)                    
    {                                                              
        glDeleteTextures(1, &backGround_TEXTUREMAP);   
        backGround_TEXTUREMAP  = 0;                    
    }                                                              
    //===========================================================  

    if(backGround_VBO  != 0)                           
    {                                                              
        glDeleteBuffers(1, &backGround_VBO);           
        backGround_VBO  = 0;                           
    }                                                              
    if(backGround_INDICES_VBO  != 0)                   
    {                                                              
        glDeleteBuffers(1, &backGround_INDICES_VBO);   
        backGround_INDICES_VBO  = 0;                   
    }                                                              
