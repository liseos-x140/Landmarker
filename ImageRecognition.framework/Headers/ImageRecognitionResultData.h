/**
 * ImageRecognitionResultData.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NonExceptionableDictionary.h"
#import "ImageRecognitionCandidateData.h"

/** 認識ジョブの識別IDのキー。 */
static NSString *const KEY_RECOGNITION_ID = @"recognitionId";

/** 認識結果一覧のキー。*/
static NSString *const KEY_CANDIDATES = @"candidates";

/**
 * 画像認識SDK： 画像認識結果データクラス。
 */
@interface ImageRecognitionResultData : NonExceptionableDictionary

/** 認識ジョブの識別ID。 */
@property (nonatomic) NSString *recognitionId;

/** 認識結果一覧。ImageRecognitionCandidateDataのArray  */
@property (nonatomic) NSArray *candidateDataList;

@end
