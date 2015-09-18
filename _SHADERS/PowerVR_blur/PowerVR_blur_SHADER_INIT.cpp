
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



    // Texel offset for blur filter kernle
	m_fTexelOffset = 1.0f / (float)viewHeight;

    intraTexelOffset = (w1 / (w1 + w2)) * m_fTexelOffset;
	m_fTexelOffset += intraTexelOffset;



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



    PowerVR_blur_SHADER = glCreateProgram();
    //----------------------------------------------------
    const GLchar *vertexSource_PowerVR_blur =                                                                                    

    " #define highp                                                                                                                             \n"
    
    //--------------------------------------------     
    "    attribute        vec4   position;                                                                                                       \n"
    //--------------------------------------------
    "    uniform   highp  float  TexelOffsetX;                                                                                                    \n"
    "    uniform   highp  float  TexelOffsetY;                                                                                                    \n"
    "    uniform   highp   vec2  adjustShadowPos;                                                                                \n"
 
    "    varying   highp   vec2  vTexCoord;                                                                                     \n"

    "    varying   highp   vec2  TexCoord0;                                                                                     \n"
    "    varying   highp   vec2  TexCoord1;                                                                                     \n"
    "    varying   highp   vec2  TexCoord2;                                                                                     \n"
  
    "              highp   vec2  offset;                                                                                        \n"



    //==================================================================================================================================
    
    " void main()                                                                                                               \n" 
    " {                                                                                                                         \n" 

        "   highp vec2 Pos;                                                                                                     \n"
        "   Pos                     =  sign(position.xy);                                                                       \n"
        "   gl_Position             =  highp vec4(Pos.x, Pos.y, 0.0, 1.0);                                                      \n"
        "   vTexCoord               =  Pos * 0.5 + 0.5;                                                                         \n"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Calculate texture offsets and pass through
        " 	  offset = vec2(TexelOffsetX, TexelOffsetY);                                                                        \n"
  
        "     TexCoord0 = vTexCoord + adjustShadowPos - offset;                                                                 \n"
        "     TexCoord1 = vTexCoord + adjustShadowPos;                                                                          \n"
        "     TexCoord2 = vTexCoord + adjustShadowPos + offset;                                                                 \n"


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    " } \n";
    
    //===================================================================================================================================                 

    const GLchar *fragmentSource_PowerVR_blur =                                                                                  

    "#ifdef GL_ES                                                                                                                                \n" 
    "#else                                                                                                                                       \n" 
    "#define highp                                                                                                                               \n" 
    "#endif                                                                                                                                      \n" 
    
    
    //--------------------------------------------
    "    uniform  sampler2D     Texture1;                                                                              \n"
    //--------------------------------------------
    "    varying  highp  vec2   vTexCoord;                                                                                     \n"
    
    "    varying  highp  vec2   TexCoord0;                                                                             \n"
    "    varying  highp  vec2   TexCoord1;                                                                             \n"
    "    varying  highp  vec2   TexCoord2;                                                                             \n"
    //--------------------------------------------
    //"    varying  highp  vec2   offset;                                                                                                      \n"

    //=======================================================================================================================

   
    "void main()                                                                                                                                \n"
    "{                                                                                                                                          \n"



"    highp vec4 color      =  texture2D(Texture1, vTexCoord);                                                              \n"
//----------------------------------------------------------------

"    highp float shadow    =  texture2D(Texture1, TexCoord0).w * 0.333333;                                 \n"
"    shadow               +=  texture2D(Texture1, TexCoord1).w * 0.333333;                                 \n"
"    shadow               +=  texture2D(Texture1, TexCoord2).w * 0.333333;                                 \n"






    "    gl_FragColor             =  highp vec4(color.xyz,  shadow   );                                                    \n"
 
    "}\n";

    
        
        
        
    //=======================================================================================================================                   

        PowerVR_blur_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( PowerVR_blur_SHADER_VERTEX, 1, &vertexSource_PowerVR_blur, NULL );                                        
        glCompileShader( PowerVR_blur_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        PowerVR_blur_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( PowerVR_blur_SHADER_FRAGMENT, 1, &fragmentSource_PowerVR_blur, NULL );                                    
        glCompileShader(PowerVR_blur_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( PowerVR_blur_SHADER, PowerVR_blur_SHADER_VERTEX );                                                        
        glAttachShader( PowerVR_blur_SHADER, PowerVR_blur_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(PowerVR_blur_SHADER,   0, "position");                                                              
        glBindAttribLocation(PowerVR_blur_SHADER,   1, "normal");                                                            
        glBindAttribLocation(PowerVR_blur_SHADER,   2, "textureCoords");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( PowerVR_blur_SHADER_VERTEX);                                                                             
        glDeleteShader( PowerVR_blur_SHADER_FRAGMENT);                                                                           
        glLinkProgram(PowerVR_blur_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    

        UNIFORM_TexelOffsetX_PowerVR_blur                            = glGetUniformLocation(PowerVR_blur_SHADER, "TexelOffsetX");
        UNIFORM_TexelOffsetY_PowerVR_blur                            = glGetUniformLocation(PowerVR_blur_SHADER, "TexelOffsetY");

        UNIFORM_adjustShadowPos_PowerVR_blur                        = glGetUniformLocation(PowerVR_blur_SHADER, "adjustShadowPos");//used to hide halo


        UNIFORM_TEXTURE_PowerVR_blur                                 = glGetUniformLocation(PowerVR_blur_SHADER, "Texture1");  
