/**
 * ImageRecognitionSiteData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"

/** 認識結果候補の物体を扱うECサイトのURLのキー。 */
static NSString *const KEY_SITE_URL = @"url";

/** 認識結果候補の物体を扱うECサイトのタイトルのキー。 */
static NSString *const KEY_SITE_TITLE = @"title";

/** 認識結果候補の物体を扱うECサイトの画像のURLのキー。 */
static NSString *const KEY_SITE_IMAGEURL = @"imageUrl";

/**
 * 画像認識SDK： 認識結果候補の物体に関連するサイト情報データクラス
 */
@interface ImageRecognitionSiteData : NonExceptionableDictionary

/** 認識結果候補の物体を扱うECサイトのURL。 */
@property (nonatomic) NSString *url;

/** 認識結果候補の物体を扱うECサイトのタイトル。 */
@property (nonatomic) NSString *title;

/** 認識結果候補の物体を扱うECサイトの画像のURL。 */
@property (nonatomic) NSString *imageUrl;

@end
