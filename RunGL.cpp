#define var GLfloat
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))//to_use-> COUNT_OF( floorTile_2m_INDICES)
#define BUFFER_OFFSET(i) ((char *)0 + (i))

//=========================================================
//=========================================================
//=========================================================
#include <sys/timeb.h>

int getMilliCount(){
	struct timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}
int getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if(nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

int start = 0;
int milliSecondsElapsed = 0;
//=========================================================
//=========================================================
//=========================================================

//=======================================================================================================================
    
#ifdef WIN32
        #define   glGenerateMipmap       glGenerateMipmapEXT
        #define   glGenFramebuffers      glGenFramebuffersEXT
        #define   glBindFramebuffer      glBindFramebufferEXT
        #define   glDeleteFramebuffers   glDeleteFramebuffersEXT        
        #define   glFramebufferTexture2D glFramebufferTexture2DEXT
         
         
         
        #define   STRICT
        #define   WIN32_LEAN_AND_MEAN
        #include <windows.h>
       // #include <iostream.h>
        #include <fstream.h>
        #include <vector>
        //using namespace std; //___used for string object

        //-----------------------------------------------------------------------------
        #include <GL/gl.h>
        #include <GL/glu.h>
        #include "headerFiles/glext.h"
        #include "headerFiles/glext_Init_A.cpp"
        //=====================================
        void InitGL(void);
        void RenderGL(void);
        void KillALData(void);
        void ProcessKeyboard(void);
        void shutDownGL(void); 
        bool CreateDummyGLWindow();       
        //=========================
        int  screenWidth;
        int  screenHeight; 
        int  viewWidth;
        int  viewHeight;        
        //----------------------------------------------------------------------
        GLfloat  Pass_MIDDLE_Mouse[2];
        GLfloat  Pass_MIDDLE_CONTROL_Mouse;
        GLfloat  Pass_MIDDLE_SHIFT_Mouse[2];        
        //-------------------------------
        bool keys[256], keypressed[256];
        bool mkeyIsReset = true;
        
        //#include "cpp/winInit.cpp"
        #include "cpp/configureWindow.cpp"
        //-------------------------------

        #include "headerFiles/VSync.h"
        
        #include <windows.h>

        void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
        #include "headerFiles/glaux.h"
        #include "headerFiles/FreeImage.h"
        #include "cpp/freeImage.cpp"
        //------------------------------------------

#endif

//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================


//===========================================================================================
//===========================================================================================
bool sound_API_selector = 0;//_0_is_openAL_/_1_is_fMod
//====================================================
GLfloat frequency[512];
GLfloat audioRotation[] = {1.0, 0.0, 1.0, 0.0};
GLfloat directionSoundTravels = 1.0;
GLuint  selectFrequency = 4;
//----------------------------------------------
#ifdef __APPLE__
        //--------------
        int  viewWidth;
        int  viewHeight;
        //----------------------------------------------
        #include "AUDIO/openAL_iOS/openAL_iOS_GLOBALS.cpp"
        //-----------------------------------------------
//        #import "fmod.hpp"
//        #import "fmod_errors.h"
        GLfloat frequency_fMod_iOS[64];

//        #include "AUDIO/fMod_iOS/fMod_iOS_GLOBALS.cpp" //_____found_in_EAGLView

#endif
//=========================================================
#ifdef WIN32
        
       #include "AUDIO/openAL_WIN/openAL_WIN_GLOBALS.cpp"
        //-----------------------------------------------
       #include "AUDIO/fMod_WIN/fMod_WIN_GLOBALS.cpp"
        int        playing  = 0;
        int       *channel  = 0;
        bool       playOnce = true;
        
#endif
//===========================================================================================
//===========================================================================================


//========================
#include <math.h>
//========================
#include "MATRIX_MATH.cpp"
//========================
#include "GLOBALS.cpp"
//========================$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$





//==========================================================================================
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//==========================================================================================

var shaderNumber = 0;

void SelectShader(var shaderNumber)
{
        
    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   1)
    {
        #include "_SHADERS/copyFBO/copyFBO_SHADER_RENDER.cpp"
    }    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   2)//gaussianBlur_9x_Horizontal
    {
        //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Horizontal_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   3)//gaussianBlur_9x_Vertical
    {
        //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Vertical_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   4)
    {
        
    }    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   5)
    {
        //#include "_SHADERS/softDiffuse_SHADER/softDiffuse_SHADER_RENDER.cpp"
    }    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   6)
    {
        #include "_SHADERS/PowerVR_blur/PowerVR_blur_SHADER_RENDER.cpp"
    }    
    //--------------------------------------------------------------------------------------
    
    
    
    //==================================================================================================          
    if(shaderNumber ==   10)
    {
        #include "_SHADERS/finalComposite/finalComposite_SHADER_RENDER.cpp"
    }         
    //--------------------------------------------------------------------------------------  


    if(shaderNumber ==  11)
    {
        #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_RENDER.cpp"
    }  
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==  12)
    {
        #include "_SHADERS/baseRoom/baseRoom_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==  13)
    {
        #include "_SHADERS/basic/basic_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==  14)
    {
        #include "_SHADERS/sky/sky_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------



}

//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================



void InitGL( void )//__BEGIN_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
{




//=======================
#include "INITIALIZE.cpp" //NOW USING FBO TO DISPLAY SCENE
//=======================





}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================



void RenderGL(void)
{
//t1.start();
//============
//countFrames ++;
//============

//=======================================================================================================================

      
                        //=================================================================
                        #ifdef __APPLE__   
                        //--------------         
                                //eyeposition[0] -= PassTouchMovement[0];
                                //eyeposition[1] -= PassTouchMovement[1];
                                //eyeposition[2] -= PassTouchMovement[2];                   
                        
                                //PassTouchMovement[0] = 0.0;
                                //PassTouchMovement[1] = 0.0;
                                //PassTouchMovement[2] = 0.0;
                        
                        //--------------                        
                        #endif 
                        //=================================================================
                                      
                        //=================================================================        
                        #ifdef WIN32  
                        //------------
                                rotateModelWithMiddleMouse[0] = Pass_MIDDLE_Mouse[0];
                                rotateModelWithMiddleMouse[1] = Pass_MIDDLE_Mouse[1];
                                //-------------------------------------------------------
                                zoomModelWithMiddleMouse = Pass_MIDDLE_CONTROL_Mouse;
                                //-------------------------------------------------------
                                moveModelWithMiddleMouse[0] = Pass_MIDDLE_SHIFT_Mouse[0];
                                moveModelWithMiddleMouse[1] = Pass_MIDDLE_SHIFT_Mouse[1];
                        //------------ 
                        #endif            
                        //=================================================================  
       
//============================================================================================================================       
//turnTable += 0.1;

        
      




//====================================================================================================================================
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
//====================================================================================================================================
        glEnable(GL_DEPTH_TEST);
        glDepthMask(1);
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); 
        glDepthFunc(GL_LESS);
        glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);   

            #include "runDepth_FBO.cpp"
        
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
	    //glDepthMask(0);
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); 
        //glDepthFunc(GL_EQUAL);    
