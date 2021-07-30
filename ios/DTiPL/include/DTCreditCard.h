//
//  DTCreditCard.h
//  Datatrans
//
//  Created by Kaspar Rohrer on 8/11/10.
//  Copyright 2010 iEffects. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTRecurringPaymentMethod.h"

@class DTPaymentMethodInfo;

@interface DTCreditCard : DTRecurringPaymentMethod<NSCopying, NSCoding>

@property (nonatomic, assign) NSUInteger expMonth;
@property (nonatomic, assign) NSUInteger expYear;
@property (nonatomic, copy) NSString* maskedCC;
@property (nonatomic, copy) NSString* cardHolder;

// Archiving / unarchiving helpers
+ (instancetype)creditCardWithData:(NSData *)data;
- (NSData *)data;

@end
