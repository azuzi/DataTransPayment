//  RCTTwintPayment.m

#import <React/RCTLog.h>
#import "RCTTwintPayment.h"
#import "../DataTransPayment/AppDelegate.h"
#import "include/DTPaymentRequest.h"
#import "include/DTPaymentController.h"

@implementation RCTTwintPayment

RCT_EXPORT_MODULE(); // To export a module named TwintPayment

RCT_EXPORT_METHOD(makePayment :(NSString *)mobileToken :(NSString *)refId :(NSString *)amount)
{
  DTPaymentRequest* paymentRequest = [[DTPaymentRequest alloc] init];
  paymentRequest.amountInSmallestCurrencyUnit = 1000;
  paymentRequest.currencyCode = @"CHF";
  paymentRequest.localizedPriceDescription = @"CHF 10.-";
  paymentRequest.merchantId = @"12345";
  paymentRequest.refno = @"refno12345";
  
  NSArray* paymentMethods = [DTPaymentController allAvailablePaymentMethods];
  
  DTPaymentController* paymentController = [DTPaymentController
   paymentControllerWithDelegate:self
   paymentRequest:paymentRequest
   paymentMethods:paymentMethods];
  
  UINavigationController* nav = [UINavigationController alloc];
  
  [paymentController presentInNavigationController:nav animated:YES];
}

@end
