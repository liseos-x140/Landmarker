/**
 * ImageRecognitionRelatedContentData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"

/** 認識結果候補の物体を扱うECサイトのURLのキー。 */
static NSString *const KEY_RELATEDCONTENT_URL = @"url";

/** 認識結果候補の物体を扱うECサイトのタイトルのキー。 */
static NSString *const KEY_RELATEDCONTENT_TITLE = @"title";

/** 認識結果候補の物体を扱うECサイトの画像のURLのキー。 */
static NSString *const KEY_RELATEDCONTENT_IMAGEURL = @"imageUrl";

/** 認識結果候補の物体に関連するコンテンツの概要のキー。 */
static NSString *const KEY_RELATEDCONTENT_ABSTRACT = @"abstract";

/**
 * 画像認識SDK： 認識結果候補の物体に関連するコンテンツデータクラス
 */
@interface ImageRecognitionRelatedContentData : NonExceptionableDictionary
/** 認識結果候補の物体を扱うECサイトのURL。 */
@property (nonatomic) NSString *url;

/** 認識結果候補の物体を扱うECサイトのタイトル。 */
@property (nonatomic) NSString *title;

/** 認識結果候補の物体を扱うECサイトの画像のURL。 */
@property (nonatomic) NSString *imageUrl;

/** 認識結果候補の物体に関連するコンテンツの概要。 */
@property (nonatomic) NSString *abstract;

@end
