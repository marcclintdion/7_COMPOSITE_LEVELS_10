/*
 File: iPhoneGLEssentialPracticesAppDelegate.m
 Abstract: The application delegate.
 Version: 1.0
*/

//#import <UIKit/UISwipeGestureRecognizer.h>
//#import <UIKit/UITapGestureRecognizer.h>

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#import "iPhoneGLEssentialsAppDelegate.h"
#import "EAGLView.h"
#import <GLKit/GLKit.h>

#import <UIKit/UIResponder.h>
#import <UIKit/UIEvent.h>
#import <UIKit/UIKit.h>

#import <Foundation/Foundation.h>


//===================================================
@implementation iPhoneGLEssentialPracticesAppDelegate
//===================================================
@synthesize window;
@synthesize glView;



//===================================================
GLuint   viewFramebuffer;
GLfloat  rotation;

GLfloat  PassTouchMovement[3];
extern GLfloat  eyePosition[4];
extern GLfloat  moveSet[4];

//extern GLfloat  shadow_BIAS;

//===================================================


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

//----------------------------------------------------------------------------------------------------------------------------------------------------
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{    
    
        

        
    
     
        
        //================================================================================================================================================   
        bounds = window.bounds;
        
        view = [[UIView alloc] initWithFrame: bounds];
        view.multipleTouchEnabled   = YES;
        view.userInteractionEnabled = YES;    
        

        
        [window addSubview: view];        
        
        //UITouch *touchRecognizer = [[UITouch alloc] initWithTarget:self action:@selector(touchDetected:)];
        //[view NSObject:touchRecognizer];
        //------------------------------------------------------------------------------------------------------------------------------------------------
        UIPanGestureRecognizer *panRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panDetected:)];
        [view addGestureRecognizer:panRecognizer];
        //----------------------------------------------------============================================================================================
        UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapDetected:)];
        tapRecognizer.numberOfTapsRequired = 1;
        [view addGestureRecognizer:tapRecognizer];     
        //----------------------------------------
       // UITapGestureRecognizer *doubleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(doubleTapDetected:)];
       // doubleTapRecognizer.numberOfTapsRequired = 2;
       // [view addGestureRecognizer:doubleTapRecognizer];        
        //----------------------------------------------------============================================================================================  
        UIPinchGestureRecognizer *pinchRecognizer = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(pinchDetected:)];
        [view addGestureRecognizer:pinchRecognizer];    
        
        
        //================================================================================================================================================
        //--------------------------------
        //################################__________from video -> session 223 - Building advanced gesture Recognizers.__________##########################
        //--------------------------------
        //################################______________UIGestureRecognizer.h________UIGestureRecognizerSubclass.h__________________######################
        //--------------------------------
        //================================================================================================================================================
        //    -[UIGestureRecognizerDelegate gestureRecognizer: shouldRecognizeSimultaneouslyWithGestureRecognizer:]
        //    -[UIGestureRecognizer shouldPreventGestureRecognizer:]
        //    -[UIGestureRecognizer shouldBePreventedByGestureRecognizer:]
        //    -[singleTap requireGestureToFail:doubleTap]
        //---------------------------------------------------------------------------------------------------------------------------   
        //    -(void)addGestureRecognizer:(UIGestureRecognizer*)gestureRecognizer 
        //    -(void)removeGestureRecognizer:(UIGestureRecognizer*)gestureRecognizer         
        //---------------------------------------------------------------------------------------------------------------------------
        //    -(CGPoint)locationOfTouch:(NSUInteger)touchIndex inView:(UIView*)view;
        //---------------------------------------------------------------------------------------------------------------------------
        //    button1TapTime = CACurrentMediaTime();
        //    http://stackoverflow.com/questions/12708184/handle-taps-in-two-different-points-at-a-same-time-via-uigesturerecognizer ->answered->tarmes
        //---------------------------------------------------------------------
        //    https://developer.apple.com/library/safari/#documentation/AppleApplications/Reference/SafariWebContent/HandlingEvents/HandlingEvents.html
        //---------------------------------------------------------------------        
        //    ontouchstart="touchStart(event);"
        //    ontouchmove="touchMove(event);"
        //    ontouchend="touchEnd(event);"
        //    ontouchcancel="touchCancel(event);"
        // 
        //    Alternatively, register handlers in JavaScript as follows:
        //    element.addEventListener("touchstart", touchStart, false);
        //    element.addEventListener("touchmove", touchMove, false);
        //    element.addEventListener("touchend", touchEnd, false);
        //    element.addEventListener("touchcancel", touchCancel, false);
        //---------------------------------------------------------------------          
        
        //------------------------------------------------------------------------------------------------------------------------------------------------
        /*        //################################################################################################################################################
         UIPanGestureRecognizer *panRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panDetected:)];
         [view addGestureRecognizer:panRecognizer];
         //================================================================================================================================================  
         UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapDetected:)];
         tapRecognizer.numberOfTapsRequired = 1;
         [view addGestureRecognizer:tapRecognizer];     
         //================================================================================================================================================  
         UITapGestureRecognizer *doubleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(doubleTapDetected:)];
         doubleTapRecognizer.numberOfTapsRequired = 2;
         [view addGestureRecognizer:doubleTapRecognizer];        
         //================================================================================================================================================  
         UIPinchGestureRecognizer *pinchRecognizer = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(pinchDetected:)];
         [view addGestureRecognizer:pinchRecognizer];    
         //================================================================================================================================================           
         UIRotationGestureRecognizer *rotationRecognizer = [[UIRotationGestureRecognizer alloc] initWithTarget:self action:@selector(rotationDetected:)];
         [view addGestureRecognizer:rotationRecognizer];
         //================================================================================================================================================       
         UISwipeGestureRecognizer *swipeRecognizer = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(swipeDetected:)];
         swipeRecognizer.direction = UISwipeGestureRecognizerDirectionRight;
         [view addGestureRecognizer:swipeRecognizer];
         */        
        //================================================================================================================================================           
        /*
        UILongPressGestureRecognizer *longpressGesture1 = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPressHandler1:)];
        longpressGesture1.minimumPressDuration = 0;
        longpressGesture1.numberOfTouchesRequired = 1;
        [view addGestureRecognizer:longpressGesture1];    
        //================================================================================================================================================           
        UILongPressGestureRecognizer *longpressGesture2 = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPressHandler2:)];
        longpressGesture2.minimumPressDuration = 0;
        longpressGesture2.numberOfTouchesRequired = 2;
        [view addGestureRecognizer:longpressGesture2];            
        //================================================================================================================================================           
        UILongPressGestureRecognizer *longpressGesture3 = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPressHandler3:)];
        longpressGesture3.minimumPressDuration = 0;
        longpressGesture3.numberOfTouchesRequired = 3;
        [view addGestureRecognizer:longpressGesture3];            
        */
        //================================================================================================================================================       
        
         /*        
         //================================================================================================================================================          
         UITapGestureRecognizer *TwoSimultaneousTapsRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapTwoSimultaneousTaps:)];
         TwoSimultaneousTapsRecognizer.numberOfTapsRequired = 1;
         TwoSimultaneousTapsRecognizer.numberOfTouchesRequired = 2;
         [view addGestureRecognizer:TwoSimultaneousTapsRecognizer];        
         //================================================================================================================================================          
         UITapGestureRecognizer *ThreeSimultaneousTapsRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapThreeSimultaneousTaps:)];
         ThreeSimultaneousTapsRecognizer.numberOfTapsRequired = 1;
         ThreeSimultaneousTapsRecognizer.numberOfTouchesRequired = 3;
         [view addGestureRecognizer:ThreeSimultaneousTapsRecognizer];           
         
         */         
        
        //================================================================================================================================================           
        [glView startAnimation];
        [window makeKeyAndVisible];
    
        return YES;
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
/*
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event 
{
        //[window touchesBegan:touches withEvent:event];
       // eyeposition[0] += 1.0;
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event 
{
        //[window touchesBegan:touches withEvent:event];
        //eyeposition[0] -= 1.0;
}
*/
//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


