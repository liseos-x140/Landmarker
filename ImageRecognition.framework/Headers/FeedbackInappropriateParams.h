/**
 * FeedbackRequestParams.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "Params.h"


/**
 *  画像認識SDK： 不適切コンテンツに対するフィードバックリクエスト用データクラス
 */
@interface FeedbackInappropriateParams : Params

/** 認識ジョブの識別ID */
@property (nonatomic) NSString *recognitionId;

/** 商品ID */
@property (nonatomic) NSString *itemId;

/** カテゴリ */
@property (nonatomic)NSString *category;
/** コメント */
@property (nonatomic) NSString *comment;

@end
