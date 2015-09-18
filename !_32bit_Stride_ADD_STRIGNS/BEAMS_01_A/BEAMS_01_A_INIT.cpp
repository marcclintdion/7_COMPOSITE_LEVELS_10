//========================================================================                            
#ifdef __APPLE__                                                                                      
 //--------------                                                                                     
    spriteImage             = [UIImage imageNamed:@"BEAMS_01_A_DOT3.png"].CGImage;      
    width                   =  CGImageGetWidth(spriteImage);                                          
    height                  =  CGImageGetHeight(spriteImage);                                         
    spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));                    
    spriteContext           =  CGBitmapContextCreate(spriteData, width,                               
                                                                 height,                              
                                                                 8,                                   
                                                                 width * 4,                           
                                                                 CGImageGetColorSpace(spriteImage),   
                                                                 kCGImageAlphaNoneSkipLast);          
    CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);                                           
    CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS                           
    CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS                           
    CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);                 
    CGContextRelease(spriteContext);                                                                  
    //---------                                                                                       
        glGenTextures(1, &BEAMS_01_A_NORMALMAP);                                          
        glBindTexture(GL_TEXTURE_2D, BEAMS_01_A_NORMALMAP);                               
        ConfigureAndLoadTexture(spriteData,  width, height);                                          
        if(spriteData != NULL)                                                                        
        {                                                                                             
             free(spriteData);                                                                        
        }                                                                                             
    //-------------------------------------------------------------------------------------           
    spriteImage             = [UIImage imageNamed:@"BEAMS_01_A.png"].CGImage;           
    width                   =  CGImageGetWidth(spriteImage);                                          
    height                  =  CGImageGetHeight(spriteImage);                                         
    spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));                    
    spriteContext           =  CGBitmapContextCreate(spriteData,                                      
                                                     width,                                           
                                                     height,                                          
                                                     8,                                               
                                                     width * 4,                                       
                                                     CGImageGetColorSpace(spriteImage),               
                                                     kCGImageAlphaNoneSkipLast);                      
    CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);                                           
    CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS                           
    CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS                           
    CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);                 
    CGContextRelease(spriteContext);                                                                  
    //---------                                                                                       
        glGenTextures(1, &BEAMS_01_A_TEXTUREMAP);                                         
        glBindTexture(GL_TEXTURE_2D, BEAMS_01_A_TEXTUREMAP);                              
        ConfigureAndLoadTexture(spriteData,  width, height);                                          
        if(spriteData != NULL)                                                                        
        {                                                                                             
            free(spriteData);                                                                         
        }                                                                                             
//----                                                                                                
#endif                                                                                                
//========================================================================                            
    //-----------------------------------------------------------------------------------                                              
    #ifdef WIN32                                                                                                                       
    loadTexture("_MODEL_FOLDERS_/BEAMS_01_A/BEAMS_01_A_DOT3.png",     BEAMS_01_A_NORMALMAP);     
    loadTexture("_MODEL_FOLDERS_/BEAMS_01_A/BEAMS_01_A.png",          BEAMS_01_A_TEXTUREMAP);    
    #endif                                                                                                                             
    //-----------------------------------------------------------------------------------                                              
    #include    "BEAMS_01_A.cpp"                                                                                         
    glGenBuffers(1,              &BEAMS_01_A_VBO);                                                                         
    glBindBuffer(GL_ARRAY_BUFFER, BEAMS_01_A_VBO);                                                                         
    glBufferData(GL_ARRAY_BUFFER, sizeof(BEAMS_01_A), BEAMS_01_A, GL_STATIC_DRAW);                             
    glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                  
    //-----------------------------------------------------------------------------------                                              
    #include    "BEAMS_01_A_INDICES.cpp"                                                                                 
    glGenBuffers(1,              &BEAMS_01_A_INDICES_VBO);                                                                 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BEAMS_01_A_INDICES_VBO);                                                         
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(BEAMS_01_A_INDICES), BEAMS_01_A_INDICES, GL_STATIC_DRAW);     
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);                                                                                          
    //-----------------------------------------------------------------------------------                                              
    //=====================================================   
    BEAMS_01_A_boundingBox[0] = -3.2934;
    BEAMS_01_A_boundingBox[1] = 3.28384;
    BEAMS_01_A_boundingBox[2] = -1.67624;
    BEAMS_01_A_boundingBox[3] = 1.7002;
    BEAMS_01_A_boundingBox[4] = -3.28513;
    BEAMS_01_A_boundingBox[5] = 2.86771;
    //=====================================================   
    collisionBoxArray[boxCount][0] = -3.2934;
    collisionBoxArray[boxCount][1] = 3.28384;
    collisionBoxArray[boxCount][2] = -1.67624;
    collisionBoxArray[boxCount][3] = 1.7002;
    collisionBoxArray[boxCount][4] = -3.28513;
    collisionBoxArray[boxCount][5] = 2.86771;
    collisionBoxArray[boxCount][6] = boxCount;
//    boxCount++;
