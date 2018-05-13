/**
 * NonExceptionableDictionary.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 画像認識SDK： データクラスのベースクラス
 */
@interface NonExceptionableDictionary : NSMutableDictionary

/**
 *  キーを指定してNSStringを取得する。
 *  取得に失敗した場合はdefaultStringを返す
 *
 *  @param key           キー
 *  @param defaultString 取得に失敗した場合に返すNSString
 *
 *  @return キーに対応したNSString
 */
- (NSString*)getString:(NSString*)key defaultString:(NSString*)defaultString;

/**
 *  キーを指定してdoubleを取得する。
 *  取得に失敗した場合はdefaultValueを返す
 *
 *  @param key          キー
 *  @param defaultValue 取得に失敗した場合に返すdouble
 *
 *  @return キーに対応したdouble
 */
- (double)getDouble:(NSString*)key defaultValue:(double)defaultValue;

/**
 *  キーを指定してNSArrayを取得する。
 *  取得に失敗した場合はnilを返す
 *
 *  @param key キー
 *
 *  @return キーに対応したNSArray
 */
- (NSArray*)getSrtingArray:(NSString*)key;

/**
 *  キーと要素のクラス名を指定してNSArrayを取得する。
 *  取得に失敗した場合はnilを返す。
 *  対応しているクラスはNSMutableDictionaryのサブクラスのみ。
 *
 *  @param key       キー
 *  @param className クラス名
 *
 *  @return キーに対応したNSArray
 */
- (NSArray*)getArray:(NSString*)key className:(NSString*)className;

@end
