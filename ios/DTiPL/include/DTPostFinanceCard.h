//
//  DTPostFinanceCard.h
//  Datatrans
//
//  Created by Basil Achermann on 5/13/13.
//  Copyright 2013 iEffects GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTRecurringPaymentMethod.h"


@interface DTPostFinanceCard : DTRecurringPaymentMethod<NSCopying, NSCoding>

@property (nonatomic, copy) NSNumber* expMonth;
@property (nonatomic, copy) NSNumber* expYear;
@property (nonatomic, copy) NSString* maskedCC;

// Archiving / unarchiving helpers
+ (instancetype)pfCardWithData:(NSData *)data;
- (NSData *)data;

@end
 
