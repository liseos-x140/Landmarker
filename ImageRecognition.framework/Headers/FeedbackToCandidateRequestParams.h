/**
 * FeedbackRequestParams.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "FeedbackRequestParams.h"


/**
 *  画像認識SDK： 認識結果の各候補に対するフィードバックリクエスト用データクラス
 */
@interface FeedbackToCandidateRequestParams : FeedbackRequestParams

/** 商品ID */
@property (nonatomic) NSString *itemId;

@end
