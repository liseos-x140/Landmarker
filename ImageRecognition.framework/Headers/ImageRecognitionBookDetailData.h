/**
 * ImageRecognitionBookDetailData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"
#import "ImageRecognitionDetailData.h"

/** 認識物体の名称のキー。 */
static NSString *const KEY_BOOK_ITEMNAME = @"itemName";

/** 発売日のキー。 */
static NSString *const KEY_BOOK_RELEASEDATE = @"releaseDate";

/** 年齢制限のキー。 */
static NSString *const KEY_BOOK_AGEREQUIREMENT = @"ageRequirement";

/** 著者のキー。 */
static NSString *const KEY_BOOK_AUTHOR = @"author";

/** 訳者のキー。 */
static NSString *const KEY_BOOK_TRANSLATOR = @"translator";

/** 発売元のキー。 */
static NSString *const KEY_BOOK_PUBLISHER = @"publisher";

/** 販売元のキー。 */
static NSString *const KEY_BOOK_SELLER = @"seller";

/** 種別のキー。 */
static NSString *const KEY_BOOK_TYPE = @"type";

/** ページ数のキー。 */
static NSString *const KEY_BOOK_PAGES = @"pages";

/** ISBN10桁コードのキー。 */
static NSString *const KEY_BOOK_ISBN10 = @"isbn10";

/** ISBN13桁コードのキー。 */
static NSString *const KEY_BOOK_ISBN13 = @"isbn13";

/** 言語のキー。 */
static NSString *const KEY_BOOK_LANG = @"lang";


/**
 * 画像認識SDK： 書籍カテゴリ詳細情報データクラス
 */
@interface ImageRecognitionBookDetailData : NonExceptionableDictionary <ImageRecognitionDetailData>

/** 認識物体の名称。 */
@property (nonatomic) NSString *itemName;

/** 発売日。 */
@property (nonatomic) NSString *releaseDate;

/** 年齢制限。 */
@property (nonatomic) NSString *ageRequirement;

/** 著者。NSString */
@property (nonatomic) NSArray *author;

/** 訳者。NSString */
@property (nonatomic) NSArray *translator;

/** 発売元。 */
@property (nonatomic) NSString *publisher;

/** 販売元。 */
@property (nonatomic) NSString *seller;

/** 種別。 */
@property (nonatomic) NSString *type;

/** ページ数。 */
@property (nonatomic) NSString *pages;

/** ISBN10桁コード。 */
@property (nonatomic) NSString *isbn10;

/** ISBN13桁コード。 */
@property (nonatomic) NSString *isbn13;

/** 言語。 */
@property (nonatomic) NSString *lang;

@end
