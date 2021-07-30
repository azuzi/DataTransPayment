//
//  DTTransactionError.h
//  datatrans-iphone
//
//  Created by paschmid on 07/03/19.
//  Copyright 2019 ieffects ag. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DTBusinessError : NSError

@property (nullable, nonatomic, copy) NSNumber* acquirerErrorCode;
@property (nullable, nonatomic, copy) NSString* threeDSecureCardHolderInfo;
@property (nullable, nonatomic, copy) NSString* threeDSecureTransStatusReason;

@end
