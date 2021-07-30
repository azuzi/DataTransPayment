//
//  DTELV.h
//  datatrans-iphone
//
//  Created by bacherma on 19/03/15.
//
//

#import <Foundation/Foundation.h>
#import "DTRecurringPaymentMethod.h"


@interface DTELV : DTRecurringPaymentMethod<NSCopying, NSCoding>

- (instancetype)initWithAlias:(NSString *)alias;

// for old-style ELV aliases with explizit bankrouting obtained from Datatrans before 2015/04/15
- (instancetype)initWithAlias:(NSString *)alias bankrouting:(NSString *)routing;
@property (nonatomic, readonly) NSString* bankrouting;

// Archiving / unarchiving helpers
+ (instancetype)elvWithData:(NSData *)data;
- (NSData *)data;

@end
