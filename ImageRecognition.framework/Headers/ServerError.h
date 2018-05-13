/**
 * ServerError.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 未定義のサーバエラー（コード）
 */
static NSInteger const USERVER_UNKNOWN_EXCEPTION_CODE = -1;

/**
 * 画像認識サーバからのHttpエラーを定義するクラス<br/>
 * @see <a href="https://dev.smt.docomo.ne.jp/?p=docs.api.page&api_name=image_recognition&p_name=api_1#tag01">エラー定義</a>
 */
@interface ServerError : NSError

/**
 *  コードを指定して生成
 *  @param code    エラーコード
 *  @param message メッセージ
 *  @return 生成したインスタンス
 */
+ (instancetype)errorWithCode:(NSInteger)code message:(NSString *)message;

@end
