//
//  CertificateManager.h
//  docomo-oauth-ios-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>

/** 証明書管理クラス */
@interface CertificateManager : NSObject
{
    SecCertificateRef rootCertificate;
}

+ (CertificateManager *)sharedInstance;
- (SecCertificateRef)getRootCertificate;

@end
