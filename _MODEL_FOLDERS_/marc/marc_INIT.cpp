                                                                                                                                       
        //========================================================================                                                                                  
        #ifdef __APPLE__                                                                                                                                            
        //--------------                                                                                                                                            
          spriteImage             = [UIImage imageNamed:@"marc_DOT3.png"].CGImage;                                                              
          width                   =  CGImageGetWidth(spriteImage);                                                                                                  
          height                  =  CGImageGetHeight(spriteImage);                                                                                                 
          spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));                                                                            
          spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);  
          CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);                                                                                                   
          CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS                                                                                   
          CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS                                                                                   
          CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);                                                                         
          CGContextRelease(spriteContext);                                                                                                                          
          //---------                                                                                                                                               
                glGenTextures(1, &marc_NORMALMAP);                                                                                                
                glBindTexture(GL_TEXTURE_2D, marc_NORMALMAP);                                                                                     
          ConfigureAndLoadTexture(spriteData,  width, height);                                                                                                      
          if(spriteData != NULL)                                                                                                                                    
          {                                                                                                                                                         
                  free(spriteData);                                                                                                                                 
          }                                                                                                                                                         
        //----------------------------------------------------------------------------------------------------------                                                
          spriteImage             = [UIImage imageNamed:@"marc.png"].CGImage;                                                                   
          width                   =  CGImageGetWidth(spriteImage);                                                                                                  
          height                  =  CGImageGetHeight(spriteImage);                                                                                                 
          spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));                                                                            
          spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);  
          CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);                                                                                                   
          CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS                                                                                   
          CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS                                                                                   
          CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);                                                                         
          CGContextRelease(spriteContext);                                                                                                                          
          //---------                                                                                                                                               
          glGenTextures(1, &marc_TEXTUREMAP);                                                                                                     
          glBindTexture(GL_TEXTURE_2D, marc_TEXTUREMAP);                                                                                          
          ConfigureAndLoadTexture(spriteData,  width, height);                                                                                                      
          if(spriteData != NULL)                                                                                                                                    
          {                                                                                                                                                         
                  free(spriteData);                                                                                                                                 
          }                                                                                                                                                         
        //----                                                                                                                                                      
        #endif                                                                                                                                                      
        //========================================================================                                                                                  
        //------------------------------------------------------------------------------------------                                                       
        #ifdef WIN32                                                                                                                                       
        loadTexture("_MODEL_FOLDERS_/marc/marc_DOT3.png",          marc_NORMALMAP);                
        loadTexture("_MODEL_FOLDERS_/marc/marc.png",               marc_TEXTUREMAP);               
        #endif                                                                                                                                             
        //------------------------------------------------------------------------------------------------------------//___LOAD_VBO                        
        #include    "marc.cpp"                                                                                                         
        glGenBuffers(1,              &marc_VBO);                                                                                         
        glBindBuffer(GL_ARRAY_BUFFER, marc_VBO);                                                                                         
        glBufferData(GL_ARRAY_BUFFER, sizeof(marc), marc, GL_STATIC_DRAW);                                             
        glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                                  
        //------------------------------------------------------------------------------------------------------------                                     
        #include    "marc_INDICES.cpp"                                                                                                 
        glGenBuffers(1,              &marc_INDICES_VBO);                                                                                   
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, marc_INDICES_VBO);                                                                           
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(marc_INDICES), marc_INDICES, GL_STATIC_DRAW);                       
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);                                                                                                            
        //------------------------------------------------------------------------------------------------------------                                       
        //====================================================================================   
        marc_boundingBox[0] = -0.262148;
        marc_boundingBox[1] = 0.270252;
        marc_boundingBox[2] = -0.89838;
        marc_boundingBox[3] = 0.902014;
        marc_boundingBox[4] = -0.177793;
        marc_boundingBox[5] = 0.188104;
        //====================================================================================   
        collisionBoxArray[boxCount][0] = -0.262148;
        collisionBoxArray[boxCount][1] = 0.270252;
        collisionBoxArray[boxCount][2] = -0.89838;
        collisionBoxArray[boxCount][3] = 0.902014;
        collisionBoxArray[boxCount][4] = -0.177793;
        collisionBoxArray[boxCount][5] = 0.188104;
        collisionBoxArray[boxCount][6] = boxCount;
//        boxCount++;
