//========================================================================                            
#ifdef __APPLE__                                                                                      
 //--------------                                                                                     
    spriteImage             = [UIImage imageNamed:@"BEAMS_01_B_DOT3.png"].CGImage;      
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
        glGenTextures(1, &BEAMS_01_B_NORMALMAP);                                          
        glBindTexture(GL_TEXTURE_2D, BEAMS_01_B_NORMALMAP);                               
        ConfigureAndLoadTexture(spriteData,  width, height);                                          
        if(spriteData != NULL)                                                                        
        {                                                                                             
             free(spriteData);                                                                        
        }                                                                                             
    //-------------------------------------------------------------------------------------           
    spriteImage             = [UIImage imageNamed:@"BEAMS_01_B.png"].CGImage;           
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
        glGenTextures(1, &BEAMS_01_B_TEXTUREMAP);                                         
        glBindTexture(GL_TEXTURE_2D, BEAMS_01_B_TEXTUREMAP);                              
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
    loadTexture("_MODEL_FOLDERS_/BEAMS_01_B/BEAMS_01_B_DOT3.png",     BEAMS_01_B_NORMALMAP);     
    loadTexture("_MODEL_FOLDERS_/BEAMS_01_B/BEAMS_01_B.png",          BEAMS_01_B_TEXTUREMAP);    
    #endif                                                                                                                             
    //-----------------------------------------------------------------------------------                                              
    #include    "BEAMS_01_B.cpp"                                                                                         
    glGenBuffers(1,              &BEAMS_01_B_VBO);                                                                         
    glBindBuffer(GL_ARRAY_BUFFER, BEAMS_01_B_VBO);                                                                         
    glBufferData(GL_ARRAY_BUFFER, sizeof(BEAMS_01_B), BEAMS_01_B, GL_STATIC_DRAW);                             
    glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                  
    //-----------------------------------------------------------------------------------                                              
    #include    "BEAMS_01_B_INDICES.cpp"                                                                                 
    glGenBuffers(1,              &BEAMS_01_B_INDICES_VBO);                                                                 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BEAMS_01_B_INDICES_VBO);                                                         
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(BEAMS_01_B_INDICES), BEAMS_01_B_INDICES, GL_STATIC_DRAW);     
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);                                                                                          
    //-----------------------------------------------------------------------------------                                              
    //=====================================================   
    BEAMS_01_B_boundingBox[0] = -2.98723;
    BEAMS_01_B_boundingBox[1] = 2.98704;
    BEAMS_01_B_boundingBox[2] = -1.67865;
    BEAMS_01_B_boundingBox[3] = 1.70257;
    BEAMS_01_B_boundingBox[4] = -2.98384;
    BEAMS_01_B_boundingBox[5] = 2.78951;
    //=====================================================   
    collisionBoxArray[boxCount][0] = -2.98723;
    collisionBoxArray[boxCount][1] = 2.98704;
    collisionBoxArray[boxCount][2] = -1.67865;
    collisionBoxArray[boxCount][3] = 1.70257;
    collisionBoxArray[boxCount][4] = -2.98384;
    collisionBoxArray[boxCount][5] = 2.78951;
    collisionBoxArray[boxCount][6] = boxCount;
//    boxCount++;
