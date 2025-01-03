//
//  AKTalkManager.h
//  AKTalkSDK
//
//  Created by 许志明 on 2020/2/6.
//  Copyright © 2020 akuvox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AKSIPModel.h"
#import "AKIncomingModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AKTalkManagerDelegate <NSObject>

/// called when SIP register status changed
/// @param status 0:disable 1:registering 2:register success 3:register failed
- (void)AkTalkDidReceiveSIPRegisterStatusChanged:(int)status;

/// called when SIP receive incoming call message
/// @param callModel Call information, e.g sipNumber, displayName...
- (void)AkTalkDidReceiveIncomingCall:(AKIncomingModel *)callModel;

/// called when SIP receive finish call message
/// @param message the reason of finish call
- (void)AkTalkDidReceiveFinishCallWithMessage:(NSString *)message;

/// called when SIP receive call establish message
/// @param callMode 0:audio call 1:video call
- (void)AkTalkDidReceiveEstablishCall:(int)callMode;

/// called when monitor section established
- (void)AkTalkDidReceiveEstablishMonitor;

/// called when monitor section finished
- (void)AkTalkDidReceiveFinishMonitor;

@optional

/// called to get the notification of whether the door is opened successfully.
/// @param res BLE_OPEN_RES:0=SUCCESS, -1=INVALID CODE, -2=INVALID DEVICE STATE, -3=INVALID RAND CODE, -4=INVALID DISTANCE,101=TIMEOUT
- (void)AkTalkDidReceiveBleOpenDoorResult:(NSString *)res;

@end

@protocol AKTalkFaceRecognitionDelegate <NSObject>

/// called when face data is detected
/// @param faceImage detected face image
- (void)AkTalkDidDetectFaceImage:(UIImage *)faceImage;

@end

@interface AKTalkManager : NSObject

//to monitor sip or call states
@property (nonatomic, weak) id<AKTalkManagerDelegate> delegate;

+ (instancetype)sharedAKTalkManager;
//initialize the AKTalk SDK
- (void)initAKTalkSDK;

//enable the log information from AKTalk SDK. default is YES.
- (void)enableAKTalkLogInfo:(BOOL)on;

//set SIP Configration
- (void)setSIPAccount:(AKSIPModel *)sipModel;

/// Logout the SIP Server
- (void)logoutSipServer;

/// set sip backend on line
- (void)setSipBackendOnline:(BOOL)on;

- (BOOL)isSipBackendOnline;

/// called when you wanna call someone with SIP number and set call mode
/// @param number the sip number you wanna call
/// @param videoMode 0:audio call 1:video call
+ (int)makeCallWithSIPNumber:(NSString *)number videoMode:(int)videoMode;

//answer/hangup the current call section
+ (int)hangupCall;
+ (int)answerCall;

#pragma mark - Media Engine API

//the view to show the video from the other device when calling
@property (nonatomic, strong, nullable) UIView *remoteVideoView;

//the view to show the video from your own camera when calling
@property (nonatomic, strong, nullable) UIView *localVideoView;

/// stop the video play when call or monitoring
+ (void)stopPlayVideo;

/// restart the video play when call or monitoring
+ (void)restartPlayVideo;

/// called to send  dtmf to the other device when calling
/// @param dtmf dtmf value
+ (int)sendDtmf:(NSString *)dtmf;

/// called to set  the microphone to mute/unmute when calling
/// @param mute if YES, then the other part can't hear your voice, vice versa
+ (int)setMute:(BOOL)mute;

/// Called to set the speaker on or off when calling
/// @param on on or off
+ (void)setSpeakerOn:(BOOL)on;

/// Enable or disable the local camera,default NO
/// @param enable if YES, 
+ (void)enableCamera:(BOOL)enable;

+ (BOOL)isEnableCamera;
#pragma mark - Monitor

//the view to show the video from the other device when monitoring
@property (nonatomic, strong, nullable) UIView *monitorView;

/// called when you wanna monitor someone/device with URL and uid, the parameters get from https://(AkcsUrl)/userinfo?token=xxx
/// @param url e.g rtsp://ak:rtsp_pwd@rtsp_server/mac
/// @param uID device account
+ (void)startMonitorWithURL:(NSString *)url uID:(NSString *)uID;

/// called when you wanna monitor someone/device with URL and uid, the parameters get from https://(AkcsUrl)/userinfo?token=xxx
/// @param url e.g rtsp://ak:rtsp_pwd@rtsp_server/mac
/// @param uID device account
/// @param mac In the call transfer, the mac of the door device that needs to be monitored for incoming call preview
+ (void)startMonitorWithURL:(NSString *)url uID:(NSString *)uID transferMac:(nullable NSString *)mac;

//stop the current monitor section
+ (void)stopMonitor;

#pragma mark - BLE Open Door

/// called to enable ble open door function or not.
/// @param on if YES, enable. if NO, disable.
/// return YES, setup success. return NO, setup failed.
+ (BOOL)enableBleOpenDoor:(BOOL)on;


/// called to open door with ble code. You can get ble code from https://xxx
/// @param bleCode ble code.
+ (void)openDoorWithBleCode:(NSString *)bleCode;

#pragma mark - Face Recognition

//to get detected face image
@property (nonatomic, weak) id<AKTalkFaceRecognitionDelegate> faceDelegate;

//start face detect with a display view
+ (void)startFaceDetectWithView:(UIView *)faceDetectView;

//stop face detect
+ (void)stopFaceDetect;

@end

NS_ASSUME_NONNULL_END
