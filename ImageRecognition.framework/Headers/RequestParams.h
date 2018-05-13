/**
 * RequestParams.h
 * Copyright (C) 2015 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "Params.h"

/** 認識カテゴリを設定するキー */
static NSString *const PARAM_RECOG = @"recog";

/**
 * 画像認識SDK： 画像認識リクエストのGETパラメータを設定するクラス
 */
@interface RequestParams : Params

/** 認識カテゴリを設定するキー */
@property (nonatomic) NSString *recognitionType;

/** 画像。セットするとimageDataにもデータが設定される。 */
@property (nonatomic) UIImage *image;

/** 画像データ */
@property (nonatomic) NSData *imageData;

@end