//====================================================================================================================================
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
//====================================================================================================================================
  
//=============================================================================================================== 
//=============================================================================================================== 
/*
    glBindFramebuffer(GL_FRAMEBUFFER, softDiffuse_FBO);//softDiffuse_FBO_TEXTURE
    //==========================================
            shaderNumber = 5;  
    #include "softDiffuse.cpp" 
    //==========================================
    glBindFramebuffer(GL_FRAMEBUFFER, 0);  
*/  

//=============================================================================================================== 
//=============================================================================================================== 


    glBindFramebuffer(GL_FRAMEBUFFER, drawMainColor_PRIMARY_FBO);//drawMainColor_PRIMARY_FBO_COLOR_TEXTURE, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE
    //==========================================
    #include "drawMainColor_FBO.cpp" 
    //==========================================
    glBindFramebuffer(GL_FRAMEBUFFER, 0);  

/*
//=============================================================================================================== 
//=============================================================================================================== 
    glBindFramebuffer(GL_FRAMEBUFFER, hardEdgeShadow_TEXTURE); //hardEdgeShadow_TEXTURE
    //----------------------------------------------------------------
        glActiveTexture (GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_COLOR_TEXTURE);
        shaderNumber = 1;        
        //---------------  
        #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//=============================================================================================================== 
*/

    //=======================_SHADOW_BLUR_========================
    //============================================================     
    scaleFrameBufferPlaneViewPort = scale_generic_FBO;
    #include "_SHADERS/PowerVR_blur/PowerVR_blur_RENDER.cpp"
    //============================================================
    //=======================_SHADOW_BLUR_========================


