//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-



      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      finalComposite_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_finalComposite =                                                                                                        

      "    #define highp                                                                                                                        \n"                           

        "       uniform       mat4      mvpMatrix;                                                                                              \n"                           

        "       attribute     vec4      position;                                                                                               \n"                           
      
        "       varying highp vec2      vTexCoord;                                                                                                      \n"                           

        "    void main()                                                                                                                        \n"                           
        "    {                                                                                                                                  \n"                           
     

        "               vec2 Pos;                                                                                                               \n"  
        "               Pos                     =  sign(position.xy);                                                                                                \n"  
 
        "               gl_Position             =  vec4(Pos.x, Pos.y, 0.0, 1.0);                                                                         \n"  
                        
        "               vTexCoord               =  Pos * 0.5 + 0.5;                                                                             \n"  
     
        "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      finalComposite_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(finalComposite_SHADER_VERTEX, 1, &vertexSource_finalComposite, NULL);                                                                        
      glCompileShader(finalComposite_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_finalComposite =                                                                                                            

    " #ifdef GL_ES                                                                                                                            \n"                       
    " #else                                                                                                                                   \n"                       
    " #define highp                                                                                                            \n"                       
    " #endif                                                                                                                    \n"                       
    
    "    varying highp  vec2       vTexCoord;                                                                                    \n"                       
    //--------------------------------------    
    "    uniform highp  sampler2D  Texture2;                                                                                     \n"                       
    "            highp  vec4       hardShadowTransformed;                                                                      \n"
    //--------------------------------------    
    "    uniform highp  sampler2D  Texture1;                                                                                    \n"   
    "    uniform highp  float      rawDepthLumin;                                                                               \n"
    
    "            highp  vec4       depthShadowRAW;                                                                              \n"
    "            highp  float      depthShadowRAW_INVERT;                                                                       \n"

   //--------------------------------------   
    "    uniform highp  sampler2D  Texture0;                                                                                     \n"                       
    "            highp  vec4       color;                                                                                            \n"
    "            highp  float      shadowBlured;                                                                                             \n"
    //--------------------------------------   
    "            highp  vec4       softDiffuseOcclusion;                                                                                     \n"

    //-------------------------------------- 
    
    "    void main()                                                                                                           \n"                       
    "    {                                                                                                                     \n"                       

    //"        hardShadowTransformed  =  texture2D(Texture3, vTexCoord);//THE UNBLURRED SHADOW                                                       \n"
    
    "        softDiffuseOcclusion   =  (texture2D(Texture2, vTexCoord)-1.0) * -1.0;                                             \n"
    
    "        depthShadowRAW         =  texture2D(Texture1, vTexCoord);                                                         \n"
    
    "        depthShadowRAW_INVERT  =  ((depthShadowRAW.r * -1.0) + 1.0) * 1.0;                                                \n"

    "        color                  =  texture2D(Texture0, vTexCoord);                                                         \n"
    "        shadowBlured           =  texture2D(Texture0, vTexCoord).w;                                                       \n"        
    
    //"        gl_FragColor           =  color * pow(depthShadowRAW_INVERT, rawDepthLumin) * shadowBlured;                                   \n"
    "        gl_FragColor           =  color *  shadowBlured;                                   \n"


    //"        gl_FragColor           =  vec4(shadowBlured);                                   \n"
  

    "    }\n";                                                                                                                                   

//==============================================================================================================      

      //---------------------------------------------------------------------                                                                         
      finalComposite_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(finalComposite_SHADER_FRAGMENT, 1, &fragmentSource_finalComposite, NULL);                                                                          
      glCompileShader(finalComposite_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(finalComposite_SHADER, finalComposite_SHADER_VERTEX);                                                                                              
      glAttachShader(finalComposite_SHADER, finalComposite_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(finalComposite_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(finalComposite_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(finalComposite _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(finalComposite_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(finalComposite_SHADER, finalComposite_SHADER_VERTEX);                                                                                              
      glDetachShader(finalComposite_SHADER, finalComposite_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(finalComposite_SHADER_VERTEX);                                                                                                            
      glDeleteShader(finalComposite_SHADER_FRAGMENT);                                                                                                          
      //---------------------------------------------------------------------------------------------------------             
      UNIFORM_TEXTURE_2_finalComposite            = glGetUniformLocation(finalComposite_SHADER,   "Texture2");                                                     
      UNIFORM_TEXTURE_1_finalComposite            = glGetUniformLocation(finalComposite_SHADER,   "Texture1"); 
      UNIFORM_TEXTURE_0_finalComposite            = glGetUniformLocation(finalComposite_SHADER,   "Texture0");                                                     
      //---------------------------------------------------------------------------------------------------------             
      UNIFORM_DEPTH_LUMIN_finalComposite          = glGetUniformLocation(finalComposite_SHADER,   "rawDepthLumin");                                                     
      //---------------------------------------------------------------------------------------------------------         
      
      //=========================================================================================================  
                                                                                                                                 
