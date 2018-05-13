/**
 * ImageRecognitionBase.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "ImageRecognitionResultData.h"
#import "Params.h"
#import "SdkError.h"
#import "HttpsRequest.h"

//! Project version number for ImageRecognition.
FOUNDATION_EXPORT double ImageRecognitionVersionNumber;

//! Project version string for ImageRecognition.
FOUNDATION_EXPORT const unsigned char ImageRecognitionVersionString[];

@interface ImageRecognitionBase : NSObject

/**
 *  画像認識要求を行う。
 *  @param requestParams 画像認識リクエストパラメータ
 *  @return HttpsResponse
 */
- (HttpsResponse*)request:(Params*)params;

/**
 *  リクエストパラメータの必須項目チェックする。
 *  @param requestParams リクエストパラメータ
 *  @param error エラー
 *  @return リクエストパラメータの必須項目が設定されていればYES
 */
- (BOOL)paramCheck:(Params*)params error:(NSError**)error;

@end
