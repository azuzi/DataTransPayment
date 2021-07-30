//
//  DTAliasRequest.h
//  Datatrans
//
//  Created by Basil Achermann on 12/27/10.
//  Copyright 2010 iEffects GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTCardPaymentMethod.h"

@interface DTAliasRequest : NSObject <NSCopying>

// hidden mode credit card alias request
- (id)initWithMerchantId:(NSString *)merchantId
	   currencyCode:(NSString *)currencyCode
	   cardPaymentMethod:(DTCardPaymentMethod *)method;

// standard mode alias request
- (id)initWithMerchantId:(NSString *)merchantId currencyCode:(NSString *)currencyCode paymentMethods:(NSArray *)paymentMethods;

@end
