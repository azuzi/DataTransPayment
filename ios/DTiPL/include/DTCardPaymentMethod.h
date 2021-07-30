//
//  DTCardPaymentMethod.h
//  Datatrans
//
//  Created by Basil Achermann on 9/24/13.
//  Copyright 2013 iEffects GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTPaymentMethod.h"


@interface DTCardPaymentMethod : DTPaymentMethod <NSCopying>

@property (nonatomic, copy) NSString* number;
@property (nonatomic, assign) NSUInteger expMonth;
@property (nonatomic, assign) NSUInteger expYear;
@property (nonatomic, copy) NSString* cvv;
@property (nonatomic, copy) NSString* holder;

- (id)initWithPaymentMethod:(NSString *)method number:(NSString *)number expMonth:(NSUInteger)expMonth
					expYear:(NSUInteger)expYear cvv:(NSString *)cvv holder:(NSString *)holder;

@end
