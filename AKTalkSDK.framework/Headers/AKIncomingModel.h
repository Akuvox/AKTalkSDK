//
//  AKIncomingModel.h
//  AKTalkSDK
//
//  Created by akuvox_mini on 2024-01-16.
//  Copyright © 2024 akuvox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AKIncomingModel : NSObject

/// the caller’s sip number
@property (nonatomic, copy) NSString *sipNumber;

/// the caller’s display number
@property (nonatomic, copy) NSString *displayName;

/// the SIP number of the calling site. If you are not in the case of multiple sites, you can ignore it
@property (nonatomic, copy) NSString *site;

/* used when you use indoor phone to transfer stream from door phone to app */

/// the door phone name
@property (nonatomic, copy) NSString *Dname;

/// the indoor phone mac
@property (nonatomic, copy) NSString *Dmac;

/// the door phone mac
@property (nonatomic, copy) NSString *Imac;

/// Relay information array used to open door during a call. e.g: @{@"name":@"xx", @"dtmf":@"123"}
@property (nonatomic, strong) NSArray *relay;
/// Call identification
@property (nonatomic, copy) NSString *traceId;

@end


NS_ASSUME_NONNULL_END
