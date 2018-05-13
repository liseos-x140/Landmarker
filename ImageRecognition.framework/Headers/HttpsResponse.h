/**
 * HttpsResponse.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "ImageRecognitionResultData.h"
#import "ServerError.h"
#import "SdkError.h"

/**
 * 画像認識SDK：画像認識サーバからのレスポンスを受信するクラス
 */
@interface HttpsResponse : NSObject

/** レスポンスデータ。 */
@property (nonatomic ,readonly) NSDictionary *content;

/** 発生したエラー。 */
@property (nonatomic ,readonly) NSError *error;

/**
 *  コードを指定して生成
 *  @param response 接続先URL
 *  @param data 接続先URL
 *  @param data 接続先URL
 *  @return 初期化したインスタンス
 */
- (instancetype)initWithResponse:(NSURLResponse*)response data:(NSData*)data error:(NSError*)error;

@end
