//
//  DTRecurringPaymentMethod.h
//  Datatrans
//
//  Created by Basil Achermann on 5/15/13.
//  Copyright 2013 iEffects GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTPaymentMethod.h"


@interface DTRecurringPaymentMethod : DTPaymentMethod <NSCopying, NSCoding>

@property (nonatomic, copy) NSString* alias;

- (instancetype)initWithPaymentMethod:(NSString *)method;

// Archiving / unarchiving helpers
+ (instancetype)recurringPaymentMethodWithData:(NSData *)data;
- (NSData *)data;
+ (instancetype)recurringPaymentMethodWithJSON:(NSString *)JSON;
- (NSString *)JSON;

@end
