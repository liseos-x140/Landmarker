/**
 * ImageRecognitionDvdDetailData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"
#import "ImageRecognitionDetailData.h"

/** 認識物体の名称のキー。 */
static NSString *const KEY_DVD_ITEMNAME = @"itemName";

/** 発売日のキー。 */
static NSString *const KEY_DVD_RELEASEDATE = @"releaseDate";

/** 年齢制限のキー。 */
static NSString *const KEY_DVD_AGEREQUIREMENT = @"ageRequirement";

/** 出演者のキー。 */
static NSString *const KEY_DVD_ACTOR = @"actor";

/** 監督のキー。 */
static NSString *const  KEY_DVD_DIRECTOR = @"director";

/** 発売元のキー。 */
static NSString *const KEY_DVD_MAKER = @"maker";

/** 販売元のキー。 */
static NSString *const KEY_DVD_SELLER = @"seller";

/** 形式のキー。 */
static NSString *const KEY_DVD_FORMAT = @"format";

/** 言語のキー。 */
static NSString *const KEY_DVD_LANG = @"lang";

/** 字幕の言語のキー。 */
static NSString *const KEY_DVD_CAPTIONLANG = @"captionLang";

/** リージョンコードのキー。 */
static NSString *const KEY_DVD_REGIONCODE = @"regionCode";

/** 収録時間のキー。 */
static NSString *const KEY_DVD_RUNNINGTIME = @"runningTime";

/** ディスク枚数のキー。 */
static NSString *const KEY_DVD_DISCS = @"discs";

/** EAN13桁コードのキー。 */
static NSString *const KEY_DVD_EAN13 = @"ean13";

/** EAN8桁コードのキー。 */
static NSString *const KEY_DVD_EAN8 = @"ean8";


/**
 * 画像認識SDK： DVDカテゴリ詳細情報データクラス
 */
@interface ImageRecognitionDvdDetailData : NonExceptionableDictionary <ImageRecognitionDetailData>

/** 認識物体の名称。 */
@property (nonatomic) NSString *itemName;

/** 発売日。 */
@property (nonatomic) NSString *releaseDate;

/** 年齢制限。 */
@property (nonatomic) NSString *ageRequirement;

/** 出演者。NSString */
@property (nonatomic) NSArray *actor;

/** 監督。NSString */
@property (nonatomic) NSArray *director;

/** 発売元。 */
@property (nonatomic) NSString *maker;

/** 販売元。 */
@property (nonatomic) NSString *seller;

/** 形式。NSString */
@property (nonatomic) NSArray *format;

/** 言語。 */
@property (nonatomic) NSString *lang;

/** 字幕の言語。 */
@property (nonatomic) NSString *captionLang;

/** リージョンコード。 */
@property (nonatomic) NSString *regionCode;

/** 収録時間。 */
@property (nonatomic) NSString *runningTime;

/** ディスク枚数。 */
@property (nonatomic) NSString *discs;

/** EAN13桁コード。 */
@property (nonatomic) NSString *ean13;

/** EAN8桁コード。 */
@property (nonatomic) NSString *ean8;

@end
