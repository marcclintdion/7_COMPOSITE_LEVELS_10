setupTransforms_MainColor();                                                    
//==========================                                                    
    glBindBuffer(GL_ARRAY_BUFFER, BEAMS_01_A_VBO);                  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BEAMS_01_A_INDICES_VBO);  
    //------------------------------------------------------------------------  
    LoadIdentity(modelWorld);                                                   
    //------------------------                                                  
    Translate(modelWorld, BEAMS_01_A_POSITION[0],                   
                          BEAMS_01_A_POSITION[1],                   
                          BEAMS_01_A_POSITION[2]);                  

    Rotate(modelWorld,    BEAMS_01_A_ROTATE[0],                     
                          BEAMS_01_A_ROTATE[1],                     
                          BEAMS_01_A_ROTATE[2],                     
                          BEAMS_01_A_ROTATE[3]);                    

    //------------------------------------------------------                    
    LoadIdentity(modelRotation);                                                
    //------------------------                                                  
    Rotate(modelRotation, BEAMS_01_A_ROTATE[0],                     
                          BEAMS_01_A_ROTATE[1],                     
                          BEAMS_01_A_ROTATE[2],                     
                          BEAMS_01_A_ROTATE[3]);                    

//=========================                                                     
SelectShader(shaderNumber);                                                     
//=========================                                                     

    glActiveTexture ( GL_TEXTURE1 );                                            
    glBindTexture(GL_TEXTURE_2D, BEAMS_01_A_NORMALMAP);             
    //---                                                                       
    glActiveTexture (GL_TEXTURE0);                                              
    glBindTexture(GL_TEXTURE_2D, BEAMS_01_A_TEXTUREMAP);            
    //--------------------------------------------------------------            
    glDrawElements(GL_TRIANGLES, 1920, GL_UNSIGNED_INT, 0);           

