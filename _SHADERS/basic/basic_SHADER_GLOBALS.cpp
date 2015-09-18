//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

var         basic_LIGHT_POSITION_01[]    =  {-0.685583, 5.7952, 7.10018, 1};

var         shininess_basic              =  100.0;

var         ambient_LIGHT_01_basic       =  1.0;

//=====================================================================================
GLuint      basic_SHADER_VERTEX;                                                                                 
GLuint      basic_SHADER_FRAGMENT;                                                                               
GLuint      basic_SHADER;     
//-------------------------------------------------------------------------------------
GLuint      UNIFORM_LIGHT_POSITION_01_basic;                                                                     

GLuint      UNIFORM_shininess_basic;
GLuint      UNIFORM_ambient_LIGHT_01_basic;
//-------------------------------------------------------------------------------------
GLuint      UNIFORM_LIGHT_MATRIX_basic;                 

GLuint      UNIFORM_PROJECTION_basic;  
GLuint      UNIFORM_MODELVIEW_basic; 
GLuint      UNIFORM_VIEW_basic; 
GLuint      UNIFORM_MODELWORLD_basic; 
GLuint      UNIFORM_VIEW_ROTATE_basic;

GLuint      UNIFORM_MOVESET_MATRIX_basic;

GLuint      UNIFORM_SHADOW_LIGHT_TEXTURE_MATRIX_basic;

//-------------------------------------------------------------------------------------
GLuint      UNIFORM_ShadowTexture_basic;       
    
GLuint      UNIFORM_TEXTURE_DOT3_basic;  
GLuint      UNIFORM_TEXTURE_basic; 

