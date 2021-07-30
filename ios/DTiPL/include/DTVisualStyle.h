//
//  DTVisualStyle.h
//  datatrans-iphone
//
//  Created by Kaspar Rohrer on 8/11/10.
//  Copyright 2010 iEffects. All rights reserved.
//

#import <UIKit/UIKit.h>


#pragma mark - DTSimpleTextStyle
@interface DTSimpleTextStyle : NSObject <NSCopying>

+ (id)textStyleWithFont:(UIFont *)font color:(UIColor *)color;

- (void)applyToTextField:(UITextField *)textField;
- (void)applyToTextView:(UITextView *)textView;

@property (nonatomic, retain) UIColor* color;
@property (nonatomic, retain) UIFont* font;

@end


#pragma mark - DTShadowTextStyle
@interface DTShadowTextStyle : DTSimpleTextStyle <NSCopying>

+ (id)textStyleWithFont:(UIFont *)font color:(UIColor *)color;
- (id)withShadowColor:(UIColor *)color andOffset:(CGSize)shadowOffset;

- (void)applyToLabel:(UILabel *)label;
- (NSString *)CSSStyle;

@property (nonatomic, retain) UIColor* shadowColor;
@property (nonatomic, assign) CGSize shadowOffset;

@end


@interface UIColor (DTAdditions)

- (UIColor *)colorWithDTLightStyleColor:(UIColor *)lightColor API_AVAILABLE(ios(13));
- (UIColor *)colorWithDTDarkStyleColor:(UIColor *)darkColor API_AVAILABLE(ios(13));

@end


#pragma mark - DTVisualStyle
@interface DTVisualStyle : NSObject <NSCopying>

+ (DTVisualStyle *)defaultStyle;

@property (nonatomic, assign) BOOL isDark;

@property (nonatomic, copy) DTShadowTextStyle* navigationBarTitleStyle;
@property (nonatomic, retain) UIColor* navigationBarButtonItemDoneTintColor;
@property (nonatomic, retain) DTShadowTextStyle* toolbarTextStyle;

@property (nonatomic, retain) UIColor* backgroundColor;

@property (nonatomic, retain) UIColor* inputFieldBackgroundColor;
@property (nonatomic, copy) DTSimpleTextStyle* inputFieldStyle;
@property (nonatomic, copy) DTShadowTextStyle* inputLabelStyle;
@property (nonatomic, copy) DTShadowTextStyle* titleStyle;
@property (nonatomic, copy) DTShadowTextStyle* textStyle;
@property (nonatomic, copy) DTShadowTextStyle* emphasizedTextStyle;
@property (nonatomic, copy) DTShadowTextStyle* infoTextStyle;
@property (nonatomic, copy) DTShadowTextStyle* emphasizedInfoTextStyle;

@property (nonatomic, copy) DTShadowTextStyle* tableViewCellTextStyle;

@property (nonatomic, retain) UIColor* tableViewBackgroundColor;
@property (nonatomic, retain) UIColor* tableViewCellBackgroundColor;
@property (nonatomic, retain) UIColor* tableViewCellSelectedBackgroundColor;

@property (nonatomic, retain) UIColor* scanGuideColor;
@property (nonatomic, retain) UIColor* scanBackgroundColor;

@end