//=================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------
//=================================================================================================================================
#ifdef __APPLE__ //=======================================================
                  if(iOS_MSAA_IS_ON)
                  {
                      glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);     
                  }else 
                  {
                      glBindFramebuffer(GL_FRAMEBUFFER, viewRenderbuffer);  
                  }
#endif //=================================================================




    //==================================__FINAL_COMPOSITE__===============================
    scaleFrameBufferPlaneViewPort = 1;
    //=================================
    glActiveTexture (GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE);
    //----------------------------
    glActiveTexture (GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE);
    //----------------------------    
    glActiveTexture (GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, generic_02_TEXTURE);//
    //---------------------------------------------------------------------
    shaderNumber = 10;
    #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"
    //==================================__FINAL_COMPOSITE__===============================


/*
    
    glBindFramebuffer(GL_FRAMEBUFFER, drawMainColor_FBO);
    const GLenum discards[]  = {GL_COLOR_ATTACHMENT0,GL_DEPTH_ATTACHMENT};
    glDiscardFramebufferEXT(GL_FRAMEBUFFER,2,discards);
   
    glBindFramebuffer(GL_FRAMEBUFFER, shadow_01_blur_HorizontalPass_fboId);
    const GLenum discards2[]  = {GL_COLOR_ATTACHMENT0};
    glDiscardFramebufferEXT(GL_FRAMEBUFFER,1,discards2);
    
    glBindFramebuffer(GL_FRAMEBUFFER, shadow_01_blur_VerticalPass_fboId);
    const GLenum discards3[]  = {GL_COLOR_ATTACHMENT0};
    glDiscardFramebufferEXT(GL_FRAMEBUFFER,1,discards3);
*/
//=================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------
//=================================================================================================================================



//==========================================================
//==========================================================
//==========================================================
milliSecondsElapsed = getMilliSpan(start);
//--------------
#ifdef __APPLE__
NSLog(@"milliSecondsElapsed: %i", (int)milliSecondsElapsed);
#endif
//==========================================================
//==========================================================
//==========================================================   
LoadIdentity(moveSetMatrix);
Translate(moveSetMatrix, moveSet[0], moveSet[1],moveSet[2]);

 
marc_ROTATE[3] += 0.2;
 
    //ROOM_01_IS_ACTIVE = false;
    //============================================ // eyePosition = 0.0
    if(eyePosition[1] >= -5.0 && eyePosition[1] <= 5.0)
    {
        room_01_IS_ACTIVE = true;
    }
    else
        {
           room_01_IS_ACTIVE = false;
        } 
    //============================================ // eyePosition = -4.0
    if(eyePosition[1] >= -9.0 && eyePosition[1] <= 1.0)
    {
        room_02_IS_ACTIVE = true;
    }
    else
        {
            room_02_IS_ACTIVE = false;
        } 
    //============================================  // eyePosition = -8.0 
    if(eyePosition[1] >= -13.0 && eyePosition[1] <= -3.0)
    {
        room_03_IS_ACTIVE = true;
    }
    else
        {
            room_03_IS_ACTIVE = false;
        } 
    //============================================      
   
   
   
   
}//_END_RenderGL()//#####################################################################################################


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

