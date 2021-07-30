//
//  DTPaymentMethod.h
//  Datatrans
//
//  Created by Basil Achermann on 9/24/13.
//  Copyright 2013 iEffects GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface DTPaymentMethod : NSObject

@property (nonatomic, copy) NSString* paymentMethod;

- (id)initWithPaymentMethod:(NSString *)method;

@end
