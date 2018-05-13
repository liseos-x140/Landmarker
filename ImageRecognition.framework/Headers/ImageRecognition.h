/**
 * ImageRecognition.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#pragma once
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ImageRecognitionBase.h"
#import "ImageRecognitionFeedback.h"
#import "ImageRecognitionWrongDescription.h"
#import "ImageRecognitionInappropriate.h"
#import "RequestParams.h"

/**
 * 画像認識SDK： 画像認識要求クラス
 */
@interface ImageRecognition : ImageRecognitionBase

/**
 *  画像認識要求を行う。
 *
 *  @param requestParams 画像認識リクエストパラメータ
 *  @param error エラー
 *
 *  @return 画像認識結果
 */
- (ImageRecognitionResultData*)recognize:(RequestParams*)requestParams error:(NSError**)error;

/**
 *  リクエストパラメータの必須項目チェックする。
 *
 *  @param requestParams リクエストパラメータ
 *  @param error         エラー
 *
 *  @return リクエストパラメータの必須項目が設定されていればYES
 */
- (BOOL)paramCheck:(RequestParams*)requestParams error:(NSError**)error;

@end
