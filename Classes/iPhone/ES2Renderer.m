/*
     File: ES2Renderer.m
 Abstract: The ES2Renderer class creates an OpenGL ES 2.0 context and delegates to its super class, OpenGLRenderer, for creating and drawing the shaders.
  Version: 1.0
*/

//###################################################################################################################################################################




#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#import <UIKit/UIResponder.h>
#import <UIKit/UIEvent.h>
#import <UIKit/UIKit.h>


EAGLContext *_context;

//=====================================
CGImageRef spriteImage;
size_t width;
size_t height;
GLubyte * spriteData;
CGContextRef spriteContext;
//=====================================

GLuint toggleRender;
GLint  backingWidth;
GLint  backingHeight;
//-------------------
//CGFloat screenScale;
//=====================================

#include "../../RunGL.cpp"

GLsizei  viewWidth;
GLsizei  viewHeight;

#import "ES2Renderer.h"



@interface ES2Renderer (PrivateMethods)

@end



GLuint viewRenderbuffer;
GLuint depthRenderbuffer2;
GLuint msaaFramebuffer, msaaRenderBuffer, msaaDepthBuffer;

@implementation ES2Renderer




//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

// Create an ES 2.0 context
- (ES2Renderer* ) initWithContext:(EAGLContext *) context AndDrawable:(id<EAGLDrawable>)drawable
{	

     
        _context = context;
        
        //=============================================================================================================================         
        //CGRect  screenBounds = [[UIScreen mainScreen] bounds];        
        
        //screenScale = [[UIScreen mainScreen] scale];        
        //CGSize  screenSize = CGSizeMake(backingWidth * screenScale, backingHeight * screenScale);        
        
        //=============================================================================================================================           	
        glGenFramebuffers(1, &viewFramebuffer);
        glGenRenderbuffers(1, &viewRenderbuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, viewFramebuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, viewRenderbuffer);
	
        [_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:drawable];
	
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, viewRenderbuffer);

        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &backingWidth);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &backingHeight);
        //-------------------------------------------------------------------------------------------------
        glGenRenderbuffers(1, &depthRenderbuffer2);
        glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer2);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24_OES, backingWidth, backingHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbuffer2);
        

        //=============================================================================================================================
 
        //Generate our MSAA Frame and Render buffers
        glGenFramebuffers(1, &msaaFramebuffer);
        glGenRenderbuffers(1, &msaaRenderBuffer);
    
        //Bind our MSAA buffers
        glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, msaaRenderBuffer);
    
        // Generate the msaaDepthBuffer.
        // 4 will be the number of pixels that the MSAA buffer will use in order to make one pixel on the render buffer.
        glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_RGBA8_OES, backingWidth, backingHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, msaaRenderBuffer);
    
        glGenRenderbuffers(1, &msaaDepthBuffer); 
        glBindRenderbuffer(GL_RENDERBUFFER, msaaDepthBuffer);
        glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_DEPTH_COMPONENT24_OES, backingWidth, backingHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, msaaDepthBuffer);

  
        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*        glBindRenderbuffer(GL_RENDERBUFFER, viewRenderbuffer);
        [_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:drawable];
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &backingWidth);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &backingHeight);
	
	glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer2);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24_OES, backingWidth, backingHeight);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbuffer2);
	//-------------------------------------------------------------------------------------------------
        
        glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, msaaRenderBuffer);
        
        // Generate the msaaDepthBuffer.
        // 4 will be the number of pixels that the MSAA buffer will use in order to make one pixel on the render buffer.
        glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_RGBA8_OES, backingWidth, backingHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, msaaRenderBuffer);
        
        glGenRenderbuffers(1, &msaaDepthBuffer); 
        glBindRenderbuffer(GL_RENDERBUFFER, msaaDepthBuffer);
        glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_DEPTH_COMPONENT24_OES, backingWidth , backingHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, msaaDepthBuffer);
        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   
*/        


        
      
        
        
        viewWidth  = backingWidth;
	viewHeight = backingHeight;             
        
        InitGL();
    
        toggleRender = 1;

	
	//self = [super initWithDefaultFBO:viewFramebuffer];
	

	
	return self;
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)render 
{
        // Replace the implementation of this method to do your own custom drawing

    

    //chassisFan_ROTATE[3] += 2.0;
        RenderGL();	    

        //===============================================================================================================================================
        //----------------------------------------------------------------Bind both MSAA and View FrameBuffers. 
    if(iOS_MSAA_IS_ON)
    {
        glBindFramebuffer(GL_READ_FRAMEBUFFER_APPLE, msaaFramebuffer); 
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER_APPLE, viewFramebuffer);   
        glResolveMultisampleFramebufferAPPLE();   
        //--------------------------------------------------------------------
        const GLenum discards[]  = {GL_COLOR_ATTACHMENT0,GL_DEPTH_ATTACHMENT};
        glDiscardFramebufferEXT(GL_READ_FRAMEBUFFER_APPLE,2,discards);        
    }  
        //===============================================================================================================================================    
        glBindRenderbuffer(GL_RENDERBUFFER, viewRenderbuffer); 
        [_context presentRenderbuffer:GL_RENDERBUFFER];    
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (BOOL) resizeFromLayer:(CAEAGLLayer *)layer
{
	// The pixel dimensions of the CAEAGLLayer

        //-------------------------------------------------------------------------------------------------
        // Allocate color buffer backing based on the current layer size
	
        
        //screenScale = [[UIScreen mainScreen] scale];        
        //CGSize  screenSize = CGSizeMake(backingWidth * screenScale, backingHeight * screenScale);           
        //-------------------------------------------------------------------------------------------------------------        
        //viewWidth  = backingWidth * screenScale;
	//viewHeight = backingHeight * screenScale;
        //---------------------------------------
	//glViewport(0, 0, viewWidth, viewWidth);
        //-------------------------------------------------------------------------------------------------------------    
	

    return YES;
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void) dealloc
{
    
        shutDownGL();
    
    
	if (viewFramebuffer)
	{
		glDeleteFramebuffers(1, &viewFramebuffer);
		viewFramebuffer = 0;
	}
        if (viewRenderbuffer)
	{
		glDeleteRenderbuffers(1, &viewRenderbuffer);
		viewRenderbuffer = 0;
	}
	if (msaaFramebuffer)
	{
		glDeleteFramebuffers(1, &msaaFramebuffer);
		msaaFramebuffer = 0;
	}
        if (msaaRenderBuffer)
	{
		glDeleteRenderbuffers(1, &msaaRenderBuffer);
		msaaRenderBuffer = 0;
	}    
    
    
        [super dealloc];
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
/*
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event 
{
        
        chassisFan_ROTATE[3] += 2.0;
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event 
{
        chassisFan_ROTATE[3] += 2.0;
}
*/

@end






