/**
 * Recog.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */


#import <Foundation/Foundation.h>

/** 全商品カテゴリ認識。 */
static NSString *const RECOG_ALL = @"product-all";
/** 書籍認識。 */
static NSString *const RECOG_BOOK = @"book";
/** CD認識。 */
static NSString *const RECOG_CD = @"cd";
/** DVD認識。 */
static NSString *const RECOG_DVD = @"dvd";
/** TVゲームソフト認識。 */
static NSString *const RECOG_GAME = @"game";
/** PCソフト認識。 */
static NSString *const RECOG_SOFTWARE = @"software";
/** 食品、飲料認識。 */
static NSString *const RECOG_FOOD = @"food";


/**
 * 画像認識SDK： 接続先クラス。
 */
@interface Recog : NSObject

/** 接続先の文字列 */
@property (nonatomic ,readonly) NSString *recog;

/** 全商品カテゴリ認識か */
@property (nonatomic ,readonly) BOOL isAll;

/** 書籍認識か */
@property (nonatomic ,readonly) BOOL isBook;

/** CD認識か */
@property (nonatomic ,readonly) BOOL isCd;

/** DVD認識か */
@property (nonatomic ,readonly) BOOL isDvd;

/** TVゲームソフト認識か */
@property (nonatomic ,readonly) BOOL isGame;

/** PCソフト認識か */
@property (nonatomic ,readonly) BOOL isSoftware;

/** 食品、飲料認識か */
@property (nonatomic ,readonly) BOOL isFood;

/**
 *  文字列を指定して生成する
 *  @param requestBean リクエスト情報
 *  @return 初期化したインスタンス
 */
- (instancetype)initWithString:(NSString*)string;

@end
