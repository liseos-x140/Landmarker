/**
 * ImageRecognitionCdDetailData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"
#import "ImageRecognitionDetailData.h"

/** 認識物体の名称のキー。 */
static NSString *const KEY_CD_ITEMNAME = @"itemName";

/** 発売日のキー。 */
static NSString *const KEY_CD_RELEASEDATE = @"releaseDate";

/** 年齢制限のキー。 */
static NSString *const KEY_CD_AGEREQUIREMENT = @"ageRequirement";

/** アーティスト名のキー。 */
static NSString *const KEY_CD_ARTIST = @"artist";

/** 作曲者のキー。 */
static NSString *const KEY_CD_COMPOSER = @"composer";

/** 指揮者のキー。 */
static NSString *const KEY_CD_CONDUCTOR = @"conductor";

/** レーベルのキー。 */
static NSString *const KEY_CD_LABEL = @"label";

/** 販売元のキー。 */
static NSString *const KEY_CD_SELLER = @"seller";

/** 形式のキー。 */
static NSString *const KEY_CD_FORMAT = @"format";

/** 収録曲数のキー。 */
static NSString *const KEY_CD_SONGS = @"songs";

/** 収録時間のキー。 */
static NSString *const KEY_CD_TIME = @"time";

/** ディスク枚数のキー。 */
static NSString *const KEY_CD_DISCS = @"discs";

/** EAN13桁コードのキー。 */
static NSString *const KEY_CD_EAN13 = @"ean13";

/** EAN8桁コードのキー。 */
static NSString *const KEY_CD_EAN8 = @"ean8";

/** SPARSコードのキー。 */
static NSString *const KEY_CD_SPARSCODE = @"sparsCode";


/**
 * 画像認識SDK： CDカテゴリ詳細情報データクラス
 */
@interface ImageRecognitionCdDetailData : NonExceptionableDictionary <ImageRecognitionDetailData>
/** 認識物体の名称。 */
@property (nonatomic) NSString *itemName;
/** 発売日。 */
@property (nonatomic) NSString *releaseDate;
/** 年齢制限。 */
@property (nonatomic) NSString *ageRequirement;
/** アーティスト名。NSString */
@property (nonatomic) NSArray *artist;
/** 作曲者。 */
@property (nonatomic) NSString *composer;
/** 指揮者。 */
@property (nonatomic) NSString *conductor;
/** レーベル。 */
@property (nonatomic) NSString *label;
/** 販売元。 */
@property (nonatomic) NSString *seller;
/** 形式。NSString */
@property (nonatomic) NSArray *format;
/** 収録曲数。 */
@property (nonatomic) NSString *songs;
/** 収録時間。 */
@property (nonatomic) NSString *time;
/** ディスク枚数。 */
@property (nonatomic) NSString *discs;
/** EAN13桁コード。 */
@property (nonatomic) NSString *ean13;
/** EAN8桁コード。 */
@property (nonatomic) NSString *ean8;
/** SPARSコード。 */
@property (nonatomic) NSString *sparsCode;
@end
