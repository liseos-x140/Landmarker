/**
 * ImageRecognitionFoodDetailData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"
#import "ImageRecognitionDetailData.h"

/** 認識物体の名称のキー。 */
static NSString *const KEY_FOOD_ITEMNAME = @"itemName";

/** 発売日のキー。 */
static NSString *const KEY_FOOD_RELEASEDATE = @"releaseDate";

/** 年齢制限のキー。 */
static NSString *const KEY_FOOD_AGEREQUIREMENT = @"ageRequirement";

/** メーカーのキー。 */
static NSString *const KEY_FOOD_MAKER = @"maker";

/** 販売元のキー。 */
static NSString *const KEY_FOOD_SELLER = @"seller";

/** ブランドのキー。 */
static NSString *const KEY_FOOD_BRAND = @"brand";

/** 商品の寸法のキー。 */
static NSString *const KEY_FOOD_DIMENSION = @"dimension";

/** 商品の重量のキー。 */
static NSString *const KEY_FOOD_WEIGHT = @"weight";

/** 内容量のキー。 */
static NSString *const KEY_FOOD_QUANTITY = @"quantity";

/** 保存方法のキー。 */
static NSString *const KEY_FOOD_PRESERVATION = @"preservation";

/** 産地のキー。 */
static NSString *const KEY_FOOD_PRODUCINGAREA = @"producingArea";

/** EAN13桁コードのキー。 */
static NSString *const KEY_FOOD_EAN13 = @"ean13";

/** EAN8桁コードのキー。 */
static NSString *const KEY_FOOD_EAN8 = @"ean8";


/**
 * 画像認識SDK： 食品パッケージカテゴリ詳細情報データクラス
 */
@interface ImageRecognitionFoodDetailData : NonExceptionableDictionary <ImageRecognitionDetailData>

/** 認識物体の名称。 */
@property (nonatomic) NSString *itemName;

/** 発売日。 */
@property (nonatomic) NSString *releaseDate;

/** 年齢制限。 */
@property (nonatomic) NSString *ageRequirement;

/** メーカー。 */
@property (nonatomic) NSString *maker;

/** 販売元。 */
@property (nonatomic) NSString *seller;

/** ブランド。 */
@property (nonatomic) NSString *brand;

/** 商品の寸法。 */
@property (nonatomic) NSString *dimension;

/** 商品の重量。 */
@property (nonatomic) NSString *weight;

/** 内容量。 */
@property (nonatomic) NSString *quantity;

/** 保存方法。 */
@property (nonatomic) NSString *preservation;

/** 産地。NSString */
@property (nonatomic) NSArray *producingArea;

/** EAN13桁コード。 */
@property (nonatomic) NSString *ean13;

/** EAN8桁コード。 */
@property (nonatomic) NSString *ean8;

@end
