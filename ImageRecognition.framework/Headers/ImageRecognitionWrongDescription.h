/**
 * ImageRecognitionFeedback.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ImageRecognitionBase.h"
#import "FeedbackWrongDescriptionParams.h"

/**
 *  画像認識SDK： 記載誤りに対するフィードバッククラス
 */
@interface ImageRecognitionWrongDescription : ImageRecognitionBase

/**
 *  認識結果の候補全体に対するフィードバック要求を行う。
 *
 *  @param requestParams <#requestParams description#>
 *  @param error         error description
 */
- (void)feedback:(FeedbackWrongDescriptionParams*)requestParams error:(NSError**)error;

@end
