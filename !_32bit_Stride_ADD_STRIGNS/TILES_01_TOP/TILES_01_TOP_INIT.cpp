//========================================================================                            
#ifdef __APPLE__                                                                                      
 //--------------                                                                                     
    spriteImage             = [UIImage imageNamed:@"TILES_01_TOP_DOT3.png"].CGImage;      
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
        glGenTextures(1, &TILES_01_TOP_NORMALMAP);                                          
        glBindTexture(GL_TEXTURE_2D, TILES_01_TOP_NORMALMAP);                               
        ConfigureAndLoadTexture(spriteData,  width, height);                                          
        if(spriteData != NULL)                                                                        
        {                                                                                             
             free(spriteData);                                                                        
        }                                                                                             
    //-------------------------------------------------------------------------------------           
    spriteImage             = [UIImage imageNamed:@"TILES_01_TOP.png"].CGImage;           
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
        glGenTextures(1, &TILES_01_TOP_TEXTUREMAP);                                         
        glBindTexture(GL_TEXTURE_2D, TILES_01_TOP_TEXTUREMAP);                              
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
    loadTexture("_MODEL_FOLDERS_/TILES_01_TOP/TILES_01_TOP_DOT3.png",     TILES_01_TOP_NORMALMAP);     
    loadTexture("_MODEL_FOLDERS_/TILES_01_TOP/TILES_01_TOP.png",          TILES_01_TOP_TEXTUREMAP);    
    #endif                                                                                                                             
    //-----------------------------------------------------------------------------------                                              
    #include    "TILES_01_TOP.cpp"                                                                                         
    glGenBuffers(1,              &TILES_01_TOP_VBO);                                                                         
    glBindBuffer(GL_ARRAY_BUFFER, TILES_01_TOP_VBO);                                                                         
    glBufferData(GL_ARRAY_BUFFER, sizeof(TILES_01_TOP), TILES_01_TOP, GL_STATIC_DRAW);                             
    glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                  
    //-----------------------------------------------------------------------------------                                              
    #include    "TILES_01_TOP_INDICES.cpp"                                                                                 
    glGenBuffers(1,              &TILES_01_TOP_INDICES_VBO);                                                                 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, TILES_01_TOP_INDICES_VBO);                                                         
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(TILES_01_TOP_INDICES), TILES_01_TOP_INDICES, GL_STATIC_DRAW);     
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);                                                                                          
    //-----------------------------------------------------------------------------------                                              
    //=====================================================   
    TILES_01_TOP_boundingBox[0] = -3;
    TILES_01_TOP_boundingBox[1] = 3;
    TILES_01_TOP_boundingBox[2] = 1.67869;
    TILES_01_TOP_boundingBox[3] = 1.99943;
    TILES_01_TOP_boundingBox[4] = -3;
    TILES_01_TOP_boundingBox[5] = 3;
    //=====================================================   
    collisionBoxArray[boxCount][0] = -3;
    collisionBoxArray[boxCount][1] = 3;
    collisionBoxArray[boxCount][2] = 1.67869;
    collisionBoxArray[boxCount][3] = 1.99943;
    collisionBoxArray[boxCount][4] = -3;
    collisionBoxArray[boxCount][5] = 3;
    collisionBoxArray[boxCount][6] = boxCount;
//    boxCount++;
