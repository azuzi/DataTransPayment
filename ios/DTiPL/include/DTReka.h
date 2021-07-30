//
//  DTReka.h
//  Datatrans
//

#import <Foundation/Foundation.h>
#import "DTRecurringPaymentMethod.h"

@class DTPaymentMethodInfo;

@interface DTReka : DTRecurringPaymentMethod<NSCopying, NSCoding>

@property (nonatomic, assign) NSUInteger expMonth;
@property (nonatomic, assign) NSUInteger expYear;
@property (nonatomic, copy) NSString* maskedCC;

// Archiving / unarchiving helpers
+ (instancetype)rekaWithData:(NSData *)data;
- (NSData *)data;

@end
