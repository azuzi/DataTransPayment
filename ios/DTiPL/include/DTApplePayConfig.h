//
//  DTApplePayConfig.h
//  datatrans-iphone
//
//  Created by bacherma on 30/06/16.
//

#import <Foundation/Foundation.h>
#import "DTApplePayDelegate.h"

@interface DTApplePayConfig : NSObject<NSCopying>

+ (BOOL)hasApplePayWithSupportedNetworks:(NSArray<PKPaymentNetwork> *)supportedNetworks;

- (instancetype)initWithMerchantIdentifier:(NSString *)merchantIdentifier supportedNetworks:(NSArray<PKPaymentNetwork> *)supportedNetworks; // country code: CH
- (instancetype)initWithMerchantIdentifier:(NSString *)merchantIdentifier supportedNetworks:(NSArray<PKPaymentNetwork> *)supportedNetworks countryCode:(NSString *)countryCode;

// Use for optional configuration of features specific to Apple Pay
@property (nonatomic, readonly) PKPaymentRequest* request;
@property (nonatomic, copy) NSString* finalSummaryItemLabel;
@property (nonatomic, weak) id<DTApplePayDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

@end
