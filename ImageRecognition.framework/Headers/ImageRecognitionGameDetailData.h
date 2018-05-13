/**
 * ImageRecognitionGameDetailData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"
#import "ImageRecognitionDetailData.h"

/** 認識物体の名称のキー。 */
static NSString *const KEY_GAME_ITEMNAME = @"itemName";

/** 発売日のキー。 */
static NSString *const KEY_GAME_RELEASEDATE = @"releaseDate";

/** 年齢制限のキー。 */
static NSString *const KEY_GAME_AGEREQUIREMENT = @"ageRequirement";

/** プラットフォームのキー。 */
static NSString *const KEY_GAME_PLATFORM = @"platform";

/** CEROレーティングのキー。 */
static NSString *const KEY_GAME_CERORATING = @"ceroRating";

/** メーカーのキー。 */
static NSString *const KEY_GAME_MAKER = @"maker";

/** 販売元のキー。 */
static NSString *const KEY_GAME_SELLER = @"seller";

/** EAN13桁コードのキー。 */
static NSString *const KEY_GAME_EAN13 = @"ean13";

/** EAN8桁コードのキー。 */
static NSString *const KEY_GAME_EAN8 = @"ean8";


/**
 * 画像認識SDK： TVゲームカテゴリ詳細情報データクラス
 */
@interface ImageRecognitionGameDetailData : NonExceptionableDictionary <ImageRecognitionDetailData>

/** 認識物体の名称。 */
@property (nonatomic) NSString *itemName;

/** 発売日。 */
@property (nonatomic) NSString *releaseDate;

/** 年齢制限。 */
@property (nonatomic) NSString *ageRequirement;

/** プラットフォーム。 */
@property (nonatomic) NSString *platform;

/** CEROレーティング。 */
@property (nonatomic) NSString *ceroRating;

/** メーカー。 */
@property (nonatomic) NSString *maker;

/** 販売元。 */
@property (nonatomic) NSString *seller;

/** EAN13桁コード。 */
@property (nonatomic) NSString *ean13;

/** EAN8桁コード。 */
@property (nonatomic) NSString *ean8;

@end
