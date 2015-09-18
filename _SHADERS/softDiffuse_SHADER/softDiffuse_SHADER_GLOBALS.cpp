//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
var         softDiffuse_LIGHT_POSITION_01[]     =  {  0.0, 0.0, 7.10018, 1};

var         ambient_softDiffuse                 =      1.0; 

//=====================================================================================
GLuint      softDiffuse_SHADER_VERTEX;                                                                                 
GLuint      softDiffuse_SHADER_FRAGMENT;                                                                               
GLuint      softDiffuse_SHADER;     
//-------------------------------------------------------------------------------------
GLuint      UNIFORM_LIGHT_POSITION_01_softDiffuse;                                                                     
GLuint      UNIFORM_ambient_softDiffuse;

//-------------------------------------------------------------------------------------
GLuint      UNIFORM_LIGHT_MATRIX_softDiffuse;                 

GLuint      UNIFORM_PROJECTION_softDiffuse;  
GLuint      UNIFORM_MODELVIEW_softDiffuse; 
GLuint      UNIFORM_VIEW_softDiffuse; 
GLuint      UNIFORM_MODELWORLD_softDiffuse; 
GLuint      UNIFORM_VIEW_ROTATE_softDiffuse;

GLuint      UNIFORM_MOVESET_MATRIX_softDiffuse;

GLuint      UNIFORM_TEXTURE_softDiffuse;
