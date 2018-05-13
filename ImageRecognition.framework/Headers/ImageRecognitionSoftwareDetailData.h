/**
 * ImageRecognitionSoftwareDetailData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"
#import "ImageRecognitionDetailData.h"

/** 認識物体の名称のキー。 */
static NSString *const KEY_SOFTWARE_ITEMNAME = @"itemName";

/** 発売日のキー。 */
static NSString *const KEY_SOFTWARE_RELEASEDATE = @"releaseDate";

/** 年齢制限のキー。 */
static NSString *const KEY_SOFTWARE_AGEREQUIREMENT = @"ageRequirement";

/** プラットフォームのキー。 */
static NSString *const KEY_SOFTWARE_PLATFORM = @"platform";

/** メディアのキー。 */
static NSString *const KEY_SOFTWARE_MEDIA = @"media";

/** 動作環境のキー。 */
static NSString *const KEY_SOFTWARE_SYSTEMREQUIREMENTS = @"systemRequirements";

/** メーカーのキー。 */
static NSString *const KEY_SOFTWARE_MAKER = @"maker";

/** 販売元のキー。 */
static NSString *const KEY_SOFTWARE_SELLER = @"seller";

/** EAN13桁コードのキー。 */
static NSString *const KEY_SOFTWARE_EAN13 = @"ean13";

/** EAN8桁コードのキー。 */
static NSString *const KEY_SOFTWARE_EAN8 = @"ean8";

/**
 * 画像認識SDK： PCソフトカテゴリ詳細情報データクラス
 */
@interface ImageRecognitionSoftwareDetailData : NonExceptionableDictionary <ImageRecognitionDetailData>

/** 認識物体の名称。 */
@property (nonatomic) NSString *itemName;

/** 発売日。 */
@property (nonatomic) NSString *releaseDate;

/** 年齢制限。 */
@property (nonatomic) NSString *ageRequirement;

/** プラットフォーム。 */
@property (nonatomic) NSString *platform;

/** メディア。 */
@property (nonatomic) NSString *media;

/** 動作環境。 */
@property (nonatomic) NSString *systemRequirements;

/** メーカー。 */
@property (nonatomic) NSString *maker;

/** 販売元。 */
@property (nonatomic) NSString *seller;

/** EAN13桁コード。 */
@property (nonatomic) NSString *ean13;

/** EAN8桁コード。 */
@property (nonatomic) NSString *ean8;

@end
