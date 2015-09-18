//========================================================================                            
#ifdef __APPLE__                                                                                      
 //--------------                                                                                     
    spriteImage             = [UIImage imageNamed:@"BEAMS_01_C_DOT3.png"].CGImage;      
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
        glGenTextures(1, &BEAMS_01_C_NORMALMAP);                                          
        glBindTexture(GL_TEXTURE_2D, BEAMS_01_C_NORMALMAP);                               
        ConfigureAndLoadTexture(spriteData,  width, height);                                          
        if(spriteData != NULL)                                                                        
        {                                                                                             
             free(spriteData);                                                                        
        }                                                                                             
    //-------------------------------------------------------------------------------------           
    spriteImage             = [UIImage imageNamed:@"BEAMS_01_C.png"].CGImage;           
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
        glGenTextures(1, &BEAMS_01_C_TEXTUREMAP);                                         
        glBindTexture(GL_TEXTURE_2D, BEAMS_01_C_TEXTUREMAP);                              
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
    loadTexture("_MODEL_FOLDERS_/BEAMS_01_C/BEAMS_01_C_DOT3.png",     BEAMS_01_C_NORMALMAP);     
    loadTexture("_MODEL_FOLDERS_/BEAMS_01_C/BEAMS_01_C.png",          BEAMS_01_C_TEXTUREMAP);    
    #endif                                                                                                                             
    //-----------------------------------------------------------------------------------                                              
    #include    "BEAMS_01_C.cpp"                                                                                         
    glGenBuffers(1,              &BEAMS_01_C_VBO);                                                                         
    glBindBuffer(GL_ARRAY_BUFFER, BEAMS_01_C_VBO);                                                                         
    glBufferData(GL_ARRAY_BUFFER, sizeof(BEAMS_01_C), BEAMS_01_C, GL_STATIC_DRAW);                             
    glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                  
    //-----------------------------------------------------------------------------------                                              
    #include    "BEAMS_01_C_INDICES.cpp"                                                                                 
    glGenBuffers(1,              &BEAMS_01_C_INDICES_VBO);                                                                 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BEAMS_01_C_INDICES_VBO);                                                         
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(BEAMS_01_C_INDICES), BEAMS_01_C_INDICES, GL_STATIC_DRAW);     
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);                                                                                          
    //-----------------------------------------------------------------------------------                                              
    //=====================================================   
    BEAMS_01_C_boundingBox[0] = -3.27986;
    BEAMS_01_C_boundingBox[1] = 3.27986;
    BEAMS_01_C_boundingBox[2] = -1.73485;
    BEAMS_01_C_boundingBox[3] = 1.70471;
    BEAMS_01_C_boundingBox[4] = -3.06183;
    BEAMS_01_C_boundingBox[5] = 3.19786;
    //=====================================================   
    collisionBoxArray[boxCount][0] = -3.27986;
    collisionBoxArray[boxCount][1] = 3.27986;
    collisionBoxArray[boxCount][2] = -1.73485;
    collisionBoxArray[boxCount][3] = 1.70471;
    collisionBoxArray[boxCount][4] = -3.06183;
    collisionBoxArray[boxCount][5] = 3.19786;
    collisionBoxArray[boxCount][6] = boxCount;
//    boxCount++;
