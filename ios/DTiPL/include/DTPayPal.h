//
//  DTPayPal.h
//  Datatrans
//
//  Created by Basil Achermann on 6/4/13.
//  Copyright 2013 iEffects GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTRecurringPaymentMethod.h"


@interface DTPayPal : DTRecurringPaymentMethod<NSCopying, NSCoding>

@property (nonatomic, copy) NSString* email;

// Archiving / unarchiving helpers
+ (instancetype)ppWithData:(NSData *)data;
- (NSData *)data;

@end
