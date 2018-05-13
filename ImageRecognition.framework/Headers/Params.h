/**
 * Params.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Recog.h"

/** APIキーを設定するキー */
static NSString *const PARAM_APIKEY = @"APIKEY";

/** 接続先 */
static NSString *const REQ_DOMAIN = @"https://api.apigw.smt.docomo.ne.jp/imageRecognition/v1";

/** 認識IDを表すキー */
static NSString *const PARAM_RECOG_ID = @"recognitionId";

/** 認識結果が妥当であったかを表すキー */
static NSString *const PARAM_ISVALID = @"isValid";

/** 商品IDを表すキー */
static NSString *const PARAM_ITEM_ID = @"itemId";

/** カテゴリを表すキー */
static NSString *const PARAM_CATEGORY = @"category";


/**
 *  画像認識SDK： リクエストパラメータを処理する基底クラス
 */
@interface Params : NSMutableDictionary

/** APIキーを設定するキー */
@property (nonatomic) NSString *apiKey;

/** HTTPヘッダ */
@property (nonatomic) NSDictionary *header;

/** HTTPのクエリ */
@property (nonatomic ,readonly) NSString *query;

/** 画像認識リクエストのパラメータ必須チェック */
@property (nonatomic ,readonly) BOOL checkParams;

/** リクエストボディに含めるデータ */
@property (nonatomic) NSData *content;

/** コンテンツタイプ */
@property (nonatomic) NSString *contentType;

/** 送信メソッド */
@property (nonatomic) NSString *method;

/** Urlデータ */
@property (nonatomic, readonly) NSString *url;

/** 必須項目キー */
@property (nonatomic, readonly) NSArray *mandatoryKeys;

@end
