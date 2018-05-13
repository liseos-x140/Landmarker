/**
 * SdkError.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>

/** 未定義エラー（コード）*/
static NSInteger const UNKNOWN_EXCEPTION_CODE = -1;

/** 証明書検証エラー（コード）*/
static NSInteger const ERROR_INVALID_SSL_CERTIFICATE = 0x01;

/** 不正なURL（コード）*/
static NSInteger const ERROR_INVALID_URL_FORMAT = 0x02;

/** HTTPメソッドエラー（コード）*/
static NSInteger const ERROR_INVALID_HTTP_METHOD = 0x03;

/** HTTP接続エラー（コード）*/
static NSInteger const ERROR_CONNECTION = 0x04;

/** データ送信エラー（コード）*/
static NSInteger const ERROR_POST = 0x05;

/** 画像ファイルパスエラー（コード）*/
static NSInteger const ERROR_INVALID_FILEPATH = 0x06;

/** 画像認識パラメータエラー（コード）*/
static NSInteger const ERROR_INVALID_PARAMS = 0x07;

/** 画像データエラー（コード）*/
static NSInteger const ERROR_INVALID_IMAGE = 0x08;

/** JSONパースエラー（コード）*/
static NSInteger const ERROR_INVALID_JSON = 0x09;

/** JSONパースエラー（コード）*/
static NSInteger const ERROR_EMPTY_RESPONSE = 0x10;


/**
 * 画像認識SDK内で発生したエラーを定義するクラス
 */
@interface SdkError : NSError

/**
 *  コードを指定して生成
 *  @param code エラーコード
 *  @return 生成したインスタンス
 */
+ (instancetype)errorWithCode:(NSInteger)code;

@end
