    softDiffuse_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_softDiffuse =                                                                                    

    " #define highp                                                                                                                           \n" 
    
    //--------------------------------------------     
    "    attribute       vec4   position;                                                                                                        \n" 
    "    attribute       vec3   normal;                                                                                                        \n" 
    "    attribute       vec2   textureCoords;                                                                                                   \n" 
    //--------------------------------------------   
    "    uniform         mat4   modelView;                                                                                                       \n" 
    "    uniform         mat4   projection;                                                                                                      \n" 
    "    uniform         mat4   view;                                                                                                       \n"         
    "    uniform         mat4   modelWorld;                                                                                                       \n"         
    "    uniform         mat4   view_Rotate;                                                                                                       \n"            
    "    uniform         mat4   moveSetMatrix;                                                                                                       \n"            
    //--------------------------------------------                                        
    "    uniform  highp  vec4   light_POSITION_01;                                                                                              \n" 
    //--------------------------------------------
    "    uniform         mat4   lightMatrix;                                                                                                    \n" 
    //--------------------------------------------
    "    varying  highp  vec4   lightPosition_PASS_01;                                                                                          \n" 
    "    varying  highp  vec2   varTexcoord;                                                                                                    \n" 
    //--------------------------------------------
    "    varying  highp  vec3   normal_PASS;                                                                                                    \n" 
 
    //==================================================================================================================================
    
    " void main()                                                                                                                               \n" 
    " {                                                                                                                                         \n" 

    "     varTexcoord             =  textureCoords;                                                                                             \n" 
    //"     lightPosition_PASS_01   =  normalize(lightMatrix * light_POSITION_01 - position);                                                   \n" 
   
   
    "     lightPosition_PASS_01   =  normalize(lightMatrix * light_POSITION_01 - position);                                                                           \n" 
    "     normal_PASS             =  normalize(highp vec3(lightMatrix * vec4(normal, 1.0)));                                                                           \n"     
    
    "     gl_Position             =  projection  * view * view_Rotate  * moveSetMatrix * modelWorld * position;                                 \n" 
    
    " } \n";   
    
    //===================================================================================================================================                 

    const GLchar *fragmentSource_softDiffuse =                                                                                  

    "#ifdef GL_ES                                                                                                                                \n" 
    "#else                                                                                                                                       \n" 
    "#define highp                                                                                                                               \n" 
    "#endif                                                                                                                                      \n" 
    
    
    
    
    
    //--------------------------------------------
    "    uniform  sampler2D     Texture1;                                                                                                         \n"     
    "    varying  highp  vec2   varTexcoord;                                                                                                      \n" 
    //--------------------------------------------
    "    uniform  highp  float  ambient;                                                                                                          \n" 
    //--------------------------------------------                                                                      
    "    varying  highp  vec4   lightPosition_PASS_01;                                                                                           \n" 
    "             highp  vec4   lightPosition_FRAG_01;                                                                                           \n" 
    
    //-------------------------------------------- 
    "    varying  highp  vec3   normal_PASS;                                                                                                    \n" 
    "             highp  vec3   normal_FRAG;                                                                                                    \n" 
    
    "             highp  float  NdotL1;                                                                                                           \n" 
                                                       
    //=======================================================================================================================                      

   
    "void main()                                                                                                              \n" 
    "{                                                                                                                        \n" 
    
  
    "    NdotL1                   =  dot(normal_PASS, lightPosition_PASS_01.xyz);                                             \n" 
         //----------------------------------------------------------------------------                                                   

    "    gl_FragColor             =  texture2D(Texture1, varTexcoord) * NdotL1 * ambient;                                                                       \n" 
 
    "}\n";

    
        
        
        
    //=======================================================================================================================                   

        softDiffuse_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( softDiffuse_SHADER_VERTEX, 1, &vertexSource_softDiffuse, NULL );                                        
        glCompileShader( softDiffuse_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        softDiffuse_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( softDiffuse_SHADER_FRAGMENT, 1, &fragmentSource_softDiffuse, NULL );                                    
        glCompileShader(softDiffuse_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( softDiffuse_SHADER, softDiffuse_SHADER_VERTEX );                                                        
        glAttachShader( softDiffuse_SHADER, softDiffuse_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(softDiffuse_SHADER,   0, "position");                                                              
        glBindAttribLocation(softDiffuse_SHADER,   1, "normal");                                                            
        glBindAttribLocation(softDiffuse_SHADER,   2, "textureCoords");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( softDiffuse_SHADER_VERTEX);                                                                             
        glDeleteShader( softDiffuse_SHADER_FRAGMENT);                                                                           
        glLinkProgram(softDiffuse_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_LIGHT_MATRIX_softDiffuse                       = glGetUniformLocation(softDiffuse_SHADER, "lightMatrix");                
        //-----------------------------        
        UNIFORM_MODELVIEW_softDiffuse                          = glGetUniformLocation(softDiffuse_SHADER, "modelView");                  
        UNIFORM_PROJECTION_softDiffuse                         = glGetUniformLocation(softDiffuse_SHADER, "projection");  
        UNIFORM_VIEW_softDiffuse                               = glGetUniformLocation(softDiffuse_SHADER, "view");                  
        UNIFORM_MODELWORLD_softDiffuse                         = glGetUniformLocation(softDiffuse_SHADER, "modelWorld");          
        UNIFORM_VIEW_ROTATE_softDiffuse                        = glGetUniformLocation(softDiffuse_SHADER, "view_Rotate");             
        UNIFORM_MOVESET_MATRIX_softDiffuse                     = glGetUniformLocation(softDiffuse_SHADER, "moveSetMatrix");          
        //-------------------------------

        UNIFORM_LIGHT_POSITION_01_softDiffuse                  = glGetUniformLocation(softDiffuse_SHADER, "light_POSITION_01");    
       
        UNIFORM_ambient_softDiffuse                            = glGetUniformLocation(softDiffuse_SHADER, "ambient");  
          
        UNIFORM_TEXTURE_softDiffuse                            = glGetUniformLocation(softDiffuse_SHADER, "Texture1");  
