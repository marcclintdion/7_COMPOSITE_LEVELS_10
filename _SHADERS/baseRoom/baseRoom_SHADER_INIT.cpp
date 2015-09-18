    baseRoom_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_baseRoom =                                                                                    

    " #define highp                                                                                                             \n" 
    
    //--------------------------------------------     
    "    attribute       vec4   position;                                                                                       \n" 
    "    attribute       vec3   normal;                                                                                         \n" 
    "    attribute       vec2   textureCoords;                                                                                  \n" 
    //--------------------------------------------   
    "    uniform         mat4   modelView;                                                                                      \n" 
    "    uniform         mat4   projection;                                                                                     \n" 
    "    uniform         mat4   view;                                                                                           \n"         
    "    uniform         mat4   modelWorld;                                                                                     \n"         
    "    uniform         mat4   view_Rotate;                                                                                    \n"            
    "    uniform         mat4   moveSetMatrix;                                                                                  \n"            
    //--------------------------------------------                                        
    "    uniform  highp  vec4   light_POSITION_01;                                                                              \n" 
    "    uniform  highp  vec4   light_POSITION_02;                                                                              \n" 
    "    uniform         mat4   light_TextureMatrix;                                                                            \n"        
    //--------------------------------------------
    "    uniform         mat4   lightMatrix;                                                                                    \n" 
    "    varying  highp  vec4   shadowTexcoord;                                                                                 \n"       
    //--------------------------------------------
    "    varying  highp  vec4   lightPosition_PASS_01;                                                                          \n" 
    "    varying  highp  vec4   lightPosition_PASS_02;                                                                          \n"     
    "    varying  highp  vec2   varTexcoord;                                                                                    \n" 
    //--------------------------------------------
    "    varying  highp  vec3   normal_PASS;                                                                                    \n" 
 

    //===============================================================================================
    
    " void main()                                                                                                               \n" 
    " {                                                                                                                         \n" 
          //-------------------------------------------------------------------------------    
    "     shadowTexcoord          =  light_TextureMatrix * moveSetMatrix * modelWorld * position;                               \n" 
          //-------------------------------------------------------------------------------
    "     varTexcoord             =  textureCoords;                                                                             \n" 
          //===============================================================================
    "     lightPosition_PASS_01   =  normalize(lightMatrix * light_POSITION_01 - position);                                   \n" 
    "     lightPosition_PASS_02   =  normalize(lightMatrix * light_POSITION_02 - position);                                   \n"     
          //--------------------------------------------------------
    "     normal_PASS             =  normalize(highp vec3(lightMatrix * vec4(normal, 1.0)));                                    \n"     
          //-------------------------------------------------------------------------------
    "     gl_Position             =  projection* view * view_Rotate  * moveSetMatrix* modelWorld * position;                    \n" 
    
    " } \n";   
    
    //===================================================================================================================================                 

    const GLchar *fragmentSource_baseRoom =                                                                                  

    "#ifdef GL_ES                                                                                                                  \n" 
    "#else                                                                                                                         \n" 
    "#define highp                                                                                                                 \n" 
    "#endif                                                                                                                        \n" 
    
    
    
    
    
    //--------------------------------------------
    "    uniform  sampler2D     ShadowTexture;                                                                                     \n"   
    "    varying  highp  vec4   shadowTexcoord;                                                                                    \n"       
    //--------------------------------------------
    "    uniform  sampler2D     NormalMap;                                                                                         \n" 
    "             highp  vec3   NormalTex;                                                                                         \n" 
    "             highp  float  NdotL1;                                                                                            \n" 
    "             highp  float  NdotL2;                                                                                            \n"     
    //--------------------------------------------
    "    uniform  sampler2D     Texture1;                                                                                          \n"     
    "    varying  highp  vec2   varTexcoord;                                                                                       \n" 
    //--------------------------------------------
    "    uniform  highp  float  shininess_L1;                                                                                         \n"    
    "    uniform  highp  float  bias;                                                                                         \n"     
    "             highp  vec4   gloss;                                                                                             \n" 
    "    uniform  highp  float  ambient_LIGHT_01;                                                                                           \n" 
    "    uniform  highp  float  ambient_LIGHT_02;                                                                                           \n" 
    //--------------------------------------------                                                                      
    "    varying  highp  vec4   lightPosition_PASS_01;                                                                             \n" 
    "    varying  highp  vec4   lightPosition_PASS_02;                                                                             \n"  
    //--------------------------------------------                                                                       
    "             highp  vec4   tempColor;                                                                                         \n" 
    "             highp  vec4   specular;                                                                                          \n"     
    //-------------------------------------------- 
    "             highp  float  comp;                                                                                              \n" 
    "             highp  float  depth_PowerVR;                                                                                     \n" 
    "             highp  float  shadowVal;                                                                                         \n" 
    //-------------------------------------------- 
    "    varying  highp  vec3   normal_PASS;                                                                                       \n" 
    
    //==================================================================================================                     
  
    "void main()                                                                                                                    \n" 
    "{                                                                                                                              \n" 
         //---------------------------------------------------------------------------------------------                            
    "    NdotL2                   =  dot(normal_PASS, lightPosition_PASS_02.xyz);                                                   \n" 
         //---------------------------------------------------------------------------------------------                                                  
    "    NormalTex                =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                                     \n" 
    "    NormalTex                =  normalize((NormalTex  - 0.5));                                                                 \n" 
    "    NdotL1                   =  max(dot(NormalTex, normalize(lightPosition_PASS_01.xyz)), 0.0);                                           \n" 
         //---------------------------------------------------------------------------------------------                            
                                         //"bias                  =  shininess_L1 * tan(acos(NdotL1));                              \n" 
                                         //"bias                  =  clamp(bias, 0.0, 0.1);                                         \n"               
         //---            
    //"    bias                     =  0.006114;                                                                                      \n"         
    "    comp                     = (shadowTexcoord.z / shadowTexcoord.w) - bias;                                                   \n" 
    "    depth_PowerVR            =  texture2DProj(ShadowTexture, shadowTexcoord).r;                                                \n" 
   
    "    shadowVal                =  comp <= depth_PowerVR ? 1.0 : 0.5;                                                             \n" 
         //--------------------------------------------------------------------------------------------- 
    "    gloss                    =  max(pow(NdotL1, shininess_L1), 0.0) * texture2D(Texture1, varTexcoord.xy);                                \n" 

    "    gl_FragColor             = (                                                                                               \n" 
    "                                    texture2D(Texture1, varTexcoord.xy) * NdotL1 * ambient_LIGHT_01                            \n" 
    "                                  + texture2D(Texture1, varTexcoord.xy) * NdotL2 * ambient_LIGHT_02                            \n" 
    "                                  + texture2D(Texture1, varTexcoord.xy) * 0.1                                                  \n"     
    
    "                               )  + gloss * 1.0;                                                                               \n" 
    
    
    "    gl_FragColor.w           =   shadowVal;                                                                                    \n"     

   
    
    
    
    
    "}\n";

    
        
        
        
    //=======================================================================================================================                   

        baseRoom_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( baseRoom_SHADER_VERTEX, 1, &vertexSource_baseRoom, NULL );                                        
        glCompileShader( baseRoom_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        baseRoom_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( baseRoom_SHADER_FRAGMENT, 1, &fragmentSource_baseRoom, NULL );                                    
        glCompileShader(baseRoom_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( baseRoom_SHADER, baseRoom_SHADER_VERTEX );                                                        
        glAttachShader( baseRoom_SHADER, baseRoom_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(baseRoom_SHADER,   0, "position");                                                              
        glBindAttribLocation(baseRoom_SHADER,   1, "normal");                                                            
        glBindAttribLocation(baseRoom_SHADER,   2, "textureCoords");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( baseRoom_SHADER_VERTEX);                                                                             
        glDeleteShader( baseRoom_SHADER_FRAGMENT);                                                                           
        glLinkProgram(baseRoom_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_LIGHT_MATRIX_baseRoom                       = glGetUniformLocation(baseRoom_SHADER, "lightMatrix");                
        //-----------------------------        
        UNIFORM_MODELVIEW_baseRoom                          = glGetUniformLocation(baseRoom_SHADER, "modelView");                  
        UNIFORM_PROJECTION_baseRoom                         = glGetUniformLocation(baseRoom_SHADER, "projection");  
        UNIFORM_VIEW_baseRoom                               = glGetUniformLocation(baseRoom_SHADER, "view");                  
        UNIFORM_MODELWORLD_baseRoom                         = glGetUniformLocation(baseRoom_SHADER, "modelWorld");          
        UNIFORM_VIEW_ROTATE_baseRoom                        = glGetUniformLocation(baseRoom_SHADER, "view_Rotate");             
        UNIFORM_MOVESET_MATRIX_baseRoom                     = glGetUniformLocation(baseRoom_SHADER, "moveSetMatrix");          
        //-------------------------------
        UNIFORM_SHADOW_LIGHT_TEXTURE_MATRIX_baseRoom        = glGetUniformLocation(baseRoom_SHADER, "light_TextureMatrix");                                                  
        //-------------------------------      

        UNIFORM_LIGHT_01_POSITION_baseRoom                  = glGetUniformLocation(baseRoom_SHADER, "light_POSITION_01");    
        UNIFORM_LIGHT_02_POSITION_baseRoom                  = glGetUniformLocation(baseRoom_SHADER, "light_POSITION_02");
         //--------------------------------                         
        UNIFORM_ambient_LIGHT_01_baseRoom                   = glGetUniformLocation(baseRoom_SHADER, "ambient_LIGHT_01");  
        UNIFORM_ambient_LIGHT_02_baseRoom                   = glGetUniformLocation(baseRoom_SHADER, "ambient_LIGHT_02");  
        //--------------------------------        
        UNIFORM_shininess_LIGHT_01_baseRoom                 = glGetUniformLocation(baseRoom_SHADER, "shininess_L1");  
        UNIFORM_bias_baseRoom                               = glGetUniformLocation(baseRoom_SHADER, "bias");        
        //--------------------------------
        UNIFORM_ShadowTexture_baseRoom                      = glGetUniformLocation(baseRoom_SHADER, "ShadowTexture");           
        UNIFORM_TEXTURE_cornerSoftDiffuse                   = glGetUniformLocation(baseRoom_SHADER, "cornerSoftDiffuse_TEX");           
        UNIFORM_TEXTURE_DOT3_baseRoom                       = glGetUniformLocation(baseRoom_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_baseRoom                            = glGetUniformLocation(baseRoom_SHADER, "Texture1");  
