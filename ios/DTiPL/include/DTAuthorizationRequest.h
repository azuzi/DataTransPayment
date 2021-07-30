//
//  DTAuthorizationRequest.h
//  datatrans-iphone
//
//  Created by pschmid on 22/11/18.
//

#import <Foundation/Foundation.h>

#pragma mark Payment authorization request

@interface DTAuthorizationRequest : NSObject <NSCopying> {
	NSString* _transactionId;
	NSString* _merchantId;
	NSString* _refno;
	NSUInteger _amountInSmallestCurrencyUnit;
	NSString* _currencyCode;
	BOOL _autoSettlement;
	NSDictionary* _merchantProperties;
}

@property (nonatomic, copy) NSString* transactionId;
@property (nonatomic, copy) NSString* merchantId;
@property (nonatomic, copy) NSString* refno;
@property (nonatomic, assign) NSUInteger amountInSmallestCurrencyUnit;
@property (nonatomic, copy) NSString* currencyCode;
@property (nonatomic, assign) BOOL autoSettlement;
@property (nonatomic, copy) NSDictionary* merchantProperties;

@end
