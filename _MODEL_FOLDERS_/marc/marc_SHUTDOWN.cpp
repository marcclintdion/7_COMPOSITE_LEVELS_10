    if(marc_NORMALMAP != 0)                                                                                                      
    {                                                                                                                                              
        glDeleteTextures(1, &marc_NORMALMAP);                                                                                
        marc_NORMALMAP = 0;                                                                                                  
    }                                                                                                                                              
    if(marc_TEXTUREMAP  != 0)                                                                                                    
    {                                                                                                                                              
        glDeleteTextures(1, &marc_TEXTUREMAP);                                                                               
        marc_TEXTUREMAP  = 0;                                                                                                
    }                                                                                                                                              
    //--------------------------------------------------
    if(marc_VBO  != 0)                                                                                                           
    {                                                                                                                                              
        glDeleteBuffers(1, &marc_VBO);                                                                                       
        marc_VBO  = 0;                                                                                                       
    }                                                                                                                                              
    if(marc_INDICES_VBO  != 0)                                                                                                   
    {                                                                                                                                              
        glDeleteBuffers(1, &marc_INDICES_VBO);                                                                               
        marc_INDICES_VBO  = 0;                                                                                               
    }                                                                                                                                              
