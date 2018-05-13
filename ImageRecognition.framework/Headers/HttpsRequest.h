/**
 * HttpsRequest.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */


#import <Foundation/Foundation.h>
#import "HttpsResponse.h"
#import "SdkError.h"
#import "Params.h"

/**
 * 画像認識SDK：画像認識サーバへリクエストを送るクラス
 */
@interface HttpsRequest : NSObject

/**
 *  コードを指定して生成
 *  @param url 接続先URL
 *  @return 初期化したインスタンス
 */
- (instancetype)initWithUrl:(NSString*)url;

/**
 *  画像認識リクエストを実行する
 *  @param params 接続先URL
 *  @return レスポンスを受信するためのHttpsResponseを返却
 */
- (HttpsResponse*)exec:(Params*)params;

@end
