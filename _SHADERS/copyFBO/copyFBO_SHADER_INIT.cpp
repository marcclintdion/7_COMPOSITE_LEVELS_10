//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


//================================================================================================================================
//================================================================================================================================
//================================================================================================================================


    #ifdef __APPLE__                                                                                                                          
    #import <OpenGLES/ES2/gl.h>                                                                                                               
    #import <OpenGLES/ES2/glext.h>                                                                                                            
    #endif                                                                                                                                    
    //=======================================================
      
      copyFBO_SHADER = glCreateProgram();                                                                                                         
   
    //=======================================================
      
      const GLchar *vertexSource_copyFBO =                                                                                                        

    "    #define highp                                                                                                                        \n"                           

    "       attribute     vec4      position;                                                                                               \n"                           
    
    "       varying highp vec2      vTexCoord;                                                                                                      \n"                           

    "    void main()                                                                                                                        \n"                           
    "    {                                                                                                                                  \n"                           
    

    "               vec2 Pos;                                                                                                               \n"  
    "               Pos                     =  sign(position.xy);                                                                                                \n"  
    
    "               vTexCoord               =  Pos * 0.5 + 0.5;                                                                             \n"  
      
    "               gl_Position             =  vec4(Pos.x, Pos.y, 0.0, 1.0);                                                                         \n"  
  
    "    }\n";                                                                                                                             
    
    
    //========================================================================================================
    
    copyFBO_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
    glShaderSource(copyFBO_SHADER_VERTEX, 1, &vertexSource_copyFBO, NULL);                                                                        
    glCompileShader(copyFBO_SHADER_VERTEX);                                                                                                     
    
    //========================================================================================================
    
    const GLchar *fragmentSource_copyFBO =                                                                                                            

    " #ifdef GL_ES                                                                                                                            \n"                       
    " #else                                                                                                                                   \n"                       
    " #define highp                                                                                                                           \n"                       
    " #endif                                                                                                                                  \n"                       

    "    uniform highp  sampler2D  Texture1;                                                                                                  \n"                       
    "    uniform highp  float      adjustBrightness;                                                                                            \n" 
    
    "    varying highp  vec2       vTexCoord;                                                                                                 \n"                       
    "            highp  float      shadowExtraction;                                                                                          \n" 
    
        
    "    void main()                                                                                                                          \n"                       
    "    {                                                                                                                                    \n"                       

    "        shadowExtraction      = pow(texture2D(Texture1, vTexCoord).w, adjustBrightness);                                                                                       \n"
   
   
    "        gl_FragColor          = vec4(shadowExtraction);                                                                                       \n"

    "    }\n";                                                                                                                                   


//==================================================================================================================
      
    copyFBO_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
    glShaderSource(copyFBO_SHADER_FRAGMENT, 1, &fragmentSource_copyFBO, NULL);                                                                          
    glCompileShader(copyFBO_SHADER_FRAGMENT);                                                                                                         

    //==============================================================================================================

    glAttachShader(copyFBO_SHADER, copyFBO_SHADER_VERTEX);                                                                                              
    glAttachShader(copyFBO_SHADER, copyFBO_SHADER_FRAGMENT);                                                                                            
    //------------------------------------------------                                                                                              
    glBindAttribLocation(copyFBO_SHADER, 0, "position");                                                                                            
    glBindAttribLocation(copyFBO_SHADER, 1, "texture");                                                                                             
    //glBindAttribLocation(copyFBO _SHADER, 2, "normal");                                                                                           
    //------------------------------------------------                                                                                              
    glLinkProgram(copyFBO_SHADER);                                                                                                                    
    //------------------------------------------------                                                                                              
    #ifdef __APPLE__                                                                                                                                
    glDetachShader(copyFBO_SHADER, copyFBO_SHADER_VERTEX);                                                                                              
    glDetachShader(copyFBO_SHADER, copyFBO_SHADER_FRAGMENT);                                                                                            
    #endif                                                                                                                                          
    //------------------------------------------------                                                                                              
    glDeleteShader(copyFBO_SHADER_VERTEX);                                                                                                            
    glDeleteShader(copyFBO_SHADER_FRAGMENT);                                                                                                          
    //---------------------------------------------------------------------------------------------------------             
    
    
    //===========================================================================================================================  
    UNIFORM_ADJUST_BRIGHTNESS_copyFBO      = glGetUniformLocation(copyFBO_SHADER, "adjustBrightness");  
    //---------------------------------------------------------------------------------------------------------
    UNIFORM_TEXTURE_1_copyFBO              = glGetUniformLocation(copyFBO_SHADER,  "Texture1");                                                     
    //===========================================================================================================================  

