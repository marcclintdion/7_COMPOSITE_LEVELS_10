//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

GLuint      selectBaseRoomLight = 1;
//=======================================================
var         baseRoom_LIGHT_01_POSITION[]    =  {8.0558, 19.4409, 63.7822, 1};
var         baseRoom_LIGHT_02_POSITION[]    =  {-0.0587503, -0.395939, 1.3555, 1};
var         baseRoom_LIGHT_03_POSITION[]    =  {-0.2, -3, -4.09981, 1};

var         ambient_LIGHT_01_baseRoom       =  0.71105;
var         ambient_LIGHT_02_baseRoom       =  0.77195;
var         ambient_LIGHT_03_baseRoom       =  1.02997;

var         shininess_LIGHT_01_baseRoom     =  381;
var         shininess_LIGHT_02_baseRoom     =  100;
var         shininess_LIGHT_03_baseRoom     =  100;
//=======================================================
GLuint      baseRoom_SHADER_VERTEX;                                                                                 
GLuint      baseRoom_SHADER_FRAGMENT;                                                                               
GLuint      baseRoom_SHADER;     
//-------------------------------------------------------
GLuint      UNIFORM_LIGHT_01_POSITION_baseRoom;                                                                     
GLuint      UNIFORM_LIGHT_02_POSITION_baseRoom; 
GLuint      UNIFORM_LIGHT_03_POSITION_baseRoom; 

GLuint      UNIFORM_ambient_LIGHT_01_baseRoom;
GLuint      UNIFORM_ambient_LIGHT_02_baseRoom;
GLuint      UNIFORM_ambient_LIGHT_03_baseRoom;

GLuint      UNIFORM_shininess_LIGHT_01_baseRoom;
GLuint      UNIFORM_shininess_LIGHT_02_baseRoom;
GLuint      UNIFORM_shininess_LIGHT_03_baseRoom;

GLuint      UNIFORM_bias_baseRoom;
//-------------------------------------------------------
GLuint      UNIFORM_LIGHT_MATRIX_baseRoom;                 

GLuint      UNIFORM_PROJECTION_baseRoom;  
GLuint      UNIFORM_MODELVIEW_baseRoom; 
GLuint      UNIFORM_VIEW_baseRoom; 
GLuint      UNIFORM_MODELWORLD_baseRoom; 
GLuint      UNIFORM_VIEW_ROTATE_baseRoom;

GLuint      UNIFORM_MOVESET_MATRIX_baseRoom;

GLuint      UNIFORM_SHADOW_LIGHT_TEXTURE_MATRIX_baseRoom;

//--------------------------------------------------------
GLuint      UNIFORM_ShadowTexture_baseRoom;       
GLuint      UNIFORM_TEXTURE_cornerSoftDiffuse;       
GLuint      UNIFORM_TEXTURE_DOT3_baseRoom;  
GLuint      UNIFORM_TEXTURE_baseRoom; 

//===============================================


