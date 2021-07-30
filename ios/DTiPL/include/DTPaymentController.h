//
//  DTPaymentController.h
//  Datatrans
//
//  Created by Kaspar Rohrer on 8/11/10.
//  Copyright 2010 iEffects. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class DTVisualStyle;
@class DTRecurringPaymentMethod;
@class DTPaymentOptions;
@class DTPaymentRequest;
@class DTAliasRequest;
@class DTAuthorizationRequest;
@class DTCardPaymentMethod;
@protocol DTPaymentControllerDelegate;
@protocol DTPaymentControllerAliasDelegate;

extern NSString* const DTPaymentMethodVisa;
extern NSString* const DTPaymentMethodMasterCard;
extern NSString* const DTPaymentMethodDinersClub;
extern NSString* const DTPaymentMethodAmericanExpress;
extern NSString* const DTPaymentMethodJCB;
extern NSString* const DTPaymentMethodMyOne;
extern NSString* const DTPaymentMethodUATP;
extern NSString* const DTPaymentMethodDiscover;
extern NSString* const DTPaymentMethodSupercard;
extern NSString* const DTPaymentMethodPostFinanceCard;
extern NSString* const DTPaymentMethodPostFinanceEFinance;
extern NSString* const DTPaymentMethodPayPal;
extern NSString* const DTPaymentMethodEasypay;
extern NSString* const DTPaymentMethodELV;
extern NSString* const DTPaymentMethodSwissBilling;
extern NSString* const DTPaymentMethodTWINT;
extern NSString* const DTPaymentMethodApplePay;
extern NSString* const DTPaymentMethodReka;
extern NSString* const DTPaymentMethodByjuno;
extern NSString* const DTPaymentMethodSwissPass;
extern NSString* const DTPaymentMethodPowerpay;
extern NSString* const DTPaymentMethodPaysafecard;
extern NSString* const DTPaymentMethodBoncard;

extern NSString* const DTPaymentErrorDomain;
extern NSString* const DTPaymentMethodKey;

typedef enum {
	DTPaymentErrorTechnical,
    DTPaymentErrorValidation,
	DTPaymentErrorAuthentication,
	DTPaymentErrorAuthorization
} DTPaymentErrorCode;

typedef enum {
	DTPaymentCancellationTypeBackButton,
    DTPaymentCancellationTypeCancelButton
} DTPaymentCancellationType;


#pragma mark - Main interface
@interface DTPaymentController : NSObject {
}

#pragma mark -
+ (NSArray *)allAvailablePaymentMethods;


#pragma mark - Properties
@property (nonatomic, copy) DTVisualStyle* visualStyle;
@property (nonatomic, copy) DTPaymentOptions* paymentOptions;
@property (nonatomic, readonly) DTRecurringPaymentMethod* recurringPaymentMethod;
@property (nonatomic, readonly) DTPaymentRequest* paymentRequest;
@property (nonatomic, readonly) NSString* transactionId;

#pragma mark - Payment
// standard mode payment
+ (id)paymentControllerWithDelegate:(id<DTPaymentControllerDelegate>)delegate
					 paymentRequest:(DTPaymentRequest *)request
					 paymentMethods:(NSArray *)identifiers;

 // new standard mode payment
 + (id)paymentControllerWithDelegate:(id<DTPaymentControllerDelegate>)delegate
						 mobileToken:(NSString *)mobileToken;

// hidden mode card payment (initial)
+ (id)paymentControllerWithDelegate:(id<DTPaymentControllerDelegate>)delegate
					 paymentRequest:(DTPaymentRequest *)request
				  cardPaymentMethod:(DTCardPaymentMethod *)cardPaymentMethod;

// new hidden mode card payment (initial)
+ (id)paymentControllerWithDelegate:(id<DTPaymentControllerDelegate>)delegate
						mobileToken:(NSString *)mobileToken
				  cardPaymentMethod:(DTCardPaymentMethod *)cardPaymentMethod;

// hidden mode recurring/alias payment
+ (id)paymentControllerWithDelegate:(id<DTPaymentControllerDelegate>)delegate
					 paymentRequest:(DTPaymentRequest *)request
			 recurringPaymentMethod:(DTRecurringPaymentMethod *)recurringPaymentMethod;


#pragma mark - Alias creation only
// hidden / standard mode, see DTAliasRequest
+ (id)paymentControllerWithDelegate:(id<DTPaymentControllerDelegate>)delegate
					   aliasRequest:(DTAliasRequest *)aliasRequest;

#pragma mark - Authorization
+ (id)paymentControllerWithDelegate:(id<DTPaymentControllerDelegate>)delegate
			   authorizationRequest:(DTAuthorizationRequest *)authorizationRequest;


#pragma mark - Presentation
- (void)presentInNavigationController:(UINavigationController *)controller animated:(BOOL)animated;
- (void)dismissAnimated:(BOOL)animated;
- (void)restoreToolbarState:(BOOL)animated;

#pragma mark - Payment method identifier
- (NSString *)paymentMethodIdentifier;

@end


#pragma mark - DTPaymentControllerDelegate
@protocol DTPaymentControllerDelegate <NSObject>

- (void)paymentControllerDidFinish:(DTPaymentController *)controller;
- (void)paymentController:(DTPaymentController *)controller didFailWithError:(NSError *)error;

@optional
- (void)paymentController:(DTPaymentController *)controller didCancelWithType:(DTPaymentCancellationType)cancellationType;

// Implement this method if the payment controller should support user interface orientations other than UIInterfaceOrientationPortrait.
- (BOOL)paymentController:(DTPaymentController *)controller shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation;

@end
