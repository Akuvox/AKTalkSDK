//
//  AKSIPModel.h
//  AKTalkSDK
//
//  Created by 许志明 on 2020/2/12.
//  Copyright © 2020 akuvox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AKSIPModel : NSObject

@property (nonatomic, copy) NSString *user_sip;
@property (nonatomic, copy) NSString *display_name;
@property (nonatomic, copy) NSString *sip_passwd;
@property (nonatomic, copy) NSString *sip_server;
@property (nonatomic, copy) NSString *sip_server_ipv6;
@property (nonatomic, copy) NSString *rtsp_server;
@property (nonatomic, copy) NSString *rtsp_server_ipv6;
@property (nonatomic, copy) NSString *sip_trans_type;   // @"1":TCP     @"2":TLS
@property (nonatomic, copy) NSString *rtsp_trans_type;  // @"0":TCP     @"1":TLS
@property (nonatomic, copy) NSString *api_server;
@property (nonatomic, copy) NSString *client_id;
@property (nonatomic, copy) NSString *main_sip;
@property (nonatomic, copy) NSString *main_sip_passwd;

@property (nonatomic, copy) NSString *sip_server_domain;
@property (nonatomic, copy) NSString *sip_tls_server_domain;
@property (nonatomic, copy) NSString *rtsp_server_domain;
@property (nonatomic, copy) NSString *rtsp_tls_server_domain;

@property (nonatomic, copy) NSString *ringtone;

@end

NS_ASSUME_NONNULL_END