/*
- (void)doubleTapDetected:(UITapGestureRecognizer *)doubleTapRecognizer
{
  
    
    //breakAnimation = true;
}   

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
 */
 - (void)pinchDetected:(UIPinchGestureRecognizer *)pinchRecognizer
{
        //=========================================================================================
        CGFloat scale = pinchRecognizer.scale;
        //self->view.transform = CGAffineTransformScale(self->view.transform, scale, scale);
        pinchRecognizer.scale = 1.0;
        //=========================================================================================
        eyePosition[2] /= scale;
        
        NSLog(@"eyePosition[2]: %f", eyePosition[2]);

}

- (void)tapDetected:(UITapGestureRecognizer *)tapRecognizer
{
    

     
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)panDetected:(UIPanGestureRecognizer *)panRecognizer
{

      
        CGPoint  locationOnScreen = [panRecognizer velocityInView: view];  
        
        eyePosition[0] +=  locationOnScreen.y * 0.001;
        eyePosition[1] +=  locationOnScreen.x * 0.001;

        //shadow_BIAS -=  locationOnScreen.y * 0.000001;
        //NSLog(@"shadow_BIAS: %f", shadow_BIAS);
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
/*
- (void)longPressHandler1:(UILongPressGestureRecognizer *)longpressGesture1 
{
        //UIGestureRecognizerStateBegan,      // the recognizer has received touches recognized as the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateChanged,    // the recognizer has received touches recognized as a change to the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateEnded,      // the recognizer has received touches recognized as the end of the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to UIGestureRecognizerStatePossible
        //UIGestureRecognizerStateCancelled   // the recognizer has received touches resulting in the cancellation of the gesture. the action method will be called at the next turn of the run loop. the recognizer will be reset to UIGestureRecognizerStatePossible
        
        //===============================================================================
        //CGPoint location =  [longpressGesture1  locationInView:self->view];
        //=================================================================================================================    
       
        
        
}
//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
- (void)longPressHandler2:(UILongPressGestureRecognizer *)longpressGesture2 
{
        //UIGestureRecognizerStateBegan,      // the recognizer has received touches recognized as the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateChanged,    // the recognizer has received touches recognized as a change to the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateEnded,      // the recognizer has received touches recognized as the end of the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to UIGestureRecognizerStatePossible
        //UIGestureRecognizerStateCancelled   // the recognizer has received touches resulting in the cancellation of the gesture. the action method will be called at the next turn of the run loop. the recognizer will be reset to UIGestureRecognizerStatePossible
        
        //===============================================================================
        //CGPoint location =  [longpressGesture2  locationInView:self->view];
        //=================================================================================================================    
        
   
        
        
}
//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
- (void)longPressHandler3:(UILongPressGestureRecognizer *)longpressGesture3 
{
        //UIGestureRecognizerStateBegan,      // the recognizer has received touches recognized as the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateChanged,    // the recognizer has received touches recognized as a change to the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateEnded,      // the recognizer has received touches recognized as the end of the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to UIGestureRecognizerStatePossible
        //UIGestureRecognizerStateCancelled   // the recognizer has received touches resulting in the cancellation of the gesture. the action method will be called at the next turn of the run loop. the recognizer will be reset to UIGestureRecognizerStatePossible
        
        //===============================================================================
        //CGPoint location =  [longpressGesture3  locationInView:self->view];
        //=================================================================================================================    
 
        
}
*/


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)applicationWillResignActive:(UIApplication *)application
{
         /*
         Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
         Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
         */
    
	toggleRender = 0;
    
    [glView stopAnimation];
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)applicationDidEnterBackground:(UIApplication *)application 
{
         /*
         Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
         If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
         */
        
    toggleRender = 0;
	
	[glView stopAnimation];
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)applicationWillTerminate:(UIApplication *)application 
{
         /*
         Called when the application is about to terminate.
         See also applicationDidEnterBackground:.
         */
    
    toggleRender = 0;
    
	[glView stopAnimation];
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)applicationWillEnterForeground:(UIApplication *)application 
{
         /*
         Called as part of transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
         */
	
    toggleRender = 1;
    
	[glView startAnimation];
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)applicationDidBecomeActive:(UIApplication *)application 
{
         /*
         Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
         */
	toggleRender = 1;
    
	[glView startAnimation];
}



//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application 
{
        /*
        Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
        */
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)dealloc 
{
    
        //------------------------------
        [glView release];
        [window release];
        [view release];   
        //------------------------------
    
    
        //------------------------------
    
        [super dealloc];
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================





@end
















