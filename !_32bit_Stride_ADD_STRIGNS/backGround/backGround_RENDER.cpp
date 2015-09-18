setupTransforms_MainColor();                                                    
//==========================                                                    
    glBindBuffer(GL_ARRAY_BUFFER, backGround_VBO);                  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, backGround_INDICES_VBO);  
    //------------------------------------------------------------------------  
    LoadIdentity(modelWorld);                                                   
    //------------------------                                                  
    Translate(modelWorld, backGround_POSITION[0],                   
                          backGround_POSITION[1],                   
                          backGround_POSITION[2]);                  

    Rotate(modelWorld,    backGround_ROTATE[0],                     
                          backGround_ROTATE[1],                     
                          backGround_ROTATE[2],                     
                          backGround_ROTATE[3]);                    

    //------------------------------------------------------                    
    LoadIdentity(modelRotation);                                                
    //------------------------                                                  
    Rotate(modelRotation, backGround_ROTATE[0],                     
                          backGround_ROTATE[1],                     
                          backGround_ROTATE[2],                     
                          backGround_ROTATE[3]);                    

//=========================                                                     
SelectShader(shaderNumber);                                                     
//=========================                                                     

    glActiveTexture ( GL_TEXTURE1 );                                            
    glBindTexture(GL_TEXTURE_2D, backGround_NORMALMAP);             
    //---                                                                       
    glActiveTexture (GL_TEXTURE0);                                              
    glBindTexture(GL_TEXTURE_2D, backGround_TEXTUREMAP);            
    //--------------------------------------------------------------            
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);           

