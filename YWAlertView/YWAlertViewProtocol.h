//
//  YWAlertViewProtocol.h
//  YWAlertViewDemo
//
//  Created by yaowei on 2018/8/28.
//  Copyright © 2018年 yaowei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    YWAlertPublicFootStyleDefalut,//横排
    YWAlertPublicFootStyleVertical,//竖排
    YWAlertPublicFootStyleSegmentation,//横排，按钮之间有间隔10
} YWAlertPublicFootStyle;

typedef enum : NSUInteger {
    
    YWAlertPublicBodyStyleDefalut,
    YWAlertPublicBodyStyleCustom,
    
    
    //YWDatePicker专用
    YWAlertStyleShowYearMonthDayHourMinuteSecond,//年月日时分秒
    YWAlertStyleShowYearMonthDayHourMinute,//年月日时分
    YWAlertStyleShowYearMonthDay,//年月日
    YWAlertStyleShowYearMonth,//年月
    YWAlertStyleShowHourMinuteSecond,//时分秒


} YWAlertPublicBodyStyle;


@protocol YWAlertViewThemeProtocol <NSObject>
@optional

/**
 alert背景图
 
 @return im
 */
- (UIImage *)alertBackgroundView;
/**
 alert背景图的清晰度

 @return 0~1(越小越清晰)
 */
- (CGFloat)alterBackgroundViewArticulation;

/**
 alert的背景颜色

 @return color
 */
- (UIColor *)alertBackgroundColor;
/**
 titleView的颜色
 
 @return color
 */
- (UIColor *)alertTitleViewColor;
/**
 取消按钮的颜色
 
 @return color
 */
- (UIColor *)alertCancelColor;
/**
 修改title的字体

 @return string
 */
- (NSString *)alertTitleFontWithName;
/**
 修改title的字号大小
 
 @return string
 */
- (CGFloat )alertTitleFont;
/**
 修改Message的字体
 
 @return string
 */
- (NSString *)alertMessageFontWithName;
/**
 修改title的字号大小
 
 @return string
 */
- (CGFloat )alertMessageFont;



@end



@protocol YWAlertViewProtocol <NSObject>
@required
/**
 默认显示在Windows上
 */
- (void)show;
/**
 隐藏弹框
 */
- (void)hiddenAlertView;
//config配置信息
@optional
/**
 设置默认选中的时间，该方法针对日期选择模式有效

 @param dateString 默认选中的时间
 */
- (void)selectedDateOnDatePicker:(NSString *)dateString;

/**
 显示在viewController上
 */
- (void)showOnViewController;
/**
 隐藏bodyview上下的两个分隔线
 */
- (void)hiddenBodyLineView;
/**
 隐藏所有的分隔线
 */
- (void)hiddenAllLineView;

/**
 是否显示关闭的按妞
 */
- (void)showCloseOnTitleView;

/**
 设置整个弹框的背景颜色

 @param color 颜色
 */
- (void)setAlertViewBackgroundColor:(UIColor *)color;
/**
 设置titleView的背景颜色

 @param color 颜色
 */
- (void)setTitleViewBackColor:(UIColor *)color;
/**
 设置titleView的title颜色

 @param color 颜色
 */
- (void)setTitleViewTitleColor:(UIColor *)color;
/**
 设置message的字体颜色

 @param color 颜色
 */
- (void)setMessageTitleColor:(UIColor *)color;
/**
 设置所有按钮的字体颜色

 @param color 颜色
 */
- (void)setAllButtionTitleColor:(UIColor *)color;
/**
 设置单个按钮的颜色

 @param color 颜色
 @param index 下标
 */
- (void)setButtionTitleColor:(UIColor *)color index:(NSInteger)index;
/**
 设置单个按钮的字体以及其大小

 @param name 什么字体
 @param size 大小
 @param index 小标
 */
- (void)setButtionTitleFontWithName:(NSString *)name size:(CGFloat)size index:(NSInteger)index;
/**
 设置title的字体以及其大小

 @param name 什么字体(为nil时,即是系统字体)
 @param size 大小
 */
- (void)setTitleFontWithName:(NSString *)name size:(CGFloat)size;
/**
 设置message的字体以及其大小
 
 @param name 什么字体(为nil时,即是系统字体)
 @param size 大小
 */
- (void)setMessageFontWithName:(NSString *)name size:(CGFloat)size;
/**
 自定义bodyview

 @param bodyView 需要定义的view
 @param height 该view的高度
 */
- (void)setCustomBodyView:(UIView *)bodyView height:(CGFloat)height;

/**
 alert背景图(目前对YWAlert有效)

 @param image image
 @param articulation 0~1(越小越清晰)
 */
- (void)setAlertBackgroundView:(UIImage *)image articulation:(CGFloat)articulation;
/**
 设置蒙版的背景图

 @param image 蒙版的背景图（可使用高斯的image）
 */
- (void)setGaussianBlurImage:(UIImage *)image;


/**
 统一配置信息

 @param theme 主题
 */
- (void)setTheme:(id<YWAlertViewThemeProtocol>)theme;
@end

@protocol YWAlertViewDelegate <NSObject>

@optional
/**
 点击view的回调

 @param buttonIndex 点击的下标
 @param value 标题名称
 */
- (void)didClickAlertView:(NSInteger)buttonIndex value:(id)value;
@end



