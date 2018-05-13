/**
 * ImageRecognitionCandidateData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"
#import "ImageRecognitionBookDetailData.h"
#import "ImageRecognitionCdDetailData.h"
#import "ImageRecognitionDvdDetailData.h"
#import "ImageRecognitionGameDetailData.h"
#import "ImageRecognitionSoftwareDetailData.h"
#import "ImageRecognitionFoodDetailData.h"
#import "ImageRecognitionSiteData.h"
#import "ImageRecognitionRelatedContentData.h"

/** 認識結果候補の確からしさを表すスコアのキー。 */
static NSString *const KEY_CANDIDATE_SCORE = @"score";

/** 認識結果候補のIDのキー。 */
static NSString *const KEY_CANDIDATE_ITEMID = @"itemId";

/** 認識結果候補として返却された物体のカテゴリのキー。 */
static NSString *const KEY_CANDIDATE_CATEGORY = @"category";

/** 認識結果候補の画像のURLのキー。 */
static NSString *const KEY_CANDIDATE_IMAGEURL = @"imageUrl";

/** 認識結果の詳細情報のキー。 */
static NSString *const KEY_CANDIDATE_DETAIL = @"detail";

/** サイト情報のキー。 */
static NSString *const KEY_CANDIDATE_SITES = @"sites";

/** 認識結果候補の物体に関連するコンテンツリストのキー。 */
static NSString *const KEY_CANDIDATE_RELATED_CONTENTS = @"relatedContents";

/**
 * 画像認識SDK： 認識結果データクラス。
 */
@interface ImageRecognitionCandidateData : NonExceptionableDictionary

/** 認識結果候補の確からしさを表すスコア。 */
@property (nonatomic) double score;

/** 認識結果候補のID。 */
@property (nonatomic) NSString *itemId;

/** 認識結果候補として返却された物体のカテゴリ。 */
@property (nonatomic) NSString *category;

/** 認識結果候補の画像のURL。 */
@property (nonatomic) NSString *imageUrl;

/** 認識結果の詳細情報。 */
@property (nonatomic) NSDictionary<ImageRecognitionDetailData> *detailData;

/** 認識結果候補の物体に関連するサイト情報リスト。ImageRecognitionSiteData */
@property (nonatomic) NSArray *siteDataList;

/** 認識結果候補の物体に関連するサイト情報リスト。ImageRecognitionRelatedContentData */
@property (nonatomic) NSArray *relatedContentDataList;

@end