#ifdef WIN32
void ProcessKeyboard(void)
{

configureShader = 1;
    
    #include "_SHADERS/baseRoom/baseRoom_SHADER_KEYBOARD.cpp"
    //=================================================================================================================      
    
    
    #include "KEYBOARD/mainRoomControls.cpp"
 
 
    //=======================================================================================    
    //--------------------------------------------------------------------------    
    //======================================__LIGHTING__======================

    //-----------------------------------------------------------
    if (keys['X'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            adjustShadowPos[0]             +=   0.000001;
    }
    if (keys['Z'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            adjustShadowPos[0]             -=   0.000001;
    }    
    //-----------------------------------------------------------
    if (keys['V'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            shadow_BIAS             +=   0.0001;
    }
    if (keys['C'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            shadow_BIAS             -=   0.0001;
    }     
    //-----------------------------------------------------------    
    
    if (keys['G'] && gKeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            selectBaseRoomLight               +=  1;
            gKeyIsReset                       = false;
    }
    if (keys['F'] && fKeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            selectBaseRoomLight               -=  1;
            fKeyIsReset                       = false;
    }     
    
 
      //======================================__LIGHTING__======================    
    //--------------------------------------------------------------------------       
    //=================================================================================================================    

  
    if(keys[VK_F8] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
         ofstream outSettings("settings.cpp");
             
         
         //------------------------------------------------------------------------------------------------------------------------------        
         outSettings << "var          adjustShadowPos[]      =  {"    
                                  <<  adjustShadowPos[0]      << ", "   
                                  <<  adjustShadowPos[1]      << "};\n\n";   
         //------------------------------------------------------------------------------------------------------------------------------
        
         outSettings << "var         eyePosition[]    =  {"   
                                  << eyePosition[0] << ", "
                                  << eyePosition[1] << ", "
                                  << eyePosition[2] << ", "
                                  << eyePosition[3] << "};\n\n";
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var          secondsElapsed        =  "    
                                  <<  (GLfloat)milliSecondsElapsed * 0.001        << ";\n\n";   
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var          shadow_BIAS                    =  "    
                                  <<  shadow_BIAS                    << ";\n\n";   
        
        
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var         marc_POSITION[]    =  {"   
                                  << marc_POSITION[0] << ", "
                                  << marc_POSITION[1] << ", "
                                  << marc_POSITION[2] << ", "
                                  << marc_POSITION[3] << "};\n\n";
         //------------------------------------------------------------------------------------------------------------------------------
        
         outSettings << "var         eyePosition_SHADOW[]    =  {"   
                                  << eyePosition_SHADOW[0] << ", "
                                  << eyePosition_SHADOW[1] << ", "
                                  << eyePosition_SHADOW[2] << ", "
                                  << eyePosition_SHADOW[3] << "};\n\n";
         //------------------------------------------------------------------------------------------------------------------------------

         outSettings << "var           eyePosition[]      =  {"   
                                    << eyePosition[0]     << ", "
                                    << eyePosition[1]     << ", "
                                    << eyePosition[2]     << ", 0.0};\n";                

         //------------------------------------------------------------------------------------------------------------------------------

         //------------------------------------------------------------------------------------------------------------------------------
        
        outSettings << "var           rotateModelWithMiddleMouse[]       =  {"   
                                    << rotateModelWithMiddleMouse[0]      << ", "
                                    << rotateModelWithMiddleMouse[1]      << "};\n\n"; 
        
         //------------------------------------------------------------------------------------------------------------------------------
       
         outSettings << "var           moveSet[]       =  {"   
                                    << moveSet[0]      << ", "
                                    << moveSet[1]      << ", "
                                    << moveSet[2]      << ", 1.0};\n";                
        
         //------------------------------------------------------------------------------------------------------------------------------
    
    
   //----------------------------------------------------------------------------------------------------------------
        
    }//_END_F8

//=======================================================================================
//---------------------------------------------------------------------------------------
//_______________________________________________________________________________________
if(keys[VK_F9])
{
    GLsizei screenCaptureWidth  = (GLsizei)viewWidth; 
    GLsizei screenCaptureHeight = (GLsizei)viewHeight;        
                
    GLubyte *pixmap =(GLubyte *)malloc(screenCaptureWidth*screenCaptureHeight*4);
    
    glReadPixels(0,0,screenCaptureWidth,screenCaptureHeight,GL_BGRA,GL_UNSIGNED_BYTE,pixmap);
    
    FIBITMAP *texture = FreeImage_ConvertFromRawBits( pixmap, screenCaptureWidth, screenCaptureHeight, screenCaptureWidth*4, 32, 0xFF0000, 0x00FF00, 0x0000FF, true);    
    FreeImage_Save(FIF_BMP, texture, "AAAAA.bmp", 0);         
        
    free(pixmap);                 
}          
//_______________________________________________________________________________________
//---------------------------------------------------------------------------------------
//=======================================================================================
    if (keys[VK_NUMPAD6] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
        marc_POSITION[0]         += 0.01;
    }
    //------------------------------------------------------------------------------
    if (keys[VK_NUMPAD4] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
        marc_POSITION[0]         -= 0.01;
    }
    //------------------------------------------------------------------------------
    if (keys[VK_NUMPAD8] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
        marc_POSITION[1]         += 0.01;
    }
    //------------------------------------------------------------------------------
    if (keys[VK_NUMPAD2] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
        marc_POSITION[1]         -= 0.01;
    }
    //------------------------------------------------------------------------------
    if (keys[VK_NUMPAD9] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
        marc_POSITION[2]         += 0.01;
    }
    //------------------------------------------------------------------------------
    if (keys[VK_NUMPAD7] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
        marc_POSITION[2]         -= 0.01;
    }
    //------------------------------------------------------------------------------
//=======================================================================================

#include "KEYBOARD/keyboard_RESET.c"

    

    //=================================================================================================================    
    //--------------------------------------------------------------------------    
    //======================================__SELECT_MODEL======================
    if (keys[VK_OEM_PERIOD] && VK_OEM_PERIOD_KeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             selectedModel += 1;
             VK_OEM_PERIOD_KeyIsReset = false;   
    }
    //=============================================================    
    if (keys[VK_OEM_COMMA] && VK_OEM_COMMA_KeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             selectedModel -= 1;
             VK_OEM_COMMA_KeyIsReset = false;   
    }
    //======================================__SELECT_MODEL__====================     
    //--------------------------------------------------------------------------
    //=================================================================================================================
    //=================================================================================================================
    //--------------------------------------------------------------------------     
    //======================================__BOX_COUNT__====================        
    if (keys[VK_PRIOR] && VK_PRIOR_KeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
         boxCount +=  1;
         VK_PRIOR_KeyIsReset  = false;
    }         
    if (keys[VK_NEXT]  && VK_NEXT_KeyIsReset  && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
         boxCount -=  1;
         VK_NEXT_KeyIsReset   = false;    
    }       
    //======================================__BOX_COUNT__====================         
    //--------------------------------------------------------------------------       
    //=================================================================================================================   
    
    
     
   
}//_END_ProcessKeyboard()
#endif


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================


void shutDownGL( void )
{

        
       
       
       #include "SHUTDOWN.cpp"
        
                                                               
 
 
 
 
}


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

#ifdef WIN32
void KillALData()
{
	alDeleteBuffers(1, &Buffer_dungeonWAV);
	alDeleteSources(1, &Source_dungeonWAV);
    alutExit();
}
#endif




