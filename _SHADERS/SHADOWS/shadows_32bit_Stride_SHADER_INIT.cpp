    
    SHADER_shadow_32bit_Stride = glCreateProgram();
    //---------------------------------------------------- 
const GLchar *vertexSource_shadow_32bit_Stride =

"    #define highp                                                                                                                              \n"


"    uniform      mat4  light_projection;                                                                                                    \n"
"    uniform      mat4  light_modelWorld;                                                                                                    \n"
"    uniform      mat4  light_view;                                                                                                    \n"
"    uniform      mat4  moveSetMatrix;                                                                                                       \n"  

"    attribute    vec4  position;                                                                                                               \n"



"    void main()                                                                                           \n"
"    {                                                                                                     \n"                                                                            

"         highp vec4 tempPosition    =  light_projection * light_view * moveSetMatrix * light_modelWorld * position;                                    \n" 


"         gl_Position                =  tempPosition;                                                      \n"

"    }\n";

    //---------------------------------------------------------------------

const GLchar *fragmentSource_shadow_32bit_Stride =     

" #ifdef GL_ES                                                                                                                                  \n"
" #else                                                                                                                                         \n"
" #define highp                                                                                                                                 \n"
" #endif                                                                                                                                        \n"


"     void main()                                                                                                                               \n"
"     {                                                                                                                                         \n"


"         gl_FragColor = highp vec4(1.0, 1.0, 1.0, 1.0);                                                                                              \n"         


"    }\n";
    //--------------------------------------------------------------------------------------------------------------------------------------   
    SHADER_VERTEX_shadow_32bit_Stride = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( SHADER_VERTEX_shadow_32bit_Stride, 1, &vertexSource_shadow_32bit_Stride, NULL );
    glCompileShader( SHADER_VERTEX_shadow_32bit_Stride);

    //----------------------------------------------------        
    SHADER_FRAGMENT_shadow_32bit_Stride = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource( SHADER_FRAGMENT_shadow_32bit_Stride, 1, &fragmentSource_shadow_32bit_Stride, NULL );
    glCompileShader(SHADER_FRAGMENT_shadow_32bit_Stride);
       
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glAttachShader( SHADER_shadow_32bit_Stride, SHADER_VERTEX_shadow_32bit_Stride );
    glAttachShader( SHADER_shadow_32bit_Stride, SHADER_FRAGMENT_shadow_32bit_Stride );
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glBindAttribLocation(SHADER_shadow_32bit_Stride,   0, "position");    
    glBindAttribLocation(SHADER_shadow_32bit_Stride,   1, "normal");    
    glBindAttribLocation(SHADER_shadow_32bit_Stride,   2, "texture");       
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glDeleteShader(SHADER_VERTEX_shadow_32bit_Stride);
    glDeleteShader(SHADER_FRAGMENT_shadow_32bit_Stride);   
    glLinkProgram( SHADER_shadow_32bit_Stride);  
    //--------------------------------------------------------------------------------------------------------------------------------------  
    UNIFORM_LIGHT_MODELWORLD_shadow_32bit_Stride             = glGetUniformLocation(SHADER_shadow_32bit_Stride, "light_modelWorld");
    UNIFORM_LIGHT_VIEW_shadow_32bit_Stride                   = glGetUniformLocation(SHADER_shadow_32bit_Stride, "light_view");
    UNIFORM_LIGHT_PROJECTION_shadow_32bit_Stride             = glGetUniformLocation(SHADER_shadow_32bit_Stride, "light_projection");  
    UNIFORM_MOVESET_MATRIX_shadow_32bit_Stride               = glGetUniformLocation(SHADER_shadow_32bit_Stride, "moveSetMatrix");  

