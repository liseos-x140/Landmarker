/**
 * FeedbackRequestParams.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "Params.h"

/**
 *  画像認識SDK： 認識結果の候補全体に対するフィードバックリクエスト用データクラス
 */
@interface FeedbackRequestParams : Params

/** 認識ジョブの識別ID */
@property (nonatomic) NSString *recognitionId;

/** 認識結果商品の妥当判定 */
@property (nonatomic) BOOL isValid;

/** コメント */
@property (nonatomic) NSString *comment;

@end
