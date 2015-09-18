    sky_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_sky =                                                                                    

    " #define highp                                                                                                             \n" 
    
    //--------------------------------------------     
    "    attribute       vec4   position;                                                                                       \n" 
    "    attribute       vec2   textureCoords;                                                                                  \n" 
    //--------------------------------------------   
    "    uniform         mat4   projection;                                                                                     \n" 
    "    uniform         mat4   view;                                                                                           \n"         
    "    uniform         mat4   modelWorld;                                                                                     \n"         
    "    uniform         mat4   view_Rotate;                                                                                    \n"            
    "    uniform         mat4   moveSetMatrix;                                                                                  \n"            
    //--------------------------------------------                                        
    "    varying  highp  vec2   varTexcoord;                                                                                    \n" 
    //--------------------------------------------

    //===============================================================================================
    
    " void main()                                                                                                               \n" 
    " {                                                                                                                         \n" 
    "     varTexcoord             =  textureCoords;                                                                             \n" 
          //-------------------------------------------------------------------------------
    "     gl_Position             =  projection * view * view_Rotate  * moveSetMatrix * modelWorld * position;                    \n" 
    
    " } \n";   
    
    //===================================================================================================================================                 

    const GLchar *fragmentSource_sky =                                                                                  

    "#ifdef GL_ES                                                                                                                  \n" 
    "#else                                                                                                                         \n" 
    "#define highp                                                                                                                 \n" 
    "#endif                                                                                                                        \n" 
    
    
    
    
    "    uniform  sampler2D     Texture1;                                                                                          \n"     
    "    varying  highp  vec2   varTexcoord;                                                                                       \n" 
    //--------------------------------------------

    //=======================================================================================================================                      
  
    "void main()                                                                                                                    \n" 
    "{                                                                                                                              \n" 
   
    "    gl_FragColor           =   texture2D(Texture1, varTexcoord.xy);                                                                                    \n"     
  
    
    
    
    "}\n";

    
        
        
        
    //=======================================================================================================================                   

        sky_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( sky_SHADER_VERTEX, 1, &vertexSource_sky, NULL );                                        
        glCompileShader( sky_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        sky_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( sky_SHADER_FRAGMENT, 1, &fragmentSource_sky, NULL );                                    
        glCompileShader(sky_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( sky_SHADER, sky_SHADER_VERTEX );                                                        
        glAttachShader( sky_SHADER, sky_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(sky_SHADER,   0, "position");                                                              
        glBindAttribLocation(sky_SHADER,   1, "normal");                                                            
        glBindAttribLocation(sky_SHADER,   2, "textureCoords");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( sky_SHADER_VERTEX);                                                                             
        glDeleteShader( sky_SHADER_FRAGMENT);                                                                           
        glLinkProgram(sky_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_sky                          = glGetUniformLocation(sky_SHADER, "modelView");                  
        UNIFORM_PROJECTION_sky                         = glGetUniformLocation(sky_SHADER, "projection");  
        UNIFORM_VIEW_sky                               = glGetUniformLocation(sky_SHADER, "view");                  
        UNIFORM_MODELWORLD_sky                         = glGetUniformLocation(sky_SHADER, "modelWorld");          
        UNIFORM_VIEW_ROTATE_sky                        = glGetUniformLocation(sky_SHADER, "view_Rotate");             
        UNIFORM_MOVESET_MATRIX_sky                     = glGetUniformLocation(sky_SHADER, "moveSetMatrix");          
        UNIFORM_TEXTURE_sky                            = glGetUniformLocation(sky_SHADER, "Texture1");  
